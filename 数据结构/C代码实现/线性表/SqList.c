#include <stdio.h>
#include "SqList.h"

// 插入操作，其中i表示第i个位置插入，e为待插入元素
bool ListInsert(SqList *L, int i, ElemType e)
{
    if(L->length >= MaxSize)
    {
        // 没有多余空间可供插入操作
        return false;
    }
    if(i < 1 || i > L->length + 1)
    {
        // 可供插入的位置下标为0~length+1
        return false;
    }
    if (i <= L->length)
    {
        // 需要移动元素
        for(int j =L->length; j > i; j--)
        {
            L->data[j] = L->data[j-1];
        }
    }
    L->data[i-1] = e;
    L->length ++;
    // 插入成功
    return true;
}

// 删除操作，删除第i个位置的元素，e用于返回被删除的元素
bool ListDelete(SqList *L, int i, ElemType *e)
{
    if(i < 1 || i > L->length)
    {
        // 可供删除元素的位置下标为0~length-1
        return false;
    }
    *e = L->data[i-1];// 保存被删除的元素
    for(int j = i; j < L->length; j++)
    {
        // 需要移动元素
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return true;
}

// 按值查找，在顺序表L中查找第一个元素值等于e的元素，并返回其位序(第几号元素)
int LocateElem(SqList L, ElemType e)
{
    int index;// 用于返回位序
    for(index = 0; index < L.length; index++)
    {
        if(e == L.data[index])
        {
            return index + 1;// 查找成功
        }
    }
    return 0;// 查找失败
}

// 显示SqList内部的信息
void ShowSqListInfo(SqList L)
{
    if(L.length < 0 || L.length > MaxSize)
    {
        printf("SqList未初始化。\n");
        return;
    }
    printf("Data of SqList : ");
    for(int i = 0; i < L.length; i++)
    {
        printf("\t%d", L.data[i]);
    }
    printf("\nLength of SqList : %d.\n", L.length);
}