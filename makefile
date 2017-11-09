all:
	gcc -o procTest processes.c

run: all
	./procTest

clean:
	rm output.txt

