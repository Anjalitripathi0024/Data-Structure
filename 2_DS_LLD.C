#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>

struct node
{ int data;
  struct node *nxt;
}*head,*newnode,*prenode,*ptr;

void llmake()
{ int i=1;
  char j;
  head=(struct node *)malloc(sizeof(struct node));
  printf("Input data for node %d : ",i);
  scanf("%d",&head->data);
  head->nxt=NULL;
  prenode=head;
  printf("\tWant to enter more ? (y/n) : ");
  scanf("%s",&j);
  while(j=='y')
  { i++;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data for node %d : ",i);
    scanf("%d",&newnode->data);
    newnode->nxt=NULL;
    prenode->nxt=newnode;
    prenode=newnode;
    printf("\tWant to enter more ? (y/n) : ");
    scanf("%s",&j);
  }
}

void displayll()
{ int i=1;
  ptr=head;
  printf("\n\nLinked list is :-\n\n");
  printf("----------------------------------------------------\n");
  do
  { printf("Node - %d | Data - %d | Address - %d |  Next - %d \n",
    i,ptr->data,ptr,ptr->nxt);
    printf("----------------------------------------------------\n");
    ptr=ptr->nxt;
    i++;
    delay(750);
  }while(ptr!=NULL);
}

int deletion()
{ int del;
  char c;
  do
  { printf("\n\nEnter data to delete : ");
    scanf("%d",&del);
    prenode=head;
    do
    { if(head==NULL)
      { printf("\nList is empty !!!\n");
	return 0;
      }
      else if(prenode->data==del)
      { head=prenode->nxt;
	printf("Node with matching data deleted successfully.\n");
	if(head==NULL)
	{ printf("List is now empty !\n");
	  return 0;
	}
	break;
      }
      else if((prenode->nxt)->data==del)
      { prenode->nxt=(prenode->nxt)->nxt;
	printf("Node with matching data deleted successfully.\n");
	if(head==NULL)
	{ printf("List is now empty !\n");
	  return 0;
	}
	break;
      }
      else
      { prenode=prenode->nxt;
	if(prenode==NULL)
	{ printf("\nElement not found !!!\n"); }
      }
    }while(prenode!=NULL);
    displayll();
    printf("Want to delete more ? (y/n) : ");
    scanf("%s",&c);
  }while(c=='y');
  return 0;
}

void main()
{ clrscr();
  printf("Enter data :-\n\n");
  llmake();
  displayll();
  deletion();
  printf("Press any key to EXIT ...");
  getch();
}