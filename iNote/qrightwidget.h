#ifndef QRIGHTWIDGET_H
#define QRIGHTWIDGET_H
#include <QWidget>
#include "qplaintextedit.h"
#include "qfileinfo.h"
#include "BaseType.h"
#define file_Codec_GBK  "GBK"
#define file_codec_UTF_8 "UTF-8"
namespace Ui {
class QRightWidget;
}

class QRightWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QRightWidget(QWidget *parent = 0);
    ~QRightWidget();
	void SetFileData(INOTE_FILEDATA fileData);
	void Openfile(QString string);
	bool SaveFile();
	void SaveTempFile(INOTE_FILEDATA fileData);
	bool IsEditData();
	INOTE_FILEDATA GetFileData();
	void SetSelectTextFont(FontSetClass fclass, int fontSize = -1);
private:
	QString EstimateFileCodec(QString strFileName);
	void resizeEvent(QResizeEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
	void wheelEvent(QWheelEvent *event);
private slots:
	void SetRowIndexAndColIndex();
	void SetFileEditState();
private:
	Ui::QRightWidget *ui;
	QFile m_afile;
	bool m_KeyPress_Ctrl;
	bool m_isEditData;
	INOTE_FILEDATA m_FileData;
};

#endif // QRIGHTWIDGET_H
