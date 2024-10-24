CC = gcc
CFLAGS = -Wall -pthread 
TARGETS = producer consumer 

all: $(TARGETS)

producer: producer.o
	$(CC) $(CFLAGS) -o producer producer.o -lrt

consumer: consumer.o
	$(CC) $(CFLAGS) -o consumer consumer.o -lrt

producer.o: producer.c shared.h
	$(CC) $(CFLAGS) -c producer.c

consumer.o: consumer.c shared.h
	$(CC) $(CFLAGS) -c consumer.c

clean:
	rm -f *.o $(TARGETS)