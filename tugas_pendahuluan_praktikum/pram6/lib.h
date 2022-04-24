#include <stdio.h>
#include <stdlib.h>

/** Node. Sebuah node dari singly-linked list.
*
* @param data data int yang disimpan dalam node.
* @param next pointer ke data selanjutnya
*/
typedef struct Node {
    int nim, nilai;
    struct Node* next;
} Node;

/**
* fungsi untuk menambah data ke dalam linked list
*
* @param head: pointer to pointer to head node ke linked list
* @param nim: NIM mahasiswa
* @param nilai: nilai mahasiswa
*/
void add(Node **head, int nim, int nilai);

/**
* fungsi untuk mencetak data dari linked list
*
* @param head: pointer to head node ke linked list
*/
void print(Node* head);

/**
* fungsi untuk mencari data nilai tertinggi dari linked list kemudian mencetak
nilainya
*
* @param head: pointer to head node ke linked list
*/
void searchMax(Node* head);

/**
* fungsi untuk mencari data nilai terendah dari linked list kemudian mencetak
nilainya
*
* @param head: pointer to head node ke linked list
*/
void searchMin(Node* head);
