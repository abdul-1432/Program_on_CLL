// program for implementation of single linked list and operations on it
int nodeCount=0;
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *tail, *neu, *temp;


void create_node();
void remove_node();
void display_list();
void insert_beginning();
void insert_end();
void insert_position();
void delete_beginning();
void delete_end();
void delete_position();

void create_node()
{
	nodeCount++;
	neu = (struct node *) malloc(sizeof(struct node));
	printf("enter data ");
	scanf("%d",&neu->data);
	neu->link=NULL;
}

void remove_node()
{
	printf("\n %d is being delete",neu->data);  // showing data that is getting removed
	free(neu);			// deallocate memory of neu
	neu=NULL;           // replace address of neu with NULL
	nodeCount--;
}

void display_list()
{
	if (tail==NULL)    // checking for underflow (empty list)
	{
		printf("List is underflow...no nodes to display");
	}
	else
	{
		printf("\n Linked List values are\n");
		temp=tail->link;   // last->link contains the address of first node
		do
		{
			printf("\t%u(%d,%u)",temp,temp->data,temp->link);
			temp=temp->link;    // to move to next node
		}while(temp!=tail->link);
	}
}

void insert_beginning()
{
	create_node();
	if (tail==NULL)
	{
		tail=neu;
		tail->link=tail;
	}
	else
	{
		neu->link = tail->link;
		tail->link=neu;
	}
}

void insert_end()
{
	create_node();
	if (tail==NULL)
	{
		tail=neu;
		tail->link=tail;
	}
	else
	{
		neu->link = tail->link;
		tail->link=neu;
		tail=neu;
	}
}
	
void insert_position()
{
    int pos,cp;
    if (tail==NULL)
    {
    	printf("no nodes in the list...try choice 1");
	}
	else
	{
		printf("insert new node at which position: ");
		scanf("%d",&pos);  		
		temp=tail->link;   // temp will have first node addr
		cp=1;
		while(cp<pos-1)
		{
			temp=temp->link;   // to move to next node
			cp++;
		}
		create_node();
		neu->link=temp->link;
		temp->link=neu;
	}
}

void delete_beginning()
{
	if (tail==NULL)
		printf("list is empty...no nodes to delete");
	else
	{
		neu=tail->link;		// this will denote the first node as neu
		tail->link=neu->link;  
		neu->link=NULL;     // break the link of neu
		remove_node();
	}
}
	
void delete_end()
{
	if (tail==NULL)
		printf("list is empty...no nodes to delete");
	else if (tail->link==tail)    // if list has only one node
	{
		printf("\n one and only last node is being delete");
		neu=tail;
		tail=NULL;
		remove_node();
	}
	else
	{
		// to move to last but one node
		temp=tail->link;
		while(temp->link!=tail)   // checking next node is last(tail) node or not
		{
			temp=temp->link;
		}
		neu=temp->link;   // making last(tail) node as neu
		temp->link=tail->link;
		tail=temp;
		neu->link=NULL;  // break the link to the last node
		remove_node();
	}
}

void delete_position()
{
    int pos,cp;
    if (tail==NULL)
    	printf("no nodes in the list to delete");
	else
	{
		printf("delete new node at which position: ");
		scanf("%d",&pos);  		
		temp=tail->link;  // pointing temp to first node 
		cp=1;
		while(cp<pos-1)
		{
			temp=temp->link;   // to move to next node
			cp++;
		}
		neu=temp->link;		// make next node as neu
		temp->link=neu->link;   
		neu->link=NULL;  
		remove_node();
	}
}

void main()
{
	char ch;
	int cho;
	neu=tail=temp=NULL;
	do
	{
		printf("\n\n*** Circular Single Linked List Operations ***");
		printf("\n 1 Add node at beginning");
		printf("\n 2 Add node at end");
		printf("\n 3 Add node at given position");
		printf("\n 4 Remove node from beginning");
		printf("\n 5 Remove node from end");
		printf("\n 6 Remove node from given position");
		printf("\n 7 List the nodes");
		printf("\n 8 Exit");
		printf("\n Enter your choice (1-8) : ");
		scanf("%d",&cho);
		if (cho==1)
			insert_beginning();
		else if (cho==2)
			insert_end();
		else if (cho==3)
			insert_position();
		else if (cho==4)
			delete_beginning();
		else if (cho==5)
			delete_end();
		else if (cho==6)
			delete_position();
		else if (cho==7)
			display_list();
		else if (cho==8)
			printf("\n Thank you");
		else
			printf("Invalid choice...retry");
	}while(cho!=8);
	printf("\n* * * End of Program * * *");
}

