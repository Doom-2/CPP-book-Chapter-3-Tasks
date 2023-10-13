
#include <std_lib_facilities.h>

int main()
{
    cout.setf(ios::fixed);
    cout << "Enter distance in miles. I'll convert it in kilometers\n";
    double dist_in_miles;

    //Reading the value

    while (1) {
        cin >> dist_in_miles;

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

    double dist_in_km = dist_in_miles * 1.609;
    stringstream ss;
    ss <<fixed << setprecision(2) << dist_in_km;
    string dist_in_km_str = ss.str();
    // Ensure that there is a decimal point somewhere (there should be)
    if (dist_in_km_str.find('.') != string::npos)
    {
        // Remove trailing zeroes
        dist_in_km_str = dist_in_km_str.substr(0, dist_in_km_str.find_last_not_of('0') + 1);
        // If the decimal point is now the last character, remove that as well
        if (dist_in_km_str.find('.') == dist_in_km_str.size() - 1)
        {
            dist_in_km_str = dist_in_km_str.substr(0, dist_in_km_str.size() - 1);
        }
    }
    cout << "Distance in kilometers (with trailing zeros) is " << setprecision(2) << dist_in_km << std::endl;
    cout << "Distance in kilometers is " << dist_in_km_str << std::endl;

    }
