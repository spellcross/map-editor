#ifndef MAPS_H
#define MAPS_H

#include <stdint.h>

// vypis delky mapy pres bash
// od -t x1 -j 9 -N 1 -A n M01_01.DTA

struct Map
{
    QString name_;
    uint8_t width_;
    uint8_t height_;
    int map_begin_x_offset_;
    int map_begin_y_offset_;

    Map()
        : name_(QString())
        , width_(0)
        , height_(0)
        , map_begin_x_offset_(0)
        , map_begin_y_offset_(0)
    {

    }

    Map(const QString name, uint8_t width, uint8_t height, int map_begin_x_offset, int map_begin_y_offset)
        : name_(name)
        , width_(width)
        , height_(height)
        , map_begin_x_offset_(map_begin_x_offset)
        , map_begin_y_offset_(map_begin_y_offset)
    {

    }
};

static Map m01_01 { "M01_01", 100, 84, 55, 120 };
static Map m03_06 { "M03_06", 60, 70, 55, 84 };

#endif // MAPS_H


// sirka vyska mapy v dlazdicich
//
//M01_01.DTA 100 84
//M02_01.DTA 40 60
//M02_02.DTA 45 65
//M02_03.DTA 60 90
//M02_04.DTA 35 85
//M02_05.DTA 55 95
//M02_06.DTA 40 60
//M03_01.DTA 40 70
//M03_02.DTA 60 80
//M03_03.DTA 70 95
//M03_04.DTA 50 70
//M03_05.DTA 60 80
//M03_06.DTA 60 70
//M03_07.DTA 40 96
//M03_08.DTA 40 86
//M03_09.DTA 50 96
//M03_10.DTA 30 130
//M03_11.DTA 50 60
//M03_12.DTA 50 96
//M03_13.DTA 70 130
//M04_01.DTA 46 60
//M04_02.DTA 60 60
//M04_03.DTA 70 70
//M04_04.DTA 36 90
//M04_05.DTA 46 100
//M04_06.DTA 56 100
//M04_07.DTA 30 68
//M04_08.DTA 50 70
//M04_09.DTA 50 90
//M04_10.DTA 100 126
//M04_11.DTA 40 60
//M04_12.DTA 60 60
//M04_13.DTA 46 70
//M04_14.DTA 70 88
//M04_15.DTA 36 70
//M04_16.DTA 36 80
//M05_01.DTA 60 70
//M05_02.DTA 46 70
//M05_03.DTA 68 70
//M05_04.DTA 46 126
//M05_05.DTA 50 66
//M05_06.DTA 66 120
//M05_07.DTA 46 100
//M05_08.DTA 68 100
//M05_09.DTA 46 126
//M06_01.DTA 50 74
//M06_02.DTA 40 94
//M06_03.DTA 50 94
//M06_04.DTA 56 104
//M06_05.DTA 30 74
//M06_06.DTA 60 90
//M06_07.DTA 60 100
//M06_08.DTA 30 100
//M06_09.DTA 50 74
//M06_10.DTA 40 80
//M06_11.DTA 50 84
//M06_12.DTA 40 126
//M06_13.DTA 70 124
//M06_14.DTA 30 64
//M07_01.DTA 40 74
//M07_02.DTA 30 84
//M07_03.DTA 50 94
//M07_04.DTA 40 104
//M07_05.DTA 50 94
//M07_06.DTA 40 80
//M07_07.DTA 40 104
//M07_08.DTA 40 114
//M07_09.DTA 50 94
//M07_10.DTA 35 70
//M07_11.DTA 40 120
//M07_12.DTA 50 84
//M07_13.DTA 60 94
//M07_14.DTA 100 60
//M08_01.DTA 50 84
//M08_04.DTA 30 74
//M08_05.DTA 40 84
//M08_06.DTA 50 94
//M08_07.DTA 34 64
//M08_09.DTA 70 114
//M08_12.DTA 40 120
//M08_13.DTA 30 74
//M08_14.DTA 40 64
//M08_15.DTA 34 84
//M08_16.DTA 54 84
//M08_17.DTA 34 94
//M08_18.DTA 44 74
//M08_19.DTA 44 74
//M08_20.DTA 64 114
//M09_01.DTA 44 84
//M09_02.DTA 44 84
//M09_03.DTA 44 84
//M09_04.DTA 46 70
//M09_05.DTA 44 84
//M09_06.DTA 30 54
//M09_07.DTA 44 84
//M09_08.DTA 40 74
//M09_09.DTA 44 84
//M09_10.DTA 64 84
//M09_11.DTA 44 74
//M09_12.DTA 44 74
//M09_13.DTA 44 120
//M10_01.DTA 44 66
//M10_02.DTA 54 116
//M10_03.DTA 54 114
//M10_03X.DTA 54 114



// python scrip co to vytahne
//import os
//import sys



//for file_name in os.listdir("."):
//    if file_name.endswith(".DTA") and file_name.startswith("M"):

//        file = open(file_name, "rb")
//        byte = file.read(1)
//        position = 1
//        width = 0
//        height = 0
//        while byte:

//            byte = file.read(1)

//            if position == 9:
//                width = int.from_bytes(byte, byteorder=sys.byteorder)

//            if position == 11:
//                height = int.from_bytes(byte, byteorder=sys.byteorder)
//                break

//            position = position + 1

//        print(file_name, width, height)


