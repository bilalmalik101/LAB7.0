#include <stdlib.h>
#include <stdio.h>

#include "array_utils.h"

void printArray(const int *arr, int n) {
  if(arr == NULL) {
    printf("[null]\n");
    return;
  }
  printf("[ ");
  for(int i=0; i<n-1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d ]\n", arr[n-1]);
  return;
}

void printTable(int **table, int n, int m) {
  if(table == NULL) {
    printf("[null]\n");
    return;
  }
  for(int i=0; i<n; i++) {
    printArray(table[i], m);
  }
  return;
}

int * generateRandomArray(int size) {
  if(size < 0) {
    return NULL;
  }
  int randomArr[size];
  for(int i=0; i<size; i++) {
    randomArr[i] = rand() % 100;
  }
  return randomArr;
}

int getSum(int *arr, int size) {
  if(arr == NULL) {
    return 0;
  }
  int total = 0;
  for(int i=0; i<size; i++) {
    total += arr[i];
    arr[i] = 0;
  }
  return total;
}

void freeTable(int **table, int n) {
  if(table == NULL) {
    return;
  }
  for(int i=0; i<n; i++) {
    free(table[i]);
  }
  free(table);
}

double getMean(const int *arr, int size) {
  //for address of array
  if(arr==NULL){
    printf("Invalid arrays address\n");
    return -1;
  }
  // checking size not find mean of 1 element
  if(size == 0){
    printf("Invalid\n");
    return -1;
  }
  double sum =0.0;
  for(int i=0;i<size;i++){
    sum+=arr[i];
  }
  return sum/size;
}
int getMin(const int*arr,int size){
  if(arr==NULL){
    printf("invalid array address\n");
       return -1;

  }
  //check size not find min
  if(size==0){
    printf("Invalid size\n");
    return -1;
  }
  int min=arr[0];
  for(int i=0;i<size;i++){
    if(arr[i]<min){
      min=arr[i];
    }
  }
  return min;
  
}
//function for index of min num
int getIndexOfMin(const int*arr,int size){
  if(arr==NULL){
    printf("Invalid array\n");
    return -1;
  }
  int min=arr[0];
  int minIndex=0;
  for(int i=0;i<size;i++){
    if(arr[i]<min){
      min=arr[i];
      minIndex=i;
    }
  }
  return minIndex;
}
//function for max num array
int getMax(const int*arr,int size){
  if(arr==NULL){
    printf("invalid arrray");
    return -1;
  }
  int max=0;
  for(int i=0;i<size;i++){
    if(arr[i]>max){
      max=arr[i];
    }
  }
  return max;
}
//Functin to find index of max
int getIndexOfMax(const int*arr,int size){
  if(arr==NULL){
    printf("invalid ");
    return -1;
  }
  int max =0;
  int maxIndex =0;
  for(int i=0;i<size;i++){
    if(arr[i]>max){
      if(arr[i]>max){
        max=arr[i];
        maxIndex=i;
      }
    }
    return maxIndex;
  }
  //function to filter the num from array as condition
  int *filterThreshold(const int *arr,int size,int threshold,int *resultSize){
    if(arr==NULL || resultSize==NULL){
      printf("Invalid array");
      return NULL;
    }
    // variable fot store increment value for array threshold
    int count =0;
    for(int i=0;I<size;i++){
      //filter size for array
      if(arr[i]>=threshold){ 
        count++;
      }
    }
    //dynamic memory allocation
    int *filterArray=(int*)malloc(count*sizeof(int));
    //to increment dynamic array
    int index =0;
    for(int i=0;i<size;i++){
      //for filter value equal or greater from threshold store in dynamic arr
      if (arr[i]>=threshold){
        filterArray[index++]=arr[i];

      }
      *resultsize=count;
    }
    return filterArray;
  }

  //Multiplication table for 2D array
  int **createMultiplicationTable(int n,int m){
    if(n==0 || m==0){
      printf("invalid\n");
      return NULL;
    }
    //pointer for store adress row
    int **table =(int **)malloc(n*sizeof(int*));
    if(table == NULL){
      printf("Invalid allocation of memory\n");
      return NULL;
    }
    for(int i=0;i<n;i++){
      // memory for colum to each row
      table[i]=(int*)malloc(m*sizeof(int));
      if(table[i]==NULL){
        printf("Invalid memory for colums index");

      }

    
  }
    // row & colums multiplication
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        table[i][j]=(i+1)*(j+1);
      }
    }
    //return array
    return table;
  
}
