#pragma once
const float f_leftWindowWidth = 2;
const float f_RightWindowWidth = 8;
//typedef std::map<QString> 
#ifdef WIN32
#pragma excution_character_set("utf-8")
#endif

enum FileType
{
	Temp_No_Exist = 0,
	Temp_Is_Existed,
	No_Temp
};


struct INOTE_FILEDATA
{
	FileType iFileType;
	QString strAbslousteFilePath;
	QString strFileName;
	INOTE_FILEDATA()
	{
		iFileType = Temp_No_Exist;
		strAbslousteFilePath = "";
		strFileName = "";
	}
};

//Sheetҳ����������Ŷ���
const int Tab_FristData_1 = 0;
const int Tab_FristData_2 = 1;


enum  FontSetClass
{
	FontSize = 0, //����
	FontBold,     //�ʻ���ϸ
	FontItalic,    //б��
	FontUnderline  //�»���
};


//Ĭ����������
const int frist_Title = 25;  //q
const int second_Title = 22; //W
const int third_Title = 20;  //e
const int default_Title = 18; //r
const int content_Size = 14; //t
