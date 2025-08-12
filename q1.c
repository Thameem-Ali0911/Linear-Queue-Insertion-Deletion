#include<stdio.h>
#define SIZE 20
int q[SIZE];
int h=-1;
int t=-1;

void enq()
{
	int val;
	if(t == SIZE-1)
    {
	   printf("Queue is Full\n");
	   return;
	}
	if(h == -1)
    {
	  h=0;
    }
	t++;
	
	printf("Enter the value to be inserted : ");
	scanf("%d",&val);
	
	q[t]=val;
	printf("value Inserted to Queue");
	printf("\n");	
}
void deq()
{
    if(h == -1 || h > t)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d deleted from Queue\n", q[h]);
    for(int i = h; i < t; i++)
    {
        q[i] = q[i + 1];
    }
    t--;
    if(t < h)
    {
        h = -1;
        t = -1;
    }
}
void display()
{
	if (h == -1 || h > t)
    {
	    printf("Queue is Empty\n");
	    return;
	}
	printf("Queue : ");
	for(int i = h;i <= t;i++)
	    printf("%d ",q[i]);
	printf("\n");
}
void main()
{
	int choice;
	do
    {
        printf("Enter choice \n 1 : Enqueue \n 2 : Dequeue \n 3 : Display \n 4 : Exit \n");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: enq(); break;
            case 2: deq(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
}