/*

������ʾ��Ŀ:
-Ҫ��ʵ���û�����һ����ʹ��26����ĸ�����з����仯�������û�����3��������:
-DEFGHIJKLMNOPORSTUVWXYZABC
-ͬʱ��Ҫ֧�ָ����������û�����-3��������:
-XYZABCDEFGHIJKLMNOPORSTUVW

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    char data;
    struct List *prior;//ָ����һ���ڵ�
    struct List *next;//ָ����һ���ڵ�
}List;

List *head;
List *tail;

List createList();
void readList(List *Head);

int main()
{
    int N;
    printf("��������Ҫ�ƶ�����:\n");
    scanf("%d",&N);

    createList();
    printf("ԭ��������:\n");
    readList(head);

    printf("�ƶ��������:\n");
    if(N > 0)
    {
        int count = 0;

        //���ſ�
        for(int i = 0 ; i < N ; i++)
        {
            head = head->next;
        }

        for(List *p = head; count++ < 26; p = p->next)
        {
            printf("%c ",p->data);
        }
        printf("\n");
    }
    else
    {
        int count = 0;

        //���ſ�
        for(int i = 0 ; i > N ; i--)
        {
            head = head->prior;
        }

        for(List *p = head; count++ < 26; p = p->next)
        {
            printf("%c ",p->data);
        }
        printf("\n");
    }

    return 0;
}

List createList()
{   
    for(int i = 0 ; i < 26 ; i++)
    {
        List *new = (List *)malloc(sizeof(List));
        new->data = 'A' + i;

        if(!head)
        {
            head = new;
            tail = new;
        }
        else
        {
            tail->next = new;
            new->prior = tail;
            tail = tail->next;
        }
        tail->next = NULL;
    }
    tail->next = head;
    head->prior = tail;

    return *head;
}

void readList(List *Head)
{
    int count = 0;
    for(List *p = Head; count++ < 26; p = p->next)
    {
        printf("%c ",p->data);
    }
    printf("\n");
}