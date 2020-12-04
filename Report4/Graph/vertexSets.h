#include <iostream>
#define MAX_VTXS 256

class VertexSets {
private:
    int parent[MAX_VTXS];
    int nSets;
public:
    VertexSets(int n);
    bool isRoot(int id);
    int findSet(int vtx);
    void unionSets(int set1, int set2);
};