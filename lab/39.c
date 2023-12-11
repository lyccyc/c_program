int main() {
  init();
  char *str = s;
  int sum;
  while(*str){
    int num=strtol(str, &str,10);
    sum+=num;
    str++;
  }
  printf("%d", sum);
  return 0;
}