/*
����������һ��nxn�ķ��󣬷�����ǡ��n�ֲ�ͬ��Ԫ�أ�ÿ��Ԫ��ǡ��n��������ÿ��Ԫ����һ�к�һ���� ǡ�ó���һ��
������ѧ�Һ�����ѧ��ŷ��ʹ��������ĸ����Ϊ����������Ԫ�صķ�������������˶�����

������ͼ��һ��3x3����������:

    1   2   3
    2   3   1
    3   1   2

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int num;
    struct List *next;
}List;

//����ѭ������
List createList(N);

List *head = NULL;
List *tail = NULL;

int main()
{
    int N;
    printf("��������Ҫ�������������������N:\n");
    scanf("%d",&N);

    createList(N);

    for(int i = 0 ; i < N ; i++)
    {
        int current = 0;
        for(List *p = head; current < N; p = p->next)
        {
            printf("%d ",p->num);
            current++;
        }

        //ÿ��ӡһ�к�ѭ�������ͷ�ڵ�����һλ
        head = head->next;
        
        printf("\n");
    }

    return 0;
}

List createList(N)
{   
    for(int i = 1; i <= N; i++)
    {
        List *new = (List *)malloc(sizeof(List));
        if(!new)
        {
            printf("�ڴ����ʧ��!");
            return;
        }
        new->num = i;

        if(!head)
        {
            head = new;
            tail = new;
        }
        else
        {
            tail->next = new;
            tail = tail->next;
        }
        tail->next = NULL;
    }
    tail->next = head;

    return *head;
}