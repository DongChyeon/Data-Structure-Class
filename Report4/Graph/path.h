#include <iostream>

class Path {
private:
    int weight;
    int vtx1;
    int vtx2;
public:
    Path();
    Path(int weight, int vtx1, int vtx2);
    void setPath(int weight, int vtx1, int vtx2);
    int getWeight();
    int getVtx1();
    int getVtx2();
};