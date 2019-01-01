all: second

second: second.c
	$gcc -Wall -Werror -fsanitize=address -std=c99 second.c -o second 

clean:
	rm -rf second 
