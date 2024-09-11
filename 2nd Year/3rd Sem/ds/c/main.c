#include <stdio.h>

typedef struct node
{
    struct node *next;
    int val;
} Node;

struct SinglyLinkedList
{
    Node *head;
    int length;
};

typedef struct SinglyLinkedList SLL;

void Nprint(Node *head)
{
    Node *i = head;

    // Iterate till the last node, last node is the node which `next` pointer is NULL
    while (i != NULL)
    {
        printf("%d -> ", i->val);
        i = i->next;
    }

    // Just to show the end of list
    printf("NULL\n");
}

Node *add_node(SLL *ll, Node *node)
{
    Node *temp = ll->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    return node;
}

int main(int argc, char *args[])
{
    SLL ll;

    // Create 3 different nodes
    Node n1 = {.val = 5};
    Node n2 = {.val = 6};
    Node n3 = {.val = 7};

    // Connect the three individual nodes
    n1.next = &n2;
    // n2.next = &n3;

    ll.head = &n1;

    // Display the values of nodes
    Nprint(ll.head);

    add_node(&ll, &n3);
    Nprint(ll.head);

    return 0;
}