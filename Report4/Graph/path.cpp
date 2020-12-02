#include "path.h"

Path::Path() {}
Path::Path(int key, int vtx1, int vtx2) {
    this->key = key;
    this->vtx1 = vtx1;
    this->vtx2 = vtx2;
}

void Path::setKey(int key, int vtx1, int vtx2) { 
    this->key = key;
    this->vtx1 = vtx1;
    this->vtx2 = vtx2;
}
int Path::getKey() { return key; }
int Path::getVtx1() { return vtx1; }
int Path::getVtx2() { return vtx2; }