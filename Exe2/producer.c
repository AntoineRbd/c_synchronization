#include "shared.h"

int main() {
    // Open the shared file
    FILE *file = fopen(SHARED_FILE, "w");
    if (!file) {
        perror("Failed to open the file");
        exit(1);
    }

    // Initialize semaphores
    sem_t *sem_empty = sem_open(SEM_EMPTY, O_CREAT, 0666, 1);  // Initially, the buffer is empty
    sem_t *sem_full = sem_open(SEM_FULL, O_CREAT, 0666, 0);    // Initially, no item to consume

    if (sem_empty == SEM_FAILED || sem_full == SEM_FAILED) {
        perror("Failed to open semaphores");
        exit(1);
    }

    int item = 1;
    while (1) {
        sem_wait(sem_empty);  // Wait if the buffer is not empty
        
        // Produce an item and write to the file
        fprintf(file, "%d\n", item);
        fflush(file);  // Make sure the data is written immediately
        printf("Producer produced item: %d\n", item);
        item++;

        sem_post(sem_full);  // Signal that the buffer is now full

        sleep(1);  // Simulate production time
    }

    // Clean up
    sem_close(sem_empty);
    sem_close(sem_full);
    fclose(file);

    return 0;
}
