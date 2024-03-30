# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -std=c++11 -Wall

# Directories
SRC_DIR = src
INC_DIR = src/headers
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Get list of header files
HEADERS = $(wildcard $(INC_DIR)/*.hpp)
# Generate list of object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Executable name
TARGET = $(BIN_DIR)/main

.PHONY: all clean build run

# Default target
all: build

# Build rule
build: $(TARGET)
	@echo "Build completed."

# Rule to compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Link object files to create executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	@echo "Linking object files to create executable..."
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)
	@echo "Executable $(TARGET) created."
	$(MAKE) clean

# Run the executable
run:
	$(TARGET)

# Clean rule
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJ_DIR)
	@echo "Clean up completed."

# Disable default make behavior of printing entering directory
MAKEFLAGS += --no-print-directory