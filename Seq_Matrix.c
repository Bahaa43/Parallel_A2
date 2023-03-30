#include <stdio.h>
#include <stdlib.h>

int main() {
    int M[100][100], N[100][100], P[100][100];
    int m, n, p, q, i, j, k;
    
    printf("Enter the number of rows and columns for the first matrix (M): ");
    scanf("%d %d", &m, &n);
    
    printf("Enter the elements of the first matrix (M):\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    printf("Enter the number of rows and columns for the second matrix (N): ");
    scanf("%d %d", &p, &q);
    
    printf("Enter the elements of the second matrix (N):\n");
    for(i = 0; i < p; i++) {
        for(j = 0; j < q; j++) {
            scanf("%d", &N[i][j]);
        }
    }
    if(n!=p) {
        printf("Matrices are not compatible for multiplication.\n");
        return 0;
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < q; j++) {
            P[i][j] = 0;
            for(k = 0; k < n; k++) {
                P[i][j] += M[i][k] * N[k][j];
            }
        }
    }
    printf("The product of the matrices is:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < q; j++) {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }
    return 0;
}
