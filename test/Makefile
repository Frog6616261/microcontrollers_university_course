CC=sdcc
CFLAGS=-mmcs51
SRC = main.c

DATE := $(shell date +%Y-%m-%d-%H-%M-%S)
BUILD_DIR := build/$(DATE)
HEX_DIR := $(BUILD_DIR)/hex
BIN_DIR := $(BUILD_DIR)/bin

TARGET = main


all: $(BUILD_DIR) compile make_hex make_bin

$(BUILD_DIR):
	@echo "Create dir $(BUILD_DIR)"
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(HEX_DIR)
	@mkdir -p $(BIN_DIR)


compile:
	@echo "compile $(SRC)"
	@$(CC) -mmcs51 $(SRC) --out-fmt-ihx -o $(BUILD_DIR)/$(TARGET).ihx
	@echo "compile $(SRC) done"

make_hex:
	@echo "start make hex"
	@packihx $(BUILD_DIR)/$(TARGET).ihx > $(HEX_DIR)/$(TARGET).hex
	@echo "complete make hex"

make_bin:
	@echo "start make bin"
	@makebin $(HEX_DIR)/$(TARGET).hex > $(BIN_DIR)/$(TARGET).bin
	@echo "complete make bin"	

	