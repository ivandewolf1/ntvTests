#include <iostream>
#include "nanoExr.h"
#include <nvec3.h>
#define vec3 ntv::nvec3<float>
#include "ray.h"
#include "rtweekend.h"
#include "sphere.h"
#include "hittable.h"
#include "hittable_list.h"
#include "camera.h"
#include "interval.h"
using namespace std;


/*vec3 ray_color(const ray& r, const hittable& world) {
        hit_record rec;
        if (world.hit(r, interval(0, infinity), rec)) {
            return 0.5 * (rec.normal + vec3(1,1,1));
        }

        vec3 unit_direction = r.direction().normalized();
    auto a = 0.5*(unit_direction[1] + 1.0);
    return (1.0-a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);
}*/


int main(int argc, const char** argv) {
    // Image
    hittable_list world;

    world.add(make_shared<sphere>(vec3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(vec3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.render(world);

}
