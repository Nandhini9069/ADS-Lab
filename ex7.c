#include <stdio.h>
 #include <stdlib.h>
typedef struct Node {
int point[2]; // store (x, y) struct Node *left, *right;
} Node;
// Create new node
Node* newNode(int x, int y) {
Node* n = (Node*)malloc(sizeof(Node)); n->point[0] = x; n->point[1] = y;
n->left = n->right = NULL; return n;
}
// Insert a point in kd-tree (axis alternates)
Node* insert(Node* root, int point[2], int depth) { if (!root) return newNode(point[0], point[1]);
int cd = depth % 2; // current dimension (0=x,1=y) if (point[cd] < root->point[cd])
root->left = insert(root->left, point, depth + 1); else
root->right = insert(root->right, point, depth + 1);
return root;
}
// Inorder Traversal (prints all points) void inorder(Node* root) {
if (root) { inorder(root->left);
printf("(%d,%d) ", root->point[0], root->point[1]); inorder(root->right);
}
}
int main() {
Node* root = NULL;
int n, x, y, p[2];
printf("Enter number of points: "); scanf("%d", &n);
printf("Enter %d points (x y):\n", n); for (int i = 0; i < n; i++) {
scanf("%d %d", &x, &y);
p[0]=x; p[1]=y;
root = insert(root, p, 0);
}
printf("Inorder Traversal of 2D Tree: "); inorder(root);
return 0;
}