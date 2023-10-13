
#include <std_lib_facilities.h>

int main()
{
    string str_1, str_2, str_3;
    int str_1_3_cmp, str_1_2_cmp, str_2_3_cmp;

    cout << "Enter 3 strings, dividing the input by pressing 'Enter'.\n";
    cin >> str_1 >> str_2 >> str_3;
    str_1_3_cmp = str_1.compare(str_3);
    str_1_2_cmp = str_1.compare(str_2);
    str_2_3_cmp = str_2.compare(str_3);

    if (str_1.compare(str_3)) swap(str_1, str_3);
    if (str_1.compare(str_2)) swap(str_1, str_2);
    if (str_2.compare(str_3)) swap(str_2, str_3);

    cout << str_1 << ", " << str_2 << ", " << str_3 << endl;
}
