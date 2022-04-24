/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 6 - Linked List
*Percobaan        : 5
*Hari dan Tanggal : Kamis, 31 Maret 2022
*Nama (NIM)       : Christopher Chandra (18320033)
*Asisten (NIM)    : Muhammad Morteza Mudrick (13219061)
*Nama File        : soal-01.c
*Deskripsi        : program yang menerima linked list terurut dan mencetak output tiap integer secara berurut
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//Struct Node Linked List
typedef struct Node {
	int data;
	struct Node* next;
} Node;


int main()
{
    Node* firstlist = (Node *) malloc (sizeof(Node));
    Node* secondlist = (Node *) malloc (sizeof(Node));
    Node* thirdlist = (Node *) malloc (sizeof(Node));

    firstlist, secondlist, thirdlist = NULL;
	int how, what;

	//input linked list pertama
	printf("Masukkan jumlah elemen linked list pertama: ");
    scanf("%d", &how);

	printf("Masukkan elemen-elemen linked list pertama: ");
	for (int i=0; i<how; i++) {
        scanf("%d", &what);
        if (i == 0) {
            Node *new_node = (Node*) malloc (sizeof(Node));
            new_node->data = what;
            new_node->next = NULL;
            firstlist = new_node;
        }
        else {
            Node *current = firstlist;

            while (current->next != NULL){
                current = current->next;
            }

            Node* new_node = (Node*) malloc(sizeof(Node));
            new_node->data = what;
            new_node->next = NULL;
            current->next = new_node;
        }
	}


	//input linked list kedua
	printf("Masukkan jumlah elemen linked list kedua: ");
    scanf("%d", &how);

	printf("Masukkan elemen-elemen linked list kedua: ");
	for (int i=0; i<how; i++) {
        scanf("%d", &what);
        if (i == 0) {
            Node *new_node = (Node*) malloc (sizeof(Node));
            new_node->data = what;
            new_node->next = NULL;
            secondlist = new_node;
        }
        else {
            Node *current = secondlist;

            while (current->next != NULL){
                current = current->next;
            }

            Node* new_node = (Node*) malloc(sizeof(Node));
            new_node->data = what;
            new_node->next = NULL;
            current->next = new_node;
        }
	}

	//input linked list ketiga
	printf("Masukkan jumlah elemen linked list ketiga: ");
    scanf("%d", &how);

	printf("Masukkan elemen-elemen linked list ketiga: ");
	for (int i=0; i<how; i++) {
        scanf("%d", &what);
        if (i == 0) {
            Node *new_node = (Node*) malloc (sizeof(Node));
            new_node->data = what;
            new_node->next = NULL;
            thirdlist = new_node;
        }
        else {
            Node *current = thirdlist;

            while (current->next != NULL){
                current = current->next;
            }

            Node* new_node = (Node*) malloc(sizeof(Node));
            new_node->data = what;
            new_node->next = NULL;
            current->next = new_node;
        }
	}


	//Cetak output berupa urutan integer
	printf("\nHasil urutan gabungan ketiga linked list: ");

	while (firstlist != NULL && secondlist != NULL && thirdlist != NULL) {
        if (firstlist->data <= secondlist->data && firstlist->data <= thirdlist->data ) {
            printf("%d ", firstlist->data);
            firstlist = firstlist->next;
        }
        else if (secondlist->data <= firstlist->data && secondlist->data <= thirdlist->data) {
            printf("%d ", secondlist->data);
            secondlist = secondlist->next;
        }
        else if (thirdlist->data <= firstlist->data && thirdlist->data <= secondlist->data) {
            printf("%d ", thirdlist->data);
            thirdlist = thirdlist->next;
        }
	}

	while (firstlist != NULL && secondlist != NULL) {
        if (firstlist->data <= secondlist->data) {
            printf("%d ", firstlist->data);
            firstlist = firstlist->next;
        }
        else {
            printf("%d ", secondlist->data);
            secondlist = secondlist->next;
        }
	}

	while (secondlist != NULL && thirdlist != NULL) {
        if (secondlist->data <= thirdlist->data) {
            printf("%d ", secondlist->data);
            secondlist = secondlist->next;
        }
        else {
            printf("%d ", thirdlist->data);
            thirdlist = thirdlist->next;
        }
	}

	while (firstlist != NULL && thirdlist != NULL) {
        if (firstlist->data <= thirdlist->data ) {
            printf("%d ", firstlist->data);
            firstlist = firstlist->next;
        }
        else {
            printf("%d ", thirdlist->data);
            thirdlist = thirdlist->next;
        }
	}

	while (firstlist != NULL) {
       printf("%d ", firstlist->data);
       firstlist = firstlist->next;
	}
	while (secondlist != NULL) {
       printf("%d ", secondlist->data);
       secondlist = secondlist->next;
	}
	while (thirdlist != NULL) {
       printf("%d ", thirdlist->data);
       thirdlist = thirdlist->next;
	}
	return 0;
}
