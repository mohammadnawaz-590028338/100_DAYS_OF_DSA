#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0}; // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        freq[index]++;

        // if frequency becomes 2 → first repeated
        if (freq[index] == 2) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
