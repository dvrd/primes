#include <stdlib.h>

int stoi(char *str) {
  int num = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    num = num * 10 + (str[i] - 48);
  }
  return num;
}

int *eliminate_multiples(int x, int *buf, int *buf_len) {
  int *new_buf = malloc(sizeof(int) * *buf_len);
  int idx = 0;
  int current;
  for (int i = 0; i < *buf_len; i++) {
    current = buf[i];
    if (current != x && current % x == 0)
      continue;

    new_buf[idx] = current;
    idx++;
  }
  *buf_len = idx;

  free(buf);

  return new_buf;
}

int *primes(int n, int *size) {
  int *buf = malloc(sizeof(int) * n);

  for (int num = 2; num <= n; num++) {
    buf[*size] = num;
    (*size)++;
  }

  int current = 0;
  int multiple = buf[current];
  while (multiple != 0) {
    buf = eliminate_multiples(multiple, buf, size);
    multiple = buf[++current];
  }

  return buf;
}
