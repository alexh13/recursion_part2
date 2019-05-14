/*
Alex Hughes
CS 110B
5/11/19
Professor Dave
Assignment 15.2


Assignment calls for usage of the MyString from earlier in the course. This program reads any number of strings entered
by the user and determines if any are a palindrome. The user ends each string by hitting the "enter"/"return" button on
their keyboard. When the user is finished entering strings, they type "quit" to stop.
 */




#include <iostream>
#include <cctype>

using namespace std;


bool isAPalindrome(char[], int, int);


//Main
int main()
{
    char str[256];
    int length;


    cout << "Enter a String: ";
    cin.getline(str, 256);


    // loop to quit
    while(strcmp(str, "quit") != 0)
    {
        length = strlen(str);
        if(isAPalindrome(str, 0, length-1))
            cout << str << " is a palindrome.";
        else
            cout << str << " is not a palindrome.";
        cout << "\nEnter a String: ";
        cin.getline(str, 256);
    }
    cout << endl;
    return 0;
}


bool isAPalindrome(char str[], int leftBound, int highBound)
{
    char ch1,ch2;

    if(leftBound > highBound)
        return true;

    while(leftBound <= highBound)
    {
        if(ispunct(str[leftBound]) || isspace(str[leftBound]))
            leftBound ++;
        else
            break;
    }


    while(highBound >= leftBound)
    {
        if(ispunct(str[highBound]) || isspace(str[highBound]))
            highBound --;
        else
            break;
    }


    ch1 = str[leftBound];
    ch1 = toupper(ch1);

    ch2 = str[highBound];
    ch2 = toupper(ch2);


    if(ch1 != ch2)
        return false;

    leftBound++;
    highBound--;
    return isAPalindrome(str, leftBound, highBound);
}

/*
OUTPUT:

/Users/alexhughes/CLionProjects/15_2/cmake-build-debug/15_2

Enter a String: Able was I, ere i saw Elba
Able was I, ere i saw Elba is a palindrome.
Enter a String: peanut butter
peanut butter is not a palindrome.
Enter a String: quit

 */