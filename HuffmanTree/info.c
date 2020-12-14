#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"

BinaryInfo makeInfo() {
    BinaryInfo info = (BinaryInfo)malloc(sizeof(struct binaryInfo));
    info->items = (item *)malloc(sizeof(struct item) * 128);
    info->size = 0;

    return info;
}

void addItem(BinaryInfo info, char character, char* code) {
    info->items[info->size].character = character;
    info->items[info->size].code = (char*)malloc(sizeof(char) * 100);
    strcpy_s(info->items[info->size].code, sizeof(char) * 100, code);
    info->size++;
}

void deleteInfo(BinaryInfo info) {
    free(info);
}

char* searchCode(BinaryInfo info, char character) {
    for (int i = 0; i < info->size; i++) {
        if (info->items[i].character == character) {
            return info->items[i].code;
        }
    }
}