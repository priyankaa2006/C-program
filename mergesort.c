#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void generate_random_array(int[], int);
void read_array_from_file(int[], int*);
int main() {
 int i, n, a[1000], ch = 1, source_choice;
 clock_t start, end;

 while (ch) {
 printf("Choose the input method:\n");
 printf("1. Generate random array\n");
 printf("2. Read array from file\n");
 scanf("%d", &source_choice);
 if (source_choice == 1) {
 printf("Enter the number of elements: ");
 scanf("%d", &n);

 generate_random_array(a, n);
 } else if (source_choice == 2) {
 read_array_from_file(a, &n);
 } else {
 printf("Invalid choice. Exiting.\n");
 return 0;
 }
 printf("Array elements:\n");
 for (i = 0; i < n; i++) {
 printf("%d ", a[i]);
 }
 printf("\n");
 start = clock();
 mergeSort(a, 0, n - 1);
 end = clock();
 printf("Sorted array elements are:\n");
 for (i = 0; i < n; i++) {
 printf("%d ", a[i]);
 }
 printf("\nTime taken = %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
 printf("Do you want to continue (0/1)? ");
 scanf("%d", &ch);
 }
 return 0;
}
void mergeSort(int a[], int low, int high) {
 if (low < high) {
 int mid = (low + high) / 2;
 mergeSort(a, low, mid);
 mergeSort(a, mid + 1, high);
 merge(a, low, mid, high);
 }
}
void merge(int a[], int low, int mid, int high) {
 int i, j, k, n1, n2;
 n1 = mid - low + 1;
 n2 = high - mid;
 int L[n1], R[n2];
 for (i = 0; i < n1; i++)
 L[i] = a[low + i];
 for (j = 0; j < n2; j++)
 R[j] = a[mid + 1 + j];
 i = 0;
 j = 0;
 k = low;
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 a[k] = L[i];
 i++;
 } else {
 a[k] = R[j];
 j++;
 }
 k++;
 }
 while (i < n1) {
 a[k] = L[i];
 i++;
 k++;
 }
 while (j < n2) {
 a[k] = R[j];
 j++;
 k++;
 }
}
void generate_random_array(int a[], int n) {
 srand(time(0));
 for (int i = 0; i < n; i++) {
 a[i] = rand() % 1000;
 }
}
void read_array_from_file(int a[], int *n) {
 FILE *file = fopen("input.txt", "r");
 if (file == NULL) {
 printf("File not found. Exiting.\n");
 exit(1);
 }
 int i = 0;
 while (fscanf(file, "%d", &a[i]) != EOF && i < 1000) {
 i++;
 }
 *n = i;
 fclose(file);
}
