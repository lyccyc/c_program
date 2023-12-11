int main() {
  int *a, *b;
  init(&a, &b);
  int sum;
  int *ptr = a;
  while(ptr != b){
    sum+=*ptr;
    ptr++;
  }
  
  printf("%d", sum);
  return 0;
}

