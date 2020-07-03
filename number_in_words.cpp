// Program to convert number to words
// Author: Nishith

#include <iostream>
#include <cmath>
using namespace std;

// Declaration of functions
string to_words (long long int);
string _1digit            (int);
string _2digits           (int);
string _3digits           (int);
string _4digits           (int);
string _5digits      (long int);
string _6digits      (long int);
string _7digits      (long int);
string _8digits      (long int);
string _9digits      (long int);
string _10digits(long long int);

// Global declaration of boolean variables to see that if a function is executed or not, excluding default cases
bool hasPassedFunc5digits = false, hasPassedFunc6digits = false, hasPassedFunc7digits = false, hasPassedFunc9digits = false, hasPassedFunc10digits = false;
short int error_count = 0;
int main()
{
    long long int num;
    char wanna_try_again;
    string words = ""; // Target string
    cout << "Enter a number: ";
    cin>> num;
    if(num < 0)
    {
        num = abs(num);
        words += " -";
    }
    words += to_words(num); // Function call
    if(words != "") // Error handling for empty strings
    cout << num << " in words is:" << words << endl;
    cout << "Do you want to try again (y/n): " << flush;
    cin >> wanna_try_again;
    if(wanna_try_again == 'y' || wanna_try_again == 'Y')
        main();
    return 0;
}

string to_words(long long int num)
{
    int count = 0;
    string words = "";
    for (long long int temp = num; temp > 0; temp/=10) // Counting its length
        count++;
    switch (count)
    {
        case 0: words += " Zero";
                break;
        case 1: words += _1digit(num); // If input consists single digit
                break;
        case 2: words += _2digits(num); // If input consists 2 digits
                break;
        case 3: words += _3digits(num); // If input consists 3 digits
                break;
        case 4: words += _4digits(num); // If input consists 4 digits
                break;
        case 5: words += _5digits(num); // If input consists 5 digits
                break;
        case 6: words += _6digits(num); // If input consists 6 digits
                break;
        case 7: words += _7digits(num); // If input consists 7 digits
                break;
        case 8: words += _8digits(num); // If input consists 8 digits
                break;
        case 9: words += _9digits(num); // If input consists 9 digits
                break;
        case 10: words += _10digits(num); // If input consists 10 digits
                break;
        default: cout << "The number is too big :( \n";
                if(error_count < 10)
                {
                    cout << "Try again...\n\n";
                    main();
                    error_count++;
                }
    }
    return words;
}

string _1digit(int num)
{
    string words = "";
    switch (num)
    {
        case 1: words += " One";
                break;
        case 2: words += " Two";
                break;
        case 3: words += " Three";
                break;
        case 4: words += " Four";
                break;
        case 5: words += " Five";
                break;
        case 6: words += " Six";
                break;
        case 7: words += " Seven";
                break;
        case 8: words += " Eight";
                break;
        case 9: words += " Nine";
                break;
    }
    return words;
}

string _2digits(int num)
{
    string words = "";
    int unit = num % 10;
    switch (num)
    {
        case 10: words += " Ten";
                break;
        case 11: words += " Eleven";
                unit /= 10;
                break;
        case 12: words += " Twelve";
                unit /= 10;
                break;
        case 13: words += " Thirteen";
                unit /= 10;
                break;
        case 14: words += " Fourteen";
                unit /= 10;
                break;
        case 15: words += " Fifteen";
                unit /= 10;
                break;
        case 16: words += " Sixteen";
                unit /= 10;
                break;
        case 17: words += " Seventeen";
                unit /= 10;
                break;
        case 18: words += " Eighteen";
                unit /= 10;
                break;
        case 19: words += " Nineteen";
                unit /= 10;
                break;
        default: num /= 10;
    }
    switch (num)
    {
        case 2: words += " Twenty";
                break;
        case 3: words += " Thirty";
                break;
        case 4: words += " Forty";
                break;
        case 5: words += " Fifty";
                break;
        case 6: words += " Sixty";
                break;
        case 7: words += " Seventy";
                break;
        case 8: words += " Eighty";
                break;
        case 9: words += " Ninety";
                break;
    }
    words += _1digit(unit); // For the number at unit place
    return words;
}

string _3digits(int num)
{
    string words = "";
    int tens = num % 100;
    num /= 100;
    switch (num)
    {
        case 1: words += " One";
                break;
        case 2: words += " Two";
                break;
        case 3: words += " Three";
                break;
        case 4: words += " Four";
                break;
        case 5: words += " Five";
                break;
        case 6: words += " Six";
                break;
        case 7: words += " Seven";
                break;
        case 8: words += " Eight";
                break;
        case 9: words += " Nine";
                break;
        default: goto skiphundred;
    }
    words += " Hundred";
    skiphundred:
    if(tens != 0)
        words += " and";
    words += _2digits(tens); // For the number at tens place
    return words;
}

