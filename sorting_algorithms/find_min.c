#include <stdio.h>
#include <stdlib.h>


float  table(float tab[], int n)
{
  if (n<= 0) return 0;
  float min = tab[0];
  for (int i = 1; i <n; i++)
  {
    if (tab[i]<min)
    {
      min = tab[i];
    }
  }
  return min;
}
int main()
{
  float dane[] = {12.5, 2.5, 4, 16, 2.00002, 1, 0.23234};
  int n = sizeof(dane)/sizeof(*dane);
  printf("%f\n", table(dane, n));
}


