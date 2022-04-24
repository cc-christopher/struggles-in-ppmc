/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 8 - Advanced Algorithms
*Percobaan        : 2
*Hari dan Tanggal : Kamis, 14 April 2022
*Nama (NIM)       : Christopher Chandra / 18320033
*Asisten (NIM)    : Nikolas Notohardjo / 13219041
*Nama File        : soal-02.c
*Deskripsi        : permasalahan bidak non-threathening
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 255

// Silahkan tambahkan fungsi sesuai kebutuhan
// Apabila menggunakan VS Code, tahan tombol Ctrl lalu arahkan ke fungsi untuk melihat deskripsi fungsi

/** @brief fungsi digunakan untuk menampilkan papan catur ke layar
 * @param dim dimensi dari papan catur
 * @param matrix pointer to pointer of char dari papan catur
**/
void print_papan_catur(int dim, char **matrix){
	// Fungsi digunakan untuk menampilkan papan catur ke layar
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			printf("%c ",matrix[i][j]);
		}
		printf("\n");
	}
}

/** @brief fungsi digunakan untuk mengatur ulang papan catur menjadi sesuai bacaan awal dari file eksternal
 * @param dim dimensi dari papan catur
 * @param matrix pointer to pointer of char dari papan catur
**/
void reset_papan_catur(int dim, char **matrix){
	// Fungsi digunakan untuk menghapus ratu yang telah diletakkan di papan catur
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if(matrix[i][j]=='Q'){
				matrix[i][j]='X';
			}
		}
	}
}

/** @brief fungsi digunakan untuk menyalin papan catur ke sebuah variabel lain
 * @param dim dimensi dari papan catur
 * @param matrix pointer to pointer of char dari papan catur
 * @param matrix_new pointer to pointer of char dari variabel baru yang akan menjadi tujuan
**/
void salin_papan_catur(int dim, char **matrix, char** matrix_new){
	// Fungsi digunakan untuk menyalin papan catur ke variabel lain
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			matrix_new[i][j] = matrix[i][j];
		}
	}
	return;
}

/** @brief fungsi digunakan untuk membuat papan catur berdasarkan file eksternal
 * @param n_catur pointer to integer dari dimensi dari papan catur
 * @param n_kuda pointer to integer dari jumlah kuda
 * @return pointer to pointer of char dari papan catur
**/
char** buat_papan_catur(int* n_catur, int* n_kuda){
	// Deklarasi variabel
	char file_name[MAX_STRING];
	char each_line[MAX_STRING];
	char temp[MAX_STRING];
	char *token;
	int count = 0;

	// Input nama file
	printf("Masukkan nama file data papan catur: ");
	scanf("%s", file_name);

	// Buka File Eksternal
	FILE* file_catur = fopen(file_name, "r") ;
	// printf("Nama File: %s\n",file_name); // Untuk Debugging

	// Validasi File
	if(file_catur == NULL){
		printf("File tidak dapat dibuka. Program Berakhir.\n");
		fclose(file_catur);
		exit(1);
	}

	// Baca ukuran papan catur
	fgets(each_line,MAX_STRING,file_catur);
	*n_catur = atoi(each_line);

	// Buat bidak catur
	char** catur = (char**) malloc ((*n_catur)*sizeof(char*));
	for(int i=0;i<*n_catur;i++){
		catur[i] = (char*) malloc ((*n_catur)*sizeof(char));
		for(int j=0;j<*n_catur;j++){
			catur[i][j] = 'X';
		}
	}
	// Baca Banyak Kuda
	fgets(each_line,MAX_STRING,file_catur);
	*n_kuda = atoi(each_line);

	// Baca Koordinat Kuda
	while(fgets(each_line,MAX_STRING,file_catur)){
		strcpy(temp,each_line);
		int column = 0,row_temp = 0;
		token = strtok(temp,",");
		while(token!=NULL){
			if(column == 0){
				row_temp = atoi(token);
			}
			else{
				catur[row_temp][atoi(token)] = 'K';
			}
			column += 1;
			token = strtok(NULL,",");
		}
	}
	return catur;
}

