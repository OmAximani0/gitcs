#include <stdio.h>
int main() {
    int numProcesses = 5; // Number of processes
    int numResources = 3; // Number of resources

    int allocationMatrix[5][3] = {{1, 1, 2}, {2, 1, 2}, {4, 0, 1}, {0, 2, 0}, {1, 1, 2}}; // Allocation Matrix
    int maxMatrix[5][3] = {{4, 3, 3}, {3, 2, 2}, {9, 0, 2}, {7, 5, 3}, {1, 1, 2}}; // MAX Matrix 
    int availableResources[3] = {2, 1, 0}; // Available Resources
    int isFinished[numProcesses], safeSequence[numProcesses], index = 0;

    for (int k = 0; k < numProcesses; k++) {
        isFinished[k] = 0;
    }

    int needMatrix[numProcesses][numResources];
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++)
            needMatrix[i][j] = maxMatrix[i][j] - allocationMatrix[i][j];
    }

    for (int k = 0; k < numProcesses; k++) {
        for (int i = 0; i < numProcesses; i++) {
            if (isFinished[i] == 0) {
                int flag = 0;
                for (int j = 0; j < numResources; j++) {
                    if (needMatrix[i][j] > availableResources[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safeSequence[index++] = i;
                    for (int y = 0; y < numResources; y++)
                        availableResources[y] += allocationMatrix[i][y];
                    isFinished[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    for (int i = 0; i < numProcesses; i++) {
        if (isFinished[i] == 0) {
            flag = 0;
            printf("The system is not safe.\n");
            break;
        }
    }

    if (flag == 1) {
        printf("SAFE Sequence: ");
        for (int i = 0; i < numProcesses - 1; i++)
            printf("P%d -> ", safeSequence[i]);
        printf("P%d\n", safeSequence[numProcesses - 1]);
    }

    return 0;
}
