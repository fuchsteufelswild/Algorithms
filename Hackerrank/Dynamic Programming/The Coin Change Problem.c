#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int c[m];
    int i, j, total;
    for(i = 0; i < m; i++){
        scanf("%d ", &c[i]);
    }
    long int sol[m + 1][n + 1];
    for(i = 0; i < m + 1; i++){
        sol[i][0] = 1;
    }
    for(i = 1; i <= n; i++){
        sol[0][i] = 0;
    }
    for(i = 1; i < m + 1; i++){
        for(j = 1; j < n + 1; j++){
            if(c[i - 1] <= j){
                sol[i][j] = sol[i - 1][j] + sol[i][j - c[i - 1]];
            }
            else{
                sol[i][j] = sol[i - 1][j];
            }
        }
    }
    
    printf("%ld", sol[m][n]);
    return 0;
}
