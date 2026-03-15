CC := sdcc
CFLAGS := -mmcs51

DATE := $(shell date +%Y-%m-%d-%H-%M-%S)
BUILD_DIR := build/$(DATE)
HEX_DIR := $(BUILD_DIR)/hex
BIN_DIR := $(BUILD_DIR)/bin
OBJ_DIR := $(BUILD_DIR)/obj

TARGET := main

INCLUDES := \
	-Iinclude \
	-Imcu \
	-Isrc \
	-Idrivers/timer \
	-Idrivers/uart

SRC := \
	main.c \
	$(wildcard src/*.c) \
	$(wildcard mcu/*.c) \
	$(wildcard include/*.c) \
	$(wildcard drivers/timer/*.c) \
	$(wildcard drivers/uart/*.c)

OBJ := $(patsubst %.c,$(OBJ_DIR)/%.rel,$(SRC))

IHX := $(BUILD_DIR)/$(TARGET).ihx
HEX := $(HEX_DIR)/$(TARGET).hex
BIN := $(BIN_DIR)/$(TARGET).bin

all: $(BIN)

$(BUILD_DIR):
	@echo "Create dir $(BUILD_DIR)"
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(HEX_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/drivers/timer
	@mkdir -p $(OBJ_DIR)/drivers/uart

$(OBJ_DIR)/%.rel: %.c | $(BUILD_DIR)
	@echo "Compile $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(IHX): $(OBJ)
	@echo "Link"
	$(CC) $(CFLAGS) $(INCLUDES) -o $(IHX) $(OBJ)

$(HEX): $(IHX)
	@echo "Make HEX"
	packihx $(IHX) > $(HEX)

$(BIN): $(HEX)
	@echo "Make BIN"
	makebin $(HEX) > $(BIN)

clean:
	rm -rf build

print-src:
	@echo $(SRC)

.PHONY: all clean print-src