#include <iostream>
using namespace std;

typedef enum BYTE{
    Ox0_=0x0u, Ox1_, Ox2_, Ox3_, Ox4_, Ox5_, Ox6_, Ox7_,
    OxC0_=0xC0, Ox30_=0x30, Ox0C_=0x0C, Ox03_=Ox3_,
    OxE0_=0xE0, Ox1C_=0x1C, Ox80_=0x80, Ox70_=0x70, Ox38_=0x38,
    Ox0F_=0x0F,
    Ox1F_=0x1F,
    OxF8_=0xF8, Ox3E_=0x3E, OxF0_=0xF0, Ox7C_=0x7C,
    Ox3F_=0x3F,
    OxFC_=0xFC,
    Ox7F_=0x7F, OxFE_=0xFE,

	OxFF_=0xFFu
}BYTE;

int main()
{
//	cout << to_string(OxFF_) << endl;
//	cout << to_string(Ox0_) << endl;
    cout << (170 << Ox4_) << endl;
	return 0;
}
