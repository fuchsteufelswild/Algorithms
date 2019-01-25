#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max(int x, int y){
    if(x > y){
        return x;
    }
    else{
        return y;
    }
}
int main() {
    int q, i, j, x;
    scanf("%d", &q);
    
    for(i = 0; i < q; i++){
        int n;
        scanf("%d", &n);
        int A[2 * n][2 * n];
        int length = 2 * n;
        
        for(x = 0; x < length; x++){
        for(j = 0; j < length; j++){
            scanf("%d ", &A[x][j]);
        }
        }
        int maxi = -1;
        int sum = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n ; j++){
                int addition = A[i][j];
                addition = max(addition,max(A[length - i - 1][j], A[i][length - j - 1]));
                addition =  max(addition,A[length - i - 1][length - j - 1]);
                sum += addition;
            }
        }
        printf("%d\n", sum);
        
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
