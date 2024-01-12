#include <stdio.h>

// 走過的路徑用-1表示
#define VISITED -1

int isSafe(int n, int maze[n][n], int x, int y) {
    // 確保(x, y)在陣列範圍內且不是障礙物
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0);
}

int solveMazeUtil(int n, int maze[n][n], int x, int y) {
    // 到終點
    if (x == n - 1 && y == n - 1) {
        return 1;
    }

    // 標記當前位置為已訪問
    maze[x][y] = VISITED;

    // 四個方向
    if (isSafe(n, maze, x + 1, y) && solveMazeUtil(n, maze, x + 1, y)) {
        return 1; // 向下移動
    }
    else if (isSafe(n, maze, x, y + 1) && solveMazeUtil(n, maze, x, y + 1)) {
        return 1; // 向右移動
    }
    else if (isSafe(n, maze,  x - 1, y) && solveMazeUtil(n, maze, x - 1, y)) {
        return 1; // 向上移動
    }
    else if (isSafe(n, maze,  x, y - 1) && solveMazeUtil(n, maze, x, y - 1)) {
        return 1; // 向左移動
    }

    maze[x][y] = 0;
    return 0;
}

int solveMaze(int n, int maze[n][n]) {
    return solveMazeUtil(n, maze, 0, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    int maze[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    if (solveMaze(n,maze)) {
        printf("Yes\n");
    } 
    else {
        printf("No\n");
    }

    return 0;
}

