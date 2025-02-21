/*
��Ŀ:�жϵ��������Ƿ��л�
����һ:ʹ��p��q����ָ�룬p������ǰ�ߣ���qÿ�ζ���ͷ��ʼ�ߣ�����ÿ���ڵ㣬��p�ߵĲ����Ƿ��qһ��

          ---<--<--<--<---
          |              |
1 -> 2 -> 3 -> 4 -> 5 -> 6
p
q

����ͼ��p��6�ߵ�3ʱ������6��
��ʱ��q��head��������ֻ�������͵�3������������ȣ�����ì�ܣ����ڻ�
*/

#include<stdio.h>

int isCircle = 0;

typedef struct List
{
    int num;
    struct List *next;
}List;

List *head = NULL;
List *tail = NULL;

//����ѭ����
List *target = NULL;

int main()
{
    for(int i = 1 ; i < 7 ; i++)
    {
        List *new = (List *)malloc(sizeof(List));
        if(!new)
        {
            printf("�ڴ����ʧ��!");
            return;
        }

        new->num = i;

        if(new->num == 3)
        {
            target = new;
        }

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

    tail->next = target;

    int countA = 0;
    printf("ԭ�б�\n");
    for(List *p = head; p != NULL; p = p->next)
    {
        if(countA > 14) break;
        printf("%d->",p->num);
        countA++;
    }

    printf("\n\n�ж��Ƿ��л��С���\n\n");

    List *p = head;//������ǰ��
    int stepP = 0;


    for(int i = 0 ; i < 20 && p->next != NULL; i++)
    {
        List *q = head;//���Ǵ�ͷ��ʼ��
        int stepQ = 0;

        if(p != NULL)
        {
            p = p->next;
            stepP++;
            printf("%d ",p->num);
        }

        for(int j = 0 ; j < i && q->next != NULL; j++)
        {
            if(p->num == q->num && stepP != stepQ)
            {
                isCircle = 1;
                break;
            }
            q = q->next;
            stepQ++;
            printf("%d",q->num);
        }
        printf("\n");
        
        if(isCircle)
        {
            printf("�˴�����ѭ����Ϊ%d!\n",p->num);
            break;
        }
    }

    if(isCircle) 
    {
        printf("\n�˵������л�!!!\n");
    }
    else 
    {
        printf("\n�˵������޻�!!!\n");
    }

    return 0;
}