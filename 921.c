/**********************************************************************************
* Description:
*只有满足下面几点之一，括号字符串才是有效的：
* 
*它是一个空字符串，或者
*它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
*它可以被写作 (A)，其中 A 是有效字符串。
*给定一个括号字符串 s ，移动N次，你就可以在字符串的任何位置插入一个括号。
* 
*例如，如果 s = "()))" ，你可以插入一个开始括号为 "(()))" 或结束括号为 "())))" 。
*返回 为使结果字符串 s 有效而必须添加的最少括号数。
*
***********************************************************************************
* 
* @Autor	:	xiefei
* @Data		:	2022-10-04

**********************************************************************************/

#include "main.h"

int minAddToMakeValid(char* s) {
	int left_number = 0;
	int result = 0;
	int len = strlen(s);

	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			left_number++;
			continue;
		}
		else if (s[i] == ')') {
			if (left_number) {
				left_number--;
			}
			else {
				result++;
			}
			continue;
		}
		else {
			continue;
		}
	}

	if (left_number) {
		result += left_number;
	}

	return result;
}

void code_921() {
	char* s = "()))";
	int result = minAddToMakeValid(s);
	printf("result = %d\n", result);
}

/*
*解题思路：
* 返回结果：result，所括号数量：left_number
* 1.遍历字符串
*	（1）遇到开始括号，left_number++
*	（2）遇到结束括号
*		左括号数量大于0，left_number--
*		左括号数量等于0，result++
* 2.如果左括号数量大于0，result += left_number
* 3.return result
*/