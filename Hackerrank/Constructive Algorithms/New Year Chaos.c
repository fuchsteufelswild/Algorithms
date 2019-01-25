#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int max(int x, int y){
    if(x > y){
        return x;
    }
    else{
        return y;
    }
}
int main(){
    int T; 
    int a0;
    scanf("%d",&T);
    for(a0 = 0; a0 < T; a0++){
        int n, j; 
        int q_i, i, sum = 0, flag = 0;
        scanf("%d",&n);
        int *q = malloc(sizeof(int) * n);
        for(q_i = 0; q_i < n; q_i++){
           scanf("%d",&q[q_i]);
        }
        for(i = n - 1; i >= 0 ; i--){
            if(q[i] - i - 1 > 2){
                printf("Too chaotic\n");
                flag = 1;
                break;
            }
            if(flag == 1){
            break;
        }
            for(j = max(0, q[i] - 2); j < i; j++){
            if(q[j] > q[i]){
                sum ++;
            }
        }
        }
        
        if(flag == 0){
        printf("%d\n", sum);
        // your code goes here
    }
    }
    return 0;
}
