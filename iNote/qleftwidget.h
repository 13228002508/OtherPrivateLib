#ifndef QLEFTWIDGET_H
#define QLEFTWIDGET_H

#include <QWidget>
#include "QFileInfo"
#include "QListWidget"
#include "BaseType.h"
namespace Ui {
class QLeftWidget;
}

class QLeftWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QLeftWidget(QWidget *parent = 0);
    ~QLeftWidget();
	void SetFileNameData(QList<QFileInfo> *fileInfo);
	void ClearAllData();
 signals:
	void  UserSelectClickFile(INOTE_FILEDATA fileData);
	  
private:
    Ui::QLeftWidget *ui;
	QList<QFileInfo> *m_pfileInfo;
protected:
	void paintEvent(QPaintEvent *event) override;
private slots:
    void on_m_listWidget_itemClicked(QListWidgetItem *item);

};

#endif // QLEFTWIDGET_H
