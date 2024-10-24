#ifndef SHARED
#define SHARED

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

#define SHARED_FILE "shared_data.txt"

// Semaphore names
#define SEM_EMPTY "/sem_empty"
#define SEM_FULL "/sem_full"

#endif