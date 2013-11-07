#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
void printArray(int *a, int len) {
	int i = 0;
	for (i = 0; i < len; i++) {
		printf("a[%d] is %d\n", i, a[i]);
	}
 
	printf("\n");
}
 
void swap(int *a, int l, int r) {
	int t;
	t = a[l];
	a[l] = a[r];
	a[r] = t;
}
 
 
 
void quickSort(int *a, int i, int j) {
	printf("quickSort called!\n");
	printf("i = %d j = %d\n", i, j);
 
	// Make sure we are in bounds of array
	if (i < j) {
		int p = (i + j)/2;
		int l = i;
		int r = j;
 
		while ( l < r ) {
			// Find element larger than pivot, if it exists,
			// else stop at pivot
			while( (a[l] <= a[p]) && (l < p) ) {
				l++;
			}
			printf("l: %d\n", l);
 
			// Find element smaller than pivot, if it exists,
			// else stop at pivot
			while( (a[r] >= a[p]) && (r > p) ) {
				r--;
			}
			printf("r: %d\n", r);
 
			// Swap if elements still need to be switched 
			if (l < r) {
				swap(a, l, r);
				printf("Post swap\n");
				printArray(a, 10);
			}
		}//end while
 
		quickSort(a, i, p);
		quickSort(a, p+1, j);
	}//end if
}//end quickSort
 
 
int main(int argc, char *argv[]) {
	int i;
	const int LEN = argc - 1;
 
	// Print out arguments
	// printf("Number of arguments: %d\n", argc);
	// for (i = 0; i < argc; i++) {
	// 	printf("%s\n", argv[i]);
	// }
 
	// Create int array
	int A[LEN];
	
	// Fill A with input
	for (i = 0; i < argc - 1; i++) {
		int n;
		A[i] = atoi(argv[i + 1]);
	}
 
	printArray(&A[0], LEN);
	quickSort(A, 0, LEN-1);
	printArray(A, LEN);
}