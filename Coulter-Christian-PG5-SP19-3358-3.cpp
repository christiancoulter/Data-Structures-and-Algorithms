/*
 Roster Number: 13
 Group Number: 8
 Author: Cole Contreras and Christain Coulter
 Due Date: April 8th, 2019
 Assignment Number: 5 (cinco)

 Spring - 2019 - CS 3358 - 2
 Instructor:  Husain Gholoom

 Description: Recursion Program. Accepts array of size 5 or above from the
 keyboard. Using this size, the array is then populated with random integer
 values between 10 and 375. The array is displayed, then displayed in reverse.
 Next creating a function using recursion that displays squares of integers
 in ascending order, starting from 1 to the first number in the array. Then
 creating another function that uses recursion to raise a number to a power.
 This function takes two arguments, the number to be raised to the power is
 the last number in the array and the power is 2. Lastly, creating a function
 that uses recursion in order to determine whether or not every number in the
 array is a prime number.

*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//**********************************************************
// Recursion class holds functions that generate an array,
// display it, reverse the array, find square values 1-arr[0],
// find the power of 2 for arr[arrSize-1], and determines if
// the numbers in the array are prime or not
//
// Public: display, generateArray, displayRev, squareVal,
// power, and prime
// All Parameter description:
// Parameter(1), int arr[]: the array that is being used
// Parameter(2), int aSize: the size of the array from keyboard
// Parameter(3), int start: used for recursion and base case
// Parameter(4), int lastNum: last number in the array
// Parameter(5), int power: what power to raise to
//
// Returns description of what function returns (if anything)
// int power: returns a integer of the last element in the array
// raised to the power of 2.
//**********************************************************
class Recursion
{
    private:

    public:
        void display(int arr[], int aSize);

        void generateArray(int arr[],int aSize);

        void displayRev(int arr[], int start, int aSize); //recursion

        void squareVal(int arr[], int start,  int aSize); //recursion

        int power(int lastNum, int power); //recursion

        void prime(int arr[], int start, int aSize); //recursion

};


//**********************************************************
// generateArray, populates an array with integers 10-375
//
// Parameter(1), int arr[]: the array that is being used
// Parameter(2), int n: the size of the array from keyboard
//**********************************************************
void Recursion::generateArray(int arr[], int n)
{
    srand(time(NULL));

    int randomNum = 0;

    for(int i = 0; i < n; i++)
    {
        randomNum = 10 + rand() % 375; //any random integer 10-375
        arr[i] = randomNum;
    }

}


//**********************************************************
// display, cout's all elements inside arr[]
//
// Parameter(1), int arr[]: the array that is being used
// Parameter(2), int n: the size of the array from keyboard
//**********************************************************
void Recursion::display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}


//**********************************************************
// displayRev, displays all elements inside arr[] in reverse
//
// Parameter(1), int arr[]: the array that is being used
// Parameter(2), int start: used for recursion and base case
// Parameter(3), int n: the size of the array from keyboard
//**********************************************************
void Recursion::displayRev(int arr[], int start,  int n)
{
    //n needs to be 1 less than arrSize
    //from user because starting at 0

    if(start >= n) {
        return;
    }

    else {
        int temp = arr[start]; //store first element in array
        arr [start] = arr[n]; //make first element equal the last element
        arr[n] = temp; //now n and temp equal first element
        displayRev(arr, start + 1, n - 1);
    }

}


//**********************************************************
// squareVal, displays a table of values and those values being
// squared starting at 1-arr[0]
//
// Parameter(1), int arr[]: the array that is being used
// Parameter(2), int start: used for recursion and base case
// Parameter(3), int n: the size of the array from keyboard
//**********************************************************
void Recursion::squareVal(int arr[], int start, int n)
{
    //in main call displayRev so array can be flipped back to original
    //and squareVal can display 1-arr[0] of original and not flipped

    if(start == arr[0] + 1)
        return;
    else {
        cout << start << "\t" << start*start << endl;
        squareVal(arr, start + 1, n);
    }
}


//**********************************************************
// power, takes two argumnets, the last element in the array,
// and the power of 2
//
// Parameter(1), int x: last number in the array
// Parameter(2), int y: the power of 2
//
// Returns: arr[arrSize-1]^2
//**********************************************************
int Recursion::power(int x, int y)
{
    if (y == 0)
        return (1);
    else if (y == 1)
        return (x);
    else
        return (x * power(x, y - 1));
}


//**********************************************************
// prime, traverses the array and checks if they are prime
// or not, if they are the user will be told which are and
// which are not prime
//
// Parameter(1), int arr[]: the array that is being used
// Parameter(2), int start: used for recursion and base case
// Parameter(3), int n: the size of the array from keyboard
//**********************************************************
void Recursion::prime(int arr[], int start, int n)
{
    bool flag = false;

    if (start == n + 1)
        return;
    else
    {
        for(int i = 2; i < arr[start]; i++)
        {
            if (arr[start] % i == 0)
            {
                flag = false;
                break;
            }
            else
                flag = true;
        }
    }

    if(flag)
        cout << "The number " << arr[start] << " is Prime\n";
    if(!flag)
        cout << "The number " << arr[start] << " is Not Prime\n";

    prime(arr, start + 1, n);
}


//****************
//main function
//****************
int main()
{
    Recursion f1;

    int arrSize = 0;
    int lastNum = 0;
    int power = 2;

    //header
    cout << "***\tWelcome to my Recursion APP\t***\n\n";

    cout << "Enter the array size. (Must be >= 5): ";
    cin >> arrSize;
    cout << endl;

    int arr[arrSize];

    if(arrSize < 5)
    {
        cout << "Invalid arrays size. Size must be >= 5." << endl;
        return 0;
    }
    cout << endl;


    ///////////////////////
    //FUNCTION CALLS
    ///////////////////////
    //
    //generating and displaying original array
    //
    f1.generateArray(arr, arrSize); //generating a array 10-375 with arrSize
    cout << "The generated array is: ";
    f1.display(arr, arrSize); //for loop to display array elements

    //
    //recursion function 1, displaying array in reverse
    //
    f1.displayRev(arr, 0, arrSize-1); //start at 0, end at arrSize-1 from user
    cout << "\nReversed array is: ";
    f1.display(arr, arrSize); //for loop to display array elements in reverse

    //
    //recursion function 2, displaying square values 1-arr[0] of original array
    //
    f1.displayRev(arr, 0, arrSize-1); //flip it back to original
    cout << "\nTable of squared values 1 - " << arr[0] << endl;
    cout << "N\tN Squared" << endl;
    f1.squareVal(arr, 1, arrSize);

    //
    //recursion function 3, raising the last number in array to a power
    //
    lastNum = arr[arrSize - 1]; //equal to the last number in the array
    cout << "\nPower Function: " << endl;
    cout << lastNum << " raised to the 2nd power is " <<
    f1.power(lastNum, power) << endl;

    //
    //recursion function 4, determining whether or not every number in the
    //array is a prime number
    //
    cout << "\nIs It Prime: " << endl;
    f1.prime(arr, 0, arrSize-1);


    //footer
    cout << "\nCole Contreras/Christian Coulter - Tweak Programming Director\n"
    "April 2019\n";
    return 0;
}
