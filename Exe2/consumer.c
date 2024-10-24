#include "shared.h"

int main() {
    // Open the shared file
    FILE *file = fopen(SHARED_FILE, "r");
    if (!file) {
        perror("Failed to open the file");
        exit(1);
    }

    // Initialize semaphores
    sem_t *sem_empty = sem_open(SEM_EMPTY, O_CREAT, 0666, 1);
    sem_t *sem_full = sem_open(SEM_FULL, O_CREAT, 0666, 0);

    if (sem_empty == SEM_FAILED || sem_full == SEM_FAILED) {
        perror("Failed to open semaphores");
        exit(1);
    }

    int item;
    while (1) {
        sem_wait(sem_full);  // Wait if there's no item to consume

        // Read and consume the item from the file
        fscanf(file, "%d", &item);
        printf("Consumer consumed item: %d\n", item);

        sem_post(sem_empty);  // Signal that the buffer is empty

        sleep(2);  // Simulate consumption time
    }

    // Clean up
    sem_close(sem_empty);
    sem_close(sem_full);
    fclose(file);

    return 0;
}
