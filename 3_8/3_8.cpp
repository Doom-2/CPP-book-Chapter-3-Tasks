
#include <std_lib_facilities.h>

int main()
{
    int val;

    do {
        try {
            cout << "Enter an integer. I'll check whether it even or not:\n";
            if (!(cin >> val)) throw 1;
            if (cin.peek() != '\n') throw 2;
        }
        catch (int i) {
            if (i == 1) cin.clear();
            while (cin.get() != '\n');
            cerr << "Invalid input! Only integer is allowed.\n";
            continue;
        }
        break;
    } while (true);

    if (val % 2 == 0) cout << val << " - an even number" << endl;
    else  cout << val << " - an odd number" << endl;
}
