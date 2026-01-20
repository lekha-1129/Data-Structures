#include<stdio.h>
#define MAX 50
int arr[MAX],num,pos,loop,ele,digit;
void insert()
{
    if(num==MAX){
   printf("Array full. Insertion not possible\n");
   return;
    }
    printf("Enter position to insert(1 to %d):",num+1);
    scanf("%d",&pos);
    if(pos<1 || pos>num+1)
    {
        printf("Invalid position\n");
        return;
    }
    printf("Enter element to insert:");
    scanf("%d",&ele);
    for(loop=num;loop>=pos;loop--)
    {
        arr[loop]=arr[loop-1];
    }
    arr[pos-1]=ele;
    num++;
    for(int i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }
}
void del()
{
     if(num==MAX){
   printf("Array full. Insertion not possible\n");
   return;
    }
    printf("Enter position to del(1 to %d):",num+1);
    scanf("%d",&pos);
    if(pos<1 || pos>num+1)
    {
        printf("Invalid position\n");
        return;
    }
    for(loop=pos-1;loop<num;loop++)
    {
        arr[loop]=arr[loop+1];
    }
    num--;
    for(int i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }
}
void search()
{
    printf("Enter element to be searched:");
    scanf("%d",&digit);
    for(loop=0;loop<num;loop++)
    {
        if(arr[loop]==digit)
        {
            printf("%d element found at position %d",digit,loop+1);
            break;
        }
    }
}
int main()
{
    int choice;
  printf("Enter the number of elements to be used:");
  scanf("%d",&num);
  printf("Enter the elements:");
  for(loop=0;loop<num;loop++)
  {
  scanf("%d",&arr[loop]);
  }
  do{
    printf("------MENU------\n1.INSERTION\n2.DELETION\n3.SEARCHING\n4.EXIT");
    printf("\nEnter choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert();break;
        case 2:del();break;
        case 3:search();break;
        case 4:printf("Exiting program");break;
        default:printf("Enter valid choice");
    }
  }while(choice!=4);

}
