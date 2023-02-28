#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void quicksort(int number[25],int first,int last){
    int i, j, pivot, temp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(number[i]<=number[pivot]&&i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
    }
}
void getNumbers(int arr[],int x){
    for(int i=0;i<x*100;i++){
        arr[i] = rand()%1000 + 1;
    }
}
int main(){
    int i, count, arr[100000];
    int x=1;
    clock_t start,end;
    for(x=1;x<=1000;x++){
        getNumbers(arr,x);
        start = clock();
        quicksort(arr,0,x*100-1);
        end = clock();
        printf("%f\n",((float)(end-start))/CLOCKS_PER_SEC);
    }    
    /*printf("Enter some elements (Max. - 25): ");
    scanf("%d",&count);
    printf("Enter %d elements: ", count);
    for(i=0;i<count;i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,count-1);
    printf("The Sorted Order is: ");
    for(i=0;i<count;i++)
        printf(" %d",arr[i]);*/
    return 0;
}