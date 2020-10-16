#include<stdio.h>
#include<conio.h>

int queue[5],front=-1,rear=-1;

void insert()
{ int data;
  if(rear==4)
  { printf("\n ------------------------------------");
    printf("\n  Overflow !!!"); }
  else if(front==-1&&rear==-1)
  { printf("\n\n Enter Data : ");
    scanf("%d",&data);
    front=rear=0;
    queue[rear]=data;
    printf("\n ------------------------------------");
    printf("\n  Data entered successfully.");
  }
  else
  { printf("\n\n Enter Data : ");
    scanf("%d",&data);
    rear++;
    queue[rear]=data;
    printf("\n ------------------------------------");
    printf("\n  Data entered successfully.");
  }
  printf("\n ------------------------------------");
}

void deletehead()
{ printf("\n ------------------------------------");
  if(front==-1&&rear==-1)
  { printf("\n  List is Empty !!!"); }
  else if(front==rear)
  { front=rear=-1;
    printf("\n  Deleted successfully.");
    printf("\n  List is Empty !!!");
  }
  else
  { front++;
    printf("\n  Deleted successfully.");
  }
  printf("\n ------------------------------------");
}

void displayqueue()
{ int i=1;
  printf("\n ------------------------------------");
  if(front==-1&&rear==-1)
  { printf("\n  List is Empty !!!"); }
  else
  { for(i=front;i<rear+1;i++)
    { printf("\n  Node %d : %d",i+1,queue[i]); }
  }
  printf("\n ------------------------------------");
}

int main()
{ int c=0,d,count=0;
  do
  { if(front==-1&&rear==-1)
    { count=0; }
    else
    { count=rear-front+1; }
    printf("\n\n\t -: Array Queue Menu :-");
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
      default : printf("\n ------------------------------------");
	            printf("\n\n  Invalid input !!!");
	            printf("\n ------------------------------------");
    }
  }while(c!=4);
  printf("\n\n Press any key to EXIT...");
  return 0;
}
