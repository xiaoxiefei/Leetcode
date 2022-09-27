/*
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
*/

#define INT_MAX 2147483646
#define INT_MIN (-2147483648)
int myAtoi(char* s) {
    int i = 0;
    int out = 0;
    int pol = 1;
    int len = strlen(s);

    if (len == 0) return 0;

    while (s[i] == ' ') i++;  //删除空格
    if (s[i] == '-') {         //判断正负
        pol = -1;
        i++;
    }
    else if (s[i] == '+') {
        pol = 1;
        i++;
    }
    else {
        pol = 1;
    }

    while (s[i] != '\0') {
        if (s[i] < '0' || s[i]>'9') { //非法字符检查
            i++;
            break;
        }
        if (out > INT_MAX / 10) return (pol > 0 ? INT_MAX : INT_MIN);  //越界判断
        if (out == INT_MAX / 10) {
            if (pol > 0 && s[i] > '7') return INT_MAX;
            else if (pol < 0 && s[i] >= '8') return INT_MIN;
        }
        //下面正常来写应该是out=10*out+(s[i]-'0')，之所以先减去'0',
        //是为了防止10*out+s[i]越界
        out = 10 * out - '0' + s[i];
        //由于本题没有不允许64位的存储数据，所以非法判断可以更加简单
        //可以直接将out定义为long型，直接判断即可
        //if(pol*out>INT_MAX) return INT_MAX;
        //if(pol*out<INT_MIN) return INT_MIN;
        i++;
    }
    out = out * pol;

    return out;
}

void code_8(){
	char* s = " -98784654894462";
	int result = myAtoi(s);
	printf("result = %d\n", result);
}