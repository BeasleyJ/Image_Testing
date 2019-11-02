#include <iostream>
#include <cstdlib>
#include "Image.h"
int main()
{
    constexpr size_t width=100;
    constexpr size_t height=100;

    std::cout<<"Line Drawing\n";
    Image myImage(width,height);
    myImage.clearColour(255,255,255);
    myImage.plotline(0,0,100,100);
    myImage.plotline(100,0,0,100);
    myImage.write("image.png");

    return EXIT_SUCCESS;
}
