#include <iostream>
#include <string>
using namespace std;

class StringOperations
{
private:
    string str1, str2;

public:
    void inputString1()
    {
        cout << "Enter first string: ";
        cin.ignore();
        getline(cin, str1);
    }

    void inputString2()
    {
        cout << "Enter second string: ";
        cin.ignore();
        getline(cin, str2);
    }

    void concatenate()
    {
        cout << "Concatenated string: " << str1 + str2 << endl;
    }

    void reverseString()
    {
        string temp = str1;
        int n = temp.length();
        for (int i = 0; i < n / 2; i++)
        {
            char ch = temp[i];
            temp[i] = temp[n - i - 1];
            temp[n - i - 1] = ch;
        }
        cout << "Reversed string: " << temp << endl;
    }

    void deleteVowels()
    {
        string temp = str1;
        string result = "";
        for (int i = 0; i < temp.length(); i++)
        {
            char lower = temp[i];
            if (lower >= 'A' && lower <= 'Z') 
                lower = lower + 32;

            if (!(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'))
            {
                result += temp[i];
            }
        }
        cout << "String without vowels: " << result << endl;
    }

    void sortStrings()
    {
        string temp = str1;
        int n = temp.length();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (temp[i] > temp[j])
                {
                    char ch = temp[i];
                    temp[i] = temp[j];
                    temp[j] = ch;
                }
            }
        }
        cout << "Alphabetically sorted characters: " << temp << endl;
    }

    void toLowercase()
    {
        string temp = str1;
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] >= 'A' && temp[i] <= 'Z')
            {
                temp[i] = temp[i] + 32;
            }
        }
        cout << "Lowercase string: " << temp << endl;
    }
};

int main()
{
    StringOperations obj;
    int choice;

    do
    {
        cout << "\nSTRING OPERATIONS MENU\n";
        cout << "1. Concatenate two strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete vowels from a string\n";
        cout << "4. Sort string characters alphabetically\n";
        cout << "5. Convert string to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.inputString1();
            obj.inputString2();
            obj.concatenate();
            break;

        case 2:
            obj.inputString1();
            obj.reverseString();
            break;

        case 3:
            obj.inputString1();
            obj.deleteVowels();
            break;

        case 4:
            obj.inputString1();
            obj.sortStrings();
            break;

        case 5:
            obj.inputString1();
            obj.toLowercase();
            break;

        case 6:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
