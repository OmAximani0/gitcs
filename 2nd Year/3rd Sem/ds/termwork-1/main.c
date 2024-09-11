#include <stdio.h>

void read_array(int *arr, int size);
void display_array(int *arr, int size);
void mid_element(int *arr, int size);
void reverse_array(int *arr, int size);
int sum_array(int *arr, int size);

int main(int argc, char *argv[])
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array: ");
    read_array(&arr[0], n);
    printf("\n");

    int option;
    do
    {
        printf("Menu Operation:\n");
        printf("\tPress 1 - Display Array using pointes \n");
        printf("\tPress 2 - Find Mid element of an Array using Pointers \n");
        printf("\tPress 3 - Reverse the array using pointers\n");
        printf("\tPress 4 - Sum of elements of an array \n");
        printf("\tPress 5 - Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            display_array(arr, n);
            break;
        case 2:
            mid_element(arr, n);
            break;
        case 3:
            reverse_array(arr, n);
            break;
        case 4:
            int arrSum = sum_array(arr, n);
            printf("The sum of array is %d", arrSum);
            printf("\n-----\n");
            break;
        case 5:
            printf("Exiting the program.....\n");
        }
    } while (option != 5);

    return 0;
}

void read_array(int *arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        scanf("%d", &arr[i]);
    }
}

void display_array(int *arr, int size)
{
    int i;
    printf("Arrays elements: ");
    for (i = 0; i < size; ++i)
    {
        printf("%d ", *arr);
        ++arr;
    }
    printf("\n-----\n");
}

void mid_element(int *arr, int size)
{
    if (size % 2 == 0)
    {
        printf("The array is even size! Can not get middle element\n");
    }
    else
    {
        int midIndex;
        midIndex = (size / 2);
        printf("The middle element is %d\n", arr[midIndex]);
    }
    printf("-----\n");
}

void reverse_array(int *arr, int size)
{
    int *start, *end;
    start = arr;
    end = arr + (size - 1);
    while (start <= end)
    {
        int tmp;
        tmp = *start;
        *start = *end;
        *end = tmp;
        ++start;
        --end;
    }
    printf("Reversed array (inplace): \n");
    display_array(arr, size);
}

int sum_array(int *arr, int size)
{
    int i, sum;
    sum = 0;
    for (i = 0; i < size; ++i)
    {
        sum += *(arr + i);
    }
    return sum;
}