string _4digits(int num)
{
    string words = "";
    int hundreds = num % 1000;
    num /= 1000;
    switch (num)
    {
        case 1: words += " One";
                break;
        case 2: words += " Two";
                break;
        case 3: words += " Three";
                break;
        case 4: words += " Four";
                break;
        case 5: words += " Five";
                break;
        case 6: words += " Six";
                break;
        case 7: words += " Seven";
                break;
        case 8: words += " Eight";
                break;
        case 9: words += " Nine";
                break;
        default: if(!hasPassedFunc5digits || (hasPassedFunc6digits && !hasPassedFunc5digits))
                { goto skipthousand; }
    }
    words += " Thousand";
    if(num != 1)
        words += "s";
    skipthousand:
    words += _3digits(hundreds); // For the number at hundreds place
    return words;
}

string _5digits(long int num)
{
    string words = "";
    int thousands = num % 10000;
    num /= 1000;
    switch (num)
    {
        case 10: words += " Ten";
                hasPassedFunc5digits = true;
                thousands %= 10000;
                break;
        case 11: words += " Eleven";
                hasPassedFunc5digits = true;
                thousands %= 1000;
                break;
        case 12: words += " Twelve";
                hasPassedFunc5digits = true;
                thousands %= 1000;
                break;
        case 13: words += " Thirteen";
                hasPassedFunc5digits = true;
                thousands %= 1000;
                break;
        case 14: words += " Fourteen";
                hasPassedFunc5digits = true;
                thousands %= 1000;
                break;
        case 15: words += " Fifteen";
                hasPassedFunc5digits = true;
                thousands %= 1000;
                break;
        case 16: words += " Sixteen";
                hasPassedFunc5digits = true;
                thousands %= 1000;
                break;
        case 17: words += " Seventeen";
                hasPassedFunc5digits = true;
                thousands %= 1000;
                break;
        case 18: words += " Eighteen";
                hasPassedFunc5digits = true;
                thousands %= 1000;
                break;
        case 19: words += " Nineteen";
                hasPassedFunc5digits = true;
                thousands %= 1000;
                break;
        default: num /= 10;
    }
    switch (num)
    {
        case 2: words += " Twenty";
                hasPassedFunc5digits = true;
                break;
        case 3: words += " Thirty";
                hasPassedFunc5digits = true;
                break;
        case 4: words += " Forty";
                hasPassedFunc5digits = true;
                break;
        case 5: words += " Fifty";
                hasPassedFunc5digits = true;
                break;
        case 6: words += " Sixty";
                hasPassedFunc5digits = true;
                break;
        case 7: words += " Seventy";
                hasPassedFunc5digits = true;
                break;
        case 8: words += " Eighty";
                hasPassedFunc5digits = true;
                break;
        case 9: words += " Ninety";
                hasPassedFunc5digits = true;
                break;
    }
    words += _4digits(thousands); // For the number at thousands place
    return words;
}

string _6digits(long int num)
{
    string words = "";
    int tths = num % 100000;
    num /= 100000;
    switch (num)
    {
        case 1: words += " One";
                hasPassedFunc6digits = true;
                break;
        case 2: words += " Two";
                hasPassedFunc6digits = true;
                break;
        case 3: words += " Three";
                hasPassedFunc6digits = true;
                break;
        case 4: words += " Four";
                hasPassedFunc6digits = true;
                break;
        case 5: words += " Five";
                hasPassedFunc6digits = true;
                break;
        case 6: words += " Six";
                hasPassedFunc6digits = true;
                break;
        case 7: words += " Seven";
                hasPassedFunc6digits = true;
                break;
        case 8: words += " Eight";
                hasPassedFunc6digits = true;
                break;
        case 9: words += " Nine";
                hasPassedFunc6digits = true;
                break;
        default: if(!hasPassedFunc7digits)
                { goto skiplakh; }
    }
    words += " Lakh";
    if(num != 1 )
        words += "s";
    skiplakh:
    words += _5digits(tths); // For the number at tenthousands place
    return words;
}

