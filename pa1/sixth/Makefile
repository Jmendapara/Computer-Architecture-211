all: sixth

sixth: sixth.c
	$gcc -Wall -Werror -fsanitize=address -std=c99 sixth.c -o sixth 

clean:
	rm -rf sixth 
