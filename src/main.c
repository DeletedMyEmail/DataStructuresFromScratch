#include <stdio.h>
#include "../includes/HashTable.h"

void print(ListNode* x) {
    printf(": %p\n", x->val);
}

void LinkedListTest1() {
    LinkedList* ll = llCreate();

    int* x0 = malloc(sizeof(int));
    *x0 = 0;
    int* x1 = malloc(sizeof(int));
    *x1 = 1;
    int* x2 = malloc(sizeof(int));
    *x2 = 2;
    int* x3 = malloc(sizeof(int));
    *x3 = 3;

    llPush(ll, x0);
    llPush(ll, x2);
    llPushAt(ll, 1, x1);
    llPush(ll, x3);
    llPop(ll);

    llForeach(ll, print);

    printf("Length: %d\nGet1: %d\nGet2: %d\nGet3: %d\n\n",
           ll->length == 3,
           *( (int*) llGet(ll, 1)->val) == 1,
           *( (int*) llGet(ll, 2)->val) == 2,
           llGet(ll, 3) == NULL
    );

    llFree(ll);
}

void HashTableTest1() {
    HashTable* ht = htCreate(16);

    //htDoubleCapacity(ht);
    printf("Capacity: %d\nGet without entries: %d\n",
           ht->capacity == 16,
           htGet(ht, "xyz") == NULL
    );

    int* i1 = malloc(sizeof(int));
    *i1 = 1;
    int* i2 = malloc(sizeof(int));
    *i2 = 2;
    int* i3 = malloc(sizeof(int));
    *i3 = 3;

    char* key1 = malloc(2 * sizeof(char));
    key1[0] = '1';
    key1[1] = '\0';
    char* key2 = malloc(2 * sizeof(char));
    key2[0] = '2';
    key2[1] = '\0';
    char* key3 = malloc(2 * sizeof(char));
    key3[0] = '3';
    key3[1] = '\0';

    printf("Keys: %p %c %p %c %p %c\n", key1, *key1, key2, *key2, key3, *key3);

    htSet(ht, key1, i1);
    htSet(ht, key2, i2);
    htSet(ht, key3, i3);

    /*printf("Get 1: %d\nGet 2: %d\nGet 3: %d\nLength: %d\n",
           *(int*)htGet(ht, key1) == 1,
           *(int*)htGet(ht, key2) == 2,
           *(int*)htGet(ht, key3) == 3,
           ht->length == 3
    );*/

    htRemove(ht, key2);

    /*printf("Len after remove: %d\nGet 2 after remove: %d\n",
           ht->length == 2,
           htGet(ht, key2) == NULL
    );

    printf("Get 1: %d\nGet 3: %d\nLength: %d\n",
           *(int*)htGet(ht, key1) == 1,
           *(int*)htGet(ht, key3) == 3,
           ht->length == 2
    );*/

    htDelete(ht);
}

int main(int argc, char const** argv) {
    //LinkedListTest1();
    HashTableTest1();

    return 0;
}
