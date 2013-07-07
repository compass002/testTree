// Tree Practice
#include <iostream>
#include <stack>
#include "MyStack.h"
using namespace std;
// Traverse
// œ»–Ú pre-order
// ÷––Ú in-order
// ∫Û–Ú post-order

typedef bool Status;
#define OK true
#define ERROR false

struct Data{
	int num;
};
typedef Data TElemType;
// tree node
struct BinaryTreeNode{
	Data mData;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};

Status printInt(TElemType e){
	cout<<e.num<<" "<<flush;
	return true;
}
// =============================
// recursion version
// =============================

// pre-order
Status PreOrderTraverseForTree_RecursionVer(BinaryTreeNode *node, Status (* Visit)( TElemType e)){
	if(node){
		if(Visit(node->mData))
			if(PreOrderTraverseForTree_RecursionVer(node->left, Visit))
				if(PreOrderTraverseForTree_RecursionVer(node->right, Visit))
					return OK;
		return ERROR;
	}else
		return OK;
}
// in-order
Status InOrderTraverseForTree_RecursionVer(BinaryTreeNode *node, Status (* Visit)( TElemType e)){
	if(node){
		if(InOrderTraverseForTree_RecursionVer(node->left, Visit))
			if(Visit(node->mData))		
				if(InOrderTraverseForTree_RecursionVer(node->right, Visit))
					return OK;
		return ERROR;
	}else
		return OK;
}
// post-order
Status PostOrderTraverseForTree_RecursionVer(BinaryTreeNode *node, Status (* Visit)( TElemType e)){
	if(node){
		if(PostOrderTraverseForTree_RecursionVer(node->left, Visit))
			if(PostOrderTraverseForTree_RecursionVer(node->right, Visit))
				if(Visit(node->mData))
					return OK;
		return ERROR;
	}else
		return OK;
}
// =============================
// stack version
// =============================

// pre-order
Status PreOrderTraverseForTree_StackVer(BinaryTreeNode *node, Status (* Visit)( TElemType e)){
	Stack<BinaryTreeNode *> mStack;
	while(node||!mStack.IsEmpty()){
		if(node){
			if(!Visit(node->mData))
				return ERROR;
			if(!mStack.Push(node))
				return ERROR;
			node = node->left;

		}else{
			BinaryTreeNode *tempNode = nullptr;
			if(!mStack.Pop(tempNode))
				return ERROR;
			node = tempNode->right;
		}
	}
	return OK;
}

// in-order
Status InOrderTraverseForTree_RecursionVer(BinaryTreeNode *node, Status (* Visit)( TElemType e)){
	Stack<BinaryTreeNode *> mStack;
	while(node||!mStack.IsEmpty()){
		if(node){
			if(!mStack.Push(node))
				return ERROR;
			node = node->left;
		}else{
			BinaryTreeNode *tempNode = nullptr;
			if(!mStack.Pop(tempNode))
				return ERROR;
			if(!Visit(node->mData))
				return ERROR;
			node = tempNode->right;
		}
	}
	return OK;
}
// post-order
struct Temp{
	BinaryTreeNode *node;
	bool right;
	Temp():node(nullptr),right(false){}
	Temp(BinaryTreeNode *x, bool y):node(x),right(y){}
	Temp(const Temp &a):node(a.node),right(a.right){}
};
Status PostOrderTraverseForTree_RecursionVer(BinaryTreeNode *node, Status (* Visit)( TElemType e)){
	Stack<Temp> mStack;
	while(node||!mStack.IsEmpty()){
		if(node){
			if(!mStack.Push(Temp(node,false)))
				return ERROR;
			node = node->left;
		}else{
			Temp a;
			if(!mStack.Pop(a))
				return ERROR;
			if(!a.right){
				if(mStack.Push(Temp(node,true)))
					return ERROR;
				node = a.node->right;
			}else{
				if(!Visit(a.node->mData))
					return ERROR;
			}
		}
	}
	return OK;
}