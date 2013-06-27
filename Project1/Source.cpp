// Tree Practice
#include <iostream>
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
struct TreeNode{
	Data mData;
	struct TreeNode *left;
	struct TreeNode *right;
};

Status printInt(TElemType e){
	cout<<e.num<<" "<<flush;
	return true;
}
// =============================
// recursion version
// =============================

// pre-order
Status PreOrderTraverseForTree(TreeNode *node, Status (* Visit)( TElemType e)){
	if(node){
		if(Visit(node->mData)){
			if(PreOrderTraverseForTree(node->left, Visit)){
				if(PreOrderTraverseForTree(node->right, Visit)){
					return OK;
				}else
					return ERROR;
			}else
				return ERROR;
		}else
			return ERROR;
	}else
		return OK;
}
// in-order
Status InOrderTraverseForTree(TreeNode *node, Status (* Visit)( TElemType e)){
	if(node){
		InOrderTraverseForTree(node->left, Visit);
		if(!Visit(node->mData))
			return ERROR;
		InOrderTraverseForTree(node->right, Visit);
		return OK;
	}else
		return OK;
}
// =============================
// stack version
// =============================