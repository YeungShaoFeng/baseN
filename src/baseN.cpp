#include "../include/baseN.h"
#include <iostream>
#include "../include/baseN_N.h"


unsigned char enresin[encrypt_input_size] = {0};
unsigned char deresin[decrypt_input_size] = {0};
unsigned char enresout[encrypt_output_size] = {0};
unsigned char deresout[decrypt_output_size] = {0};


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

unsigned char *Encrypt(unsigned char *output, unsigned char *input, int base_choice) {
    unsigned char const *choice = base_choices[base_choice];
    memset(output, 0, encrypt_output_size);

    unsigned char big_steps = choice[0];
    int currentPos = 2;
    for (int i = 0; i < big_steps; i++) {
        output[choice[currentPos + 1]] = process_step(input[choice[currentPos + 2]],
                                                      (SD) choice[currentPos + 3],
                                                      (BYTE) choice[currentPos + 4],
                                                      (BYTE) choice[currentPos + 5]);
        currentPos += encrypt_choice_step;
        if (choice[currentPos] == 255u) {
            output[choice[currentPos + 1]] |= process_step(input[choice[currentPos + 2]],
                                                           (SD) choice[currentPos + 3],
                                                           (BYTE) choice[currentPos + 4],
                                                           (BYTE) choice[currentPos + 5]);
            currentPos += encrypt_choice_step;
        }
    }

    return output;
}

//sd
unsigned char process_step(unsigned char a, SD sd, BYTE SB, BYTE AB) {
    return shift(a, sd, SB) & AB;
}

unsigned char *Decrypt(unsigned char *output, unsigned char *input, int base_choice) {
    unsigned char const *choice = base_choices[base_choice];
    memset(output, 0, decrypt_output_size);

    unsigned char total_stepsIndex = choice[0] * encrypt_choice_step
                                     + choice[1] * (encrypt_choice_step)
                                     + 2;
    unsigned char total_steps = choice[total_stepsIndex];
    unsigned char time_repeated = 0, currentPos = total_stepsIndex;

    currentPos += 2;// point to the time_repeated
    for (unsigned char i = 0; i < total_steps; i++) {
        time_repeated = choice[currentPos++];
        for (unsigned char j = 0; j < time_repeated; j++) {
            output[choice[currentPos]] |= process_step(input[choice[currentPos + 1]],
                                                       (SD) choice[currentPos + 2],
                                                       (BYTE) choice[currentPos + 3],
                                                       (BYTE) choice[currentPos + 4]);
            currentPos += decrypt_choice_step;
        }
    }

    return output;
}

unsigned char shift(unsigned char a, SD sd, BYTE _byte) {
    return sd ? a >> _byte : a << _byte;
}
