/*    typedef struct Stack{
        Node * head;

    Stack;

    typedef struct Node{
        int * element;
        Node * next;
    }Node;

void sort(int arr[])
{
    # pointer terpaksa digunakan...
    if (sizeof(arr) <= 1) {
        return;
    }
    else {
        int Nh = floor(sizeof(arr)/2)];
        int left[Nh+1] = {};
        int right [Nh] = {};

        for (int i =0; i<sizeof(arr); i++) {
            if (i<Nh) {
                left[i] = arr[i];
            }
            else {
                right[i-Nh] = arr[i];
            }
        }
        sort(left);
        sort(right);
    }
    recomp(left,right);
}

void recomp(int arr1[], int arr2[])
{

}


ge(arr, start, mid, end);
  }
}

int main() {
  int arr[] = {6, 5, 4, 8, 1, 9};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
  printf("\n");
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int arr[])
{
    # pointer terpaksa digunakan...
    if (sizeof(arr) <= 1) {
        return;
    }
    else {

    }
}




        Node* new_node = (Node *) malloc (sizeof(Node));
        if (sizeof(arr) == 2) {

            if (arr[0] <= arr[1]) {
                new_node->mininum = arr[0];
                new_node->minimum = arr[1];
            }
            else {
                new_node->minimum = arr[1];
                new_node->minimum = arr[0];
            }

        }
        else {
            new_node->minimum = arr[0];
            new_node->maximum = NULL;
        }
        new_node->next = stack->head;
        stack->head = new_node;
    }
    else {
        int N = floor(sizeof(arr)/2);
        int arr1[N+1] = [];
        int arr2[N] = [];

        for (int i=0; i < N+1; i++) {
            arr1[i] = arr[i];
            if (i<N) {
                arr2[i] = arr[N+i]
            }
        }
        divide(arr1);
        divide(arr2);
    }
}

int sort(int arr = {}, Stack * cepha)
{
    length = sizeof(arr);
    int newarr[length] = {-999};
    divide(arr, cepha);
    Node * current = stack->head;
    while (current->next != NULL) {
        for (int i=0, i<length; i++) {
            if (newarr[i] == -999) {
                break
            }
        }
        if (current->minimum <= current->next->minimum && current->maximum <= current->next->minimum) {
            newarr[i] = current->minimum;
            newarr[i+1] = current->maximum;
            newarr[i+2] = current->next->minimum;
            if (current->next->maximum != -999) {
                newarr[i+3] = current->next->maximum;
            }
        }
        else if (current->minimum <= current->next->minimum && current->maximum >= current->next->minimum && current->maximum >= current->next->maximum) {
            newarr[i] = current->minimum;
            newarr[i+3] = current->maximum;
            newarr[i+1] = current->next->minimum;
            newarr[i+2] = current->next->maximum;
        }
        else if () {

        }
    }
}

int main() {
    typedef struct Node{
        int minimum;
        int maximum;
        struct Node* next;
    }Node;

    typedef struct Stack {
        Node* head;
    } Stack;

    Stack* stack = (Stack *) malloc (sizeof(Stack));
    Node* begin = (Node *) malloc (sizeof(Node));

    stack->head = NULL;
    begin->next = stack->head;
    stack->head = begin;



	char ask;
	ask = 'I';
	int what;
	scanf("%c", &ask);

	while (ask != 'F') {
        if (ask == 'Z') {
            Node * current = stack->head;
            if (current->next == NULL) {
                printf("Bottom of Stack\n");
            }
            else {
                Node* new_redo = (Node *) malloc (sizeof(Node));
                new_redo->data = current->data;
                new_redo->next = redostack->head;
                redostack->head = new_redo;

                stack->head = current->next;
                free(current);
            }
        }
        else if (ask == 'Y') {
            Node * current = redostack->head;
            if (current == NULL) {
                printf("Top of Stack\n");
            }
            else {
                Node* new_redo = (Node *) malloc (sizeof(Node));
                new_redo->data = current->data;
                new_redo->next = stack->head;
                stack->head = new_redo;

                redostack->head = current->next;
                free(current);
            }
        }
        else if (ask == 'P') {
            printf("Current Value : %d\n", stack->head->data);
        }
        else if (ask == '+') {
            scanf("%d", &what);

            int result;
            if (stack->head == NULL) {
                result = what;
            }
            else {
                result = what + stack->head->data;
            }

            Node* new_node = (Node *) malloc (sizeof(Node));
            new_node->data = result;
            new_node->next = stack->head;
            stack->head = new_node;

            while (redostack->head != NULL) {
                Node* temp = redostack->head;
                redostack->head = temp->next;

                free(temp);
            }
        }
        scanf("%c", &ask);
	}

	printf("Final Value : %d\n", stack->head->data);

}
*/
