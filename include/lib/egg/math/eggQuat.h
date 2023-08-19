#pragma once

#include <types.h>
#include <egg/math/eggVector.h>

namespace EGG
{

class Quatf {
public:
    Vector3f vector;
    f32 real; 
public:
    Quatf() {}
    // Quatf(f32, Vector3f);

    /* 8049b390 */ void set(f32 fw, f32 fx, f32 fy, f32 fz);
    /* 8049b3b0 */ void setAxisRotation(const Vector3f&, f32);
    /* 8049b450 */ f32 norm(); 
    /* 8049b480 */ void normalise();
    /* 8049b500 */ void conjugate();
    /* 8049b550 */ Vector3f rotateVector(const Vector3f&);
    /* 8049b800 */ void slerpTo(const Quatf&, f32, Quatf& out) const;
    /* 8049b800 */ void limitSlerpTo(const Quatf&, f32, Quatf& out, f32) const;
    /* 8049bbb0 */ void makeVectorRotation(Vector3f&, Vector3f&);
};
} // namespace EGG
