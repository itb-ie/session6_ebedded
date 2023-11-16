#include <stdio.h>
//#include "math.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 100

void generate_array(int ar[]) {
    int i;
    for (i=0; i<N; i++)
        ar[i] = rand() % (10*N);
}

void print_array(int ar[]) {
    int i;
    for (i=0; i<N; i++)
        printf("%d ", ar[i]);
    printf("\n");
}

void quick_sort(int ar[], int start, int end) {
    if (start >= end)
        return;
    int pivot = ar[end], poz_p = start, i;
    for (i = start; i < end; i++) {
        if (ar[i] < pivot) {
            // swap and increase poz
            int glass = ar[i];
            ar[i] = ar[poz_p];
            ar[poz_p] = glass;
            poz_p++;
        }
    }
    // last swap
    ar[end] = ar[poz_p];
    ar[poz_p] = pivot;
    quick_sort(ar, start, poz_p - 1);
    quick_sort(ar, poz_p + 1, end);
}

void bubble_sort(int ar[]) {
    int i;
    bool done = false;
    while (!done) {
        done = true;
        for (i=0; i< N-1; i++)
            if (ar[i] > ar[i+1]) {
                // need to swap and mark as not done
                done = false;
                int glass = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = glass;
            }
    }
}


int main() {
    int ar[N], ar2[N], i;
    clock_t start, end;
    printf("Quick Sort vs Bubble Sort %d elemenets\n", N);
    srand(time(NULL));
    generate_array(ar);
    for (i = 0; i < N; i++)
        ar2[i] = ar[i];
    print_array(ar);
    start = clock();
    bubble_sort(ar);
    end = clock();
    float bubble = (float)(end-start) / CLOCKS_PER_SEC;
    printf("bubble sort took %f seconds\n", bubble);
    print_array(ar);

    printf("---------\n");

    generate_array(ar2);
    print_array(ar2);
    start = clock();
    quick_sort(ar2, 0, N-1);
    end = clock();
    float quick = (float)(end-start) / CLOCKS_PER_SEC;

    printf("quick sort took %f seconds\n", quick);
    print_array(ar2);

    printf("qsort is faster than bubble sort by %f times\n", bubble/quick);
}



/*
int main2() {
    int j, numbers[5], i;

    for (i=0; i<5; i++)
        numbers[i] = i+1;
    i = 99;
    j = 88;
    printf("%p %p\n", &i, &j);
    printf("%p %p\n", &numbers[0], &numbers[5]);

    printf("Hello, World! %d\n", N);
    printf("result = %d\n", add(N, 100));
    return 0;
}
*/