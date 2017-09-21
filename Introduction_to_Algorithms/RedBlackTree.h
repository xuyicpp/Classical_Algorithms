/**
 * C++ RBTree
 * author xy
 */

#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

#include <iostream>
#include <iomanip>	//iomanip.h是I/O流控制头文件,就像C里面的格式化输出一样.

using namespace std;

enum  RBTColor{ RED, BLACK};

template<class T>
class RBTNode
{
public:
	RBTColor color;
	T key;
	RBTNode* left;
	RBTNode* right;
	RBTNode* parent;

	RBTNode(T value, RBTColor c, RBTNode* p,RBTNode *l, RBTNode* r)
	:key(value),color(c),parent(),left(l),right(r) { }
};

template <class T>
class RBTree
{
private:
	RBTNode<T> *mRoot;	//root node

public:
	RBTree();
	~RBTree();

	//前序遍历"红黑树"
	void preOrder();
	// 中序遍历"红黑树"
	void inOrder();
	// 后序遍历"红黑树"
	void postOrder();

	// (递归实现)查找"红黑树"中键值为key的节点
	RBTNode<T>* search(T key);
	// (非递归实现)查找"红黑树"中键值为key的节点
	RBTNode<T>* iterativeSearch(T key);

	// 查找最小节点：返回最小节点的键值。
	T minimum();
	// 查找最大节点：返回最大节点的键值。
	T maximum();

	// 找节点(x)的后继节点。即，查找"红黑树中数据值大于该节点"的"最小节点"。
	RBTNode<T>* successor(RBTNode<T>* x);
	// 找节点(x)的前驱节点。即，查找"红黑树中数据值小于该节点"的"最大节点"。
	RBTNode<T>* predecessor(RBTNode<T>* x);

	// 将节点(key为节点键值)插入到红黑树中
	void insert(T key);

	// 删除节点(key为节点键值)
	void remove(T key);

	// 销毁红黑树
	void destroy();

	// 打印红黑树
	void print();

private:
	// 前序遍历"红黑树"
	void preOrder(RBTNode<T>* tree) const;
	// 中序遍历"红黑树"
	void inOrder(RBTNode<T>* tree) const;
	// 后序遍历"红黑树"
	void postOrder(RBTNode<T>* tree) const;

	// (递归实现)查找"红黑树x"中键值为key的节点
	RBTNode<T>* search(RBTNode<T>* x, T key) const;
	// (非递归实现)查找“红黑树x”中键值为key的节点
	RBTNode<T>* iterativeSearch(RBTNode<T>* X, T key) const;

	// 查找最小节点：返回tree为根节点的红黑树的最小节点。
	RBTNode<T>* minimum(RBTNode<T>* tree);
	// 查找最大节点：返回tree为根节点的红黑树的最大节点。
	RBTNode<T>* maximum(RBTNode<T>* tree);

	// 左旋
	void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
	// 右旋
	void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);
	// 插入函数
	void insert(RBTNode<T>* &root, RBTNode<T>* node);
	// 插入修正函数
	void inserFixUp(RBTNode<T>* &root, RBTNode<T>* node);
	// 删除函数
	void remove(RBTNode<T>* &root, RBTNode<T>* node);
	// 删除修正函数
	void removeFixUp(RBTNode<T>* &root, RBTNode<T>* node, RBTNode<T> *parent);

	//销毁红黑树
	void destroy(RBTNode<T>* &tree);

	//打印红黑树
	void printf(RBTNode<T>* tree, T key, int direction);

	#define rb_parent(r) ((r)->parent)
	#define rb_color(r) ((r)->color)
	#define rb_is_red(r)   ((r)->color==RED)
 	#define rb_is_black(r)  ((r)->color==BLACK)
 	#define rb_set_black(r) do { (r)->color = BLACK; } while(0);
 	#define rb_set_red(r)  do { (r)->color = RED; } while (0)
 	#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
 	#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};

//构造函数
template<class T>
RBTree<T>::RBTree():mRoot(NULL)
{
	mRoot = NULL;	//上面的已经赋值了，这里为啥还要？
}

//析构函数
template<class T>
RBTree<T>::~RBTree()
{
	destroy();
}

//前序遍历“红黑树”
template<class T>
void RBTree<T>::preOrder(RBTNode<T>* tree) const
{
	if(tree != NULL)
	{
		cout<< tree->key << " " ;
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template <class T>
void RBTree<T>::preOrder()
{
	preOrder(mRoot);
}

//中序遍历“红黑树”
template<class T>
void RBTree<T>::inOrder(RBTNode<T>* tree) const
{
	if(tree != NULL)
	{
		inOrder(tree->left);
		cout<< tree->key << " " ;
		inOrder(tree->right);
	}
}

template<class T>
void RBTree<T>::inOrder()
{
	inOrder(mRoot);
}

//后序遍历“红黑树”
template <class T>
void RBTree<T>::postOrder(RBTNode<T>* tree) const
{
	if(tree != NULL)
	{
		postOrder(tree->left)
		postOrder(tree->right)
		cout<< tree->key << " " ;
	}
}

template <class T>
void RBTree<T>::postOrder()
{
	postOrder(mRoot);
}


//(递归实现)查找“红黑树x”中键值为key的节点
template <class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key) const
{
	if(x == NULL || x ->key == key)
		return x;

	if(key < x->key)
		return search(x -> left, key);
	else
		return search(x -> right, key);
}

template <class T>
RBTNode<T>* RBTree<T>::search(T key)
{
	search(mRoot, key);
}

//(非递归实现)查找“红黑树”中键值为key的节点
template <class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const
{
	while ((x != NULL) && (x->key != key))
	{
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	return x;
}

template <class T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	iterativeSearch(mRoot, key);
}

//查找最小节点：返回tree为根节点的红黑树的最小节点。
template <class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while(tree->left != NULL)
		tree = tree->left;

	return tree;
}

