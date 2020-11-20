// Serial Number : 13/14
//
// Author : Cole Contreras and Christian Coulter
//
// Due Date : April 24, 2019
// Programming Assignment Number 6 (seis)//
// Spring 2019 - CS 3358 - 2 //
// Instructor: Husain Gholoom. //
//
// Brief Description: a random number generator creates a char array
// using the user input for the size of the array. Then only the 20 first
// elements of the array are displayed. Second function uses recursion to
// search for char 80 then displays the comparisons made during the sequential
// search. Third function uses selection sort to sort the original array given.
// The fourth function then uses another sort function, insertion sort also
// counting the number of comparisons. The last three functions all use quick
// sort to sort the original array but each vary on where the pivot table value
// is placed. All function print the CPU time before each step starts and after
// each completed step then calculating actual CPU time for the completion of
// each step.
//

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

//Function prototypes
void firstFn(char arr[], int sizeOf);
int secondFn(char arr2[], int left, int right, int elem, int count);
int thirdFn(char arr3[], int sizeOf, int swaps);
int fourthFn(char arr4[], int sizeOf, int comparisons);
int fifthFn(char arr5[], int left, int right, int recCalls);
int sixthFn(char arr6[], int left, int right, int recCalls2);
int seventhFn(char arr7[], int left, int right, int recCalls3);

