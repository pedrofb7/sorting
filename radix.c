#include <stdio.h>
#include <stdlib.h>

// ---------- FUNCTIONS ---------- //

int *Allocate_int(int N); // Alocates an integer vector

int main() {

  int N; // number of integers
  scanf("%d", &N);
}

int *Allocate_int(int N) {
  return (int *)malloc(sizeof(int) * N);
};
