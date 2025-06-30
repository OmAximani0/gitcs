#include <stdio.h>

int referenceString[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
int lengthOfReferenceString = sizeof(referenceString) / sizeof(int);

// Function to print current pages in frames
void printPagesInFrames(int frame[], int numberOfFrames) {
    for (int k = 0; k < numberOfFrames; k++) {
        if (frame[k] == -1)
            printf("\t -");
        else
            printf("\t %d", frame[k]);
    }
}

// Function to find index of Least Recently Used page
int findIndexOfLeastRecentlyUsed(int lruCounter[], int numberOfFrames) {
    int maxValue = -1;
    int index = -1;

    for (int i = 0; i < numberOfFrames; i++) {
        if (lruCounter[i] == -1) {
            return i; // Empty frame found
        }
        if (lruCounter[i] > maxValue) {
            maxValue = lruCounter[i];
            index = i;
        }
    }
    return index;
}

// FIFO Page Replacement Algorithm
void fifoPageReplacement(int numberOfFrames) {
    int frame[5] = {-1, -1, -1, -1, -1};
    int pageFaults = 0;
    int j = 0;

    printf("\nFIFO Page Replacement using %d frame(s):\n", numberOfFrames);
    printf("Page\tFrames\n");

    for (int i = 0; i < lengthOfReferenceString; i++) {
        int page = referenceString[i];
        int pageFound = 0;

        for (int k = 0; k < numberOfFrames; k++) {
            if (frame[k] == page) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            frame[j] = page;
            j = (j + 1) % numberOfFrames;
            pageFaults++;
        }

        printf("%d", page);
        printPagesInFrames(frame, numberOfFrames);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", pageFaults);
}

// LRU Page Replacement Algorithm
void lruPageReplacement(int numberOfFrames) {
    int frame[5] = {-1, -1, -1, -1, -1};
    int lruCounter[5] = {-1, -1, -1, -1, -1};
    int pageFaults = 0;

    printf("\nLRU Page Replacement using %d frame(s):\n", numberOfFrames);
    printf("Page\tFrames\n");

    for (int i = 0; i < lengthOfReferenceString; i++) {
        int page = referenceString[i];
        int pageFound = 0;

        for (int k = 0; k < numberOfFrames; k++) {
            if (frame[k] == page) {
                pageFound = 1;
                lruCounter[k] = 0; // Reset counter if page is used
            } else if (frame[k] != -1) {
                lruCounter[k]++; // Increase counter for all other used frames
            }
        }

        if (!pageFound) {
            int index = findIndexOfLeastRecentlyUsed(lruCounter, numberOfFrames);
            frame[index] = page;
            lruCounter[index] = 0;
            pageFaults++;

            for (int k = 0; k < numberOfFrames; k++) {
                if (k != index && frame[k] != -1) {
                    lruCounter[k]++;
                }
            }
        }

        printf("%d", page);
        printPagesInFrames(frame, numberOfFrames);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", pageFaults);
}

int main() {
    int choice;

    printf("Reference String: ");
    for (int i = 0; i < lengthOfReferenceString; i++) {
        printf("%d ", referenceString[i]);
    }
    printf("\n");

    while(1) {
		printf("\n1. FIFO\n2. LRU\n3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

        switch(choice) {
            case 1:
                fifoPageReplacement(3);
                break;
            case 2:
                lruPageReplacement(3);
                break;
            case 3:
                printf("\nExiting...");
                return 0;
        }
    }

    return 0;
}

