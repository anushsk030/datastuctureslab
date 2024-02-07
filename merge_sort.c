#include<stdio.h>
void mergeSort(int arr[],int low,int high);
void merge(int arr[],int low,int middle,int high);
int main() {
    int limit, i;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    int a[limit];

    printf("Enter the numbers to be sorted:\n");
    for (i = 0; i < limit; i++) {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, limit - 1);

    printf("Sorted array: ");
    for (i = 0; i < limit; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
void mergeSort(int arr[],int low,int high){
    if(low!=high){
int middle=(low+high)/2;
mergeSort(arr,low,middle);
mergeSort(arr,middle+1,high);
merge(arr,low,middle,high);
    }

}
void merge(int arr[],int low,int middle,int high){
int temp[90],i,j,k;
i=low;
j=middle+1;
k=low;
while(i<=middle&&j<=high){

    if(arr[i]<=arr[j]){
        temp[k]=arr[i];
        i++;
        k++;
    }
    else{
        temp[k]=arr[j];
        j++;
        k++;
    }
}
while(i<=middle){
     temp[k]=arr[i];
        i++;
        k++;
}
while(j<=high){
    temp[k]=arr[j];
        j++;
        k++;
}

for(i=low;i<=high;i++){
    arr[i]=temp[i];
}


}
