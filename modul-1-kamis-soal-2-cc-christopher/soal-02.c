/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : Overview of C Language
*Percobaan        : 4
*Hari dan Tanggal : Kamis, 17 Februari 2022
*Nama (NIM)       : Christopher Chandra (18320033)
*Asisten (NIM)    : Reynaldo Averill Adji Putra (13219071)
*Nama File        : soal-02.c
*Deskripsi        : Sebuah program yang memiliki dua fungsi: 1. untuk memetakan matriks LBP 3x3; 2. untuk memetakan intensitas piksel dalam histogram sederhana
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//request input
	int buff_in;
	int mat[3][3] = {};
	int one, two, three, four, five = 0;

	for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("masukkan data ke - [%d] [%d] ", i, j);
            scanf("%d", &buff_in);
            mat[i][j] = buff_in;

    //categorize... Woohoo!
            if (mat[i][j] <= 10) {
                one = one + 1;
            }
            else if (mat[i][j] <= 20) {
                two = two + 1;
            }
            else if (mat[i][j] <= 30) {
                three = three + 1;
            }
            else if (mat[i][j] <= 40) {
                four = four + 1;
            }
            else {
                five = five + 1;
            }
        }
	}

	//LBP time
	char lbp[8];
	int loc_lbp;
	loc_lbp = 0;

	for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            else {
                if (mat[1][1] < mat[i][j]) {
                    lbp[loc_lbp] = '1';
                }
                else {
                    lbp[loc_lbp] = '0';
                }
                loc_lbp = loc_lbp + 1;
            }
        }
	}


	//template output histogram
	printf("histogram matriks adalah :\n");

	// perhitungan whitespace
    int buff_max = 0;
    int buffray[5];

    buffray[0] = one;
    buffray[1] = two;
    buffray[2] = three;
    buffray[3] = four;
    buffray[4] = five;

	for (int i = 0; i < 5; i++) {
        if (buff_max < buffray[i]) {
            buff_max = buffray[i];
        }
	}


	int space = 10 - buff_max;

	for (int i = 0; i<space; i++) {
        printf("\n");

	}
    for (int i = 0; i<buff_max; i++) {
        for (int j = 0; j<5; j++) {
            if (j==0) {
                if (buff_max <= one) {
                    printf("1");
                }
                else {
                    printf(" ");
                }
            }
            else if (j==1) {
                if (buff_max <= one) {
                    printf("1");
                }
                else {
                    printf(" ");
                }
            }
            else if (j==2) {
                if (buff_max <= one) {
                    printf("1");
                }
                else {
                    printf(" ");
                }
            }
            else if (j==3) {
                if (buff_max <= one) {
                    printf("1");
                }
                else {
                    printf(" ");
                }
            }
            else if (j==4) {
                if (buff_max <= one) {
                    printf("1");
                }
                else {
                    printf(" ");
                }
            }


            }
            buff_max = buff_max -1;
    }

	//template output lbp
	printf("lbp matriks adalah :\n");
	for (int i=0; i<8; i++) {
        printf("%c", lbp[i]);
	}


	return 0;
}
