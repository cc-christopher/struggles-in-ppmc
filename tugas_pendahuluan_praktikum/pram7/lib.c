#include "lib.h"

/** push. Tambahkan new_data ke atas stack.
 *
 * @param stack pointer menuju stack.
 * @param new_data data baru untuk ditambahkan ke dalam stack.
 */
void push(Stack** stack, int new_data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    new_node->data = new_data;

    if ((*stack) == NULL) {
        new_stack->head = NULL;
        (*stack) = new_stack;
        new_node->next = NULL;
        (*stack)->head = new_node;
    }
    else {
        new_node->next = NULL;
        (*stack)->head = new_node;
    }


}

/**
* fungsi untuk mengurutkan isi stack
*
* @param head: pointer to pointer to head of the stack
*/
void sortStack(Stack **head)
{
    Node* current = (*head)->head;
    Stack* new_stack = (Stack *) malloc(sizeof(Stack));
    new_stack->head = NULL;
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    int max = -1;
    for (int i = 0; i < count; i++) {
        while (current != NULL) {
            if (current->data >= max) {
                max = current->data;
                current->data = -2;
                current = current->data;

                Node* new_sortnode = (Node *) malloc (sizeof(Node));
                new_sortnode->data = max;
                new_sortnode->next = new_stack->head;

                new_stack->head = new_sortnode;
            }
        }

    }
    (*head)->head = new_stack->head;
}

void print(Stack* stack)
{
    Node* current = stack->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
