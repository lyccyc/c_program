#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// 走過的路徑用-1表示
#define VISITED -1

bool isSafe(int maze[MAX_SIZE][MAX_SIZE], int n, int x, int y) {
    // 確保(x, y)在陣列範圍內且不是障礙物
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0);
}

bool solveMazeUtil(int maze[MAX_SIZE][MAX_SIZE], int n, int x, int y) {
    // 到終點
    if (x == n - 1 && y == n - 1) {
        return true;
    }

    // 標記當前位置為已訪問
    maze[x][y] = VISITED;

    // 四個方向
    if (isSafe(maze, n, x + 1, y) && solveMazeUtil(maze, n, x + 1, y)) {
        return true; // 向下移動
    }
    if (isSafe(maze, n, x, y + 1) && solveMazeUtil(maze, n, x, y + 1)) {
        return true; // 向右移動
    }
    if (isSafe(maze, n, x - 1, y) && solveMazeUtil(maze, n, x - 1, y)) {
        return true; // 向上移動
    }
    if (isSafe(maze, n, x, y - 1) && solveMazeUtil(maze, n, x, y - 1)) {
        return true; // 向左移動
    }

    maze[x][y] = 0;
    return false;
}

bool solveMaze(int maze[MAX_SIZE][MAX_SIZE], int n) {
    return solveMazeUtil(maze, n, 0, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    int maze[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    if (solveMaze(maze, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

