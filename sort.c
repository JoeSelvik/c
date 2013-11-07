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
	// printf("quickSort called!\n");
	// printf("i = %d j = %d\n", i, j);
 
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
			// printf("l: %d\n", l);
 
			// Find element smaller than pivot, if it exists,
			// else stop at pivot
			while( (a[r] >= a[p]) && (r > p) ) {
				r--;
			}
			// printf("r: %d\n", r);
 
			// Swap if elements still need to be switched 
			if (l < r) {
				swap(a, l, r);
				// printf("Post swap\n");
				// printArray(a, 10);
			}
		}//end while
 
		quickSort(a, i, p);
		quickSort(a, p+1, j);
	}//end if
}//end quickSort

// ******************************************************************************
typedef struct BinTreeNode BinTreeNode;

struct BinTreeNode {
	BinTreeNode		*leftChild;
	BinTreeNode		*rightChild;
	int 			data;
};

void fillH(BinTreeNode *h, int *a, int len) {
	int i = 0;
	for(i = 0; i < len; i++) {
		struct BinTreeNode t;
		t.leftChild = NULL;
		t.rightChild = NULL;
		t.data = a[i];

		h[i] = t;
	}
}

void printH(BinTreeNode *h, int len) {
	int i = 0;
	for (i = 0; i < len; i++) {
		printf("h[%d] is %d\n", i, h[i].data);
	}
	printf("\n");
}

int findLargeChild(BinTreeNode *h, int i, int len) {
	int leftIndex = i*2+1;
	int rightIndex = i*2+2;

	if (leftIndex > len)
		return -1;
	else if (rightIndex > len)
		return -2;

	if (h[leftIndex].data > h[rightIndex].data)
		return leftIndex;
	else
		return rightIndex;
}



// ****************************************************************************** 
 
int main(int argc, char *argv[]) {
	int i;
	const int LEN = argc - 1;
 
	// Create int array
	int A[LEN];

	// Create BinTreeNode array
	BinTreeNode H[LEN];
	
	// Fill A with input
	for (i = 0; i < argc - 1; i++) {
		int n;
		A[i] = atoi(argv[i + 1]);
	}
 
	printArray(A, LEN);
	quickSort(A, 0, LEN-1);
	printArray(A, LEN);

	printf("Creating H\n");

	// Fill H with BinTreeNodes
	fillH(H, A, LEN);
	printH(H, LEN);
}







