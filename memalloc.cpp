#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>

typedef char ALIGN[16];

union header {
    struct header_t {
        size_t size;
        unsigned is_free;
        struct header_t *next;
    } s;
    ALIGN stub;
};

typedef union header header_t;

header_t *head, *tail;

pthread_mutex_t global_malloc_lock;

void *malloc(size_t size) {
    size_t total_size;
    void *block;
    header_t *header;
}