///////////////////
// Main Function
/////////////////
int main()
{
    cout << "Searching / Sorting Benchmark\n\n\n";
    cout << "Using a random number generator, we are creating an array" <<
    "\nof n elements of type char then performing the following : \n\n";
    cout << "1. Displaying the first 20 numbers.\n\n";
    cout << "2. Using recursion, Searching for an element in the array " <<
    "\nusing sequential search and at the end displaying number of comparisons"
    << "\nit makes. \n\n";
    cout << "3. Sort the original array using Selection Sort and at the " <<
    "\nend display the number of swaps it makes. \n\n";
    cout << "4.Sorting the array using insertion Sort and at the end " <<
    "\ndisplaying the number of comparisons it makes. \n\n";
    cout << "5. Sorting the array using Quick Sort and at the end " <<
    "\ndisplaying the number of recursion calls it makes. Using the next to " <<
    "\nthe middle value as a pivot value. \n\n";
    cout << "6.Sorting the same array using Quick Sort and at the end " <<
    "\ndisplaying the number of recursion calls it makes. Using the first " <<
    "\nvalue as a pivot value. \n\n";
    cout << "7.Sorting the same array using Quick Sort and at the end " <<
    "\ndisplaying the number of recursion calls it makes. Using the last "<<
    "\nvalue as a pivot value. \n\n";
    cout << "8. For each of the preceding steps ( 2 thru 7 ), " <<
    "\ncalculating and printing the CPU time before each step starts " <<
    "\nand after each completed step then calculating actual CPU time " <<
    "\nfor the completion of each step. \n\n";


    srand(time(0));
    clock_t start, stop;
    int sizeOf;
    int swaps = 0;
    int comparisons = 0;
    int recCalls = 0;
    int recCalls2 = 0;
    int recCalls3 = 0;
    double duration;


    cout << "Enter the size of the array: ";
    cin >> sizeOf;

    if (sizeOf <= 0)
    {
        cout << "\n\n***  Error - Invalid input - Size must be > 0  ***";
        //footer
        cout << "\nBenchmark Algorithm implemented by: Christian Coulter," <<
        "Cole Contreras";
        cout << "\n 4 - 24 - 2019\n";
        return 0;
    }


    // Generate char array with random characters
    // And create empty arrays to copy the original one to
    char *arr;
    arr = new char [sizeOf];
    char *arr2;
    arr2 = new char [sizeOf];
    char *arr3;
    arr3 = new char [sizeOf];
    char *arr4;
    arr4 = new char [sizeOf];
    char *arr5;
    arr5 = new char [sizeOf];
    char *arr6;
    arr6 = new char [sizeOf];
    char *arr7;
    arr7 = new char [sizeOf];

    cout << "Array elements are: ";
    for(int i = 0; i < sizeOf; i++)
    {
        arr[i] = char(33 + rand() % 96);
    }

    // Display the generated array
    firstFn(arr, sizeOf);
    cout << endl << endl;

    //**********************************
    // Call for second function
    // Count's only working if P is in the array
    for (int i=0; i < sizeOf; i++)
        arr2[i] = arr[i];
    cout << "Sequential Search"<< endl;
    cout << "Searching for 80" << endl;

    start = clock();
    int count = secondFn(arr, 0, sizeOf - 1, 80, 0);
    int found = secondFn(arr, 0, sizeOf - 1, 80, 0);
    if(found != -1)
        cout << "\n80 was found" << endl;
    else
        cout << "\n80 was not found" << endl;
    cout << "Start Time: " << double(start)/(CLOCKS_PER_SEC) <<" sec"<< endl;

    stop = clock();
    cout << "End Time: " << double(stop)/(CLOCKS_PER_SEC) <<" sec"<< endl;
    duration = double(stop - start);
    cout << "Actual CPU Clock Time: " << duration << endl;
    cout << "Total number of Comparisons: " << count;
    cout << "\nArray Elements: ";
    if(sizeOf > 20)
    {
        for(int i = 0; i<20; i++)
            cout << arr2[i] <<" ";
    }
    else
    {
        for(int i = 0; i<sizeOf; i++)
            cout << arr2[i] <<" ";
    }

    //*******************************************
    // Call for third function
    // Done
    for (int i=0; i < sizeOf; i++)
        arr3[i] = arr[i];
    cout << "\n\nSelection Sort" << endl;
    start = clock();
    cout << "Start Time: " << double(start)/(CLOCKS_PER_SEC) <<" sec"<< endl;
    swaps = thirdFn(arr3, sizeOf, swaps);
    stop = clock();
    cout << "End Time: " << double(stop)/(CLOCKS_PER_SEC) <<" sec"<< endl;
    duration = double(stop - start);
    cout << "Actual CPU Clock Time: " << duration << endl;
    cout << "Total Number of Swaps: " << swaps << endl;
    cout << "Sorted Elements: ";
    if(sizeOf > 20)
    {
        for(int i = 0; i<20; i++)
            cout << arr3[i] <<" ";
    }
    else
    {
        for(int i = 0; i<sizeOf; i++)
            cout << arr3[i] <<" ";
    }
// **********************************************
    // Call for fourth function
    // Needs number of comparisons
    for (int i=0; i < sizeOf; i++)
        arr4[i] = arr[i];
    cout << "\n\nInsertion Sort" << endl;
    start = clock();
    cout << "Start Time: " << double(start)/(CLOCKS_PER_SEC) <<" sec"<< endl;
    comparisons = fourthFn(arr4, sizeOf, comparisons);
    stop = clock();
    cout << "End Time: " << double(stop)/(CLOCKS_PER_SEC) <<" sec"<< endl;
    duration = double(stop - start);
    cout << "Actual CPU Clock Time: " << duration << endl;
    cout << "Total Number of Comparisons: " << comparisons << endl;
    cout << "Sorted Elements: ";
    if(sizeOf > 20)
    {
        for(int i = 0; i<20; i++)
            cout << arr4[i] <<" ";
    }
    else
    {
        for(int i = 0; i<sizeOf; i++)
            cout << arr4[i] <<" ";
    }

    // **********************************************
    // Call for fifth function
    // Need number of recursion calls
    for (int i=0; i < sizeOf; i++)
        arr5[i] = arr[i];
    cout << "\n\nQuick Sort - next to middle element as a pivot: " << endl;
    start = clock();

    cout << "Start Time: " << double(start)/(CLOCKS_PER_SEC) <<" sec"<< endl;
    recCalls = fifthFn(arr5, 0, sizeOf-1, recCalls);
    stop = clock();
    cout << "End Time: " << double(stop)/(CLOCKS_PER_SEC) <<" sec"<< endl;
    duration = double(stop - start);
    cout << "Actual CPU Clock Time: " << duration << endl;
    cout << "Total Number of Recursive Calls: " << recCalls << endl;
    cout << "Sorted Elements: ";
    if(sizeOf > 20)
    {
        for(int i = 0; i<20; i++)
            cout << arr5[i] <<" ";
    }
    else
    {
        for(int i = 0; i<sizeOf; i++)
            cout << arr5[i] <<" ";
    }

// ***************************************************************************
    // Call for sixth function
    // Need number of recursion calls
    for (int i=0; i < sizeOf; i++)
        arr6[i] = arr[i];
    cout << "\n\nQuick Sort - first element as pivot: " << endl;
    start = clock();
    cout << "Start Time: " << double(start)/(CLOCKS_PER_SEC) <<" sec"<< endl;
    recCalls2 = sixthFn(arr6, 0, sizeOf-1, recCalls2);
    stop = clock();
    cout << "End Time: " << double(stop)/(CLOCKS_PER_SEC) <<" sec"<< endl;
    duration = double(stop - start);
    cout << "Actual CPU Clock Time: " << duration << endl;
    cout << "Total Number of Recursive Calls: " << recCalls2 << endl;
    cout << "Sorted Elements: ";
    if(sizeOf > 20)
    {
        for(int i = 0; i<20; i++)
            cout << arr6[i] <<" ";
    }
    else
    {
        for(int i = 0; i<sizeOf; i++)
            cout << arr6[i] <<" ";
    }

    // **************************************
    // Call for seventh function
    // Need number of recursion calls
    for (int i=0; i < sizeOf; i++)
        arr7[i] = arr[i];
    cout << "\n\nQuick Sort - last element as pivot: " << endl;
    start = clock();
    cout << "Start Time: " << double(start)/(CLOCKS_PER_SEC)<<" sec" << endl;
    recCalls3 = seventhFn(arr7, 0, sizeOf-1, recCalls3);
    stop = clock();
    cout << "End Time: " << double(stop)/(CLOCKS_PER_SEC)<<" sec" << endl;
    duration = double(stop - start);
    cout << "Actual CPU Clock Time: " << duration << endl;
    cout << "Total Number of Recursive Calls: " << recCalls3 << endl;
    cout << "Sorted Elements: ";
    if(sizeOf > 20)
    {
        for(int i = 0; i<20; i++)
            cout << arr7[i] <<" ";
    }
    else
    {
        for(int i = 0; i<sizeOf; i++)
            cout << arr7[i] <<" ";
    }

    //footer
    cout << "/nBenchmark Algorithm implemented by: Christian Coulter," <<
    "Cole Contreras";
    cout << "/n 4 - 24 - 2019";
    cout << endl << endl;
    return 0;
}

