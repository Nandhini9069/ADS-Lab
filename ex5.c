#include <stdio.h> #include <stdlib.h>
typedef struct Node { int key, degree, mark;
struct Node *parent, *child, *left, *right;
} Node;
Node *min = NULL;
// Create new node
Node* newNode(int key) {
Node *n = (Node*)malloc(sizeof(Node)); n->key = key; n->degree = n->mark = 0; n->parent = n->child = NULL;
n->left = n->right = n; return n;
}
// Insert node
void insert(int key) {
Node *n = newNode(key); if (!min) min = n;
else {
n->left = min;
n->right = min->right; min->right->left = n; min->right = n;
if (n->key < min->key) min = n;
}
}
// Display root list void display() {
if (!min) { printf("Heap empty\n"); return; } Node *t = min;
printf("Root List: "); do {
printf("%d ", t->key); t = t->right;
} while (t != min);
printf("\n");
}
int main() {
int choice, key; while (1) {
printf("\n1. Insert\n2. Display\n3. Get Min\n4. Exit\nEnter choice: "); scanf("%d", &choice);
if (choice == 1) { printf("Enter key: "); scanf("%d", &key); insert(key);
}
else if (choice == 2) display(); else if (choice == 3) {
if (min) printf("Minimum = %d\n", min->key); else printf("Heap empty\n");
}
else if (choice == 4) break; else printf("Invalid choice!\n");
}
return 0;
