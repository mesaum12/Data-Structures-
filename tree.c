#include<stdio.h>
#include<stdlib.h>
struct BSTnode 
{
    int info;
    struct BSTnode *left,*right;
};

struct BSTnode* createNode( int data)
{  
   struct BSTnode *temp=(struct BSTnode*)malloc(sizeof(struct BSTnode ));
   temp->info=data;
   temp->left=temp->right=NULL;
   return temp;
}
struct BSTnode* insertion(struct BSTnode *root,int data)
{
     

     if(root==NULL)
     return createNode(data);

     else if(root->info>data)
     root->left=insertion(root->left,data);

     else 
     root->right=insertion(root->right,data);

     return root;

}
struct BSTnode* Find(struct BSTnode *root,int data)
{
    if(root==NULL)
    return NULL;

    else if(root->info==data)
    return root;

      else
      {
        struct BSTnode *temp;
        if(root->info>data)
        return Find(root->left,data);
        else
        return Find(root->right,data);
      }
}
struct BSTnode* findmax(struct BSTnode *root)
{
     struct BSTnode *temp;
     temp=root;
     while(temp->right!=NULL)
     temp=temp->right;
     return temp;
    
}
struct BSTnode* delete(struct BSTnode *root,int data)
{
    if(root==NULL)
    return NULL;

    else if(root->info>data)
    root->left=delete(root->left,data);

    else if(root->info<data)
    root->right=delete(root->right,data);

    else
    {
       
          if(root->left==NULL)
          {
              struct BSTnode *temp=root->right;
              free(root);
              return temp;
          }
          else if(root->right==NULL)
          {
             struct BSTnode *temp=root->left;
             free(root);
             return temp;
          }
         
             struct BSTnode *temp=findmax(root->left);
             root->info=temp->info;
             root->left=delete(root->left,temp->info);
     }
    return root;
}

void inorderTraversal(struct BSTnode *root)
{
    if(root==NULL)return;
    {
        inorderTraversal(root->left);
        printf("%d ",root->info);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(struct BSTnode *root)
{
    if(root==NULL)return;
    {
        
        printf("%d ",root->info);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct BSTnode *root)
{
    if(root==NULL)return;
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->info);
    }
}

int main()
{
   int choice;struct BSTnode *root=NULL; 
   int value,data;
     while(1){
       printf("1.insertion\n");
       printf("2.find a value \n");
       printf("3.delete a value \n");
       printf("4.indorder traversal\n");
       printf("5.preorder traversal\n");
       printf("6.postorder traversal\n");
       printf("7.exit\n");
       printf("enter your choice: \n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
                  printf("enter the value tobe inserted\n");
                  scanf("%d",&value);
                  root=insertion(root,value);
                  break;
           case 2:
                 printf("enter the value to be found\n");
                 scanf("%d",&value);
                 
                 if(Find(root,value))
                 printf("value is found successfully\n");
                 else
                 printf("value not found \n");
                 break;
                   
           case 3: 
                  printf("enter the value to be deleted\n");
                 scanf("%d",&value);
                 root=delete(root,value);
                 if(delete(root,value))
                 printf("value is deleted successfully\n");
                 else
                 printf("value not found \n");
                 break;
                 
           case 4:
                  inorderTraversal(root);
                  break;
           case 5:
                  preorderTraversal(root);
                  break;
           case 6:
                 postorderTraversal(root);
                 break;
           case 7:
                  exit(0);
           default:
                 printf("invalid choice \n");

            }
        }
        return 0;
}