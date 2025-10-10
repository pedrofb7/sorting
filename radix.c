#include <stdio.h>
#include <stdlib.h>

// ---------- FUNCTIONS ---------- //

int *Allocate_int(int N); // Alocates an integer vector



// ------------Counting Sort-------------//
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}




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
