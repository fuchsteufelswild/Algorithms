#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int check(int **M, long long int *A, int column, int row, int n);
int backtrack(int **M, long long int *A, int column, int row, int n, int *B, int *ptr){
    int a = 0;
    *ptr = 0;
   
    if(row == n){
        *ptr = 1;
       
        return a;
    }
    int i, j, flag = 0;
    for(i = 0; i < n; i++){
        flag = 0;
        
       
        for(j = 0; j < row; j++){
            if(i == B[j]){
                flag = 1;
            }
     
        }
        if(flag != 0){
            continue;
        }
        int a = check(M, A, i, row, n);
        B[row] = i;
        
        if(a){
            backtrack(M, A, i, row + 1, n, B, ptr);
        }
    }
    return a;
}
int check(int **M, long long int *A, int column, int row, int n){
            int i, j; 
            long long int sum = 0;
            for(j = 0; j < n; j++){
                if(j == column){
                    continue;
                }
                sum += M[row][j];
            }
            if(sum == A[column] - M[row][column]){
                
                return 1;
            }
            
            return 0;
        
}
int main(){
    int q; 
    scanf("%d",&q);
    int a0;
    for(a0 = 0; a0 < q; a0++){
        int n;
        int *B = (int*)malloc(4 * n);
        scanf("%d",&n);
        long long int A[n];
        int *M[n];
        int i, j;
        for(i = 0; i < n; i++){
            A[i] = 0;
        }
        for(i = 0; i < n; i++){
            M[i] = (int*)malloc(4 * n);
        }
        for(int M_i = 0; M_i < n; M_i++){
           for(int M_j = 0; M_j < n; M_j++){
              
              scanf("%d",&M[M_i][M_j]);
           }
        }
        for(int M_i = 0; M_i < n; M_i++){
           for(int M_j = 0; M_j < n; M_j++){
             
              A[M_i] += M[M_j][M_i];
           }
        }
        int c = 0;
        int *ptr = &c;
        int column;
        int flag = 0;
        for(i = 0; i < n; i++){
            flag = 0;
            column = i;
            B[0] = column;
            int c = backtrack(M, A, column, 1, n, B, ptr);
            if(*ptr == 1){
                printf("Possible\n");
                flag = 1;
                break;
            }
            
        }
        if(flag == 0){
                printf("Impossible\n");
            }
        
        // your code goes here
    }
    return 0;
}
