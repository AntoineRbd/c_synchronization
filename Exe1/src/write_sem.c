#include "write_sem.h"


// Global variables
pthread_mutex_t mutex;
sem_t north_queue;
sem_t south_queue;

int north_count = 0;
int south_count = 0;

void *car_from_north() {
    // Wait if there are cars from the south crossing
    pthread_mutex_lock(&mutex);
    north_count++;
    if (north_count == 1) {
        sem_wait(&south_queue);  // Block cars from the south
    }
    pthread_mutex_unlock(&mutex);

    // Cross the bridge
    printf("Car from North is crossing the bridge.\n");
    sleep(1);  // Simulate crossing time

    // Leave the bridge
    pthread_mutex_lock(&mutex);
    north_count--;
    if (north_count == 0) {
        sem_post(&south_queue);  // Allow cars from the south to cross
    }
    pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);
}

void *car_from_south() {
    // Wait if there are cars from the north crossing
    pthread_mutex_lock(&mutex);
    south_count++;
    if (south_count == 1) {
        sem_wait(&north_queue);  // Block cars from the north
    }
    pthread_mutex_unlock(&mutex);

    // Cross the bridge
    printf("Car from South is crossing the bridge.\n");
    sleep(1);  // Simulate crossing time

    // Leave the bridge
    pthread_mutex_lock(&mutex);
    south_count--;
    if (south_count == 0) {
        sem_post(&north_queue);  // Allow cars from the north to cross
    }
    pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);
}