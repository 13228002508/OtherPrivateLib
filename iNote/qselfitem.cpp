#include "qselfitem.h"
#include "QLineEdit"
#include "QPushButton"
#include "QLabel"
QSelfItem::QSelfItem(QWidget *paretn) : QWidget(paretn)
{
	InitUi();
}

void QSelfItem::SetFileName(QString strFileName)
{
	m_strFileName = strFileName;
}

void QSelfItem::SetFileLastModifyData(QString strData)
{
	m_strFileLastModifyData = strData;
}

void QSelfItem::SetParetControlWidth(int tWidth)
{
	m_ParentWidth = tWidth;
}

void QSelfItem::InitUi()
{
	//�ļ�������
	QLabel* pLabel = new QLabel(this);
	pLabel->setStyleSheet("Color:gray");
	QFont qfont;
	qfont.setPointSize(8);
	pLabel->setFont(qfont);
	int istrWindth;
	int istrHeight;
	//int istrWindth = QFontMetrics(pLabel->font()).width(m_strFileName);//�����ı�����
	//int istrHeight = QFontMetrics(pLabel->font()).height();//�����ı��߶�
	QRect QplableRect = pLabel->geometry();
	int pLableWid = QplableRect.width() < istrWindth ? istrWindth + 5 : QplableRect.width();
	int plableHeight = QplableRect.height() < istrHeight ? istrHeight + 3 : QplableRect.height();
	pLabel->move(15, 5);
	pLabel->resize(pLableWid, plableHeight);  
	pLabel->setText(m_strFileName);

	QLabel* pTimelable = new QLabel(this);
	pTimelable->setStyleSheet("Color:gray");
	pTimelable->setFont(qfont);
	//istrWindth = QFontMetrics(pTimelable->font()).width(m_strFileLastModifyData);//�����ı�����
	//istrHeight = QFontMetrics(pTimelable->font()).height();//�����ı��߶�
	pTimelable->move(m_ParentWidth - istrWindth -10,5);
	pTimelable->resize(istrWindth, plableHeight);
	pTimelable->setText(m_strFileLastModifyData);


	QLabel* pfileNamelable = new QLabel(this);
	pfileNamelable->setStyleSheet("Color:black");
	qfont.setPointSize(16);
	pfileNamelable->setFont(qfont);
	//istrWindth = QFontMetrics(pfileNamelable->font()).width(m_strFileName);//�����ı�����
	//istrHeight = QFontMetrics(pfileNamelable->font()).height();//�����ı��߶�
	QplableRect = pfileNamelable->geometry();
	pLableWid = QplableRect.width() < istrWindth ? istrWindth + 5 : QplableRect.width();
	plableHeight = QplableRect.height() < istrHeight ? istrHeight + 3 : QplableRect.height();
	pfileNamelable->move(15, 30);
	pfileNamelable->resize(pLableWid, plableHeight);
	pfileNamelable->setWordWrap(true);
	pfileNamelable->setText(m_strFileName);
	pfileNamelable->setAlignment(Qt::AlignVCenter);

}
