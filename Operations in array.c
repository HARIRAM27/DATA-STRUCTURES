#include<stdio.h>
#define MAX 50
int n, arr[MAX];
int main()
{
    int ch;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    arr[n];
    printf("Enter array elements:");
    for(int i =0 ;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    do{
        printf("\n----MENU----\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.EXIT");
        printf("\nEnter choice:");

        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();break;
            case 2 : deletion();break;
            case 3:display();break;
            case 4:searching();break;
            case 5:printf("Exiting...");break;
            default:printf("Invalid!!!");
        }
    }while(ch!=5);



}
void insert()
{
    int pos,ele;
    printf("Enter element and position:");
    scanf("%d %d",&ele,&pos);
    if(pos>n||pos<=0){printf("Position out of range!!!");return 0;}
    for(int i = n;i>=pos;i--)
    {
        arr[i] = arr[i - 1];
    }n++;
    arr[pos - 1] = ele;

}
void deletion()
{
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos>=n||pos<=0){printf("Position out of range!!!");return 0;}
    for(int i = pos - 1;i<n;i++)
    {
        arr[i] = arr[i + 1];
    }n--;


}
void display()
{
    for(int i = 0;i < n ;i++)
    {

        printf("%d ",arr[i]);
    }
}
void searching()
{
    int ele;
    printf("Enter element to search:");
    scanf("%d",&ele);
    for(int i =0 ;i < n;i++)
    {
        if(ele == arr[i])
        {
            printf("Element found at position %d",i+1);return 0;
        }
    }
    printf("Element not found");
}
