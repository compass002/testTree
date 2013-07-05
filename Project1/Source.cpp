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
// pre-order
Status PreOrderTraverseForTree_StackVer(BinaryTreeNode *node, Status (* Visit)( TElemType e)){
	Stack<BinaryTreeNode *> mStack;
	
	while(node||!mStack.IsEmpty()){
		if(node){
		Visit(node->mData);
			mStack.Push(node);
			
			node = node->left;
		}else{
			BinaryTreeNode *tempNode = nullptr;
			mStack.Pop(tempNode);
			node = tempNode->right;
		}
	}
}