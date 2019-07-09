//
//  main.c
//  toroyanseda_L2
//
//  Created by Seda on 07/07/2019.
//  Copyright © 2019 Seda. All rights reserved.
//

#include <stdio.h>


//Task1

int decToBinfunc(int a){
   
  int b = a%2;
    
    if (a>0){
        
    decToBinfunc(a/2);
     
   printf("%d",b);
        
    }
   
    return 0;
    
}



//Task2(a,b)
int oddEvenPowerRec(int a,int b){
    int k;
    if (b==0){
        return 1;
    }
    if (b==1){
        return a;
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
    
    decToBinfunc(5);
    printf("\n");
    printf("%d\n",oddEvenPowerRec(6,3));
    
    return 0;
}
