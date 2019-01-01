#include<stdio.h>
#include<stdlib.h>

int main (int argc, char** argv){
int size;
int value;

FILE *fp;

fp = fopen(argv[1], "r");

fscanf(fp, "%d\n",&size);//gets the size of matrix

if(size<=0){
printf("not-magic");
return 0;
}


int** matrix = malloc(size*sizeof(int*));//allocate space for matrix

for(int i = 0; i<size; i++){

matrix[i] =malloc(size*sizeof(int));

}

for(int i = 0; i < size; i++){
	for(int j = 0; j < size; j++){	
		fscanf(fp, "%d", &value);
		matrix[i][j]= value;


	}

}


int max = size*size;

int* array = malloc(max*sizeof(int));//put all elements in an array to check for stufff

int count = 0;

for(int j = 0; j < size; j++){

	for(int i = 0; i < size; i++){
	array[count]= matrix[j][i];
	if(array[count]>(size*size)){//check all elements are below n^2
		printf("not-magic");
		return 0;
		}

	count++;

	}


}




for (int i=0;i<max;i++){
	int j;
	for(j = 0; j < i; j++) {
		if(array[i]==array[j]){
		printf("not-magic");//check for duplicates
		return 0;
		}
	}
}




int total=0;
int temp=0;


for(int i = 0; i < size; i++){

total = total + matrix[0][i];

}





////////////////////////////////////horizontal checks

for(int j = 0; j < size; j++){

	for(int i = 0; i < size; i++){
	temp = temp + matrix[j][i];

	}
	
if(temp!=total){
printf("not-magic");
return 0;}

temp=0;

}


///////////////////////////////////////////vertical checks

for(int j = 0; j < size; j++){

	for(int i = 0; i < size; i++){
	temp = temp + matrix[i][j];

	}
	
if(temp!=total){
printf("not-magic");
return 0;}

temp=0;
}



/////////////////////////////////////////////////diagonal 

for(int i = 0; i < size; i++){
	temp = temp + matrix[i][i];

	}
	
if(temp!=total){
printf("not-magic");
return 0;}

temp = 0;


/////////////////////////////////////////////
for(int i = 0; i < size; i++){
	temp = temp + matrix[size-1-i][size-1-i];

	}
	
if(temp!=total){
printf("not-magic");
return 0;}

temp = 0;



printf("magic");







return 0;

}
