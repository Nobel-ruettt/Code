#include <bitset>
#include <iostream>
#include <limits>

using namespace std;

int main( )
{
   // write a decimal integer as a binary number
   int num = 100;
   cout  << "\n\nDecimal number: " << num << "\tBinary equivalent: " << bitset<8>(num) << endl;
}
