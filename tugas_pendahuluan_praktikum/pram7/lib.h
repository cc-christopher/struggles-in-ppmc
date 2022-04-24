#include <stdio.h>
#include <stdlib.h>

/** Node. Sebuah node dari singly-linked list.
 * Digunakan sebagai elemen dari Stack dan Queue.
 *
 * @param data data int yang disimpan dalam node.
 * @param next pointer menuju node berikutnya.
 */
typedef struct Node{
    int data;
    struct Node* next;
}Node;

/** Stack. Representasi dari sebuah stack.
 *
 * @param head pointer menuju node paling atas dalam stack.
 */
typedef struct Stack {
    Node* head;
} Stack;

/** push. Tambahkan new_data ke atas stack.
 *
 * @param stack pointer menuju stack.
 * @param new_data data baru untuk ditambahkan ke dalam stack.
 */
void push(Stack** stack, int new_data);

/**
* fungsi untuk mengurutkan isi stack
*
* @param head: pointer to pointer to head of the stack
*/
void sortStack(Stack **head);

void print(Stack* stack);
