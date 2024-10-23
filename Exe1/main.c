#include "include/write_sem.h"
#include "include/display.h"


int main(void)
{
    start_exe();

    pthread_t north[NUM_CARS_NORTH], south[NUM_CARS_SOUTH];

    // Initialize the mutex and semaphores
    pthread_mutex_init(&mutex, NULL);
    sem_init(&north_queue, 0, 1);  // Initially, allow cars from the north to pass
    sem_init(&south_queue, 0, 1);

    // Create threads for cars from the north and south
    for (int i = 0; i < NUM_CARS_NORTH; i++) {
        pthread_create(&north[i], NULL, car_from_north, NULL);
    }
    for (int i = 0; i < NUM_CARS_SOUTH; i++) {
        pthread_create(&south[i], NULL, car_from_south, NULL);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_CARS_NORTH; i++) {
        pthread_join(north[i], NULL);
    }
    for (int i = 0; i < NUM_CARS_SOUTH; i++) {
        pthread_join(south[i], NULL);
    }

    // Destroy the mutex and semaphores
    pthread_mutex_destroy(&mutex);
    sem_destroy(&north_queue);
    sem_destroy(&south_queue);

    end_exe();

    return 0;
}