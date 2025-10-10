#include <stdio.h>
#include <stdlib.h>

// ---------- FUNCTIONS ---------- //

int *Allocate_int(int N);                     // Alocates an integer vector
void countingSort(int arr[], int n, int exp); // Counting sort
void radixSort(int arr[], int n);             // Radix :)

// ------------ MAIN -------------//
int main() {

  int N; // number of integers
  scanf("%d", &N);

  int *numbers = Allocate_int(N); // the numbers provided by the user
  for (int i = 0; i < N; i++) scanf("%d", &numbers[i]);
  radixSort(numbers, N);

  for (int i = 0; i < N; i++) {
    printf("%d ", numbers[i]);
  }

  free(numbers);

  return 0;
}

// ------- IMPLEMENTATIONS -------------//

// ------------ Alocation --------------//
int *Allocate_int(int N) {
  return (int *)malloc(sizeof(int) * N);
};

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

// ------------Radix Sort-------------//
void radixSort(int arr[], int n) {
  int max = arr[0];
  for (int i = 0; i < n; i++) { // Find the maximum value in the array;
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  for (int exp = 1; max / exp > 0;
       exp *= 10) { // Sort based in the decimal place
    countingSort(arr, n, exp);
  }
}
