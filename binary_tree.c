#include<stdio.h>
void main(){
    int limit,i,pos,choice;
    printf("enter the maximum no. of nodes\n");
    scanf("%d",&limit);
    int a[limit];
    printf("enter the data of the nodes\n");
    for(i=1;i<=limit;i++){
            scanf("%d",&a[i]);
    }
  do{
    printf("enter the position do you want to check\n");
    scanf("%d",&pos);  
    if(pos>limit)
        printf("Invalid Position  /n");
    else if((pos/2)<=0){
        printf("No Parent for given position\n");
    }
    else{
        printf("parent of %d is %d\n",a[pos],a[(pos/2)]);
        }
    if(2*pos>limit){
      printf("no left child in position %d \n",pos);
    }
   else{
     printf("Left child of %d is :%d\n",a[pos],a[2*pos]);
   }
   if((2*pos)+1>limit){
     printf("No right child in position %d \n",pos);
     }
   else{
   printf("Right child of %d is:%d\n",a[pos],a[(2*pos)+1]);
   }
   printf("do you want to continue checking \n click 1 if yes\n");
   scanf("%d",&choice);
  }while(choice==1);
 }
   
    
   
          
