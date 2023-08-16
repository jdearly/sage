#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN_BUFFER_SIZE 1024
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define gb_front(buf) ((buf)->cursor)
#define gb_back(buf)  ((buf)->size - (buf)->gap_end)
#define gb_used(buf)  (gb_front(buf) + gb_back(buf))

typedef struct gap_buf {
  char* buffer;
  size_t size;
  size_t cursor;
  size_t gap_end;
} gap_buf;

gap_buf* create_buffer(size_t size);
bool insert(gap_buf* buf, char c);
char* extract_text(gap_buf* buf);
void free_buf(gap_buf* buf);
void print(gap_buf* buf);

