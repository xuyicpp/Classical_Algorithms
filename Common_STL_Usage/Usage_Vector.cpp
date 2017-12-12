#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>	//可以使用memcpy(buffer, &vecHeight[0], vecHeight.size()*sizeof(int));这个函数

using namespace std;

bool LessSort (int a,int b);

int main()
{
	// Vector初始化  
	// vector<ElemType>创建一个空的vector  
	// vector<ElemType> c1(c2) 复制一个vector。  
	// vector <ElemType> c(n) 创建一个vector，含有n个数据，数据均已缺省构造产生。 
	// vector <ElemType> c(n, elem) 创建一个含有n个elem拷贝的vector。 	
	// vector <ElemType> c(beg,end) 创建一个以[beg;end)区间的vector
	vector<int> v1;

	vector<int> v3(4);

	vector<int> v2(v3);

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

	//c.assign(beg,end) 将[beg; end)区间中的数据赋值给c 
	//c.assign(n,elem)  将n个elem的拷贝赋值给c
	
	//c.at(idx)  传回索引idx所指的数据，如果idx越界，抛出out_of_range
	
	//c.back() 传回最后一个数据，不检查这个数据是否存在
	
	//c.begin()    返回指向容器第一个元素的迭代器
	
	//c.capacity() 返回容器所申请的内存的大小
	//Returns the number of elements that the container has currently allocated space for.
	
	//c.clear()         移除容器中所有数据。数组大小为0，内存不变
	//c.empty()         判断容器是否为空。为空返回1，否则返回0
	//c.erase(pos)        删除pos位置的数据//pos为指针，数组大小size减1，内存不变
	//c.erase(beg,end) 删除[beg,end)区间的数据// beg、end为指针，size减小，内存不变
	//c.front()         传回第一个数据。
	//c.insert(pos,elem) 在pos位置插入一个elem拷贝，传回新数据位置 
	//c.insert(pos,n,elem) 在pos位置插入n个elem数据,无返回值  
	//c.insert(pos,beg,end) 在pos位置插入在[beg,end)区间的数据。无返回值。 
	//c.pop_back()     删除最后一个数据。
	//c.push_back(elem) 在尾部加入一个数据。 
	//
	//c.resize(num)     重新设置该容器的大小
	//c.reserve(num)  重新设置预留空间的大小，功能类似resize，但有区别
	//c.size()         回容器中实际数据的个数
	//
	//c.begin()           返回指向容器第一个元素的迭代器  
	//c.end()            返回迭代器中末端元素的下一个，指向一个不存在元素的指针 
	//c.rbegin()  返回Vector尾部的逆迭代器  
	//c.rend()  返回Vector起始的逆迭代器
	//
	//==、!=、<、<=、>、>=      保持这些操作符惯有含义   
	//c[n]           返回v中位置为n的元素，下标不能添加元素，只能操作存在的元素
	//
	//c.~ vector <ElemType>() 销毁所有数据，释放内存，即：size()为0，内存capacity()为0 
	


	//使用reverse将元素翻转：需要头文件#include<algorithm>
	//reverse(vec.begin(),vec.end());将元素翻转(在vector中，如果一个函数中需要两个迭代器，
	//一般后一个都不包含.)
	vector<int> vtest = {1,2,3,4,5,6};
	cout<<"Before reverse: ";
	for(auto a : vtest)
		cout<< a << " ";
	cout<<endl<<"After reverse: ";
	reverse(vtest.begin(), vtest.end());
	for(auto a : vtest)
		cout<< a << " ";
	cout<<endl;

	cout<<"After sort: > 降序排序";
	sort(vtest.begin(),vtest.end(),LessSort);
	for(auto a : vtest)
		cout<< a << " ";
	cout<<endl;

	return 0;
}

bool LessSort (int a,int b) { return a > b; } 