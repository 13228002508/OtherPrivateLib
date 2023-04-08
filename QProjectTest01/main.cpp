#include "iostream"
#include "qapplication.h"
#include "qobject.h"
#include "MyMainWindow.h"
using namespace std;

int main(int agrc,char *argv[])
{
    cout<<"Hello World! \\t\\n";

    QApplication a(agrc, argv);
    
     shared_ptr<MainWindow>  m_pMainWin = std::make_shared<MainWindow>(new MainWindow());
     m_pMainWin->show();
    
    return a.exec();
}