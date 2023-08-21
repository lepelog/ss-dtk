#pragma once

#include <types.h>
#include <egg/math/eggMath.h>
#include <nw4r/math/vec.h>
namespace EGG
{

class Vector3f : public nw4r::math::VEC3  {
public:
    // __cl__Q23EGG8Vector3fFi
    f32 operator()(int i) { return ((f32*)this)[i]; }
    // __ct__Q23EGG8Vector3fFv
    Vector3f() {}
    // __ct__Q23EGG8Vector3fFfff
    Vector3f(f32 fx, f32 fy, f32 fz) : VEC3(fx, fy, fz) {}
    // __ct__Q23EGG8Vector3fFRCQ34nw4r4math4VEC3
    Vector3f(const VEC3& v) { x = v.x; y = v.y; z = v.z; }
    // __ct__Q23EGG8Vector3fFRCQ23EGG8Vector3f
    Vector3f(const Vector3f& v) { x = v.x; y = v.y; z = v.z; }
    // __dt__Q23EGG8Vector3fFv
    // ~Vector3f() {}

    inline void set(f32 fx, f32 fy, f32 fz) { x = fx; y = fy; z = fz; }

    inline f32 squaredLength() const { return x*x + y*y + z*z; }
    inline f32 length() const { return Math<f32>::sqrt(squaredLength()); }
    // distance__Q23EGG8Vector3fCFRCQ23EGG8Vector3f

    inline void multScalar(f32 f) { x*=f; y*=f; z*=f; }
    inline void divScalar(f32 f) { multScalar(1.0f / f); }

    // __as__Q23EGG8Vector3fFRCQ34nw4r4math4VEC3
    inline Vector3f& operator=(const VEC3& v) {  x = v.x; y = v.y; z = v.z; return *this; }
    // __as__Q23EGG8Vector3fFRCQ23EGG8Vector3f
    inline Vector3f& operator=(const Vector3f& v) {  x = v.x; y = v.y; z = v.z; return *this; }
    // __pl__Q23EGG8Vector3fCFRCQ23EGG8Vector3f
    inline  Vector3f operator+(const Vector3f& v) { return Vector3f(x+v.x, y+v.y, z+v.z); }
    // __apl__Q23EGG8Vector3fFRCQ23EGG8Vector3f
    inline Vector3f& operator+=(const Vector3f& v) { x+=v.x; y+=v.y; z+=v.z; return *this; }
    // __mi__Q23EGG8Vector3fCFv
    inline Vector3f operator-() const{ return Vector3f(-x, -y, -z); }
    // __mi__Q23EGG8Vector3fCFRCQ23EGG8Vector3f
    inline Vector3f operator-(const Vector3f& v) { return Vector3f(x-v.x, y-v.y, z-v.z); }
    // __ami__Q23EGG8Vector3fFRCQ23EGG8Vector3f
    inline Vector3f& operator-=(const Vector3f& v) { x-=v.x; y-=v.y; z-=v.z; return *this; }
    // __ml__Q23EGG8Vector3fCFf
    inline Vector3f operator*(f32 f) const { return Vector3f(x*f,y*f,z*f); }
    // __amu__Q23EGG8Vector3fFf
    inline Vector3f& operator*=(f32 f) { multScalar(f); return *this; }
    // __dv__Q23EGG8Vector3fCFf
    inline Vector3f operator/(f32 f) const { return Vector3f(x/f,y/f,z/f); } // could do temp then divScalar
    // __adv__Q23EGG8Vector3fCFf // assumed
    inline  Vector3f& operator/=(f32 f) { divScalar(f); return *this; }
    // __ne__Q23EGG8Vector3fCFRCQ23EGG8Vector3f
    inline  bool operator!=(const Vector3f& v) { return x != v.x || y != v.y || z != v.z; }

    // vtx__Q23EGG8Vector3fCFv
    // nrm__Q23EGG8Vector3fCFv
    // calcHalfNormalVector__Q23EGG8Vector3fFRCQ23EGG8Vector3f
    // normalize__Q23EGG8Vector3fFv
    // normalise__Q23EGG8Vector3fFv
    /* 8049bcc0 */ void normalise();
    // dot__Q23EGG8Vector3fCFRCQ23EGG8Vector3f
    inline f32 dot(const Vector3f& v) const {
        return x*v.x + y*v.y + z*v.z;
    }
    // cross__Q23EGG8Vector3fCFRCQ23EGG8Vector3f
    inline Vector3f cross(const Vector3f& other) const {
        return Vector3f ( y*other.z - z*other.y,
                          z*other.x - y*other.x,
                          x*other.y - y*other.x );
    }
    /* 8049bd50 */ void setLength(Vector3f& src, f32 length);
    /* 8049be10 */ void setLength(f32 length);
    // isNan__Q23EGG8Vector3fCFv
    // isZero__Q23EGG8Vector3fCFf

// Operators
// Seen in BBA LinkerMap
// tex__Q23EGG8Vector2fCFv
// vtx__Q23EGG8Vector2fCFv
// distance__Q23EGG8Vector2fCFRCQ23EGG8Vector2f
// length__Q23EGG8Vector2fCFv
// squaredLength__Q23EGG8Vector2fCFv
// normalise__Q23EGG8Vector2fFv
// normalize__Q23EGG8Vector2fFv
// dot__Q23EGG8Vector2fCFRCQ23EGG8Vector2f
// set__Q23EGG8Vector2fFff
// __ct__Q23EGG8Vector2fFv
// __ct__Q23EGG8Vector2fFff
// __ct__Q23EGG8Vector2fFRCQ23EGG8Vector2f
// __dt__Q23EGG8Vector2fFv
// __as__Q23EGG8Vector2fFRCQ23EGG8Vector2f
// __opPf__Q23EGG8Vector2fFv
// __pl__Q23EGG8Vector2fCFRCQ23EGG8Vector2f
// __apl__Q23EGG8Vector2fFRCQ23EGG8Vector2f
// __mi__Q23EGG8Vector2fCFRCQ23EGG8Vector2f
// __ami__Q23EGG8Vector2fFRCQ23EGG8Vector2f
// __ml__Q23EGG8Vector2fCFf
// __amu__Q23EGG8Vector2fFf
// __dv__Q23EGG8Vector2fCFf
// __adv__Q23EGG8Vector2fFf
// __eq__Q23EGG8Vector2fCFRCQ23EGG8Vector2f
// __ne__Q23EGG8Vector2fCFRCQ23EGG8Vector2f
//
// __ml__3EGGFfRCQ23EGG8Vector2f

public:
    /* 80674c30 */ static Vector3f zero;
    /* 80674c3c */ static Vector3f ex;
    /* 80674c48 */ static Vector3f ey;
    /* 80674c54 */ static Vector3f ez;
};
// outside ops
// __ml__3EGGFfRCQ23EGG8Vector3f
inline Vector3f operator*(f32 f, const Vector3f& v) {
    return v * f;
}


struct Vector2f {
    f32 x,y;

public:
    /* 805767c0 */ static Vector2f zero;
    /* 805767c8 */ static Vector2f ex;
    /* 805767d0 */ static Vector2f ey;
};

struct Vector3s {
    s16 x,y,z;
public:
    /* 805767d8 */ static Vector3s zero;
    /* 805767e0 */ static Vector3s ex;
    /* 805767e8 */ static Vector3s ey;
    /* 805767f0 */ static Vector3s ez;
};

} // namespace EGG