//*****************************
// firstFn, display elements of the array then displays
// the first 20 elements if the size is bigger than 20
//
// char arr[]: takes the array that has been populated
// int sizeOf: obtains and use the size of the given array
//****************************
void firstFn(char arr[], int sizeOf)
{
    if(sizeOf > 20)
    {
        for(int i = 0; i<20; i++)
            cout << arr[i] <<" ";
    }
    else
    {
        for(int i = 0; i<sizeOf; i++)
            cout << arr[i] <<" ";
    }
}

//******************************************************************
// secondFn, uses recursion to search for a specific char
// which is 80. The search used is sequential. seconFn also
// displays the number of comparisons the search makes before
// 80 is found.
//
// char arr[]: takes the array that has been populated
// int left: used to traverse array and compare
// int right: used to traverse array and compare
// int elem: value that is being searched for
// int count: recording the number of comparisons made during search
// return: recursively to call its self again until base case is met
//******************************************************************
int secondFn(char arr[], int left, int right, int elem, int count)
{
    if (right < 1)
    {
        return -1;
    }
    if (arr[left] == elem)
    {
        count++;
        return left;
    }
    if (arr[right] == elem)
    {
        count++;
        return right;
    }
    count++;
    return secondFn(arr, left + 1, right - 1, elem, count);
}

