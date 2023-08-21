#include <egg/math/eggQuat.h>

namespace EGG {

f32 Quatf::norm() {
    return w*w + vec.squaredLength();
}

void Quatf::normalise() {
    f32 normval = Math<f32>::sqrt(norm());
    if (normval > 0.0f) {
        multScalar(Math<f32>::inv(normval));
    }

}

Quatf Quatf::conjugate(){
    return Quatf(w, -1.0f * vec); 
}

Vector3f Quatf::rotateVector(const Vector3f& v) {
    Quatf q0 = conjugate();
    return (*this * v * q0).vec;
}


}