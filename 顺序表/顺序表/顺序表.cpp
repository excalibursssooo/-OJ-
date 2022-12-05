#include <iostream>
using namespace std;
#define OK 0
#define ERROR -1

//顺序表类定义
class SeqList {
private:
	int* list;		//元素数组
	int maxsize;	//顺序表最大长度
	int size;		//顺序表实际长度
public:
	~SeqList();		//析构函数		
//顺序表其他操作
	SeqList(int max = 0);	//构造函数，动态创建顺序表，设置顺序表最大长度
	int Insert(int item, int i);//插入一个元素
	int DEL(int i);				//删除一个元素，返回删除的元素值
	int get_i(int i);			//返回第i位置元素
	void print();				//打印顺序表所有数据
};

SeqList::~SeqList()			//析构函数
{
	delete[]list;
}

//完成其他顺序表函数和主函数
/********** Write your code here! **********/
SeqList::SeqList(int max ) {
	list = new int[max];
	maxsize = max;
	size = 0;
}

int SeqList::  Insert(int item, int i) {
	
}

/*******************************************/
//end main
