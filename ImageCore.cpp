
#include "ImageCore.h"

template <typename T>
static T min(T a, T b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

template <typename T>
static T max(T a, T b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}


void LIHImageCore::getNormalLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for(int i=0; i<256; i++){
        table->red[i] = int(r*opacity + (1-opacity)*i);
        table->green[i] = int(g*opacity + (1-opacity)*i);
        table->blue[i] = int(b*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getDarkenLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for(int i=0; i<256; i++){
        table->red[i] = int(min(i,r)*opacity + (1-opacity)*i);
        table->green[i] = int(min(i,g)*opacity + (1-opacity)*i);
        table->blue[i] = int(min(i,b)*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getMultiplyLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for(int i=0; i<256; i++){
        table->red[i] = int(r*i/255.0*opacity + (1-opacity)*i);
        table->green[i] = int(g*i/255.0*opacity + (1-opacity)*i);
        table->blue[i] = int(b*i/255.0*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getColorBurnLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for(int i=0; i<256; i++){
        if (r!=0){
            table->red[i] = int(max(0.0, 255-1.0*(255-i)/r*255)*opacity + (1-opacity)*i);
        }
        else{
            table->red[i] = int((1-opacity)*i);
        }
        if (g!=0){
            table->green[i] = int(max(0.0, 255-1.0*(255-i)/g*255)*opacity + (1-opacity)*i);
        }
        else{
            table->green[i] = int((1-opacity)*i);
        }
        if (b!=0){
            table->blue[i] = int(max(0.0, 255-1.0*(255-i)/b*255)*opacity + (1-opacity)*i);
        }
        else{
            table->blue[i] = int((1-opacity)*i);
        }
    }
}

void LIHImageCore::getLinearBurnLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for(int i=0; i<256; i++){
        table->red[i] = int(max(0, i+r-255)*opacity + (1-opacity)*i);
        table->green[i] = int(max(0, i+g-255)*opacity + (1-opacity)*i);
        table->blue[i] = int(max(0, i+b-255)*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getLightenLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for(int i=0; i<256; i++){
        table->red[i] = int(max(i,r)*opacity + (1-opacity)*i);
        table->green[i] = int(max(i,g)*opacity + (1-opacity)*i);
        table->blue[i] = int(max(i,b)*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getScreenLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for(int i=0; i<256; i++){
        table->red[i] = int((255-(255-i)*(1-r/255.0))*opacity + (1-opacity)*i);
        table->green[i] = int((255-(255-i)*(1-g/255.0))*opacity + (1-opacity)*i);
        table->blue[i] = int((255-(255-i)*(1-b/255.0))*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getColorDogeLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for (int i=0; i<256; i++){
        if(r==255){
            table->red[i] = int(255*opacity + (1-opacity)*i);
        }
        else{
            table->red[i] = int(min(255.0, 1.0*i/(255-r)*255)*opacity + (1-opacity)*i);
        }
        if(g==255){
            table->green[i] = int(255*opacity + (1-opacity)*i);
        }
        else{
            table->green[i] = int(min(255.0, 1.0*i/(255-g)*255)*opacity + (1-opacity)*i);
        }
        if(b==255){
            table->blue[i] = int(255*opacity + (1-opacity)*i);
        }
        else{
            table->blue[i] = int(min(255.0, 1.0*i/(255-b)*255)*opacity + (1-opacity)*i);
        }
    }
}

void LIHImageCore::getLinearDogeLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for (int i=0; i<256; i++){
        table->red[i] = int(min(255, i+r)*opacity + (1-opacity)*i);
        table->green[i] = int(min(255, i+g)*opacity + (1-opacity)*i);
        table->blue[i] = int(min(255, i+b)*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getOverlayLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for (int i=0; i<256; i++){
        if (i<128){
            table->red[i] = int(2.0*i*r/255*opacity + (1-opacity)*i);
            table->green[i] = int(2.0*i*g/255*opacity + (1-opacity)*i);
            table->blue[i] = int(2.0*i*b/255*opacity + (1-opacity)*i);
        }
        else{
            table->red[i] = int((255-2.0*(255-i)*(1-r/255.0))*opacity + (1-opacity)*i);
            table->green[i] = int((255-2.0*(255-i)*(1-g/255.0))*opacity + (1-opacity)*i);
            table->blue[i] = int((255-2.0*(255-i)*(1-b/255.0))*opacity + (1-opacity)*i);
        }
    }
}

void LIHImageCore::getHardLightLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for (int i=0; i<256; i++){
        if (r<128){
            table->red[i] = int(2.0*i*r/255*opacity + (1-opacity)*i);
        }
        else{
            table->red[i] = int((255-2.0*(255-i)*(1-r/255.0))*opacity + (1-opacity)*i);
        }
        if (g<128){
            table->green[i] = int(2.0*i*g/255*opacity + (1-opacity)*i);
        }
        else{
            table->green[i] = int((255-2.0*(255-i)*(1-g/255.0))*opacity + (1-opacity)*i);
        }
        if (b<128){
            table->blue[i] = int(2.0*i*b/255*opacity + (1-opacity)*i);
        }
        else{
            table->blue[i] = int((255-2.0*(255-i)*(1-b/255.0))*opacity + (1-opacity)*i);
        }

    }

/*
 * soft light blend mode
 * */
void getSoftLightLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

/*
 * linear light blend mode
 * */
void getLinearLightLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

/*
 * pin light blend mode
 * */
void getPinLightLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

/*
 * difference blend mode
 * */
void getDifferenceLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

/*
 * exclusion blend mode
 * */
void getExclusionLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

/*
 * subtract blend mode
 * */
void getSubtractLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

/*
 * divide blend mode
 * */
void getDivideLookupTable(LookUpTable *table, int r, int g, int b, double opacity);
