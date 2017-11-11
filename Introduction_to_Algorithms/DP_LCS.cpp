/**
 *	@description 最长公共子序列问题(longest common subsequence problem)给定两个序列 X=(x1, x2, ...,xm)和
 *	Y = (y1, y2, ..., yn),求X和Y长度最长的公共子序列。			  
 *	@author XY
 *  @data 20171109
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void init();
void LCS_length();
void print_LCS(int i, int j);

char X[7] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
char Y[6] = {'B', 'D', 'C', 'A', 'B', 'C'};
char b[8][7];
int c[8][7];

int main()
{
	init();
	LCS_length();
	print_LCS();
	return 0;
}

void init()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			c[i][j] = 0;
			b[i][j] = 'q';
		}
	}
	return;
}

void LCS_length()
{
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if(X[i] == Y[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = '+';

			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 'N';
			}
			else
			{
				c[i][j] = c[i][j-1]
				b[i][j] = 'W'
			}
		}
	}
	return;
}

void print_LCS(int i, int j)
{
	if(i ==0 && j ==0)
		return;
	if(b[i][j] == '+')
	{
		print_LCS(i-1,j-1);
		cout<<X[i];
	}
	else if(b[i][j] == 'N')
	{
		print_LCS(i-1,j);
	}
	else if(b[i][j] == 'W')
	{
		print_LCS(i,j-1);
	}


}