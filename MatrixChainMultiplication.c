#include <stdio.h>
#define MAX 100

int m[MAX][MAX], s[MAX][MAX];

void printOptimalParenthesis(int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParenthesis(i, s[i][j]);
        printOptimalParenthesis(s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n = 4, i, j, k, len, q;
    printf("Enter number of matrices: ");
    scanf("%d",&n);

    int p[n+1];

    printf("Enter %d elements of the dimension matrix: ",(n+1));
    for(i=0;i<n+1;i++){
        scanf("%d",&p[i]);
    }

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (len = 2; len <= n; len++) {
        for (i = 1; i <= n - len + 1; i++) {
            j = i + len - 1;
            m[i][j] = 99999999;
            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nMinimum Number of computation: %d\n",m[1][n]);
    printf("\nOptimal Parenthesis: ");
    printOptimalParenthesis(1, n);

    return 0;
}
