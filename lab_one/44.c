#include <stdio.h>

#define SIZE 9

char board[SIZE][SIZE];

int is_valid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

int dfs(int x, int y, char color, int *territory, int *stones, char visited[SIZE][SIZE]) {
    if (!is_valid(x, y) || visited[x][y] || board[x][y] == 'b' || board[x][y] == 'w') {
        return 0;
    }

    visited[x][y] = 1;

    if (board[x][y] == '.') {
        (*territory)++;
    } else if (board[x][y] == 'X') {
        (*stones)++;
    } else if (board[x][y] == 'O') {
        (*stones)++;
    }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for (int i = 0; i < 4; ++i) {
        dfs(x + dx[i], y + dy[i], color, territory, stones, visited);
    }
}

void count_territory_and_stones(int *black_territory, int *white_territory, int *black_stones, int *white_stones) {
    char visited[SIZE][SIZE] = {0};

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == '.' && !visited[i][j]) {
                int territory = 0, stones = 0;
                dfs(i, j, board[i][j], &territory, &stones, visited);

                if (board[i][j] == 'X') {
                    *black_territory += territory;
                    *black_stones += stones;
                } else if (board[i][j] == 'O') {
                    *white_territory += territory;
                    *white_stones += stones;
                }
            }
        }
    }
}

int main() {
    int num;
    scanf("%d",&num);
    
    while(num--){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%c", &board[i][j]);
            }
        }
        int black_territory = 0, white_territory = 0, black_stones = 0, white_stones = 0;

        count_territory_and_stones(&black_territory, &white_territory, &black_stones, &white_stones);

        int black_total = black_territory + black_stones;
        int white_total = white_territory + white_stones;

        printf("Black %d White %d", black_total,white_total);
    }
    return 0;
}
