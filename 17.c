/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

#include "main.h"

char* temp ;
int* number;

void fun_17(char ** keyboard, char** result,int len, int index, int *returnSize) {

	//结束条件
	if (index == len) {
		memcpy(result[*returnSize], temp, len+1);
		(*returnSize)++;
		return;
	}
	int letterlen = strlen(keyboard[number[index]]);
	for (int i=0; i < letterlen; i++) {
		temp[index] = keyboard[number[index]][i];
		fun_17(keyboard, result, len, index + 1, returnSize);
	}
}

char** letterCombinations(char* digits, int* returnSize) {
	//定义一个键盘数组
	const char* keyboard[] = { "abc\0", "def\0", "ghi\0", "jkl\0", "mno\0", "pqrs\0", "tuv\0", "wxyz\0" };

	//输入的数字个数
	int len = strlen(digits);
	if (!len) {
		*returnSize = 0;
		return "";
	}

	temp = malloc(sizeof(char) * (len+1));
	if (!temp) {
		return "";
	}
	else {
		temp[len] = '\0';
	}

	//字符串转换成数字
	number = malloc(sizeof(int) * len);
	if (!number) {
		return "";
	}
	else {
		memset(number, 0, len);
		*returnSize = 1;
		for (int i = 0; i < len; i++) {
			*(number + i) = (int)digits[i] - 50;
			*returnSize *= strlen(keyboard[*(number + i)]);
		}
	}


	//申请一个要返回的内存
	char** result = (char**)malloc(sizeof(char*) * (*returnSize));
	if (result) {
		for (int i = 0; i < *returnSize; i++) {
			*(result + i) = (char*)malloc(sizeof(char) * (strlen(digits) + 1));
			if (*(result + i)) {
				memset(*(result + i), 0, sizeof(char) * strlen(digits));
				(*(result + i))[sizeof(char) * strlen(digits)] = '\0';
			}
		}
	}


	*returnSize = 0;

	//递归所有可能
	fun_17(keyboard, result, len, 0, returnSize);
	return result;
	return "";
}

void code_17() {
	char* digits = "23";
	int size = 0;
	int* returnSize = &size;
	char** result = letterCombinations(digits, returnSize);
	for (int i = 0; i < *returnSize; i++) {
		printf("%s\n", result[i]);
	}
}