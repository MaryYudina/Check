# для запуска, возможно, понадобится докачать lcov на свой пк через brew
# нету или не скачивается brew? Печалька, придется тестить у нас на маке
CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
FLAGS_FOR_TEST:=-g $(CFLAGS)
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose
# SOURCES
OWN_FUNCS=s21_isnan_answer.c s21_fmax.c s21_factorial.c s21_pow_int.c
TRIGON=s21_sin.c s21_asin.c s21_cos.c s21_tan.c s21_acos.c s21_atan.c
OTHERS=s21_abs.c s21_fabs.c s21_ceil.c s21_floor.c s21_exp.c s21_log.c s21_fmod.c s21_pow.c s21_sqrt.c
# OBGECTS
OBGS_OWN_FUNCS=s21_isnan_answer.o s21_fmax.o s21_factorial.o s21_pow_int.o
OBGS_TRIGON=s21_sin.o s21_asin.o s21_cos.o s21_tan.o s21_acos.o s21_atan.o
OBGS_OTHERS=s21_abs.o s21_fabs.o s21_ceil.o s21_floor.o s21_exp.o s21_log.o s21_fmod.o s21_pow.o s21_sqrt.o
# OTHER PSEVDO_VALUES
EXE=test
GCOVFLAGS = -fprofile-arcs -ftest-coverage --coverage
OS = $(shell uname)
USER = $(shell whoami)
MAIN_TARGET=s21_math.a

ifeq ($(OS), Darwin)
	OPTS_FOR_TEST=-lcheck
	CMD_OPEN=open
	LEAK_TEST=leaks -atExit -- $(EXE)
else
	OPTS_FOR_TEST=-lcheck -lsubunit -lrt -lpthread -lm		
	CMD_OPEN=xdg-open
	LEAK_TEST=CK_FORK=no valgrind $(VALGRIND_FLAGS) --log-file=valgrind_result.txt $(EXE)
endif

all: $(MAIN_TARGET)

$(MAIN_TARGET): $(OBGS_OWN_FUNCS) $(OBGS_TRIGON) $(OBGS_OTHERS)
	$(CC) $(OWN_FUNCS) $(TRIGON) $(OTHERS) -c
	ar rcs $(MAIN_TARGET) $(OBGS_OWN_FUNCS) $(OBGS_TRIGON) $(OBGS_OTHERS)

test: test_s21_math.c $(MAIN_TARGET)
	$(CC) $(CFLAGS) -c test_s21_math.c -o test_s21_math.o
	$(CC) test_s21_math.o $(MAIN_TARGET) $(OPTS_FOR_TEST) -o $(EXE)

gcov_report: $(MAIN_TARGET)
# $(CC) $(CFLAGS) --coverage test_s21_math.c $(OWN_FUNCS) $(TRIGON) $(OTHERS) $(MAIN_TARGET) $(OPTS_FOR_TEST) -o gcov_test
	$(CC) $(CFLAGS) $(GCOVFLAGS) test_s21_math.c $(OWN_FUNCS) $(TRIGON) $(OTHERS) $(MAIN_TARGET) $(OPTS_FOR_TEST) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	$(CMD_OPEN) ./report/index.html
# Первой страницей открывается сразу полная сводка по тестам. Так и задумано.
style: style-add style-check style-fix style-delete

# STYLE-PART
style-add:
	cp ../materials/linters/.clang-format .

style-check:
	clang-format -style=Google -n *.c
	clang-format -style=Google -n *.h

style-fix:
	clang-format -style=Google -i *.c
	clang-format -style=Google -i *.h

style-delete:
	rm .clang-format
# END OF STYLE-PART

brsw:
	eval /opt/goinfre/$(USERNAME)/homebrew/bin/brew shellenv; \
	brew update --force --quiet; \
	chmod -R go-w "$(brew --prefix)/share/zsh"

install-brew:
	cd /opt/goinfre/$(USERNAME); \
	mkdir homebrew; \
	git clone https://github.com/Homebrew/brew homebrew; \
	make brsw

install-lcov:
	brew install lcov

clean:
	rm -rf *.o *.a gcov_test *.html *.css ./GcovReport ./*.gcno ./*.gcda ./report ./*.info ./*.dSYM test valgrind_result.txt

leaks:
	$(LEAK_TEST)

rebuild: clean all test style-check leaks gcov-report

.PHONY: all clean test install_lcov