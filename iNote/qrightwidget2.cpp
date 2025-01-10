#include "qrightwidget2.h"
#include "ui_qrightwidget2.h"
#include "qrightwidget.h"
#include "qmessagebox.h"
QRightWidget2::QRightWidget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QRightWidget2)
{
    ui->setupUi(this);
	ui->m_tabWidget->setTabsClosable(true);
	QObject::connect(ui->m_tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(CloseSpecialTab(int)));
	m_itempFileCount = 0;
}

QRightWidget2::~QRightWidget2()
{
    delete ui;
}

void QRightWidget2::SetFileData(INOTE_FILEDATA fileData)
{
	OpenExistInoteFile(fileData);
}

void QRightWidget2::SaveAllFile()
{
	for (int i = 0; i < ui->m_tabWidget->count(); i++)
	{
		QRightWidget* pWidget = reinterpret_cast<QRightWidget*>(ui->m_tabWidget->widget(i));
		QString  strName = pWidget->GetFileData().strFileName;
		
		auto it = std::find_if(m_fileDataVec.begin(), m_fileDataVec.end(), [&](INOTE_FILEDATA fileData) { return  fileData.strFileName == strName; });
		if (it != m_fileDataVec.end())
		{
			if (Temp_No_Exist == it->iFileType || Temp_Is_Existed == it->iFileType)
				pWidget->SaveTempFile(*it);
			else
				pWidget->SaveFile();

		}
	}
}

void QRightWidget2::OpenExistInoteFile(INOTE_FILEDATA fileData)
{
	QString strName;
	int ilast = fileData.strAbslousteFilePath.lastIndexOf('/');
	strName = fileData.strAbslousteFilePath.right(fileData.strAbslousteFilePath.length() - ilast - 1);

	auto it = std::find_if(m_fileDataVec.begin(), m_fileDataVec.end(), [&](INOTE_FILEDATA fileData) { return  fileData.strFileName == strName; });
	if (it != m_fileDataVec.end())
	{
		for (int i = 0; i < ui->m_tabWidget->count(); i++)
		{
			QString  strName = ui->m_tabWidget->tabText(i);
			if (strName == fileData.strFileName)
			{
				ui->m_tabWidget->setCurrentIndex(i);
				break;
			}
		}
		return;
	}

	//1.创建一个Sheet页
	QRightWidget * pTabSheet = new QRightWidget;
	pTabSheet->SetFileData(fileData);


	QString strFileName = strName;
	if (Temp_Is_Existed == fileData.iFileType || Temp_No_Exist == fileData.iFileType)
	{
		int iIndex = strFileName.lastIndexOf(".");
		strFileName = strFileName.left(iIndex);
	}

	//加载该Sheet页
	int iIndex = ui->m_tabWidget->addTab(pTabSheet, strFileName);
	ui->m_tabWidget->setCurrentIndex(iIndex);
	m_fileDataVec.emplace_back(fileData);
	if (fileData.iFileType == Temp_No_Exist || fileData.iFileType == Temp_Is_Existed)
		m_itempFileCount++;
}

void QRightWidget2::ClearAllOpenTrueExistFIle()
{
	 bool IsEdit = false;
	 for (int i = 0; i< ui->m_tabWidget->count(); i++)
	 {
		 QString  strName = ui->m_tabWidget->tabText(i);
		 auto it = std::find_if(m_fileDataVec.begin(), m_fileDataVec.end(), [&](INOTE_FILEDATA fileData) { return  fileData.strFileName == strName && fileData.iFileType == No_Temp; });
		 if (it != m_fileDataVec.end())
		 {
			 QRightWidget* pWidget = reinterpret_cast<QRightWidget*>(ui->m_tabWidget->widget(i));
			 if (pWidget->IsEditData())
			 {
				 IsEdit = true;
				 break;
			 }	
		 }
	 }
	 if (IsEdit)
	 {
		 QString strQes = QString::fromLocal8Bit("是否保存当前文件?");
		 int iRet = QMessageBox::question(this, "INote", strQes, QMessageBox::StandardButton::Save, QMessageBox::StandardButton::No);
		 if (QMessageBox::StandardButton::Save == iRet)
		 {
			 for (int i = 0; i < ui->m_tabWidget->count(); i++)
			 {
				 QString  strName = ui->m_tabWidget->tabText(i);
				 auto it = std::find_if(m_fileDataVec.begin(), m_fileDataVec.end(), [&](INOTE_FILEDATA fileData) { return  fileData.strFileName == strName && fileData.iFileType == No_Temp; });
				 if (it != m_fileDataVec.end())
				 {
					 m_fileDataVec.erase(it);
					 QRightWidget* pWidget = reinterpret_cast<QRightWidget*>(ui->m_tabWidget->widget(i));
					 if (pWidget->IsEditData())
						 pWidget->SaveFile();
					 ui->m_tabWidget->removeTab(i);
				 }
			 }
		 }
	 }

}

