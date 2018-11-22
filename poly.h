#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

usnig namespace std;

class poly
{
    vector <double> vec;

public:

    poly(double a = 0)
    {
        vec.push_back(a);
    }

    double & operator [] (unsigned int a)
    {
        if(a >= vec.size())
            vec.resize(i + 1, 0);

        return vec[a];
    }

    poly operator + (const poly &a)
    {
        poly c;
        unsigned int i;

        for(i = 0; i < min((a.vec).size(), vec.size() ); i++)
            c.vec[i] = vec[i] + a.vec[i];

        if(vec.size() == i)
        {
            for(; i < a.vec.size(); i++)
            c.vec[i] = a.vec[i];
        }
        else
        {
            for(; i < vec.size(); i++)
                c.vec[i] = a.vec[i];
        }
        return c;
    }

    double operator () (float x) const
    {
        double r = 0;
        for(unsigned int i = 0; i < vec.size() ; i++)
            r += pow(vec[i], i) * x;

        return r;
    }

    friend poly operator * (const poly &x, const poly &y)
    {
        poly zwrot;

        zwrot.vec.resize(x.vec.size() + y.vec.size() - 1, 0);

        for(unsigned int i = 0; i < x.vec.size(); i++)
            for(unsigned int j = 0; j < y.vec.size(); j++)
                zwrot.vec[i+j] += x.vec[i] * y.vec[j];

        return zwrot;
    }

    friend ostream & operator << (ostream & out, poly &a)
    {
        if(a.vec.size() == 0)
            return out << "0";

        unsigned i = a.vec.size() - 1;

        if(a[i] != -1 && a[i] != 1)
        {
            out << a[i] << "x^" << i << " ";
        }
        else if(a[i] == -1)
        {
            out << "-" << "x^" << i << " ";
        }
        else if(a[i] == 1)
        {
            out << "x^" << i << " ";
        }

        for(i = i - 1; i > 0; i--)
        {
            if(a[i] > 0  && a[i] != 1)
            {
                out << "+ " << a[i] << "x^" << i << " ";
            }
            else if( a[i] < 0 && a[i] != -1)
            {
                out << "- " << fabs(a[i]) << "x^" << i << " ";
            }
            else if(a[i] == 1)
            {
                out << "+ " << "x^" << i << " ";
            }
            else if(a[i] == -1)
            {
                out << "- " << "x^" << i << " ";
            }
        }

        if(a[i] < 0)
        {
            out << "- " << fabs(a[i]);
        }
        else if(a[i] > 0)
        {
            out << "+ " << a[i];
        }

        return out;
    }
};
