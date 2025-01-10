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
	//QPlainTextEdit::extraSelections() 之前选中所有的
	//QList<QTextEdit::ExtraSelection> extraSection1 = QPlainTextEdit::extraSelections();
	QList<QTextEdit::ExtraSelection> extraSection;//本次额外选中的行的容器
	QTextEdit::ExtraSelection selection;//当前选中行
	QColor lineColor = QColor(Qt::blue);// .light(180);//选中行背景色
	selection.format.setBackground(lineColor);//设置选中行的背景色
	selection.format.setProperty(QTextFormat::FullWidthSelection, true);//设置选中行属性
	QTextCursor cCursor(this->textCursor());//获取当前文本编辑器的光标，通过该光标可以获取选中内容等信息
	cCursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
	selection.cursor = this->textCursor();
	selection.cursor.clearSelection();//不清除将会选中多行
	extraSection.append(selection);
	this->setExtraSelections(extraSection);

}

