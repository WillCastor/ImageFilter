//
// Created by lishiyu on 16-7-12.
//

#ifndef IMAGEFILTER_IMAGECORE_H
#define IMAGEFILTER_IMAGECORE_H

#include <Magick++.h>

namespace LIHImageCore {
    struct LookUpTable{
        int red[256] = {0};
        int green[256] = {0};
        int blue[256] = {0};
    };

    /*
     * normal blend mode
     * */
    void getNormalLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

    /*
     * darken blend mode
     * */
    void getDarkenLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

    /*
     * multiply blend mode
     * */
    void getMultiplyLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

    /*
     * color burn blend mode
     * */
    void getColorBurnLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

    /*
     * linear burn blend mode
     * */
    void getLinearBurnLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

    /*
     * lighten blend mode
     * */
    void getLightenLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

    /*
     * screen blend mode
     * */
    void getScreenLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

    /*
     * color doge blend mode
     * */
    void getColorDogeLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

    /*
     * linear doge blend mode
     * */
    void getLinearDogeLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

    /*
     * overlay blend mode
     * */
    void getOverlayLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

    /*
     * hard light blend mode
     * */
    void getHardLightLookupTable(LookUpTable *table, int r, int g, int b, double opacity);

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
};

#endif //IMAGEFILTER_IMAGECORE_H
