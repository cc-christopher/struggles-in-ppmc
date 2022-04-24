#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void recomp(int part1[], int part2[], int N) {

  // Create arr1 ← A[start..mid] and arr2 ← A[mid+1..end]
    int n1 = sizeof(part1)/sizeof(part1[0]);
    int n2 = sizeof(part2)/sizeof(part2[0]);
    int nt = n1+n2;

    int temp[N];
    int at1 = 0;
    int at2 = 0;
    int attemp = 0;
    while (at1 < n1 && at2 < n2) {
        if (part1[at1] <= part2[at2]) {
            temp[attemp] = part1[at1];
            at1++;
        }
        else {
            temp[attemp] = part2[at2];
            at2++;
        }
        attemp++;
    }

    while (at1 < n1) {
        temp[attemp] = part1[at1];
        at1++;
        attemp++;
    }
    while (at2 < n2) {
        temp[attemp] = part2[at2];
        at2++;
        attemp++;
    }
}

void sort(int arr[])
{
    if ((sizeof(arr)/sizeof(arr[0])) <= 1) {
        return;
    }

    int N = sizeof(arr)/sizeof(arr[0]);
    int Nh = floor((sizeof(arr)/sizeof(arr[0]))/2);
    int left[Nh+1];
    int right [Nh];

    for (int i =0; i<(sizeof(arr)/sizeof(arr[0])); i++) {
        if (i<Nh) {
            left[i] = arr[i];
        }
        else {
            right[i-Nh] = arr[i];
        }
    }
        sort(left);
        sort(right);

    recomp(left,right, N);

}

int main()
{
    int data[10] = {6,1,5,8,28,4,7,9,16,24};
    for(int i = 0;i<10;i++){
        printf("%d ",data[i]);
    }
    sort(data);
    printf("Sorted data: ");
    for(int i = 0;i<10;i++){
        printf("%d ",data[i]);
    }
    return 0;
}
