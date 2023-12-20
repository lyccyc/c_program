#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

// 迷宮地圖
int maze[SIZE][SIZE] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
    { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
    { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
    { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
    { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

// 定義方向
typedef struct {
    int row;
    int col;
} Direction;

Direction directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 上、下、左、右

// 定義座標點
typedef struct {
    int row;
    int col;
} Point;

// 堆疊節點
typedef struct StackNode {
    Point point;
    struct StackNode* next;
} StackNode;

// 堆疊結構
typedef struct {
    StackNode* top;
} Stack;

// 初始化堆疊
void initStack(Stack* stack) {
    stack->top = -1;
}

// 判斷堆疊是否為空
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 入堆疊
void push(Stack* stack, Point point) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->point = point;
    newNode->next = stack->top;
    stack->top = newNode;
}

// 出堆疊
Point pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    Point point = stack->top->point;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return point;
}

// 走迷宮的堆疊版函數
int solveMazeStack() {
    Stack stack;
    initStack(&stack);

    Point start = {1, 0};
    push(&stack, start);

    while (!isEmpty(&stack)) {
        Point current = pop(&stack);

        int row = current.row;
        int col = current.col;

        // 到達終點
        if (row == SIZE - 1 && col == SIZE - 1) {
            return 1;  // 表示找到通路
        }

        // 標記當前位置已經走過
        maze[row][col] = 1;

        // 嘗試往四個方向走
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i].row;
            int newCol = col + directions[i].col;

            // 判斷是否超出邊界或是遇到障礙物
            if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE && maze[newRow][newCol] == 0) {
                Point next = {newRow, newCol};
                push(&stack, next);
            }
        }
    }

    return 0;  // 表示無法找到通路
}

int main() {

    printf("\nStack Solution:\n");
    if (solveMazeStack()) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}

