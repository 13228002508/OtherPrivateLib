#include "qleftwidget.h"
#include "ui_Qleftwidget.h"
#include "qtabbar.h"
#include "qfile.h"
#include "BaseType.h"
QLeftWidget::QLeftWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLeftWidget)
{
	m_pfileInfo = nullptr;
    ui->setupUi(this);
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

QLeftWidget::~QLeftWidget()
{
    delete ui;
}

void QLeftWidget::SetFileNameData(QList<QFileInfo> *fileInfo)
{
	m_pfileInfo = fileInfo;
	ui->m_listWidget->InitListData(m_pfileInfo);
}

void QLeftWidget::ClearAllData()
{
	ui->m_listWidget->clear();
}

void QLeftWidget::paintEvent(QPaintEvent *event)
{
	QString strStyle = QString::asprintf("QTabBar::tab{width:%dpx; height:%dpx;}", this->width()/2 - 10, 50);
	ui->m_tabWidget->setStyleSheet(strStyle);
}

void QLeftWidget::on_m_listWidget_itemClicked(QListWidgetItem *item)
{
	int  iRow = ui->m_listWidget->currentIndex().row();
	if (iRow < 0 || iRow > m_pfileInfo->size())
		return;
	int index = 0;
	auto var = m_pfileInfo->begin();
	for(;var != m_pfileInfo->end(); var++)
	{
		if (index == iRow)
			break;
		index++;
	}
	QString  QstrfilePath = var->absoluteFilePath();
	INOTE_FILEDATA FileData;
	FileData.strAbslousteFilePath = var->absoluteFilePath();
	FileData.strFileName = var->fileName();
	FileData.iFileType = No_Temp;
	emit UserSelectClickFile(FileData);
}
