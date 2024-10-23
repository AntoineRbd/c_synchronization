CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11
SRC = main.c src/write_sem.c
TARGET = main

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)