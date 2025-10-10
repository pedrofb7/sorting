#include <stdio.h>
#include <stdlib.h>

// ---------- FUNCTIONS ---------- //

int *Allocate_int(int N); // Alocates an integer vector

// ------------ MAIN -------------//
int main() {

  int N; // number of integers
  scanf("%d", &N);

  int *numbers = Allocate_int(N); // the numbers provided by the user
  for (int i = 0; i < N; i++) scanf("%d", &numbers[i]);

  free(numbers);

  return 0;
}

// ------- IMPLEMENTATIONS -------------//

int *Allocate_int(int N) {
  return (int *)malloc(sizeof(int) * N);
};
