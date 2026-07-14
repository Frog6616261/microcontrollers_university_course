CC := sdcc
FLASH := FlashUtilCL.exe
USB_RESET := "USB Debug Adapter Firmware Reset.exe"

CFLAGS := -mmcs51

BUILD_DIR := build
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

SRC_MAIN := main.c

SRC_OTHER := \
	$(wildcard src/*.c) \
	$(wildcard mcu/*.c) \
	$(wildcard include/*.c) \
	$(wildcard drivers/timer/*.c) \
	$(wildcard drivers/uart/*.c)

OBJ_MAIN := $(patsubst %.c,$(OBJ_DIR)/%.rel,$(SRC_MAIN))
OBJ_OTHER := $(patsubst %.c,$(OBJ_DIR)/%.rel,$(SRC_OTHER))
OBJ := $(OBJ_OTHER) $(OBJ_MAIN)

IHX := $(BUILD_DIR)/$(TARGET).ihx
HEX := $(HEX_DIR)/$(TARGET).hex
BIN := $(BIN_DIR)/$(TARGET).bin

create-build-dir:
	@echo "Create build directories"
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(HEX_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/mcu
	@mkdir -p $(OBJ_DIR)/include
	@mkdir -p $(OBJ_DIR)/drivers
	@mkdir -p $(OBJ_DIR)/drivers/timer
	@mkdir -p $(OBJ_DIR)/drivers/uart

# Сначала компилируем все обычные .c
$(OBJ_DIR)/%.rel: %.c | create-build-dir
	@echo "Compile $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# main.c компилируем отдельно и делаем зависимым от остальных объектов
$(OBJ_DIR)/main.rel: main.c $(OBJ_OTHER) | create-build-dir
	@echo "Compile main.c last"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(IHX): $(OBJ)
	@echo "Link"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(IHX) $(OBJ)

$(HEX): $(IHX)
	@echo "Make HEX"
	@packihx $(IHX) > $(HEX)

$(BIN): $(HEX)
	@echo "Make BIN"
	@makebin $(HEX) > $(BIN)

build: $(BIN)
	@echo "Complete build"

clean:
	@rm -rf $(BUILD_DIR)/

rebuild: clean build

print-src:
	@echo $(SRC_MAIN) $(SRC_OTHER)

print-obj:
	@echo $(OBJ)

erase-flash:
	@echo "Start erase flash"
	@$(FLASH) FLASHEraseUSB "" 1
	@echo "Complete erase flash"

flash-run: build
	@echo "Start flash-run"
	@$(FLASH) DownloadUSB -ER $(HEX) "" 0 1
	@echo "Complete flash-run"

flash-halt: build
	@echo "Start flash-halt"
	@$(FLASH) DownloadUSB -E $(HEX) "" 0 1
	@echo "Complete flash-halt"

verify: build
	@echo "Start verify"
	@$(FLASH) VerifyUSB $(HEX) "" 1
	@echo "Complete verify"

reflash: build erase-flash flash-run verify
	@echo "Complete reflash"

reflash-halt: build erase-flash flash-halt verify
	@echo "Complete reflash-halt"

adapter-reset:
	@echo "Reset USB Debug Adapter"
	@$(USB_RESET)
	@echo "Complete adapter reset"

debug-target:
	@echo "FLASHUtilCL does not support interactive debug."
	@echo "Use Silicon Labs IDE for breakpoints, stepping, registers, memory view, run/halt/reset."

help:
	@echo "Targets:"
	@echo "  build         - compile and link project"
	@echo "  clean         - remove build directory"
	@echo "  rebuild       - clean and build again"
	@echo "  print-src     - print source files"
	@echo "  print-obj     - print object files"
	@echo "  erase-flash   - erase MCU flash"
	@echo "  flash-run     - build and flash, target runs after download"
	@echo "  flash-halt    - build and flash, target stays halted"
	@echo "  verify        - build and verify HEX in target"
	@echo "  reflash       - build + erase + flash-run + verify"
	@echo "  reflash-halt  - build + erase + flash-halt + verify"
	@echo "  adapter-reset - reset USB Debug Adapter"
	@echo "  debug-target  - reminder that full debug needs Silicon Labs IDE"

all: clean build erase-flash flash-run

.PHONY: all build clean rebuild print-src print-obj erase-flash flash-run flash-halt verify reflash reflash-halt adapter-reset debug-target help