string _7digits(long int num)
{
    string words = "";
    int lakh = num % 1000000;
    num /= 100000;
    switch (num)
    {
        case 10: words += " Ten";
                hasPassedFunc7digits = true;
                lakh %= 100000;
                break;
        case 11: words += " Eleven";
                hasPassedFunc7digits = true;
                lakh %= 100000;
                break;
        case 12: words += " Twelve";
                hasPassedFunc7digits = true;
                lakh %= 100000;
                break;
        case 13: words += " Thirteen";
                hasPassedFunc7digits = true;
                lakh %= 100000;
                break;
        case 14: words += " Fourteen";
                hasPassedFunc7digits = true;
                lakh %= 100000;
                break;
        case 15: words += " Fifteen";
                hasPassedFunc7digits = true;
                lakh %= 100000;
                break;
        case 16: words += " Sixteen";
                hasPassedFunc7digits = true;
                lakh %= 100000;
                break;
        case 17: words += " Seventeen";
                hasPassedFunc7digits = true;
                lakh %= 100000;
                break;
        case 18: words += " Eighteen";
                hasPassedFunc7digits = true;
                lakh %= 100000;
                break;
        case 19: words += " Nineteen";
                hasPassedFunc7digits = true;
                lakh %= 100000;
                break;
        default: num /= 10;
    }
    switch (num)
    {
        case 2: words += " Twenty";
                hasPassedFunc7digits = true;
                break;
        case 3: words += " Thirty";
                hasPassedFunc7digits = true;
                break;
        case 4: words += " Forty";
                hasPassedFunc7digits = true;
                break;
        case 5: words += " Fifty";
                hasPassedFunc7digits = true;
                break;
        case 6: words += " Sixty";
                hasPassedFunc7digits = true;
                break;
        case 7: words += " Seventy";
                hasPassedFunc7digits = true;
                break;
        case 8: words += " Eighty";
                hasPassedFunc7digits = true;
                break;
        case 9: words += " Ninety";
                hasPassedFunc7digits = true;
                break;
    }
    words += _6digits(lakh); // For the number at lakhs place
    return words;
}

string _8digits(long int num)
{
    string words = "";
    int tlakhs = num % 10000000;
    num /= 10000000;
    switch (num)
    {
        case 1: words += " One";
                break;
        case 2: words += " Two";
                break;
        case 3: words += " Three";
                break;
        case 4: words += " Four";
                break;
        case 5: words += " Five";
                break;
        case 6: words += " Six";
                break;
        case 7: words += " Seven";
                break;
        case 8: words += " Eight";
                break;
        case 9: words += " Nine";
                break;
        default: if(!hasPassedFunc9digits && !hasPassedFunc10digits)
                    { goto skipcrore; }
    }
    words += " Crore";
    if(num != 1 )
        words += "s";
    skipcrore:
    words += _7digits(tlakhs); // For the number at tenlakhs place
    return words;
}

string _9digits(long int num)
{
    string words = "";
    int crores = num % 100000000;
    num /= 10000000;
    switch (num)
    {
        case 10: words += " Ten";
                hasPassedFunc9digits = true;
                break;
        case 11: words += " Eleven";
                hasPassedFunc9digits = true;
                break;
        case 12: words += " Twelve";
                hasPassedFunc9digits = true;
                break;
        case 13: words += " Thirteen";
                hasPassedFunc9digits = true;
                break;
        case 14: words += " Fourteen";
                hasPassedFunc9digits = true;
                break;
        case 15: words += " Fifteen";
                hasPassedFunc9digits = true;
                break;
        case 16: words += " Sixteen";
                hasPassedFunc9digits = true;
                break;
        case 17: words += " Seventeen";
                hasPassedFunc9digits = true;
                break;
        case 18: words += " Eighteen";
                hasPassedFunc9digits = true;
                break;
                hasPassedFunc9digits = true;
        case 19: words += " Nineteen";
                hasPassedFunc9digits = true;
                break;
        default: num /= 10;
    }
    switch (num)
    {
        case 2: words += " Twenty";
                hasPassedFunc9digits = true;
                break;
        case 3: words += " Thirty";
                hasPassedFunc9digits = true;
                break;
        case 4: words += " Forty";
                hasPassedFunc9digits = true;
                break;
        case 5: words += " Fifty";
                hasPassedFunc9digits = true;
                break;
        case 6: words += " Sixty";
                hasPassedFunc9digits = true;
                break;
        case 7: words += " Seventy";
                hasPassedFunc9digits = true;
                break;
        case 8: words += " Eighty";
                hasPassedFunc9digits = true;
                break;
        case 9: words += " Ninety";
                hasPassedFunc9digits = true;
                break;
        default: crores %= 10000000;
    }
    words += _8digits(crores); // For the number at crores place
    return words;
}

string _10digits(long long int num)
{
    string words = "";
    int tcrores = num % 1000000000;
    num /= 1000000000;
    switch (num)
    {
        case 1: words += " One";
                hasPassedFunc10digits = true;
                break;
        case 2: words += " Two";
                hasPassedFunc10digits = true;
                break;
        case 3: words += " Three";
                hasPassedFunc10digits = true;
                break;
        case 4: words += " Four";
                hasPassedFunc10digits = true;
                break;
        case 5: words += " Five";
                hasPassedFunc10digits = true;
                break;
        case 6: words += " Six";
                hasPassedFunc10digits = true;
                break;
        case 7: words += " Seven";
                hasPassedFunc10digits = true;
                break;
        case 8: words += " Eight";
                hasPassedFunc10digits = true;
                break;
        case 9: words += " Nine";
                hasPassedFunc10digits = true;
                break;
    }
    words += " Hundred";
    words += _9digits(tcrores); // For the number at ten crores place
    return words;
}
