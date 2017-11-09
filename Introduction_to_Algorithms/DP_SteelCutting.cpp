/**
 *	@description 钢条切割问题：给定一段长度为n英寸的钢条和一个价格表Pi(i=1,2,..., n),
 *	             求切割方案，使销售收益rn最大。
 *	@author XY
 *  @data 20171108
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void init();
void print_cut_rod_solution();
//自底向上
int extended_bottom_up_cut_rod(int n);
//自上向下
int extended_cut_rod_aux(int n);
int totalPrice;

vector<int> price_sheet = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
//这里还有细微不同
vector<int> result_up(11,-1);
vector<int> result_bottom(11,0);
vector<int> result_length_up(11,0);

int main()
{
	init();
	int i = 10;

	extended_bottom_up_cut_rod(i);
//	extended_cut_rod_aux(i);

	print_cut_rod_solution();
	return 0;
}

void init()
{
	
	return;
}

void print_cut_rod_solution()
{
	for(auto a : price_sheet)
		cout<< a <<" ";
	cout<<endl;
	for(auto a : result_up)
		cout<< a <<" ";
	cout<<endl;
	for(auto a : result_bottom)
		cout<< a <<" ";
	cout<<endl;
	for(auto a : result_length_up)
		cout<< a <<" ";
	cout<<endl;
	return;
}

int extended_cut_rod_aux(int n)
{
	int q;
	if(result_up[n] >= 0)
		return result_up[n];

	if(n == 0)
	{
		q = 0;
	}
	else
	{
		q = -1;
		for(int i = 1; i <= n; ++i)
		{
			//这里保留最优解对应的第一段钢条的切割长度
			if((price_sheet[i] + extended_cut_rod_aux(n-i)) > q)
				result_length_up[n] = i;
			q = max(q, price_sheet[i] + extended_cut_rod_aux(n-i));
		}
	}

	result_up[n] = q;
	return q;
}

int extended_bottom_up_cut_rod(int n)
{
	for(int j = 1; j <= n; ++j)
	{
		int q = -1;
		for(int i = 1; i <= j; ++i)
		{
			if(q < price_sheet[i] + result_bottom[j-i])
			{
				q = price_sheet[i]+result_bottom[j-i];
				result_length_up[j] = i;
			}		
		}
		result_bottom[j] = q;
	}
	return result_bottom[n];
}