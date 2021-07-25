main: main.cpp *.h die.cc
	g++ main.cpp die.cc -o main

.PHONY: test

test: test_main

test_main: test_main.cpp *.h die.cc
	g++ -DTEST -g test_main.cpp die.cc -o test_main
clean:
	rm -f main test_main