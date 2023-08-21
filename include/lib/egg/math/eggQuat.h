#pragma once

#include <types.h>
#include <egg/math/eggVector.h>

namespace EGG
{

class Quatf {
public:
    Vector3f vec;
    f32 w;
public:
    Quatf() {}
    Quatf(f32 fw, const Vector3f& v) {
        set(fw, v);
    }
    void multScalar(f32 f) { w*=f; vec.multScalar(f); }
    // Quatf(f32, Vector3f);
    /* 8049b390 */ void set(f32 fw, f32 fx, f32 fy, f32 fz);
    inline void set(f32 fw, const Vector3f& v){
        w = fw;
        vec = v;
    }
    /* 8049b3b0 */ void setAxisRotation(const Vector3f&, f32);
    /* 8049b450 */ f32 norm();
    /* 8049b480 */ void normalise();
    /* 8049b500 */ Quatf conjugate();
    /* 8049b550 */ Vector3f rotateVector(const Vector3f&);
    /* 8049b800 */ void slerpTo(const Quatf&, f32, Quatf& out) const;
    /* 8049b800 */ void limitSlerpTo(const Quatf&, f32, Quatf& out, f32) const;
    /* 8049bbb0 */ void makeVectorRotation(Vector3f&, Vector3f&);

    // __ct__Q23EGG5QuatfFRCQ23EGG5Quatf
    // __ct__Q23EGG5QuatfFRQ23EGG5Quatf
    // __dt__Q23EGG5QuatfFv
    // __as__Q23EGG5QuatfFRCQ23EGG5Quatf
    // setUnit__Q23EGG5QuatfFv
    // set__Q23EGG5QuatfFffff
    // set__Q23EGG5QuatfFfRCQ23EGG8Vector3f
    // setRPY__Q23EGG5QuatfFfff
    // setRPY__Q23EGG5QuatfFRCQ23EGG8Vector3f
    // calcRPY__Q23EGG5QuatfFv
    // inverse__Q23EGG5QuatfFv
    // rotateVectorInv__Q23EGG5QuatfFRCQ23EGG8Vector3f
    // makeVectorRotationLimit__Q23EGG5QuatfFRQ23EGG8Vector3fRQ23EGG8Vector3ff
    // applyAngularVelocity__Q23EGG5QuatfFRCQ23EGG8Vector3ff
};

// __ml__3EGGFRCQ23EGG5QuatfRCQ23EGG8Vector3f
inline Quatf operator*(const Quatf& q, const Vector3f& v){
    Vector3f crossP = q.vec.cross(v); // cross__Q23EGG8Vector3fCFRCQ23EGG8Vector3f
    Vector3f mult = v * q.w;
    f32 real = -(q.vec.z*v.z + q.vec.x*v.x + q.vec.y*v.y);
    return Quatf(real, crossP + mult);
}

// __ml__3EGGFRCQ23EGG5QuatfRCQ23EGG5Quatf
inline Quatf operator*(const Quatf& q1, const Quatf& q2){
    Vector3f cross0 = q1.vec.cross(q2.vec);
    Vector3f mullw1 = q2.vec * q1.w;
    Vector3f cross_mull = cross0  + mullw1;
    Vector3f mullw0 = q1.vec * q2.w;

    f32 val = q1.w*q2.w - q1.vec.dot(q2.vec);
    return Quatf(val, cross_mull + mullw0);

}
// __pl__3EGGFRCQ23EGG5QuatfRCQ23EGG5Quatf
// __ml__3EGGFRCQ23EGG5Quatff

} // namespace EGG
