#include<stdio.h>

int coinChange(int* coins, int coinsSize, int amount) {
    if(amount==0) return 1;
    if(amount<0) return 0;

    int i,remainder;
    for(i=0;i<coinsSize;i++)
    {
        remainder=amount-coins[i];
        if(coinChange(coins,coinsSize,remainder)==1) return 1;
    }
    return 0;
}

void  main() {
    int coins[] = {20, 10, 5};
    int coinsSize = 3;
    int amount = 14;
    printf("%d", coinChange(coins, coinsSize, amount));
}