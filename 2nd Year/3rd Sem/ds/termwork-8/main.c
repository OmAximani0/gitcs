#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

// Structure to store customer information
struct Customer {
    int custid;
    char custname[50];
    char custphno[15];
};

// Hash table to store customer records
struct Customer hashTable[TABLE_SIZE];

// Function to calculate the hash value for a given customer id
int hashFunction(int custid) {
    return custid % TABLE_SIZE;
}

// Function to insert a new customer record into the hash table
void insertCustomer(int custid, const char *custname, const char *custphno) {
    int index = hashFunction(custid);

    // Linear probing to handle collisions
    while (hashTable[index].custid != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    // Insert the new customer record
    hashTable[index].custid = custid;
    strcpy(hashTable[index].custname, custname);
    strcpy(hashTable[index].custphno, custphno);
}

// Function to search for customer information using custid
void searchCustomer(int custid) {
    int index = hashFunction(custid);
    int originalIndex = index;

    // Linear probing to find the correct record
    while (hashTable[index].custid != -1) {
        if (hashTable[index].custid == custid) {
            printf("Customer found:\n");
            printf("Customer ID: %d\n", hashTable[index].custid);
            printf("Customer Name: %s\n", hashTable[index].custname);
            printf("Customer Phone Number: %s\n", hashTable[index].custphno);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            // Customer not found
            printf("Customer not found for ID %d\n", custid);
            return;
        }
    }

    // Customer not found
    printf("Customer not found for ID %d\n", custid);
}

// Function to display all customer records
void displayRecords() {
    printf("Customer Records:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].custid != -1) {
            printf("Index %d: (ID: %d, Name: %s, Phone: %s)\n", i, hashTable[i].custid, hashTable[i].custname, hashTable[i].custphno);
        }
    }
}

int main() {
    int data;
    // Initialize hash table with -1 indicating empty slots
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].custid = -1;
    }

    // Insert some sample data
    insertCustomer(101, "Ajay", "9562385665");
    insertCustomer(205, "Pooja", "9874523610");
    insertCustomer(312, "Swayam", "7895463210");

    // Display all records
    displayRecords();

    // Search for a customer
    printf("\n Enter Item to search:");
    scanf("%d",&data);

    searchCustomer(data);

    return 0;
}
