#include<stdio.h>
#include<stdlib.h>

int main (int argc, char** argv){


int M1col;
int M1row;
int M2col;
int M2row;

int value;

FILE *fp;

fp = fopen(argv[1], "r");

fscanf(fp, "%d %d\n", &M1col, &M1row);

int** matrix1col = malloc(M1col*sizeof(int*));

for(int i = 0; i< M1col; i++){

matrix1col[i] =malloc(M1row*sizeof(int));

}

for(int i = 0; i < M1col; i++){//FIRST MATRIX
	for(int j = 0; j < M1row; j++){	
		fscanf(fp, "%d", &value);
		matrix1col[i][j]= value;

	}


}

fscanf(fp, "%d %d\n", &M2col, &M2row);//SECOND MATRIX




int** matrix2col = malloc(M2col*sizeof(int*));

for(int i = 0; i< M2col; i++){

matrix2col[i] =malloc(M2row*sizeof(int));

}

for(int i = 0; i < M2col; i++){
	for(int j = 0; j < M2row; j++){	
		fscanf(fp, "%d", &value);
		matrix2col[i][j]= value;

	}


}

if(M1row!=M2col){
printf("bad-matrices");
return 0;
}

int sum=0;

int** matrix = malloc(M1col*sizeof(int*));//FINAL MATRIX

for(int i = 0; i< M1col; i++){

matrix[i] =malloc(M2row*sizeof(int));

}




for (int c = 0; c < M1col; c++) {
      for (int d = 0; d < M2row; d++) {
        for (int k = 0; k < M2col; k++) {
          sum = sum + ((matrix1col[c][k])*(matrix2col[k][d]));

        }

        matrix[c][d] = sum;

        sum = 0;
      }



    }



for(int i = 0; i < M1col; i++){
	for(int j = 0; j < M2row; j++){	

	printf("%d\t",matrix[i][j]);

	}
printf("\n");

}








fclose(fp);

return 0;

}//end main




