//Randomized BST Sort
//1.randomly permute the array A
//2.BST sort(A)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BST
{
public:
	class node
	{
	public:
		node() {left = right = nullptr; }
		int data;
		node* left;
		node* right;
	};

public:
	BST() { root = nullptr; };
	BST(int item) { root = nullptr; root->data = item; }
	bool empty() const;
	void Insert(int value);
	void Search(int item, bool &found, node* &pre, node* &p);
//	void Delete(int item);
	void Inorder(node* p) const;
	node* getroot();
private:
	node* root;	
};

int main()
{
	vector<int> RUA = {5,4,3,2,1};
	for(auto a : RUA)
		cout << a << " ";
	cout << endl;

	// STL中的函数random_shuffle()用来对一个元素序列进行重新排序（随机的）
	random_shuffle(RUA.begin(),RUA.end());

	for(auto a : RUA)
	cout << a << " ";
	cout << endl;

	BST bbb;
	for(auto a : RUA)
	{
		bbb.Insert(a);
	}
	bbb.Inorder(bbb.getroot());

	cout<<endl;

	return 0;
}

bool BST::empty() const
{
	return (root == nullptr);
}

void BST::Insert(int value)
{
	bool found = false;
	node* p = root;
	node* pre = p;
	Search(value, found, pre, p);
	if(found)
		cout<< "The value has been in the BST"<<endl;
	else
	{
		node* n = new node();
		n -> data = value;
		if(empty())
			root = n;
		else
		{
			if(value < pre->data)
				pre->left = n;
			if(value > pre->data)
				pre->right = n;
		}
	}
}

void BST::Search(int item, bool &found, node* &pre, node* &p)
{
	for(; ;)
	{
		if(found||p==nullptr)
			break;
		else
		{
			if(item < p->data)
			{
				pre = p;
				p = p->left;
			}
			else if(item > p->data)
			{
				pre = p;
				p = p->right;
			}
			else
				found = true;
		}
	}
}

void BST::Inorder(node* p) const
{
	if(p != nullptr)
	{
		Inorder(p->left);
		cout<< p->data <<" ";
		Inorder(p->right);
	}

}

BST::node* BST::getroot()
{
	return root;
}