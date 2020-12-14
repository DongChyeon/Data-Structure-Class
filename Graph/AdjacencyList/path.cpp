#include "path.h"

Path::Path() {}
Path::Path(int weight, int vtx1, int vtx2) {
    this->weight = weight;
    this->vtx1 = vtx1;
    this->vtx2 = vtx2;
}

void Path::setPath(int weight, int vtx1, int vtx2) { 
    this->weight = weight;
    this->vtx1 = vtx1;
    this->vtx2 = vtx2;
}
int Path::getWeight() { return weight; }
int Path::getVtx1() { return vtx1; }
int Path::getVtx2() { return vtx2; }