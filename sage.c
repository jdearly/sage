#include "gap_buffer.h"

int main()
{
  gap_buf* buf = create_buffer(MIN_BUFFER_SIZE);
  {
    insert(buf, 'f');
    insert(buf, 'o');
    insert(buf, 'o');
    print(buf);
  }

  free_buf(buf);
}
