#include<stdio.h>
#include<stdlib.h>

struct listnode{//array nodes
int value;
struct listnode * next;};

void traverse(struct listnode*);
void cleanup(struct listnode*);
void sort(struct listnode*); 

/////////////////////////////////////////////////

void traverse(struct listnode* list){

struct listnode* t1= list;

while(t1!=NULL){
	printf("%d\t",t1->value);
	t1=t1->next;
}


}

///////////////////////////////////////////////////
void cleanup(struct listnode* list){

struct listnode* t1 = list;
struct listnode* t2 = NULL;

while(t1!=NULL){
t2=t1;
t1=t1->next;
free(t2);
}

}
////////////////////////////////////////////////////

void swap(struct listnode *a, struct listnode *b){
int temp = a->value;
a->value=b->value;
b->value=temp;
}

//////////////////////////////////////////////////// to sort a list

void sort(struct listnode* head)
{
	struct listnode *start = head;
	struct listnode *ptr;
	struct listnode *min;

	while(start->next)
	{
		min = start;
		ptr = start->next;
		
		while(ptr){
			if( min->value > ptr->value ){
			min = ptr;
			}
		ptr = ptr->next;
		}
	swap(start,min);
	start = start->next;
	}
} 

//////////////////////////////////////////////////


int main (int argc, char** argv){

int sizeofarray;

FILE *fr;
fr = fopen(argv[1], "r");

fscanf(fr,"%d",&sizeofarray);

if(sizeofarray==0){
printf("0");
return 0;
}

int num;

struct listnode * head = NULL;//evenarray
struct listnode * head2 = NULL;//odd array

for(int i= 0; i < sizeofarray; i++){



	if(sizeofarray==1){
	fscanf(fr,"%d",&num);
	printf("%d\t",num);
	return 0;
	}

	fscanf(fr,"%d",&num);

	struct listnode* temp = (struct listnode*)malloc(1*sizeof(struct listnode));

	if(num%2==0){
	temp->value=num;
	temp->next=head;
	head=temp;
	}

	else{
	temp->value=num;
	temp->next=head2;
	head2=temp;
	}
}

struct listnode* final = head;

sort(head);
sort(head2);

while(final->next!=NULL){
final = final->next;
}

final->next = head2;

traverse(head);

cleanup(head);

fclose(fr);

return 0;
}


















