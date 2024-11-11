#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int dp[n+1][W+1];  // DP table to store maximum value at each (i, w)

    // Build table dp[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Base case: no items or no capacity
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]); // Include or exclude item
            else
                dp[i][w] = dp[i-1][w];  // Exclude item
        }
    }

    // Print the final DP table
    printf("DP Table:\n");
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            printf("%d ", dp[i][w]);
        }
        printf("\n");
    }

    // Print the result
    printf("Maximum value in knapsack = %d\n", dp[n][W]);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the value and weight arrays
    int val[n], wt[n];
    
    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    // Call the knapsack function to solve the problem
    knapsack(W, wt, val, n);

    return 0;
}
