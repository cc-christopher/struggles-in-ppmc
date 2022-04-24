#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    Node* head = NULL;
    add(&head, 10018001,90);
    add(&head, 10018002,80);
    add(&head, 10018003,68);
    add(&head, 10018004,89);
    add(&head, 10018005,92);
    add(&head, 10018006,80);
    print(head);
    searchMax(head);
    searchMin(head);
    free(head);
    return 0;
}
