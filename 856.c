/*
* 给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串。
输入： "(())"
输出： 2

输入： "()()"
输出： 2

输入： "(()(()))"
输出： 6

* @Author	:	xiefei
* @Date		:	2022-10-09
*/

#include "main.h"

int scoreOfParentheses(char* s) {
	int index = 0;
	int result = 0;
	char* temp = (char*)malloc(sizeof(char) * strlen(s));
	int number = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '(') {
			if (number) {
				result += pow(2, index -1);
				index -= number;
				number = 0;
			}
			temp[index++] = s[i];
		}
		else {
			number++;
		}
	}
	result += pow(2, number - 1);
	return result;
}

void code_856() {
	char* s = "()()()";
	/*(()) ((()))*/
	int result = scoreOfParentheses(s);
	printf("result = %d\n", result);
}

/*
* 解题思路
* 拆解括号：
* 例如 (()(())) ， 可以拆解成(()) + ((())) = 2 + 4 = 6
*/