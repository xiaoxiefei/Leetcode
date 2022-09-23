/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
*/

#include "main.h"

#define NUMSSIZE 3

/***************
*	阶乘
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
	printf("%d\n", *returnSize);
	int ** result = (int**)malloc(sizeof(int*) * (*returnSize));
	if (!result) {
		return;
	}
	for (int i = 0; i < numsSize; i++) {
		result[i] = (int*)malloc(sizeof(int) * numsSize);
	}
	for (int i = 0; i < *returnSize; i++) {
		for (int j = 0; j < numsSize; j++) {
			result[i][j] = 0;
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

}


void code_46() {
	int nums[NUMSSIZE] = { 1,2,3 };

	int** returnColumnSizes;
	int returnSize = factorial(NUMSSIZE);
	returnColumnSizes = (int**)malloc(sizeof(int*) * (returnSize));
	returnColumnSizes =  permute(nums, NUMSSIZE, &returnSize, returnColumnSizes);
}