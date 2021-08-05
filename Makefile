CC := g++
CINC_DIR := /home/debjit/Tools/Xilinx/Vivado/2021.1/include
BIN=./bin

## Nothing to be changed after this line
SRCS := $(wildcard *.cc)
BINS := $(patsubst %.cc,%,$(SRCS))
CXXFLAGS = -g -Wall -I$(CINC_DIR)

all: $(BINS)

$(BINS): %: %.cc
	$(CC) $(CXXFLAGS) $< -o $(BIN)/$@

clean:
	rm -f $(BIN)/*

.PHONY: all clean
## Nothing to be changed before this line
