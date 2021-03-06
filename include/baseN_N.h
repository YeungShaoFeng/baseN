#ifndef _baseN_N_h
#define _baseN_N_h

#include "BYTE.h"
#include "SD.h"

// 80
unsigned char const baseN_1[] = {
    // En
    8u,/* total steps, output size */
    0u,/* +1=input size */
    //will_or output[n] input[n]
        0u,      0u,       0u,    RIGHT, Ox7_, Ox1_,
        0u,      1u,       0u,    RIGHT, Ox6_, Ox1_,
        0u,      2u,       0u,    RIGHT, Ox5_, Ox1_,
        0u,      3u,       0u,    RIGHT, Ox4_, Ox1_,
        0u,      4u,       0u,    RIGHT, Ox3_, Ox1_,
        0u,      5u,       0u,    RIGHT, Ox2_, Ox1_,
        0u,      6u,       0u,    RIGHT, Ox1_, Ox1_,
        0u,      7u,       0u,    RIGHT, Ox0_, Ox1_,

    //De
    1u,/* total steps */// 50
    8u,/* input size */
    //time_repeated output[n] input[n]  SD    SB    AB
        8u,            0u,      Ox0_,  LEFT, Ox7_, Ox80_,
                       0u,      Ox1_,  LEFT, Ox6_, Ox40_,
                       0u,      Ox2_,  LEFT, Ox5_, Ox20_,
                       0u,      Ox3_,  LEFT, Ox4_, Ox10_,
                       0u,      Ox4_,  LEFT, Ox3_, Ox08_,
                       0u,      Ox5_,  LEFT, Ox2_, Ox04_,
                       0u,      Ox6_,  LEFT, Ox1_, Ox02_,
                       0u,      Ox7_,  LEFT, Ox0_, Ox01_,
                  /*👆 +1=output size */
};
unsigned char const baseN_2[] = {
    //En
    4u,/* total steps, output size */
    0u,/* +1=input size */

    0u, 0u, 0u, RIGHT, Ox6_, Ox3_,
    0u, 1u, 0u, RIGHT, Ox4_, Ox3_,
    0u, 2u, 0u, RIGHT, Ox2_, Ox3_,
    0u, 3u, 0u, RIGHT, Ox0_, Ox3_,

    //De
    1u,/* total steps */
    4u,/* input size */
    //time_repeated
        4u,         0u, Ox0_, LEFT, Ox6_, OxC0_,
                    0u, Ox1_, LEFT, Ox4_, Ox30_,
                    0u, Ox2_, LEFT, Ox2_, Ox0C_,
                    0u, Ox3_, LEFT, Ox0_, Ox03_,
                  /*👆 +1=output size */
};

unsigned char const baseN_3[] = {
    //En
    8u,/* total steps, output size */
    2u,/* +1=input size */

    0u, 0u, 0u, RIGHT, Ox5_, Ox7_,
    0u, 1u, 0u, RIGHT, Ox2_, Ox7_,
    0u, 2u, 0u, LEFT,  Ox1_, Ox6_, 255u, 2u, 1u, RIGHT, Ox7_, Ox1_,
    0u, 3u, 1u, RIGHT, Ox4_, Ox7_,
    0u, 4u, 1u, RIGHT, Ox1_, Ox7_,
    0u, 5u, 1u, LEFT,  Ox2_, Ox4_, 255u, 5u, 2u, RIGHT, Ox6_, Ox3_,
    0u, 6u, 2u, RIGHT, Ox3_, Ox7_,
    0u, 7u, 2u, RIGHT, Ox0_, Ox7_,

    //De
    3u,/* total steps*/ // 60
    8u,/* input size */
    //time_repeated
        3u,          0u, Ox0_, LEFT,  Ox5_, OxE0_,
                     0u, Ox1_, LEFT,  Ox2_, Ox1C_,
                     0u, Ox2_, RIGHT, Ox1_, Ox03_,

        4u,          1u, Ox2_, LEFT,  Ox7_, Ox80_,
                     1u, Ox3_, LEFT,  Ox4_, Ox70_,
                     1u, Ox4_, LEFT,  Ox1_, Ox0E_,
                     1u, Ox5_, RIGHT, Ox2_, Ox01_,

        3u,          2u, Ox5_, LEFT,  Ox6_, OxC0_,
                     2u, Ox6_, LEFT,  Ox3_, Ox38_,
                     2u, Ox7_, RIGHT, Ox0_, Ox07_,
                   /*👆 +1=output size */
        0u/* prevent currentPos+5 will be illegal */
};

unsigned char const baseN_4[] = {
    //En
    2u,/* total steps, output size */
    0u,/* +1=input size */

    0u, 0u, 0u, RIGHT, Ox4_, OxF_,
    0u, 1u, 0u, RIGHT, Ox0_, OxF_,

    //De
    1u,/*total steps */
    2u,/* input size */
    //time_repeated
        2u,           0u, Ox0_, LEFT, Ox4_, OxF0_,
                      0u, Ox1_, LEFT, Ox0_, Ox0F_,
                    /*👆 +1=output size */
};

