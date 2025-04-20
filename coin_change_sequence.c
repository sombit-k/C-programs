#include <stdio.h>
#include <stdlib.h>

int* coinChange(int* coins, int coinsSize, int amount) {
    if (amount == 0) {
        int* result = malloc(sizeof(int) * 1);
        result[0] = 0;
        return result;
    }
    if (amount < 0) return NULL;
    int* shortestCombination = NULL;    
    for (int i = 0; i < coinsSize; i++) {
        int remainder = amount - coins[i];
        int* remainder_res = coinChange(coins, coinsSize, remainder);


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

    int* result = coinChange(coins, coinsSize, amount);
    if (result != NULL) {
        for (int i = 0; result[i] != 0; i++) {
            printf("%d ", result[i]);
        }
        free(result);
    } else {
        printf("No solution");
    }
}