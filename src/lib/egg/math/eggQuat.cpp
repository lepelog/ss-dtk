#include <egg/math/eggQuat.h>

namespace EGG {

f32 Quatf::norm() {
    return real*real + vector.squaredLength(); 
}

void Quatf::normalise() {
    f32 normval = Math<f32>::sqrt(norm());
    if (normval > 0.0f) {
        multScaler(1.0f / normval); 
    }
    
}

}