void QRightWidget2::CreateNewFile()
{
	
	QString strTempFileName = QString::asprintf("New file %d", m_itempFileCount);

	INOTE_FILEDATA FileData;
	FileData.iFileType = Temp_No_Exist;
	FileData.strFileName  = strTempFileName;

	//1.创建一个Sheet页
	QRightWidget * pTabSheet = new QRightWidget;
	pTabSheet->SetFileData(FileData);
	//加载该Sheet页
	int iIndex = ui->m_tabWidget->addTab(pTabSheet, strTempFileName);
	ui->m_tabWidget->setCurrentIndex(iIndex);
	m_fileDataVec.emplace_back(FileData);
	m_itempFileCount++;
}

void QRightWidget2::SaveSpecialFile()
{
	QRightWidget* pWidget = reinterpret_cast<QRightWidget*>(ui->m_tabWidget->currentWidget());

	if (nullptr != pWidget)
	{
		if (pWidget->SaveFile())
		{
			INOTE_FILEDATA fileData = pWidget->GetFileData();
			int iCur = ui->m_tabWidget->currentIndex();
			if (0 <= iCur)
			{
				QString strOldTabName = ui->m_tabWidget->tabText(iCur);
				auto it = std::find_if(m_fileDataVec.begin(), m_fileDataVec.end(), [&](INOTE_FILEDATA fileData) {return fileData.strFileName == strOldTabName; });
				if (it != m_fileDataVec.end())
				{
					std::memcpy(&(*it), &fileData, sizeof(INOTE_FILEDATA));
					ui->m_tabWidget->setTabText(iCur, fileData.strFileName);
				}	
			}
		}
	}	
}

void QRightWidget2::SetSelectTextFont(FontSetClass fclass, int fontSize)
{
	QRightWidget* pWidget = reinterpret_cast<QRightWidget*>(ui->m_tabWidget->currentWidget());
	if ( nullptr != pWidget)
		pWidget->SetSelectTextFont(fclass,fontSize);
}

void QRightWidget2::CloseSpecialTab(int iIndex)
{
	QRightWidget* pWidget = reinterpret_cast<QRightWidget*>(ui->m_tabWidget->widget(iIndex));
	if (nullptr == pWidget)
		return;
	QString  strName = pWidget->GetFileData().strFileName;

	auto it = std::find_if(m_fileDataVec.begin(), m_fileDataVec.end(), [&](INOTE_FILEDATA fileData) { return  fileData.strFileName == strName;});
	if (it != m_fileDataVec.end())
	{
		INOTE_FILEDATA tempFileData = *it;
		m_fileDataVec.erase(it);
		if (tempFileData.iFileType == No_Temp )
		{			
			QRightWidget* pWidget = reinterpret_cast<QRightWidget*>(ui->m_tabWidget->widget(iIndex));
			if (pWidget->IsEditData())
			{
				QString strQes = QString::fromLocal8Bit("是否保存当前文件?");
				int iRet = QMessageBox::question(this, strName, strQes, QMessageBox::StandardButton::Save, QMessageBox::StandardButton::No);
				if (QMessageBox::StandardButton::Save == iRet)
				{
					pWidget->SaveFile();
				}
			}
			ui->m_tabWidget->removeTab(iIndex);
		}
		else if (tempFileData.iFileType == Temp_Is_Existed)
		{
			QFile aFile(tempFileData.strAbslousteFilePath);
			if (aFile.exists())
				aFile.remove();
			m_itempFileCount--;
			ui->m_tabWidget->removeTab(iIndex);
		}
		else
		{
			m_itempFileCount--;
			ui->m_tabWidget->removeTab(iIndex);
		}
			
	}
}
