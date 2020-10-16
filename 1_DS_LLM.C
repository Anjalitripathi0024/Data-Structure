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

void displaycll()
{ int i=1;
  ptr=head;
  printf("\n\nLinked list is :-\n");
  do
  { printf("---------------------------------\n");
    printf("| Node | Data | Address |  Next |\n");
    printf("---------------------------------\n");
    printf("|  %d   |  %d   |   %d  |  %d |\n",i,ptr->data,ptr,ptr->nxt);
    printf("---------------------------------\n");
    if(ptr->nxt!=NULL)
    { printf("               |\n");
      printf("               v\n");
    }
    ptr=ptr->nxt;
    i++;
    delay(750);
  }while(ptr!=NULL);
}

void main()
{ clrscr();
  printf("LL creation :-\n\n");
  llmake();
  displaycll();
  printf("\nPress any key to EXIT...");
  getch();
}