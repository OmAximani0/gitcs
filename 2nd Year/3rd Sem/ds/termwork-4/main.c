#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int);
void dequeue();
void display();

int main() {
	int choice = 0;
	int element;

	while (choice != 4) {
		// printf("REAR: %d, FRONT: %d", rear, front);
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", & choice); switch (choice) {
			case 1:
				printf("\tEnter a number: ");
				scanf("%d", &element);
				enqueue(element);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\tWrong Choice\n");
		}
	}
}


void enqueue(int ele)
{
	if(rear==MAX-1)
	{
		printf("\tQueue overflow\n");
	}
	else
	{
		rear=rear+1;
		if(front == -1) front = 0;
		queue[rear]=ele;
		printf("\t%d inserted into the queue.\n", ele);
	}
}

void dequeue()
{

	int dele;
	if(front > rear)
	{
		printf("\tQueue underflow\n");
	}
	else
	{
		dele=queue[front];
		front++;
	}
	printf("\tDeleted element : %d\n", dele);
}


void display()
{
	int i;
	if(front > rear || front == -1)
	{
		printf("\tQueue underflow\n");
	}
	else
	{
		printf("\t[ ");
		for (i=front; i<=rear; i++)
			printf("%d ", queue[i]);
		printf("]\n");
	}
}
