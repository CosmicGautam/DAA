#include <stdio.h>
#include <string.h>
#define MAX 1000
void rle_compress(char *input, char *output) {
    int count, j = 0;
    int i;  // Moved declaration here
    for (i = 0; input[i] != '\0'; i++) {
        count = 1;
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }
        output[j++] = input[i];  // Store character
        j += sprintf(output + j, "%d", count);  // Store count
    }
    output[j] = '\0';  // Null-terminate string
}
void rle_decompress(char *input, char *output) {
    int j = 0, count;
    int i, k;  // Moved declarations here
    for (i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        count = 0;
        while (input[i + 1] >= '0' && input[i + 1] <= '9') {
            count = count * 10 + (input[i + 1] - '0');
            i++;
        }
        for (k = 0; k < count; k++) {
            output[j++] = ch;
        }
    }
    output[j] = '\0';  // Null-terminate string
}
int main() {
    char input[MAX], compressed[MAX], decompressed[MAX];
    printf("Enter a string: ");
    scanf("%s", input);
    rle_compress(input, compressed);
    printf("Compressed: %s\n", compressed);
    rle_decompress(compressed, decompressed);
    printf("Decompressed: %s\n", decompressed);
    return 0;
}
