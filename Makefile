# === Config ===
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -O2
AR = ar
ARFLAGS = rcs

# === File Paths ===# === Config ===
CC = gcc
INCLUDE_DIR = inc
CFLAGS = -Wall -Wextra -O3 -I$(INCLUDE_DIR)
AR = ar
ARFLAGS = rcs

TEST_CFLAGS = -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer -I$(INCLUDE_DIR)

# === File Paths ===
SRC_DIR = src
BUILD_DIR = build
LIB_NAME = libdynamic_string.a

SRC = $(SRC_DIR)/dynamic_string.c
OBJ = $(BUILD_DIR)/dynamic_string.o

# === Targets ===

# Default: Build the static library
all: $(LIB_NAME)

# Static library
$(LIB_NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

# Compile object file
$(OBJ): $(SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build dir if needed
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(LIB_NAME)
	rm -rf test/test_dynamic_string
	rm -rf compile_commands.json

# Optional: Build a test binary
test: $(LIB_NAME)
	$(CC) $(TEST_CFLAGS) test/test_dynamic_string.c $(LIB_NAME) -o test/test_dynamic_string

.PHONY: all clean test
