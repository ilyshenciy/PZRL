#include "StringUtil.h"

int stringIsChar(const char* str) {
    int result = 0;
    while (*str) {
        if (*str >= 'A' && *str <= 'Z' || *str >= 'a' && *str <= 'z' || *str == ' ') {
            result = 1;
        }
        else {
            result = 0;
            break;
        }
        ++str;
    }

    return result;
}

int stringIsNumbers(const char* str) {
    int size = strlen(str);
    int itsNumber = 0;
    while ((str[itsNumber] >= '0') && (str[itsNumber] <= '9')) {
        ++itsNumber;
    }
    if (itsNumber == size) {
        return 1;
    } else {
        return 0;
    }
}

void stringSpaceDeleteMuttable(char* str) {
    int size = strlen(str);
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z'))
            || ((str[i] >= '0') && (str[i] <= '9')) || (str[i] == ' '))
        {
            str[j] = str[i];
            ++j;
        }
    }
    str[j] = '\0';
}

char* stringSpaceDeleteIMuttable(const char* str) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res, str);
    stringSpaceDeleteMuttable(res);

    return res;
}

void stringDeleteStripsEndMuttable(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (str[i] == ' ') {
        ++i;
    }
    while (str[j] == ' ') {
        ++j;
    }
    for (int k = 0; k < j; ++k, ++i) {
        str[k] = str[i];
    }
    str[j - 1] = '\0';
}

char* stringDeleteStripsEndIMuttable(const char* str) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res, str);
    stringDeleteStripsEndMuttable(res);

    return res;
}

void stringDeleteStripsBeginingMuttable(char* str) {
    int i;
    int j;

    for (i = j = 0; str[i] != '\0'; ++i) {
        if (str[i] != ' ') {
            str[++j] = str[i];
        }
    }
}

char* stringDeleteStripsBeginingIMuttable(const char* str) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res, str);
    stringDeleteStripsBeginingMuttable(res);

    return res;
}
void stringUpperMuttable(char* str) {
    for (int i = 0; str[i]; ++i) {
        str[i] = toupper(str[i]);
    }
}

char* stringUpperIMuttable(const char* str) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res, str);
    stringUpperMuttable(res);

    return res;
}

void stringLowwerMuttable(char* str) {
    for (int i = 0; str[i]; ++i) {
        str[i] = tolower(str[i]);
    }
}

char* stringLowwerIMuttable(const char* str) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res, str);
    stringLowwerMuttable(res);

    return res;
}