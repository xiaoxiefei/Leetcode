/*
*数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
* 
*/

#include "main.h"


//回溯
void create_str(char ** str, char *temp, int n, int *returnSize, int left, int right) {
    static int k = 0;

    if (temp[2 * n - 1] == '(' || temp[2 * n - 1] == ')') {
        strcpy_s(str[*returnSize], 2*n+1, temp);
        (* returnSize)++;
        return;
    }

    if (left < n) {
        temp[k] = '(';
        k++;
        create_str(str, temp, n, returnSize, left+1, right);
        temp[--k] = ' ';
    }

    if (right < left) {
        temp[k] = ')';
        k++;
        create_str(str, temp, n, returnSize, left, right+1);
        temp[--k] = ' ';
    }
    return;
}

char** generateParenthesis(int n, int* returnSize) {
    (*returnSize) = 0;
    char** str = (char**)malloc(sizeof(char*) * (int)pow(2, 2 * (int)n));
    if (str) {
        for (int i = 0; i < pow(2, n * 2); i++) {
            *(str + i) = (char*)malloc(sizeof(char) * (2 * n));
            if (!(*(str + i))) {
                break;
            }
            memset(*(str + i), 0, sizeof(char) * (2 * n));
        }
    }


    char* temp = (char*)malloc(sizeof(char) * (2 * n + 1));
    if (temp) {
        temp[2 * n] = '\0';
    }

    create_str(str, temp, n, returnSize, 0, 0);

    return str;
}

void code_22() {
    int returnSize = -1;
    int n = 3;
    char** ret = generateParenthesis(n, &returnSize);

    for (int i = 0; i < returnSize; i++) {

        printf("ret=%s\n", ret[i]);
    }
}