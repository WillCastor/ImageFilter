
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

void LIHImageCore::getHardLightLookupTable(LookUpTable *table, int r, int g, int b, double opacity) {
    for (int i = 0; i < 256; i++) {
        if (r < 128) {
            table->red[i] = int(2.0 * i * r / 255 * opacity + (1 - opacity) * i);
        }
        else {
            table->red[i] = int((255 - 2.0 * (255 - i) * (1 - r / 255.0)) * opacity + (1 - opacity) * i);
        }
        if (g < 128) {
            table->green[i] = int(2.0 * i * g / 255 * opacity + (1 - opacity) * i);
        }
        else {
            table->green[i] = int((255 - 2.0 * (255 - i) * (1 - g / 255.0)) * opacity + (1 - opacity) * i);
        }
        if (b < 128) {
            table->blue[i] = int(2.0 * i * b / 255 * opacity + (1 - opacity) * i);
        }
        else {
            table->blue[i] = int((255 - 2.0 * (255 - i) * (1 - b / 255.0)) * opacity + (1 - opacity) * i);
        }

    }
}

void LIHImageCore::getSoftLightLookupTable(LookUpTable *table, int r, int g, int b, double opacity) {
    for (int i=0; i<256; i++){
        if(r<128){
            table->red[i] = int( (2.0*r*i/255+i*i/255.0*(1-2.0*r/255))*opacity + (1-opacity)*i );
        }
        else{
            table->red[i] = int( (2.0*i*(1-r/255.0)+sqrt(i/255.0)*(2.0*r-255))*opacity + (1-opacity)*i );
        }
        if(g<128){
            table->green[i] = int( (2.0*g*i/255+i*i/255.0*(1-2.0*g/255))*opacity + (1-opacity)*i );
        }
        else{
            table->green[i] = int( (2.0*i*(1-g/255.0)+sqrt(i/255.0)*(2.0*g-255))*opacity + (1-opacity)*i );
        }
        if(b<128){
            table->blue[i] =  int( (2.0*b*i/255+i*i/255.0*(1-2.0*b/255))*opacity + (1-opacity)*i );
        }
        else{
            table->blue[i] =  int( (2.0*i*(1-b/255.0)+sqrt(i/255.0)*(2.0*b-255))*opacity + (1-opacity)*i );
        }
    }
}

