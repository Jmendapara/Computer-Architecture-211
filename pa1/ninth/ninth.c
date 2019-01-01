#include<stdio.h>
#include<stdlib.h>

typedef struct node{//array nodes
int height;
int value;
struct node * right;
struct node * left;
} node;

void search(int);
void insert(int);

int nextnode(struct node*);

struct node* delete(int,struct node*);

void inorderTraversal(struct node*);

void cleanup(struct node*);

int recurselevel(int,struct node*, int);


struct node *head = NULL;
  


///////////////////////////////////////////////////////////////////////

int recurselevel(int number,struct node *temp, int level) 
{ 
    if (temp == NULL) 
        return 0; 
  
    if (temp->value == number) 
        return level; 
  
    int next = recurselevel(number,temp->left, level+1); 
    if (next != 0) 
        return next; 
  
    next = recurselevel(number,temp->right, level+1); 
    return next; 
} 

/////////////////////////////////////////////////////
void cleanup(struct node* head)
{
      if(head==NULL)
      return;
      cleanup(head->left);
      head->left=NULL;
      cleanup(head->right);
      head->right=NULL;
      free(head); 
      head=NULL; 
	return;
}


////////////////////////////////////////////////


void inorderTraversal(struct node* head){
    if(head == NULL){
        return;
    }
    inorderTraversal(head->left);
	head->value=recurselevel(head->value,head,1);
    inorderTraversal(head->right);
};


/////////////////////////////////////////

struct node *  delete(int number,struct node* main)
{
	if(main==NULL)
	{
	printf("fail\n");
	return NULL;
	}
        
        if(main->value==number)
        {
                if((main->left==NULL) && (main->right==NULL))//both values are null
                {
                   struct node* nodetodel=main;
                   main=main->right;
                   free(nodetodel);
                   printf("success\n");
                   return main;
                }

		else if(main->right==NULL)
                {
                      struct node*nodetodel = main;
                      main=main->left;
                      printf("success\n");
                      free(nodetodel);
                      return main;
                }

                else if(main->left==NULL)
                {
                      struct node *nodetodel=main;
                      main=main->right;
                      printf("success\n");
                      free(nodetodel);
                      return main; 
                }  
                
		
		else{ 
                      main->value=nextnode(main->right);
                      main->right=delete(main->value,main->right);
                      return main;}

          
         } 
         else if(main->value>number)
         {
                main->left= delete(number,main->left);
         }
         else 
         {
                 main->right=delete(number,main->right);
         }
                  

                 return main;

};


/////////////////////////////////////////////////////////

int nextnode(struct node* root)
{
   struct node *temp=root;
   int i=2147483647;
   while(temp!=NULL)
  {
    if(temp->value<i)
    {
      i=temp->value;
    }
    temp=temp->left;
  }  
    return i;
}
//////////////////////////////////////////////
void insert(int number){
struct node* prev = NULL;
struct node *ptr = head;

    int leftright = 0;
    
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->height=1;

	
if(head!=NULL){
    while(ptr != NULL){
        prev = ptr;
        if(ptr->value == number){
            printf("duplicate\n");
		return;
        }
        else if(number < ptr->value){
            ptr = ptr->left;
            leftright = -1;
		temp->height++;
        } else{
            ptr = ptr->right;
            leftright = 1;
		temp->height++;
        }
    }

}

    temp->left = NULL;
    temp->value = number;
    temp->right= NULL;

    if(prev == NULL){
        head = temp;
    }

    else if(leftright<0){
        prev->left = temp;
    } else{
        prev->right = temp;
    }

int templevel = recurselevel(number,head,1);
printf("inserted %d\n",templevel);


};


////////////////////////////////////////////
void search(int number){

   struct node* ptr = head;

    if(head == NULL){
        printf("absent\n");
	return;
    }

    else{
        while(ptr != NULL){
            if(ptr->value == number){
		int templevel = recurselevel(number,head,1);
		printf("present %d\n",templevel);
		return;
            }

            if(number< ptr->value){
                ptr = ptr->left;
            } 
		
		else{
                ptr = ptr->right;
            }
        }
	}

        if(ptr == NULL){
            printf("absent\n");
		return;

        } 



};
///////////////////////////////////////////////////////


int main(int argc, char** argv){


FILE *fp = fopen(argv[1],"r"); 

if(fp==NULL){//if the file doesn't exist
printf("error"); 
return 0;}

char id;
int number;

	while(fscanf(fp, "%c %d\n", &id, &number) == 2){

                if(id == 'i'){
			insert(number);
		}else if (id == 's'){
			search(number);
		}
		
		else{ 
			head = delete(number,head);
		}



}

cleanup(head);
  return 0;
}





