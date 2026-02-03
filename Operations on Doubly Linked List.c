#include<stdio.h>
struct node{
    int data;
    struct node* next,*prev;
};
int main()
{
    struct node*head = NULL;
    int ch;
    do{
        printf("\n----MENU----\n1.Insert\n2.Insert at end\n3.Delete\n4.Delete at end\n5.Search\n6.Display\n7.Display in Reverse order\n8.EXIT\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_pos(&head);break;
            case 2:insert_end(&head);break;
            case 3:delete_pos(&head);break;
            case 4:delete_end(&head);break;
            case 5:search(head);break;
            case 6:display(head);break;
            case 7:display_rev(head);break;
            case 8:printf("EXITED...");break;
            default:printf("Invalid Choice!!!");break;
        }
    }while(ch!=8);
}
struct node*create(int d)
{
        struct node* nn;
        nn = (struct node*)malloc(sizeof(struct node));
        nn -> data = d;
        nn -> next = NULL;
        nn -> prev = NULL;
        return nn;
}
void display(struct node*q)
{
    struct node*temp = q;
    printf("[ ");
    while(temp != NULL)
    {
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("]");
}
void insert_pos(struct node**q)
{
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    int count = 0;
    struct node*temp;
    temp = *q;
    while(temp!=0)
    {
        count++;
        temp = temp -> next;
    }
    if((count+1)<pos)
    {
        printf("Invalid position!!!");
        return 0;
    }
    if(count+1==pos)
    {
        insert_end(q);
        return 0;
    }
    int d;
    printf("Enter data:");
    scanf("%d",&d);
    struct node*nn;
    nn = create(d);

    if(pos == 1)
    {

        if(*q == NULL)
            *q = nn;
        else
        {
            nn -> next = *q;
            (*q) -> prev = nn;
            *q = nn;
        }
        return 0;
    }

    struct node* tem = *q;
    for(int i = 1; i < pos - 1; i++)
        tem = tem -> next;
    nn -> next = tem -> next;
    nn -> prev = tem;
    tem -> next -> prev = nn;
    tem -> next = nn;

}
void insert_end(struct node**q)
{
    int d;
    printf("Enter data:");
    scanf("%d",&d);
    struct node*nn;
    nn = create(d);
    struct node*temp = *q;
    if(*q == NULL)
        *q = nn;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;
        temp -> next = nn;
        nn -> prev = temp;
    }
}
void delete_pos(struct node**q)
{
    if(*q == NULL){
            printf("LL is EMPTY");
            return 0;
        }
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    int count = 0;
    struct node*temp;
    temp = *q;
    while(temp!=0)
    {
        count++;
        temp = temp -> next;
    }
    if(count<pos)
    {
        printf("Invalid position!!!");
        return 0;
    }
    struct node*tem = *q;
    if(pos == 1)
    {


        *q = tem -> next;
        if(*q != NULL)
        (*q) -> prev = NULL;
        free(tem);
        return 0;
    }
    if(count == pos)
    {
        delete_end(q);
        return 0;
    }
    for(int i = 1; i < pos; i++)
        tem = tem -> next;
    tem -> next -> prev = tem -> prev;
    tem -> prev -> next = tem -> next;
    free(tem);

}
void delete_end(struct node**q)
{
    if(*q == NULL){
        printf("LL is Empty");
        return 0;
    }
    if((*q) -> next == NULL)
    {
        free(*q);
        *q = 0;
        return 0;
    }
     struct node *temp = *q;
     while(temp -> next != 0)
        temp = temp -> next;
     temp -> prev -> next = NULL;
     free(temp);

}
void search(struct node*head)
{
    int num,f = 0;
    printf("Enter value to search:");
    scanf("%d",&num);
    struct node*temp = head;
    for(int i = 1; temp != 0; i++)
    {
        if(temp -> data == num)
        {
            f = 1;
            printf("Value found at Node %d",i);
            break;
        }
        temp = temp -> next;
    }
    if(f == 0)printf("Value not found");
}
void display_rev(struct node*q)
{
    struct node*temp = q;
    while(temp -> next!=NULL)
    {
        temp = temp -> next;
    }
    printf("[ ");
    while(temp != 0)
    {
        printf("%d ",temp -> data);
        temp = temp -> prev;
    }
    printf("]");

}

