#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <pthread.h>

#define MAGIC '7'
#define CONVERT _IO(MAGIC, 0)
#define CREATE _IO(MAGIC, 1)
#define SWITCH _IO(MAGIC, 2)
#define FLSALLOC _IO(MAGIC, 3)
#define FLSSET _IO(MAGIC, 4)
#define FLSGET _IO(MAGIC, 5)
#define FLSFREE _IO(MAGIC, 6)
#define STACK_SIZE (4096*2)

typedef void (*entry_point)(void *param);

struct ioctl_params {
    long pos;
    long long value;
    void *args;
    unsigned long sp;
    unsigned long bp;
    entry_point user_func;
    int fiber_id;
};

void *convertThreadToFiber(void);

void *createFiber(size_t, entry_point, void *);

void switchToFiber(int);

long long flsGet(long);

bool flsFree(long);

long flsAlloc(void);

void flsSet(long, long long);

int open_device(void);

