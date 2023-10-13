
#include <std_lib_facilities.h>

int main()
{
    string user_input;
    int user_val = 0;
    cout << "Enter digit 1, 2, 3 or 4 as word - one, two, three or four:\n";
    cin >> user_input;

    if (user_input == "one") user_val = 1;
    else if (user_input == "two") user_val = 2;
    else if (user_input == "three") user_val = 3;
    else if (user_input == "four") user_val = 4;
    
    if (user_val) cout << "You have entered number " << user_val << endl;
    else cout << "I don't know such a number.\n";
}
