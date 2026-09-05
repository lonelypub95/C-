#include <stdio.h>
#include<string.h>
#include<assert.h>
#include "sort/sort.h"
#include "SeqList/seqList.h"
int main() {
   int arr[]={55,24,56,33,100,101,73,66};
    int len=sizeof(arr)/sizeof(int);
    selectionSort(arr,len);
     for (int i=0;i<len;i++) {
         printf("%d\n",arr[i]);
     }
    return 0;
}
