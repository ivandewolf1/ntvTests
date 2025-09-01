# 3  The vec3 Class

In the book, this section builds up a small library, where we instead use the NTV library. 

On my linux computer, I have the NTV library in a directory called /job
so, to use this library in a cmake (clion) workflow, simply add this to the CMakeLists.txt:
include_directories(/job/ntv/src/)

This allows you to include the .h files from the project.
#include <nvec3.h>

I simplified it a bit with a define that sets the template to float
#define vec3 ntv::nvec3<float>

which allows us to cut-and-paste a fair amount of code from the original course. 
