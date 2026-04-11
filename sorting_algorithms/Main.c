#include <stdio.h>


void zamien(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}


int min(float tab[], int start, int n) {
    int min_index = start;
    for (int i = start + 1; i < n; i++) {
        if (tab[i] < tab[min_index])
            min_index = i;
    }
    return min_index;
}


void selekcja(float tab[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = min(tab, i, n);
        if (min_index != i) {
            zamien(&tab[i], &tab[min_index]);
        }
    }
}

int main() {
    float tab[] = {3.2, -1.5, 0.0, 7.1, 2.4};
    int n = sizeof(tab) / sizeof(tab[0]);

    selekcja(tab, n);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", tab[i]);
    }


    return 0;
}
