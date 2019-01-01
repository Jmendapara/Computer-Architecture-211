all: eighth

eighth: eighth.c
	$gcc -Wall -Werror -fsanitize=address -std=c99 eighth.c -o eighth 

clean:
	rm -rf eighth 
