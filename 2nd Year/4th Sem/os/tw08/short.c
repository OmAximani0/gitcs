#include <stdio.h>

int reference[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
int n = sizeof(reference) / sizeof(reference[0]);

void printFrames(int frames[], int size) {
    for (int i = 0; i < size; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}

void fifo(int frameSize) {
    int frames[10];
    int index = 0, faults = 0;

    for (int i = 0; i < frameSize; i++)
        frames[i] = -1;

    printf("\nFIFO Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == reference[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[index] = reference[i];
            index = (index + 1) % frameSize;
            faults++;
        }

        printf("Page %d ->", reference[i]);
        printFrames(frames, frameSize);
    }

    printf("Total Page Faults (FIFO): %d\n", faults);
}

void lru(int frameSize) {
    int frames[10], used[10];
    int faults = 0;

    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
        used[i] = -1;
    }

    printf("\nLRU Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == reference[i]) {
                found = 1;
                used[j] = i;
                break;
            }
        }

        if (!found) {
            int min = 0;
            for (int j = 1; j < frameSize; j++) {
                if (used[j] < used[min]) min = j;
            }

            frames[min] = reference[i];
            used[min] = i;
            faults++;
        }

        printf("Page %d ->", reference[i]);
        printFrames(frames, frameSize);
    }

    printf("Total Page Faults (LRU): %d\n", faults);
}

int main() {
    int choice;

    printf("Reference String: ");
    for (int i = 0; i < n; i++)
        printf("%d ", reference[i]);
    printf("\n");

    while (1) {
        printf("\n1. FIFO\n2. LRU\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);

        if (choice == 1)
            fifo(3);
        else if (choice == 2)
            lru(3);
        else if (choice == 3)
            break;
        else
            printf("Invalid choice!\n");
    }

    return 0;
}
