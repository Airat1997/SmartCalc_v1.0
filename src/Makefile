TARGET = SmartCalc
CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11 

all: install gcov_report

install: uninstall
	mkdir SmartCalc
	cd SmartCalc && cmake -B build "../ui/SmartCalc" && make -C build SmartCalc
	cp -R SmartCalc/build/SmartCalc.app ~/Desktop
	
uninstall:
	rm -rf SmartCalc ~/Desktop/SmartCalc.app
clean:
	rm -rf SmarCalc.tar archiv SmartCalc ~/Desktop/SmartCalc.app test report

dvi:
	open ../README_RUS.md

dist: uninstall install
	mkdir archiv
	@cp -r calculator Makefile SmartCalc.c SmartCalc2.h ui archiv
	@tar -cf SmarCalc.tar archiv
	rm -rf archiv
test:clean 
	gcc $(FLAGS) -o test tests/test.c calculator/*.c SmartCalc.c -lcheck
	./test

gcov_report:
	gcc --coverage -o s21_test tests/test.c calculator/*.c SmartCalc.c -lcheck
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html
	rm -rf *.gcno *.gcda *.info s21_test

clang:
	cp ../materials/linters/.clang-format .
	cp ../materials/linters/.clang-format calculator
	cp ../materials/linters/.clang-format ui/SmartCalc
	clang-format -i *.c *.h calculator/*.c calculator/*.h
	clang-format -i ui/SmartCalc/*.cpp
	rm -rf .clang-format calculator/.clang-format
	rm -rf .clang-format ui/SmartCalc/.clang-format
clang_test:
	cp ../materials/linters/.clang-format .
	cp ../materials/linters/.clang-format calculator
	clang-format -n *.c calculator/*.c
	rm -rf .clang-format calculator/.clang-format