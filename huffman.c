#include <stdio.h>
#include <stdlib.h>
 
struct HuffmanNode {
    char data;
    int freq;
    struct HuffmanNode *left, *right;
};
 
struct MinHeap {
    int size;
    struct HuffmanNode **array;
};
 
struct HuffmanNode* createNode(char data, int freq) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}
 
void swapNodes(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}
 
void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != index) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}
 
struct HuffmanNode* extractMin(struct MinHeap* minHeap) {
    struct HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}
 
void insertMinHeap(struct MinHeap* minHeap, struct HuffmanNode* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}
 
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = size;
    minHeap->array = (struct HuffmanNode**)malloc(size * sizeof(struct HuffmanNode*));
    for (int i = 0; i < size; i++)
        minHeap->array[i] = createNode(data[i], freq[i]);
    for (int i = (size - 1) / 2; i >= 0; i--)
        minHeapify(minHeap, i);
    return minHeap;
}
 
struct HuffmanNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (minHeap->size > 1) {
        struct HuffmanNode* left = extractMin(minHeap);
        struct HuffmanNode* right = extractMin(minHeap);
        struct HuffmanNode* top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
 
void printCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);
    char data[n];
    int freq[n];
    printf("Enter characters: ");
    for (int i = 0; i < n; i++)
        scanf(" %c", &data[i]);
    printf("Enter their frequencies: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);
    struct HuffmanNode* root = buildHuffmanTree(data, freq, n);
    int arr[100], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);
    return 0;
}
