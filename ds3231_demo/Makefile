SHELL := /bin/bash # Use bash syntax
DC ?=
PROGRAM ?=
#default target board
TARGET ?= artix7_35t
DEBUG ?=
MARCH ?= rv32imac
MABI  ?= ilp32
XLEN  ?= 32
FLAGS ?=


CXX := riscv$(XLEN)-unknown-elf-g++
LD := riscv$(XLEN)-unknown-elf-ld
OBJCOPY := riscv$(XLEN)-unknown-elf-objcopy
OBJDUMP := riscv$(XLEN)-unknown-elf-objdump

bspinc := $(GENLIB)/bsp/inc
bspdri := $(GENLIB)/bsp/dri
bspboard := $(GENLIB)/bsp/boards/$(TARGET)

all: create_dir
	$(MAKE) $(PROGRAM).riscv
	echo "$(PROGRAM)"

$(PROGRAM).riscv: create_dir
	$(CXX) $(CXXFLAGS) -march=$(MARCH) -mabi=$(MABI) -w $(DC) -mcmodel=medany -static $(FLAGS) \
	-I$(bspinc) -I$(bspdri) -I$(bspboard) \
	-c ./$(PROGRAM).cpp -o ./output/$(PROGRAM).cpp.o -lm -lgcc -lstdc++
	$(CXX) $(CXXFLAGS) -march=$(MARCH) -mabi=$(MABI) -w $(DC) -mcmodel=medany -static $(FLAGS) \
	-I$(bspinc) -I$(bspdri) -I$(bspboard) \
	-c ./Unified_ds3231.cpp -o ./output/Unified_ds3231.cpp.o -lm -lgcc -lstdc++
	$(CXX) $(CXXFLAGS) -march=$(MARCH) -mabi=$(MABI) -w $(DC) -mcmodel=medany -static $(FLAGS) \
	-I$(bspinc) -I$(bspdri) -I$(bspboard) \
	-c ./Unified_testing.cpp -o ./output/Unified_testing.cpp.o -lm -lgcc -lstdc++
	$(LD) -T $(bspboard)/link.ld ./output/$(PROGRAM).cpp.o ./output/Unified_testing.cpp.o \
	$(GENLIB)/gen_lib/libtesting$(XLEN).a -o ./output/$(PROGRAM).testing -static -nostartfiles -lm -lgcc -lstdc++
	$(OBJCOPY) -O binary ./output/$(PROGRAM).testing ./output/$(PROGRAM).bin
	$(OBJDUMP) -D ./output/$(PROGRAM).testing > ./output/$(PROGRAM).dump

create_dir:
	@mkdir -p ./output

