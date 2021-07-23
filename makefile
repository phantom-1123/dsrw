main: main.cpp *.h die.cc
	g++ main.cpp die.cc -o main
clean:
	rm main