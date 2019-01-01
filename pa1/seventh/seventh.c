#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv){
	for(int i = 1; i < argc; i++){
		int stringlength = strlen(argv[i]);
		printf("%c", argv[i][stringlength-1]);	
	}
	return 0;
}
