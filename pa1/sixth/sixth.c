#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc, char** argv){

	for(int i = 1; i < argc; i++){// if the first letter is a vowel
		if(argv[i][0] == 'A' || argv[i][0] == 'E' || 
		argv[i][0] == 'I' || argv[i][0] == 'O' || 
		argv[i][0] == 'U'|| argv[i][0] == 'a' || argv
		[i][0] == 'e' || argv[i][0] == 'i' || 
		argv[i][0] == 'o' || argv[i][0] == 'u' ) {
			printf("%syay ", argv[i]);
		}
		

		else{
			int length = strlen(argv[i]);
			int one = 0;
			int mark = 0;


			if(length == 1){
			printf("%c",argv[i][0]);
			printf("ay ");
			one =1;
			};

			int lencounter=0;

			for(mark = 1; mark <=length; mark++){
				if(argv[i][mark] == 'a' || argv[i][mark] == 'e' || argv[i][mark] == 'i' || 
				argv[i][mark] == 'o' || argv[i][mark] == 'u'){
				for(int letter = mark; letter < length; letter++){//print the last letters
					printf("%c", argv[i][letter]);
				}
				for(int phrase = 0; phrase < mark; phrase++){
					printf("%c", argv[i][phrase]);					
				}
					printf("ay ");
					break;

				}

				else{
				lencounter++;
				if((lencounter==length)&&(one==0)){
					for(int letter = 0; letter < length; letter++){
					printf("%c", argv[i][letter]);
					}
					printf("ay ");
					lencounter=0;
				}
				


				}
					
			}
		}
	}	

	return 0;
}
