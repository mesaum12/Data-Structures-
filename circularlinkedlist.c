#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int info;
    struct node *link;

};
struct node *createNode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return n;
}

struct node *LAST=NULL;
struct node* findnode(struct node **l,int value)
{
   struct node *temp;
   temp=*l;
   if(temp==NULL)
   return NULL;

   else
   {
         do
         {
          temp=temp->link;
          if(temp->info==value )
          return temp;
         } while (temp!=*l);
     return NULL;
   }
 
   
}
void display(struct node **l)
{
   struct node *temp;
   temp=*l;
   if(*l==NULL)
   printf("list is empty\n");

   else
   {
       do
       {   
           temp=temp->link;
           printf("%d ",temp->info);
       } while (temp!=*l);
       
   }
   


}
struct node* addatbeg(struct node **l)
{
   struct node *t;
   t=createNode();
   printf("enter the value\n");
   scanf("%d",&t->info);
   if(*l==NULL)
   {
       *l=t;
       t->link=t;
   }
   else
   {
       t->link=(*l)->link;
       (*l)->link=t;
       

   }
   return *l;
   
}
struct node* addatend(struct node **l)
{
   struct node *t;
   t=createNode();
   printf("enter the value to be added\n");
   scanf("%d",&t->info);
   if(*l==NULL)
   {
       *l=t;
       t->link=t;
   }
   else
   {
        t->link=(*l)->link;
       (*l)->link=t;
       (*l)=t;
     
   }
   return *l;
   

}
struct node* addafter(struct node **l,struct node *ptr)
{
    int data;
    struct node *temp;
    temp=createNode();
    scanf("%d",&temp->info);
    if(ptr==NULL)
     printf("data not found\n");
   
    else
   {
       if(ptr==*l)
       {
           temp->link=ptr->link;
           ptr->link=temp;
           (*l)=temp;
          
       }
       else
       {
        temp->link=ptr->link;
        ptr->link=temp;
       }
       
   }
   return *l;
   

}
struct node* delfirst(struct node **l)//check from here 
{
    if(*l==NULL)
    printf("list is empty\n");
    
    else
    { 
      struct node *temp=*l;
      if((*l)->link==*l)
      {*l=NULL;free(temp);}

      else
      {
          temp=temp->link;
          (*l)->link=temp->link;
          free(temp);

      }
      
    }
  
  return *l;

}
struct node* dellast(struct node **l)
{  
    if(*l==NULL)
    printf("list is empty\n");
    else{
        if((*l)->link==*l)
        (*l)=NULL;
       struct node *temp;
       temp=*l;
       do
        {
          temp=temp->link;
        } while (temp->link!=*l);
    

     temp->link=(*l)->link;
     *l=temp;
    
    }

    return *l;

   
}
struct node* delparticular(struct node **l,struct node *ptr)
{
   
   if(ptr==NULL)
   printf("value not found\n");

   else
   {
       if(ptr==*l)
       {
         dellast(l);
       }
       else
       {
         struct node *temp=*l;
         do
         {
             temp=temp->link;

         }while(temp->link!=ptr);

         temp->link=ptr->link;
         free(ptr);
       }
       
   }
   return *l;
}
struct node* insertNode(struct node *(*l))
{   
    struct node *t;
    int data;
    t=createNode();
    printf("enter the value to be inserted\n");
    scanf("%d",&t->info);
  

    if((*l)==NULL)
    {
        (*l)=t;
        t->link=t;  
    }
    else
    {
        t->link=(*l)->link;
        (*l)->link=t;
        (*l)=t;

    }
    return *l;

}



int main()
{
    int choice,value;
    while(1)
    {
        printf("\n1.Insert a node \n");
        printf("2.Display the values\n");
        printf("3.Insert at the beginning\n");
        printf("4.Insert at the end\n");
        printf("5.Insert after a particular\n");
        printf("6.Delete the first node\n");
        printf("7.Delete the last node\n");
        printf("8.Delte a particular node \n");
        printf("9.exit\n ");
        
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
               insertNode(&LAST);
               break;
          
        case 2:
               display(&LAST );
               break;
        case 3:
              addatbeg(&LAST);
              break;
        case 4:
              addatend(&LAST);
              break;
        case 5:
             
              printf("enter the value after which data is to be added\n");
              scanf("%d",&value);
              struct node *ptr2=findnode(&LAST,value);
              addafter(&LAST,ptr2);
              break;
        case 6:
              delfirst(&LAST);
              break;
        case 7:
              dellast(&LAST);
              break;
        case 8:
            
              printf("enter the value to be deleted\n");
              scanf("%d",&value);
              struct node *ptr1=findnode(&LAST,value);
              delparticular(&LAST,ptr1);
              
              break;
        case 9:
              exit(0);
            
            
        
        default:
        printf("invalid choice \n");
            
        }

    }
    return 0;
    
}