#pragma once
#include <QApplication>
//树形数据结构模板
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
	int iLevel; //当前节点位于第几级
	int iSeq;   //当前节点为该级别第几个节点
	T strData; //当前节点的数据
	struct INoteTreeNodeClass * pleft; /*节点左边的树枝*/
	struct INoteTreeNodeClass * pright;/*节点右边的树枝*/
	struct INoteTreeNodeClass * pParent;/*节点的父节点*/
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