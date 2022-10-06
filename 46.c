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

void swap(int* nums, int a, int b) {
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

void fun(int* nums, int numsSize, int** result, int* returnSize, int i) {

	if (i == numsSize) {
		for (int j = 0; j < i; j++) {
			result[*returnSize][j] = nums[j];
		}
		*returnSize += 1;

	}
	if (*returnSize == factorial(numsSize)) {
		return;
	}
	int k;
	for (k = i; k < numsSize; k++) {
		swap(nums, i, k);
		fun(nums, numsSize, result, returnSize, i + 1);
		swap(nums, i, k);
	}
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = factorial(numsSize);
	int** result = (int**)malloc(sizeof(int*) * (*returnSize));
	if (!result) {
		return;
	}
	for (int i = 0; i < *returnSize; i++) {
		returnColumnSizes[i] = numsSize;
		*(result +i) = (int*)malloc(sizeof(int) * numsSize);
		if (*(result + i)) {
			memset(*(result + i), 0, sizeof(int) * numsSize);
		}
	}

	*returnSize = 0;
	fun(nums, numsSize, result, returnSize, 0);
	return result;
}


void code_46() {
	int nums[NUMSSIZE] = { 1,2,3 };
	int** result;
	int** returnColumnSizes;
	int returnSize = factorial(NUMSSIZE);
	returnColumnSizes = (int**)malloc(sizeof(int*) * (returnSize));
	returnColumnSizes = permute(nums, NUMSSIZE, &returnSize, returnColumnSizes);
	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < NUMSSIZE; j++) {
			printf("%d ", returnColumnSizes[i][j]);
		}
	}
}