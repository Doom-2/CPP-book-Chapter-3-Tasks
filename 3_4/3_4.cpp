
#include <std_lib_facilities.h>

int main()
{
    cout.setf(ios::fixed);
    int val_1, val_2;

    do {
        try {
            cout << "Enter 2 integers, dividing the input by pressing 'Enter'.\n";
            if (!(cin >> val_1 >> val_2)) throw 1;
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

    cout << "The lowest value is " << min(val_1, val_2) << endl;
    cout << "The biggest value is " << max(val_1, val_2) << endl;
    cout << "The sum of two integers is " << val_1 + val_2 << endl;
    cout << "The difference of two integers is " << val_1 - val_2 << endl;
    cout << "The product of two integers is " << val_1 * val_2 << endl;

    try {
        if (val_2 == 0) {
            throw logic_error("Divide by zero");
        }
        else if (val_1 == 0)
            cout << "The quotient of two integers is 0" << endl;
        else {
            double quotient = static_cast<double>(val_1) / val_2;
            cout << "The quotient of two integers is " << setprecision(2) << quotient << endl;
        }
    }
    catch (logic_error e) {
        std::cerr << e.what();
    }
}