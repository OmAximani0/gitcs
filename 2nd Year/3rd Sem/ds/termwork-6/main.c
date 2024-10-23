#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int id;
	struct Node *next;
	struct Node *prev;
} Node;

void addItemAtStart(Node **head, int id);
void addItemAtEnd(Node **head, int id);
void displayInventory(Node *head);
Node *searchForward(Node *head, int id);
Node *searchBackward(Node *tail, int id);
void freeInventory(Node *head);

void addItemAtStart(Node **head, int id)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->id = id;
	newNode->next = *head;
	newNode->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = newNode;
	}

	*head = newNode;
}

void addItemAtEnd(Node **head, int id)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->id = id;
	newNode->next = NULL;

	if (*head == NULL)
	{
		newNode->prev = NULL;
		*head = newNode;
		return;
	}

	Node *last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = newNode;
	newNode->prev = last;
}

void displayInventory(Node *head)
{
	if (head == NULL)
	{
		printf("Inventory is empty.\n");
		return;
	}

	Node *current = head;
	while (current != NULL)
	{
		printf("Item ID: %d\n", current->id);
		current = current->next;
	}
}

Node *searchForward(Node *head, int id)
{
	Node *current = head;
	while (current != NULL)
	{
		if (current->id == id)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}

Node *searchBackward(Node *tail, int id)
{
	Node *current = tail;
	while (current != NULL)
	{
		if (current->id == id)
		{
			return current;
		}
		current = current->prev;
	}
	return NULL;
}

void freeInventory(Node *head)
{
	Node *current = head;
	Node *next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int main()
{
	Node *inventory;
	int choice, id;

	do
	{
		printf("\n1. Insert at front\n");
		printf("2. Insert a new node at the end\n");
		printf("3. Display the list\n");
		printf("4. Search in the list (forward)\n");
		printf("5. Search in the list (backward)\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter Item ID to insert at front: ");
			scanf("%d", &id);
			addItemAtStart(&inventory, id);
			break;

		case 2:
			printf("Enter Item ID to insert at end: ");
			scanf("%d", &id);
			addItemAtEnd(&inventory, id);
			break;

		case 3:
			displayInventory(inventory);
			break;

		case 4:
			printf("Enter Item ID to search (forward): ");
			scanf("%d", &id);
			Node *foundForward = searchForward(inventory, id);
			if (foundForward)
			{
				printf("Item ID %d found in the list.\n", foundForward->id);
			}
			else
			{
				printf("Item ID %d not found.\n", id);
			}
			break;

		case 5:
		{
			Node *tail = inventory;
			while (tail && tail->next)
			{
				tail = tail->next;
			}
			printf("Enter Item ID to search (backward): ");
			scanf("%d", &id);
			Node *foundBackward = searchBackward(tail, id);
			if (foundBackward)
			{
				printf("Item ID %d found in the list.\n", foundBackward->id);
			}
			else
			{
				printf("Item ID %d not found.\n", id);
			}
		}
		break;

		case 6:
			freeInventory(inventory);
			printf("Exiting the program. Memory freed.\n");
			break;

		default:
			printf("Invalid choice. Please enter a valid option.\n");
			break;
		}
	} while (choice != 6);

	return 0;
}
