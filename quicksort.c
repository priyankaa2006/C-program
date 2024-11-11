#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quicksort(int[], int, int);
int partition(int[], int, int);
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
quicksort(a, 0, n - 1);
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
void quicksort(int a[], int low, int high) {
int mid;
if (low < high) {
mid = partition(a, low, high);
quicksort(a, low, mid - 1);
quicksort(a, mid + 1, high);
}
}
int partition(int a[], int low, int high) {
int key, i, j, temp;
key = a[low];

i = low + 1;
j = high;
while (i <= j) {
while (i <= high && key >= a[i]) i++;
while (key < a[j]) j--;
if (i < j) {
temp = a[i];
a[i] = a[j];
a[j] = temp;
} else {
temp = a[j];
a[j] = a[low];
a[low] = temp;
}
}
return j;
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
