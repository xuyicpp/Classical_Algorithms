#include <iostream>
#include <vector>

using namespace std;

//在这里，数组排序是从0开始的。
//同时，整数的范围不可能都是从0开始，所以在这我定义了一个平移量RUA
int main()
{
	int RUA=1;	//平移位
	vector<int> v={9,8,8,7,6,3,2,1};
	vector<int> temp(9,0);
	vector<int> b(v.size(),0);

	for(auto a : v)
		++temp[a-RUA];

	for(int a = 0; a < temp.size() - 1; a++)
		temp[a + 1] += temp[a];

	for(auto a : v)
		b[--temp[a-RUA]] = a;

	for(auto a : v)
		cout<< a <<" ";

	cout << endl;

	for(auto t : b)
		cout<< t << " ";
	cout <<endl;

	return 0;
}