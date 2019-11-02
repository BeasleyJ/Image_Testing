#include <iostream>
#include <cstdlib>
#include "Image.h"
int main()
{
    constexpr size_t width=300;
    constexpr size_t height=300;

    std::cout<<"Image Sequence\n";
    Image myImage(width,height);
    for(int current=0; current<width; ++current)
    {
        myImage.clearColour(255,255,255);
        for(size_t x=0; x<=current; ++x)
        {
            myImage.setPixel(x,(height/2)-1,255,0,0);
            myImage.setPixel(x,height/2,255,0,0);
            myImage.setPixel(x,(height/2)+1,255,0,0);
        }
        char fname[100];
        std::cout<<fname<<'\n';
        sprintf(fname,"images/test.%04ld.png",current);
        std::cout<<"Writing file "<<fname<<'\n';
        myImage.write(fname);
    }
    return EXIT_SUCCESS;
}
