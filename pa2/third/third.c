#include<stdio.h>
#include<stdlib.h>

int check(int, int **, int, int);
int horizontal(int **);
int vertical(int **);
int recur(int , int,int **);
int checker(int **, int, int, int , int);

int firstc;
int firstr;

/////////////////////////////////////////////////////////////////




int checker(int **X, int r, int i, int c, int match){

firstc = (i/3)+(3 * (c/3));
firstr = (i%3)+(3 * (r/3));

 if ((X[firstr][firstc] == match)||(match==X[r][i])||(match==X[i][c])){//check for same row,column, and box
	 return 0;}
return 1;
}





/////////////////////////////////////////////////////////////////






int check(int match, int **X, int c, int r)
{
    for(int i=0; i<9; i++)
    {if(!checker(X,r,i,c,match)){
     return 0;}}
    return 1;
}







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




int inGrid(int column, int row){//still in the matrix
if(column<9 && row<9)
{return 1;}
else{return 0;}
}





/////////////////////////////////////////////////////////////////





int recur(int currc, int currr,int **X){
  
if(inGrid(currc,currr)) {
    if(((currc+1)<9) && (0!=X[currr][currc]))
   	 {return recur(currc+1,currr,X);}
    else if(((currr+1)<9)&&(0!=X[currr][currc])) 
    	 {return recur(0,currr+1,X);}
    else if (X[currr][currc]>0)
     	{return 1;}
    else if(0==X[currr][currc]) {
     	for(int i=0; i<9; i++){
           if(check(i+1, X, currc, currr)){
               X[currr][currc] = i+1;
               if((currc+1)<9){
                   if(!recur(currc +1,currr,X))
			{ X[currr][currc] = 0;}
                        else 
		        {return 1;}
                    }
               else if((currr+1)<9){
               		if(!recur(0,currr+1,X))
                        { X[currr][currc] = 0; }
                        else 
                         {return 1;}
                    }
               else
               { 
                return 1;
               }

               }
            }
        }
        return 0;
    }
return 0;
}


/////////////////////////////////////////////////////////////////



int main (int argc, char** argv){

int **X;

FILE *fr;
fr = fopen(argv[1], "r");

X = malloc((9*sizeof(double*))); //ORIGINAL MATRIX

for(int i = 0; i< 9; i++){ //ORGINAL ALLOCATION 

X[i] = malloc(9*sizeof(double));

}



char tempvalue;

for(int i = 0; i < 9; i++){
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

int start1 = 0;
int start2 = 0;

int final = recur(start2, start1,X);

if(1!=final){

printf("no-solution");
	return 0;
}

else{for(int i = 0; i < 9 ;i++){
		for(int j = 0;j<9;j++){

			printf("%d\t",X[i][j]); }

		printf("\n");

	}
}

fclose(fr);

return 0;
}

