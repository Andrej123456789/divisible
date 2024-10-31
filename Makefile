CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

OBJ = binary

OBJDIR = $(OBJ)/objects
OBJS = $(addprefix $(OBJDIR)/, $(patsubst src/%.c, %.o, $(wildcard src/*.c)))

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

.PHONY: run
run:
	@./$(BIN)

.PHONY: clean
clean:
	rm -rf $(OBJ)
