#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

// L(保存HeadNode的地址) -> LNode -> LNode -> ··· -> LNode -> NULL

typedef struct LNode{
    ElemType data;// 数据域
    struct LNode * next;// 指针域
}LNode, *LinkList;

// 使用头插法建立链表
LinkList List_HeadInsert(LinkList L)
{
    LNode *s = NULL; ElemType x;
    // 创建头结点
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;// 初始化为空链表
    scanf("%d", &x);
    while(x != 9999)
    {
        // 输入9999结束
        s = (LinkList)malloc(sizeof(LNode));
        // 结点数据赋值
        s->data = x;
        // 插入到头结点后
        s->next = L->next;
        L->next = s;
        // 继续输入新结点data域值，输入9999即可结束新增结点
        scanf("%d", &x);
    }
    return L;
}

// 使用尾插法建立链表
LinkList List_TailInsert(LinkList L)
{
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s = NULL;
    // 为了记录最后一个元素的位置，引入辅助指针r,指向链表最后一个元素
    LNode *r = L;
    scanf("%d", &x);
    while(x != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;// 当前尾结点后新增元素
        r = s;// r重新指向末尾
        scanf("%d", &x);
    }
    // 尾结点指针域置空
    r->next = NULL;
    return L;
}

// 按序号查找元素，查找成功则返回指向第i个结点的指针，否则返回NULL
LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if(i == 0)
    {
        return p;
    }
    if(i < 1)
    {
        return NULL;// 查找位置无效
    }
    while(p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找元素，查找成功则返回该结点的指针，否则返回NULL
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while(p->next && p->data != e)
    {
        p = p->next;// 继续往后查找
    }
    return p;
}

// 返回链表长度，长度为0表示链表仅含头结点
int ListLength(LinkList L)
{
    int length = 0;
    LNode *p = L->next;
    while(p)
    {
        p = p->next;
        length++;
    }
    return length;
}

// 在链表的第i个位置插入一个新的结点
LNode *ListInsert(LinkList L, int i, ElemType e)
{
    // 检查插入位置的合法性
    if(i < 1 || i > ListLength(L) + 1)
    {
        printf("插入位置有误\n");
        return L;// 插入位置错误，原样返回
    }
    LNode *s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    LNode *p;
    if((p = GetElem(L,i-1)))
    {
        s->next = p->next;
        p->next = s;
    }
    return L;
}

// 删除链表中第i个位置的结点，并通过e返回该结点的信息
LNode *ListDelete(LinkList L, int i, ElemType *e)
{
    // 检查删除位置的合法性
    if(i < 1 || i > ListLength(L))
    {
        printf("删除位置有误\n");
        return L;// 删除位置错误，原样返回
    }
    // 保存结点信息
    *e = GetElem(L, i)->data;
    LNode *p = GetElem(L, i-1);
    LNode *q = NULL;
    if(p)
    {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    return L;
}

void ShowLinkListInfo(LinkList L)
{
    int length = ListLength(L);
    if(length == 0)
    {
        printf("L(&HeadNode)-->NULL\n");
    }
    if(length > 0)
    {
        LNode *p = L->next;
        printf("L(&HeadNode)");
        while(p->next)
        {
            printf("-->%d", p->data);
            p = p->next;
        }
        printf("-->%d-->NULL", p->data);
        printf("\nLength of LinkList : %d\n", length);
    }
}

int main()
{
    LinkList L = NULL;
    L = List_HeadInsert(L);
    ShowLinkListInfo(L);
    L = ListInsert(L, 2, 9);
    ShowLinkListInfo(L);
    ElemType e = 0;
    L = ListDelete(L, 3, &e);
    printf("element %d has been deleted.\n", e);
    ShowLinkListInfo(L);
}