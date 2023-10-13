
#include <std_lib_facilities.h>

int main()
{
    int val_1, val_2, val_3;

    do {
        try {
            cout << "Enter 3 integers, dividing the input by pressing 'Enter'.\n";
            if (!(cin >> val_1 >> val_2 >> val_3)) throw 1;
            if (cin.peek() != '\n') throw 2;
        }
        catch (int i) {
            if (i == 1) cin.clear();
            while (cin.get() != '\n');
            cerr << "Invalid input! Only integers are allowed.\n";
            continue;
        }
        break;
    } while (true);

    if (val_1 > val_3) swap(val_1, val_3);
    if (val_1 > val_2) swap(val_1, val_2);
    if (val_2 > val_3) swap(val_2, val_3);

    cout << val_1 << ", " << val_2 << ", " << val_3 << endl;
}
