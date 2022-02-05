.PHONY=all clean install
all: main

main: clean
	gcc -o main main.c

install:
	./main

clean:
	rm -f main

archive:
	tar -czvf ../test-package-latest.tar.gz ./*