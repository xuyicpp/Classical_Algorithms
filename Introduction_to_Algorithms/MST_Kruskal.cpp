#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000
#define POINTNUM 9

using namespace std;

char VECCHAR[] = {'a','b','c','d','e','f','g','h','i'};

struct Arc
{
	int u;
	int v;
	int cost;
};

void init(int adjMatCost[][POINTNUM])
{
	for (int i = 0; i < POINTNUM; ++i)
	{
		for (int j = 0; j < POINTNUM; ++j)
		{
			adjMatCost[i][j] = MAX;
		}
	}
	adjMatCost[0][1] = 4; adjMatCost[0][7] = 8;
	adjMatCost[1][0] = 4; adjMatCost[1][2] = 8; adjMatCost[1][7] = 11;
	adjMatCost[2][1] = 8; adjMatCost[2][8] = 2; adjMatCost[2][5] = 4; adjMatCost[2][3] = 7;
	adjMatCost[3][2] = 7; adjMatCost[3][5] = 14; adjMatCost[3][4] = 9;
	adjMatCost[4][3] = 9; adjMatCost[4][5] = 10;
	adjMatCost[5][6] = 2; adjMatCost[5][2] = 4; adjMatCost[5][3] = 14; adjMatCost[5][4] = 10;
	adjMatCost[6][7] = 1; adjMatCost[6][8] = 6; adjMatCost[6][5] = 2;
	adjMatCost[7][0] = 8; adjMatCost[7][8] = 7; adjMatCost[7][1] = 11; adjMatCost[7][6] = 1;
	adjMatCost[8][2] = 2; adjMatCost[8][7] = 7; adjMatCost[8][6] = 6;
	return;
}

void readAdj(int adjMat[][POINTNUM], vector<Arc> &vecArc)
{
	Arc* temp = nullptr;
	for (int i = 0; i < POINTNUM; ++i)
	{
		for (int j = 0; j < POINTNUM; ++j)
		{
			if (adjMat[i][j] != MAX)
			{
				temp = new Arc;
				temp->u = i;
				temp->v = j;
				temp->cost = adjMat[i][j];
				vecArc.push_back(*temp);
			}
		}
	}
	return;
}

bool compare(Arc A, Arc B)
{
	return A.cost < B.cost ? true : false;
}

bool findTree(int u, int v,vector<vector<int> > &Tree)
{
	int index_u = MAX;
	int index_v = MAX;
	//检查u,v分别属于那棵树
	for (int i = 0; i < Tree.size(); ++i)
	{
		if(find(Tree[i].begin(), Tree[i].end(), u) != Tree[i].end())
			index_u = i;
		if(find(Tree[i].begin(), Tree[i].end(), v) != Tree[i].end())
			index_v = i;
	}
	//u,v不在一棵树上，合并两棵树
	if(index_u != index_v)
	{
		for (int i = 0; i < Tree[index_v].size(); ++i)
		{
			Tree[index_u].push_back(Tree[index_v][i]);

		}
		Tree[index_v].clear();
		cout << Tree[index_v][0] << "rua ";
		return true;
	}
	return false;
}

void MST_Kruskal(int adjMat[][POINTNUM])
{
	std::vector<Arc> vec;
	readAdj(adjMat, vec);	//读取边信息
	sort(vec.begin(), vec.end(), compare);	//边按从小到大排序
	vector<vector<int> > Tree(POINTNUM);	//9颗独立树
	for (int i = 0; i < POINTNUM; ++i)
	{
		Tree[i].push_back(i);	//初始化9颗独立树的信息
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		int u = vec[i].u;
		int v = vec[i].v;
		if(findTree(u, v, Tree))
		{
			cout<< VECCHAR[u] << "---" <<VECCHAR[v] <<endl;
		}
	}
}

int main()
{
	int adjMat[POINTNUM][POINTNUM] = { 0 };
	init(adjMat);
	MST_Kruskal(adjMat);
	return 0;
}