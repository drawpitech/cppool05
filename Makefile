##
## EPITECH PROJECT, 2024
## ppool05
## File description:
## Makefile for string
##

# ↓ Basic variables
CC := gcc -std=gnu11
CFLAGS := -W -Wall -Wextra -Wunused -Wpedantic
CFLAGS += -Wundef -Wshadow -Wcast-align
CFLAGS += -Wstrict-prototypes -Wmissing-prototypes
CFLAGS += -Waggregate-return -Wcast-qual
CFLAGS += -Wunreachable-code
CFLAGS += -U_FORTIFY_SOURCE
CFLAGS += -iquote .

# ↓ Binaries
NAME := libstring.a
TEST_NAME := unit_tests

# Source files
VPATH := .
SRC := string_init.c
SRC += string_assign.c
SRC += string_append.c
SRC += string_at.c
SRC += string_clear.c
SRC += string_length.c
SRC += string_compare.c
SRC += string_copy.c
SRC += string_c_str.c
SRC += string_empty.c
SRC += string_find.c
SRC += string_insert.c
SRC += string_to_int.c
SRC += string_split.c
SRC += string_print.c
SRC += string_join.c

VPATH += tests
TEST_SRC := test_assign.c

# ↓ Objects
BUILD_DIR := .build
OBJ := $(SRC:%.c=$(BUILD_DIR)/source/%.o)
TEST_OBJ := $(TEST_SRC:%.c=$(BUILD_DIR)/tests/%.o)

# ↓ Dependencies for headers
DEPS_FLAGS := -MMD -MP
DEPS := $(OBJ:.o=.d)
TEST_DEPS := $(OBJ_TESTS:.o=.d)

DIE := exit 1
# ↓ Colors
ECHO := echo -e
C_RESET := \033[00m
C_BOLD := \e[1m
C_RED := \e[31m
C_GREEN := \e[32m
C_YELLOW := \e[33m
C_BLUE := \e[34m
C_PURPLE := \e[35m
C_CYAN := \e[36m

all: $(NAME)

.PHONY: all

# ↓ Compiling
$(BUILD_DIR)/source/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(ECHO) "[${C_BOLD}${C_RED}CC${C_RESET}] $^"
	@ $(CC) -o $@ -c $< $(CFLAGS) || $(DIE)

$(NAME): $(OBJ)
	@ $(ECHO) "[${C_BOLD}${C_YELLOW}AR${C_RESET}] ${C_RED}$@${C_RESET}"
	@ $(AR) rc $@ $(OBJ) || $(DIE)

.PHONY: $(NAME)

# ↓ Tests
$(BUILD_DIR)/tests/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(ECHO) "[${C_BOLD}${C_RED}CC${C_RESET}] $^"
	@ $(CC) -o $@ -c $< $(CFLAGS) || $(DIE)

ifneq ($(NO_COV), 1)
$(TEST_NAME): CFLAGS += -g3 --coverage
endif
$(TEST_NAME): LDFLAGS += -lcriterion -L . -lstring
$(TEST_NAME): $(TEST_OBJ) $(NAME)
	@ $(ECHO) "[${C_BOLD}${C_YELLOW}CC${C_RESET}] ${C_GREEN}$@${C_RESET}"
	@ $(CC) -o $@ $(TEST_OBJ) $(LDFLAGS) $(CFLAGS) || $(DIE)

tests_run: fclean
	@ $(MAKE) -s -C . $(TEST_NAME)
	@-./$(TEST_NAME)

.PHONY: $(TEST_NAME) tests_run

# ↓ Cleaning
clean:
	@ $(RM) -r $(BUILD_DIR)

fclean: clean
	@ $(RM) $(NAME) $(TEST_NAME)

.PHONY: clean fclean

re: fclean
	@ $(MAKE) -s -C .

.PHONY: re

-include $(DEPS)
