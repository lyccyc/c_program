#include <stdio.h>

#define BOARD_SIZE 8

// 函数用于检查坐标 (x, y) 是否在棋盘内
int is_valid(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

// 函数用于判断是否可以下相同颜色的棋子
int can_place_piece(int chess[BOARD_SIZE][BOARD_SIZE], int player, int x, int y) {
    if (chess[x][y] != 0) {
        return 0;  // (i, j) 不是空白，无法下子
    }

    int directions[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    for (int d = 0; d < 8; d++) {
        int dx = directions[d][0];
        int dy = directions[d][1];
        int x_ = x + dx;
        int y_ = y + dy;

        while (is_valid(x_, y_) && chess[x_][y_] != 0 && chess[x_][y_] != player) {
            x_ += dx;
            y_ += dy;
        }

        if (is_valid(x_, y_) && chess[x_][y_] == player) {
            return 1;  // (i, j) 可以下相同颜色的棋子
        }
    }

    return 0;  // (i, j) 无法下相同颜色的棋子
}

int main() {

    // 输入棋盘
    int chess[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 2, 0, 0, 0},
        {0, 0, 0, 2, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    int i, j, color;
    // 输入坐标 (i, j)
    printf("请输入坐标 (i, j)：\n");
    scanf("%d %d", &i, &j);

    // 输入颜色 (1表示黑子，2表示白子)
    printf("请输入颜色 (1表示黑子，2表示白子)：\n");
    scanf("%d", &color);

    if (chess[i][j] == 0) {
        printf("(%d, %d) 是空白\n", i, j);
    } else if (chess[i][j] == color) {
        printf("(%d, %d) 是颜色 %d 的棋子\n", i, j, color);
    } else {
        printf("(%d, %d) 是颜色 %d 的棋子\n", i, j, 3 - color);  // 另一种颜色
    }

    if (can_place_piece(chess, color, i, j)) {
        printf("(%d, %d) 可以下相同颜色的棋子\n", i, j);
    } else {
        printf("(%d, %d) 无法下相同颜色的棋子\n", i, j);
    }

    return 0;
}
