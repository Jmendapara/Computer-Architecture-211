#include<stdio.h>
#include<stdlib.h>

typedef struct node{//array nodes
struct node * right;
struct node * left;
int height;
int value;} node;

void insert(int);
void cleanup(struct node*);
void search(int);

////////////////////////////////////////////////

struct node *head = NULL;

void insert(int number){

struct node* prev = NULL;
struct node *ptr = head;

    int leftright = 0;
    
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->height=1;

	if(head == NULL){
	temp->height = 1;
	}
	
if(head!=NULL){
    while(ptr != NULL){
        prev = ptr;
        if(ptr->value == number){
            printf("duplicate\n");
		return;
        }
        else if(number > ptr->value){
            ptr = ptr->right;
            leftright = 1;
		temp->height++;
        } else{
            ptr = ptr->left;
            leftright = -1;
		temp->height++;
        }
    }

}

    temp->right = NULL;
    temp->left= NULL;
    temp->value = number;

    if(prev == NULL){
        head = temp;
    }

    else if(leftright<0){
        prev->left = temp;
    } else{
        prev->right = temp;
    }


printf("inserted %d\n",temp->height);


};

///////////////////////////////////////////
void cleanup(struct node* head)
{
      if(head==NULL)
      {return;}
      
	cleanup(head->left);
     	head->left=NULL;
	cleanup(head->right);
         head->right=NULL;
	free(head); 
         head=NULL; return;
}

////////////////////////////////////////////

void search(int number){

   struct node* ptr = head;

    if(head == NULL){
        printf("absent");
	return;
    }

    else{
        while(ptr != NULL){
            if(ptr->value == number){
		printf("present %d\n",ptr->height);
		return;
            }

            if(number > ptr->value){
                ptr = ptr->right;
            } 
		
		else{
                ptr = ptr->left;
            }
        }
	}

        if(ptr == NULL){
            printf("absent\n");

        } 



};


int main(int argc, char** argv){


FILE *fp = fopen(argv[1],"r"); 

char id;
int number;

if(fp==NULL){//if the file doesn't exist
printf("error"); 
return 0;}

	while(fscanf(fp, "%c %d\n", &id, &number) == 2){
       
                if(id == 'i'){
			insert(number);
		}else if (id == 's'){
			search(number);
		}
	}

cleanup(head);

  return 0;
}





