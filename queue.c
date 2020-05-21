#include<stdio.h>
#include<stdlib.h>
struct ArrayQueue
{
   int CAPACITY;
   int rear,front;
   int *array;
};
struct ArrayQueue* createQueue(int capacity)
{
    struct ArrayQueue *Q;
    Q=(struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));
    if(!Q)
    return NULL;
    Q->front=Q->rear=-1;
    Q->CAPACITY=capacity;
    Q->array=(int*)malloc(Q->CAPACITY*sizeof(int));
    if(Q->array==NULL)
    return NULL;

    return Q;
}
int  isemptyQueue(struct ArrayQueue *Q)
{
   return (Q->front==-1);
}
int isfullQueue(struct ArrayQueue *Q)
{
   return ((Q->rear+1)%(Q->CAPACITY)==Q->front);
}
int QueueSize(struct ArrayQueue *Q)
{
   return (Q->CAPACITY-Q->front+Q->rear+1)%(Q->CAPACITY);
}
void enqueue(struct ArrayQueue *Q,int data)
{
   if(isfullQueue(Q))
   printf("overflow\n");
   else
   {
       Q->rear=(Q->rear+1)%Q->CAPACITY;
       Q->array[Q->rear]=data;
       if(Q->front==-1)
       Q->front=Q->rear;
   }
   
}
int dequeue(struct ArrayQueue *Q)
{
    int data=-1;
  if(isemptyQueue(Q))
  printf("no elements already empty\n");
  else
  {
      
      data=(Q->array[Q->front]);
      if(Q->front==Q->rear)
      Q->front=Q->rear=-1;
      else
      {
          Q->front=(Q->front+1)%Q->CAPACITY;
      }
      
  }
  return data;

  
}
void  deleteQueue(struct ArrayQueue *Q)
{
  if(Q)
  {
      if(Q->array)
      {
          free(Q->array);
      }
      free (Q);
  }
}

int main()
{
    int choice,capacity,data;
    printf("enter the capacity of the queue\n");
    scanf("%d",&capacity);
    struct ArrayQueue *Q=createQueue(capacity);
    
    while(1)
    {
    
    printf("1.enqueue\n");
    printf("2.dequeue\n");
    printf("3.check if full\n");
    printf("4.check if empty\n");
    printf("5.delete\n");
    printf("6.size of the queue\n");
    printf("7.exit\n");
    printf("enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
             printf("enter the data value to be enqueued\n");
             scanf("%d",&data);
             enqueue(Q,data);
             break;
        case 2:
              
              printf("the value deueued is %d\n",dequeue(Q));
              break;
        case 3:
              if(isfullQueue(Q))
              printf("yes the queue is full\n");
              else
              {
                  printf("the queue is not full\n");
              }
              break;
         case 4:
             if(isemptyQueue(Q))
              printf("yes the queue is empty\n");
              else
              {
                  printf("the queue is not empty\n");
              }
              break;

        case 5:
                
                deleteQueue(Q);
                break;
        case 6:
               printf("%d",QueueSize(Q));
               break;
        case 7:
               exit(0);
       
        default:
        printf("invalid choice \n");
    }
     }
    return 0;
}