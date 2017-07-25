#include <iostream>
#include <vector>

using namespace std;

long Fibonacci_naive_reu(int n);//朴素递归算法
long Fibonacci_bottom_up(int n);//自底向上算法
void Matrix_power(int n,long Result[2][2]);
void MUL( long MatrixA[2][2],long MatrixB[2][2], 
long MatrixResult[2][2] );//矩阵相乘

long Result[2][2] = {0,0,0,0};


int main()
{
	cout<<"Fibonacci 10: ";
	
	for(int i = 0; i<10; ++i)
	{
		cout<<Fibonacci_naive_reu(i)<<" ";
	}

	cout<<endl;

	for(int i = 0; i<10; ++i)
	{
		cout<<Fibonacci_bottom_up(i)<<" ";
	}

	cout<<endl;

	cout<<"0 1 ";
	for(int i = 1; i<9; ++i)
	{
		Matrix_power(i,Result);
		cout<<Result[0][0]<<" ";
	}


	return 0;
}

long Fibonacci_naive_reu(int n)//朴素递归算法
{
     vector<int>  v = {0,1};
     if (n<2)       //退出条件
        return v[n];
 
     return (Fibonacci_naive_reu(n-1)+ Fibonacci_naive_reu(n-2));//递归调用
}

long Fibonacci_bottom_up(int n)//自底向上算法
{
	vector<int>  v = {0,1};

	long fib_n , fib_n0 = 0, fib_n1 = 1;

	if(n<2)
		return v[n];


	for(int i=1;i < n;++i)
	{
		fib_n = fib_n1+fib_n0;
		fib_n0 = fib_n1;
		fib_n1 = fib_n;
	}

	return fib_n; 
}

/**********************************************************************/
 /*  下面矩阵的n次幂，结果保存在      Result[2][2]                   */
 //   矩阵的n次幂，采用分治法，与x的n 次方算法一致，时间复杂度T(n)=o(logn)
 //    1    1
 //    1    0
 /************************************************************************/
 void Matrix_power(int n,long Result[2][2])//求矩阵幂
 {
      long AResult[2][2];
      long zResult1[2][2];
      long zResult2[2][2];
 
     AResult[0][0]=1;AResult[0][1]=1;AResult[1][0]=1;AResult[1][1]=0;
     if (1==n)
     {
         Result[0][0]=1;Result[0][1]=1;Result[1][0]=1;Result[1][1]=0;
     }	
     else if (n%2==0)
     {
         Matrix_power(n/2,zResult1);
         MUL(zResult1,zResult1,Result);
     }
     else if (n%2 == 1)
     {
         Matrix_power((n-1)/2,zResult1);
         MUL(zResult1,zResult1,zResult2);
         MUL(zResult2,AResult,Result);
     }
 }

/***********************************************************************/
 /* 两个 矩阵相乘  、结果矩阵保存在 MatrixResult[2][2]中       */
 /************************************************************************/
 void MUL( long MatrixA[2][2],long MatrixB[2][2], long MatrixResult[2][2] )//矩阵相乘
 {
     for (int i=0;i<2 ;i++)
     {
         for (int j=0;j<2 ;j++)
         {
             MatrixResult[i][j]=0;
             for (int k=0;k<2 ;k++)
             {
                 MatrixResult[i][j]=MatrixResult[i][j]+MatrixA[i][k]*MatrixB[k][j];
             }
         }
     }
 }
