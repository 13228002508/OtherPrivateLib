#pragma once
#include <QApplication>
//�������ݽṹģ��
template<class T>
class INoteTreeNodeClass
{
public:
	INoteTreeNodeClass(T strrootData);
	~INoteTreeNodeClass();
public:
	inline T GetCurrentNodeData(){return strData;}
	INoteTreeNodeClass InsertLeftNode(INoteTreeNodeClass *pRight, T data);
	INoteTreeNodeClass InsertRightNode(INoteTreeNodeClass *pLeft, T data);
	INoteTreeNodeClass InsertChildNode(INoteTreeNodeClass *pParent,T data);
	INoteTreeNodeClass deleteSepicNode(INoteTreeNodeClass data);
	std::vector<INoteTreeNodeClass> SpeicifLevelNodeVector();
	INoteTreeNodeClass CurrentNodeLeftNode();
	INoteTreeNodeClass CurrentNodeRightNode();

private:
	int iLevel; //��ǰ�ڵ�λ�ڵڼ���
	int iSeq;   //��ǰ�ڵ�Ϊ�ü���ڼ����ڵ�
	T strData; //��ǰ�ڵ������
	struct INoteTreeNodeClass * pleft; /*�ڵ���ߵ���֦*/
	struct INoteTreeNodeClass * pright;/*�ڵ��ұߵ���֦*/
	struct INoteTreeNodeClass * pParent;/*�ڵ�ĸ��ڵ�*/
};

template<class T>
INoteTreeNodeClass<T> INoteTreeNodeClass<T>::InsertChildNode(INoteTreeNodeClass *pParent, T data)
{

}

template<class T>
INoteTreeNodeClass<T> INoteTreeNodeClass<T>::InsertRightNode(INoteTreeNodeClass *pLeft, T data)
{
	if (pLeft == this)
	{

	}
}

template<class T>
INoteTreeNodeClass<T> INoteTreeNodeClass<T>::InsertLeftNode(INoteTreeNodeClass *pRight, T data)
{

}

template<class T>
INoteTreeNodeClass<T> INoteTreeNodeClass<T>::CurrentNodeRightNode()
{

}

template<class T>
INoteTreeNodeClass<T> INoteTreeNodeClass<T>::CurrentNodeLeftNode()
{

}

template<class T>
std::vector<INoteTreeNodeClass<T>> INoteTreeNodeClass<T>::SpeicifLevelNodeVector()
{

}

template<class T>
INoteTreeNodeClass<T> INoteTreeNodeClass<T>::deleteSepicNode(INoteTreeNodeClass data)
{

}

template<class T>
INoteTreeNodeClass<T>::INoteTreeNodeClass(T strrootData)
{
	iLevel = 0;
	iSeq = 0;
	strData = strrootData;
	pleft = nullptr;
	pright = nullptr;
	pParent = nullptr;
}

template<class T>
INoteTreeNodeClass<T>::~INoteTreeNodeClass()
{

}