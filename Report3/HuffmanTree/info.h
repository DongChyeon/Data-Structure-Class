#ifndef _INFO_
#define _INFO_

typedef struct binaryInfo* BinaryInfo;
typedef struct item {
    char character;
    char* code;
} item;
typedef struct binaryInfo {
    int size;
    item* items;
} binaryInfo;

BinaryInfo makeInfo();
void addItem(BinaryInfo info, char character, char* code);
void deleteInfo(BinaryInfo info);
void printCode(BinaryInfo info, char character);

#endif