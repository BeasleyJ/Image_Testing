
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

void Image::plotline(int _x0, int _y0, int _x1, int _y1)
{
    if(std::abs(_y1 - _y0) < std::abs(_x1 - _x0))
    {
            if(_x0 > _x1)
            {
                plotlinelow(_x1, _y1, _x0, _y0);
            }
            else
            {
                plotlinelow(_x0, _y0, _x1, _y1);
            }
    }
    else
    {
        if(_y0 > _y1)
        {
            plotlinehigh(_x1, _y1, _x0, _y0);
        }
        else
        {
           plotlinehigh(_x0, _y0, _x1, _y1);
        }
    }

}

void Image::plotlinelow(int _x0, int _y0, int _x1, int _y1)
{
    int dx = _x1 - _x0;
    int dy = _y1 - _y0;
    int yi = 1;
    if(dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    int D = 2 * dy - dx;
    int y = _y0;
    for(int x=_x0; x<_x1; ++x)
    {
        setPixel(x,y,255,0,0);
        if (D > 0)
        {
            y = y + yi;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
     }
}

void Image::plotlinehigh(int _x0, int _y0, int _x1, int _y1)
{
    int dx = _x1 - _x0;
    int dy = _y1 - _y0;
    int xi = 1;
    if(dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    int D = 2 * dx - dy;
    int x = _x0;
    for(int y=_y0; y<_y1; ++y)
    {
        setPixel(x,y,255,0,0);
        if (D > 0)
        {
            x = x + xi;
            D = D - 2 * dy;
        }
        D = D + 2 * dx;
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

