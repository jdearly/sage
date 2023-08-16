#include <stdlib.h>

typedef struct gap_buf {
  char* buffer;
  size_t size;
  size_t cursor;
  size_t gap_end;
} gap_buf;
