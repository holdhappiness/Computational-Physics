#ifndef Vec_H
#define Vec_H

#include <vector>
#include <iostream>
#include <random>
#include <math.h>
#include <chrono>

using namespace std;

class Vec
{
public:

    vector<float> cord;

    Vec();
    Vec(int);
    void init(const vector<float>&);
    int getdim() const;
    float readdim(int) const;


    Vec add(const Vec&);
    Vec sub(const Vec&);
    Vec mult(float);
    Vec div(float);
    Vec nomalize();
    Vec randomvec(float);
    float dot(const Vec&);
    float mag() const;


    Vec operator+(const Vec&);
    Vec operator-(const Vec&);
    Vec operator*(float);
    float operator*(const Vec& v);
    Vec operator/(float);
    Vec& operator+=(const Vec&);
    Vec& operator-=(const Vec&);
    Vec& operator*=(float);

    friend Vec operator*(float, const Vec&);
    friend ostream& operator<<(ostream&, const Vec&);



};


#endif