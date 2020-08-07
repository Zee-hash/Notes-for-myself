#include <stdio.h>
#include "SqList.h"

int main()
{
    // 定义一个顺序表
    SqList sqlist;
    ShowSqListInfo(sqlist);

    // 初始化
    sqlist.length = 0;// 长度赋初值

    // 插入元素
    for(int i = 1; i <= 10; i++)
    {
        ListInsert(&sqlist, i, i * i + 2);
    }
    ShowSqListInfo(sqlist);

    // 删除元素
    ElemType e;
    if(ListDelete(&sqlist, 4, &e))
    {
        printf("删除成功，被删除元素的值为%d\n", e);
        ShowSqListInfo(sqlist);
    }
    else
    {
        printf("删除失败\n");
    }

    // 查找元素
    e = 38;
    int res = 0;
    if((res = LocateElem(sqlist, e)) != 0)
    {
        printf("查找元素成功，该元素位于顺序表的第%i个位置\n", res);
    }
    else
    {
        printf("查找元素成功");
    }    
}