#include <stdio.h>
#include <stdbool.h>

typedef int ElemType;

// LinkList -> LNode -> LNode -> ··· -> LNode -> NULL

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
