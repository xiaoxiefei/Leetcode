#include "main.h"

#define NUMSSIZE 3

/***************
*	½×³Ë
***************/
int factorial(int n) {
	int ret = 1;
	while (n) {
		ret *= n;
		n--;
	}
	return ret;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = factorial(numsSize);
	returnColumnSizes = (int**)malloc(sizeof(int*) * (*returnSize));
	printf("returnColumnSizes = %d\n", returnColumnSizes);

}


void code_46() {
	int nums[NUMSSIZE] = { 1,2,3 };
	int returnSize = 0;
	int** returnColumnSizes;
	returnColumnSizes =  permute(nums, NUMSSIZE, &returnSize, returnColumnSizes);
}