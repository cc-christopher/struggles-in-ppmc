
#include "lib.h"

void add(Node **head, int nim, int nilai)
{
    if ((*head) == NULL) {
        Node *new_node = (Node*) malloc (sizeof(Node));
        new_node->nim = nim;
        new_node->nilai = nilai;
        new_node->next = NULL;
        (*head) = new_node;
    }
    else {
        Node *current = *head;

        while (current->next != NULL){
            current = current->next;
        }

        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->nim = nim;
        new_node->nilai = nilai;
        new_node->next = NULL;
        current->next = new_node;
    }

}

void print(Node* head)
{

    while (head != NULL) {
        printf("NIM: %d, Nilai: %d\n", head->nim, head->nilai);
        head = head->next;
    }
}

void searchMax(Node* head)
{
    Node* max_at = (Node*) malloc(sizeof(Node));

    int max;
    max = 0;
    while (head != NULL) {
        if (head->nilai > max) {
            max = head->nilai;
            max_at = head;
        }
        head = head->next;
    }
    printf("Nilai tertinggi:\nNIM: %d, Nilai: %d\n", max_at->nim, max_at->nilai);

}

void searchMin(Node* head)
{

    Node* min_at = (Node*) malloc(sizeof(Node));

    int min;
    min = 999;
    while (head != NULL) {
        if (head->nilai < min) {
            min = head->nilai;
            min_at = head;
        }
        head = head->next;
    }
    printf("Nilai terendah:\nNIM: %d, Nilai: %d\n", min_at->nim, min_at->nilai);


}

