CC=g++
CFLAGS=-Wall -Wextra -std=c++11 # Enable all warnings | additional warnings for extra features
TARGET=addMatrix
SRC=$(wildcard *.cpp) # Search for all .cpp files in the current directory and set them to SRC files
OBJS=$(SRC:.cpp=.o)

all: $(TARGET)

# $@ target file names, in this case is the name of the executable file being built
# $^ list of source files 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)