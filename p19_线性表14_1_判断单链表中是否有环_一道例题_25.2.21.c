/*

��Ŀ:ʵ�ֽ��������Ա�(a1��a2������an)��(b1��b2������bm)���ӳ�һ�����Ա�(a1��.an�� b1��...bm)������

����:
-���ڵ������ͷָ���ʾ�ĵ�ѭ���������������Ӳ���������Ҫ������һ�������ҵ����an��Ȼ�󽫽��b1����an�ĺ��棬��ִ��ʱ����0(n)
-����βָ���ʾ�ĵ�ѭ��������ʵ�֣���ֻ���޸�ָ�룬�����������ִ��ʱ����0(1)

*/

#include<stdio.h>

static int N = 5;
static int M = 5;

typedef struct List
{
    int num;
    char name;
    struct List *next;
}List;

List *head_A = NULL;
List *tail_A = NULL;

List *head_B = NULL;
List *tail_B = NULL;

int main()
{
    //��������A
    for(int i = 0 ; i < N ; i++)
    {
        List *newA = (List *)malloc(sizeof(List));
        if(!newA)
        {
            printf("�ڴ�������!");
            break;
        }

        newA->num = i;
        newA->name = 'A';

        if(!head_A)
        {
            head_A = newA;
            tail_A = newA;
        }
        else
        {
            tail_A->next = newA;
            tail_A = tail_A->next;
        }
        tail_A->next = NULL;
    }

    //��������β�ڵ�ָ��
    List *rearA = tail_A;

    tail_A->next = head_A;


    //��������B
    for(int i = 0 ; i < M ; i++)
    {
        List *newB = (List *)malloc(sizeof(List));
        if(!newB)
        {
            printf("�ڴ�������!");
            break;
        }

        newB->num = i;
        newB->name = 'B';

        if(!head_B)
        {
            head_B = newB;
            tail_B = newB;
        }
        else
        {
            tail_B->next = newB;
            tail_B = tail_B->next;
        }
        tail_B->next = NULL;
    }

    List *rearB = tail_B;

    tail_B->next = head_B;

    int countA = 1;
    printf("���Ա�A:\n");
    for(List *p = head_A; p != NULL; p = p->next)
    {
        printf("%c%d->",p->name,p->num);
        countA++;
        if(countA > N) break;
    }
    int countB = 1;
    printf("\n���Ա�B:\n");
    for(List *p = head_B; p != NULL; p = p->next)
    {
        printf("%c%d->",p->name,p->num);
        countB++;
        if(countB > M) break;
    }

    //�ı�����βָ���ָ��ʹ�䲻��ָ���Լ���ͷ�ڵ������һ�����ͷ�ڵ�
    rearA->next = head_B;
    rearB->next = head_A;

    int countC = 0;
    printf("\n���Ӻ�:\n");
    for(List *p = head_A; p != NULL; p = p->next)
    {
        printf("%c%d->",p->name,p->num);
        countC++;
        if(0.5*countC > N + M) break;
    }

    return 0;
}
