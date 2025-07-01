#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int memory[MAX] = {0}; // 0 = free, 1 = used

/*
 * Simulates a disk of 100 blocks.
 * Each index in memory[] represents a block. 0 = free, 1 = occupied.
*/
typedef struct Block {
  int blockNum;
  struct Block *next;
} Block;

/*
 * Defines a linked list node to represent blocks in Linked Allocation.
*/
typedef struct {
  char name[20];
  int start, length;
  Block *head;
} File;

File files[MAX];
int fileCount = 0;

/*
 * A File struct holds:
 *  name: file name.
 *  start and length: used in Sequential allocation.
 *  head: pointer to the head of a linked list for Linked allocation.
 * files[]: stores all the files created. fileCount: number of files.
*/
void sequential() {
  char name[20];
  int start, len;
  printf("Enter file name, start block, length: ");
  scanf("%s %d %d", name, &start, &len);
  for (int i = start; i < start + len; i++) {
    if (memory[i]) {
      printf("Block %d already used. Allocation failed.\n", i);
      return;
    }
  }
  for (int i = start; i < start + len; i++)
    memory[i] = 1;
  File f = {.start = start, .length = len, .head = NULL};
  strcpy(f.name, name);
  files[fileCount++] = f;
  printf("File '%s' allocated from %d to %d (Sequential).\n", name, start,
         start + len - 1);
}

/*
 * Prompts user for name, start, and length.
 * Checks if all required blocks (start to start + length) are free.
 * If yes, marks them as used (memory[i] = 1) and adds the file info to files[].
 * Otherwise, prints an error and aborts allocation.
*/
void linked() {
  char name[20];
  int len, count = 0;
  printf("Enter file name and number of blocks: ");
  scanf("%s %d", name, &len);
  Block *head = NULL, *tail = NULL;
  for (int i = 0; i < MAX && count < len; i++) {
    if (memory[i])
      continue;
    memory[i] = 1;
    Block *b = (Block *)malloc(sizeof(Block));
    b->blockNum = i;
    b->next = NULL;
    if (!head)
      head = tail = b;
    else
      tail->next = b, tail = b;
    count++;
  }
  if (count < len) {
    printf("Not enough space. Allocation failed.\n");
    return;
  }
  File f = {.start = -1, .length = len, .head = head};
  strcpy(f.name, name);
  files[fileCount++] = f;
  printf("File '%s' allocated (Linked).\n", name);
}

/*
 * Prompts for name and number of blocks (len) needed.
 * Scans memory[] to find free blocks.
 * For each free block, allocates memory for a Block node, sets its blockNum, and
 * links it in a list. If not enough free blocks, prints an error. Otherwise,
 * stores the file info in files[].
*/
void show() {
  printf("\nFile Table:\n");
  for (int i = 0; i < fileCount; i++) {
    printf("File: %s\n", files[i].name);
    if (files[i].head == NULL) {
      printf(" Type: Sequential, Blocks: ");
      for (int j = files[i].start; j < files[i].start + files[i].length; j++)
        printf("%d ", j);
    } else {
      printf(" Type: Linked, Blocks: ");
      Block *b = files[i].head;
      while (b) {
        printf("%d -> ", b->blockNum);
        b = b->next;
      }
      printf("NULL");
    }
    printf("\n");
  }
}

/*
 * Displays all files stored so far:
 *  For Sequential files: prints all block numbers in a range.
 *  For Linked files: traverses the linked list and prints block numbers.
*/
int main() {
  int choice;
  do {
    printf("\n1.Sequential Allocation\n2.Linked Allocation\n3.Show "
           "Files\n4.Exit\nChoice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      sequential();
      break;
    case 2:
      linked();
      break;
    case 3:
      show();
      break;
    case 4:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice.\n");
    }
  } while (choice != 4);
  return 0;
}
