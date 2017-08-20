#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// Vector初始化  
	// vector<ElemType>创建一个空的vector  
	// vector<ElemType> c1(c2) 复制一个vector。  
	// vector <ElemType> c(n) 创建一个vector，含有n个数据，数据均已缺省构造产生。 
	// vector <ElemType> c(n, elem) 创建一个含有n个elem拷贝的vector。 	
	// vector <ElemType> c(beg,end) 创建一个以[beg;end)区间的vector
	vector<int> v1;
	vector<int> v2(v3);
	vector<int> v3(4);
	vector<int> v4(3,6);
	vector<int> v5(v4.begin()+1,v4.end());

	cout<<"v1"<<": "<<v1.empty()<<endl;
	
	cout<<"v2"<<": ";
	for(auto a : v2)
		cout<<a<<" ";
	cout<<endl;

	cout<<"v3"<<": ";
	for(auto a : v3) 
		cout<<a<<" ";
	cout<<endl;

	cout<<"v4"<<": ";
	for(auto a : v4)
		cout<<a<<" ";
	cout<<endl;

	cout<<"v5"<<": ";
	for(auto a : v5)
		cout<<a<<" ";
	cout<<endl;

	//数组和vector相互转换
	int arrHeight[] = {1,2,3};
	vector<int> vecHeight(arrHeight, arrHeight + sizeof(arrHeight)/sizeof(int));

	//由于vector内部的数据是存放在连续的存储空间，
	//vector转数组事实上只需要获取vector中第一个数据的地址和数据的长度即可。
	//如果仅仅是传参，无需任何操作，直接传地址即可，如果要进行数据复制，可以借用内存拷贝函数“memcpy”
	int *buffer = new int[sizeof(arrHeight)];
	if(!vecHeight.empty())
	{
		memcpy(buffer, &vecHeight[0], vecHeight.size()*sizeof(int));
	}

	

	return 0;
}