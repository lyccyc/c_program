#include <stdio.h>
int front = -1, rear = -1;

// Check if the queue is full
int isFull(int n) {
  if ((front == rear + 1) || (front == 0 && rear == n - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
int enQueue(int arr[],int n,int index,int element) {
  if (isFull(n))
    return 0;
  else {
    if (front == -1) 
      front = 0;
    //rear = (rear + 1) % SIZE;
    arr[index] = element;
  }
}

// Removing an element
int deQueue(int n,int index,int arr[]) {
  int element;
  if (isEmpty()) {
    return 0;
  } 
  else {
    element = arr[index];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 

    else {
      front = (front + 1) % n;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

// Display the queue
int display(int n,int arr[]) {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d\n ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % n) {
      printf("%d ", arr[i]);
    }
    printf("%d ", arr[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
    int n, k;
    int front=n-1;
    int rear=n-1;

    
    while () {
        // 輸入人數和步長
        scanf("%d %d", &n, &k);
        int num[n];
        // 檢查是否結束
        if (n == 0 && k == 0) {
            break;
        }
        for(int i=0;i<n;i++)
          num[i]=i+1;

        for(int i=0;i<n;i++){
          int item1=num[i]+k-1; //2
          deQueue(n,item1,num);
          int item2=item1+k;//4
          enQueue(num,n,item1,item2);
        }

        display(n,num);
        break;
    }

    return 0;
}

//index: 0 1 2 3 4
//numbe: 1 2 3 4 5
//1: 1 4 3 5 dead:2
//2: 1 3 4   daed:5
//3: 1 4     dead:3
//4: 4       dead:1