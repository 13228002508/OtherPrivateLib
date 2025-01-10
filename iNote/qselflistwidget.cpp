#include "qselflistwidget.h"
#include "QListWidget"
#include "QDateTime"
QSelfListWidget::QSelfListWidget(QWidget *paretn)
{

}

void QSelfListWidget::InitListData(QList<QFileInfo> *fileInfo)
{
	for (auto it=fileInfo->begin() ; it != fileInfo->end(); it++)//fileInfo->size()
	{
		QListWidgetItem *newItem = new QListWidgetItem(this);
		QSelfItem * pSelfItem = new QSelfItem();
		pSelfItem->SetFileName(it->fileName());
		pSelfItem->SetFileLastModifyData((it->lastModified()).toString("yyyy-MM-dd hh:mm:ss"));
		pSelfItem->SetParetControlWidth(this->width());
		QString str= QString::asprintf("QListWidget::item{border:none; height: 80px; Width : %d}", this->width());
		this->setStyleSheet(str);
		pSelfItem->InitUi();
		this->insertItem(this->count(), newItem);
		this->setItemWidget(newItem, pSelfItem);
	}
}

