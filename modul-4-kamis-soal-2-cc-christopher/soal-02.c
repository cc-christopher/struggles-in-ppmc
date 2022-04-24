/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 4 - Structures and Dynamic Arrays
*Percobaan        : 4
*Hari dan Tanggal : Kamis, 17 Maret 2022
*Nama (NIM)       : Christopher Chandra (18320033)
*Asisten (NIM)    : Agape D'sky (13219010)
*Nama File        : soal-02.c
*Deskripsi        : pengecek karakteristik matriks skew dan hermetian
*/

#include <stdio.h>
#include <stdlib.h>

// takpakai string.h, manipulasi string lebih sulit tetapi dapat diakali//
typedef struct complex {
	int real;
	int imag;
} complex;

int main() {
	//insert code here
	int row, column;
    scanf("%d %d", &row, &column);

    complex *cell=(complex *) malloc(sizeof(complex));

    for (int i=0; i < row; i++) {
        for (int j=0; i < column; j++) {
            if (j+i*column != 0) {
                cell = (complex *) realloc(cell, (j+i*column+1)*(sizeof(complex)));
            }
            scanf("%d %d", &cell[j+i*column].real, &cell[j+i*column].imag);
        }
        printf("\n");
    }



    // transpose and conjugate rule//

    int transpose, conj;
    transpose = 1;
    conj = 1;
    for (int i = 0; i < sizeof(cell); i++) {
        if (cell[i].imag == cell[(i+1)%row].imag && cell[i].real == cell[(i+1)%row].real) {
            transpose = transpose && 1;

        }
        else {
            transpose = 0;
        }

        if (cell[i].imag == -(cell[(i+1)%row].imag) && cell[i].real == cell[(i+1)%row].real) {
            conj = conj && 1;

        }
        else {
            conj = 0;
        }
    }


   // verdict//
    int verdict;
    if (transpose == 1 && conj == 1) {
        verdict = 1;
    }
    else if (transpose == 1 && conj == 0) {
        verdict = 2;
    }
    else if (transpose == 0 && conj == 1) {
        verdict = 3;
    }
    else {
        verdict = 4;
    }

	//template output :


    switch (verdict) {
    case 1:
        printf("Matriks merupakan matriks skew hermitian dan matriks hermitian\n");
    case 2:
        printf("Matriks merupakan matriks hermitian\n");
    case 3:
        printf("Matriks merupakan matriks skew hermitian\n");
    case 4:
        printf("Matriks bukan merupakan keduanya\n");
    }
    free(cell);
}
