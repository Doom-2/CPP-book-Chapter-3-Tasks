
#include <std_lib_facilities.h>

int cin_with_check_for_int(int val)
// Checks for positive integers, throws an error othewise.
// Returns correct integer.
{
    do {
        try {
            if (!(cin >> val)) throw 1;
            if (cin.good() && val < 0 && cin.peek() == '\n') throw 2;
            if (cin.peek() != '\n') throw 3;
        }
        catch (int i) {
            switch (i)
            {
            case 1:
            case 3:
                cerr << "Invalid input! Only integer is allowed.\n";
                cin.clear();
                break;
            case 2:
                cerr << "Invalid input! An integer must be a positive.\n";
                cin.clear();
                break;
            default:
                break;
            }
            while (cin.get() != '\n');
            continue;
        }
        break;
    } while (true);
    return val;
}

string plural_singular_zero_output(int num, string str)
// Adds an 's' ending if plural.
// Returns string in correct form.
{
    if (num == 0) return "You don't have any " + str + "s";
    else if (num == 1) return "You have " + to_string(num) + " " + str;
    else return "You have " + to_string(num) + " " + str + "s";
}

string calc_print_total(int _one_cent = 0, int _nickel = 0, int _dime = 0, int _twenty_five_cent = 0, int _fifty_cent = 0)
// Calculates total value of coins in dollars and cents.
// Returns a string in literary form.
{
    int _total_cents = _one_cent + _nickel * 5 + _dime * 10 + _twenty_five_cent * 25 + _fifty_cent * 50;
    string prefix = "The total value of your coins is ";
    if (_total_cents == 0) return "You're empty\n";
    else if (_total_cents < 100) return prefix + to_string(_total_cents);
    else if (_total_cents == 100) return prefix + "1 dollar\n";
    else if (_total_cents % 100 == 0) return prefix + to_string(_total_cents / 100) + " dollars\n";
    else if (_total_cents % 100 > 0 && _total_cents < 100000) return prefix + to_string(_total_cents / 100) + " dollars " + to_string(_total_cents % 100) + " cents\n";
    // rich status output
    else return prefix + to_string(_total_cents / 100) + " dollars " + to_string(_total_cents % 100) + " cents\nYou're rich!\n";
}

int main()
{
    int one_cent=0, nickel=0, dime=0, twenty_five_cent=0, fifty_cent=0;

    cout << "How many one-cent coins do you have?\n";
    one_cent = cin_with_check_for_int(one_cent);
    cout << "How many nickels do you have?\n";
    nickel = cin_with_check_for_int(nickel);
    cout << "How many dimes do you have?\n";
    dime = cin_with_check_for_int(dime);
    cout << "How many twenty_five_cent coins do you have?\n";
    twenty_five_cent = cin_with_check_for_int(twenty_five_cent);
    cout << "How many fifty_cent coins do you have?\n";
    fifty_cent = cin_with_check_for_int(fifty_cent);
    cout << endl;
    cout << plural_singular_zero_output(one_cent, "one-cent coin") << endl;
    cout <<  plural_singular_zero_output(nickel, "nickel") << endl;
    cout << plural_singular_zero_output(dime, "dime") << endl;
    cout << plural_singular_zero_output(twenty_five_cent, "twenty-five cent coin") << endl;
    cout << plural_singular_zero_output(fifty_cent, "fifty-cent coin") << endl << endl;
    cout << calc_print_total(one_cent, nickel, dime, twenty_five_cent, fifty_cent);
    cout << endl;
    system("pause");
}
