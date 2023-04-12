#include "BigBinaryNum.h"


int main()
{
    BigBinaryNum bigbin("101010");
    cout << bigbin << endl;
    cout << bigbin.bin2dec() << "  //Conversion" << endl;


    
    cout << endl << "Operations test: " << endl;
    BigBinaryNum operations_test("101");
    cout << "  " << bigbin << " and " << operations_test << endl;
    cout << "  " << (bigbin - operations_test) << "  //Substraction" << endl;
    cout << "  " << (bigbin / operations_test) << "  //Subdivision" << endl;
    cout << "  " << (bigbin % operations_test) << "  //Remainder division" << endl;



    cout << endl << "Offsets test: " << endl;
    
    BigBinaryNum left_offset_test("1010101111");
    cout << "  " << left_offset_test << "  //Original" << endl;
    left_offset_test < 5;
    cout << "  " << left_offset_test << "  //Left offset" << endl;    

    BigBinaryNum right_offset_test("1010101111");
    right_offset_test > 5;
    cout << "  " << right_offset_test << "  //Right offset" << endl;    
    
    return 0;
}