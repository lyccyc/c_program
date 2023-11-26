#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define EMPTY_QUEUE (-1)

int arr[MAX_SIZE];
int front = EMPTY_QUEUE;
int rear = EMPTY_QUEUE;

// 初始化循環隊列
void initializeQueue() {
    front = EMPTY_QUEUE;
    rear = EMPTY_QUEUE;
}

// 檢查循環隊列是否為空
bool isEmpty() {
    return front == EMPTY_QUEUE;
}

// 入隊
void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {
        // 隊列已滿
        printf("Queue is full.\n");
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
    }
}

// 出隊
int dequeue() {
    int value = -1;
    if (isEmpty()) {
        // 隊列為空
        printf("Queue is empty.\n");
    } else {
        value = arr[front];
        if (front == rear) {
            // 隊列中只有一個元素
            initializeQueue();
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
    return value;
}

// 約瑟夫斯問題求解
int Survivor(int n, int k) {
    initializeQueue();

    // 初始化隊列，將1到n的數字入隊
    for (int i = 1; i <= n; i++) {
        enqueue(i);
    }

    while (!isEmpty()) {
        // 進行k-1次出隊再入隊操作
        for (int i = 0; i < k - 1; i++) {
            int frontValue = dequeue();
            enqueue(frontValue);
        }
        // 第k次出隊，表示被殺死
        int killed = dequeue();
        if (isEmpty()) {
            // 如果隊列中只剩一個人，則該人為倖存者
            return killed;
        }
    }
    return -1; // 不應該達到這一點
}

int main() {
    int n, k;

    while (1) {
        // 讀取輸入
        scanf("%d %d", &n, &k);

        // 檢查結束條件
        if (n == 0 && k == 0) {
            break;
        }

        // 計算結果並輸出
        int result = Survivor(n, k);
        printf("%d", result);
    }

    return 0;
}
