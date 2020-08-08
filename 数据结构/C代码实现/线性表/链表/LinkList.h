#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef int ElemType;

// L(保存HeadNode的地址) -> LNode -> LNode -> ··· -> LNode -> NULL

typedef struct LNode{
    ElemType data;// 数据域
    struct LNode * next;// 指针域
}LNode, *LinkList;

// 使用头插法建立链表
LinkList List_HeadInsert(LinkList L);

// 使用尾插法建立链表
LinkList List_TailInsert(LinkList L);

// 按序号查找元素，查找成功则返回指向第i个结点的指针，否则返回NULL
LNode *GetElem(LinkList L, int i);

// 按值查找元素，查找成功则返回该结点的指针，否则返回NULL
LNode *LocateElem(LinkList L, ElemType e);

// 返回链表长度，长度为0表示链表仅含头结点
int ListLength(LinkList L);

// 在链表的第i个位置插入一个新的结点
LNode *ListInsert(LinkList L, int i, ElemType e);

// 删除链表中第i个位置的结点，并通过e返回该结点的信息
LNode *ListDelete(LinkList L, int i, ElemType *e);

// 显示链表中各结点的逻辑关系
void ShowLinkListInfo(LinkList L);

#endif