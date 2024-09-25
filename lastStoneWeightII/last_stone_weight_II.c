#include <stdlib.h>
#include <stdio.h>

/* Max Heap Structure */
typedef struct {
    int *arr; // Arr to hold heap elements
    int size; // Current size of the heap
    int capacity; // Max capacity of the heap
} MaxHeap;

/* Creates a Max Heap */
MaxHeap* createMaxHeap(int capacity) {
    MaxHeap *maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
    maxHeap->capacity = capacity;
    maxHeap->size = 0;
    maxHeap->arr = (int*)malloc(capacity * sizeof(int));
    return maxHeap;
}

/* Swaps two elements */ 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify Down */
void maxHeapify(MaxHeap *maxHeap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < maxHeap->size && maxHeap->arr[left] > maxHeap->arr[largest])
        largest = left;

    if (right < maxHeap->size && maxHeap->arr[right] > maxHeap->arr[largest])
        largest = right;

    if (largest != index) {
        swap(&maxHeap->arr[index], &maxHeap->arr[largest]);
        maxHeapify(maxHeap, largest);
    }
}

/* Insert a new element into the max heap */
void insertMaxHeap(MaxHeap *maxHeap, int value) {
    if (maxHeap->size == maxHeap->capacity) {
        maxHeap->capacity *= 2;
        maxHeap->arr = (int *)realloc(maxHeap->arr, maxHeap->capacity * sizeof(int));
    }
    maxHeap->arr[maxHeap->size++] = value;
    
    for (int i = (maxHeap->size / 2) - 1; i >= 0; i--) {
        maxHeapify(maxHeap, i);
    }
}

/* Extract max element from the max heap */
int extractMax(MaxHeap *maxHeap) {
    if (maxHeap->size == 0)
        return -1;

    int maxElement = maxHeap->arr[0];
    maxHeap->arr[0] = maxHeap->arr[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);
    return maxElement;
}

int lastStoneWeightII(int* stones, int stonesSize) {

    MaxHeap *maxHeap = createMaxHeap(stonesSize);

    for (int i = 0; i < stonesSize; i++) {
        insertMaxHeap(maxHeap, stones[i]);
    }

    while (maxHeap->size > 1) {
        int first = extractMax(maxHeap);
        int second = extractMax(maxHeap);

        if (first != second) {
            insertMaxHeap(maxHeap, first - second);
        }
    }

    int result = (maxHeap->size == 0) ? 0 : extractMax(maxHeap);

    // Clean up
    free(maxHeap->arr);
    free(maxHeap);

    return result;
}

int main() {
    int stones[] = {2, 7, 4, 1, 8, 1};
    int size = sizeof(stones) / sizeof(stones[0]);
    int result = lastStoneWeightII(stones, size);
    printf("The smallest possible weight of the last stone is: %d\n", result);
    return 0;
}