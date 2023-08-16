#include <stdlib.h>

#define MIN_BUFFER_SIZE 1024
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct gap_buf {
  char* buffer;
  size_t size;
  size_t cursor;
  size_t gap_end;
} gap_buf;

gap_buf* create_buffer(size_t size)
{
  gap_buf* buf = malloc(sizeof *buf);
  if (!buf) {
    return NULL;
  }
  size = MAX(size, MIN_BUFFER_SIZE);
  buf->buffer = malloc(size);
  if (!buf->buffer) {
    free(buf);
    return NULL;
  }
  buf->size = size;
  buf->gap_end = size;
  buf->cursor = 0;
  return buf;
}
