#include<stdio.h>
#include<stdlib.h>
struct node 
{   
    int info;
    struct node *prev,*next;
};
struct node *START=NULL;
struct node* createNode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return n;
}

void insertNode(struct node **s,int data)
{  
    struct node *temp;
    temp=createNode();
    temp->info=data;
    temp->next=NULL;
    if((*s)==NULL)
    {
        (*s)=temp;
        temp->prev=NULL;

    }
    else
    {
        struct node *t;
        t=(*s);
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=temp;
        temp->prev=t;
    }
    
}

void insertBegin(struct node *(*s),int data)
{
     struct node *temp;
    temp=createNode();
    temp->info=data;
    
    if((*s)==NULL)
    {
         (*s)=temp;
        temp->prev=NULL;
        temp->next=NULL;

    }
    else
    {   
        temp->prev=NULL;
        temp->next=(*s);
        ((*s))->prev=temp;
        (*s)=temp;
        
    }
    
   
}
void insertLast(struct node *(*s),int data)
{
    struct node *temp;
    temp=createNode();
    temp->info=data;
    temp->next=NULL;
    if((*s)==NULL)
    {
        (*s)=temp;
        temp->prev=NULL;
        
    }
    else
    {
        struct node *t;
        t=(*s);
        while(t->next!=NULL)
         t=t->next;
         t->next=temp;
         temp->prev=t;
    }
    
    
}
struct node* findNode(struct node **s,int *data)
{
     struct node *temp;
     temp=(*s);
     if(*s==NULL)
     return NULL;
     else 
     {  
         while(temp!=NULL)
         { 
           if(temp->info==(*data))
           return temp;
           temp=temp->next;
         
         }
         return NULL;
     }
     
}
void insertAfter(struct node **s,struct node *ptr,int data)
{
   struct node *temp,*t;
   temp=createNode();
   temp->info=data;
   if(ptr==NULL)
   printf("value not found\n");
   else
   { 
      temp->prev=ptr;
      temp->next=ptr->next;
      if(ptr->next!=NULL)
      ptr->next->prev=temp;
      ptr->next=temp;

   }
     
     
 }
   
  void deleteFirst(struct node *(*s))
  {
      if((*s)==NULL)
      printf("list is empty\n");

  
  else
  {
     struct node *t;
     t=createNode();
     t=(*s);
     (*s)=(*s)->next;
     if((*s)->next==NULL)
     (*s)=NULL;
     else
     {
         (*s)->next->prev=NULL;
     }
     
     free(t);
  }
}
  
  void deleteLast(struct node **s)
  {
      if(*s== NULL)
      printf("list is empty\n");
      else if((*s)->next==NULL)
      *s=NULL;
      else
      {
         struct node *t;
         t=(*s);
         while(t->next!=NULL)
         t=t->next;
         t->prev->next=NULL;
         free(t);
      }
      
 }
  void deleteAnyNode(struct node **s,struct node *ptr2)
  {
     
      if(ptr2==NULL)
      printf("data not found\n");
      else
      {
          struct node *t;
          t=(*s);
          while(t!=ptr2)
          t=t->next;
          if(t->next==NULL)
           t->prev->next=NULL;
           else
           {
               t->prev->next=t->next;
               t->next->prev=t->prev;
           }
        free(t);

      }
      
  }
  void viewList(struct node **s)
  {
      struct node *t;
    
      t=(*s);
      if((*s)==NULL)
      {
          printf("list is empty\n");
      }
      while(t!=NULL)
      {
          printf("%d ",t->info);
          t=t->next;

      }
      printf("\n");
  }
int main()
{
    int choice ,value,data;
    while (1)
    {
    printf("\n1.insertNode\n");
    printf("2.insertBegin\n");
    printf("3.insertLast\n");
    printf("4.insertAfter\n");
    printf("5.deleteFirst\n");
    printf("6.deleteLast\n");
    printf("7.deleteAnyNode\n");
    printf("8.viewList\n");
    printf("9.exit\n");
    printf("enter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
              printf("enter the value :");
              scanf("%d",&value);
              insertNode(&START,value);
              break;

        case 2:
              printf("enter the value :");
              scanf("%d",&value);
              insertBegin(&START,value);
              printf("\n");
              break;

        case 3:
         printf("enter the value :");
              scanf("%d",&value);
              insertLast(&START,value);
              printf("\n");
              break;

        case 4: 
              printf("enter the value after which node is to be inserted\n");
              scanf("%d",&value);
              struct node *ptr =findNode(&START,&value);
              printf("enter data to be inserted\n");
              scanf("%d",&data);
              insertAfter(&START,ptr,data);
              printf("\n");
              break;

        case 5: 
              deleteFirst(&START);
              printf("\n");
              break;

        case 6:
                deleteLast(&START);
                printf("\n");
                break;
        case 7:
               printf("enter the value after which node is to be deleted\n");
              scanf("%d",&value);
              struct node *ptr2 =findNode(&START,&value);
               deleteAnyNode(&START,ptr2);
               printf("\n");
               break;
        case 8:
                  viewList(&START);
                  printf("\n");
                  break;
        case 9:
                 exit(0);
        default:
        printf("invalid input \n");

        }
    }

    return 0;
   
}

