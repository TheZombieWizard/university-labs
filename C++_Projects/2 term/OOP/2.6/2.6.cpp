#include "BigBinaryNum.h"


int main()
{
    BigBinaryNum bigbin("101010");
    cout << "Enter binary num: " << endl;
    cin >> bigbin;
    cout << bigbin << endl;
    cout << bigbin.bin2dec() << "  //Conversion" << endl;


    
    cout << endl << "Operations test: " << endl;
    BigBinaryNum operations_test("101");
    cout << "  " << bigbin << " and " << operations_test << endl;
    cout << "  " << bigbin.bin2dec() << " and " << operations_test.bin2dec() << endl;
    cout << "  " << (bigbin - operations_test) << "  //Substraction binary" << endl;
    cout << "  " << (bigbin - operations_test).bin2dec() << "  //Substraction decimal" << endl;
    cout << "  " << (bigbin / operations_test) << "  //Subdivision" << endl;
    cout << "  " << (bigbin % operations_test) << "  //Remainder division binary" << endl;
    cout << "  " << (bigbin % operations_test).bin2dec() << "  //Remainder division decimal" << endl;



    cout << endl << "Offsets test: " << endl;
    
    BigBinaryNum left_offset_test("1010101111");
    cout << "  " << left_offset_test << "  //Original" << endl;
    left_offset_test < 5;
    cout << "  " << left_offset_test << "  //Left offset" << endl;    

    BigBinaryNum right_offset_test("1010101111");
    right_offset_test > 5;
    cout << "  " << right_offset_test << "  //Right offset" << endl;    

    BigBinaryNum task;
    task.resize(201);
    task[0] = 1;
    cout << "//" << task.bin2dec();

    return 0;
}