#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>
#include "vec06.h"
const float gamma = 1;
const float m = 1;
const float kT = 1;
const float dt = 1;



Vec new_a(Vec v, Vec r)
{
    Vec rv;
    float fact = 1 / (m * (1 + 0.5 * gamma *dt));
    return fact * (
        - m * gamma * v
        + rv.randomvec(sqrt(2*m*gamma*kT/dt)));
}

Vec new_v(Vec a, Vec v)
{
    return v + a*dt;
}
 
Vec new_r(Vec v, Vec r)
{
    return r + v*dt;
}



 int main()
 {
    using namespace std;
    srand((unsigned)time(NULL));
    int nstep = 100;
    Vec r;
    Vec v;
    Vec a;
    r.init(vector<float>{0, 0});
    v.init(vector<float>{0, 0});
    a.init(vector<float>{0, 0});
    for(int i = 0; i< nstep; i++)
    {
        a = new_a(v, r);
        v = new_v(a, v);
        r = new_r(v, r);
        cout<<r<<endl;
    }


 }