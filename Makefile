FLAGS=-O3 -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

all: a.out git

git:
	git add .

a.out: main.cpp bin_tree.h
	g++ $(FLAGS) main.cpp bin_tree.h -o a.out

clean:
	rm -f *.o *.out

zip:
	zip bin_tree.zip *.cpp *.h Makefile

delete_zip:
	rm -f *.zip