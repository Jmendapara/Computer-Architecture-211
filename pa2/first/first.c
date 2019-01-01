#include<stdio.h>
#include<stdlib.h>



double** transpose(double**, int, int);

double** multiply(double**, double**, int, int, int, int);

double** inverse(double**,int);



/////////////////////////////////////////////////

double **X = NULL;
double **Y = NULL;
double **Xtrans = NULL;
double **Xmul = NULL;
double **Inverse = NULL;
double **W = NULL;
double **Test = NULL;
double **RESULT = NULL;

double ** inverse(double** A, int n){


double **AUG = malloc(n*sizeof(double*)); 

	for(int i = 0; i< n; i++){ 
 
	AUG[i] = malloc((n*2)*sizeof(double));

	}

for(int i = 0;i < n; i++){
	for(int j = 0; j< n*2; j++){
		AUG[i][j] = 0.0;
	}

}


for(int i = 0;i < n; i++){
	for(int j = 0; j< n; j++){
		AUG[i][j] = A[i][j];
	}

}


for(int i = 0 ;i <n; i++){
		AUG[i][n+i] = 1.0;

}



for(int i = 0; i < n; i++){
	int j = 0;
	while(j< i+1){

		if(i==j){

			if(AUG[i][j]!=1.0)
				   {	
				double temp = AUG[i][j];
				for(int k = 0; k< n*2;k++){
					AUG[i][k]= AUG[i][k] / temp;

					    }
				}
			else{  }
			
			}

		else{	

			if(AUG[i][j]!=0.0)
				{
				double temp2 = AUG[i][j];
				for(int k = 0; k< n*2;k++){
					AUG[i][k]= AUG[i][k] - (temp2*AUG[j][k]);

					}
				
				}

			else {	}


		}


		j++;

		}


}




for(int i = n-1; i >= 0; i--){
	int j = n-1;
	while(j>0){

		if(i==j){	
			
			}

		else{	

			if(AUG[i][j]!=0.0)
				{
				double temp2 = AUG[i][j];
				for(int k = 0; k< n*2;k++){
					AUG[i][k]= AUG[i][k] - (temp2*AUG[j][k]);

					}
				
				}

			else {	}


		}


		j--;

		}


}




double **FINAL = malloc(n*sizeof(double*)); 

	for(int i = 0; i< n; i++){ 
 
	FINAL[i] = malloc((n)*sizeof(double));

	}

for(int i = 0;i < n; i++){
	for(int j = n; j< n*2; j++){
		FINAL[i][j-n] = AUG[i][j];
	}

}


return FINAL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



double ** multiply(double** A, double** B, int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
	
	double **MUL = malloc(rowFirst*sizeof(double*)); 

	for(int i = 0; i< rowFirst; i++){ 
 
	MUL[i] = malloc((columnSecond)*sizeof(double));

	}



	// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
	for(int i = 0; i < rowFirst; ++i)
	{
		for(int j = 0; j < columnSecond; ++j)
		{
			for(int k=0; k<columnFirst; ++k)
			{
				MUL[i][j] += A[i][k] * B[k][j];
			}
		}
	}


return MUL;

}

//////////////////////////////////////////////////

double** transpose (double** X, int r, int c)
{


double** TRANS = malloc(c*sizeof(double*));//TRANSPOSE X MATRIX


for(int i = 0; i< c; i++){ //TRANSPOSE X ALLOCATION

TRANS[i] = malloc(r*sizeof(double));

}


    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            TRANS[i][j] = X[j][i];
        }

    }


return TRANS;

}




/////////////////////////////////////////////

int main (int argc, char** argv){

int Xwidth;
int Xheight;
double tempval;

FILE *fr;
fr = fopen(argv[1], "r");



fscanf(fr,"%d",&Xwidth);
fscanf(fr,"%d",&Xheight);

/////////////////////////////////////////////////////////////////

X = malloc((Xheight*sizeof(double*))); //ORIGINAL X MATRIX

for(int i = 0; i< Xheight; i++){ //ORGINAL X ALLOCATION 

X[i] = malloc(((Xwidth)*sizeof(double))+sizeof(double));

}


Y = malloc(Xheight*sizeof(double*));//ORIGINAL Y MATRIX

for(int i = 0; i< Xheight; i++){ //ORIGINAL Y ALLOCATION

Y[i] = malloc(sizeof(double));

}

///////////////////////////////////////////////////////////////


for(int i = 0; i < Xheight; i++){
	
X[i][0] = 1.0;

}



for(int i = 0; i < Xheight; i++){//FIRST MATRIX AND CREATING MATRIX Y
	for(int j = 1; j < Xwidth+2; j++){	
		fscanf(fr,"%lf,",&tempval);
		if(j==Xwidth+1){
			Y[i][0]=tempval;}
		else{
		X[i][j]= tempval;

		}

	}

}



Xtrans = transpose(X, Xheight, Xwidth+1);



Xmul=multiply(Xtrans,X,Xwidth+1,Xheight,Xheight,Xwidth+1);



Inverse = inverse(Xmul,Xwidth+1);




W = multiply(Inverse,Xtrans,Xwidth+1,Xwidth+1,Xwidth+1,Xheight);
W = multiply(W,Y,Xwidth+1,Xheight,Xheight,1);



FILE *fr2;
fr2 = fopen(argv[2], "r");


int test = 0;
double tempvalue = 0;

fscanf(fr2,"%d",&test);



Test = malloc(test*sizeof(double*)); 

for(int i = 0; i< test; i++){ 

Test[i] = malloc(((Xwidth)*sizeof(double))+sizeof(double));

}


for(int i = 0; i < test; i++){
	
Test[i][0] = 1.0;

}


for(int i = 0; i < test; i++){
	for(int j = 1; j < Xwidth+1; j++){	
		fscanf(fr2,"%lf,",&tempvalue);
		Test[i][j]= tempvalue;

		}

	}





RESULT= multiply(Test,W,test,Xwidth+1,Xwidth+1,1);

for(int i = 0;i <test; i++){
		printf("%0.0lf\n",RESULT[i][0]);

}




fclose(fr);
fclose(fr2);

return 0;
}


















