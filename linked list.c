#include<stdio.h>
#include <stdlib.h>
int num;
struct node{
int data;
struct node *next;
};
int count(struct node*q);
struct node* create()
{
    printf("Enter number to add:");
    scanf("%d",&num);
    struct node*nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=num;
    nn->next=NULL;
    return nn;
}

void insert_beg(struct node **q)
{
 struct node*nn;
 nn=create();
 if((*q)==NULL)
 {
     (*q)=nn;
 }
 else{
    nn->next=(*q);
    (*q)=nn;
 }
}

void insert_end(struct node**q)
{
    struct node*nn;
    nn=create();
    struct node*temp;
    temp=(*q);
    if((*q)==NULL)
    {
        (*q)=nn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
    }
}

void insert_pos(struct node**q)
{
    struct node*nn;
    struct node*temp;
    temp=*q;
    int pos,quan,i=1;
    printf("Enter position to insert:");
    scanf("%d",&pos);
    quan=count(*q);
    if(pos<1||pos>quan+1)
    {
        printf("Invalid position");
        return;
    }

    if(pos==1)
    {
        insert_beg(q);
        return;
    }
  if(pos==quan+1)
    {
        insert_end(q);
        return;
    }
       nn=create();

    while(i!=pos-1)
    {
        temp=temp->next;
        i++;
    }
    nn->next=temp->next;
        temp->next=nn;

}

int count(struct node*q)
{
    struct node*temp;
    int c=0;
    temp=q;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

void display(struct node *q)
{
    struct node*temp;
    temp=q;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    struct node*head=NULL;
    int choice;
    do{
        printf("\n------MENU------\n1.INSERT AT BEGINNING\n2.INSERT AT END\n3.INSERT AT POSITION\n4.COUNT\n5.DISPLAY\n6.EXIT\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_beg(&head);
            break;

        case 2:
            insert_end(&head);
            break;

        case 3:
            insert_pos(&head);
            break;

        case 4:
            printf("Count = %d",count(head));
            break;

        case 5:
            display(head);
            break;

        case 6:
            printf("Exiting programming");
            break;

        default:
            printf("Invalid choice");
            break;
        }
    }while(choice!=6);

}
