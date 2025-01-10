#ifndef QSELFLISTWIDGET_H
#define QSELFLISTWIDGET_H
#include "QListWidget"
#include <QWidget>
#include "QFileInfo"
#include "qselfitem.h"
class QSelfListWidget : public QListWidget
{
public:
    QSelfListWidget(QWidget *paretn);
	void InitListData(QList<QFileInfo> *fileInfo);
};

#endif // QSELFLISTWIDGET_H
