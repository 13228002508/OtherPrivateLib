#ifndef QRIGHTWIDGET2_H
#define QRIGHTWIDGET2_H

#include <QWidget>
#include "BaseType.h"


namespace Ui {
class QRightWidget2;
}

class QRightWidget2 : public QWidget
{
    Q_OBJECT

public:
    explicit QRightWidget2(QWidget *parent = 0);
    ~QRightWidget2();
	void SetFileData(INOTE_FILEDATA fileData);
	void SaveAllFile();
	void OpenExistInoteFile(INOTE_FILEDATA fileData);
	void ClearAllOpenTrueExistFIle();
	void CreateNewFile();
	void SaveSpecialFile();
	void SetSelectTextFont(FontSetClass fclass, int fontSize = -1);
private slots:
	void CloseSpecialTab(int iIndex);
private:
    Ui::QRightWidget2 *ui;
	int m_itempFileCount;
	std::vector<INOTE_FILEDATA> m_fileDataVec;
};

#endif // QRIGHTWIDGET2_H
