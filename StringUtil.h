#ifndef STRINGUTIL_H_INCLUDED
#define STRINGUTIL_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int stringIsChar(const char* str);
int stringIsNumbers(const char* str);
void stringSpaceDeleteMuttable(char* str);
char* stringSpaceDeleteIMuttable(const char* str);
void stringDeleteStripsEndMuttable(char* str);
char* stringDeleteStripsEndIMuttable(const char* str);
void stringDeleteStripsBeginingMuttable(char* str);
char* stringDeleteStripsBeginingIMuttable(const char* str);
void stringUpperMuttable(char* str);
char* stringUpperIMuttable(const char* str);
void stringLowwerMuttable(char* str);
char* stringLowwerIMuttable(const char* str);

#endif
