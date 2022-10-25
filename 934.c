/*
����һ����СΪ n x n �Ķ�Ԫ���� grid ������ 1 ��ʾ½�أ�0 ��ʾˮ��

�� �������������� 1 �γɵ�һ������飬������������ڵ��κ����� 1 ������grid �� ǡ�ô��������� ��

����Խ����������� 0 ��Ϊ 1 ����ʹ������������������� һ���� ��

���ر��뷭ת�� 0 ����С��Ŀ��

���룺grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
�����1

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
* ����˼·:
* ������ȱ��������ҵ���һ�����죬Ȼ��ʣ�µ�1�ǵڶ�������
* �����������죬���������е�x,yԪ��֮����С�������Ǵ�
*/