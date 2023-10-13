
#include <std_lib_facilities.h>
using namespace std;

int main()
{
    cout << "Enter recipient name (and press 'Enter'):\n";
    string first_name;
    cin >> first_name;
    cout << "Enter your friend name (and press 'Enter'):\n";
    string friend_name;
    cin >> friend_name;
    cout << "Enter your friend sex (and press 'Enter'):\n";
    string friend_sex_input;
    char friend_sex;
    string pronoun;
    bool done = false;
    do
    {
        getline(std::cin, friend_sex_input);
        if (friend_sex_input.length() > 1)
        {
            cout << "Error! Only single character is allowed.\n";
            continue;
        }
        else
            friend_sex = friend_sex_input[0];
        switch (friend_sex)
        {
        case 'm':
            pronoun = "him";
            done = true;
            break;
        case 'f':
            pronoun = "her";
            done = true;
            break;
        case 'q':
            return 0;
        case '\0':
            break;
        default:
            cout << "Please type either 'm' or 'f' or 'q' to quit the program\n";
            break;
        }
    } while (!done);
    done = false;
    cout << "Dear " << first_name << ",\n" << "How are you doing? I'm fine. I miss you." << endl;
    cout << "How long have you met " << friend_name << "?\n";
    cout << "If you see " << friend_name << ", please ask " << pronoun << " to call me.\n";
    int age;

    do {
        try {
            cout << "Enter recipient age (and press 'Enter'):\n";
            if (!(cin >> age)) throw 1;
            if (cin.peek() != '\n') throw 2;
        }
        catch (int i) {
            if (i == 1) cin.clear();
            while (cin.get() != '\n');
            cerr << "Invalid input! Only integer value is allowed.\n";
            continue;
        }
        break;
    } while (true);

    if (age <= 0 || age >= 110)
        simple_error("You're kidding!");
    else
    {
        cout << "I heard you just celebrated your birthday and you turned " << age << ".\n";
        done = true;
    }

    if (age < 12)
        cout << "Next year you will be " << age + 1 << " years old.\n";
    else if (age == 17)
        cout << "Next year you will be able to vote.\n";
    else if (age > 70)
        cout << "I hope you're not bored in retirement.\n";

    cout << "Sincerely yours" << endl << endl;
    string my_name;
    cin >> my_name;
    system("pause");
}
