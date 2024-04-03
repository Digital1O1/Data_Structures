# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Target: All
all: find_kth_smallest

# Target: find_kth_smallest
find_kth_smallest: main.cpp
	$(CC) $(CFLAGS) -o $@ $^

# Target: clean
clean:
	rm -f find_kth_smallest
