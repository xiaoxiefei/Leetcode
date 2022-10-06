/*
* 给定一个由 0 和 1 组成的数组 arr ，将数组分成  3 个非空的部分 ，使得所有这些部分表示相同的二进制值。

如果可以做到，请返回任何 [i, j]，其中 i+1 < j，这样一来：

arr[0], arr[1], ..., arr[i] 为第一部分；
arr[i + 1], arr[i + 2], ..., arr[j - 1] 为第二部分；
arr[j], arr[j + 1], ..., arr[arr.length - 1] 为第三部分。
这三个部分所表示的二进制值相等。
如果无法做到，就返回 [-1, -1]。

注意，在考虑每个部分所表示的二进制时，应当将其看作一个整体。例如，[1,1,0] 表示十进制中的 6，而不会是 3。此外，前导零也是被允许的，所以 [0,1,1] 和 [1,1] 表示相同的值。

* 
* @Author	:	xiefei
* @Date		:	2022-10-06
* 
*/

#include "main.h"

int* threeEqualParts(int* arr, int arrSize, int* returnSize) {
	*returnSize = 2;
	long long a = 0, b = 0, c = 0;
	int* result = (int*)malloc(sizeof(int) * (*returnSize));
	if (result) {
		memset(result, -1, *returnSize);
	}



	//找到第一个非0数值
	int start = 0;
	for (start; start < arrSize ; start++) {
		if (arr[start]) {
			break;
		}
	}
	if (start == arrSize) {
		result[0] = 0;
		result[1] = start - 1;
		return result;
	}

	int number = 0;
	for (int i = start; i < arrSize - 2; i++) {
		number++;
		a = i;
		b = a + 1;

		for (b; b < arrSize - 1; b++) {
			if (arr[b]) {
				break;
			}
		}
		int j;
		for (j = 0; j < number && (b + j ) < arrSize; j++) {
			if (arr[j+start] != arr[b + j ]) {
				break;
			}
		}

		if (j == number) {
			c = b + number ;
			for (c; c < arrSize; c++) {
				if (arr[c]) {
					break;
				}
			}
			int k;
			for (k = 0; k < number && (c + k ) < arrSize; k++) {
				if (arr[k + start] != arr[c + k ]) {
					break;
				}
			}
			if (k == number && (c + k ) == arrSize ) {
				result[0] = a;
				result[1] = b + number;
				return result;
			}
		}
	}
	result[0] = -1;
	result[1] = -1;
	return result;
}

void code_927() {
	int arr[10] = { 1,1,1,1,1,1,0,1,1,1 };
	int arrSize = 10;
	int returnSize = 0;
	int* result = threeEqualParts(arr, arrSize, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", result[i]);
	}

}

/*
* 解题思路：
* 找出第一个区间首次出现1的位置，记为start
*	循环假设第一个区间有number个二进制
*	找出第二个区间首次出现1的位置
*		找出第三个区间首次出现1的位置
*			如果三个区间每一位二进制完全相等，返回result
* 
* 例如：0，1，0，1，1
* 第一个区间：起止位置2，number= 1，结束位置1；
* 第二个区间，起始位置3，number= 1，结束位置3；
* 第三个区间，起始位置4，number= 1，结束位置4；
* 返回[2,3]
*/