
#include <std_lib_facilities.h>

int main()
{
    cout.setf(ios::fixed);
    cout << "Enter operation and two operands in following manner :'\n'";
    cout << "+ 100 3.14'\n'" << "'* 4 5\n'" << "div 40 8.3684'\n'";
    cout << "Allowed operations are '+', '-', '*', '/', 'plus', 'minus', 'mul', 'div'.\n";
    string oper;
    double operand_1, operand_2;
    cin >> oper;

    while (1) {
        cin >> operand_1 >> operand_2;

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
                cout << "Invalid input! Only decimal value is allowed.\n" << "Try input operands again\n";
                cin.clear();
                while (cin.get() != '\n');
            }
        }
    }
    cout << setprecision(2);
    if (oper == "+" || oper == "plus") cout << operand_1 + operand_2;
    else if (oper == "-" || oper == "minus") cout << operand_1 - operand_2;
    else if (oper == "*" || oper == "mul") cout << operand_1 * operand_2;
    else if (oper == "/" || oper == "div") {
        try {
            if (operand_2 == 0) {
                throw logic_error("Divide by zero");
            }
            else if (operand_1 == 0)
                cout << 0 << endl;
            else {
                cout << operand_1 / operand_2;
            }
        }
        catch (logic_error e) {
            std::cerr << e.what();
        }
    }
    else cout <<"'" << oper << "' - unknown operation type.\n";
}
