all: third

third: third.c
	$gcc -Wall -Werror -fsanitize=address -std=c99 third.c -o third 

clean:
	rm -rf third 
