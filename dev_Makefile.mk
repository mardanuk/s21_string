DEV_FLAGS 			:= -Wall -Werror -Wextra -std=c11 -pedantic \
 						-Wnested-externs -Wcast-qual -Wshadow \
 						-Wstrict-prototypes

CC              := gcc
CFLAGS 			:= -Wall -Werror -Wextra -std=c11
DEBUG_FLAGS 	:= -g
FUNC_DIR        := ./functions/
FUNC_TEST_DIR   := tests/
OBJ_DIR         := ./
BUILD_DIR		:= ../build/
LIB_HEADER      := s21_string.h
TEST_FLAGS := -lcheck -lm -lpthread




GCOV_FLAGS      := -fprofile-arcs -ftest-coverage
EXTRA_LIB_FLAGS	:=
TEST_DIR_BUILD	:= tests/build/
LIB_STATIC      := s21_string.a
VALGRIND_FLAGS  := --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log

FUNC_SRCS       := $(addprefix $(FUNC_DIR), s21_common.c \
                                            s21_dynamic_arrays.c \
                                            s21_atof.c \
                                            s21_strtol.c \
                                            s21_itoa.c \
                                            s21_ftoa.c \
                                            s21_sprintf_aux.c \
                                            s21_sscanf_aux.c \
											s21_memchr.c \
                                            s21_memcmp.c \
                                            s21_memcpy.c \
                                            s21_memset.c \
                                            s21_strchr.c \
                                            s21_strcspn.c \
                                            s21_strerror.c \
                                            s21_strlen.c \
                                            s21_strncat.c \
                                            s21_strncmp.c \
                                            s21_strncpy.c \
                                            s21_strpbrk.c \
                                            s21_strrchr.c \
                                            s21_strstr.c \
                                            s21_strtok.c \
                                            s21_sprintf.c \
                                            s21_sscanf.c \
                                            s21_to_upper.c \
                                            s21_to_lower.c \
                                            s21_insert.c \
                                            s21_trim.c)





dev_main_test_manual_valgrind:
	$(CC) main_test.c $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $@.out
	valgrind $(VALGRIND_FLAGS) ./$@.out
dev_main_test_manual:
	$(CC) main_test.c $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $@.out
	 ./$@.out

dev_test_sprintf_manual:
	$(CC) test_s21_sprintf.c functions/s21_sprintf.c functions/s21_sprintf_aux.c functions/s21_common.c  $(EXTRA_LIB_FLAGS) $(DEV_FLAGS) -o ./$@_exec.out $(DEBUG_FLAGS)

dev_test_sscanf_manual:
	$(CC) test_s21_sscanf.c functions/s21_sscanf.c functions/s21_sscanf_aux.c functions/s21_common.c functions/s21_atof.c  $(EXTRA_LIB_FLAGS) $(DEV_FLAGS) -o ./$@_exec.out $(DEBUG_FLAGS)

dev_test_sprintf_manual_exec: dev_test_sprintf_manual
	./$@.out

dev_test_sscanf_manual_exec: dev_test_sscanf_manual
	./$@.out

dev_test_sprintf_manual_valgrind: dev_test_sprintf_manual
	valgrind $(VALGRIND_FLAGS) ./dev_test_sprintf_manual_exec.out

dev_valgrind_test_sscanf: dev_test_sscanf
	valgrind $(VALGRIND_FLAGS) ./dev_test_sscanf.out

dev_test_memchr:
	$(CC) $(FUNC_TEST_DIR)s21_test_memchr.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_memchr_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_memchr.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_atof:
	$(CC) $(FUNC_TEST_DIR)s21_test_atof.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_atof_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_atof.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strtol:
	$(CC) $(FUNC_TEST_DIR)s21_test_strtol.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_strtol_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strtol.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_memcmp:
	$(CC) $(FUNC_TEST_DIR)s21_test_memcmp.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_memcmp_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_memcmp.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_memcpy:
	$(CC) $(FUNC_TEST_DIR)s21_test_memcpy.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_memcpy_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_memcpy.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_memset:
	$(CC) $(FUNC_TEST_DIR)s21_test_memset.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_memset_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_memset.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strchr:
	$(CC) $(FUNC_TEST_DIR)s21_test_strchr.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_strchr_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strchr.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strcspn:
	$(CC) $(FUNC_TEST_DIR)s21_test_strcspn.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_strcspn_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strcspn.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strerror:
	$(CC) $(FUNC_TEST_DIR)s21_test_strerror.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_strerror_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strerror.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strlen:
	$(CC) $(FUNC_TEST_DIR)s21_test_strlen.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_strlen_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strlen.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strncat:
	$(CC) $(FUNC_TEST_DIR)s21_test_strncat.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_strncat_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strncat.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strncmp:
	$(CC) $(FUNC_TEST_DIR)s21_test_strncmp.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_strncmp_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strncmp.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strncpy:
	$(CC) $(FUNC_TEST_DIR)s21_test_strncpy.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_strncpy_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strncpy.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strpbrk:
	$(CC) $(FUNC_TEST_DIR)s21_test_strpbrk.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_strpbrk_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strpbrk.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strrchr:
	$(CC) $(FUNC_TEST_DIR)s21_test_strrchr.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_strrchr_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strrchr.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strstr:
	$(CC) $(FUNC_TEST_DIR)s21_test_strstr.c -L. $(LIB_STATIC) $(TEST_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out
dev_test_strstr_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strstr.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_strtok:
	$(CC) $(FUNC_TEST_DIR)s21_test_strtok.c -L. $(LIB_STATIC) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS)  -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_strtok_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_strtok.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_sprintf:
	$(CC) $(FUNC_TEST_DIR)s21_test_sprintf.c -L. $(LIB_STATIC) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS)  -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_sprintf_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_sprintf.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $@.out
	valgrind $(VALGRIND_FLAGS) ./$@.out

dev_test_sscanf:
	$(CC) $(FUNC_TEST_DIR)s21_test_sscanf.c -L. $(LIB_STATIC) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_sscanf_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_sscanf.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_to_upper:
	$(CC) $(FUNC_TEST_DIR)s21_test_to_upper.c -L. $(LIB_STATIC) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_to_upper_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_to_upper.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_to_lower:
	$(CC) $(FUNC_TEST_DIR)s21_test_to_lower.c -L. $(LIB_STATIC) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_to_lower_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_to_lower.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_trim:
	$(CC) $(FUNC_TEST_DIR)s21_test_trim.c -L. $(LIB_STATIC) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_trim_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_trim.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out

dev_test_insert:
	$(CC) $(FUNC_TEST_DIR)s21_test_insert.c -L. $(LIB_STATIC) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	./$(TEST_DIR_BUILD)$@.out

dev_test_insert_valgrind:
	$(CC) $(FUNC_TEST_DIR)s21_test_insert.c -L. $(FUNC_SRCS) $(TEST_FLAGS) $(EXTRA_LIB_FLAGS) $(DEBUG_FLAGS) -o $(TEST_DIR_BUILD)$@.out
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR_BUILD)$@.out
