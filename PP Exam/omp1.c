#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int arr[], int l, int m, int r){
    int i = l, j = m + 1,k = 0, temp[100];

    while (i <= m && j <= r){
        if (arr[i] > arr[j]){
            temp[k++] = arr[j++];
        }
        else{
            temp[k++] = arr[i++];
        }
    }
    while(i <= m){
        temp[k++] = arr[i++];
    }
    while (j <= r){
        temp[k++] = arr[j++];
    }

    i = 0; j = l;
    while(i < k){
        arr[j++] = temp[i++]; 
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                mergeSort(arr,l,m);
            }
            #pragma omp section
            {
                mergeSort(arr,m+1,r);
            }
        }
        merge(arr,l,m,r);
    }
}

int main(){
    int n = 100, a[1000];
    omp_set_num_threads(8);
    srand(time(NULL));
    
    for(int i = 0; i < n; i++){
        a[i] = rand() % 100;
    }
    mergeSort(a,0,n - 1);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}