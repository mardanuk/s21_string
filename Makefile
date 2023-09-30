CC              := gcc
CFLAGS 			:= -Wall -Werror -Wextra -std=c11 -pedantic
FUNC_DIR        := ./functions/
FUNC_TEST_DIR   := tests/
OBJ_DIR         := ./
BUILD_DIR		:= ../build/
LIB_HEADER      := s21_string.h
TEST_FLAGS      := -lcheck -lm -lpthread
GCOV_FLAGS      := -fprofile-arcs -ftest-coverage
EXTRA_LIB_FLAGS	:= -lpcre
TEST_DIR_BUILD	:= tests/build/
LIB_STATIC      := s21_string.a

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



FUNC_OBJS_WITHOUT_OBJECT_DIRNAME = $(FUNC_SRCS:.c=.o)
FUNC_OBJS = $(subst $(FUNC_DIR), $(OBJ_DIR), $(FUNC_OBJS_WITHOUT_OBJECT_DIRNAME))

$(LIB_STATIC):$(FUNC_SRCS)
	mkdir tests/build
	$(CC) $(CFLAGS) -c $(FUNC_SRCS)
	ar -rcs $@ *.o
	make clean_obj

all: rebuild

build:
	make $(LIB_STATIC)

rebuild: clean build

cppcheck_check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h ./*/*.c ./*/*.h ./*/*/*.c ./*/*/*.h
check:
	clang-format -n -style=Google  *.c *.h ./*/*.c ./*/*.h ./*/*/*.c ./*/*/*.h
clang_format:
	clang-format -i -style=Google  *.c *.h ./*/*.c ./*/*.h ./*/*/*.c ./*/*/*.h


gcov_report:
	mkdir report
	gcc tests/main_test.c $(FUNC_DIR)*.c  $(CFLAGS) $(TEST_FLAGS) $(GCOV_FLAGS) $(EXTRA_LIB_FLAGS) -o ./$@.out
	./$@.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

test:
	gcc tests/main_test.c $(LIB_STATIC) $(CFLAGS) $(TEST_FLAGS)  -o ./test.out
	./test.out

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

install_brew_goinfre: # be careful with this!
	cd ~/goinfre
	mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C homebrew

install_lcov:
	brew install lcov

clean:
	make clean_silent --silent

clean_silent:
	rm -rf "__.SYMDEF SORTED"
	rm -rf ../*/*.o
	rm -rf ../*/*.out
	rm -rf ../*/*.info
	rm -rf ../*/*.a
	rm -rf ../*/*.g*
	rm -rf ../*/*/*.o
	rm -rf ../*/*/*.out
	rm -rf ../*/*/*.info
	rm -rf ../*/*/*.a
	rm -rf ../*/*/*.g*
	rm -rf ../*/*/*/*.o
	rm -rf ../*/*/*/*.out
	rm -rf ../*/*/*/*.info
	rm -rf ../*/*/*/*.a
	rm -rf ../*/*/*/*.g*
	rm -rf ./object_files
	rm -rf ./tests/build
	rm -rf ./report
	rm -rf ./*.log

dev_%:
	make -f dev_Makefile.mk $@

clean_obj :
	rm -f *.o

clean_after_gcov:
	rm -rf ../*.g*
	rm -rf ../*/*.g*
	rm -rf ../*/*/*.g*
	rm -rf ../*/*/*/*.g*
