// Tree Practice
#include <iostream>
using namespace std;
// Traverse
// ���� pre-order
// ���� in-order
// ���� post-order

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
			PreOrderTraverseForTree(node->left, Visit);
			PreOrderTraverseForTree(node->right, Visit);
			return OK;
		}else
			return ERROR;
	}
	return OK;
}
// =============================
// stack version
// =============================