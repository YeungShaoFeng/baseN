#include <iostream>
#include "../include/baseN.h"

using namespace std;


int main() {
    unsigned char tmp = 0xFF;
    unsigned char test[] = {tmp, tmp, tmp, tmp, tmp, tmp, tmp, 0x0};
    unsigned char enresout[encrypt_output_size] = {0},
            deresout[decrypt_output_size] = {0};
//    unsigned char test[] = "abcdefg";
    for (int choice = 1; choice < 8; choice++) {
        Encrypt(enresout, test, choice);
        Decrypt(deresout, enresout, choice);

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
