#include <iostream>
#include "../include/BYTE.h"
#include "../include/SD.h"
#include "../include/baseN_N.h"

using namespace std;

#define encrypt_choice_step         6
#define decrypt_choice_step         5
#define encrypt_input_size          7 + 1
#define encrypt_output_size         8 + 1
#define decrypt_input_size          8 + 1
#define decrypt_output_size         7 + 1
unsigned char enresin[encrypt_input_size] = {0};
unsigned char deresin[decrypt_input_size] = {0};
unsigned char enresout[encrypt_output_size] = {0};
unsigned char deresout[decrypt_output_size] = {0};

unsigned char shift(unsigned char a, SD sd, BYTE _byte);

unsigned char *Encrypt(unsigned char *input, int base_choice);

unsigned char *Decrypt(unsigned char *input, int base_choice);

unsigned char process_step(unsigned char a, SD sd, BYTE SB, BYTE AB);

int main() {
    unsigned char tmp = 0xF0;
    unsigned char test[] = {tmp, tmp, tmp, tmp, tmp, tmp, tmp, 0x0};
//    unsigned char test[] = "abcdefg";
    for (int choice = 1; choice < 8; choice++) {
        Encrypt(test, choice);
        Decrypt(enresout, choice);

        cout << "=============choice: {" << choice << "}==============" << endl;
        for (unsigned char i : enresout) {
            printf("%#x\t", i);
        }
        cout << endl << "--------------------------" << endl;
//        cout << deresout << endl;
        for (unsigned char i : deresout) {
            printf("%#x\t", i);
        }
        cout << endl << "===============================" << endl;
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
    memset(enresout, 0, encrypt_output_size);

    unsigned char big_steps = choice[0];
    int currentPos = 2;
    for (int i = 0; i < big_steps; i++) {
        enresout[choice[currentPos + 1]] = process_step(input[choice[currentPos + 2]],
                                                        (SD) choice[currentPos + 3],
                                                        (BYTE) choice[currentPos + 4],
                                                        (BYTE) choice[currentPos + 5]);
        currentPos += encrypt_choice_step;
        if (choice[currentPos] == 255u) {
            enresout[choice[currentPos + 1]] |= process_step(input[choice[currentPos + 2]],
                                                             (SD) choice[currentPos + 3],
                                                             (BYTE) choice[currentPos + 4],
                                                             (BYTE) choice[currentPos + 5]);
            currentPos += encrypt_choice_step;
        }
    }

    return enresout;
}

//sd
unsigned char process_step(unsigned char a, SD sd, BYTE SB, BYTE AB) {
    return shift(a, sd, SB) & AB;
}

unsigned char *Decrypt(unsigned char *input, int base_choice) {
    unsigned char const *choice = base_choices[base_choice];
    memset(deresout, 0, decrypt_output_size);

    unsigned char total_stepsIndex = choice[0] * encrypt_choice_step
                                     + choice[1] * (encrypt_choice_step)
                                     + 2;
    unsigned char total_steps = choice[total_stepsIndex];
    unsigned char time_repeated = 0, currentPos = total_stepsIndex;

    currentPos += 2;// point to the time_repeated
    for (unsigned char i = 0; i < total_steps; i++) {
        time_repeated = choice[currentPos++];
        for (unsigned char j = 0; j < time_repeated; j++) {
            deresout[choice[currentPos]] |= process_step(input[choice[currentPos + 1]],
                                                         (SD) choice[currentPos + 2],
                                                         (BYTE) choice[currentPos + 3],
                                                         (BYTE) choice[currentPos + 4]);
            currentPos += decrypt_choice_step;
        }
    }

    return deresout;
}

unsigned char shift(unsigned char a, SD sd, BYTE _byte) {
    return sd ? a >> _byte : a << _byte;
}

unsigned char Or(unsigned char a, unsigned char b) {
    return a | b;
}