char banboard(char **matrix, int dim)
{
    for (int i=0; i<dim; i++) {
        for (int j=0; j<dim; j++) {
            if (matrix[i][j] == 'K') {
                for (int a=0; a<5;a++) {
                    for (int b=0; b<5; b++) {
                        if (i-2+a >= 0 && i-2+a<dim && j-2+b >= 0 && j-2+b<dim) {
                            if (matrix[i-2+a][j-2+b] == 'X') {
                                matrix[i-2+a][j-2+b] = 'O';
                            }
                        }
                    }
                }
                for (int am = 0; am<dim; am++) {
                    if (matrix[i][am] == 'X') {
                        matrix[i][am] = 'O';
                    }
                }
                for (int bm = 0; bm<dim; bm++) {
                    if (matrix[bm][j] == 'X') {
                        matrix[bm][j] = 'O';
                    }
                }
                int xo = i;
                int yo = j;
                for (int da = 0; da<2*dim; da++) {
                    if (xo-dim+1+da < dim && xo-dim+1+da > -1 && yo-dim+1+da < dim && yo-dim+1+da > -1) {
                        if (matrix[xo-dim+1+da][yo-dim+1+da] == 'Q' && da != dim-1) {
                            matrix[xo-dim+1+da][yo-dim+1+da] == 'O';
                        }
                    }
                }
                for (int da = 0; da<2*dim; da++) {
                    if (xo-dim+1+da < dim && xo-dim+1+da > -1 && yo+dim-1-da < dim && yo+dim-1-da > -1) {
                        if (matrix[xo-dim+1+da][yo+dim-1-da] == 'Q' && da != dim-1 && da != dim-1) {
                            matrix[xo-dim+1+da][yo+dim-1-da] == 'O';
                        }
                    }
                }
            }
        }
    }
}

char yassQueen(char **matrix, int dim)
{
    for (int xo  = 0; xo<dim; xo++) {
        for (int yo  = 0; yo<dim; yo++) {
            if (matrix[xo][yo] == 'X') {
                matrix[xo][yo] = 'Q';
            }
        }
    }

}

char cancelled(char **matrix, int dim)
{
    for (int xo = 0; xo<dim; xo++) {
        for (int yo = 0; yo<dim; yo++) {
            if (matrix[xo][yo] == 'Q') {
                for (int a = 0; a< dim; a++) {
                    if (matrix[xo][a] == 'Q' && a != yo) {
                        matrix[xo][a] = 'O';
                    }
                    if (matrix[a][yo] == 'Q' && a != xo) {
                        matrix[a][yo] = 'O';
                    }

                }
                for (int da = 0; da<2*dim; da++) {
                    if (xo-dim+1+da < dim && xo-dim+1+da > -1 && yo-dim+1+da < dim && yo-dim+1+da > -1) {
                        if (matrix[xo-dim+1+da][yo-dim+1+da] == 'Q' && da != dim-1) {
                            matrix[xo-dim+1+da][yo-dim+1+da] == 'O';
                        }
                    }
                }
                for (int da = 0; da<2*dim; da++) {
                    if (xo-dim+1+da < dim && xo-dim+1+da > -1 && yo+dim-1-da < dim && yo+dim-1-da > -1) {
                        if (matrix[xo-dim+1+da][yo+dim-1-da] == 'Q' && da != dim-1 && da != dim-1) {
                            matrix[xo-dim+1+da][yo+dim-1-da] == 'O';
                        }
                    }
                }
            }
        }
    }


}

char amOguX (char **matrix, int dim)
{
    for (int xo = 0; xo<dim; xo++) {
        for (int yo = 0; yo<dim; yo++) {
            if (matrix[xo][yo] == 'O') {
                matrix[xo][yo] = 'X';
            }
        }
    }
}

int harem(char **matrix, int dim)
{
    int count = 0;
    for (int xo = 0; xo<dim; xo++) {
        for (int yo = 0; yo<dim; yo++) {
            if (matrix[xo][yo] == 'Q') {
                count++;
            }
        }
    }
    return count;
}

int main(){
	int n_catur, n_kuda, n_ratu;
	char** catur;
	n_ratu = 0;

	catur = buat_papan_catur(&n_catur,&n_kuda);
	printf("Konfigurasi papan catur yang diberikan oleh Fei adalah:\n");
	print_papan_catur(n_catur,catur);

	banboard(catur, n_catur);
	yassQueen(catur, n_catur);
	cancelled(catur, n_catur);
	amOguX(catur, n_catur);


	int polygamy;
	polygamy = harem(catur, n_catur);
	printf("Jumlah pion ratu terbanyak yang dapat diletakkan di papan catur adalah %d ratu.\n",polygamy);

    printf("Susunan akhir papan catur adalah:\n");
	print_papan_catur(n_catur,catur);

	free(catur);

	return 0;
}
