#include <stdio.h>

struct Activity {
    int index;
    int s, f;
};

void sort(struct Activity a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j].f > a[j+1].f) {
                struct Activity t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

void select(struct Activity a[], int n, struct Activity sel[], int *sc) {
    int i = 0;
    sel[(*sc)++] = a[i];
    for (int j = 1; j < n; j++) {
        if (a[j].s >= a[i].f) {
            sel[(*sc)++] = a[j];
            i = j;
        }
    }
}

int main() {
    int n, sc = 0,i;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity a[n], sel[n];
    for (i = 0; i < n; i++) {
        printf("Enter start and finish %d: ", i+1);
        a[i].index = i + 1; // Change index to start from 1
        scanf("%d %d", &a[i].s, &a[i].f);
    }

    sort(a, n);
    select(a, n, sel, &sc);

    printf("Selected activities: ");
    for (i = 0; i < sc; i++) {
        printf("%d ", sel[i].index);
    }
    printf("\n");

    return 0;
}
