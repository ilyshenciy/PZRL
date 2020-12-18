#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Coder.h"
#include "StringUtil.h"

char *concat(int argc, char* argv[]) {
    int len = 0;

    for (int i = 2; i < argc - 1; ++i) {
        len += strlen(argv[i]) + 1;
    }
    char* str = malloc((len + 1) * (sizeof(char)));

    for (int i = 2; i < argc - 1; ++i) {
        strcat(str, argv[i]);
        strcat(str, " ");
    }
    return str;
}

int main(int argc, char* argv[]) {
    char* command = argv[0];
    char* cipher = argv[1];
    char* str = concat(argc, argv);
    char* key = argv[argc - 1];


    if (strcmp(cipher, "--xor") == 0 && !isLetter(key)) {
        printf("Fatal error: Key for XOR algorithm must be a number!\n");
        exit(0);
    }
    
    if (strcmp(command, "./encoder") == 0) {
        if (strcmp(cipher, "--caesar") == 0) {
            stringLowwerMuttable(str);
            muttableCaesarEncoder(str, atoi(key));
            printf("%s\n", str);
        }
        else if (strcmp(cipher, "--xor") == 0) {
            stringLowwerMuttable(str);
            muttableXorCoder(str, key);
            printf("%s\n", str);
        }
        else {
            printf("Fatal error: Unknown algorithm. Available:\n--caesar\n--xor\n");
        }
    }

    if (strcmp(command, "./decoded") == 0) {
        if (strcmp(cipher, "--caesar") == 0) {
            int pass = atoi(key) * (-1);
            muttableCaesarDecoder(str, pass);
            printf("%s\n", str);
        }
        else if (strcmp(cipher, "--xor") == 0) {
            muttableXorCoder(str, key);
            printf("%s\n", str);
            }
        else {
            printf("Fatal error: Unknown algorithm. Available:\n--caesar\n--xor\n");
        }
    }
    return 0;
}
