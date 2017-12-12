# Classical_Algorithm
- Introduction to Algorithm [算法导论笔记](https://github.com/xuyicpp/Classical_Algorithms/tree/master/Introduction_to_Algorithms)

- C++中的vector使用规范 [BLOG](https://wenku.baidu.com/view/4bb4ea03a45177232e60a20f.html)

- C++中string的用法 [BLOG](https://jingyan.baidu.com/article/20b68a8854f919796dec6265.html)

/定义和结构初始化
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

