#include<stdio.h>
#include<stdlib.h>
struct node 
    {
        int info;
        struct node *link;

    };
struct node *START=NULL;
struct node* createList()
{
    struct node  *n;
    n=(struct node *)malloc(sizeof(struct node ));
    return n;
}

void insertValue()
{   
    
    struct node *temp,*t;
    printf("enter value :\n");
     t=createList();
    scanf("%d",&t->info);
    t->link=NULL;
    if(START==NULL)
    {
        START=t;
    }
    else
    {
        temp=START;
        while(temp->link!=NULL)
        {
        temp=temp->link;
        }
         temp->link=t;
   
    }
    
     printf("\n");
    
    
}
void viewList()
{

    if(START==NULL)
    printf("list is empty\n");
    else
    {
        struct node *t;
        t=START;
         while(t!=NULL)
         {
         
           printf("%d ",t->info);
           t=t->link;
          }

    }
    printf("\n");
    

}
void deletefirst()
{
    if(START==NULL)
    printf("list is empty\n");
    
    else 
    {
        struct node *t;
        t=START;
        START=START->link;
        free(t);

    }
    printf("\n");
}


int main()
{   
     int choice ;
    while(1)
    {
        printf("1.insert a value \n");
        printf("2.view the list \n");
        printf("3.delete the first node \n");
        printf("4.exit \n");
        printf("enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                 insertValue();
                 break;
            case 2:
                 viewList();
                 break;
            case 3:
                 deletefirst();
                 break;
            case 4:
                 exit(0);
            default: 
             printf("Invalid choice \n");
        }
    }
    return 0;
}