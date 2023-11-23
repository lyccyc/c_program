#include <stdio.h>

#define MAX_BLOCKS 25

int blocks[MAX_BLOCKS][MAX_BLOCKS];
int position[MAX_BLOCKS];

void moveOnto(int a, int b) {
    for (int i = position[a] + 1; i < MAX_BLOCKS && blocks[a][i] != -1; i++) {
        int block = blocks[a][i];
        position[block] = block;
        blocks[block][0] = block;
    }
    blocks[a][1] = -1;
    position[a] = position[b] + 1;
    blocks[b][++blocks[b][0]] = a;
}

void moveOver(int a, int b) {
    for (int i = position[a] + 1; i < MAX_BLOCKS && blocks[a][i] != -1; i++) {
        int block = blocks[a][i];
        position[block] = block;
        blocks[block][0] = block;
    }
    blocks[a][1] = -1;
    position[a] = blocks[b][0];
    blocks[b][++blocks[b][0]] = a;
}

void pileOnto(int a, int b) {
    for (int i = position[b] + 1; i < MAX_BLOCKS && blocks[b][i] != -1; i++) {
        int block = blocks[b][i];
        position[block] = block;
        blocks[block][0] = block;
    }

    int height = blocks[b][0];
    blocks[b][0] += blocks[a][0];
    for (int i = 1; i <= blocks[a][0]; i++) {
        blocks[b][height + i] = blocks[a][i];
        position[blocks[a][i]] = b;
    }

    blocks[a][0] = 1;
    blocks[a][1] = -1;
}

void pileOver(int a, int b) {
    int height = blocks[b][0];
    blocks[b][0] += blocks[a][0];
    for (int i = 1; i <= blocks[a][0]; i++) {
        blocks[b][height + i] = blocks[a][i];
        position[blocks[a][i]] = b;
    }

    blocks[a][0] = 1;
    blocks[a][1] = -1;
}

void printState(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 1; j <= blocks[i][0]; j++) {
            if(blocks[i][j]==-1)
                break;
            else 
                printf(" %d", blocks[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, a, b;
    char command1[5],command2[5];

    scanf("%d", &n);

    // 初始化
    for (int i = 0; i < n; i++) {
        blocks[i][0] = 1;
        blocks[i][1] = i;
        position[i] = i;
    }

    while (1) {
        scanf("%s", command1);

        if (command1[0] == 'q') {
            break;
        }

        scanf("%d %s %d", &a, command2, &b);

        if (a == b || position[a] == position[b]) {
            // 忽略非法指令
            continue;
        }

        if (command1[0] == 'm') {
            if (command2[1] == 'n') {
                moveOnto(a, b);
            } else {
                moveOver(a, b);
            }
        } else {
            if (command2[1] == 'n') {
                pileOnto(a, b);
            } else {
                pileOver(a, b);
            }
        }
    }

    // 輸出最終狀態
    printState(n);

    return 0;
}
