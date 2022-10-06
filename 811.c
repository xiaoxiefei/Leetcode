/*
* 网站域名 "discuss.leetcode.com" 由多个子域名组成。顶级域名为 "com" ，二级域名为 "leetcode.com" ，最低一级为 "discuss.leetcode.com" 。当访问域名 "discuss.leetcode.com" 时，同时也会隐式访问其父域名 "leetcode.com" 以及 "com" 。

计数配对域名 是遵循 "rep d1.d2.d3" 或 "rep d1.d2" 格式的一个域名表示，其中 rep 表示访问域名的次数，d1.d2.d3 为域名本身。

例如，"9001 discuss.leetcode.com" 就是一个 计数配对域名 ，表示 discuss.leetcode.com 被访问了 9001 次。
给你一个 计数配对域名 组成的数组 cpdomains ，解析得到输入中每个子域名对应的 计数配对域名 ，并以数组形式返回。可以按 任意顺序 返回答案。

*
* @ Author	:	xiefei
* @Date		:	2022-10-05

*/

#include "main.h"

char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize) {
	(*returnSize) = 0;

	//访问次数
	int index[100];
	for (int i = 0; i < 100; i++) {
		index[i] = 0;
	}
	//返回二维字符串
	char** result = (char**)malloc(sizeof(char*) * (cpdomainsSize * 3));
	if (result) {
		for (int i = 0; i < cpdomainsSize * 3; i++) {
			result[i] = (char*)malloc(sizeof(char) * 100);
			memset(result[i], 0, sizeof(char) * 99);
			result[i][99] = '\0';
		}
	}

	for (int i = 0; i < cpdomainsSize; i++) {
		int sum = 0;
		int j;
		for (j = 0; j < strlen(cpdomains[i]); j++) {
			if (cpdomains[i][j] != ' ') {
				sum = sum * 10 + (int)cpdomains[i][j] - 48;
			}
			else {
				j++;
				break;
			}
		}

		char cptemp[100] = "";
		int cptemp_number = 0;
		int w = j;

		j = strlen(cpdomains[i] ) - 1;
		for (j;  j >= w; j--) {
			if (cpdomains[i][j] != '.') {
				cptemp[cptemp_number++] = cpdomains[i][j];
			}
			else {
				cptemp[cptemp_number] = '\0';
				int flag = 0;

				//cptemp
				for (int m = 0; m < *returnSize; m++) {
					if (strcmp(result[m], cptemp) == 0) {
						flag = 1;
						index[m] += sum;
						break;
					}
				}
				if (!flag) {
					strcpy_s(result[*returnSize], cptemp_number+1, cptemp);
					index[(*returnSize)++] = sum;
				}
				cptemp[cptemp_number++] = '.';
			}
		}

		cptemp[cptemp_number] = '\0';

		int flag = 0;
		//cptemp
		flag = 0;
		for (int m = 0; m < *returnSize; m++) {
			if (strcmp(result[m], cptemp) == 0) {
				flag = 1;
				index[m] += sum;
				break;
			}
		}
		if (!flag) {
			strcpy_s(result[*returnSize], cptemp_number+1, cptemp);
			index[(*returnSize)++] = sum;
		}
		cptemp_number = 0;
	}


	for (int i = 0; i < *returnSize; i++) {
	}

	for (int i = 0; i < *returnSize; i++) {
		char temp[100] = "";
		int k = strlen(result[i]);
		result[i][k++] = ' ';
		char number[100] = "";
		while (index[i]) {
			result[i][k++] = (char)(index[i] % 10) + '0';
			index[i] /= 10;
		}
		result[i][k] = '\0';
		strcpy_s(temp, k+1, result[i]);
		k--;
		for (int j = 0; k>=0; j++,k--) {
			result[i][j] = temp[k];
		}

	}

	return result;
}

void code_811() {
	char* cpdomains[] = { {"900 google.mail.com"}, {"50 yahoo.com"}, {"1 intel.mail.com"}, {"5 wiki.org"} };
	int cpdomainsSize = sizeof(cpdomains) / sizeof(cpdomains[0]);
	int returnSize = 0;
	char** result;
	result = subdomainVisits(cpdomains, cpdomainsSize, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%s  \n", result[i]);
	}
	//printf("len = %d\n", cpdomainsSize);
}

/*
* 解题思路：
* 创建一个键值对
* 遍历域名
*	如果在哈希表里存在，number相加
*	如果在哈希表里不存在，加入到哈希表中
*/