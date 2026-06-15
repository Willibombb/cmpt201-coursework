#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


struct header {
  uint64_t size;
  struct header *next;
};

int main() {

  void *heap_start = sbrk(256);

  if (heap_start == (void *)-1) {
    perror("sbrk failed");
    return 1;
  }



  uint64_t block_size = 128;

  struct header *first_block = (struct header *)heap_start;
  struct header *second_block = (struct header *)((char *)heap_start + block_size);



  first_block->size = block_size;
  first_block->next = NULL;


  second_block->size = block_size;
  second_block->next = first_block;



  char *first_block_data = (char *)first_block + sizeof(struct header);
  char *second_block_data = (char *)second_block + sizeof(struct header);


  size_t data_size = block_size - sizeof(struct header);


  memset(first_block_data, 0, data_size);
  memset(second_block_data, 1, data_size);


  printf("first block:       %p\n", (void *)first_block);
  printf("second block:      %p\n", (void *)second_block);

  printf("first block size:  %lu\n", first_block->size);
  if (first_block->next == NULL) {
    printf("first block next:  (nil)\n");
  } else {
    printf("first block next:  %p\n", (void *)first_block->next);
  }

  printf("second block size: %lu\n", second_block->size);
  printf("second block next: %p\n", (void *)second_block->next);


  for (size_t i = 0; i < data_size; i++) {
    printf("%d\n", first_block_data[i]);
  }


  for (size_t i = 0; i < data_size; i++) {
    printf("%d\n", second_block_data[i]);
  }

  return 0;
}
