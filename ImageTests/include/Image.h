#ifndef IMAGE_H
#define IMAGE_H

#include <memory>

class Image
{
  public :
    Image()=default;
    Image(unsigned int _width, unsigned int _height, unsigned int _channels=3);
    ~Image() noexcept =default;
    Image(const Image &);
    Image & operator=(const Image &)=default;
    Image(Image &&)=default;
    Image & operator=(Image &&)=default;
    unsigned int width() const noexcept;
    unsigned int height() const noexcept;
    unsigned int channels() const noexcept;
    unsigned char * pixels();
    void setPixel(unsigned int _x, unsigned int _y, unsigned char _r, unsigned char _g, unsigned _b);
    void getPixel(unsigned int _x, unsigned int _y, unsigned char &o_r, unsigned char &o_g, unsigned char &o_b);
    bool write(const std::string &_fname);
    void clearColour(unsigned char _r, unsigned char _g, unsigned char _b);

private :
      unsigned int m_width=0;
      unsigned int m_height=0;
      unsigned int m_channels=3;
      std::unique_ptr<unsigned char []> m_pixels;

};

#endif
