#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <vector>

using namespace std;

/*******************************************************************************
 * drawPattern
 * This function takes in an int and outputs a star pattern.
 *  - returns nothing.
 ******************************************************************************/
void drawPattern(int n);            // IN - int value

/*******************************************************************************
 * generate_substrings
 * This function takes in a string and generates all possible substrings.
 *  - returns a vector of substrings.
 ******************************************************************************/
vector<string> generate_substrings(string s);   // IN - string phrase

/*******************************************************************************
 * ispalindrome
 * This function takes in a character array and its length and determins if the
 * string is a palindrome.
 *  - returns bool.
 ******************************************************************************/
bool ispalindrome(const char a[],   // IN - array storing word
                  int n);           // IN - length of array

/*******************************************************************************
 * findsum
 * This function takes in an int array and its length and finds the sum of the
 * elements.
 *  - returns the int sum.
 ******************************************************************************/
int findsum(const int a[],          // IN - array of rand numbers
            int n);                 // IN - length of array

/*******************************************************************************
 * findmin
 * This function takes in an int array and its length and finds the minimum
 * element.
 *  - returns the int min value.
 ******************************************************************************/
int findmin(const int a[],          // IN - array of rand numbers
            int n);                 // IN - length of array

/*******************************************************************************
 * sum
 * This function takes in an int and returns the sum of all numbers leading up
 * to the passed value.
 *  - returns the int sum.
 ******************************************************************************/
int sum(int n);                     // IN - int number

/*******************************************************************************
 * menuSelection
 * This function takes in an int value that corresponds to the above functions.
 *  - returns nothing.
 ******************************************************************************/
void menuSelection(int choice);     // IN - user input menu selection

#endif // HEADER_H
