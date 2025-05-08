all:
	g++ -std=c++20 -fmodules-ts -Wall -g main.cc

run:
	./a.out

clean:
	rm *.o *.d ${EXEC}


.PHONY: clean run
