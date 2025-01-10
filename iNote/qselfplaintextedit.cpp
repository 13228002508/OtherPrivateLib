#include "qselfplaintextedit.h"
#include "QTextCharFormat"
#include "QTextBlock"
#include "qnamespace.h"
QSelfPlainTextEdit::QSelfPlainTextEdit()
{
	
}

QSelfPlainTextEdit::QSelfPlainTextEdit(QWidget *paretn)
{

}

void QSelfPlainTextEdit::QSelfPlainTextEditConnect()
{
	QMetaObject::Connection sstate = QObject::connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(OnTextCursorChange()));
}

void QSelfPlainTextEdit::mousePressEvent(QMouseEvent *e) 
{

	QPlainTextEdit::mousePressEvent(e);

}

void QSelfPlainTextEdit::mouseReleaseEvent(QMouseEvent *e) 
{
	QPlainTextEdit::mouseReleaseEvent(e);
}

void QSelfPlainTextEdit::keyPressEvent(QKeyEvent *e) 
{
		QPlainTextEdit::keyPressEvent(e);
}

void QSelfPlainTextEdit::OnTextCursorChange()
{
	//QPlainTextEdit::extraSelections() ֮ǰѡ�����е�
	//QList<QTextEdit::ExtraSelection> extraSection1 = QPlainTextEdit::extraSelections();
	QList<QTextEdit::ExtraSelection> extraSection;//���ζ���ѡ�е��е�����
	QTextEdit::ExtraSelection selection;//��ǰѡ����
	QColor lineColor = QColor(Qt::blue);// .light(180);//ѡ���б���ɫ
	selection.format.setBackground(lineColor);//����ѡ���еı���ɫ
	selection.format.setProperty(QTextFormat::FullWidthSelection, true);//����ѡ��������
	QTextCursor cCursor(this->textCursor());//��ȡ��ǰ�ı��༭���Ĺ�꣬ͨ���ù����Ի�ȡѡ�����ݵ���Ϣ
	cCursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
	selection.cursor = this->textCursor();
	selection.cursor.clearSelection();//���������ѡ�ж���
	extraSection.append(selection);
	this->setExtraSelections(extraSection);

}