//*****************************
// thirdFn, sorts the original array by using
// selection sort
//
// char arr[]: takes the array that has been populated
// int sizeOf: obtains and use the size of the given array
// int swaps: keeps track of how many swaps take place during
// the selection sort
// return: the number of swaps it makes
//******************************
int thirdFn(char arr3[], int sizeOf, int swaps)
{
    for (int i = 0; i < sizeOf - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < sizeOf; j++)
        {
            if (arr3[j] < arr3[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            int swap = arr3[i];
            arr3[i] = arr3[min];
            arr3[min] = swap;
            swaps++;
        }
    }
    return swaps;
}

//*************************************************************
// fourthFn, sorts the original array given using insertion sort.
// Also keeps track of the number of comparisons made during the
// insertion sort.
//
// char arr[]: takes the array that has been populated
// int sizeOf: obtains and use the size of the given array
// int comparisons: keeps track of the number of comparisons made
// during the insertion sort
//**************************************************************
int fourthFn(char arr4[], int sizeOf, int comparisons)
{
    if (sizeOf <= 1)
    {
        return 1;
    }

    fourthFn(arr4, sizeOf - 1, comparisons);
    comparisons++;

    int last = arr4[sizeOf - 1];
    int j = sizeOf - 2;

    while (j >= 0 && arr4[j] > last)
    {
        comparisons++;
        arr4[j + 1] = arr4[j];
        j--;
    }

    arr4[j + 1] = last;
    return comparisons;
}

//*****************************
// fifthFn, sorts the original array using quick sort recursively.
// Also displays the number of recursive calls made.
//
// char arr[]: takes the array that has been populated
// int sizeOf: obtains and use the size of the given array
// int left: traverse the array and compare
// int right: traverse the array and compare
// int recCalls: used to record the number of recursive calls
// are made on the function during the search
// return: int value of how many times the function was called
// recursively
//************************************
int fifthFn(char arr5[], int left, int right, int recCalls)
{
    int i = left, j = right;
    int temp;
    int pivot = arr5[(left + right) / 2];


    while (i <= j)
    {
        while (arr5[i] < (pivot))
            i++;
        while (arr5[j] > (pivot))
            j--;
        if (i <= j)
        {
            temp = arr5[i];
            arr5[i] = arr5[j];
            arr5[j] = temp;
            i++;
            j--;
        }
        recCalls++;
    };

    if (left < j)
        fifthFn(arr5, left, j, recCalls);

    if (i < right)
        fifthFn(arr5, i, right, recCalls);

    return recCalls;
}

//*****************************
// sixthFn, sorts the original array using quick sort recursively.
// First value in the array is used as the pivot value for the quick sort.
// Also displays the number of recursive calls made.
//
// char arr[]: takes the array that has been populated
// int sizeOf: obtains and use the size of the given array
// int recCalls: used to record the number of recursive calls
// are made on the function during the search
// return: int value of how many times the function was called
// recursively
//************************************
int sixthFn(char arr6[], int left, int right, int recCalls2)
{
    int i = left, j = right;
    int temp;
    int pivot = arr6[left];


    while (i <= j)
    {
        while (arr6[i] < pivot)
            i++;
        while (arr6[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = arr6[i];
            arr6[i] = arr6[j];
            arr6[j] = temp;
            i++;
            j--;
        }
        recCalls2++;
    };

    if (left < j)
        sixthFn(arr6, left, j, recCalls2);

    if (i < right)
        sixthFn(arr6, i, right, recCalls2);

    return recCalls2;
}

//*****************************
// sixthFn, sorts the original array using quick sort recursively.
// Last value in the array is used as the pivot value for the quick sort.
// Also displays the number of recursive calls made.
//
// char arr[]: takes the array that has been populated
// int sizeOf: obtains and use the size of the given array
// int recCalls: used to record the number of recursive calls
// are made on the function during the search
// return: int value of how many times the function was called
// recursively
//************************************
int seventhFn(char arr7[], int left, int right, int recCalls3)
{
    int i = left, j = right;
    int temp;
    int pivot = arr7[right];

    while (i <= j)
    {
        while (arr7[i] < pivot)
            i++;
        while (arr7[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = arr7[i];

            arr7[i] = arr7[j];
            arr7[j] = temp;
            i++;
            j--;
        }
        recCalls3++;
    };

    if (left < j)
        seventhFn(arr7, left, j, recCalls3);

    if (i < right)
        seventhFn(arr7, i, right, recCalls3);
    return recCalls3;
}
