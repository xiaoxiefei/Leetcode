/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

* @Author	:	xiefei
* @Date		:	2000-10-09
*/

#include "main.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void sort_18(int *nums, int numsSize) {
	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] > nums[j]) {
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {

	int** result = (int**)malloc(sizeof(int*) * 2000);
	if (*result) {
		for (int i = 0; i < 2000; i++) {
			result[i] = (int*)malloc(sizeof(int) * 4);
			memset(result[i], 0, 4);
		}
	}

	sort_18(nums, numsSize);
	for (int i = 0; i < numsSize - 3; i++) {
		for (int j = i + 1; j < numsSize - 2; j++) {
			int left = j + 1;
			int right = numsSize - 1;
			while (left < right) {
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum < target) {
					left++;
				}
				else if (sum > target) {
					right--;
				}
				else {
					(returnColumnSizes)[*returnSize] = 4;
					//printf("%d %d %d %d\n", nums[i], nums[j], nums[left], nums[right]);
					(*result + (*returnSize))[0] = nums[i];
					(*result + (*returnSize))[1] = nums[j];
					(*result + (*returnSize))[2] = nums[left];
					(*result + (*returnSize))[3] = nums[right];
					for (int w = 0; w < 4; w++) {
						printf("%d ", (*result + (*returnSize))[w]);
					}
					printf("returnSize = %d  size = %d\n", *returnSize, returnColumnSizes[*returnSize]);
					(*returnSize)++;
					break;
				}
			}
		}
	}
	printf("size = %d\n", *returnSize);
	for (int i = 0; i < *returnSize; i++) {
		printf("returnSize = %d  size = %d\n",i , returnColumnSizes[i]);
	}
	return result;
}

#define numsSize  6
void code_18() {
	int nums[numsSize] = { 1,0,-1,0,-2,2 };
	int target = 0;
	int returnSize = 0;
	int* returnColumnSize = (int *)malloc(sizeof(int) * 2000);
	int **ret = fourSum(nums, numsSize, target, &returnSize, returnColumnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("size = %d \n", returnColumnSize[i]);
	}
	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < returnColumnSize[i]; j++) {
			printf("%d ", ret[i][j]);
		}
		printf("\n");
	}
}