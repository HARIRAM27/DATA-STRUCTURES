#include<stdio.h>
struct linlist{
    int data;
    struct linlist* next;
};
int main()
{
    struct linlist*head;
    int ch;
    do{
        printf("\n---MENU---\n1.Insert\n2.Insert at end\n3.Delete\n4.Delete at end\n5.Display\n6.EXIT\n");
        printf("Enter Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_pos(&head);break;
            case 2:insert_end(&head);break;
            case 3:del_pos(&head);break;
            case 4:del_end(&head);break;
            case 5:disp(head);break;
            case 6:printf("Exited");break;
            default:printf("Invalid Option");break;
        }
    }while(ch!=6);
}
struct linlist* create(int d)
{
        struct linlist* neww;
        neww = (struct linlist *)malloc(sizeof(struct linlist));
        neww->data = d;
        neww->next = NULL;
        return neww;
}
void disp(int *q)
{
    struct linlist *temp = q;
    printf("[ ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("]");
}
void insert_beg(struct linlist**q)
{
    int d;
    printf("Enter data:");
    scanf("%d",&d);
    struct linlist*nn = create(d);
    if(*q == NULL)*q = nn;
    else
    {
        nn->next = *q;
        *q = nn;
    }
}
void insert_end(struct linlist**q)
{
    if(*q == NULL)
    {insert_beg(q);return 0;}
    int d;
    printf("Enter data:");
    scanf("%d",&d);
    struct linlist*nn = create(d);
    struct linlist * temp = *q;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = nn;
}
void insert_pos(struct linlist**q)
{
    int pos;
    printf("Enter position to add data:");
    scanf("%d",&pos);
    if(pos == 1)
    {insert_beg(q);return 0;}
    int count = 0;
    struct linlist * temp;
    temp = (*q);
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    if(count+1 == pos){insert_end(q);}
    else if(pos>(count+1))
    {
        printf("Invalid Position!!!");
        return 0;
    }
    int d;
    printf("Enter data:");
    scanf("%d",&d);
    struct linlist*nn = create(d);
    if(*q == NULL)*q = nn;
    int i = 1;
    struct linlist*temp1 = *q;
    while(temp1!=NULL)
    {
        if(i == pos -1)
        {
            nn->next = temp1->next;
            temp1->next = nn;
        }
        i++;
        temp1 = temp1 ->next;
    }


}
void del_beg(struct linlist **q)
{
    struct linlist*temp;
    if(*q == NULL){printf("Linked list is Empty");return 0;}
    temp = *q;
    *q = temp->next;
    free(temp);
}
void del_pos(struct linlist **q)
{
    if(*q == NULL)
    {
        printf("Linked list is Empty");
        return 0;
    }
    int pos;
    printf("Enter position :");
    scanf("%d",&pos);
    if(pos == 1)
    {
        del_beg(q);
        return 0;
    }

    int count = 0;
    struct linlist * temp1;
    temp1 = *q;
    while(temp1!=NULL)
    {
        count++;
        temp1 = temp1->next;
    }
    if(pos>count)
    {
        printf("Invalid Position!!!");
        return 0;
    }

    struct linlist*temp,*prev;
    temp = *q;
    for(int i = 1;i<pos;i++)
    {
        prev = temp;
        temp = temp->next;

    }
    prev -> next = temp -> next;
    free(temp);

}
void del_end(struct linlist**q)
{
    struct linlist*temp,*prev;
    if(*q == NULL)
    {
        printf("Linked list is Empty");
        return 0;
    }
    temp = *q;
    while(temp -> next!=NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = temp -> next;
    free(temp);

}
