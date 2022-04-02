CC = gcc
FLAGS = -g -O0
SRC = $(shell find src -name *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))
TARGET = ./bin/main.bin

all: $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(TARGET)

%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@

run_main: all
	$(TARGET)

clean:
	rm -rf bin/*.*
	rm -rf $(OBJ)