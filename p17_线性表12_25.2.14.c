#include<stdio.h>


typedef struct List
{
    int num;
    struct List *next;
} List;

List *head = NULL;
List *tail = NULL;

int main()
{
    
    printf("1.��ʼ������\n");
    printf("2.�����ڵ�\n");
    printf("3.ɾ���ڵ�\n");
    printf("4.���ؽڵ�λ��\n");
    printf("5.��������\n");
    printf("0.�˳�\n");

    while(1)
    {
        printf("��ѡ����Ĳ���: ");
        int choice;
        scanf("%d",&choice);
        fflush(stdin);

        if(choice == 0) break;

        switch(choice)
        {
            case 1:
            {
                printf("����ڵ��ֵ,����0��ɳ�ʼ��\n");
                while(1)
                {
                    List *new = (List*)malloc(sizeof(List));
                    if(new == NULL)
                    {
                        printf("�ڴ����ʧ��!");
                        return;
                    }

                    int number;
                    scanf("%d",&number);
                    if(number == 0) 
                    {
                        free(new);
                        break;
                    }

                    new->num = number;

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
                printf("��ʼ���ɹ�!\n");
                break;
            }

            case 2:
            {
                if(!head)
                {
                    printf("���ȳ�ʼ������!\n");
                    break;
                }

                List *New = (List*)malloc(sizeof(List)); 
                int numm;
                printf("����������Ҫ��������:\n");
                scanf("%d",&numm);

                New->num = numm;

                printf("������Ҫ����ᵽ�ڼ���λ��:\n");
                int location , loc = 1;
                scanf("%d",&location);

                for(List *q = head ; q != NULL ; q = q->next)
                {
                    ++loc;
                    if(loc == location)
                    {
                        New->next = q->next;
                        q->next = New;
                    }
                }
                printf("�����ɹ�!\n");
                break;
            }

            case 3:
            {
                printf("��������Ҫɾ���Ľڵ��λ��:");
                int loc , location = 1;
                scanf("%d",&loc);
                
                List *prev = NULL;
                List *curr = head;
                while (curr != NULL && location < loc) {
                    prev = curr;
                    curr = curr->next;
                    location++;
                }
            
                if (curr == NULL) {
                    printf("λ�ó��������ȣ�ɾ��ʧ�ܣ�\n");
                } else {
                    prev->next = curr->next;  // ����ǰ��ڵ�
                    free(curr);  // ɾ����ǰ�ڵ�
                    printf("ɾ���ɹ�!\n");
                }
                break;
            }

            case 4:
            {
                printf("����������Ҫ����λ�õ�����:");
                int n , location = 1;
                scanf("%d",&n);

                for(List *q = head; q != NULL; q = q->next)
                {
                    if(q->num == n)
                    {
                        printf("%d �ڵ� %d ��λ����\n",n,location);
                        break;
                    }
                    else
                    {
                        location++;
                    }
                }
                break;
            }

            case 5:
            {
                if(!head)
                {
                    printf("���ȳ�ʼ������!\n");
                    break;
                }
                printf("*****************�����е�Ԫ��*****************\n");
                for(List *p = head ; p != NULL ; p = p->next)
                {

                    printf("%d  ",p->num);
                }
                printf("\n");
                break;
            }

            default: 
            {
                printf("��������ȷ��ѡ��!\n");
                continue;
            }
        }

    }

    return 0;
}