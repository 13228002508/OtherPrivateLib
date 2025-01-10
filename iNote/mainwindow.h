#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BaseType.h"
#include "qleftwidget.h"
#include "qrightwidget.h"
#include "qrightwidget2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionNew_triggered();
    void on_actionfristTitle_triggered();
    void on_actionSecondTitle_triggered();
    void on_actionThirdTitle_triggered();
    void on_actionfourthTitle_triggered();
    void on_actionContent_triggered();
    void on_actionBold_triggered();
    void on_actionitalic_triggered();
    void on_actionCode_triggered();
    void on_actionHttpLinl_triggered();
    void on_actionShowSiderbar_triggered();
    void on_actionfileOutLine_triggered();
    void on_actionfileList_triggered();

    void on_actionantTionOpenFilePath_triggered();

	void UserSelectFileChanged(INOTE_FILEDATA FileData);

    void on_actSave_triggered();

	void on_Open_file_Path(QString strfilePath);


private:
    Ui::MainWindow *ui;
	QLeftWidget*  m_pLeftWidget;
	QRightWidget* m_pRightWidget;
	QRightWidget2* m_PRightWidget2;
	QString   m_CurrentFileName;
	bool      m_IsShowRightControl;
private:
	void SplitWindow();
	void InitStyleShet();
	void InitWindow();
protected:
	void closeEvent(QCloseEvent *event) override;

};

#endif // MAINWINDOW_H