unsigned char const baseN_5[] {
    //En
    8u,/* total steps, output size */
    4u,/* +1=input size */

    0u, 0u, 0u, RIGHT, Ox3_, Ox1F_,
    0u, 1u, 0u, LEFT,  Ox2_, Ox1C_, 255u, 1u, 1u, RIGHT, Ox6_, Ox03_,
    0u, 2u, 1u, RIGHT, Ox1_, Ox1F_,
    0u, 3u, 1u, LEFT,  Ox4_, Ox10_, 255u, 3u, 2u, RIGHT, Ox4_, Ox0F_,
    0u, 4u, 2u, LEFT,  Ox1_, Ox1E_, 255u, 4u, 3u, RIGHT, Ox7_, Ox01_,
    0u, 5u, 3u, RIGHT, Ox2_, Ox1F_,
    0u, 6u, 3u, LEFT,  Ox3_, Ox18_, 255u, 6u, 4u, RIGHT, Ox5_, Ox0F_,
    0u, 7u, 4u, RIGHT, Ox0_, Ox1F_,

    //De
    5u,/* total steps */
    8u,/* input size */
    //time_repeated
        2u,          0u, Ox0_, LEFT,  Ox3_, OxF8_,
                     0u, Ox1_, RIGHT, Ox2_, Ox07_,

        3u,          1u, Ox1_, LEFT,  Ox6_, OxC0_,
                     1u, Ox2_, LEFT,  Ox1_, Ox3E_,
                     1u, Ox3_, RIGHT, Ox4_, Ox01_,

        2u,          2u, Ox3_, LEFT,  Ox4_, OxF0_,
                     2u, Ox4_, RIGHT, Ox1_, Ox0F_,

        3u,          3u, Ox4_, LEFT,  Ox7_, Ox80_,
                     3u, Ox5_, LEFT,  Ox2_, Ox7C_,
                     3u, Ox6_, RIGHT, Ox3_, Ox03_,

        2u,          4u, Ox6_, LEFT,  Ox5_, OxE0_,
                     4u, Ox7_, RIGHT, Ox0_, Ox1F_,
                   /*👆 +1=output size */
};

unsigned char const baseN_6[] {
    //En
    4u,/* total steps, output size */
    2u,/* +1=input size */

    0u, 0u, 0u, RIGHT, Ox2_, Ox3F_,
    0u, 1u, 0u, LEFT,  Ox4_, Ox30_, 255u, 1u, 1u, RIGHT, Ox4_, OxF_,
    0u, 2u, 1u, LEFT,  Ox2_, Ox3C_, 255u, 2u, 2u, RIGHT, Ox6_, Ox3_,
    0u, 3u, 2u, RIGHT, Ox0_, Ox3F_,

    //De
    6u,/* total steps */
    4u,/* input size */
    //time_repeated
        2u,          0u, Ox0_, LEFT,  Ox2_, OxFC_,
                     0u, Ox1_, RIGHT, Ox4_, Ox03_,

        2u,          1u, Ox1_, LEFT,  Ox4_, OxF0_,
                     1u, Ox2_, RIGHT, Ox2_, Ox0F_,

        2u,          2u, Ox2_, LEFT,  Ox6_, OxC0_,
                     2u, Ox3_, RIGHT, Ox0_, Ox3F_,
                   /*👆 +1=output size */
};
unsigned char const baseN_7[] {
    //En
    8u,/* total steps, output size */
    6u,/* +1=input size */

    0u, 0u, 0u, RIGHT, Ox1_, Ox7F_,
    0u, 1u, 0u, LEFT,  Ox6_, Ox40_, 255u, 1u, 1u, RIGHT, Ox2_, Ox3F_,
    0u, 2u, 1u, LEFT,  Ox5_, Ox60_, 255u, 2u, 2u, RIGHT, Ox3_, Ox1F_,
    0u, 3u, 2u, LEFT,  Ox4_, Ox70_, 255u, 3u, 3u, RIGHT, Ox4_, Ox0F_,
    0u, 4u, 3u, LEFT,  Ox3_, Ox78_, 255u, 4u, 4u, RIGHT, Ox5_, Ox07_,
    0u, 5u, 4u, LEFT,  Ox2_, Ox7C_, 255u, 5u, 5u, RIGHT, Ox6_, Ox03_,
    0u, 6u, 5u, LEFT,  Ox1_, Ox7E_, 255u, 6u, 6u, RIGHT, Ox7_, Ox01_,
    0u, 7u, 6u, LEFT,  Ox0_, Ox7F_,

    //De
    7u,/* total steps, output size */
    8u,/* input size */
    //time_repeated
        2u,          0u, Ox0_, LEFT,  Ox1_, OxFE_,
                     0u, Ox1_, RIGHT, Ox6_, Ox01_,

        2u,          1u, Ox1_, LEFT,  Ox2_, OxFC_,
                     1u, Ox2_, RIGHT, Ox5_, Ox03_,

        2u,          2u, Ox2_, LEFT,  Ox3_, OxF8_,
                     2u, Ox3_, RIGHT, Ox4_, Ox07_,

        2u,          3u, Ox3_, LEFT,  Ox4_, OxF0_,
                     3u, Ox4_, RIGHT, Ox3_, Ox0F_,

        2u,          4u, Ox4_, LEFT,  Ox5_, OxE0_,
                     4u, Ox5_, RIGHT, Ox2_, Ox1F_,

        2u,          5u, Ox5_, LEFT,  Ox6_, OxC0_,
                     5u, Ox6_, RIGHT, Ox1_, Ox3F_,

        2u,          6u, Ox6_, LEFT,  Ox7_, Ox80_,
                     6u, Ox7_, RIGHT, Ox0_, Ox7F_,
                   /*👆 +1=output size */
};

unsigned char const *base_choices[8] = {
        nullptr, baseN_1, baseN_2, baseN_3, baseN_4, baseN_5, baseN_6, baseN_7
};

#endif // !_baseN_N_h
