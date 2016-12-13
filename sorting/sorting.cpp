//
// Created by Kirill Khlopko.
//

#include "sorting.h"

using namespace std;

template<typename T>
int min(T* a, const int N) {
    int k = 0;
    for (int i = 1; i < N; i++) if (a[i] < a[k]) k = i;
    return k;
}

template<typename T>
void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
void quick_sort(T* a, const int N) {
    int mid = N / 2;
    T p = a[mid];
    int i = 0, k = N - 1;
    do {
        while (a[i] < p) i++;
        while (a[k] > p) k--;
        if (i <= k) {
            swap(&a[i], &a[k]);
            i++, k--;
        }
    } while (i <= k);
    if (k > 0) quick_sort(a, k + 1);
    if (i < N) quick_sort(a + i, N - i);
}

template<typename T>
void bubble_sort(T* a, const int N) {
    for (int i = 0; i < N; i++) {
        for (int k = i + 1; k < N; k++) {
            if (a[i] > a[k]) {
                swap(&a[i], &a[k]);
            }
        }
    }
}

template<typename T>
void insertion_sort(T* a, const int N) {
    for (int k = 1; k < N; k++) {
        T key = a[k];
        int i = k - 1;
        while ((i >= 0) && (a[i] > key)) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

template<typename T>
void selection_sort(T* a, const int N) {
    for (int i = 0; i < N; i++) swap(&a[i], &a[i + min(a + i, N - i)]);
}

template<typename T>
void shell_sort(T* a, const int N) {
    static int c = 0;
    int d = N - pow(2, c) - 1;
    if (d > 1) {
        for (int k = d; k < N; k += d) {
            T key = a[k];
            int i = k - d;
            while ((i >= 0) && (a[i] > key)) {
                a[i + 1] = a[i];
                i -= d;
            }
            a[i + 1] = key;
        }
        c++;
        shell_sort(a, N);
    } else {
        insertion_sort(a, N);
    }
}