template <class T>
T RBTree<T>::minimum()
{
	RBTNode<T>* p = minimum(mRoot);
	if( p != NULL)
		return p->key;

	return (T)NULL;
}

//查找最大节点：返回tree为根节点的红黑树的最大节点。
template<class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
	if(tree == NULL)
		return NULL;

	while(tree -> right != NULL)
		tree = tree -> right;

	return tree;
}

template<class T>
T RBTree<T>::maximum()
{
	RBTNode<T>* p = maximum(mRoot);
	if(p != NULL)
		return p->key;

	return (T)NULL;
}

//找节点(x)的后继节点。即，查找"红黑树中数据值大于该节点"的"最小节点"。
template <class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T>* x)
{
	//如果x存在右孩子，则"x的后继节点"为 "以其右孩子为根的子树的最小节点"。
	if(x->right != NULL)
		return minimum(x ->right);
	// 如果x没有右孩子。则x有以下两种可能：
    // (01) x是"一个左孩子"，则"x的后继节点"为 "它的父节点"。
    // (02) x是"一个右孩子"，则查找"x的最低的父节点，并且该父节点要具有左孩子"，
    //找到的这个"最低的父节点"就是"x的后继节
    
    RBTNode<T>* y = x->parent;
    while((y!=NULL) && (x==y->right))
    {
    	x = y;
    	y = y->parent;
    }

    return y;
}

//找结点(x)的前驱结点。即，查找"红黑树中数据值小于该结点"的"最大结点"。
template <class T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T>* x)
{
	//如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
	if(x -> left != NULL)
		return maximum(x -> left);

	// 如果x没有左孩子。则x有以下两种可能：
    // (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
    // (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，
	//找到的这个"最低的父结点"就是"x的前驱结点"。

	RBTNode<T>* y = x->parent;
	while((y!=NULL) && (x==y->left))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

 /* 
  * 对红黑树的节点(x)进行左旋转
  *
  * 左旋示意图(对节点x进行左旋)：
  *      px                              px
  *     /                               /
  *    x                               y                
  *   /  \      --(左旋)-->           / \                #
  *  lx   y                          x  ry     
  *     /   \                       /  \
  *    ly   ry                     lx  ly  
  *
  *
  */
 
template <class T>
void RBTree<T>::leftRotate(RBTNode<T>* &root, RBTNode<T>* x)
{
	// 设置x的右孩子为y
	RBTNode<T>* y = x -> right;
	// 将 “y的左孩子” 设为 “x的右孩子”；
    // 如果y的左孩子非空，将 “x” 设为 “y的左孩子的父亲”
    x->right = y->left;
    if (y->left != NULL)
    	y->left->parent = x;

    // 将“x的父亲”设为“y的父亲”
    y->parent = x->parent;

    if(x->parent == NULL)
    {
    	root = y;	//如果 “x的父亲” 是空节点，则将y设为根节点
    }
    else
    {
    	if(x->parent->left == x)
    		x->parent->left = y;	// 如果 x是它父节点的左孩子，则将y设为“x的父节点的左孩子”
    	else
    		x->parent->right = y;	// 如果 x是它父节点的右孩子，则将y设为“x的父节点的右孩子”
    }

    //将“x"设为“y的左孩”
    y->left = x;
    // 将 “x的父节点” 设为 “y”
    x->parent = y;
}

/* 
  * 对红黑树的节点(y)进行右旋转
  *
  * 右旋示意图(对节点y进行右旋)：
  *            py                               py
  *           /                                /
  *          y                                x                  
  *         /  \      --(右旋)-->            /  \                     #
  *        x   ry                           lx   y  
  *       / \                                   / \                   #
  *      lx  rx                                rx  ry
  * 
  */
 template <class T>
 void RBTree<T>::rightRotate(RBTNode<T>* &root, RBTNode<T>* y)
 {
     // 设置x是当前节点的左孩子。
     RBTNode<T> *x = y->left;
 
     // 将 “x的右孩子” 设为 “y的左孩子”；
     // 如果"x的右孩子"不为空的话，将 “y” 设为 “x的右孩子的父亲”
     y->left = x->right;
     if (x->right != NULL)
         x->right->parent = y;
 
     // 将 “y的父亲” 设为 “x的父亲”
     x->parent = y->parent;
 
     if (y->parent == NULL) 
     {
         root = x;            // 如果 “y的父亲” 是空节点，则将x设为根节点
     }
     else
     {
         if (y == y->parent->right)
             y->parent->right = x;    // 如果 y是它父节点的右孩子，则将x设为“y的父节点的右孩子”
         else
             y->parent->left = x;    // (y是它父节点的左孩子) 将x设为“x的父节点的左孩子”
     }
 
     // 将 “y” 设为 “x的右孩子”
     x->right = y;
 
     // 将 “y的父节点” 设为 “x”
     y->parent = x;
}

#endif