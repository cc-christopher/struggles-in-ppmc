#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    Stack* head = NULL;
    push(&head,5);
    push(&head,4);
    push(&head,8);
    push(&head,3);
    push(&head,7);
    push(&head,1);
    print(head);
    sortStack(head);
    print(head);
    free(head);
    return 0;
}

