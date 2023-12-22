int main() {
  init();
  char str = s1;
  char* key = s2;
  int count=0;
  int keyLength=strlen(key);
  while (*str) {
    if (strncmp(str, key, keyLength) == 0) {
      count++;
      str ++;
    }
    else {
      str++;
    }
  }
  printf("%d", count);
  return 0;
}