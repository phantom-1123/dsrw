main: main.cpp *.h die.cc
	g++ main.cpp die.cc -o main

test: main.cpp *.h die.cc
	g++ -DTEST main.cpp die.cc -o test

.PHONY: debug

debug: test_main

test_main: test_main.cpp *.h die.cc
	g++ -DTEST -g test_main.cpp die.cc -o test_main
clean:
	rm -f main test_main test