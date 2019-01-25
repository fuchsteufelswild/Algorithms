#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t, i;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        int n, j, temp;
        scanf("%d\n", &n);
        int B[4] = {0, 1, 2, 5};
        int total1, temp1;
        int *A = (int*)malloc(4 * n);
        int min = 0, total = 0, k;
        min = 1001;
        for(j = 0; j < n; j++){
            scanf("%d ", &A[j]);
            if(A[j] < min){
                min = A[j];
            }
        }
        for(k = 0; k < 4; k++){
            total1 = 0;
        for(j = 0; j < n; j++){
            if(A[j] + B[k] > min){
                temp = (A[j] - min + B[k]) % 5;
                total1 += (A[j] - min + B[k]) / 5;
                if(temp <= 2 && temp > 0){
                    total1 += 1;
                }
                else if(temp > 2){
                    total1 += 2;
                }
            }
        }
            if(k == 0){
                temp1 = total1;
            }
            else{
                if(total1 < temp1){
                    temp1 = total1;
                }
            }
            
        }
        printf("%d\n", temp1);
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
