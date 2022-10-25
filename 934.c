/*
给你一个大小为 n x n 的二元矩阵 grid ，其中 1 表示陆地，0 表示水域。

岛 是由四面相连的 1 形成的一个最大组，即不会与非组内的任何其他 1 相连。grid 中 恰好存在两座岛 。

你可以将任意数量的 0 变为 1 ，以使两座岛连接起来，变成 一座岛 。

返回必须翻转的 0 的最小数目。

输入：grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
输出：1

* @Author	:	xiefei
* @Date		:	2022-10-25
*/
#include "main.h"

typedef struct {
    int x;
    int y;
}Point;

Point island1[10000], island2[10000];
int index1 = 0, index2 = 0;

void IsNeighbor(int** grid, int m, int n, int gridSize) {
    if (m < 0 || n < 0 || m == gridSize || n == gridSize || grid[m][n] == 0)return;
    if (grid[m][n] == 1) {
        island1[index1].x = m;
        island1[index1].y = n;
        grid[m][n] = 0;
        index1++;
    }
    IsNeighbor(grid, m, n + 1, gridSize);
    IsNeighbor(grid, m + 1, n, gridSize);
    IsNeighbor(grid, m, n - 1, gridSize);
    IsNeighbor(grid, m - 1, n, gridSize);

    return;
}

int shortestBridge(int** grid, int gridSize, int* gridColSize) {
    index1 = 0, index2 = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j] == 1) {
                IsNeighbor(grid, i, j, gridSize);
                break;
            }
        }
        if (index1)break;
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {

            if (grid[i][j] == 1) {
                island2[index2].x = i;
                island2[index2++].y = j;
            }
        }
    }

    int min = 300;
    for (int i = 0; i < index1; i++) {
        for (int j = 0; j < index2; j++) {
            int distance = abs(island1[i].x - island2[j].x) +
                abs(island1[i].y - island2[j].y) - 1;

            if (distance < min) {
                min = distance;
            }
        }
    }

    return min;
}
void code_934() {
    int** grid = (int**)malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++) {
        *(grid+i) = (int*)malloc(sizeof(int) * 5);
    }
    int test[5][5] = {
        {0,0,1,0,1},
        {0,1,1,0,1},
        {0,1,0,0,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] = test[i][j];
        }
    }
    int gridSize = 5;
    int result = shortestBridge(grid, gridSize, &gridSize);
    printf("result = %d\n", result);
}
/*
* 解题思路:
* 深度优先遍历，先找到第一个岛屿，然后剩下的1是第二个岛屿
* 遍历两个岛屿，两个岛屿中的x,y元素之差最小的数就是答案
*/