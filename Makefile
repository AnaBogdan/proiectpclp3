CC = gcc
CFLAGS = -Wall -Wextra -g
LIBS = -lncurses

TARGET = stewordle

all: $(TARGET)

$(TARGET): stewordle.c
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -f $(TARGET)
