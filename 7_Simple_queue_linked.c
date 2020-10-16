#include<stdio.h>
#include<stdlib.h>

struct node
{ int data;
  struct node *next;
}*front,*rear,*ptr;

void insert()
{ int dt;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
  { printf("\n ------------------------------------------------");
    printf("\n Overflow !!!");
  }
  else
  { printf("\n\n Enter Data : ");
    scanf("%d",&dt);
    ptr->data=dt;
    if(front==NULL)
    { front=ptr;
      rear=ptr;
      front->next=NULL;
      rear->next=NULL;
    }
    else
    { rear->next=ptr;
      rear=ptr;
      rear->next=NULL;
    }
    printf("\n ------------------------------------------------");
    printf("\n  Data inserted successfully.");
  }
  printf("\n ------------------------------------------------");
}

void deletehead()
{ printf("\n ------------------------------------------------");
  if(front==NULL)
  { printf("\n  Queue is EMPTY !!!");  }
  else
  { ptr=front;
    front=front->next;
    free(ptr);
    printf("\n  Deleted successfully.");
  }
  printf("\n ------------------------------------------------");
}

void displayqueue()
{ int i=1;
  ptr=front;
  printf("\n ------------------------------------------------");
  if(front==NULL)
  { printf("\n  Queue is EMPTY !!!"); }
  else
  { while(ptr!=NULL)
    { printf("\n  Node %d : %d",i,ptr->data);
      ptr=ptr->next;
      i++;
    }
  }
  printf("\n ------------------------------------------------");
}

int calcount()
{ int i=0;
  struct node *ptr;
  ptr=front;
  if(front==NULL)
  { i=0; }
  else
  { while(ptr!=NULL)
    { i++;
      ptr=ptr->next;
    }
  }
  return i;
}

int main()
{ int c=0,d,count=0;
  do
  { count=calcount();
    printf("\n\n \t-: Linked List Queue Menu :-");
    printf("\n\n 1. Enter Data           ----------");
    printf("\n 2. Display Queue        | Status |");
    printf("\n 3. Delete Head          | (%d/NA) |",count);
    printf("\n 4. Quit                 ----------");
    printf("\n\n Enter choice number : ");
    scanf("%d",&c);
    switch(c)
    { case 1 : insert();
	       break;
      case 2 : displayqueue();
	       break;
      case 3 : deletehead();
	       break;
      case 4 : break;
      default : printf("\n -------------------------------------------------");
		printf("\n  Invalid input !!!");
		printf("\n -------------------------------------------------");
    }
  }while(c!=4);
  printf("\n\n Press any key to EXIT...");
  return 0;
}
