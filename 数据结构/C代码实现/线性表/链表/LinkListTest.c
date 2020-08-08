#include <stdio.h>
#include "LinkList.h"

int main()
{
    printf("LinkList 功能测试（输入9999结束输入）:\n");
    LinkList L1 = List_HeadInsert(L1);
    ShowLinkListInfo(L1);

    printf("0号位置的结点的data为%d\n",GetElem(L1, 0)->data);

    printf("查找data值为88的结点：");
    LNode *res = LocateElem(L1, 88);
    if(res)
    {
        printf("成功\n");
    }
    else
    {
        printf("失败\n");
    }
    

    LinkList L2 = List_TailInsert(L2);
    printf("插入前的链表为：\n");
    ShowLinkListInfo(L2);

    ElemType e = 88;
    L2 = ListInsert(L2, 1, e);
    printf("插入88到第1个位置后的链表为：\n");
    ShowLinkListInfo(L2);

    printf("删除第1个结点的链表为：\n");
    L2 = ListDelete(L2, 1, &e);
    ShowLinkListInfo(L2);
    printf("被删除的第一个结点的内容为%d\n", e);



    return 0;
}