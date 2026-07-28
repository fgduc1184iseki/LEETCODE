#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 100003

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

int hash(int val)
{
    int h = val % TABLE_SIZE;
    if (h < 0)
        h += TABLE_SIZE;
    return h;
}

bool containsDuplicate(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return false;

    Node **hashTable = (Node **)calloc(TABLE_SIZE, sizeof(Node *));
    bool found = false;

    for (int i = 0; i < numsSize; i++)
    {
        int key = hash(nums[i]);
        Node *curr = hashTable[key];

        while (curr != NULL)
        {
            if (curr->val == nums[i])
            {
                found = true;
                break;
            }
            curr = curr->next;
        }

        if (found)
            break;

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = nums[i];
        newNode->next = hashTable[key];
        hashTable[key] = newNode;
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *curr = hashTable[i];
        while (curr != NULL)
        {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(hashTable);

    return found;
}