/*
��������:ħ��ʦ����һ�����е�13�ź��ƣ�Ԥ�Ƚ������źú������һ�����泯��
�Թ���˵:�Ҳ����ƣ�ֻ�����Ϳ��Բµ�ÿ������ʲô���Ҵ���������������������?
�ֳ���ʾ
ħ��ʦ�����������������Ϊ1�����������������Ǻ���A��������A����������
�ڶ�����1��2������һ���Ʒ�����Щ�Ƶ����棬���ڶ����Ʒ������������Ǻ���2��Ҳ���������������������ν��н�13����ȫ��������׼ȷ����

����:�ƵĿ�ʼ˳������ΰ��ŵ�?
*/

#include<stdio.h>
#include<stdlib.h>


typedef struct List
{
    int num;
    struct List *next;
}List;

List *head = NULL;
List *tail = NULL;

int main()
{
    for(int i = 1 ; i <= 13 ; i++)
    {
        List *new = (List *)malloc(sizeof(List));
        if(!new)
        {
            printf("�ڴ�������!");
            exit(0);
        }
        new->num = 0;

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

    int count = 2;

    List *p = head;
    p->num = 1;

    while(1)
    {
        for(int i = 0 ; i < count ; i++)
        {
            p = p->next;
            if(p->num != 0)
            {
                i--;
            }
        }
        if(p->num == 0)
        {
            p->num = count;
            count++;

            if(count == 14) break;
        }
    }

    int times = 0;
    for(List *q = head; q != NULL && times < 13; q = q->next)
    {
        times++;
        printf("%d ",q->num);
    }

    return 0;
}