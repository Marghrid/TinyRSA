all: encrypt.exe decrypt.exe new_key.exe hack.exe

encrypt.exe: encrypt.o algorithms.o
	gcc -Wall -Wextra -o encrypt.out encrypt.o algorithms.o

decrypt.exe: decrypt.o algorithms.o
	gcc -Wall -Wextra -o decrypt.out decrypt.o algorithms.o

new_key.exe: new_key.o algorithms.o
	gcc -Wall -Wextra -o new_key.out new_key.o algorithms.o

hack.exe: hack.o algorithms.o
	gcc -Wall -Wextra -o hack.out hack.o algorithms.o

algorithms.o: algorithms.c algorithms.h
	gcc -Wall -Wextra -c algorithms.c

encrypt.o: encrypt.c
	gcc -Wall -Wextra -c encrypt.c

decrypt.o: decrypt.c
	gcc -Wall -Wextra -c decrypt.c

new_key.o: new_key.c
	gcc -Wall -Wextra -c new_key.c

hack.o: hack.c
	gcc -Wall -Wextra -c hack.c

clean: 
	rm *.o *.out
