#include <iostream>
#include <cstdlib>
#include "Image.h"
int main()
{
    constexpr size_t width=100;
    constexpr size_t height=100;

    std::cout<<"Image Sequence\n";
    Image myImage(width,height);
    for(int current=0; current<width; ++current)
    {
        myImage.clearColour(255,255,255);
        char fname[100];
        sprintf(fname,"images/test.%d.png",current);
        std::cout<<"Writing file "<<fname<<'/n/';
        myImage.write("images/test.png");
    }
    return EXIT_SUCCESS;
}
