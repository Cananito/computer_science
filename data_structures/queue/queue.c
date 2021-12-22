#include "queue.h"

#include <stdlib.h>

// TODO: Add nullability annotations here and in the header.

struct Queue_r {
  // TODO: Change to an "ArrayList_r" or something for storage.
  void **storage;
  int storage_size;
  int count;
};

Queue_r *Queue_r_new(void) {
  Queue_r *q = malloc(sizeof(Queue_r));
  int storage_size = 4;
  // TODO: Delay allocation until first enqueue?
  q->storage = calloc(storage_size, sizeof(void *));
  q->storage_size = storage_size;
  q->count = 0;
  return q;
}

void Queue_r_free(Queue_r *queue) {
  free(queue->storage);
  free(queue);
}

int Queue_r_count(Queue_r *queue) {
  return queue->count;
}

void *Queue_r_peek(Queue_r *queue) {
  return *(queue->storage + 0);
}

void Queue_r_enqueue(Queue_r *queue, void *element) {
  int current_count = queue->count;
  *(queue->storage + current_count) = element;
  queue->count++;

  // TODO: Increase storage size if needed.
}

Queue_r *Queue_r_dequeue(Queue_r *queue) {
  void *element = *(queue->storage + 0);
  // TODO: Create new storage without the first element.
  queue->count--;

  // TODO: Decrease storage size if needed.

  return element;
}
