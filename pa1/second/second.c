#include<stdio.h>
#include<stdlib.h>

typedef struct listnode{//array nodes
int value;
struct listnode * next;} listnode;

void traverse(struct listnode*);
void sort(struct listnode*); 
listnode* doubles(struct listnode*);

////////////////////////////////////////////////////////

void swap(struct listnode *a, struct listnode *b){
int temp = a->value;
a->value=b->value;
b->value=temp;
}


//////////////////////////////////////////////////////////

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
///////////////////////////////////////////////////////
listnode* doubles(listnode* mainhead) { 
struct listnode* ptr2=mainhead->next;
struct listnode* ptr1=mainhead;
struct listnode* prevnode=ptr1;
  while(ptr1!=NULL){
    ptr2=ptr1->next;
    prevnode=ptr1;
    while(ptr2!=NULL){
     
	 if(ptr1->value==ptr2->value){
        prevnode->next=ptr2->next;
      }
     
	 prevnode=ptr2;
     
	 ptr2=ptr2->next;
    }
   
      ptr1=ptr1->next;
  }
  return mainhead;
};

/////////////////////////////////////////////////////////////

void traverse(struct listnode* list){

struct listnode* t1= list;

while(t1!=NULL){
printf("%d\t",t1->value);
t1=t1->next;
}


};




//////////////////////////////////////////////////////////////////

listnode* delete(int value,listnode* head){
  
if(head->value == value){
head = head-> next; 
}
 
  struct listnode* point=head->next;
  struct listnode* prev=head;
  while(point!=NULL){
    if(point->value==value){
      prev->next=point->next;
    }
    prev=point;
    point=point->next;
  }
  return head;
};

//////////////////////////////////////////////////////////////////


int main (int argc, char** argv){

FILE *fr;
fr = fopen(argv[1], "r");

if(fr==NULL)//if the file doesn't exist
{
	printf("error"); 
	return 0;
}


fseek (fr, 0, SEEK_END);//check if file is empty
int size = ftell(fr);

if (size==0) 
{
	printf("0\n");
	return 0;
}

/////////////////////////////////////////////////////////// basic checks end

struct listnode* head=NULL;
char id;
int number;
FILE *fp;
fp = fopen(argv[1], "r");

while(fscanf(fp, "%c %d\n", &id, &number)==2){

if(id == 'i')
{
	struct listnode* node = (struct listnode*)malloc(1*sizeof(struct listnode));
	node->next=head;
	node->value = number;
	head=node;
	head = doubles(head);
}

else if(id == 'd')
{
	if(head==NULL)
	{
	}

	else if(head->next==NULL && head->value==number)
	{
		head = NULL;
	}

	else
	{
		head = delete(number,head);
	}

}


}//end while

if(head!=NULL)
{
sort(head);
}

int listsize = 0;

if(head==NULL)
{
	printf("0\n");
	return 0;
}

struct listnode* ctr=head;

while(ctr!=NULL)//listsize 
{
	listsize++;
	ctr=ctr->next;
}

printf("%d\n",listsize);

traverse(head);

fclose(fp);

return 0;

}//end main




