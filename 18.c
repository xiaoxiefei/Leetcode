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

void sort_18(int* nums, int numsSize) {
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

int is_in(int** nums, int numsSize, int* temp) {
	for (int i = 0; i < numsSize; i++) {
		int num = 0;
		for (int j = 0; j < 4; j++) {
			if (nums[i][j] == temp[j])num++;
		}
		if (num == 4)return 0;
		num = 0;
	}
	return 1;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {

	*returnColumnSizes = (int*)malloc(sizeof(int) * 1001);
	*returnSize = 0;
	int** result = (int**)malloc(sizeof(int*) * 1001);


	sort_18(nums, numsSize);

	for (int i = 0; i < numsSize - 3; i++) {
		for (int j = i + 1; j < numsSize - 2; j++) {

			int left = j + 1;
			int right = numsSize - 1;

			while (left < right) {
				long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
				if (sum < target) {
					left++;
				}
				else if (sum > target) {
					right--;
				}
				else {
					(*returnColumnSizes)[*returnSize] = 4;
					int* temp = (int*)malloc(sizeof(int) * 4);
					temp[0] = nums[i];
					temp[1] = nums[j];
					temp[2] = nums[left];
					temp[3] = nums[right];
					sort_18(temp, 4);
					if (is_in(result, *returnSize, temp)) {
						*(result + (*returnSize)) = temp;
						(*returnSize)++;
					}
					left++;
					continue;
				}
			}
		}
	}

	return result;
}

#define numsSize  5
void code_18() {
	int nums[numsSize] = { 2,2,2,2,2 };
	int target = 8;
	int returnSize = 0;
	int returnColumnSize[1001];

	int **result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSize);
	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}

/*
* 勉强做对，思路垃圾，不写解题思路了，希望自己下次碰到可以好运
*/