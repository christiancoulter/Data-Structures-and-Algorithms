/*
    Roster Number:
    Author: Cole Contreras and Christian Coulter
    Due Date: 2/06/2019
    Assignment Number: Uno (1)
    Spring  -   2019    -   CS 3358, Section 2
    Instructor: Husain Gholoom
*/

#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h> //time

using namespace std;

int main()
{
    cout << "Welcome to my Game Program" << endl;
    cout << "I am thinking of a 3-digit number. Try to guess what it is. Here are some clues..." << endl;
    cout << endl;
    cout << "When I say:\t it means" << endl;
    cout << endl;
    cout << "\tB \t NO digit is correct" << endl;
    cout << "\tP \t One digit is correct BUT in the wrong position" << endl;
    cout << "\tF \t One digit is correct AND in the wrong position" << endl;

    int RandomNumberGen();
    cout << RandomNumberGen;
    return 0;
}

int RandomNumberGen()
{
    int number, num1, num2, num3, num4;
    srand(time(NULL)); //take this out when testing in each case
    do
    {
    number = rand() % 1000;
    } while(number < 99);

     num1 = number % 10;
     num2 = number / 10;
     num3 = num2 % 10;
     num4 = number / 100;

    cout << num1 << num3 << num4 << endl;
    int secretNumber[] {num1, num3, num4};
    return num1, num3, num4;

}


