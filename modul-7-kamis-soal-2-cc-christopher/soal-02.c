/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 7 - Stacks and Queues
*Percobaan        : 4
*Hari dan Tanggal : Kamis, 7 April 2022
*Nama (NIM)       : Christopher Chandra (18320033)
*Asisten (NIM)    : Gala Ramadhan Ilham Warno Putra (13218076)
*Nama File        : soal-02.c
*Deskripsi        : stacking of events on operasi aritmatika.
*/

#include<stdio.h>
#include<stdlib.h>

//tuliskan bentuk data stack/queue yang anda gunakan

int main() {
    typedef struct Node{
        int data;
        struct Node* next;
    }Node;

    typedef struct Stack {
        Node* head;
    } Stack;

    Stack* stack = (Stack *) malloc (sizeof(Stack));
    Stack* redostack = (Stack *) malloc (sizeof(Stack));
    Node* begin = (Node *) malloc (sizeof(Node));
    redostack->head = NULL;

    stack->head = NULL;
    begin->data = 0;
    begin->next = stack->head;
    stack->head = begin;

	char ask;
	ask = 'I';
	int what;
	scanf("%c", &ask);

	while (ask != 'F') {
        if (ask == 'Z') {
            Node * current = stack->head;
            if (current->next == NULL) {
                printf("Bottom of Stack\n");
            }
            else {
                Node* new_redo = (Node *) malloc (sizeof(Node));
                new_redo->data = current->data;
                new_redo->next = redostack->head;
                redostack->head = new_redo;

                stack->head = current->next;
                free(current);
            }
        }
        else if (ask == 'Y') {
            Node * current = redostack->head;
            if (current == NULL) {
                printf("Top of Stack\n");
            }
            else {
                Node* new_redo = (Node *) malloc (sizeof(Node));
                new_redo->data = current->data;
                new_redo->next = stack->head;
                stack->head = new_redo;

                redostack->head = current->next;
                free(current);
            }
        }
        else if (ask == 'P') {
            printf("Current Value : %d\n", stack->head->data);
        }
        else if (ask == '+') {
            scanf("%d", &what);

            int result;
            if (stack->head == NULL) {
                result = what;
            }
            else {
                result = what + stack->head->data;
            }

            Node* new_node = (Node *) malloc (sizeof(Node));
            new_node->data = result;
            new_node->next = stack->head;
            stack->head = new_node;

            while (redostack->head != NULL) {
                Node* temp = redostack->head;
                redostack->head = temp->next;

                free(temp);
            }
        }
        scanf("%c", &ask);
	}

	printf("Final Value : %d\n", stack->head->data);

}
