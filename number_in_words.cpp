// Program to convert number to words @C++
// Author: Nishith

#include <iostream>
#include <cmath>
using namespace std;

// Declaration of functions
string to_words(long int);
string _1digit      (int);
string _2digits     (int);
string _3digits     (int);
string _4digits     (int);
string _5digits(long int);
string _6digits(long int);
string _7digits(long int);
string _8digits(long int);
string _9digits(long int);

// Global declaration of boolean variables to see that if a function is executed or not
bool pass5 = false, pass7 = false, pass9 = false;
bool isnegative = false;
short int try_again = 0;
int main()
{
    long int num;
    string words = ""; // Target string
    cout << "Enter a number: ";
    cin>> num;
    if(num < 0)
    {
        isnegative = true;
        num = abs(num);
        words += " -";
    }
    words += to_words(num); // Function call
    if(words != "") // Error handling
    cout << num << " in words is:" << words << endl; // Output printing
    main();
    return 0;
}

string to_words(long int num)
{
    int count = 0;
    string words = "";
    for (long int temp = num; temp > 0; temp/=10) // Counting its length
        count++;
    switch (count)
    {
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
        default: cout << "The number is too big :( \n";
                if(try_again < 10)
                {
                    cout << "Try again...\n\n";
                    main();
                    try_again++;
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
        default: if(!pass5) { goto skipthousand; }
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
                pass5 = true;
                break;
        case 11: words += " Eleven";
                pass5 = true;
                break;
        case 12: words += " Twelve";
                pass5 = true;
                break;
        case 13: words += " Thirteen";
                pass5 = true;
                break;
        case 14: words += " Fourteen";
                pass5 = true;
                break;
        case 15: words += " Fifteen";
                pass5 = true;
                break;
        case 16: words += " Sixteen";
                pass5 = true;
                break;
        case 17: words += " Seventeen";
                pass5 = true;
                break;
        case 18: words += " Eighteen";
                pass5 = true;
                break;
        case 19: words += " Nineteen";
                pass5 = true;
                break;
        default: num /= 10;
    }
    switch (num)
    {
        case 2: words += " Twenty";
                pass5 = true;
                break;
        case 3: words += " Thirty";
                pass5 = true;
                break;
        case 4: words += " Forty";
                pass5 = true;
                break;
        case 5: words += " Fifty";
                pass5 = true;
                break;
        case 6: words += " Sixty";
                pass5 = true;
                break;
        case 7: words += " Seventy";
                pass5 = true;
                break;
        case 8: words += " Eighty";
                pass5 = true;
                break;
        case 9: words += " Ninety";
                pass5 = true;
                break;
        default: thousands %= 1000;
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
        default: if(!pass7) { goto skiplakh; }
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
                break;
        case 11: words += " Eleven";
                break;
        case 12: words += " Twelve";
                break;
        case 13: words += " Thirteen";
                break;
        case 14: words += " Fourteen";
                break;
        case 15: words += " Fifteen";
                break;
        case 16: words += " Sixteen";
                break;
        case 17: words += " Seventeen";
                break;
        case 18: words += " Eighteen";
                break;
        case 19: words += " Nineteen";
                break;
        default: num /= 10;
                pass7 = true;
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
        default: lakh /= 10;
                pass7 = true;
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
        default: goto skipcrore;
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
                break;
        case 11: words += " Eleven";
                break;
        case 12: words += " Twelve";
                break;
        case 13: words += " Thirteen";
                break;
        case 14: words += " Fourteen";
                break;
        case 15: words += " Fifteen";
                break;
        case 16: words += " Sixteen";
                break;
        case 17: words += " Seventeen";
                break;
        case 18: words += " Eighteen";
                break;
        case 19: words += " Nineteen";
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
    words += _8digits(crores); // For the number at crores place
    return words;
}

