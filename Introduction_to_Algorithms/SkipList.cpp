 //                                                          _ooOoo_
 //                                                         o8888888o
 //                                                         88" . "88
 //                                                         (| -_- |)
 //                                                          O\ = /O
 //                                                      ____/`---'\____
 //                                                    .   ' \\| |// `.
 //                                                     / \\||| : |||// \
 //                                                   / _||||| -:- |||||- \
 //                                                     | | \\\ - /// | |
 //                                                   | \_| ''\---/'' | |
 //                                                    \ .-\__ `-` ___/-. /
 //                                                 ___`. .' /--.--\ `. . __
 //                                              ."" '< `.___\_<|>_/___.' >'"".
 //                                             | | : `- \`.;`\ _ /`;.`/ - ` : | |
 //                                               \ \ `-. \_ __\ /__ _/ .-` / /
 //                                       ======`-.____`-.___\_____/___.-`____.-'======
 //                                                          `=---='
 //
 //                                       .............................................
 //                                              佛祖保佑             永无BUG
 //                                              

#include <iostream>
//这里的最大值最小值用了climits中的，其实可以自己define的
#include <climits>
#include <cstdlib>
#include <climits>

using namespace std;

/**
 *	@author XY
 *  @date 2017-11-2
 *  @descriptin 简单跳跃表，key值是int默认是升序，
 *              有头节点INT_MIN，和尾节点INT_MAX(但是尾节点,我们这里并没有用)
 *              每个节点包含四个指针，但有可能为nullptr
 */

/**
 * 	1. 默认构造函数主要是用来完成如下形式的初始化的：1 testClass classA; // 或者  testClass *classA = new testClass;
 * 	2. 如果程序猿没有定义任何构造函数，则编译器会自动定义默认构造函数，其形式如  testClass() {};   可以看出，编译器自动提供的默认构造函数是 啥也没有啊 ；
	3. 定义默认构造函数有两种方式，如上述代码展示的，一是定义一个无参的构造函数，二是定义所有参数都有默认值的构造函数 ；
	4. 注意：一个类只能有一个默认构造函数！也就是说上述两种方式不能同时出现，一般选择 testClass(); 这种形式的默认构造函数 ；
	5. 只要程序猿定义了构造函数，编译器就不会再提供默认构造函数了，所以，程序猿最好再手动定义一个默认构造函数，以防出现 testClass a; 这样的错误。
 */
class SkipList
{
private:
	class SkipListNode
	{
	public:
		//带参数的默认构造函数,编译器就不会再提供默认构造函数了
		SkipListNode(int Key = INT_MIN) : key(Key),forward(nullptr),afterward(nullptr),upward(nullptr),downward(nullptr) { }
		int key;
		SkipListNode* forward;
		SkipListNode* afterward;
		SkipListNode* upward;
		SkipListNode* downward;
	};
	//头节点
	SkipListNode* head;
	int currentLevel;
	bool randomVal();	
public:
	//在构造函数中初始化头尾节点
	SkipList() : currentLevel(1)
	{
		head = new SkipListNode();
	}
	//插入新元素
	void insert(int val);
	bool find(int val);
	void remove(int val);
	void show();
};




int main()
{
//	cout << INT_MAX << INT_MIN <<endl;
//	-2147483648 2147483647
	int testArray[] = {1 , 2, 3, 4, 5, 6, 7, 8, 9, 22};
	//这里改了构造函数所以好像不能直接NEW对象
	SkipList* s1 = new SkipList();
	for (auto a : testArray)
	{
		s1->insert(a);
	}
	s1->show();
	s1->insert(16);
	s1->show();
	s1->remove(9);
	s1->show();

	return 0;
}

