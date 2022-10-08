/*
* 给定两个大小相等的数组 nums1 和 nums2，nums1 相对于 nums 的优势可以用满足 nums1[i] > nums2[i] 的索引 i 的数目来描述。

返回 nums1 的任意排列，使其相对于 nums2 的优势最大化。

输入：nums1 = [2,7,11,15], nums2 = [1,10,4,11]
输出：[2,11,7,15]

* @Author	:	xiefei
* @Date		:	2022-10-08
*/

#include "main.h"

#define SIZE 4

void swap_1(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//快速排序
void my_quick_sort(int* nums, int left, int right, int *index) {
	if (left >= right)return;
	int i, j;
	for (i = left + 1, j = right; i <= j;) {

		if (nums[i] <= nums[left]) {
			i++;
			continue;
		}
		if (nums[i] > nums[left]) {
			if (nums[j] < nums[left]) {
				swap_1(&nums[i], &nums[j]);
				swap_1(&index[i], &index[j]);
				i++;
				j--;
				continue;
			}
			if (nums[j] >= nums[left]) {
				j--;
			}
		}
	}
	if (i >= j) {
		i = i < j ? i : j;
		if (nums[i] < nums[left]) {
			swap_1(&nums[i], &nums[left]);
			swap_1(&index[i], &index[left]);
		}

		my_quick_sort(nums, left, i - 1, index);
		my_quick_sort(nums, i + 1, right, index);
	}
}


int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	*returnSize = nums1Size;
	
	int* result = (int*)malloc(sizeof(int) * nums1Size);
	if (result) {
		memset(result, 0, nums1Size);
	}

	int* index = (int*)malloc(sizeof(int) * nums1Size);
	for (int i = 0; i < nums1Size; i++) {
		index[i] = i;
	}
	my_quick_sort(nums1, 0, nums1Size - 1, index);
	for (int i = 0; i < nums1Size; i++) {
		index[i] = i;
	}
	my_quick_sort(nums2, 0, nums2Size - 1, index);
	
	int left = 0, right = nums2Size - 1;
	for (int i = 0; i < nums2Size; i++) {
		if (nums1[i] > nums2[left]) {
			nums2[left] = nums1[i];
			left++;
		}
		else {
			nums2[right] = nums1[i];
			right--;
		}
	}

	for(int i = 0; i < nums2Size; i++) {
		result[index[i]] = nums2[i];
	}
	return result;
}

void code_870() {

	int nums1[SIZE] = { 12,24,8,32 };
	int nums2[SIZE] = { 13,25,32,11 };
	int returnSize = 0;
	int* result = advantageCount(nums1, SIZE, nums2, SIZE, &returnSize);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
}

/*
* 解题思路：
* 两个数组排序
* 从第一个数组第i=0个元素开始，第二个数组用left和right标记没有对比的范围
*	若nums1[i] > nums2[left]，nums2[left] = nums1[i],left++;
*	否则，nums2[right] = nums1[i], right--;
*/