/**
 *	@author XY
 *  @date 20171210
 *  @description 算法导论P344
 */

#include <iostream>
#include <queue>
#include <vector>
#define NUM 8

using namespace std;

char transChar[] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};

struct node
{
	string color;
	int id;
	int value;
	node* pre;
};

void init(vector<vector<int> > &adjMat, vector<node*> &vec)
{
	adjMat[0].push_back(1);
	adjMat[0].push_back(4);
	adjMat[1].push_back(0);
	adjMat[1].push_back(5);
	adjMat[2].push_back(3);
	adjMat[2].push_back(5);
	adjMat[2].push_back(6);
	adjMat[3].push_back(2);
	adjMat[3].push_back(6);
	adjMat[3].push_back(7);
	adjMat[4].push_back(0);
	adjMat[5].push_back(1);
	adjMat[5].push_back(2);
	adjMat[5].push_back(6);
	adjMat[6].push_back(2);
	adjMat[6].push_back(3);
	adjMat[6].push_back(5);
	adjMat[6].push_back(7);
	adjMat[7].push_back(3);
	adjMat[7].push_back(6);
	for (int i = 0; i < NUM; ++i)
	{
		node* v = new node;
		v->color = "WHITE";
		v->id = i;
		v->value = -1;
		v->pre = nullptr;
		vec.push_back(v);
	}
	return;
}

void BFS(vector<vector<int> > &adjMat, vector<node*> vec, int strat)
{
	vec[strat]->color = "BLACK";
	vec[strat]->value = 0;
	vec[strat]->id = strat;
	cout<< "Begin from: "<< transChar[strat] <<" : " << vec[strat]->value << endl;
	queue<node*> que;
	que.push(vec[strat]);
	while(que.size() > 0)
	{
		node* temp = que.front();
		que.pop();
		int tempId = temp -> id;
		for (int i = 0; i < adjMat[tempId].size(); ++i)
		{
			if(vec[adjMat[tempId][i]]->color == "WHITE")
			{
				vec[adjMat[tempId][i]]->color = "BLACK";
				vec[adjMat[tempId][i]]->value = temp->value + 1;
				vec[adjMat[tempId][i]]->pre = temp;
				que.push(vec[adjMat[tempId][i]]);
				cout<< transChar[adjMat[tempId][i]] <<" : " << vec[adjMat[tempId][i]]->value << endl;
			}
		}
	}
	return;
}

int main()
{
	vector<vector<int> > Tree(NUM);
	vector<node*> vec;
	init(Tree,vec);
	BFS(Tree, vec, 1);
	return 0;
}