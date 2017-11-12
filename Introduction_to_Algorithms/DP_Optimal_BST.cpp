/**
 *	@description 而现实生活中，查找的关键字是有一定的概率的，就是说有的关键字可能经常被搜索，而有的很少被搜索，而且搜索的关键字可
 *	能不存在，为此需要根据关键字出现的概率构建一个二叉树。比如中文输入法字库中各词条（单字、词组等）的先验概率，
 *	针对用户习惯可以自动调整词频——所谓动态调频、高频先现原则，以减少用户翻查次数，使得经常用的词汇被放置在前面，
 *	这样就能有效地加快查找速度。这就是最优二叉树所要解决的问题。			  
 *	@author XY
 *  @data 20171112
 */

#include <iostream>

using namespace std;

#define MAX 999999.99999
#define N 5

void optimal_binary_search_tree(double *p, double *q, int n, double e[N+2][N+1],int root[N+1][N+1]);
void show_optimal_bst(int root[N+1][N+1], int i, int j);
void init();

double p[N+1] = {0,0.15,0.10,0.05,0.10,0.20};
double q[N+1] = {0.05,0.10,0.05,0.05,0.05,0.10};
double e[N+2][N+1];
int root[N+1][N+1];

int main()
{
	init();
	optimal_binary_search_tree(p,q,N,e,root);
	cout<<"最优二叉查找树的代价为: "<<e[1][N]<<endl;
	show_optimal_bst(root,1,N);
	return 0;
}

void init()
{

	return;
}

void optimal_binary_search_tree(double *p, double *q, int n, double e[N+2][N+1],int root[N+1][N+1])
{
	int j;
	double t;
	double w[N+2][N+1];
	for (int i = 1; i <= N+1; ++i)	//主表和根表元素的初始化
	{
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}

	for (int k = 1; k <= n; ++k)	//自底向上寻找最优子树
	{
		for (int i = 1; i <= n-k+1; ++i)
		{
			j = i+k-1;
			e[i][j] = MAX;
			w[i][j] = w[i][j-1] + p[j] + q[j];

			for (int r = i; r <= j; ++r)	//找最优根
			{
				t = e[i][r-1] + e[r+1][j] + w[i][j];

				if(t < e[i][j])
				{
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
	return;
}

void show_optimal_bst(int root[N+1][N+1], int i, int j)
{
	if(i==1 && j==N)
		cout<<"k"<<root[1][N]<<"是根"<<endl;
	if(i < j)
	{
		int r = root[i][j];

        if(r != i)
            cout<<"k"<<root[i][r-1]<<"是k"<<r<<"的左孩子"<<endl;

        show_optimal_bst(root,i,r-1);
        
        if(r!= j)
        	cout<<"k"<<root[r+1][j]<<"是k"<<r<<"的右孩子"<<endl;

        show_optimal_bst(root,r+1,j);
    }
    if(i==j)
    {
        cout<<"d"<<i-1<<"是k"<<i<<"左孩子"<<endl;
        cout<<"d"<<i<<"是k"<<i<<"右孩子"<<endl;
    }
    if(i>j)
        cout<<"d"<<j<<"是k"<<j<<"右孩子"<<endl;
	
	return;
}
