#include <stdio.h>
#include <stdlib.h>

int* coinChange(int* coins, int coinsSize, int amount, int* used) {
    if (amount == 0) {
        int* result = malloc(sizeof(int) * 1);
        result[0] = 0;
        return result;
    }
    if (amount < 0) return NULL;
    int* shortestCombination = NULL;    
    for (int i = 0; i < coinsSize; i++) {
        if (used[i] > 0) continue; // Skip used coins
        int remainder = amount - coins[i];
        used[i] = 1; // Mark coin as used
        int* remainder_res = coinChange(coins, coinsSize, remainder, used);
        used[i] = 0; // Unmark coin after recursion

        if (remainder_res != NULL) {
            int res_length = 0;
            while (remainder_res[res_length] != 0) res_length++;
            int* result = malloc(sizeof(int) * (res_length + 2));
            for (int j = 0; j < res_length; j++) {
                result[j] = remainder_res[j];
            }
            result[res_length] = coins[i];
            result[res_length + 1] = 0;
            free(remainder_res);
            return result;
        }
    }
    return NULL;
}

void main() {
    int coins[100], coinsSize, amount, i;
    printf("Enter the number of coins: ");
    scanf("%d", &coinsSize);
    printf("Enter the coins: ");
    for (i = 0; i < coinsSize; i++) {
        scanf("%d", &coins[i]);
    }
    printf("Enter the amount: ");
    scanf("%d", &amount);

    int used[100] = {0}; // Array to track used coins
    int* result = coinChange(coins, coinsSize, amount, used);
    if (result != NULL) {
        for (int i = 0; result[i] != 0; i++) {
            printf("%d ", result[i]);
        }
        free(result);
    } else {
        printf("No solution");
    }
}