#include<stdio.h>
#include<stdlib.h>

typedef struct listnode{
int value;
struct listnode *next;}listnode;

struct listnode* bucket[10000];

////////////////////////////////////////////////////////////////////////////////
void insert(int number){
	int key=0;

	if(number<0)//in case its negative
	{
		key = abs(number);
		key=key%10000;
	}
	else{key = number % 10000;}
        struct listnode *temp;
        for(temp = bucket[key]; temp != NULL; temp = temp -> next){
        	if(temp -> value == number){
                	printf("duplicate\n");
			return;}
        	}
        	struct listnode *newnode=(struct listnode*) malloc(sizeof(struct listnode));
                newnode -> value = number;
                newnode -> next = bucket[key];
                bucket[key] = newnode;
                printf("inserted\n");
	return;
}
/////////////////////////////////////////////////////////////////////////////////

void search(int number){
	int key=0;
	if(number<0){
	key=abs(number);
	key=key%10000;}

	else{
	key = number % 10000;}

	struct listnode *temp;
        for(temp = bucket[key]; temp != NULL; temp = temp -> next){

        	if(temp -> value == number){
                	printf("present\n");
			return;}


        }
        printf("absent\n");
	return;
}

///////////////////////////////////////////////////////////////////////

int main (int argc, char** argv){

char id;
int number;

for(int i = 0; i < 10000; i++){//initialize 
		bucket[i] = NULL;}

FILE *fp;

fp = fopen(argv[1], "r");

while(fscanf(fp, "%c %d\n", &id, &number)==2){

	if(id == 'i')
	{	
	insert(number);
	}

	else if(id == 's')
	{
	search(number);
	}

}//end while


fclose(fp);

return 0;

} 
