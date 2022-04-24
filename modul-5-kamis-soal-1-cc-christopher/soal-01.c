/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 5 - Recursion
*Percobaan        : 5
*Hari dan Tanggal : Kamis, 24 Maret 2022
*Nama (NIM)       : Christopher Chandra (18320033)
*Asisten (NIM)    : Syifa Kushirayati (18319037)
*Nama File        : soal-01.c
*Deskripsi        : traverse terpanjang bilangan anggota matriks secara cacah terurut dari 0,0
*/

#include <stdio.h>
#include <stdlib.h>

int results[10000] = {0};
int *results_ptr = &results;

int search(int n, int matrix[n][n], int length, int loc_i, int loc_j)
{
    for (int i = (loc_i -1); i<loc_i+2; i++) {
        for (int j = (loc_j -1); j<loc_j+2; j++) {
            if (i > -1 && j > -1 && i < n && j < n && i != j && i != (j+2) && j != (i+2) ) {
                if (matrix[i][j] == matrix[loc_i][loc_j] + 1) {
                        search(n, matrix, length+1, i, j);
                }
                else {
                    for (int res_loc = 0; res_loc < 10000; res_loc++) {
                        if (*(results_ptr+res_loc) == 0) {
                            return *(results_ptr+res_loc) = length;
                        }
                    }
                }
            }
        }
    }
}

int main() {
	// baca input
	int n;
	scanf("%d",&n);
	int arr[n][n];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	// lanjutkan program

	search(n, arr, 1, 0, 0);

    int max = 0;
	for (int i =0; i<10000; i++) {
        if (*(results_ptr+i) > max) {
            max = *(results_ptr+i);
        }
	}
	printf("%d", max);
	return 0;
}

