#include <stdio.h>
#include <stdlib.h>

int product(int array, int i, int j)
{
    int *array_ptr;
    *array_ptr = &array[0][0];
    for (int k = 0; k < i; k++) {
        for (int l = 0; l < j; l++) {
            array[k][l] = *(array_ptr+l+j*k) * 5
        }
    }

}

int main()
{
    printf("Masukkan ukuran matriks.\ni: ");
    scanf("%i", &i);
    printf("\nj: ")
    scanf("%j", &j);

    int array[i][j]= {};
    srand(0);

    for (int k = 0; k < i; k++) {
        for (int l = 0; l < j; l++) {
            array[k][l] = rand();
        }
    }

    product(array, i, j);

    for (int k=0;k<i;k++){
        for(int l = 0;l<j;l++){
            printf("%d ",array[k][l]);
        }
        printf("\n");
    }
    return 0;
}


