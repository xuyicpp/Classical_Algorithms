//使用string，必须要包含头文件string.h
//C++中，最好使用string来代替char[ ]
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;
//定义和结构初始化
//string 提供了很多构造函数，可以以多种方式来初始化string字符串
void init();
//赋值，拼接字符串
//string重载了 =  +   +=  等多种运算符，让字符串组合拼接更简单
void splitjoint();
//访问字符操作
//string可以按数组方式，以下标来访问。还可以用at()函数访问指定的字符
void AccessCharacters();
//可以使用 STL 的接口
//可以把 string 理解为一个特殊的容器，容器中装的是字符
void container();
//比较操作 ==  !=  >  >=  <  <=  compare 等
//string的比较操作，按字符在字典中的顺序进行逐一比较。
//在字典前面的字符小于后面的字符。
void compare();
//查找 find  rfind   
//string中除了find、rfind，还有find_first_of等函数也提供了强大的查找功能
void Find_String();
//C++中有strstr、strchr等也有查找功能。函数说明如下 need #include <string.h>
//char *strstr( const char *str, const char *substr );  返回指针，指向substr在字符串str中首次出现的位置。 
//char *strchr( const char *str, int ch );  返回指针，指向 str 中字符ch 首次出现的位置。 
void Char_Find_String();
//与 char[ ] 的相互转换
//copy()，返回指针，赋值给char[ ]数组名
//c_str() ，返回 const 类型的指针
//data() ，将内容以字符数组的形式返回
void Change_to_char();
//分割字符串常用 strtok 和 substr 来分割字符串
void Split();
//string 大小分配函数
//capacity() ，返回容器在它已经分配的内存中可以容纳多少元素
//resize(Container::size_type n)，强制把容器改为容纳n个元素
void Capacity();
//string 中的字符替换、删除操作
void Replace_Delete();
//char[ ] 常用的比较、拼接字符串功能
//任意字符查找：char *strpbrk( const char *str1, const char *str2 );
//内存拷贝：void *memcpy( void *to, const void *from, size_t count );
//如果 to 和 from 重叠，则函数行为不确定。
//memset() 对内存初始化。如：memset( array, '\0', sizeof(array) );
//这是将数组的所以元素设置成零的很方便的方法 
void Common_Function();


int main()
{
	//init();
	//splitjoint();
	//AccessCharacters();
	//container();
	//compare();
	//Find_String();
	//Char_Find_String();
	//Change_to_char();
	//Split();
	//Capacity();
	//Replace_Delete();
	Common_Function();
	return 0;
} 

void init()
{
	string str1 = "yesterday once more";
	string str2 ("my heart go on");
	string str3 (str1, 6);		// = day once more
	string str4 (str1, 6, 3);	// = day

	char ch_music[] = {"Roly-Poly"};

	string str5 = ch_music;
	string str6 (ch_music);
	string str7 (ch_music, 4);	// = Roly
	string str8 (10, 'i');		// = iiiiiiiiii
	string str9 (ch_music + 5, ch_music + 9);	// = Poly

	

	string str10 = {"RUA"};
	string str11 {"RUA RUA"};	//C++11A

	cout<<str10<<str11<<endl;


	str9.~string();			//销毁字符，释放内存，这个释放内存的操作得放在最后
	return;
}

void splitjoint()
{
	string str = "A women appreciates";
	string str2 = "a man who can make her laugh";
	string strlove = str + str2;

	str += str2;

	str.push_back('.');
	cout<<str<<endl;
	str.append(" -RUA");
	cout<<str<<endl;
	str.assign("dream come ture");	//重新赋值
	cout<<str<<endl;
	str.insert(10, "!!!!");	//在指定位置 插入字符
	cout<<str<<endl;
	return;
}

void AccessCharacters()
{
	string strip = {"iPhone 8"};
	cout << strip[2] <<endl;		// = h
	cout << strip.at(5) <<endl;			// = e

	string stuff;
	//getline(cin, stuff);	//输入一行字符， 赋值给stuff
	//getline(cin, stuff, '!');		//输入一行字符，赋值给stuff, 以!结束

	return;
}

void container()
{
	string str;

	str.push_back('Q');
	str.push_back('A');

	string::iterator itstr = str.begin();

	for( ;itstr != str.end(); itstr++)
	{
		cout << *itstr;
	}

	cout<<endl;

	sort(str.begin(), str.end());	//排序 要头文件 algorithm

	itstr = str.begin();
	for( ;itstr != str.end(); itstr++)
	{
		cout << *itstr;
	}

	cout<<endl;

	str.pop_back();

	itstr = str.begin();
	for( ;itstr != str.end(); itstr++)
	{
		cout << *itstr;
	}

	cout<<endl;
}

