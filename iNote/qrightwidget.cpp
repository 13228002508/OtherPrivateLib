#include "qrightwidget.h"
#include "ui_Qrightwidget.h"
#include "qpalette.h"
#include "qrgb.h"
#include "qcolor.h"
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "BaseType.h"
//#include "qtextcodec.h"
#include "QFileDialog"

QRightWidget::QRightWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QRightWidget)
{
    ui->setupUi(this);
	QMetaObject::Connection sstate = QObject::connect(ui->plainTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(SetRowIndexAndColIndex()));
	QObject::connect(ui->plainTextEdit, SIGNAL(textChanged()), this, SLOT(SetFileEditState()));
	//ui->plainTextEdit->zoomIn(1.5);
	ui->plainTextEdit->QSelfPlainTextEditConnect();
	m_KeyPress_Ctrl = false;
	m_isEditData = true;
}

QRightWidget::~QRightWidget()
{
    delete ui;
}

void QRightWidget::SetFileData(INOTE_FILEDATA fileData)
{
	m_FileData = fileData;
	QString strFileName = m_FileData.strFileName;
	int iIndex = strFileName.lastIndexOf(".");
	strFileName = strFileName.left(iIndex);
	//ui->fileNamelabel->setText(strFileName);
	if (Temp_No_Exist != fileData.iFileType)
	{
		Openfile(m_FileData.strAbslousteFilePath);
		SetRowIndexAndColIndex();
	}
}

void QRightWidget::Openfile(QString string)
{
	QString strPrompt;
	QFile m_afile(string);
	if (!m_afile.exists())
	{
		strPrompt = " this file is not exist";
		QMessageBox::information(this, "iNote", strPrompt);
		return;
	}
	QString strCode = EstimateFileCodec(string);
	if (!m_afile.open(QIODevice::ReadWrite | QIODevice::Text))
		return;
	QString QstrFileName = m_afile.fileName();
    QTextStream aStream(&m_afile);//
	ui->plainTextEdit->clear();
	//aStream.setCodec(strCode.toLocal8Bit().data());
	while (!aStream.atEnd())
	{
		QString str= aStream.readLine();//
		ui->plainTextEdit->appendPlainText(str);
		//ui->plainTextEdit->append(str);
	}
	m_afile.close();//
	m_isEditData = false;
}

bool QRightWidget::SaveFile()
{
	if (No_Temp == m_FileData.iFileType)
	{
		if (QFile::exists(m_FileData.strAbslousteFilePath))
		{

			QFile afile(m_FileData.strAbslousteFilePath);
			if (!afile.open(QIODevice::WriteOnly | QIODevice::Text))
				return false;
			QString strfileContent = ui->plainTextEdit->toPlainText();//all content as string
			//QString strfileContent = ui->plainTextEdit->toPlainText();
			QByteArray  strByte = strfileContent.toUtf8();  // String transform byte array
			afile.write(strByte, strByte.length()); //
			afile.close();
			return true;
		}
		return false;
	}
	else
	{
		QString strTitle = "Save File";
		QString strdefaultPath = QCoreApplication::applicationDirPath();
		QString strfilePath = QFileDialog::getSaveFileName(this, strTitle, strdefaultPath, tr("text Files (*.txt) ;; Code C files (*.cpp) ;; Code C files (*.c )"));
		if (!strfilePath.isEmpty())
		{
			QFile tfile(strfilePath);
			if (!tfile.open(QIODevice::WriteOnly | QIODevice::Text))
				return false;
			QString strfileContent = ui->plainTextEdit->toPlainText();//all content as string
			QByteArray  strByte = strfileContent.toUtf8();  // String transform byte array
			tfile.write(strByte, strByte.length()); //
			tfile.close();

			if (Temp_Is_Existed == m_FileData.iFileType)
			{
				QFile aFile(m_FileData.strAbslousteFilePath);
				if (aFile.exists())
					aFile.remove();
			}

			QString strName;
			int ilast = strfilePath.lastIndexOf('/');
			m_FileData.iFileType = No_Temp;
			m_FileData.strAbslousteFilePath = strfilePath;
			m_FileData.strFileName = strfilePath.right(strfilePath.length() - ilast - 1);
			return true;
		}
		return false;
	}
}

