#ifndef _SQLIST_H
#define _SQLIST_H

#include <stdbool.h> //#define bool _Bool
// 便于后期修改数据类型
typedef int ElemType;

#define MaxSize 50
typedef struct{
    ElemType data[MaxSize];// 顺序表的元素
    int length;// 顺序表的当前长度
}SqList;// 顺序表的类型定义

// 插入操作，其中i表示第i个位置插入，e为待插入元素
bool ListInsert(SqList *L, int i, ElemType e);

// 删除操作，删除第i个位置的元素，e用于返回被删除的元素
bool ListDelete(SqList *L, int i, ElemType *e);

// 按值查找，在顺序表L中查找第一个元素值等于e的元素，并返回其位序(第几号元素)
int LocateElem(SqList L, ElemType e);

// 显示SqList内部的信息
void ShowSqListInfo(SqList L);

#endif