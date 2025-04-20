#include <stdio.h>
#include <stdlib.h>

int* calc(int* coins, int coinsSize, int amount, int* returnSize) {
    if (amount == 0) {
        *returnSize = 0;
        return (int*)malloc(0);
    }
    if (amount < 0) {
        *returnSize = -1;
        return NULL;
    }

    int* shortestCombination = NULL;
    int shortestLength = -1;

    for (int i = 0; i < coinsSize; i++) {
        int remaining_coin = amount - coins[i];
        int remainderSize;
        int* remainder_res = calc(coins, coinsSize, remaining_coin, &remainderSize);

        if (remainder_res != NULL) {
            int combinationLength = remainderSize + 1;
            int* combination = (int*)malloc(combinationLength * sizeof(int));
            for (int j = 0; j < remainderSize; j++) {
                combination[j] = remainder_res[j];
            }
            combination[remainderSize] = coins[i];

            if (shortestCombination == NULL || combinationLength < shortestLength) {
                if (shortestCombination != NULL) {
                    free(shortestCombination);
                }
                shortestCombination = combination;
                shortestLength = combinationLength;
            } else {
                free(combination);
            }
            free(remainder_res);
        }
    }

    *returnSize = shortestLength;
    return shortestCombination;
}

int main() {
    int coinsSize;
    printf("Enter the number of coin types: ");
    scanf("%d", &coinsSize);

    int* coins = (int*)malloc(coinsSize * sizeof(int));
    printf("Enter the coin values: ");
    for (int i = 0; i < coinsSize; i++) {
        scanf("%d", &coins[i]);
    }

    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    int returnSize;
    int* result = calc(coins, coinsSize, amount, &returnSize);

    if (result != NULL) {
        printf("Shortest combination: ");
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    } else {
        printf("No combination found.\n");
    }

    free(coins);
    return 0;
}
