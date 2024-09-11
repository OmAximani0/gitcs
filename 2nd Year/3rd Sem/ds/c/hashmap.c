#include <stdio.h>

#define HASH_STORE_SIZE 10

typedef struct hashmap
{
    char *arr[HASH_STORE_SIZE];
} tHashMap;

int hasher(char *key)
{
    int ans = 0;
    while ((*key) != 0)
    {
        ans += *key;
        key++;
    }

    return ans % 10;
}

void add(tHashMap *map, char *key, char *value)
{
    int position = hasher(key);
    map->arr[position] = value;
}

char *get(tHashMap *map, char *key)
{
    int position = hasher(key);

    if (NULL == map->arr[position])
        return NULL;

    return map->arr[position];
}

void printMap(tHashMap *map)
{
    for (int i = 0; i < HASH_STORE_SIZE; i++)
    {
        if (map->arr[i] == NULL)
            continue;
        printf("%d : %s\n", i, map->arr[i]);
    }
}

int main(int argc, char *args[])
{
    tHashMap map;
    char *key = "AA";
    char *value = "my value";

    add(&map, key, value);
    add(&map, "BB", "second");
    printMap(&map);

    key = "F";
    value = "second value";

    add(&map, key, value);
    printMap(&map);

    return 0;
}