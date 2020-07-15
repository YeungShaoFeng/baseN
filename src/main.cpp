#include <iostream>
#include "../include/BYTE.h"
#include "../include/SD.h"
#include "../include/baseN_N.h"

using namespace std;

#define encrypt_input_size          7 + 1
#define encrypt_output_size         8 + 1
#define decrypt_input_size          8 + 1
#define decrypt_output_size         7 + 1
unsigned char enresin[encrypt_input_size] = {0};
unsigned char deresin[decrypt_input_size] = {0};
unsigned char enresout[encrypt_output_size] = {0};
unsigned char deresout[decrypt_output_size] = {0};

unsigned char Or(unsigned char a, unsigned char b, bool willDoOr);

unsigned char Or(unsigned char a, unsigned char b);

unsigned char And(unsigned char a, BYTE _byte);

unsigned char shift(unsigned char a, SD sd, BYTE _byte);

unsigned char *Encrypt(unsigned char *input, int base_choice);

unsigned char En_step(unsigned char a, SD sd, BYTE SB, BYTE AB);

int main() {
    unsigned char tmp[] = {0x88};
    Encrypt(tmp, 0);
    for (unsigned char i : enresout) {
        printf("%#X\n", i);
    }
    return 0;
}

/*
 * AB: and byte
 * SB: shift byte
 * SD: shift direction
 * T/F: true/false
 * l/r: left/right
 *
 * En:
 *      tmp = or(
 *                  and(
 *                      shift(a, l/r, SB), AB
 *                  ),
 *                  and(
 *                      shift(b, l/r, SB), AB
 *                  ),
 *                  will_do_or:T/F
 *              )
 * De:
 *      tmp = or(
 *                  and(
 *                      shift(a, l/r, SB), AB
 *                  ),
 *                  tmp
 *              )
 */

unsigned char *Encrypt(unsigned char *input, int base_choice) {
    unsigned char const *choice = base_choices[base_choice];
    memset(enresout, 0, choice[1] + 1);

    unsigned char counter = 0, nextCounter = 0;
    unsigned char tmp1 = 0, tmp2 = 0;

    unsigned char looper = choice[0];
    for (int i = 0; i < looper; i++) {
        counter = i * 5 + 2;
        enresout[i] = En_step(input[choice[counter + 1]], (SD) choice[counter + 2], (BYTE) choice[counter + 3],
                              (BYTE) choice[counter + 4]);
        nextCounter = (i + 1) * 5 + 2;
        if (nextCounter == 255u) {
            enresout[i] |= En_step(input[choice[nextCounter + 1]], (SD) choice[nextCounter + 2],
                                   (BYTE) choice[nextCounter + 3], (BYTE) choice[nextCounter + 4]);
            i++;
        }
    }

    return enresout;
}

unsigned char En_step(unsigned char a, SD sd, BYTE SB, BYTE AB) {
    return shift(a, sd, SB) & AB;
}

unsigned char *Decrypt(unsigned char *input, int base_choice) {
    unsigned char const *choice = base_choices[base_choice];
    unsigned char looper = choice[0] *



    return deresout;
}


unsigned char shift(unsigned char a, SD sd, BYTE _byte) {
    return sd ? a >> _byte : a << _byte;
}

unsigned char And(unsigned char a, BYTE _byte) {
    return a & _byte;
}

unsigned char Or(unsigned char a, unsigned char b, bool willDoOr) {
    return willDoOr ? a | b : a;
}

unsigned char Or(unsigned char a, unsigned char b) {
    return a | b;
}
