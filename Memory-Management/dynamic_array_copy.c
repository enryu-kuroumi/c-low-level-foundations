#include <stdio.h>
#include <stdlib.h>
int show(int rows, int cols, int a[rows][cols]) {
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
int *copy(int rows, int cols, int a[rows][cols])
{
  int all = rows * cols;
  int *copy = malloc(all * sizeof(int));
  for (int i = 0; i < all; i++){
    copy[i] = a[i/cols][i%cols];
  }
  int* tab2[rows];
  for (int i = 0; i < rows; i++) {
    tab2[i] = &copy[i * cols];
  }

  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          printf("%d ", tab2[i][j]);
      }
    printf("\n");
  }
  return copy;
}
void dealoc(int* arr2) {
    free(arr2);
}
int main() {
    int tab[2][2]; 
    show(2, 2, tab);
    int *my_copy = copy(2, 2, tab);
    dealoc(my_copy);
    return 0;
}
