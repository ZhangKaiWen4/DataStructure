//2022,7,13 ��ϰ(�ൺ��ѧ-��׿)
//Sequence List (˳���)����ز���
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
//�������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100
//Status �Ǻ���������,��ֵ�Ǻ������״̬����
typedef int Status;
typedef char ELemType;


typedef struct {
	ELemType *elem;
	int length;//��ǰ����
}SqList;//˳�������

//[�㷨2.1] ���Ա�L�ĳ�ʼ��(����������)
Status InitList_Sq(SqList& L) {//����һ���յ�˳���L
	L.elem = new ELemType[MAXSIZE]; //Ϊ˳������ռ�
	if (!L.elem)
		exit(OVERFLOW);	//�洢����ʧ��
	L.length = 0;	//�ձ���Ϊ0
	return OK;
}

//[�㷨2.2] �������Ա�L
void DestroyList(SqList& L) {
	if (L.elem)
		delete L.elem;//�ͷŴ洢�ռ�
}

//[�㷨2.3] ������Ա�L
void ClearList(SqList& L) {
	L.length = 0;//�����Ա�������Ϊ0
}

//[�㷨2.4] �����Ա�L�ĳ���
int GetLength(SqList L) {
	return (L.length);
}

//[�㷨2.5] �ж����Ա�L�Ƿ�Ϊ��
int IsEmpty(SqList L) {
	if (L.length == 0)
		return 1;	//����Ϊ0,��ʾû��Ԫ��
	else
		return 0;
}

//[�㷨2.6] ˳����ȡֵ(����λ��i��ȡ��Ӧλ������Ԫ�ص�����)
//1 <= i <= L.length
int GetElem(SqList L, int i, ELemType& e) {
	if (i < 1 || i> L.length)
		return ERROR;
	//��i-1�ĵ�Ԫ�洢�ŵ�i������
	e = L.elem[i - 1];
	return OK;
}

//[�㷨2.7] ˳���Ĳ���
//	�����Ա�L�в�����ָ��ֵe��ͬ������Ԫ�ص�λ��
//	�ӱ��һ�˿�ʼ,������м�¼�Ĺؼ��ֺ͸���ֵ�ıȽ�;
//			�ҵ�,���ظ�Ԫ�ص�λ�����,δ�ҵ�,����0
int LocateElem(SqList L, ELemType e) {
	//�����Ա�L�в���ֵΪe������Ԫ��,���������(�ǵڼ���Ԫ��)
	for(int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)
			//elem[0]������ǵ�1��Ԫ��,���� i+1
			return i + 1;//���ҳɹ�,�������
		return 0;//����ʧ��,����0
	}
}

//[�㷨2.8] ˳���Ĳ���
//˼��:
//	1,�жϲ���λ��i�Ƿ�Ϸ�;
//	2,�ж�˳���Ĵ洢�ռ��Ƿ�����,����������ERROR
//	3,����n����iλ��Ԫ����������ƶ�һ��λ��,�ճ���i��λ��
//	4,��Ҫ�������Ԫ��e�����i��λ��
//	5,����1,����ɹ�����OK
Status ListInsert_Sq(SqList& L, int i, ELemType e) {
	//1,iֵ���Ϸ�
	if (i<1 || i>L.length + 1)
		return ERROR;
	//2,��ǰ�洢�ռ�����
	if (L.length == MAXSIZE)
		return ERROR;
	//3,����λ�ü�֮���Ԫ�غ���
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	//4,���µ�Ԫ��e�����i��λ��
	L.elem[i - 1] = e;
	//5,����1
	L.length++;
	return OK;
}

//[�㷨2.9] ���Ա��ɾ��
//˼��:
//	1,�ж�ɾ��λ��i�Ƿ�Ϸ�(�Ϸ�ֵΪ1<=i<=n)
//	2,��Ҫɾ����Ԫ�ر�����e��
//	3,����i+1��nλ��Ԫ��������ǰ�ƶ�һ��λ��
//	4,����1,ɾ���ɹ�����OK
Status ListDelete_Sq(SqList& L, int i) {
	//1,iֵ���Ϸ�
	if (i<1 || i>L.length)
		return ERROR;
	//2,��ɾ��Ԫ��֮���Ԫ����ǰ��
	for (int j = i; j <= L.length; j++)
		L.elem[j - 1] = L.elem[j];
	//3,����1
	L.length--;
	return OK;
}