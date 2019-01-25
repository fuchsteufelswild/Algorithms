#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int b[100000];
int find_bigger(int a, int b){
    return a > b ? a : b;
}
int main(){
	int t;
	scanf("%d\n", &t);
	while (t--)
	{
		int n;
        int i;
		scanf("%d\n", &n);
		for (i = 0; i < n; i++)
			scanf("%d ", &b[i]);
        int s1[n + 1];
        int s2[n + 1];
        int temp;
        s1[0] = 0;
        s2[0] = 0;
        int j = 0;
		for (i = 1; i < n; i++){
            s1[i] = find_bigger(s2[i - 1] + b[i] - 1, s1[i - 1] + fabs(b[i] - b[i - 1]));
            s2[i] = s1[i - 1] + b[i - 1] - 1;
		}
		printf("%d\n", find_bigger(s1[n - 1], s2[n - 1]));
	}
	return 0;
}
