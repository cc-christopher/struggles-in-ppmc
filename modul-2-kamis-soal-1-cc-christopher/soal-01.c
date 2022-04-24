/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 2 - Strings and External Files
*Percobaan        : 5
*Hari dan Tanggal : Kamis, 24 Februari 2022
*Nama (NIM)       : Christopher Chandra (18320033)
*Asisten (NIM)    : Nikolas Notohardjo (13219041)
*Nama File        : soal-01.c
*Deskripsi        : Program untuk membaca file data bpm dan mengecek sesuai permintaan pengguna
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(){

	//template output

	//read requested files
	printf("Masukkan nama file kelas : ");
    char filename[100];
	scanf("%s", &filename);

    FILE *stream = fopen(filename, "r");

    if (!stream) {
        printf("Error : file invalid\n");
    }
	else {
        char line[1000];
        char* token;

        int i = 0;
        char table[30][2][200];
        while(fgets(line, 1000, stream)){
            token = strtok(line, ",");
            int j = 0;
            while( token != NULL) {

                strcpy(table[i][j], token);

                j++;

                token = strtok(NULL, "\n");

            }
            i++;
        }
        printf("Pilihlah nomor menu dibawah ini : \n");
        printf("1. Cari siswa dengan bpm terkecil\n");
        printf("2. Cari siswa dengan nama nya\n");
        printf("3. Cari siswa dengan rentang bpm tertentu\n");
        printf("Masukkan nomor menu 1/2/3 : ");
        char choice;
        scanf("%i", &choice);

        if (choice == 1) {
            int min_bp = 999999;
            int min_loc;
            int inspect_bp;
            for (int i = 0; i < 30; i++) {
                inspect_bp = atof(table[i][1]);
                if (inspect_bp < min_bp && inspect_bp != 0) {
                    min_bp = inspect_bp;
                    min_loc = i;
                }

            }
            printf("Siswa 1\n");
            printf("Nama siswa : %s\n", &table[min_loc][0]);
            printf("Bpm siswa : %s\n", &table[min_loc][1]);

        }

        else if (choice ==2) {
            char stu_name[80];
            printf("Masukkan nama siswa : ");
            scanf("%s", &stu_name);

            int counter = 1;
            for (int i = 0; i < 30; i++) {
                if (strstr(table[i][0], stu_name)) {
                    printf("Siswa %i\n", counter);
                    printf("Nama siswa : %s\n", &table[i][0]);
                    printf("Bpm siswa : %s\n", &table[i][1]);
                    counter++;
                }
            }
            if (counter == 1) {
                printf("Hasil pencarian tidak ditemukan :(\n");
            }
        }

        else if (choice == 3) {
            int maxbp;
            int minbp;
            printf("Masukkan batas atas bpm : ");
            scanf("%i", &maxbp);
            printf("Masukkan batas bawah bpm : ");
            scanf("%i", &minbp);

            int counter = 1;
            for (int i = 0; i < 30; i++) {
                if (minbp <= atof(table[i][1]) && atof(table[i][1]) <= maxbp && table[i][1] != 0) {
                    printf("Siswa %i\n", counter);
                    printf("Nama siswa : %s\n", &table[i][0]);
                    printf("Bpm siswa : %s\n", &table[i][1]);
                    counter++;
                }

            }
            if (counter == 1) {
                printf("Hasil pencarian tidak ditemukan :(\n");
        }
        }
        else {
            printf("Error : Nomor menu invalid\n");
        }


	return 0;
}
}
