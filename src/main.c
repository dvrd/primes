#include "lib.c"
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc > 1) {
    int target = stoi(argv[1]);

    int size = 0;
    int *buf = primes(target, &size);

    printf("-------------\n");
    for (int i = 0; i < size; i++) {
      printf("[%d] %d\n", i + 1, buf[i]);
    }
    free(buf);
  } else {
    printf("Missing range to calculate primes\n");
    return 1;
  }

  return 0;
}
