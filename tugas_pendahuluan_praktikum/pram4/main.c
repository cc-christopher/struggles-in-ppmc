#include <stdio.h>
#include <stdlib.h>

typedef struct book{
    int jenis_buku;
    int jumlah_buku;
}buku;

void addjenisbuku(int jenis, int jumlah, buku* perpustakaan, int *count){
    if (*count != 0) {
        perpustakaan = (buku*) realloc(perpustakaan, (*count+1) *(sizeof(buku)));

    }
    int loc;
    loc = *count;
    perpustakaan[loc].jenis_buku = jenis;
    perpustakaan[loc].jumlah_buku = jumlah;
    // mengasumsikan input jenis berurutan dan tidak diulang jika sudah diinput //
    (*count)++;
}
void print(int count, buku* perpustakaan){
    for (int i = 0; i < (count); i++) {
        printf("jenis: %d, jumlah: %d\n", perpustakaan[i].jenis_buku, perpustakaan[i].jumlah_buku);
    }

}

int main(){
    buku* perpus=(buku*) malloc(sizeof(buku));
    int banyak_jenis_buku = 0;
    addjenisbuku(1,5,perpus,&banyak_jenis_buku);
    addjenisbuku(2,8,perpus,&banyak_jenis_buku);
    addjenisbuku(6,20,perpus,&banyak_jenis_buku);
    print(banyak_jenis_buku, perpus);
    free(perpus);
    return 0;
}