void LIHImageCore::getLinearLightLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for (int i=0; i<256; i++){
        table->red[i] =  int((min(255,max(0,i+2*r-255)))*opacity + (1-opacity)*i);
        table->green[i] = int((min(255,max(0,i+2*g-255)))*opacity + (1-opacity)*i);
        table->blue[i] = int((min(255,max(0,i+2*b-255)))*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getPinLightLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for (int i=0; i<256; i++){
        if (r<128){
            table->red[i] = int(min(i, 2*r)*opacity + (1-opacity)*i);
        }
        else{
            table->red[i] = int(max(i, 2*r-255)*opacity + (1-opacity)*i);
        }
        if (g<128){
            table->green[i] = int(min(i, 2*g)*opacity + (1-opacity)*i);
        }
        else{
            table->green[i] = int(max(i, 2*g-255)*opacity + (1-opacity)*i);
        }
        if (b<128){
            table->blue[i] = int(min(i, 2*b)*opacity + (1-opacity)*i);
        }
        else{
            table->blue[i] = int(max(i, 2*b-255)*opacity + (1-opacity)*i);
        }
    }
}

void LIHImageCore::getDifferenceLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for (int i=0; i<256; i++){
        table->red[i] = int(abs(i-r)*opacity + (1-opacity)*i);
        table->green[i] = int(abs(i-g)*opacity + (1-opacity)*i);
        table->blue[i] = int(abs(i-b)*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getExclusionLookupTable(LookUpTable *table, int r, int g, int b, double opacity){
    for (int i=0; i<256; i++){
        table->red[i] = int((255.0/2-(2.0*i-255)*(r/255.0-0.5))*opacity + (1-opacity)*i);
        table->green[i] = int((255.0/2-(2.0*i-255)*(g/255.0-0.5))*opacity + (1-opacity)*i);
        table->blue[i] = int((255.0/2-(2.0*i-255)*(b/255.0-0.5))*opacity + (1-opacity)*i);
    }
}


void LIHImageCore::getSubtractLookupTable(LookUpTable *table, int r, int g, int b, double opacity) {
    for (int i=0; i<256; i++){
        table->red[i] = int(max(0, i-r)*opacity + (1-opacity)*i);
        table->green[i] = int(max(0, i-g)*opacity + (1-opacity)*i);
        table->blue[i] = int(max(0, i-b)*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getFilterBasicSoftlight(LookUpTable *table, double opacity){
    int red[256] = {18,21,18,19,19,18,22,19,20,19,19,20,19,19,19,21,22,24,24,25,26,27,29,29,30,31,33,33,35,36,37,38,38,38,39,40,42,43,44,46,47,48,49,51,52,53,54,55,56,57,58,59,61,62,63,64,65,66,67,68,70,71,72,73,74,75,76,78,79,80,81,83,84,85,86,87,89,90,91,92,93,94,95,97,98,99,100,101,102,103,104,106,107,108,109,110,112,112,114,115,116,117,118,119,120,121,123,124,124,126,127,127,129,130,131,132,133,134,135,136,138,138,140,140,141,143,144,145,146,147,148,149,150,151,152,153,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,210,211,211,213,213,214,215,216,217,217,218,219,220,221,222,222,223,224,225,226,226,227,228,228,229,230,231,232,233,233,234,235,235,236,237,237,238,238,239,240,240,241,242,242,243,244,245,245,246,247,247,248,248,249,250,250,251,251,252,253,253,254,254};
    int green[256] = {18,18,14,17,16,17,18,16,16,16,16,17,18,18,19,20,20,22,23,24,25,26,27,28,29,30,31,33,34,35,36,37,38,39,41,42,43,44,45,47,48,49,50,52,53,54,55,57,58,59,60,62,63,64,65,67,68,69,71,72,73,74,76,76,78,79,79,80,82,82,84,85,86,87,89,89,90,91,92,94,94,95,97,98,99,100,101,103,104,105,106,107,108,109,110,111,112,113,115,115,117,117,119,120,120,123,123,124,125,127,127,129,129,131,132,133,134,136,136,137,139,139,141,142,143,144,145,146,147,148,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,166,166,167,168,169,171,171,172,173,174,175,177,177,179,180,181,181,182,183,185,186,187,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,204,205,206,207,207,208,209,209,210,211,212,213,214,215,215,217,217,218,219,220,221,222,223,223,224,225,226,227,227,228,229,230,230,231,232,233,234,234,235,236,237,237,238,239,239,240,241,241,242,242,243,244,244,245,245,246,247,247,248,248,249,250,250,251,251,252,252,253,253,254,254};
    int blue[256] = {10,7,8,8,8,8,9,9,10,10,11,12,13,14,15,16,17,18,20,21,22,23,24,26,27,28,30,31,32,33,35,35,37,38,39,41,41,43,44,45,47,48,49,50,52,53,54,55,56,57,59,60,61,62,63,65,66,66,68,69,70,71,73,74,74,76,77,78,79,81,81,83,83,85,86,87,88,89,90,91,92,94,95,96,97,98,99,100,102,103,103,104,105,107,108,109,109,111,112,113,114,116,117,118,119,120,121,122,123,124,126,126,127,129,130,131,132,133,134,135,136,138,139,140,141,142,143,144,145,146,147,148,149,151,152,152,153,155,156,157,158,159,160,161,162,163,164,165,166,167,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,185,186,186,187,188,189,190,190,192,192,193,194,194,195,196,197,198,198,199,200,202,202,204,204,205,206,207,208,209,210,211,212,213,214,215,216,217,217,218,219,220,221,222,222,223,224,225,226,226,227,228,229,229,230,231,232,232,233,234,234,235,236,237,237,238,238,239,240,241,241,242,243,243,244,245,245,246,246,247,248,248,249,250,250,251,251,252,252,253,254,254};

    for (int i=0; i<256; i++){
        table->red[i] = int(red[i]*opacity + (1-opacity)*i);
        table->green[i] = int(green[i]*opacity + (1-opacity)*i);
        table->blue[i] = int(blue[i]*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getFilterBasicWarmingUp(LookUpTable *table, double opacity) {
    int red[256] = {0,1,3,5,7,9,11,13,15,17,19,21,23,24,26,28,30,32,34,36,38,40,42,43,45,47,49,51,53,54,56,58,60,62,63,65,67,69,70,72,74,76,77,79,80,82,84,85,87,89,90,92,94,95,97,99,100,102,104,105,107,108,110,111,113,114,116,117,119,120,122,123,125,126,128,129,130,132,133,135,136,137,139,140,142,143,144,146,147,148,150,151,152,153,155,156,157,158,160,161,162,163,165,166,167,168,169,171,172,173,174,175,176,177,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,205,206,207,208,209,210,211,211,212,213,214,215,216,216,217,218,218,219,220,221,221,222,223,224,225,225,226,227,227,228,229,229,229,230,231,231,232,232,233,234,234,235,236,236,237,237,238,238,239,239,240,240,240,241,241,242,242,242,243,243,244,244,245,245,245,246,246,246,247,247,247,247,248,248,248,249,249,250,249,250,250,250,250,251,250,251,251,251,252,252,252,252,252,253,252,253,252,253,253,253,253,253,253,253,253,253,254,254,253,253,253,253,253,254,254};
    int green[256] = {0,3,4,5,7,8,10,11,13,14,16,17,18,20,21,23,24,26,27,29,30,32,33,35,36,38,39,41,42,43,45,46,47,49,50,51,52,54,55,57,58,60,61,62,63,65,66,68,69,70,72,73,74,76,77,78,79,81,82,83,85,86,87,88,90,91,92,93,95,96,97,98,100,101,102,103,104,106,107,108,109,110,112,113,114,115,116,118,118,120,121,122,123,124,126,127,128,129,130,131,132,133,134,135,137,138,139,140,141,142,143,144,145,146,147,149,149,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,172,173,174,175,176,177,178,179,180,181,182,182,183,184,184,185,186,188,189,189,190,191,192,193,194,194,195,196,197,197,198,199,200,201,202,202,203,204,205,206,207,207,208,208,209,210,211,211,212,213,214,215,215,216,217,218,218,219,220,221,222,222,223,224,224,225,226,226,227,228,228,229,230,230,231,231,232,233,233,234,234,235,236,236,237,238,238,239,239,240,240,241,242,243,243,244,244,245,245,245,246,247,247,248,248,249,249,250,250,251,251,252,252,253,253,254,254};
    int blue[256] = {0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,220,220,221,222,223,224,225,226,227,228,229,231,231,232,234,235,235,236,237,238,239,240,241,242,243,244,246,247,247,248,249,250,251,252,253,254};

    for (int i=0; i<256; i++){
        table->red[i] = int(red[i]*opacity + (1-opacity)*i);
        table->green[i] = int(green[i]*opacity + (1-opacity)*i);
        table->blue[i] = int(blue[i]*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getFilterLOMOFilm(LookUpTable *table, double opacity) {
    int red[256] = {26,25,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,27,28,29,30,32,33,34,35,36,37,38,39,41,42,43,44,46,47,48,50,51,52,53,54,56,57,58,59,61,63,64,66,67,68,70,71,72,74,75,76,78,80,82,83,84,86,87,89,90,91,93,94,96,97,99,100,102,103,104,106,107,109,111,113,114,116,117,119,120,122,123,125,126,128,129,131,132,134,135,137,138,139,141,142,144,145,147,149,150,152,153,155,156,157,158,160,161,162,164,165,167,168,170,171,173,174,175,177,178,180,181,182,184,185,186,187,188,190,191,192,193,195,196,198,199,200,202,202,203,204,205,207,208,209,210,212,213,214,215,216,216,218,219,220,221,222,223,224,225,226,227,227,228,229,230,231,232,233,234,234,235,236,237,237,238,239,239,240,241,242,242,243,244,244,245,245,245,246,246,247,247,248,249,249,250,250,250,251,251,251,252,252,252,253,253,253,253,253,253,253,254,254,253,254,254};
    int green[256] = {49,49,48,48,49,49,49,48,48,48,49,48,48,48,48,49,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,49,48,48,48,48,48,48,48,49,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,49,48,49,49,50,51,52,53,55,56,58,59,60,61,63,64,66,67,68,70,71,72,74,75,77,78,80,82,83,84,85,87,88,90,91,92,94,95,97,98,100,101,103,104,106,108,109,111,112,114,115,117,118,120,121,123,124,126,127,129,130,132,133,135,137,138,139,141,142,144,145,147,148,150,151,153,154,156,157,159,160,161,162,164,165,166,168,169,171,172,174,175,176,178,180,181,182,183,185,186,187,188,190,190,192,193,194,196,198,199,200,201,203,204,204,206,207,208,208,209,211,212,213,214,215,216,217,219,220,221,222,222,223,224,225,227,227,229,230,230,232,233,233,234,234,235,236,237,238,238,239,240,241,241,242,242,243,244,244,244,245,246,246,247,247,248,248,249,249,250,250,250,251,251,251,252,252,252,252,252,253,253,253,253,254,253,254,253,254,254,254};
    int blue[256] = {67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,68,68,67,67,67,67,68,68,67,68,67,67,68,68,67,68,67,67,67,68,67,68,67,67,68,68,67,68,67,67,67,68,68,68,68,67,68,69,71,72,73,74,76,78,79,80,82,83,85,86,88,89,91,92,93,94,95,97,98,100,101,103,104,106,107,109,110,112,113,115,116,118,119,121,122,124,125,126,128,129,131,132,134,135,137,138,140,141,143,144,146,147,150,151,152,154,155,157,158,160,161,163,164,165,167,168,170,171,172,174,176,177,178,179,180,181,183,186,187,188,190,191,192,194,195,196,198,199,200,201,202,204,205,207,208,209,210,211,212,214,215,216,217,218,219,220,221,222,223,225,226,227,228,229,230,230,231,232,233,234,235,236,236,237,238,239,239,241,241,242,243,243,244,245,245,246,246,247,247,248,248,249,249,250,250,250,250,251,251,251,251,252,252,252,252,252,252,252,252,253,254};

    for (int i=0; i<256; i++){
        table->red[i] = int(red[i]*opacity + (1-opacity)*i);
        table->green[i] = int(green[i]*opacity + (1-opacity)*i);
        table->blue[i] = int(blue[i]*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getFilterLOMOImpression(LookUpTable *table, double opacity) {
    int red[256] = {29,29,29,29,29,29,29,30,31,32,33,33,34,35,35,36,36,39,39,39,41,41,43,43,44,45,45,46,48,49,49,52,51,52,53,53,53,55,57,57,58,59,59,59,60,60,61,64,65,67,67,66,68,69,70,70,71,72,74,75,76,77,79,81,81,83,83,84,86,86,87,87,88,89,90,91,91,92,93,96,96,100,100,100,102,102,103,104,105,105,107,108,109,111,113,116,115,118,120,120,121,123,124,126,127,129,130,131,132,134,136,139,140,141,142,142,143,144,145,145,147,148,150,151,153,154,155,158,158,159,161,161,162,163,164,165,166,166,167,168,169,170,171,173,173,175,175,175,175,175,176,177,178,178,179,180,180,181,182,183,182,183,183,183,183,184,185,185,186,186,187,187,187,187,188,188,189,189,189,189,190,190,191,191,192,192,192,193,193,194,194,195,194,195,195,195,195,195,195,195,196,196,197,197,197,198,198,199,200,200,200,200,200,201,201,202,202,202,203,203,204,205,205,206,206,206,207,207,208,208,208,209,209,209,210,211,211,211,211,212,212,214,214,215,215,216,216,216,217,217,217,218,219,219,219,219};
    int green[256] = {51,51,52,52,52,53,54,54,55,55,55,56,57,58,59,61,68,66,69,71,70,70,71,72,73,74,75,76,77,78,80,77,81,80,81,80,80,80,80,81,82,83,84,86,86,87,90,90,92,91,92,93,94,95,96,97,98,99,100,101,102,103,105,105,107,107,107,108,109,110,111,112,113,114,115,116,118,120,122,122,124,124,124,125,126,128,130,131,132,132,133,135,136,138,140,141,143,143,144,145,146,147,149,150,152,153,153,155,156,157,159,160,162,162,162,164,164,165,166,167,168,169,171,172,172,174,176,175,177,177,177,178,179,180,180,181,182,183,184,186,186,187,188,188,190,190,190,191,192,193,194,194,195,195,196,196,197,197,198,198,198,198,198,199,199,199,200,200,201,201,201,202,202,202,203,203,203,203,203,204,204,204,204,205,205,206,206,207,207,207,207,208,208,208,208,208,209,209,210,210,211,211,211,212,213,213,214,214,214,214,214,215,215,215,216,216,216,216,216,217,217,218,218,219,219,219,220,220,220,220,221,221,222,222,222,223,223,223,223,223,225,225,225,226,226,226,227,226,227,227,227,228,229,229,230,230};
    int blue[256] = {80,81,81,81,82,81,81,81,81,82,82,83,83,84,84,85,85,85,85,86,86,86,87,88,90,91,92,92,92,92,92,93,93,93,94,94,95,95,96,96,96,97,97,97,97,97,98,98,97,98,98,98,99,99,100,101,101,101,101,102,102,103,105,106,106,107,107,106,107,108,109,110,110,110,111,111,112,113,114,115,116,116,117,117,117,117,118,118,119,120,121,121,122,123,124,125,126,127,128,127,129,129,130,131,132,133,134,134,135,136,138,139,139,140,142,142,142,143,144,145,146,146,147,148,149,150,151,153,154,154,155,155,156,157,158,159,160,161,161,162,163,163,164,166,167,168,169,170,170,172,172,173,174,174,175,176,176,178,178,180,182,182,184,183,184,186,187,188,188,189,189,190,191,193,193,195,194,195,195,195,195,196,196,197,197,198,198,199,199,199,200,201,202,202,202,202,202,202,203,203,204,204,205,205,206,206,206,207,207,208,209,209,209,209,210,211,211,211,212,212,213,214,214,214,215,216,215,216,216,217,217,218,218,218,219,219,220,220,220,220,220,220,221,221,222,223,223,223,224,224,224,226,226,227,226,225};

    for (int i=0; i<256; i++){
        table->red[i] = int(red[i]*opacity + (1-opacity)*i);
        table->green[i] = int(green[i]*opacity + (1-opacity)*i);
        table->blue[i] = int(blue[i]*opacity + (1-opacity)*i);
    }
}

void LIHImageCore::getFilterLOMOYouth(LookUpTable *table, double opacity) {
    int red[256] = {23,18,20,19,22,21,21,22,23,23,24,24,25,25,26,27,27,28,28,29,30,31,32,32,33,34,35,36,37,38,39,41,42,43,45,45,46,47,49,50,51,52,54,56,57,58,59,61,62,63,65,65,66,67,69,70,72,75,76,78,79,81,83,83,85,86,88,90,91,92,95,97,98,101,103,106,108,110,113,115,116,117,119,122,124,127,129,131,132,133,136,138,139,141,144,145,146,147,148,150,151,153,156,158,161,161,163,165,167,168,171,172,173,176,175,177,178,178,179,181,182,183,183,184,186,186,186,189,189,191,192,193,193,193,195,196,196,196,197,198,199,199,199,200,200,201,202,203,202,204,204,205,206,207,208,209,209,210,210,212,214,214,214,216,217,218,217,218,219,219,221,221,222,222,223,224,225,226,226,227,228,228,228,228,229,229,229,230,230,230,230,231,232,232,232,233,233,234,235,236,235,236,236,237,237,237,238,238,238,238,238,239,239,239,239,240,240,241,241,241,242,242,242,242,242,243,243,244,243,243,243,244,245,245,245,246,246,246,246,246,247,247,247,248,248,248,248,248,248,248,248,248,248,249,249,249};
    int green[256] = {29,31,30,31,30,31,32,32,32,33,33,34,34,35,35,36,37,38,39,40,40,41,43,43,45,45,47,48,49,50,51,53,54,55,56,57,58,60,61,62,63,64,66,67,68,69,70,72,72,74,74,76,77,78,80,81,82,84,85,87,88,90,93,95,94,96,98,101,102,104,106,107,108,109,112,113,115,118,119,121,122,124,127,128,129,131,132,134,136,137,139,140,143,143,146,147,148,150,151,152,155,155,158,158,159,160,162,162,163,165,165,166,167,168,169,171,170,172,172,173,174,174,177,178,179,180,180,181,182,181,183,183,185,184,186,186,188,187,188,189,191,192,194,194,194,196,197,198,198,200,201,201,203,203,205,205,206,206,207,207,208,208,209,210,211,211,211,211,212,213,213,214,215,215,215,216,216,216,217,217,217,218,218,218,219,219,219,220,220,220,221,220,222,222,223,222,223,223,224,225,225,225,225,226,226,226,226,227,227,227,228,228,229,229,229,229,230,230,230,230,230,231,231,232,232,232,233,233,233,233,233,234,234,234,234,234,234,235,235,236,236,236,236,236,236,236,236,237,237,237,237,237,238,238,238,238};
    int blue[256] = {49,52,54,53,54,55,55,55,55,56,56,56,56,56,55,55,55,55,55,54,55,56,57,59,60,61,61,61,61,62,62,63,63,64,64,65,67,69,70,72,73,74,74,75,76,76,77,79,79,80,80,81,81,84,84,85,86,85,87,88,87,88,89,89,92,92,93,93,93,95,96,96,97,98,98,99,100,101,101,102,102,104,105,106,108,109,110,111,112,113,114,116,115,118,121,119,120,122,122,122,124,125,124,125,127,126,127,128,128,129,131,132,132,132,133,134,135,135,137,139,140,141,143,144,144,146,147,146,149,151,152,152,154,156,157,159,160,161,162,163,164,164,165,166,166,167,167,168,168,169,169,170,170,171,172,172,174,175,176,177,178,178,179,178,179,180,181,181,182,183,183,183,184,184,184,185,186,188,189,190,191,192,192,192,194,194,195,196,196,197,198,199,200,200,201,200,201,202,202,203,203,203,204,204,205,206,206,206,206,206,207,206,208,208,208,208,209,209,210,210,211,211,212,212,212,213,213,214,214,214,214,213,213,214,214,214,214,213,214,214,213,214,213,213,214,215,215,215,215,215,216,215,216,214,215,215};

    for (int i=0; i<256; i++){
        table->red[i] = int(red[i]*opacity + (1-opacity)*i);
        table->green[i] = int(green[i]*opacity + (1-opacity)*i);
        table->blue[i] = int(blue[i]*opacity + (1-opacity)*i);
    }
}