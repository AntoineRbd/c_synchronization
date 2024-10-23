#ifndef WRITE_SEMAPHORE
#define WRITE_SEMAPHORE

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define NUM_CARS_NORTH 5
#define NUM_CARS_SOUTH 5

// Global variables
extern pthread_mutex_t mutex;
extern sem_t north_queue;
extern sem_t south_queue;
extern int north_count;
extern int south_count;


void *car_from_north();
void *car_from_south();

#endif