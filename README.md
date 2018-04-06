you need opencv, [figure it out](https://docs.opencv.org/master/df/d65/tutorial_table_of_content_introduction.html)

i just commited everything in the project directory

build output from eclipse build on my arch linux machine, not sure what's important but here it is:
```
make all 
Building file: ../src/slitscan.cpp
Invoking: GCC C++ Compiler
g++ -I/usr/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/slitscan.d" -MT"src/slitscan.d" -o "src/slitscan.o" "../src/slitscan.cpp"
Finished building: ../src/slitscan.cpp
 
Building target: slitscan
Invoking: GCC C++ Linker
g++ -L/usr/include/ -o "slitscan"  ./src/slitscan.o   -lopencv_core -lopencv_videoio -lopencv_imgproc -lopencv_video -lopencv_ml -lopencv_imgcodecs -lopencv_highgui
Finished building target: slitscan
```