void QRightWidget::SaveTempFile(INOTE_FILEDATA fileData)
{
	QString strFileName = fileData.strFileName;
	QString curPath = QCoreApplication::applicationDirPath();
	curPath = curPath + "/" + "TempFile";
	QDir qdir;
	if ( !qdir.exists(curPath))
	{
		if (!qdir.mkpath(curPath))
			return;
	}
	if (Temp_No_Exist == fileData.iFileType)
		curPath = curPath + "/" + strFileName + ".txt";// + "/" + "TempFile"
	else
		curPath = curPath + "/" + strFileName;
	QFile afile(curPath);
	if (!afile.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
	QString strfileContent = ui->plainTextEdit->toPlainText();//all content as string
	QByteArray  strByte = strfileContent.toUtf8();  // String transform byte array
	afile.write(strByte, strByte.length()); //
	afile.close();
}





bool QRightWidget::IsEditData()
{
	return m_isEditData;
}



INOTE_FILEDATA QRightWidget::GetFileData()
{
	return m_FileData;
}

void QRightWidget::SetSelectTextFont(FontSetClass fclass, int fontSize)
{
	QTextCursor textCursor = ui->plainTextEdit->textCursor();
	QString strBlock = textCursor.selectedText();
	QTextCharFormat fmt = textCursor.charFormat();	
	qreal size = fmt.fontPointSize();
	if (fclass == FontSize)
		fmt.setFontPointSize(fontSize);
	else if (fclass == FontBold)
		QFont::Normal == textCursor.charFormat().fontWeight() ? fmt.setFontWeight(QFont::Bold) : fmt.setFontWeight(QFont::Normal);
	else if (fclass == FontItalic)
		textCursor.charFormat().fontItalic() ? fmt.setFontItalic(false) : fmt.setFontItalic(true);
	else if (fclass == FontUnderline)
		textCursor.charFormat().fontUnderline() ? fmt.setFontUnderline(false) : fmt.setFontUnderline(true);
	textCursor.setCharFormat(fmt);
	textCursor.insertText(strBlock);
}

QString QRightWidget::EstimateFileCodec(QString strFileName)
{
	QString strCodecName = "UTF-8";
	QFile file(strFileName);
	if(file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QByteArray text = file.readAll();
		//QTextCodec::ConverterState state;
		//QTextCodec *codec = QTextCodec::codecForName("UTF-8");
		//codec->toUnicode(text.constBegin(), text.size(), &state);

		//if (0 < state.invalidChars)
		//	strCodecName = "GBK";
	}
	file.close();
	return strCodecName;
}

void QRightWidget::wheelEvent(QWheelEvent *event)
{
	if (event->modifiers() == Qt::ControlModifier)
	{
		if (event->angleDelta().x() > 0)
			ui->plainTextEdit->zoomIn();
		else
			ui->plainTextEdit->zoomOut();
	
	}
}

void QRightWidget::SetRowIndexAndColIndex()
{	
	QTextCursor  tCursor = ui->plainTextEdit->textCursor();
	int iRow = tCursor.blockNumber() + 1;
	int iCol = tCursor.columnNumber() + 1;
	QString strRow = QString::asprintf("%d", iRow);
	QString strCol = QString::asprintf("%d", iCol);
	ui->RowVlalueLabe->setText(strRow);
	ui->CloValue->setText(strCol);
}



void QRightWidget::SetFileEditState()
{
	m_isEditData = true;
}

void QRightWidget::keyPressEvent(QKeyEvent *event)
{
	QWidget::keyPressEvent(event);
}


void QRightWidget::resizeEvent(QResizeEvent *event)
{
	QRect WindowRect = ui->groupBox_2->geometry();
	int iTopW = WindowRect.top();
	int iLeftW = WindowRect.left();
	int iBottomW = WindowRect.bottom();
	int iRightW4 = WindowRect.right();
	if (750 < WindowRect.width())
	{
		iRightW4 -= 50;
		ui->CodecLableValue->setGeometry(iRightW4, 5, 30, 10);
		iRightW4 -= 35;
		ui->CodecLable->setGeometry(iRightW4, 5, 35, 10);
		iRightW4 -= 20;
		ui->CloValue->setGeometry(iRightW4, 5, 30, 10);
		iRightW4 -= 25;
		ui->ColLable->setGeometry(iRightW4, 5, 30, 10);
		iRightW4 -= 20;
		ui->RowVlalueLabe->setGeometry(iRightW4, 5, 30, 10);
		iRightW4 -= 25;
		ui->Rowlabel->setGeometry(iRightW4, 5, 30, 10);
	}
	else
	{

	}
}
