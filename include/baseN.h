#ifndef _baseN_h
#define _baseN_h

#include "BYTE.h"
#include "SD.h"

#define encrypt_choice_step         6
#define decrypt_choice_step         5
#define encrypt_input_size          7 + 1
#define encrypt_output_size         8 + 1
#define decrypt_input_size          8 + 1
#define decrypt_output_size         7 + 1

unsigned char shift(unsigned char a, SD sd, BYTE _byte);

unsigned char *Encrypt(unsigned char *output, unsigned char *input, int base_choice);

unsigned char *Decrypt(unsigned char *output, unsigned char *input, int base_choice);

unsigned char process_step(unsigned char a, SD sd, BYTE SB, BYTE AB);


#endif