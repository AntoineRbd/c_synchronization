#include "shared.h"

int main() {
    FILE *file = fopen(SHARED_FILE, "w");
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

    int item = 1;
    while (1) {
        sem_wait(sem_empty);
        
        fprintf(file, "%d\n", item);
        fflush(file);
        printf("Producer produced item: %d\n", item);
        item++;

        sem_post(sem_full);
        sleep(1);
    }

    sem_close(sem_empty);
    sem_close(sem_full);
    fclose(file);

    return 0;
}
