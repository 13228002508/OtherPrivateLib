#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "qsplitter.h"
#include "qfile.h"
#include "QFileDialog"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	m_IsShowRightControl = true;
    ui->setupUi(this);	
	this->setWindowState(Qt::WindowMaximized); //窗口最大化显示
	this->setStyleSheet(QString("QWidget{background - color: rgb(245, 245, 245);border-color:rgb(245, 245, 245);}"));
	SplitWindow();
	InitWindow();
	on_actionShowSiderbar_triggered();
	QObject::connect(m_pLeftWidget, SIGNAL(UserSelectClickFile(INOTE_FILEDATA)), this, SLOT(UserSelectFileChanged(INOTE_FILEDATA)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{

	QString curPath = QCoreApplication::applicationDirPath();
	QFileDialog fileDialog;
	QString strTitle = "Slect file";
	fileDialog.setWindowTitle(strTitle);
	QString selectDir = fileDialog.getOpenFileName(this, strTitle, curPath, "");
	if (!selectDir.isEmpty())
	{
		/*int index = selectDir.lastIndexOf('/');
		QString dir = selectDir.left(index);
		QDir * pdir = new QDir(dir);
		QStringList filter;
		filter << QStringLiteral("*.txt");
		filter << QStringLiteral("*.cpp");
		filter << QStringLiteral("*.c");
		pdir->setNameFilters(filter);
		QList<QFileInfo> *fileInfo = new QList<QFileInfo>(pdir->entryInfoList(filter));
		if (nullptr != fileInfo)
			m_pLeftWidget->SetFileNameData(fileInfo);*/
		INOTE_FILEDATA fileData;
		fileData.iFileType = No_Temp;
		fileData.strAbslousteFilePath = selectDir;
		fileData.strFileName = selectDir.right(selectDir.length() - selectDir.lastIndexOf("/") - 1);
		m_PRightWidget2->SetFileData(fileData);
	}
}

void MainWindow::on_actionNew_triggered()
{
	m_PRightWidget2->CreateNewFile();
}


void MainWindow::on_actionfristTitle_triggered()
{
	m_PRightWidget2->SetSelectTextFont(FontSize, frist_Title);
}

void MainWindow::on_actionSecondTitle_triggered()
{
	m_PRightWidget2->SetSelectTextFont(FontSize, second_Title);
}

void MainWindow::on_actionThirdTitle_triggered()
{
	m_PRightWidget2->SetSelectTextFont(FontSize, third_Title);
}

void MainWindow::on_actionfourthTitle_triggered()
{
	m_PRightWidget2->SetSelectTextFont(FontSize,default_Title);
}

void MainWindow::on_actionContent_triggered()
{
	m_PRightWidget2->SetSelectTextFont(FontSize, content_Size);
}

void MainWindow::on_actionBold_triggered()
{
	m_PRightWidget2->SetSelectTextFont(FontBold);
}

void MainWindow::on_actionitalic_triggered()
{
	m_PRightWidget2->SetSelectTextFont(FontItalic);
}

void MainWindow::on_actionCode_triggered()
{
	m_PRightWidget2->SetSelectTextFont(FontUnderline);
}


void MainWindow::on_actionHttpLinl_triggered()
{

}

void MainWindow::on_actionShowSiderbar_triggered()
{
	if (m_IsShowRightControl)
	{
		m_pLeftWidget->hide();
		m_IsShowRightControl = false;
	}
	else
	{
		m_pLeftWidget->show();
		m_IsShowRightControl = true;
	}  
}

void MainWindow::on_actionfileOutLine_triggered()
{

}

void MainWindow::on_actionfileList_triggered()
{

}

void MainWindow::SplitWindow()
{
	QSplitter* pQSplit = new QSplitter(this);
	//代码的方式添加QStyle
	this->setCentralWidget(pQSplit);
	m_pLeftWidget = new QLeftWidget;
	//m_pRightWidget = new QRightWidget;
	m_PRightWidget2 = new QRightWidget2;
	pQSplit->addWidget(m_pLeftWidget);
	pQSplit->addWidget(m_PRightWidget2);
	pQSplit->setStretchFactor(0, f_leftWindowWidth);
	pQSplit->setStretchFactor(1, f_RightWindowWidth);
}

void MainWindow::InitStyleShet()
{
	QFile qfile("stylesheet.qss");
	if (qfile.open(QFile::ReadOnly))
	{
		qDebug("open success");

		QString style = QLatin1String(qfile.readAll());

		this->setStyleSheet(style);

		qfile.close();
	}
	else
	{
		qDebug("Open failed");
	}
}

void MainWindow::InitWindow()
{
	QString curPath = QCoreApplication::applicationDirPath();
	curPath = curPath + "\\" + "TempFile";
	//Get All Txt files
	if (!curPath.isEmpty())
	{
		QDir * dir = new QDir(curPath);
		QStringList filter;
		filter << QStringLiteral("*.txt");
		filter << QStringLiteral("*.cpp");
		filter << QStringLiteral("*.c");
		dir->setNameFilters(filter);
		QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
		for (auto it = fileInfo->begin(); it != fileInfo->end(); it++)//fileInfo->size()
		{
			INOTE_FILEDATA fileData;
			fileData.iFileType = Temp_Is_Existed;
			fileData.strAbslousteFilePath = it->absoluteFilePath();
			fileData.strFileName = it->fileName();
			m_PRightWidget2->SetFileData(fileData);
		}
	}
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	m_PRightWidget2->SaveAllFile();
}

void MainWindow::on_actionantTionOpenFilePath_triggered()
{
	//seleft file Path
	m_PRightWidget2->ClearAllOpenTrueExistFIle();
	m_pLeftWidget->ClearAllData();
	QString curPath = QCoreApplication::applicationDirPath();
	QString digTitle = "Select ";
	QString selectDir = QFileDialog::getExistingDirectory(this, digTitle, curPath, QFileDialog::ShowDirsOnly);
	//Get All Txt files
	if (!selectDir.isEmpty())
	{
		QDir * dir = new QDir(selectDir);
		QStringList filter;
		filter << QStringLiteral("*.txt");
		filter << QStringLiteral("*.cpp");
		//filter << QStringLiteral("");
		dir->setNameFilters(filter);
		QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
		if (nullptr != fileInfo)
			m_pLeftWidget->SetFileNameData(fileInfo);    
	}
	if (!m_IsShowRightControl)
		on_actionShowSiderbar_triggered();
}

void MainWindow::UserSelectFileChanged(INOTE_FILEDATA FileData)
{
	m_PRightWidget2->SetFileData(FileData);
}

void MainWindow::on_actSave_triggered()
{
	m_PRightWidget2->SaveSpecialFile();
}


void MainWindow::on_Open_file_Path(QString strfilePath)
{
	int index = strfilePath.lastIndexOf('/');
	QString dir = strfilePath.left(index);
	QDir * pdir = new QDir(dir);
	QStringList filter;
	filter << QStringLiteral("*.txt");
	filter << QStringLiteral("*.cpp");
	pdir->setNameFilters(filter);
	QList<QFileInfo> *fileInfo = new QList<QFileInfo>(pdir->entryInfoList(filter));
	if (nullptr != fileInfo)
		m_pLeftWidget->SetFileNameData(fileInfo);
}


