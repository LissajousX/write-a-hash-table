CC = gcc
CFLAGS = -Wall -Wextra -pedantic -lm
SRC = src/prime.c src/hash_table.c src/main.c
OBJ = $(SRC:.c=.o)
TARGET = hash_table_program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
