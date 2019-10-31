#include <stdio.h>

typedef struct {
    int size;
    int *element;
} Heap;

void swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}


void heapify(Heap *heap, int idx) {
    int temp = idx;
    int *arr = heap->element;

    if (heap->size < idx * 2) return;

    //only has left child node
    if (heap->size == idx * 2) {
        if (arr[idx] < arr[idx * 2])
            temp = idx * 2;
    } else {
        if (arr[idx * 2] < arr[idx * 2 + 1]) {
            if (arr[idx] < arr[idx * 2 + 1])
                temp = idx * 2 + 1;
        } else {
            if (arr[idx] < arr[idx * 2])
                temp = idx * 2;
        }
    }

    if (temp != idx) {
        swap(heap->element[idx], heap->element[temp]);
        heapify(heap, temp);
    }
}

Heap *makeHeap(int size, int *data) {
    Heap *heap = new Heap;
    heap->size = size - 1;
    heap->element = data;

    for (int i = heap->size / 2; 1 <= i; i--) {
        heapify(heap, i);
    }

    return heap;
}

void heapSort(int size, int *data) {
    Heap *heap = makeHeap(size, data);

    for (int i = heap->size; 1 <= i; i--) {
        swap(heap->element[1], heap->element[i]);
        heap->size--;
        heapify(heap, 1);
    }
}

//delete
int extractMax(Heap* heap) {
    int max = heap->element[1];

    swap(heap->element[1], heap->element[heap->size]);
    heap->size--;
    heapify(heap, 1);

    return max;
}

void heapInsert(Heap* heap, int value) {
    heap->size++;
    heap->element[heap->size] = value;

    int idx = heap->size;
    while (1 < idx && heap->element[idx/2] < heap->element[idx]) {
        swap(heap->element[idx/2], heap->element[idx]);
        idx = idx/2;
    }
}

int main() {
    int size = 11;
    int data[] = {0, 15, 4, 8, 11, 16, 7, 3, 1, 2, 5};

    int size2 = 10;
    int data2[] = {0, 15, 4, 8, 11, 16, 7, 3, 1, 2, 5};

    heapSort(size, data);

    printf("After Heap Sort\n");

    for (int i = 1; i < size; i++) {
        printf("%d : %d\n", i, data[i]);
    }

    Heap* heap = makeHeap(size2, data2);

    int max = extractMax(heap);

    printf("\nDelete MAX : %d\n", max);

    int insertElement = 100;

    heapInsert(heap, 100);

    printf("Heap Status After Insert %d", insertElement);

    int idx = 1;
    int level = 1;
    for(int i = 1; i <= heap->size; i++) {
        if(idx == i) {
            printf("\n%d : ", level);
            idx *= 2;
            level++;
        }
        printf("%d ", heap->element[i]);
    }
}