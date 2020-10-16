#include<stdio.h>
#include<stdlib.h>
 
struct node
{ int data;
  struct node *nxt;
}*ptr,*rear=NULL;

void insert()
{ int dt;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
  { printf("\n -----------------------------------------------");
    printf("\n  Overflow !!!");
  }
  else 
  { if(rear==NULL)
    { printf("\n\n Enter Data : ");
      scanf("%d",&dt);
      ptr->data=dt;
      rear=ptr;
	  ptr->nxt=rear;
    }
    else
    { printf("\n\n Enter Data : ");
      scanf("%d",&dt);
      ptr->data=dt;
	  ptr->nxt=rear->nxt;
      rear->nxt=ptr;
      rear=ptr;
    }
    printf("\n -----------------------------------------------");
    printf("\n  Data inserted successfully.");
  }
  printf("\n -----------------------------------------------");
}

void deletehead()
{ printf("\n -----------------------------------------------");
  if(rear==NULL)
  { printf("\n  C-Queue is EMPTY !!!"); }
  else
  { if(rear->nxt==rear)
    { ptr=rear;
      rear=NULL;
    }
    else
    { ptr=rear->nxt;
      rear->nxt=(rear->nxt)->nxt;
    }
    printf("\n  Deleted successfully.");
  }
  printf("\n -----------------------------------------------");
}

void displayqueue()
{ struct node *p;
  int i=1;
  printf("\n -----------------------------------------------");
  if(rear==NULL)
  { printf("\n  C-Queue is EMPTY !!!"); }
  else
  { p=rear->nxt;
    do
    { printf("\n  Node %d : %d",i,p->data);
      p=p->nxt;
      i++;
    }while(p!=rear->nxt);
  }
  printf("\n -----------------------------------------------");
}

int calcount()
{ int i=0;
  struct node *p;
  if(rear==NULL)
  { i=0; }
  else
  { p=rear->nxt;
    do
    { p=p->nxt;
      i++;
    }while(p!=rear->nxt);
  }
  return i;
}

int main()
{ int c=0,d,count=0;
  do
  { count=calcount();
    printf("\n\n     -: Linked List Circualar Queue Menu :-");
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
      default : printf("\n --------------------------------------------------------");
		printf("\n  Invalid input !!!");
		printf("\n --------------------------------------------------------");
    }
  }while(c!=4);
  printf("\n\nPress any key to EXIT...");
  return 0;
}
