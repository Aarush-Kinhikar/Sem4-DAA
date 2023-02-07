#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
int main(){
    void getData(int x, int arr[]), insertionSort(int x,int arr[]);
    void selectionSort(int x,int arr[]), printArray(int x,int arr[]);
    int arr[100000];
    __clock_t start,end;
    printf("Selection Sort:\n")
    for(int i=0;i<1000;i++){
        getData(i+1,arr);
        start = clock();
        selectionSort(i+1,arr);
        end = clock();
        double duration = ((double)(end - start))/CLOCKS_PER_SEC;
        printf("%lf ",duration);
    }
    printf("Insertion Sort:\n")
    for(int i=0;i<1000;i++){
        getData(i+1,arr);
        start = clock();
        insertionSort(i+1,arr);
        end = clock();
        double duration = ((double)(end - start))/CLOCKS_PER_SEC;
        printf("%lf ",duration);
    }
    return 0;
}
void getData(int x, int arr[]){
    for(int i=0;i<x*100;i++){
        arr[i] = rand()%1000 + 1;
    }
}
void insertionSort(int x,int arr[]){
    for (int i = 1; i < x*100; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(int x,int arr[]){
    int i, j, min_idx;
    for (i = 0; i < x*100 -1; i++)
    {
        min_idx = i;
        for (j = i+1; j < x*100; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i){
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}