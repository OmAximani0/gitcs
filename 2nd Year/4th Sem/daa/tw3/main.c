#include <stdio.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int main()
{
    int n;
    clock_t s, e;
    double t;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];

    for (int i = 0; i < n; i++) arr[i] = n-i;

    // NOTE: this prints sorted array, no need to execute if array is big
    printf("Array elements are:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    s = clock();
    mergeSort(arr, 0, n - 1);
    e = clock();

    t = (double)(e - s) / CLOCKS_PER_SEC;

    // NOTE: this prints sorted array, no need to execute if array is big
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Time taken to sort %d elements: %f seconds\n", n, t);

    return 0;
}

