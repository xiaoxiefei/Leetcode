/************************************
*									*
*			  目前未成功			*
*									*
************************************/

/*
* 782.变为棋盘
一个 n x n 的二维网络 board 仅由 0 和 1 组成 。每次移动，你能任意交换两列或是两行的位置。

返回 将这个矩阵变为  “棋盘”  所需的最小移动次数 。如果不存在可行的变换，输出 -1。

“棋盘” 是指任意一格的上下左右四个方向的值均与本身不同的矩阵

*/
#include <stdio.h>

#define bool int
#define true (int)1
#define false (int)0
#define N 4

int board[4][4] = { {0, 1, 1, 0},{0, 1, 1, 0},{1, 0, 0, 1},{1, 0, 0, 1} };

void print_board();		//打印棋盘

bool is_Can();			//是否有可能变成棋盘

int odd_board();		//奇数棋盘

int even_board();		//偶数棋盘

void row_swap(int** board, int row1, int row2);		//行交换

void col_swap(int** board, int col1, int col2);		//列交换

int movesToChessboard();	//最终返回值




int main() {

	print_board();
	printf("%d", movesToChessboard());

}

int movesToChessboard() {
	if (!is_Can)return -1;
	if (N % 2 == 0)return odd_board();
	else if (N % 2 != 0) {
		return even_board();
	}
}

int odd_board() {
	int ret = 0;
	if (board[0][0] == 1) {
		for (int i = 1; i < N; i++) {
			if (board[0][i] == i % 2)ret++;
			if (board[i][0] == i % 2)ret++;
		}
	}
	else {
		for (int i = 1; i < N; i++) {
			if (board[0][i] != i % 2)ret++;
			if (board[i][0] != i % 2)ret++;
		}
	}
	return ret / 2;
}

int even_board() {
	int sum_0 = 0, sum_1 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0)sum_0++;
			else {
				sum_1++;
			}
		}
	}

	int ret = 0;
	if (sum_0>sum_1) {
		if (board[0][0] != 0) {
			for (int i = 1; i < N; i++) {
				if (board[i][0] == 0) {
					row_swap(board, 0, i);
					ret += 2;
					break;
				}
			}
		}
		for (int i = 1; i < N; i++) {
			if (board[0][i] != i % 2)ret++;
			if (board[i][0] != i % 2)ret++;
		}
		printf("ret = %d\n", ret);
	}
	else {
		if (board[0][0] != 1) {
			for (int i = 1; i < N; i++) {
				if (board[i][0] == 1) {
					row_swap(board, 0, i);
					ret += 2;
				}
			}
		}
		for (int i = 1; i < N; i++) {
			if (board[0][i] == i % 2)ret++;
			if (board[i][0] == i % 2)ret++;
		}
	}
	if (ret % 2 == 1)return ret / 2 +1;
	return -1;
}

void row_swap(int** board, int row1, int row2) {
	for (int i = 0; i < N; i++) {
		int temp = board[row1][i];
		board[row1][i] = board[row2][i];
		board[row2][i] = temp;
	}
}

void col_swap(int** board, int col1, int col2) {
	for (int i = 0; i < N; i++) {
		int temp = board[i][col1];
		board[i][col1] = board[i][col2];
		board[i][col2] = temp;
	}
}

void print_board() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

bool is_Can() {
	int sum_0 = 0, sum_1 = 0;
	int col_0 = 0, col_1 = 0;

	if (N % 2 == 0) {		//偶数棋盘
		for (int i = 0; i < N; i++) {
			sum_0 = 0, sum_1 = 0;
			col_0 = 0, col_1 = 0;
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) {
					sum_0++;
				}
				else {
					sum_1++;
				}
				if (board[j][i] == 0) {
					col_0++;
				}
				else {
					col_1++;
				}
			}
			if (sum_0 != sum_1 || col_0 != col_1) {
				return false;
			}
		}
	}
	else {					//奇数棋盘
		for (int i = 0; i < N; i++) {
			sum_0 = 0, sum_1 = 0;
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) {
					sum_0++;
				}
				else {
					sum_1++;
				}
				if (board[j][i] == 0) {
					col_0++;
				}
				else {
					col_1++;
				}
			}
			if ((sum_0 + 1 != sum_1) && (sum_0 != sum_1 + 1)) {
				return false;
			}
			if ((col_0 + 1 != col_1) && (col_0 != col_1 + 1)) {
				return false;
			}
		
		}
		
	}
	return true;
}