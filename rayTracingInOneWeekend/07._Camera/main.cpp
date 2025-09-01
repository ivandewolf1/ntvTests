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
using namespace std;

/*void nvecToArray(float* image, int index, vec3 pixel_color) {
    image[index + 0] = pixel_color[0];
    image[index + 1] = pixel_color[1];
    image[index + 2] = pixel_color[2];
}*/

vec3 ray_color(const ray& r, const hittable& world) {
        hit_record rec;
        if (world.hit(r, interval(0, infinity), rec)) {
            return 0.5 * (rec.normal + vec3(1,1,1));
        }

        vec3 unit_direction = r.direction().normalized();
    auto a = 0.5*(unit_direction[1] + 1.0);
    return (1.0-a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);
}


int main(int argc, const char** argv) {
    // Image

    /*auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // World

    hittable_list world;

    world.add(make_shared<sphere>(vec3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(vec3(0,-100.5,-1), 100));
    // Camera

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
    auto camera_center = vec3 (0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3 (viewport_width, 0, 0);
    auto viewport_v = vec3 (0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center
                             - vec3 (0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Render
    auto* image = new float[3 * image_width * image_height];
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0, idx = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++, idx += 3) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            vec3 pixel_color = ray_color(r, world);
            nvecToArray(image, idx, pixel_color);
        }
    }
    Exr(argc < 2 ? "../test.exr" : argv[1], image_width, image_height, image);
    delete [] image;*/
    hittable_list world;

    world.add(make_shared<sphere>(vec3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(vec3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;

    cam.render(world);

}
