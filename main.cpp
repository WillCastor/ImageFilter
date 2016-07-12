/*
 *
 *
 * */

#include <Magick++.h>
#include <iostream>
#include "ImageCore.h"
using namespace std;
using namespace Magick;

int main(int argc, char **argv)
{
    InitializeMagick(*argv);
    Image image;

    try{
        image.quiet(false);
        image.read("/home/lishiyu/picture/test.jpg");

        PixelPacket *pixels = image.getPixels(0,0,image.baseColumns(),image.baseRows());

        LIHImageCore::LookUpTable lookUpTable;
        LIHImageCore::getNormalLookupTable(&lookUpTable,100,200,100,0.6);

        for(int i=0;i<image.baseColumns()*image.baseRows();i++){
            pixels[i].red = lookUpTable.red[pixels[i].red];
            pixels[i].green = lookUpTable.green[pixels[i].green];
            pixels[i].blue = lookUpTable.blue[pixels[i].blue];
        }
        image.syncPixels();

        image.write("/home/lishiyu/picture/out.jpg");
    }
    catch(Exception &error_) {
        cout<<"Caught exception: "<<error_.what()<<endl;
        return -1;
    }

    return 0;
}