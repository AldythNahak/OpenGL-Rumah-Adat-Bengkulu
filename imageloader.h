#ifndef IMAGELOADER_H
#define IMAGELOADER_H

class Image {
public:
    char* pixels;
    int width;
    int height;

    Image(char* ps, int w, int h);
    ~Image();
};

Image* loadBMP(const char* filename);

#endif
