//2022,7,13 复习(青岛大学-王卓)
//Sequence List (顺序表)的相关操作
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100
//Status 是函数的类型,其值是函数结果状态代码
typedef int Status;
typedef char ELemType;


typedef struct {
	ELemType *elem;
	int length;//当前长度
}SqList;//顺序表类型

//[算法2.1] 线性表L的初始化(参数用引用)
Status InitList_Sq(SqList& L) {//构造一个空的顺序表L
	L.elem = new ELemType[MAXSIZE]; //为顺序表分配空间
	if (!L.elem)
		exit(OVERFLOW);	//存储分配失败
	L.length = 0;	//空表长度为0
	return OK;
}

//[算法2.2] 销毁线性表L
void DestroyList(SqList& L) {
	if (L.elem)
		delete L.elem;//释放存储空间
}

//[算法2.3] 清空线性表L
void ClearList(SqList& L) {
	L.length = 0;//将线性表长度设置为0
}

//[算法2.4] 求线性表L的长度
int GetLength(SqList L) {
	return (L.length);
}

//[算法2.5] 判断线性表L是否为空
int IsEmpty(SqList L) {
	if (L.length == 0)
		return 1;	//长度为0,表示没有元素
	else
		return 0;
}

//[算法2.6] 顺序表的取值(根据位置i获取相应位置数据元素的内容)
//1 <= i <= L.length
int GetElem(SqList L, int i, ELemType& e) {
	if (i < 1 || i> L.length)
		return ERROR;
	//第i-1的单元存储着第i个数据
	e = L.elem[i - 1];
	return OK;
}

//[算法2.7] 顺序表的查找
//	在线性表L中查找与指定值e相同的数据元素的位置
//	从表的一端开始,逐个进行记录的关键字和给定值的比较;
//			找到,返回该元素的位置序号,未找到,返回0
int LocateElem(SqList L, ELemType e) {
	//在线性表L中查找值为e的数据元素,返回其序号(是第几个元素)
	for(int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)
			//elem[0]代表的是第1个元素,所以 i+1
			return i + 1;//查找成功,返回序号
		return 0;//查找失败,返回0
	}
}

//[算法2.8] 顺序表的插入
//思想:
//	1,判断插入位置i是否合法;
//	2,判断顺序表的存储空间是否已满,若已满返回ERROR
//	3,将第n至第i位的元素依次向后移动一个位置,空出第i个位置
//	4,将要插入的新元素e放入第i个位置
//	5,表长加1,插入成功返回OK
Status ListInsert_Sq(SqList& L, int i, ELemType e) {
	//1,i值不合法
	if (i<1 || i>L.length + 1)
		return ERROR;
	//2,当前存储空间已满
	if (L.length == MAXSIZE)
		return ERROR;
	//3,插入位置及之后的元素后移
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	//4,将新的元素e放入第i个位置
	L.elem[i - 1] = e;
	//5,表长加1
	L.length++;
	return OK;
}

//[算法2.9] 线性表的删除
//思想:
//	1,判断删除位置i是否合法(合法值为1<=i<=n)
//	2,将要删除的元素保留在e中
//	3,将第i+1至n位的元素依次向前移动一个位置
//	4,表长减1,删除成功返回OK
Status ListDelete_Sq(SqList& L, int i) {
	//1,i值不合法
	if (i<1 || i>L.length)
		return ERROR;
	//2,被删除元素之后的元素向前移
	for (int j = i; j <= L.length; j++)
		L.elem[j - 1] = L.elem[j];
	//3,表长减1
	L.length--;
	return OK;
}