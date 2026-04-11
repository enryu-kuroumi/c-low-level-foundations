#include <stdio.h>
#include <stdlib.h>

void wyswietl(int rows, int cols, int a[rows][cols]) {
    int w = 1; 

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = w++;
        }
    }

   

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

   

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%p ", &a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tab[2][2]; 

    wyswietl(2, 2, tab); 

    return 0;
}
