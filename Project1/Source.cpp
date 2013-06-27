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
Status PreOrderTraverseForTree_RecursionVer(TreeNode *node, Status (* Visit)( TElemType e)){
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
Status InOrderTraverseForTree_RecursionVer(TreeNode *node, Status (* Visit)( TElemType e)){
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
Status PostOrderTraverseForTree_RecursionVer(TreeNode *node, Status (* Visit)( TElemType e)){
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

