#include<stdio.h>
#include "sort.h"
//希尔排序
void shellSort(int arr[],int len) {
   int step=len/2;
   while (step>=1) {
      for (int i=step;i<len;i++) {
         if (arr[i-step]>arr[i]) {
            int temp=arr[i];
            int j=i-step;
            while (j>=0&&arr[j]>temp) {
               arr[j+step]=arr[j];
               j=j-step;
            }
            arr[j+step]=temp;
            }
         }
      step=step/2;
   }
}
//归并排序
void merge(int*data,int left,int mid,int right) {
   int temp[100];
   int i=left;
   int j=mid+1;
   int k=0;
   while (i<=mid&&j<=right) {
      if (data[i]<=data[j]) {
         temp[k++]=data[i++];
      }else {
         temp[k++]=data[j++];
      }

   }
   while (i<=mid) {
      temp[k++]=data[i++];
   }
   while (j<=right) {
      temp[k++]=data[j++];
   }
   for (int i=0;i<k;i++) {
      data[left+i]=temp[i];
   }
}
void mergeSort(int*data,int left,int right) {
   if (left<right) {
      int mid=(left+right)/2;
      mergeSort(data,left,mid);
      mergeSort(data,mid+1,right);
      merge(data,left,mid,right);
   }
}
//快速排序
int partition(int *data,int low,int high) {
   int pivot=data[low];
   while (low<high) {
      while (low<high&&data[high]>=pivot) {
         high--;
      }
      data[low]=data[high];
      while (low<high&&data[low]<=pivot) {
         low++;
      }
      data[high]=data[low];
   }
   data[low]=pivot;
   return low;
}
void quickSort(int*data,int low,int high) {
   if (low<high) {
       int pivot=partition(data,low,high);
      quickSort(data,low,pivot-1);
      quickSort(data,pivot+1,high);
   }
}
//冒泡排序
void swap(int *a,int *b) {
   int temp=*a;
   *a=*b;
   *b=temp;
}
void bubbleSort(int*data,int len) {
   for (int i=0;i<len;i++) {
      for (int j=0;j<len-1-i;j++) {
         if (data[j]>data[j+1]) {
            swap(&data[j],&data[j+1]);
         }
      }
   }
}
//插入排序
void insertSort(int*data,int len) {
   int key;
   for (int i=1;i<len;i++) {
      key=data[i];
      int j=i-1;
      while (j>=0&&data[j]>key) {
         data[j+1]=data[j];
         j--;
      }
       data[j+1]=key;
   }
}
//二分插入排序
void binaryInsertSort(int *data,int len) {
   int low,high,key;
   for (int i=1;i<len;i++) {
      int low=0,high=i-1;
      int key=data[i];
      while (low<=high) {
         int mid=low+(high-low)/2;
         if (key<data[mid]) {
            high=mid-1;
         }else if (data[mid]<key) {
            low=mid+1;
         }
      }
      for (int j=i-1;j>=low;j--) {
         data[j+1]=data[j];
      }
      data[low]=key;
   }
}
//简单的选择排序
void selectionSort(int*data,int len) {

   for (int i=0;i<len;i++) {
      int min=i;
      for (int j=i+1;j<len;j++) {
         if (data[j]<data[min]) {
            min=j;
         }
      }
      swap(&data[min],&data[i]);
   }
}
