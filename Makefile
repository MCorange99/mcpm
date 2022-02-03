.PHONY=all clean
objects=obj/mcpm.o

cc=g++
ccoptions= -Iconfig++

all: setup mcpm

setup:
	mkdir -p obj
	rm -f mcpm

obj/%.o: src/%.cpp
	$(cc) $(ccoptions) -o $@ $<

mcpm: $(objects)
	ln $< $@
	chmod +x $@

clean:
	rm -rf ./obj mcpm
	