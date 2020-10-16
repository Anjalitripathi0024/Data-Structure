#include<stdio.h>

int cqueue[5],front=-1,rear=-1;

void insert()
{ int data;
  if(front==0&&rear==4||front==rear+1)
  { printf("\n --------------------------------------------");
    printf("\n  Overflow !!!"); }
  else
  { printf("\n\n Enter Data : ");
    scanf("%d",&data);
    if(front==-1)
    { front=rear=0; }
    else if(rear==4)
    { rear=0; }
    else
    { rear=rear+1; }
    cqueue[rear]=data;
    printf("\n --------------------------------------------");
    printf("\n  Data inserted successfully.");
  }
  printf("\n --------------------------------------------");
}

void deletehead()
{ printf("\n --------------------------------------------");
  if(front==-1)
  { printf("\n  C-Queue is EMPTY !!!"); }
  else
  { if(front==rear)
    { front=rear=-1; }
    else if(front==4)
    { front=0; }
    else
    { front++; }
    printf("\n  Deleted successfully.");
  }
  printf("\n --------------------------------------------");
}

void displayqueue()
{ int i,j=1;
  printf("\n --------------------------------------------");
  if(front==-1)
  { printf("\n  C-Queue is EMPTY !!!"); }
  else
  { if(front<=rear)
    { for(i=front;i<=rear;i++)
      { printf("\n  Node %d : %d",j,cqueue[i]);
	    j++;
      }
    }
    else
    { j=1;
      for(i=front;i<=4;i++)
      { printf("\n  Node %d : %d",j,cqueue[i]);
	    j++;
      }
      for(i=0;i<=rear;i++)
      { printf("\n  Node %d : %d",j,cqueue[i]);
	    j++;
      }
    }
  }
  printf("\n --------------------------------------------");
}

int calcount()
{ int i,j=0;
  if(front==-1)
  { j=0; }
  else
  { if(front<=rear)
    { for(i=front;i<=rear;i++)
      { j++; }
    }
    else
    { for(i=front;i<=4;i++)
      { j++; }
      for(i=0;i<=rear;i++)
      { j++; }
    }
  }
  return j;
}

int main()
{ int c=0,d,count=0;
  do
  { count=calcount();
    printf("\n\n\t -: Array Circular Queue Menu :-");
    printf("\n\n 1. Enter Data           ----------");
    printf("\n 2. Display Queue        | Status |");
    printf("\n 3. Delete Head          | (%d/5)  |",count);
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
      default : printf("\n --------------------------------------------");
		printf("\n  Invalid input !!!");
		printf("\n --------------------------------------------");
    }
  }while(c!=4);
  printf("\n\n Press any key to EXIT...");
  return 0;
}
