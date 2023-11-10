#include<stdio.h>
#include<stdlib.h>
 struct node
 {
int data;
struct node *link;
}*head;
 void insertFront(){
       int item;
       struct node *temp;
       temp=(struct node*)malloc(sizeof(struct node));
       printf("\nenter the data to insert\n");
       scanf("%d",&item);
       if(temp==NULL)
         printf("No Space to Store\n");
       else{
          temp->data=item;
          temp->link=head;
          head=temp;
       }
     } 
void insertEnd(){
        int item;
        struct node  *temp,*ptr;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the item to be inserted \n");
        scanf("%d",&item);
        ptr=head;
        while(ptr->link!=NULL){
            ptr=ptr->link;
            }
        ptr->link=temp;
        temp->data=item;
        temp->link=NULL;
       }
void display(){
     struct node *ptr;
     ptr=head;  
     printf("Linked List\n");
     while(ptr!=NULL){
         printf("%d",ptr->data);
         ptr=ptr->link;
         }
         printf("\n");
    }
void insertAtposition(){
   int item,key;
   struct node *temp,*ptr;
   printf("enter the data to be added\n");
   scanf("%d",&item);
   temp=(struct node*)malloc(sizeof(struct node));
   printf("enter the positon after which value to added\n");
   scanf("%d",&key);
   ptr=head;
   while(ptr->data!=key&&ptr->link!=NULL){
   ptr=ptr->link;
   }
   if(ptr->link==NULL)
   printf("search fails\n");
   else{
   temp->data=item;
   temp->link=ptr->link;
   ptr->link=temp;
   }
   }
void deleteFront(){
   struct node *ptr;
    if(head==NULL)
   printf("no elements\n");
   else{
       ptr=head;
       head=ptr->link;
       printf("the data %d is deleted\n",ptr->data);
       free(ptr);
       } 
   }    
void deleteEnd(){
     struct node *ptr,*temp;
      if(head->link==NULL){
          ptr=head;
           head=NULL;
           printf("the data %d is deleted\n",ptr->data);
            free(ptr);
       }
    ptr=head;
    temp=head->link;
     while(temp->link!=NULL){
       ptr=temp;
       temp=temp->link;
         }
       ptr->link=NULL;
       printf("the data %d is deleted\n",temp->data);
       free(temp);
    }
void deletePosition(){
       struct node *ptr,*temp;
   int key,i=1;
   printf("enter the position to be deleted\n");
   scanf("%d",&key);
   temp=head;
   if(head==NULL){
      printf("no elements\n");
   }
   while(i<key-1){
      temp=temp->link;
      i++;
   }
   ptr=temp->link;
   temp->link=ptr->link;
   printf("the data %d is deleted\n",ptr->data);
   free(ptr);
   }
     

       
 
      
 void main()
     {
      int choice;
      printf("Enter the Choice:\n1. Insertion at front\n2.Insertion at End \n 3.Insertion at position\n4.Deletion from front\n5.Deletion from    End\n6.Delete From Position7.Display\n");
       scanf("%d",&choice);
       while (choice!=8){
        switch(choice){       
         case 1:{
                 insertFront();
                 break;
               }
         case 2:{
                 insertEnd();
                 break;
               }
        case 3:{
                insertAtposition();
                break;
               }
        case 4:{
                 deleteFront();
                 break;
               }
        case 5:{
                 deleteEnd();
                 break;
               }
        case 6:{
                  deletePosition();
                  break;
               }
                
         case 7:{
                  display();
                  break;
               }
        case 8 :{
                 break;
                }                
         default:
               {
                 printf("wrong choice\n");
               }
         
         }
           printf("Enter the Choice:\n1. Insertion at front\n2.Insertion at End \n 3.Insertion at position\n4.Deletion from front\n5.Deletion from End7.Display\n");
       scanf("%d",&choice);
         
     }
   }
     
       
