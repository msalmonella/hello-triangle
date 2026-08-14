CXX      := g++
CC       := gcc
CXXFLAGS := -std=c++17 -Wall -Iinclude
CFLAGS   := -Iinclude

# pull glfw3 cflags/libs from pkg-config
GLFW_CFLAGS := $(shell pkg-config --cflags glfw3)
GLFW_LIBS   := $(shell pkg-config --libs glfw3)

LIBS := $(GLFW_LIBS) -lGL -ldl -lpthread -lX11

SRC_CXX := src/main.cpp
SRC_C   := src/glad.c

OBJ := $(SRC_CXX:.cpp=.o) $(SRC_C:.c=.o)

TARGET := hello_triangle

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LIBS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(GLFW_CFLAGS) -c $< -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(GLFW_CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f src/*.o $(TARGET)
