#include "IntervalTree.h"
using namespace std;

BSTNode* IntervalTree::insertBST(BSTNode *p, const dataNode &d){
	BSTNode *y = NULL;
	BSTNode *in = new BSTNode();
	in->left = NULL;
	in->right = NULL;
	in->val = d.low;
	in->parent = NULL;
	in->m = d.high;
	in->d = d;
	while(p != NULL){
		y = p;
		if(p->m < in->m) p->m = in->m;  // 为子树结点的最大值
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

void IntervalTree::insertIntervalTree(BSTNode *root1, const dataNode &d){
	BSTNode * in = insertBST(root1, d);
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
					in->m = pa->m;    //  修改该结点所包含子树结点个数
					in->parent = pa->parent;
					pa->parent->left = in;
					pa->parent = in;
					if(pa->left != NULL)
						pa->m = pa->left->m > pa->m ? pa->left->m : pa->m;

					if(in->left != NULL){
						in->left->parent = pa;
						pa->m = in->left->m > pa->m ? pa->left->m : pa->m;
					}
					pa->right = in->left;
					in->left = pa;

					
					in = pa;
				}
				// case 3    in->parent->parent 右旋
				BSTNode *pa = in->parent;
				BSTNode *gpa = in->parent->parent;
				pa->m = gpa->m;
				if(gpa->parent != NULL){
					if(gpa == gpa->parent->left){
						gpa->parent->left = pa;
					}else
						gpa->parent->right = pa;
				}
				pa->parent = gpa->parent;
				if(gpa->right != NULL)gpa->m = gpa->right->m > gpa->m ? gpa->right->m : gpa->m;
				if(pa->right != NULL){
					gpa->m = pa->right->m > gpa->m ? pa->right->m : gpa->m;
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

					in->m = pa->m;    //  修改该结点所包含子树结点个数

					in->parent = pa->parent;
					pa->parent->right = in;
					pa->parent = in;
					if(pa->right != NULL)
						pa->m = pa->right->m > pa->m ? pa->right->m : pa->m;
					if(in->right != NULL){
						in->right->parent = pa;
						pa->m = in->right->m > pa->m ? in->right->m : pa->m;
					}
					pa->left = in->right;
					in->right = pa;
					in = pa;
				}
				// case 3    in->parent->parent 左旋
				BSTNode *pa = in->parent;
				BSTNode *gpa = in->parent->parent;
				pa->m = gpa->m;
				if(gpa->parent != NULL){
					if(gpa == gpa->parent->left){
						gpa->parent->left = pa;
					}else
						gpa->parent->right = pa;
				}
				pa->parent = gpa->parent;
				if(gpa->left != NULL)gpa->m = gpa->left->m > gpa->m ? gpa->left->m : gpa->m;
				if(pa->left != NULL){
					pa->left->parent = gpa;
					gpa->m = pa->left->m > gpa->m ? pa->left->m : gpa->m;
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

void IntervalTree::inorderOSRBTree(BSTNode *p){
	if(p == NULL) return;
	if(p->left != NULL) inorderOSRBTree(p->left);
	cout << p->val << p->color << p->m << " ";

	//cout << p->d.low << p->color << p->d.high << " ";
	if(p->right != NULL) inorderOSRBTree(p->right);
}

BSTNode* IntervalTree::intervalSearch(BSTNode *p, const dataNode &d){
	while(p != NULL && (d.low > p->d.high || d.high < p->d.low)){
		if(p->left != NULL && d.low < p->m)
			p = p->left;
		else p = p->right;
	}
	return p;
}

void IntervalTree::destroyBST(BSTNode *p){
	if(p == NULL) return;
	if(p->left != NULL){
		destroyBST(p->left);
	}
	if(p->right != NULL){
		destroyBST(p->right);
	}
	delete p;
}