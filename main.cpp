/*
 *
 *
 * */

#include <Magick++.h>
#include <iostream>
#include "ImageCore.h"
using namespace std;
using namespace Magick;

void learnStyle(Image src, Image effect)
{
    PixelPacket *pixels = src.getPixels(0,0,src.baseColumns(),src.baseRows());
    PixelPacket *stylePixels = effect.getPixels(0,0,effect.baseColumns(),effect.baseRows());
    int redChannelLookupTable[256] = {0};
    int redChannelCount[256] = {0};
    int greenChannelLookupTable[256] = {0};
    int greenChannelCount[256] = {0};
    int blueChannelLookupTable[256] = {0};
    int blueChannelCount[256] = {0};

    for(int i=0;i<src.baseColumns()*src.baseRows();i++){
        redChannelCount[pixels[i].red] += 1;
        redChannelLookupTable[pixels[i].red] += stylePixels[i].red;

        greenChannelCount[pixels[i].green] += 1;
        greenChannelLookupTable[pixels[i].green] += stylePixels[i].green;

        blueChannelCount[pixels[i].blue] += 1;
        blueChannelLookupTable[pixels[i].blue] += stylePixels[i].blue;
    }

    for(int i=0; i<256; i++){
        if(redChannelCount[i]==0){
            redChannelCount[i] = 1;
            redChannelLookupTable[i] = i;
        }
        if(greenChannelCount[i]==0){
            greenChannelCount[i] = 1;
            greenChannelLookupTable[i] = i;
        }
        if(blueChannelCount[i]==0){
            blueChannelCount[i] = 1;
            blueChannelLookupTable[i] = i;
        }

        redChannelLookupTable[i] = int(1.0*redChannelLookupTable[i]/redChannelCount[i]);
        greenChannelLookupTable[i] = int(1.0*greenChannelLookupTable[i]/greenChannelCount[i]);
        blueChannelLookupTable[i] = int(1.0*blueChannelLookupTable[i]/blueChannelCount[i]);
    }

    printf("red\n");
    for (int i = 0; i <256 ; ++i) {
        printf("%d,",redChannelLookupTable[i]);
    }
    printf("\ngreen\n");
    for (int i = 0; i <256 ; ++i) {
        printf("%d,",greenChannelLookupTable[i]);
    }
    printf("\nblue\n");
    for (int i = 0; i <256 ; ++i) {
        printf("%d,",blueChannelLookupTable[i]);
    }
}

int main(int argc, char **argv)
{
    InitializeMagick(*argv);
    Image image;
    Image meitu;

    try{
        image.quiet(false);
        image.read("/home/will/picture/before.JPG");

        PixelPacket *pixels = image.getPixels(0,0,image.baseColumns(),image.baseRows());

        LIHImageCore::LookUpTable lookUpTable;
        LIHImageCore::getFilterBasicSoftlight(&lookUpTable,1.0);

        for(int i=0;i<image.baseColumns()*image.baseRows();i++){
            pixels[i].red = lookUpTable.red[pixels[i].red];
            pixels[i].green = lookUpTable.green[pixels[i].green];
            pixels[i].blue = lookUpTable.blue[pixels[i].blue];
        }
        image.syncPixels();

        image.write("/home/will/picture/new_after.jpg");


    }
    catch(Exception &error_) {
        cout<<"Caught exception: "<<error_.what()<<endl;
        return -1;
    }

    return 0;
}


