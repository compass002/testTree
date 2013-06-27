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
		Visit(node->mData);
		PreOrderTraverseForTree(node->left, Visit);
		PreOrderTraverseForTree(node->right, Visit);
		return OK;
	}
	return OK;
}
// =============================
// stack version
// =============================