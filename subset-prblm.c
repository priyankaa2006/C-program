#include <stdio.h>
#include <stdlib.h>
void findSubsets(int arr[], int n, int index, int sum, int
currentSum, int solution[], int solIndex) {
 if (currentSum == sum) {
 printf("{ ");
 for (int i = 0; i < solIndex; i++) {
 printf("%d ", solution[i]);
 }
 printf("}\n");
 return;
 }
 if (index == n || currentSum > sum) {
 return;
 }
 solution[solIndex] = arr[index];
 findSubsets(arr, n, index + 1, sum, currentSum + arr[index],
solution, solIndex + 1);
 findSubsets(arr, n, index + 1, sum, currentSum, solution,
solIndex);
}
int main() {
 int n, d;
 printf("Enter the number of elements in the set: ");
 scanf("%d", &n);
 int *arr = (int *)malloc(n * sizeof(int));
 printf("Enter the elements of the set:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 printf("Enter the target sum: ");
 scanf("%d", &d);
 int *solution = (int *)malloc(n * sizeof(int));
 printf("Subsets with sum %d:\n", d);
 findSubsets(arr, n, 0, d, 0, solution, 0);
 free(arr);
 free(solution);
 return 0;
}
