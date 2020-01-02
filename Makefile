run: Hashmap
	gcc -Wall -g HashMap.o main.c

Hashmap: HashMap.c
	gcc -g -c HashMap.c	

clean:
	rm HashMap.o a.out	
