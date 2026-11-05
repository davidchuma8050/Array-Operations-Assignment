
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int capacity = 10;
    int size = 5;
    int i, j, value, position;
    int *arr = (int *)malloc(capacity * sizeof(int));

    if(arr == NULL) return 1;

    printf("Enter 5 elements:\n");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, size);

    printf("Enter value and position to insert: ");
    scanf("%d %d", &value, &position);

    if(position >= 0 && position <= size && size < capacity) {
        for(i = size; i > position; i--)
            arr[i] = arr[i - 1];

        arr[position] = value;
        size++;
    }

    printf("After insertion: ");
    printArray(arr, size);

    printf("Enter value to delete: ");
    scanf("%d", &value);

    for(i = 0; i < size; i++) {
        if(arr[i] == value) {
            for(j = i; j < size - 1; j++)
                arr[j] = arr[j + 1];
            size--;
            break;
        }
    }

    printf("After deletion: ");
    printArray(arr, size);

    free(arr);
    return 0;
}


