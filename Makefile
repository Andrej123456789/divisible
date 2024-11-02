INCLUDE_DIR ?= "include"

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g -I$(INCLUDE_DIR)

OBJ = binary

OBJDIR = $(OBJ)/objects
OBJS = $(addprefix $(OBJDIR)/, $(patsubst src/%.c, %.o, $(wildcard src/*.c)))
OBJS += $(addprefix $(OBJDIR)/, $(patsubst src/simplifier/%.c, %.o, $(wildcard src/simplifier/*.c)))
OBJS += $(addprefix $(OBJDIR)/, $(patsubst src/factorer/%.c, %.o, $(wildcard src/factorer/*.c)))

BINFOLDER = $(OBJ)
BIN = $(BINFOLDER)/divisible

.PHONY: all
all : $(OBJ) $(OBJDIR) $(BIN)

$(OBJ):
	mkdir $(OBJ)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BIN) : $(OBJS)
	$(CC) $(OBJS) -o $(BIN) $(CFLAGS)

$(OBJDIR)/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : src/simplifier/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : src/factorer/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: run
run:
	@./$(BIN)

.PHONY: run_debug
run_debug:
	@./$(BIN) 3x+3 3

.PHONY: clean
clean:
	rm -rf $(OBJ)
