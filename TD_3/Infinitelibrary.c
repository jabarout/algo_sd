#include <stdio.h>
#include <stdlib.h>

struct Node {
    int n;
    struct Node *left;
    struct Node *right;
    int height; 
};
typedef struct Node *Node;

struct Node* createNode(int valeur) {
    struct Node *r = malloc(sizeof(struct Node));
    r->n = valeur;
    r->left = NULL;
    r->right = NULL;
    r->height = 1;
    return r;
}

int height(Node N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int IsAvlNode(Node N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node rotateRight(Node y) {
    Node x = y->left;
    Node T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x; // nouvelle racine
}

Node rotateLeft(Node x) {
    Node y = x->right;
    Node T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y; 
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->n)
        root->left = insert(root->left, val);
    else if (val > root->n)
        root->right = insert(root->right, val);
    else
        return root; 

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = IsAvlNode(root);

    // LL
    if (balance > 1 && val < root->left->n)
        return rotateRight(root);

    // RR
    if (balance < -1 && val > root->right->n)
        return rotateLeft(root);

    // LR
    if (balance > 1 && val > root->left->n) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL
    if (balance < -1 && val < root->right->n) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

int level(Node N) {
    if (N == NULL)
        return 0;
    int left = level(N->left);
    int right = level(N->right);
    return 1 + (left > right ? left : right);
}

void search(struct Node *root, int val) {
    if (root == NULL) {
        printf("NO\n");
        return;
    }
    if (root->n == val) {
        printf("YES\n");
        return;
    }
    if (val < root->n)
        search(root->left, val);
    else
        search(root->right, val);
}

struct Node *ReadInFileTree(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier %s\n", filename);
        return NULL;
    }

    int a, value;
    struct Node *root = NULL;
    fscanf(file, "%d", &a);
    for (int i = 0; i < a; i++) {
        if (fscanf(file, "%d", &value) == 1) {
            root = insert(root, value);
        }
    }

    int size = 0, b = 0;
    fscanf(file, "%d", &size);
    for (int k = 0; k < size; k++) {
        if (fscanf(file, "%d", &b) == 1) {
            search(root, b);
        }
    }

    fclose(file);
    return root;
}

int main() {
    Node tree = ReadInFileTree("test05.txt");
    if (tree != NULL) {
        printf("Hauteur de l'arbre: %d\n", level(tree));
        printf("Facteur d'équilibre racine: %d\n", IsAvlNode(tree));
    }
    return 0;
}