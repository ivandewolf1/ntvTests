#ifndef RAY_H
#define RAY_H

#include <nvec3.h>

#ifndef vec3
#define vec3 ntv::nvec3<float>

class ray {
    public:
        ray() {}
        ray(const vec3& origin, const vec3& direction)
            : orig(origin), dir(direction)
        {}

        vec3 origin() const  { return orig; }
        vec3 direction() const { return dir; }

        vec3 at(float t) const {
           return vec3(orig + (t * dir));
        }

    public:
        vec3 orig;
        vec3 dir;
};

#endif
#endif