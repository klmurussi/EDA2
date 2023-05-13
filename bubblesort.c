#include <stdio.h>

void cmpexch(int A, int B) {
  if (B < A) {
    int t = A;
    A = B;
    B = t;
  }
}

void bubblesort(int *v, int l, int r) {
  for (int i = l; i < r; i++) {
    for (int j = l + 1; j <= r; j++)
      cmpexch(v[j - 1], v[j]);
  }
}

int main(void) {
    int v[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubblesort(v, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
  return 0;
}