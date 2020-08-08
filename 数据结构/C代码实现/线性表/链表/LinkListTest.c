#include <stdio.h>
#include <LinkList.h>

int main()
{
    printf("LinkList 功能测试:\n");
    LinkList L;
    List_HeadInsert(L);
    ShowLinkListInfo(L);
    return 0;
}