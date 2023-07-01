#include "header.h"

/*******************************************************************************
 * FUNCTION drawPattern
 * _____________________________________________________________________________
 * This function takes in an int and outputs a star pattern.
 *  - returns nothing.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      int n: User input number.
 *
 * POST-CONDITIONS
 *      prints out pattern of * user input many times.
 ******************************************************************************/

void drawPattern(int n)                 // IN - user input number
{
    // PROCESSING - base condition
    if(n <= 0) return;
    // OUTPUT - printing '*' n times
    for(int i = 0; i < n; i++) cout << "*";
    cout << endl;
    // PROCESSING - recursive call
    drawPattern(n - 1);
    // OUTPUT - printing '*' n times
    for(int i = 0; i < n; i++) cout << "*";
    cout << endl;
}

/*******************************************************************************
 * FUNCTION generate_substrings
 * _____________________________________________________________________________
 * This function takes in a string and generates all possible substrings.
 *  - returns a vector of substrings.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      string s        : User input string.
 *
 * POST-CONDITIONS
 *      vector<string>  : Vector of substrings.
 ******************************************************************************/

vector<string> generate_substrings(string s)    // IN - user input string
{
    vector<string> v;           // CALC - vector storing substrings

    // PROCESSING - empty string case
    if(s.empty()) return {};
    // PROCESSING - reserve space in vector for substrings
    v.reserve(s.size() * (s.size() + 1) / 2);
    // PROCESSING - base case
    for(__SIZE_TYPE__ i = 0; i < s.size(); i++)
    {
        v.push_back(s.substr(0, i + 1));
    }
    //PROCESSING - recurrsive call
    for (string& t : generate_substrings(s.substr(1)))
    {
        v.push_back(t);
    }
    return v;
}

/*******************************************************************************
 * FUNCTION ispalindrome
 * _____________________________________________________________________________
 * This function takes in a character array and its length and determins if the
 * string is a palindrome.
 *  - returns bool.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      const char a[]  : Character array user input word.
 *      int n           : Length of array.
 *
 * POST-CONDITIONS
 *      bool            : Returns true if palindrome.
 ******************************************************************************/

bool ispalindrome(const char a[],   // IN - array storing word
                  int n)            // IN - length of array
{
    // PROCESSING - empty array case
    if (n == 0) return true;
    // PROCESSING - cmparing first and last characters
    if ((a[0] == a[n - 1]))
    {
        // PROCESSING - one letter case
        if(n == 1) return true;
        // PROCESSING - new character array that excludes 1st and last char
        char b[n - 2];
        // PROCESSING - base case
        for(int i = 0; i < (n - 2); i++)
        {
            b[i] = a[i + 1];
        }
        // PROCESSING - recurssive call
        ispalindrome(b,n - 2);
    }
    else return false;
}

/*******************************************************************************
 * FUNCTION findsum
 * _____________________________________________________________________________
 * This function takes in an int array and its length and finds the sum of the
 * elements.
 *  - returns the int sum.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      const int a[]   : Array of rand numbers.
 *      int n           : Length of array.
 *
 * POST-CONDITIONS
 *      int             : Returns the int sum.
 ******************************************************************************/

int findsum(const int a[],          // IN - array of rand numbers
            int n)                  // IN - length of array
{
    // PROCESSING - base case
    if (n == 0)
    {
        //cout << a[n] << " -> " << n << ", ";
        return a[n];
    }
    // PROCESSING - recurssive call
    else
    {
        //cout << a[n] << " -> " << n << ", ";
        return a[n] + findsum(a, n - 1);
    }
}

/*******************************************************************************
 * FUNCTION findmin
 * _____________________________________________________________________________
 * This function takes in an int array and its length and finds the minimum
 * element.
 *  - returns the int min value.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      const int a[]   : Array of rand numbers.
 *      int n           : Length of array.
 *
 * POST-CONDITIONS
 *      int             : Returns the int min value.
 ******************************************************************************/

int findmin(const int a[],          // IN - array of rand numbers
            int n)                  // IN - length of array
{
    int minval;                 // CALC - running min
    // PROCESSING - base case
    if(n == 1) return a[0];
    // PROCESSING - recurrsive call
    else
    {
        minval = findmin(a, n - 1);
        if(minval > a[n - 1]) return minval;
        else return a[n - 1];
    }
}

/*******************************************************************************
 * FUNCTION sum
 * _____________________________________________________________________________
 * This function takes in an int and returns the sum of all numbers leading up
 * to the passed value.
 *  - returns the int sum.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      int n: User input number.
 *
 * POST-CONDITIONS
 *      int  : Returns the int sum.
 ******************************************************************************/

int sum(int n)              // IN - user input number
{
    // PROCESSING - base case
    if(n < 1) return 0;
    // PROCESSING - recurrsive call
    else return n + sum(n - 1);
}

/*******************************************************************************
 * FUNCTION menuSelection
 * _____________________________________________________________________________
 * This function takes in an int value that corresponds to the above functions.
 *  - returns nothing.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously define values:
 *      int choice: User input menu selection.
 *
 * POST-CONDITIONS
 *      none.
 ******************************************************************************/

void menuSelection(int choice)  // IN - user input menu selection
{
    int input;      // IN - user input
    int output;     // IN - output values

    if(choice == 1)
    {
        cout << "Enter a positive integer: \n";
        cin >> input;
        output = sum(input);
        cout << endl << "The sum is " << output << endl;
    }
    else if(choice == 2)
    {
        cout << "Finding the minimum element of an array "
                "containing random numbers from -1000 to 1000.\n";
        cout << "Enter the size of the array: \n";
        cin >> input;
        int* a = new int[input];
        for(int i = 0; i < input; i++)
        {
            a[i] = rand() % 2001 - 1000;
            //cout << a[i] << ", ";
        }
        output = findmin(a, input);
        cout << endl << "The minimum element of the array is "
             << output << endl;
        delete[] a;
    }
    else if(choice == 3)
    {
        cout << "Finding the sum of the elements of an array "
                "containing random numbers from -1000 to 1000.\n";
        cout << "Enter the size of the array: \n";
        cin >> input;
        int* a = new int[input];
        for(int i = 0; i < input; i++)
        {
            a[i] = rand() % 2000 - 1000;
            cout << a[i] << ", ";
        }
        //cout << " < from main" << endl;
        output = findsum(a, input - 1);
        cout << endl << "The sum of the elements of the array is "
             << output << endl;
        delete[] a;
    }
    else if(choice == 4)
    {
        cout << "Enter a phrase: \n";
        string phrase;
        int len;
        cin >> phrase;
        len = phrase.length();
        char a[len + 1];
        strcpy(a, phrase.c_str());
        bool ans = ispalindrome(a, len);
        if(ans == true) cout << "The phrase is a palindrome.\n";
        else cout << "The phrase is not a palindrome\n";
    }
    else if(choice == 5)
    {
        vector<string> substrings;
        cout << "Enter a string: \n";
        string phrase, z;
        cin >> phrase;
        for (string &t : generate_substrings(phrase))
        {
            substrings.push_back(t);
        }
        z = '\0';
        substrings.push_back(z);
        cout << substrings.size() << " substrings\n";
        for(unsigned i = 0; i < substrings.size(); i++)
        {
            if(i == substrings.size()-1) cout << substrings[i] << endl;
            else cout << substrings[i] << ", ";
        }
    }
    else if(choice == 6)
    {
        cout << "Enter a positive number: \n";
        cin >> input;
        drawPattern(input);
    }
}
