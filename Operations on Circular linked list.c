#include<stdio.h>
#include<stdlib.h>
struct node* create(int);
void insert_pos(struct node**);
void insert_end(struct node**);
void delete_pos(struct node**);
void delete_end(struct node**);
void search(struct node*);
void display(struct node*);
void display_rev(struct node*);
struct node{
    int data;
    struct node* next;
    struct node* prev;
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
    do
    {
        printf("%d ",temp -> data);
        temp = temp -> next;
    }while(temp != q);
    printf("]");
}
void insert_pos(struct node**q)
{
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos != 1 && *q == NULL)
    {
        printf("Invalid position!!!");
        return ;
    }
    if(*q == NULL && pos == 1)
    {
        int d;
    printf("Enter data:");
    scanf("%d",&d);
    struct node*nn;
    nn = create(d);
            *q = nn;
            nn -> prev = *q;
            nn -> next = *q;
            return;
    }
    int count = 1;
    struct node*temp;
    temp = *q;
    while(temp -> next != *q)
    {
        count++;
        temp = temp -> next;
    }
    if((count+1)<pos||pos<=0)
    {
        printf("Invalid position!!!");
        return ;
    }
    if(count+1==pos)
    {
        insert_end(q);
        return ;
    }
    int d;
    printf("Enter data:");
    scanf("%d",&d);
    struct node*nn;
    nn = create(d);

    if(pos == 1)
    {

            nn -> next = *q;
            nn -> prev = (*q) -> prev;
            (*q) -> prev -> next = nn;
            (*q) -> prev = nn;
            *q = nn;
        return;
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
    if(*q == NULL){
        *q = nn;
        nn -> prev = *q;
        nn -> next = *q;
    }
    else
    {
        nn -> next = *q;
        nn -> prev = (*q) -> prev;
        (*q) -> prev -> next = nn;
        (*q) -> prev = nn;
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
    int count = 1;
    struct node*temp;
    temp = *q;
    while(temp -> next != *q)
    {
        count++;
        temp = temp -> next;
    }
    if(count<pos)
    {
        printf("Invalid position!!!");
        return ;
    }
    struct node*tem = *q;
    if(pos == 1)
    {
        struct node* temp = *q;
         if((*q) -> next == *q)
         {
             free(temp);
             *q = NULL;
         }
         else{
            *q = temp -> next;
            (*q) -> prev = temp -> prev;
            temp -> prev -> next = *q;
            free(temp);
         }
         return;
    }
    if(count == pos)
    {
        delete_end(q);
        return ;
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
        return;
    }
    struct node* temp = *q;
    if((*q) -> next == *q)
    {
        free(temp);
        *q = NULL;
    }
    else
    {
        temp = (*q) -> prev;
        temp -> prev -> next = *q;
        (*q) -> prev = temp -> prev;
        free(temp);
    }

}
void search(struct node*head)
{
    int num,f = 0;
    printf("Enter value to search:");
    scanf("%d",&num);
    struct node*temp = head;
    int i = 1;
    do
    {
        if(temp -> data == num)
        {
            f = 1;
            printf("Value found at Node %d",i);
            break;
        }
        temp = temp -> next;
        i++;
    }while(temp != head);
    if(f == 0)printf("Value not found");
}
void display_rev(struct node*q)
{
    struct node*temp = q -> prev;
    struct node * last = q -> prev;
    printf("[ ");
    do
    {
        printf("%d ",temp -> data);
        temp = temp -> prev;
    }while(temp != last);
    printf("]");

}
