#include "DynamicOrderStatisticsTree.h"

// 二叉查找树的插入
BSTNode* OSRBTree::insertBST(BSTNode *p, const int &value){
	BSTNode *y = NULL;
	BSTNode *in = new BSTNode();
	in->left = NULL;
	in->right = NULL;
	in->val = value;
	in->parent = NULL;
	in->size = 1;
	while(p != NULL){
		y = p;
		p->size += 1;
		if(p->val > in->val)
			p = p->left;
		else p = p->right;
	}
	
	if(y == NULL)
		p = in;
	else{
		in->parent = y;
		if(y->val > in->val) y->left = in;
		else y->right = in;
	}
	return in;
}

// 插入红黑树
void OSRBTree::insertOSRBTree(BSTNode *root1, const int &value){
	BSTNode * in = insertBST(root1, value);
	in->color = "red";
	while(in != root1 && in->color == "red"){            // 对红黑特性进行调整
		if(in->parent->color == "black") return;   //  也就保证了必须
		if(in->parent == in->parent->parent->left){
			BSTNode *y = in->parent->parent->right;
			if(y != NULL && y->color == "red"){   //  case 1
				y->color = "black";
				y->parent->color = "red";
				in->parent->color ="black";
				in = in->parent->parent;
			}
			else{
				if(in == in->parent->right){      // case 2   in->parent 左旋
					BSTNode *pa = in->parent;
					in->size = pa->size;    //  修改该结点所包含子树结点个数
					in->parent = pa->parent;
					pa->parent->left = in;
					pa->parent = in;
					if(pa->left != NULL)
						pa->size = pa->left->size + 1;        // 修改结点子树结点大小 
					else pa->size = 1;
					if(in->left != NULL){
						in->left->parent = pa;
						pa->size += in->left->size;
					}
					pa->right = in->left;
					in->left = pa;

					
					in = pa;
				}
				// case 3    in->parent->parent 右旋
				BSTNode *pa = in->parent;
				BSTNode *gpa = in->parent->parent;
				pa->size = gpa->size;
				if(gpa->parent != NULL){
					if(gpa == gpa->parent->left){
						gpa->parent->left = pa;
					}else
						gpa->parent->right = pa;
				}
				pa->parent = gpa->parent;
				if(gpa->right != NULL)gpa->size = gpa->right->size + 1;
				else gpa->size = 1;
				if(pa->right != NULL){
					gpa->size += pa->right->size;
					pa->right->parent = gpa;
				}
				gpa->left = pa->right;
				pa->right = gpa;
				gpa->parent = pa;
				pa->color = "black";
				gpa->color = "red";
			}
		}
		else{
			BSTNode *y = in->parent->parent->left;
			if(y != NULL && y->color == "red"){   //  case 1
				y->color = "black";
				y->parent->color = "red";
				in->parent->color ="black";
				in = in->parent->parent;
			}else{                               // do the same as A  but left与right对换
				if(in == in->parent->left){      // case 2   in->parent 右旋
					BSTNode *pa = in->parent;

					in->size = pa->size;    //  修改该结点所包含子树结点个数

					in->parent = pa->parent;
					pa->parent->right = in;
					pa->parent = in;
					if(pa->right != NULL)
						pa->size = pa->right->size + 1;
					else pa->size = 1;
					if(in->right != NULL){
						in->right->parent = pa;
						pa->size += in->right->size;
					}
					pa->left = in->right;
					in->right = pa;
					in = pa;
				}
				// case 3    in->parent->parent 左旋
				BSTNode *pa = in->parent;
				BSTNode *gpa = in->parent->parent;
				pa->size = gpa->size;
				if(gpa->parent != NULL){
					if(gpa == gpa->parent->left){
						gpa->parent->left = pa;
					}else
						gpa->parent->right = pa;
				}
				pa->parent = gpa->parent;
				if(gpa->left != NULL)gpa->size = gpa->left->size+1;
				else gpa->size = 1;
				if(pa->left != NULL){
					pa->left->parent = gpa;
					gpa->size += pa->left->size;
				}
				gpa->right = pa->left;
				pa->left = gpa;
				gpa->parent = pa;
				pa->color = "black";
				gpa->color = "red";
			}
		}
	}
	root1->color = "black";
}

// 中序遍历输出
void OSRBTree::inorderOSRBTree(BSTNode *p){
	if(p == NULL) return;
	if(p->left != NULL) inorderOSRBTree(p->left);
	cout << p->val << p->color << p->size << " ";
	if(p->right != NULL) inorderOSRBTree(p->right);
}

//  give ith smallest value
BSTNode* OSRBTree::os_select(BSTNode *p, const int &ith){
	if(p == NULL) return p;
	int k = 1;
	if(p->left != NULL){
		k = p->left->size + 1;           // 当前该结点所对应的rank
		
	}
	if(ith == k) return p;
	if(ith < k) return os_select(p->left, ith);
	else return os_select(p->right, ith - k);
}

//  return the rank of value
int OSRBTree::os_rank(BSTNode *p, const int &value){
	if(p == NULL) return 0;
	int k = 1;
	if(p->left != NULL)
		k = p->left->size + 1;
	if(p->val == value)
		return k;
	else if(p->val > value) return os_rank(p->left, value);
	else return os_rank(p->right, value)+k;
}