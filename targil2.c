#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* make(int data, Node* next)
{
    Node* p = malloc(sizeof(Node));
    p->data = data;
    p->next = next;
    p->prev = NULL;
    return p;
}

void destroy(Node* p)
{
    if (!p)
    {
        return;
    }

    {
        Node* next = p->next;
        free(p);
        destroy(next);
    }
}

Node* find(Node* head, int value)
{
    if (!head || head->data == value) {
        return head;
    }

    return find(head->next, value);
}

void print(Node* head)
{
    if (!head) {
        return;
    }

    printf("%d ", head->data);
    print(head->next);
}

int main()
{
    Node *ptr = 0;
    Node *head = make(5, 0);
    int i;

    for (i = 0; i < 10; ++i) {
        head = make(i+10, head);
    }
    print(head);

    ptr = find(head, 13);
    if (ptr) {
        ptr->data = 1337;
    }
    
    print(head);

    
    destroy(head);
}