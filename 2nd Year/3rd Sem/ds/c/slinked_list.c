#include <stdio.h>

struct Node
{
    struct Node *next;
    int val;
};

void Nprint(struct Node *head)
{
    struct Node *i = head;

    // Iterate till the last node, last node is the node which `next` pointer is NULL
    while (i != NULL)
    {
        printf("%d -> ", i->val);
        i = i->next;
    }

    // Just to show the end of list
    printf("NULL\n");
}

int main(int argc, char *args[])
{
    // Create 3 different nodes
    struct Node n1 = {.val = 5};
    struct Node n2 = {.val = 6};
    struct Node n3 = {.val = 7};

    // Connect the three individual nodes
    n1.next = &n2;
    n2.next = &n3;

    // Display the values of nodes
    Nprint(&n1);

    return 0;
}