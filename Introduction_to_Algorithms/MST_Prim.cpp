#include <iostream>

#define MAX 10000
#define POINTNUM 9

using namespace std;

char VECCHAR[] = {'a','b','c','d','e','f','g','h','i'};

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

struct node
{
	int data;
	int minCost;
}closeEdge[POINTNUM];	//Prim算法中的辅助信息

int minmum(node* closeEdge)
{
	int min = MAX;
	int index = -1;
	for (int i = 0; i < POINTNUM; ++i)
	{
		if(closeEdge[i].minCost < min && closeEdge[i].minCost != 0)
		{
			min = closeEdge[i].minCost;
			index = i;
		}
	}

	return index;
}

void MST_Prim(int adjMatCost[][POINTNUM], int s)
{
	for (int i = 0; i < POINTNUM; ++i)
	{
		closeEdge[i].minCost = MAX;
	}
	closeEdge[s].data = s;	//从顶点s开始
	closeEdge[s].minCost = 0;
	for (int i = 0; i < POINTNUM; ++i)
	{
		if(i != s)
		{
			closeEdge[i].data = s;
			closeEdge[i].minCost = adjMatCost[s][i];
		}
	}

	for(int e = 1; e <= POINTNUM - 1; ++e)
	{
		int k = minmum(closeEdge);	//选择最小边
		cout << VECCHAR[closeEdge[k].data] << "--" <<VECCHAR[k] << endl;
		closeEdge[k].minCost = 0;	//代价置为0
		for (int i = 0; i < POINTNUM; ++i)
		{
			if (adjMatCost[k][i] < closeEdge[i].minCost)
			{
				closeEdge[i].data = k;
				closeEdge[i].minCost = adjMatCost[k][i];
			}
		}
	}
	return;
}

int main()
{
	int adjMat[POINTNUM][POINTNUM] = { 0 };
	init(adjMat);
	MST_Prim(adjMat,0);
	return 0;
}