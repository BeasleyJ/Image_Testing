
#include "Image.h"
#include <iostream>
#include <OpenImageIO/imageio.h>
#include <cstring>

Image::Image(unsigned int _width, unsigned int _height, unsigned int _channels)
{
    m_width=_width;
    m_height=_height;
    m_channels=_channels;
    m_pixels = std::make_unique<unsigned char []>(m_width*m_height*m_channels);
}

Image::Image(const Image &_c)
{
    m_width=_c.m_width;
    m_height=_c.m_height;
    m_channels=_c.m_channels;
    m_pixels = std::make_unique<unsigned char []>(m_width*m_height*m_channels);
    memcpy(m_pixels.get(),_c.m_pixels.get(),m_width*m_height*m_channels);
}


void Image::setPixel(unsigned int _x, unsigned int _y, unsigned char _r, unsigned char _g, unsigned _b)
{

    size_t index=(m_width*m_channels*_y)+m_channels*_x;
    m_pixels[index]=_r;
    m_pixels[index+1]=_g;
    m_pixels[index+2]=_b;

}


void Image::getPixel(unsigned int _x, unsigned int _y, unsigned char &o_r, unsigned char &o_g, unsigned char &o_b)
{
 size_t index=(m_width*m_channels*_y)+m_channels*_x;
 o_r=m_pixels[index];
 o_g=m_pixels[index+1];
 o_b=m_pixels[index+2];
}

bool Image::write(const std::string &_fname)
{
    using namespace OIIO;
    std::unique_ptr<ImageOutput> out = ImageOutput::create (_fname);
    if(!out)
    {
        return false;
    }
    bool success;
    ImageSpec spec (m_width,m_height,m_channels, TypeDesc::UINT8);
    success=out->open(_fname,spec);
    success=out->write_image(TypeDesc::UINT8,m_pixels.get());
    success=out->close();
    return success;
}

void Image::clearColour(unsigned char _r, unsigned char _g, unsigned char _b)
{
    for(size_t y=0; y<m_height; ++y)
    {
        for(size_t x=0; x<m_width; ++x)
        {
            setPixel(x,y,_r,_g,_b);
        }
    }
}



unsigned char * Image::pixels()
{
    return m_pixels.get();
}


unsigned int Image::width() const noexcept
{
    return m_width;
}

unsigned int Image::height() const noexcept
{
    return m_height;
}


unsigned int Image::channels() const noexcept
{
    return m_channels;
}

