#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	char value;
	int priority;
	Node *lchild,*rchild;

	Node(){ }
	Node(char val, int pri)
	{
		value = val;
		priority = pri;
		lchild = nullptr;
		rchild = nullptr;
	}
};

bool compareNode(Node* n1,Node* n2)
{
	return n1->priority < n2->priority;
}

Node* buildHuffmanTree(vector<Node*> vctNode)
{
	while(vctNode.size() > 1)
	{
		sort(vctNode.begin(),vctNode.end(),compareNode);

		Node *first = vctNode[0];
		Node *second = vctNode[1];
		Node *merge = new Node();
		merge->priority = first->priority + second->priority;
		merge->lchild = first;
		merge->rchild = second;

		vector<Node*>::iterator iter;
		iter = vctNode.erase(vctNode.begin(),vctNode.begin()+2);
		vctNode.push_back(merge);
	}
	return vctNode[0];
}

void printHuffman(Node *node,vector<int> vctNode)
{
	if(node->lchild == nullptr && node->rchild == nullptr)
	{
		cout<< node->value << ": ";
		for(vector<int>::iterator iter = vctNode.begin(); iter!=vctNode.end(); iter++)
		{
			cout<<*iter;
		}
		cout<<endl;
		return;
	}
	else
	{
		vctNode.push_back(0);
		printHuffman(node->lchild,vctNode);
		vctNode.pop_back();
		vctNode.push_back(1);
		printHuffman(node->rchild,vctNode);
		vctNode.pop_back();
	}
}

int main()
{
	vector<Node*> vctNode;        //存放Node结点的vector容器vctNode
	Node* tempa = new Node('a',45);
	Node* tempb = new Node('b',13);
	Node* tempc = new Node('c',12);
	Node* tempd = new Node('d',16);
	Node* tempe = new Node('e',9);
	Node* tempf = new Node('f',5);
	vctNode.push_back(tempa);
	vctNode.push_back(tempb);
	vctNode.push_back(tempc);
	vctNode.push_back(tempd);
	vctNode.push_back(tempe);
	vctNode.push_back(tempf);
	Node* root = buildHuffmanTree(vctNode);
	vector<int> vctchar;
	printHuffman(root,vctchar);
	return 0;
}