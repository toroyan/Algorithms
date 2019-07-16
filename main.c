//
//  main.c
//  toroyanseda_L2
//
//  Created by Seda on 07/07/2019.
//  Copyright © 2019 Seda. All rights reserved.
//

#include <stdio.h>


//LESSON3

//Task1

int bubbleFunc(int*arr,int len){
    int count =0;
    int i,j;
    int temp=0;
    for(i=0;i<len;i++){
        for(j=0;j<len-1;j++){
            count++;
            if(arr[j]>arr[j+1]){
                count++;
                temp= arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return count;
}


int insertionSortFunc (int*arr,int len){
    int i,j;
    int count = 0;
    int temp;
    for(i=1;i<len;i++){
        
        j=i-1;
        temp = arr[i];
        count++;
        while(j>=0 && arr[j]>temp){
            count++;
            arr[j-1] = arr[j];
            j--;
        }
        count++;
        arr[j+1] = temp;
        
    }
    return count;
}


//TASK2

int* sheikSortFunc(int*arr,int len){
    int i,j;
    int temp=0,  k= 0;
    
    for(i=1;i<len;i++){
        for(j = 0;j<len-i;j++){
            if(arr[j]>arr[j+1]){
                temp= arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        for(j=len-(i+1);j>=i;j--){
            if(arr[j]<arr[j-1]){
                k= arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = k;
            }
        }
    }
    printf("Shaker sorting:\n");
    return arr;
}

//TASK3
int linearRecFunc(int*arr,int len, int v){
    if(len<0){
        return -1;
    }
    if(arr[len-1] == v){
        return len-1;
    }
    return linearRecFunc( arr,len-1, v);
    
}





//LESSON2
//Task1

void decToBinfunc(int a){
   
  int b = a%2;
  char p[100];
  sprintf(p, "%d", b);
    if (a>0){
        
    decToBinfunc(a/2);
     
   printf("%d",*p);
        
    }
   
    return 0;
    
}



//Task2(a,b)
int oddEvenPowerRec(int a,int b){
    int k;
    if (b==0){
        return 1;
    }
   
    if (b % 2 == 0) {
        k  = oddEvenPowerRec(a, b / 2);
        return k * k;
    }
    else {
        k = a* oddEvenPowerRec(a, b-1);
        
        return k;
    }
   
    return 0;
}





int main(int argc, const char * argv[]) {
    
    const int SIZE = 5;
    int arr[SIZE];
    for(int i = 0;i<SIZE;i++){
        arr[i] = rand() % 100;
        printf("%d\n",arr[i]);
    }
    printf("\n");
    printf("the count of buble  sorting operations is: %d\n",bubbleFunc(arr, SIZE));
    printf("the count of insertion sorting operations is: %d\n",insertionSortFunc(arr, SIZE));
    printf("The index of the number is: %d\n", linearRecFunc(arr,SIZE,58));
    
    
    int *p;
    p = sheikSortFunc(arr, SIZE);
    for(int i =0; i<SIZE;i++){
        printf("%d\n", *(p+i));
    }
    
    
    
    //decToBinfunc(5);
   // printf("%d\n",oddEvenPowerRec(6,3));
    
    return 0;
}
