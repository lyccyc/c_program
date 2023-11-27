#include <stdio.h>

int isSafe(int n,int maze[n][n], int x, int y) {
    // 確保(x, y)在陣列範圍內且不是障礙物
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0);
}

int solve(int n,int maze[n][n], int x, int y) {
    // 如果到達終點，返回true
    if (x == n - 1 && y == n - 1) {
        return 0;
    }

    // 標記當前位置為已訪問
    maze[x][y] = 1;

    // 從當前位置向四個方向嘗試
    if (isSafe(n,maze, x + 1, y) && solve(n,maze, x + 1, y)) {
        return 0; // 向下移動
    }
    else if (isSafe(n,maze, x, y + 1) && solve(n,maze, x, y + 1)) {
        return 0; // 向右移動
    }
    else if (isSafe(n,maze, x - 1, y) && solve(n,maze, x - 1, y)) {
        return 0; // 向上移動
    }
    else if (isSafe(n,maze, x, y - 1) && solve(n ,maze, x, y - 1)) {
        return 0; // 向左移動
    }

    // 如果無法移動，標記為未訪問並返回false
    maze[x][y] = 0;
    return 1;
}

int Maze(int n,int maze[n][n]) {
    return solve(n,maze, 0, 0);
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

    if (Maze(n,maze)) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}
