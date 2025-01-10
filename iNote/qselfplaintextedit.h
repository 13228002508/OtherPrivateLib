#ifndef QSELFPLAINTEXTEDIT_H
#define QSELFPLAINTEXTEDIT_H
#include "qplaintextedit.h"
//  QTextEdit
class QSelfPlainTextEdit : public QPlainTextEdit
{
	Q_OBJECT
public:
    QSelfPlainTextEdit();
	QSelfPlainTextEdit(QWidget *paretn);
	void QSelfPlainTextEditConnect();
	
protected:
	void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE ;
	void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE ;
	void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE ;

private slots:
	void OnTextCursorChange();


};

#endif // QSELFPLAINTEXTEDIT_H
