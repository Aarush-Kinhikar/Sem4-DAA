#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
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
    printf("Merge Sort:\n");
    for(x=1;x<=1000;x++){
        getNumbers(arr,x);
        start = clock();
        mergeSort(arr, 0, x*100 - 1);
        end = clock();
        printf("%f\n",((float)(end-start))/CLOCKS_PER_SEC);
    }
    printf("Quick Sort:\n");
    for(x=1;x<=1000;x++){
        getNumbers(arr,x);
        start = clock();
        quicksort(arr,0,x*100-1);
        end = clock();
        printf("%f\n",((float)(end-start))/CLOCKS_PER_SEC);
    }    
    return 0;
}