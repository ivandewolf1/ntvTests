# ntvTests
test code for the ntv nano templated vectors library

## Houdini tests

the hip dir contains a houdini scene file, and a C++ source code file for a function that gets read in as an inlinecpp python module in Houdini. 
This allows easy access to the suite of Houdini geometry display, modification, and analysis tools on geometry set up using the ntv libraries.

## Ray Tracing In One Weekend test

this implements the ray tracer in "ray tracing in one weekend" using the ntv headers instead off the vec3 class implemented in the course.
It seemed a complex enough yet simple enough codebase to make use of various features in the ntv tools. 