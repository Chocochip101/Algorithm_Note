#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-9;

struct vector2
{
    double x, y;

    explicit vector2(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator == (const vector2& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }

    bool operator < (const vector2& rhs) const
    {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }

    vector2 operator + (const vector2& rhs) const
    {
        return vector2(x + rhs.x, y + rhs.y);
    }

    vector2 operator - (const vector2& rhs) const
    {
        return vector2(x - rhs.x, y - rhs.y);
    }

    vector2 operator * (double rhs) const
    {
        return vector2(x * rhs, y * rhs);
    }


    double norm() const { return hypot(x, y); }

    vector2 normalize() const
    {
        return vector2(x / norm(), y / norm());
    }
    double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }
    double dot(const vector2& rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }
    double cross(const vector2& rhs) const
    {
        return x * rhs.y - y * rhs.x;
    }
    vector2 project(const vector2& rhs) const
    {
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};