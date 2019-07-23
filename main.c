//
//  main.c
//  toroyanseda_L2
//
//  Created by Seda on 07/07/2019.
//  Copyright © 2019 Seda. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


//Lesson6

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    
    
} Node;

//Task1
int hashFunc(char *string){
    int i=0;
    
    int sum =0;
    
    for(i=0;i<strlen(string);i++){
        sum = sum + string[i];
    }
    return sum;
}




//Task2.1
void balancedOrder(Node *root){
    if(root){
        balancedOrder(root->left);
        printf("%d",root->data);
        balancedOrder(root->right);
    }
}


//Task2.1
void leftRightRoot(Node *root){
    if(root){
        leftRightRoot(root->left);
        leftRightRoot(root->right);
        printf("%d",root->data);
    }
}

//Task2.2
Node * searchBinaryTree(int value,Node *root){
    if(root == NULL){
        return 0;
    }
    
    else  if (root ->data < value){
        return searchBinaryTree(value, root->right);
    }
    else if (root ->data > value){
    
        return searchBinaryTree(value, root->left);
    }
    else
    return root;
}

Node * createNode(int value){
    Node* temp =(Node*) malloc(sizeof(Node));
    temp->data = value;
    temp->right = NULL;
    temp->left = NULL;
    
    return temp;
}
//Task2.3
Node * addNode(int value,Node *root){
    
    if(root == NULL){
        root = createNode(value);
        
    }
    else if(value<=root->data){
        root->left = addNode(value, root->left);
        
    }
    else if(value>=root->data){
        root->right = addNode(value, root->right);
    }
    return root;
}




//Lesson5


#define T int
#define Size 100
#define C char
int ind = -1;
int j = -1;
int m = -1;
int n = 0;
int z=0;
T Stack[Size];
C St[Size];
C Queue[Size];

//TASK1
void binaryPush (T i){
    int n=i/2;
    
    Stack[++ind] = i%2;
    while(n>=2){
        int m=n%2;
        Stack[++ind] = m;
        n = n/2;
    }
    Stack[++ind] = n;
    
}
T binaryPop (){
    if(ind != -1){
        return Stack[ind--];
    }
    return 0;
}


//TASK2
void push(C a){
    
    St[++j] = a;
}

C pop (){
    
    if (j!=-1){
        
        return St[j--];
    }
    return 0;
    
}


//TASK3
void enqueue (C a) {
    if (m< Size){
        m=m+1;
        Queue[m] = a;
        
    }
}

C dequeue (){
    m= m-m+z;
    if (m<Size){
        z=z+1;
        return Queue[m];
    }
    return 0;
}














//LESSON4

//Task3

int binarySearch(int*arr,int len,int v,int i){
   
    int m = (i+(len-1))/2;
    if(i>(len-1)){
        return -1;
    }
    if(arr[m]==v){
        return m;
    }
    if(arr[m]>v){
        return binarySearch(arr, m, v,i);
    }
    else {
        return binarySearch(arr, len, v, m+1);
    }
    
    return 0;
}






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
    
    printf("%d", hashFunc("hello"));
    
    printf("\n");
    
    struct Node *root = NULL;
    root = addNode(5, root);
    addNode(7, root);
    addNode(4, root);
    addNode(1, root);
    addNode(6,root);
    
    balancedOrder(root);
    
    printf("\n");
    
    leftRightRoot(root);
    
    printf("\n");
    
    if (searchBinaryTree(4, root)){
        printf("The value is in the binary tree");
    }
    else {
        printf("Couldn't find the value");
    }
    
    printf("\n");

    
    return 0;
    
    
   // const int SIZE = 5;
  //  int arr[SIZE];
  //  for(int i = 0;i<SIZE;i++){
       // arr[i] = rand() % 100;
      //  printf("%d\n",arr[i]);
    }
   // printf("\n");
   // printf("the count of buble  sorting operations is: %d\n",bubbleFunc(arr, SIZE));
   // printf("the count of insertion sorting operations is: %d\n",insertionSortFunc(arr, SIZE));
   // printf("The index of the number is: %d\n", linearRecFunc(arr,SIZE,58));
    //int *p;
   // p = sheikSortFunc(arr, SIZE);
   // for(int i =0; i<SIZE;i++){
      //  printf("%d\n", *(p+i));
   // }
   // printf("Binary search: The indes is %d\n",binarySearch(arr, SIZE,73,0));
    //decToBinfunc(5);
   // printf("%d\n",oddEvenPowerRec(6,3));


//binaryPush(4);
/*while (ind != -1) {
    printf("%d",binaryPop());
}
printf("\n");

char a [Size];
int i;
int l=-1;
int k=0;
printf ("Enter the expression ");
scanf("%s",a);

for (i=0; a[i] != '\0';i++){
    
    if (a[i] == '(' || a[i] == '[' || a[i] == '{'){
        push(a[i]);
        k=k+1;
        
    }
    else if (a[i] == ')' || a[i] == ']' || a[i] == '}') {
        if(j ==-1){
            printf("The are not an opening brackets\n");
            return 0;
        }
        
        char b = pop();
        if (((a[i] == ')' ) && (b == '(')) || ((a[i] == ']') && (b == '['))||((a[i] == '}' )&& (b == '{'))){
            if (l==-1){
                l = l+2;
            }
            else{
                l=l+1;
            }
            
        }
    }
    
}
if (k==l){
    printf("balanced paranthesis\n");
}
else if (k==0 && l==-1){
    
    printf("There are no any brackets\n");
}
else {
    printf("not balanced paranthesis\n");
}


enqueue('a');
enqueue('b');
enqueue('c');
enqueue('d');
enqueue('e');

n=m;
while(m<=n){
    printf("%c",dequeue());
}*/





}
