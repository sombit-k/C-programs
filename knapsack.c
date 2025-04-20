#include <stdio.h>
#include <stdlib.h>

struct Obj {
    int w; // weight
    int p; // profit
    double r; // profit/weight ratio
};

// Comparison function to sort objects by ratio in descending order
int cmp(const void *a, const void *b) {
    struct Obj *A = (struct Obj *)a;
    struct Obj *B = (struct Obj *)b;
    return (B->r - A->r) > 0 ? 1 : -1;
}

double fracKnapsack(int W, struct Obj objs[], int n) {
    qsort(objs, n, sizeof(struct Obj), cmp);
    double profit = 0.0;
    for (int i = 0; i < n; i++) {
        if (objs[i].w <= W) {
            W -= objs[i].w;
            profit += objs[i].p;
        } else {
            profit += objs[i].p * ((double)W / objs[i].w);
            break;
        }
    }
    return profit;
}

int main() {
    int n, W;
    printf("Enter number of objects: ");
    scanf("%d", &n);
    struct Obj objs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit of object %d: ", i+1);
        scanf("%d %d", &objs[i].w, &objs[i].p);
        objs[i].r = (double)objs[i].p / objs[i].w;
    }
    printf("Enter maximum weight: ");
    scanf("%d", &W);
    printf("Maximum profit: %.2f\n", fracKnapsack(W, objs, n));
    return 0;
}
