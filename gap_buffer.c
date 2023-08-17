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

bool insert(gap_buf* buf, char c)
{
  buf->buffer[buf->cursor++] = c;
  return false;
}

char* extract_text(gap_buf* buf)
{
  char* text = malloc(gb_used(buf) + 1);
  if (!text) return NULL;

  strncpy(text, buf->buffer, buf->cursor);
  strncpy(text + buf->cursor, buf->buffer + buf->gap_end, gb_back(buf));
  text[gb_used(buf)] = '\0';
  return text;
}

void free_buf(gap_buf* buf)
{
  if (!buf) {
    return;
  }
  free(buf->buffer);
  free(buf);
}

void print(gap_buf* buf) {
  char* text = extract_text(buf);
  printf("%s\n", text);
  free(text);
}


