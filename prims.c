#include <stdio.h>
#include <limits.h>

void main() {
    int cost[10][10], visited[10] = {0}, n, a, b, i, j, numEdges = 1, minCost = 0, min;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (Enter 0 for no connection):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INT_MAX;
            }
        }
    }

    visited[0] = 1;

    while (numEdges < n) {
        min = INT_MAX;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("\n%d - %d cost = %d", a, b, min);
        minCost += min;
        visited[b] = 1;
        cost[a][b] = cost[b][a] = INT_MAX;
        numEdges++;
    }
    printf("\nMinimum cost is %d\n", minCost);
}
