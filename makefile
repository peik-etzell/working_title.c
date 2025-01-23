.PHONY: run all test clean
SHELL = /bin/sh

BUILD_DIR = ./build

SRCS := $(shell find src -type f -name "*.c")
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

EXEC = cube

CFLAGS = -g3 -O0 -Wall -Wno-unused-function -Wno-unused-parameter \
	 -Wconversion -Wdouble-promotion \
	 -fsanitize=address,undefined

LDLIBS = -lm

all: $(EXEC) $(OBJS)
run: $(EXEC)
	@./$(EXEC)

$(EXEC): $(OBJS)
	@echo $(CC) $(OBJS) -o $@
	@$(CC) $(CFLAGS) $(LDLIBS) $(OBJS) -o $@ 

$(BUILD_DIR)/%.o: %.c makefile
	@mkdir -p $(dir $@)
	@echo $(CC) $< -o $@
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR) $(EXEC)