static unsigned int seed = 0; // 随机种子
bool SkipList::randomVal()
{
	if(seed == 0)
	{
		seed = (unsigned)time(nullptr);
	}
/**
 *	int  Time=1996;  //  临时变量，应区别于全局变量  
    ::Time=1997;  
    cout<<"Temp  Time  is  "<<Time<<endl;  
    cout<<"Outer  Time  is  "<<::Time<<endl;  
	表示这个::srand是全局命名空间
 */
	::srand(seed);
	int ret = ::rand()%2;
	seed = ::rand();
	if(ret == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SkipList::insert(int val)
{
	SkipListNode* cursor = head;
	SkipListNode* new_node = nullptr;
	while(cursor->downward != nullptr)
	{
		cursor = cursor->downward;
	}
	SkipListNode* cur_head = cursor;	//底层链表头

	while(cursor->afterward != nullptr)
	{
		if(val < cursor->afterward->key && new_node == nullptr)
		{
			new_node = new SkipListNode(val);
			new_node->afterward = cursor->afterward;
			cursor->afterward = new_node;
		}

		cursor = cursor->afterward;
	}

	if(new_node == nullptr)
	{
		new_node = new SkipListNode(val);
		cursor->afterward = new_node;
	}

	//底层插入完成
	int temp_Level = 1;
	while(randomVal())
	{
		++temp_Level;
		if(currentLevel < temp_Level)
		{
			++currentLevel;
			SkipListNode* new_node = new SkipListNode();
			new_node->downward = head;
			head -> upward = new_node;
			head = new_node;
		}

		cur_head = cur_head -> upward;	//当前链表头上移一层
		cursor = cur_head;	
		SkipListNode* Skip_Node = nullptr;	//非L1层的节点

		while(cursor->afterward != nullptr)
		{
			if(val < cursor->afterward->key && Skip_Node == nullptr)
			{
				Skip_Node = new SkipListNode(val);
				Skip_Node->afterward = cursor->afterward;
				cursor->afterward = Skip_Node;
			}
			cursor = cursor->afterward;
		}

		if(Skip_Node == nullptr)
		{
			Skip_Node = new SkipListNode(val);
			cursor->afterward = Skip_Node;
		}

		//将新插入的节点移到最新的一层
		while(new_node->upward != nullptr)
		{
			new_node = new_node->upward;
		}

		//链接上下个节点
		Skip_Node->downward = new_node;
		new_node->upward = Skip_Node;
	}
	return;
}

bool SkipList::find(int val)
{
	SkipListNode* cursor = nullptr;
	if(head == nullptr)
		return false;

	cursor = head;
	while(cursor->downward != nullptr)
	{
		while(cursor->afterward != nullptr)
		{
			if(val <= cursor->afterward->key)
			{
				break;
			}
			cursor = cursor->afterward;
		}
		cursor = cursor->downward;
	}

	while(cursor->afterward != nullptr)	//L1层循环开始具体查询
	{
		if(val > cursor->afterward->key)
		{
			cursor = cursor->afterward;
		}
		else if(val == cursor->afterward->key)
		{
			return true;
		}
		else
		{
			return false;
		}

		return false;
	}

	return false;
}

void SkipList::remove(int val)
{
	SkipListNode* cursor = head;
	SkipListNode* pre_head = nullptr;	//上一行的头指针，删除行时使用
	while(true)
	{
		SkipListNode* cur_head = cursor;
		if(pre_head != nullptr)
		{
			cur_head->upward = nullptr;
			pre_head->downward = nullptr;
			delete pre_head;
			pre_head = nullptr;	//指针归0
			--currentLevel;//层数减1
			head = cur_head;//重新指定起始指针
		}

		//在当前行中查询val
		while(cursor != nullptr && cursor->afterward != nullptr)
		{
			if(val == cursor ->afterward->key )
			{
				SkipListNode* delptr = cursor->afterward;
				cursor->afterward = cursor->afterward->afterward;
				delete delptr;
			}
			cursor = cursor->afterward;
		}
		//判断当前行还存在其它元素，如果不存在则删除该行并将整个跳跃表降维
		if(cur_head->afterward == nullptr)
		{
			pre_head = cur_head;
		}

		if(cur_head->downward == nullptr)
		{
			break;
		}
		else
		{
			cursor = cur_head ->downward;
		}
	}
	return;
}

void SkipList::show()
{
	SkipListNode* cur_head = head;
	SkipListNode* cursor = nullptr;
	while(cur_head->downward != nullptr)
	{
		cursor = cur_head;
		cursor = cursor -> afterward;
		while(cursor->afterward != nullptr)
		{
			cout << cursor ->afterward ->key<<" ";
			cursor = cursor -> afterward;
		}
		cur_head = cur_head ->downward;
		cout<<endl;
	}

	cursor = cur_head;
	cursor = cursor ->afterward;
	do
	{
		cout<<cursor->key<<" ";
		cursor =cursor -> afterward;
	}while(cursor->afterward != nullptr);
	cout<<cursor->key<<endl;

	return;
}