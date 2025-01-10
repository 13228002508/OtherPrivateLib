#ifndef QSELFITEM_H
#define QSELFITEM_H

#include <QWidget>

class QSelfItem : public QWidget
{
    Q_OBJECT
public:
    explicit QSelfItem(QWidget *parent = nullptr);
	void SetFileName(QString strFileName);
	void SetFileLastModifyData(QString strData);
	void SetParetControlWidth(int tWidth);
	void InitUi();

signals:

public slots:

private:
	QString m_strFileName;
	QString m_strFileLastModifyData;
	int   m_ParentWidth;
};

#endif // QSELFITEM_H
