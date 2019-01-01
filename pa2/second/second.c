#include<stdio.h>
#include<stdlib.h>


int check(int, int **, int, int);
int horizontal(int **);
int vertical(int **);
int** solve(int **);
int checker(int **, int, int, int , int);


int different;

/////////////////////////////////////////////////////////////////
int horizontal(int **X){

for(int k = 0;k<9;k++){ //TESTING HORIZONTAL NUMBERS

for(int j = 0;j<9;j++){

	int temp = X[k][j];
	
	for(int i = j+1; i<9;i++){
	
	if(temp == X[k][i] && temp != 0){

		return 0;
	
	       }
	

          }

      }

}

return 1;

}

/////////////////////////////////////////////////////////////////

int vertical(int **X){


for(int k = 0;k<9;k++){ //TESTING VERTICAL NUMBERS

for(int j = 0;j<9;j++){

	int temp = X[j][k];
	
	for(int i = j+1; i<9;i++){
	
	if(temp == X[i][k] && temp != 0){

		return 0;
	
		}
	

	  }
       }

}

return 1;
}

/////////////////////////////////////////////////////////////////

int checker(int **X, int r, int i, int c, int match){

int firstr;
int firstc;

firstc = (i/3)+(3 * (c/3));
firstr = (i%3)+(3 * (r/3));

if((X[firstr][firstc] == match)||(match==X[r][i])||(match==X[i][c])){//Check for row,col,and box
	 return 0;}

return 1;
}

/////////////////////////////////////////////////////////////////

int check(int match, int **X, int c, int r)
{
    for(int i=0; i<9; i++){
	
	if(!checker(X,r,i,c,match)){
     	return 0;}

	}

    return 1;
}

/////////////////////////////////////////////////////////////////

int** solve(int** X){

different = 1;


while(different){

different = 0;

for(int i = 0; i < 9 ;i++){
	for(int j = 0;j<9;j++){
		
		if(X[i][j]==0){

			int possibles = 0;
			int value = 0;

			for(int k = 1;k<=9;k++){
			
				if(check(k, X, j, i)){
				possibles = possibles + 1;
				value = k;
				}
			

			}

			if(possibles == 1){//if there is only one possibility 
			X[i][j] = value;
			different = 1;//matrix changed 
			}
			
		

	}


	}


}

}//while

return X;

}//solve

/////////////////////////////////////////////////////////////////

int main (int argc, char** argv){


FILE *fr;
fr = fopen(argv[1], "r");



int **X = malloc((9*sizeof(double*))); 

for(int i = 0; i< 9; i++){
	X[i] = malloc(9*sizeof(double));
}




char tempvalue;

for(int i = 0; i < 9; i++){//populate 
	for(int j = 0; j < 9; j++){	
		
		fscanf(fr,"%c\t",&tempvalue);
		
		if(tempvalue - '0' == -3){
		X[i][j]= 0;}
		
		else{
		int test = tempvalue - '0';

			if(test > 9 || test < 0){
			printf("no-solution");
			return 0;}
			
			else{X[i][j]= test;}
		}

	}

}


if(!horizontal(X) || !vertical(X)){
	printf("no-solution");
	return 0;
}



X = solve(X);


int has0=0;


for(int i = 0; i < 9 ;i++){
	for(int j = 0;j<9;j++){

		if(X[i][j]==0){
		has0=1;}

	}

}

if(has0){
printf("no-solution");
return 0;}

else{

for(int i = 0; i < 9 ;i++){
	for(int j = 0;j<9;j++){

		printf("%d\t",X[i][j]); 
	}

	printf("\n");

}

}



return 0;

}//end main













