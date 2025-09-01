#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

using namespace std;

// Constants

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385;

// Utility Functions

inline float degrees_to_radians(float degrees) {
    return degrees * pi / 180;
}

// Common Headers
#include <random>
#include <functional>


inline float random_float() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

inline float random_float(float min, float max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_float();
}

inline float random_float_mt() {
    std::mt19937::result_type seed = time(0);
    auto gen = std::bind(std::uniform_real_distribution<float>(0.0, 1.0), std::mt19937(seed));
    return gen();
}

inline float clamp(float x, float min, float max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

inline float random_float2() {
    static std::uniform_real_distribution<float> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline vec3 randomInUnitSphere(){
    //srand(time(NULL));
    vec3 out(random_float()-.5,random_float()-.5,random_float()-.5);
    return out.normalized() * random_float();
}

inline vec3 randomV() {
    return vec3(random_float(), random_float(), random_float());
}

inline vec3 random(float min, float max) {
    return vec3(random_float(min,max), random_float(min,max), random_float(min,max));
}

inline vec3 random_unit_vector() {
    while (true) {
        auto p = random(-1,1);
        auto lensq = p.length2();
        if (1e-160 < lensq && lensq <= 1)
            return p / sqrt(lensq);
    }
}

inline vec3 random_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (on_unit_sphere.dot(normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

inline vec3 linear_to_gamma(vec3 linear_component) {
    for (int i=0; i<3; ++i) {
        if (linear_component[i] > 0) {
            linear_component[i] = std::sqrt(linear_component[i]);
        } else {
            linear_component[i] = 0;
        }

    }

    return linear_component;
}

inline bool near_zero(vec3 e) {
    // Return true if the vector is close to zero in all dimensions.
    auto s = 1e-8;
    return (std::fabs(e[0]) < s) && (std::fabs(e[1]) < s) && (std::fabs(e[2]) < s);
}

inline vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*v.dot(n)*n;
}

#endif