void compare()
{
	string str = "hehe";
	if(str < "hello")
	{
		cout<< "hehe 小于 hello"<<endl;
	}

	string str2 = "anhui";
	string str3 = "hunan";
	string str4 = "nanjing";

	if(str2 >= str3 || str2 == str4)
	{
		cout<<"安徽-南京-湖南";
	}

	str2.compare("anhui");	//相等
	str2.compare("str3");	//相等返回0 大于返回正数 小于返回负数

	str3.compare(2,2, str4, 2,2);	//na比较nj

	cout<<str4.compare(3,4, "jing", 4)<<endl;		//jing == jing 输出0

	return;
}

//need #include <string.h>
void Find_String()
{
	string str = "when i was young, i listen to the radiao.";
	string::size_type position;

	//find函数返回listen在str中第一次出现的下标位置
	position = str.find("listen");

	if(position != str.npos)	//如果没找到，返回npos，这个值很大4294967295
	{
		cout<<"第一次出现的下标是 "<< position <<endl;
	}

	//从字符串 str 下标 9 开始,查找字符串you,返回you在str中的下标
	position = str.find("you", 9);
	cout<< "str.find(you, 9) is : "<<position << endl;

	string substr = "i";
	position = 0;
	int i = 1;
	while((position = str.find_first_of(substr, position)) != string::npos)
	{
		//查找str中substr出现的所有位置
		cout<<"position "<<i++<<" : "<<position<<endl;
		++position;
	}

	string flag = "to";
	position = str.rfind(flag);	//反向查找，flag 在 str中最后出现的位置
	cout << "str.rfind(flag) ："<< position << endl;
	return;
}

void Char_Find_String()
{
	char str[] = {"keep your decide in mind, not change except for your parents."};
	const char *psubstr = "your";

	char * p = strstr(str, psubstr);	//如果没找到 返回NULL
	if(p)
	{
		cout<<"找到了字符串，下标为 "<< p -str <<endl;
	}

	p = strchr(str, 'f');
	if(p)
	{
		cout<<"找到了字符，从该字符开始的字符串为 "<<p<<endl;
	}

	p = strrchr(str, 'e');	//从后往前找，如果没找到 返回NULL
	if(p)
	{
		cout<<"找到了字符，从该字符开始的字符串为"<<p<<endl;
	}

	return;
}

void Change_to_char()
{
	char strch[] = {"shrimp"};

	string str = strch;		// char[] 可以直接赋值给string
	cout<< str <<endl;

	str = "fish";
	strcpy(strch, str.c_str());
	cout<< strch <<endl;

	str = "duck";
	str.copy(strch, str.length(), 0);	//可指定拷贝的位置和字符个数
	cout<< strch <<endl;

	str = "chicken";
	strcpy(strch, str.data());		// data()返回指向自己的第一个字符的指针
	cout<< strch <<endl;
	return;
}

void Split()
{
	char str[] = "a,b,c,d*e flower";
	const char * split = " ,*";		//以[空格,*]三个字符来分割
	char * p;

	p = strtok(str, split);

	while(p != NULL)
	{
		cout<< p <<"\n";
		p = strtok(NULL, split);
	}

	string city = "nanjingshanghai";
	string strsh = city.substr(7, 8);	//提取子串
	cout<<strsh<<endl;
	return;
}

void Capacity()
{
	string str = "spring-summer-autumn-winter";

	int isize = str.size();			//容器中有多少元素
	int lenth = str.length();		//和size函数功能相同
	int maxsize = str.max_size();	//字符串可能的最大大小

	//在不重新分配内存的情况下，字符串可能的大小
	int cpsize = str.capacity();	//容器在它已经分配的内存中可以容纳多少元素

	if(str.empty())		//判断是否为空
	{
		cout<<"字符串为空!";
	}

	//提前预留一定容量大小，避免多次容量扩充操作导致效率低下
	str.reserve();

	str.resize(2014);		//强制把容器改为容纳n个元素
	cout << str.length() <<endl;

	return;
}

void Replace_Delete()
{
	string str = "standard lover";
	string str2 = "gates of down";
	str.swap(str2);		//交换
	cout << str <<endl;

	string strtemp = "OF";
	str.replace(6, strtemp.length(), strtemp);	//替换字符串 有多种形参格式
	cout<< str<<endl;

	str.erase(2, 4);	//删除index = 2 , 长度为4的字符串
	cout<< str <<endl;

	str.erase();	//删除整个字符串
	str2.clear();	//清空字符容器中所有内容

	return;
}

void Common_Function()
{
	char from[] = {"rain"};
	char to[100] = {"snow"};

	//strcmp to==from,返回值等于0  to<from,返回值小于0
	if(strcmp(to, from) > 0)
	{
		cout<< "to 大于 from" <<endl;
	}

	strcat(to, from);	//将字符串 from 链接到 to 的末端,并返回指针 to
	cout<< to <<endl;	// = snowrain

	//返回一个指针，指向 from 中  任意字符  在to中首次出现的位置，如不存在返回NULL
	char *p = strpbrk(to, from);
	cout<< p <<endl;	// = nowrain

	memset(to, 0, strlen(to));		//可以应用在将一段内存初始化为某个值

	//从from中复制strlen(from)个字符到to中，并返回to指针
	memcpy(to, from, strlen(from));

	cout<< to <<endl;

	return;
}