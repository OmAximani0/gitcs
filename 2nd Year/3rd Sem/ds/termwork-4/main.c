#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();

int main() {
	int choice = 0;
	int element;

	while (choice != 4) {
		//printf("%d, %d", front, rear);
		printf("\n1.Enqueue\t2.Dequeue\n3.Display\t4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				enqueue();
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

void enqueue()
{
	if(rear==SIZE-1)
	{
		printf("\tQueue overflow\n");
	}
	else
	{
		int element;
		printf("\tEnter a number: ");
		scanf("%d", &element);
		rear=rear+1;
		if(front == -1) front = 0;
		queue[rear]=element;
		printf("\t%d inserted into the queue.\n", element);
	}
}

void dequeue()
{

	int dele;
	if(front > rear)
	{
		printf("\tQueue underflow\n");
		return;
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
		return;
	}
	else
	{
		printf("\t[ ");
		for (i=front; i<=rear; i++)
			printf("%d ", queue[i]);
		printf("]\n");
	}
}
