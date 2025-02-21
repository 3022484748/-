/*����:��ѭ���б�ģ��Լɪ������,��41������ɱ��˳�������*/

#define STEP 2

#include<stdio.h>


typedef struct List
{
    int num;//����
    int isOut;//0��ʾû�б���̭
    struct List *next;
}List;

List *head = NULL;
List *tail = NULL;

static const int count = 0;

int main()
{
    for(int i = 1; i < 42; i++)
    {
        List *new = (List*)malloc(sizeof(List));
        if(new == NULL)
        {
            printf("�ڴ����ʧ��!");
            return;
        }
        
        new->num = i;
        new->isOut = 0;

        if(head == NULL)
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

    List *current = head;//���ڵĽڵ�
    List *prev = tail;//��һ���ڵ�

    // ģ��Լɪ��
    int count = 0;
    while(count < 41)
    {
        for(int i = 0 ; i < STEP ; i++)
        {
            prev = current;
            current = current->next;
        }

        printf("%d ",current->num);

        prev->next = current->next;
        free(current);
        current = prev->next;
        count++;
    }

    return 0;
}