#include "header.h"

int main()
{
    int choice;     // IN - user input menu selection
    cout << "Select a function to test(1-6): \n";
    cin >> choice;
    // PROCESSING - run program based on input
    menuSelection(choice);
    return 0;
}
