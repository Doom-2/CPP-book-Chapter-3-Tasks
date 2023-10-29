
#include <std_lib_facilities.h>

int main()
{
    cout.setf(ios::fixed);
    double val_1, val_2;
    while (1) {
        cout << "Enter 2 doubles, dividing the input by pressing 'Enter'.\n";
        cin >> val_1 >> val_2;

        //Numeric input validation
        if (!cin.eof())
        {
            int peeked = cin.peek();
            if (peeked == 10 && cin.good())
            {
                //Good!
                break;
            }
            else
            {
                cout << "Invalid input! Only decimal value is allowed.\n" << "Try again\n";
                cin.clear();
                while (cin.get() != '\n');
            }
        }
    }
    cout << setprecision(2);
    cout << "The lowest value is " << min(val_1, val_2) << endl;
    cout << "The biggest value is " << max(val_1, val_2) << endl;
    cout << "The sum of two doubles is " << val_1 + val_2 << endl;
    cout << "The difference of two doubles is " << val_1 - val_2 << endl;
    cout << "The product of two doubles is " << val_1 * val_2 << endl;

    try {
        if (val_2 == 0) {
            throw logic_error("Divide by zero");
        }
        else if (val_1 == 0)
            cout << "The quotient of two doubles is 0" << endl;
        else {
            double quotient = val_1 / val_2;
            cout << "The quotient of two doubles is " << setprecision(2) << quotient << endl;
        }
    }
    catch (logic_error e) {
        std::cerr << e.what();
    }
}
