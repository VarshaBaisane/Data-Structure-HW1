#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining the binary tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structuring stack node
struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
};

// Structure for a stack
struct Stack {
    struct StackNode* top;
};

// Function for creating a new binary tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to push a node onto the stack
void push(struct Stack* stack, struct TreeNode* node) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->node = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

// checking if the stack is empty
bool isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to pop a node from the stack
struct TreeNode* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    struct StackNode* temp = stack->top;
    struct TreeNode* poppedNode = temp->node;
    stack->top = stack->top->next;
    free(temp);
    return poppedNode;
}

// Function for inorder traversal using stack
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    struct Stack* stack = createStack();
    struct TreeNode* current = root;

    while (!isEmpty(stack) || current != NULL) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        
        current = pop(stack);
        printf("%d ", current->value);
        
        current = current->right;
    }

    free(stack); // Freeing the stack memory
}

int main() {
    // Construct a binary tree
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    // Perform an inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);

    return 0;
}
