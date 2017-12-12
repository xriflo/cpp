#include <iostream>
#include "Engine/Vertex.hpp"
#include <assert.h>



using namespace std;
using namespace Engine;
int main()
{
    Vertex v(2,3,4), u(100,100,100);
    assert(ToString(v)=="(2,3,4)" && "Method ToString failed");
    assert(ToString(-v)=="(-2,-3,-4)" && "Operator- failed");
    assert(ToString(v)=="(2,3,4)" && "Method ToString failed");

    v+=u;
    assert(ToString(v)=="(102,103,104)" && "Operator+= failed");
    assert(ToString(u)=="(100,100,100)" && "Operator+= failed");

    v-=u;
    assert(ToString(v)=="(2,3,4)" && "Operator-= failed");
    assert(ToString(u)=="(100,100,100)" && "Operator-= failed");

    Vertex w = v+u;
    assert(ToString(v)=="(2,3,4)" && "Operator+ failed");
    assert(ToString(u)=="(100,100,100)" && "Operator+ failed");
    assert(ToString(w)=="(102,103,104)" && "Operator+ failed");

    std::ostringstream os;
    os<<w;
    assert(os.str()=="(102,103,104)" && "Operator+ failed");

    cin>>w;
}