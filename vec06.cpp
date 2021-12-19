#include <vector>
#include <iostream>
#include <cmath>
#include "vec06.h"

using namespace std;
const float PI = 3.1415926;
Vec::Vec(){}

Vec::Vec(int a) {
   cord = vector<float> (a, 0);
}

void Vec::init(const vector<float>& v)
{
    cord = vector<float> (v.size(), 0);
    for (int i=0; i<v.size(); ++i) 
    {
        cord[i] = v[i];
    }
}

//return the number of dimensions
int Vec::getdim() const
{
    return cord.size();
} 

//pick out the value of a certain dimension
float Vec::readdim(int i) const
{
    return cord[i];
}

Vec Vec::add(const Vec& V)
{
    if(V.getdim()==cord.size())
    {
        Vec nV = Vec();
        nV.init(vector<float>(cord.size(), 0));
        for(int i=0;i<cord.size();i++)
        {
            nV.cord[i] = cord[i] + V.cord[i]; 
        }
        return nV;
    }
    else
    {
        cerr << "Dimensions are different!" << endl;
        exit(1);
    }
    
}

Vec Vec::sub(const Vec& V)
{
    if(V.getdim()==cord.size())
    {
        Vec nV = Vec();
        nV.init(vector<float>(cord.size(), 0));
        for(int i=0;i<cord.size();i++)
        {
            nV.cord[i] = cord[i] - V.cord[i]; 
        }
        return nV;
    }
    else
    {
        cerr << "Dimensions are different!" << endl;
        exit(1);
    }
    
}

Vec Vec::mult(float a)
{
    Vec nV = Vec();
    nV.init(vector<float>(cord.size(), 0));
    for(int i=0;i<cord.size();i++)
    {
        nV.cord[i] = cord[i] * a; 
    }
    return nV;    
}

Vec Vec::div(float a)
{
    Vec nV = Vec();
    nV.init(vector<float>(cord.size(), 0));
    for(int i=0;i<cord.size();i++)
    {
        nV.cord[i] = cord[i] / a; 
    }
    return nV;    
}

float Vec::dot(const Vec& V)
{
    if(V.getdim()==cord.size())
    {
        Vec nV = Vec();
        nV.init(vector<float>(cord.size(), 0));
        float s;
        for(int i=0;i<cord.size();i++)
        {
            s += cord[i] * V.cord[i]; 
        }
        return s;
    }
    else
    {
        cerr << "Dimensions are different!" << endl;
        exit(1);
    }
    
}

float Vec::mag() const
{
    float m = 0.0;
    for(int i=0; i< cord.size(); i++)
    {
        m += cord[i]*cord[i];
    }
    return sqrt(m);
}

Vec Vec::nomalize()
{
    float m = 0.0;
    for(int i=0; i< cord.size(); i++)
    {
        m += cord[i]*cord[i];
    }
    m = sqrt(m);
    Vec nV = Vec();
    nV.init(vector<float>(cord.size(), 0));
    for(int i=0;i<cord.size();i++)
    {
        nV.cord[i] = cord[i] / m; 
    }
    return nV; 
}

Vec Vec::randomvec(float mag)
{
    Vec nV = Vec(2);
    float theta = 2 * PI * rand();
    nV.init(vector<float>{mag*cos(theta), mag*sin(theta)});
    return nV
    ;
}

Vec Vec::operator+(const Vec& v) {
    return add(v);
}

Vec Vec::operator-(const Vec& v) {
    return sub(v);
}

Vec Vec::operator*(float a) {
    return mult(a);
}

Vec Vec::operator/(float a) {
    return div(a);
}
float Vec::operator*(const Vec& v) {
    return dot(v);
}

Vec& Vec::operator+=(const Vec& v) {
    for(int i=0; i<v.getdim(); ++i)
	cord[i] += v.readdim(i);
    return *this;
}

Vec& Vec::operator-=(const Vec& v) {
    for(int i=0; i<v.getdim(); ++i)
	cord[i] -= v.readdim(i);
    return *this;
}

Vec& Vec::operator*=(float fac) {
    for(int i=0; i<cord.size(); ++i)
	cord[i] *= fac;
    return *this;
}

Vec operator*(float d, const Vec& V){
    Vec nV = Vec();
    nV.init(vector<float>(V.getdim(), 0));
    for(int i=0; i<V.getdim(); ++i)
	nV.cord[i] = V.cord[i]*d;
    return nV;
};

ostream& operator<<(ostream& os, const Vec& v){
    os << v.readdim(0);
    for(int i=1; i<v.getdim(); i++)
        os << "  " << v.readdim(i);
    return os;
};
 

/*int main()
{
    //Vec arrow = Vec(5);
    Vec arrow = Vec();
    arrow.init(vector<float>{1,1,5,4,6});
    Vec brrow = Vec();
    brrow.init(vector<float>{1,2,3,0,6});
    Vec c = Vec();
    c = arrow.add(brrow);
    cout<<arrow.getdim()<<endl;
    cout<<arrow.readdim(1)<<endl;
    cout<<c.readdim(1)<<endl;
    cout<<c<<endl;
    //arrow.yieldall();
    
}*/
