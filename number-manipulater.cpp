#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class myInt
{
private:
    int userInt;
    
public:
    void menuValidation();
    void intValidation();
    int getInt() const;
    void setInt(int);
    void mult_A();
    void sum_B();
    void sqrt_C();
    void prime_D();
    void perfNum_E();
};

int main()
{
    myInt v;
    
    int posNum;
    bool flag = false;
    bool temp = false;
    
    //cout << "this is the integer test: " << v.getInt() << endl;
    char option;
    char choice;
    
    do
    {
        cout << "\nPlease choose from the following options below for"
        " manipulations.\n\n";
        cout << "\tA. Is it a multiple of 7, 11, or 13.\n";
        cout << "\tB. Is the sum of its digits odd or even.\n";
        cout << "\tC. What is the square root value.\n";
        cout << "\tD. Is it a prime number.\n";
        cout << "\tE. Is it a perfect number.\n";
        cout << "\tF. All of the above.\n";
        cout << "\tZ. Exit.\n\n";
        cout << "Enter option here: ";
        
        cin >> option;
        cout << endl;
        
        if (option == 'z' || option == 'Z')
        {
            return 0;
        }
        else
        {
            cout << "Enter a positive integer that you would like"
            " to manipulate: ";
            cin >> posNum;
            cout << endl;
        }
        
        
        while(posNum <= 0)
        {
            cout << "*ERROR* Enter a positive integer: ";
            cin >> posNum;
            cout << endl;
        }
        
        v.setInt(posNum);
        
        //checking for 'a' and 'A'
        //then will send to function m
        if (option == 'a' || option == 'A')
        {
            v.mult_A();
            
            do
            {
                cout << "Would you like to re-run the program? " << endl;
                cout << "Enter Y or N -> ";
                
                cin >> choice;
                cout << endl;
                if (choice == 'y' || choice == 'Y')
                {
                    flag = true;
                    temp = false;
                }
                else if (choice == 'n' || choice == 'N')
                {
                    return 0;
                }
                else
                {
                    cout << "Error *** Invalid choice - Must enter y|Y or n|N. " << endl;
                    temp = true;
                }
            } while (temp);
            
        }
        
        if (option == 'b' || option == 'B')
        {
            v.sum_B();
            
            do
            {
                cout << "Would you like to re-run the program? " << endl;
                cout << "Enter Y or N -> ";
                
                cin >> choice;
                cout << endl;
                if (choice == 'y' || choice == 'Y')
                {
                    flag = true;
                    temp = false;
                }
                else if (choice == 'n' || choice == 'N')
                {
                    return 0;
                }
                else
                {
                    cout << "Error *** Invalid choice - Must enter y|Y or n|N. " << endl;
                    temp = true;
                }
            } while (temp);
            
        }
        
        if (option == 'c' || option == 'C')
        {
            v.sqrt_C();
            
            do
            {
                cout << "Would you like to re-run the program? " << endl;
                cout << "Enter Y or N -> ";
                
                cin >> choice;
                cout << endl;
                if (choice == 'y' || choice == 'Y')
                {
                    flag = true;
                    temp = false;
                }
                else if (choice == 'n' || choice == 'N')
                {
                    return 0;
                }
                else
                {
                    cout << "Error *** Invalid choice - Must enter y|Y or n|N. " << endl;
                    temp = true;
                }
            } while (temp);
            
        }
        
        if (option == 'd' || option == 'D')
        {
            v.prime_D();
            
            do
            {
                cout << "Would you like to re-run the program? " << endl;
                cout << "Enter Y or N -> ";
                
                cin >> choice;
                cout << endl;
                if (choice == 'y' || choice == 'Y')
                {
                    flag = true;
                    temp = false;
                }
                else if (choice == 'n' || choice == 'N')
                {
                    return 0;
                }
                else
                {
                    cout << "Error *** Invalid choice - Must enter y|Y or n|N. " << endl;
                    temp = true;
                }
            } while (temp);
        }
        
        if (option == 'e' || option == 'E')
        {
            v.perfNum_E();
            
            do
            {
                cout << "Would you like to re-run the program? " << endl;
                cout << "Enter Y or N -> ";
                
                cin >> choice;
                cout << endl;
                if (choice == 'y' || choice == 'Y')
                {
                    flag = true;
                    temp = false;
                }
                else if (choice == 'n' || choice == 'N')
                {
                    return 0;
                }
                else
                {
                    cout << "Error *** Invalid choice - Must enter y|Y or n|N. " << endl;
                    temp = true;
                }
            } while (temp);
        }
        
        if (option == 'f' || option == 'F')
        {
            for (int i = 0; i < 1; i++)
            {
                v.mult_A();
                v.sum_B();
                v.sqrt_C();
                v.prime_D();
                v.perfNum_E();
                
                do
                {
                    cout << "Would you like to re-run the program? " << endl;
                    cout << "Enter Y or N -> ";
                    
                    cin >> choice;
                    cout << endl;
                    if (choice == 'y' || choice == 'Y')
                    {
                        flag = true;
                        temp = false;
                    }
                    else if (choice == 'n' || choice == 'N')
                    {
                        return 0;
                    }
                    else
                    {
                        cout << "Error *** Invalid choice - Must enter y|Y or n|N. " << endl;
                        temp = true;
                    }
                } while (temp);
            }
        }
        
        if (option == 'z' || option == 'Z')
        {
            cout << "You have chosen to leave the program. " << endl;
            return 0;
        }
        
    } while (flag);
    
    return 0;
}


//first function for option
void myInt::mult_A()
{
    cout << "In (A) function: " << userInt;
    cout << endl << endl;
    
    int i = 0;
    while (i == 0)
    {
        if (userInt % 7 == 0 && userInt % 11 == 0 && userInt % 13 == 0)
        {
            cout << userInt << " is a multiple of ALL 7, 11, and 13\n";
            break;
        }
        if (userInt % 7 == 0 && userInt % 11 == 0)
        {
            cout << userInt << " is a multiple of 7 and 11\n";
            break;
        }
        if (userInt % 11 == 0 && userInt % 13 == 0)
        {
            cout << userInt << " is a multiple of 11 and 13\n";
            break;
        }
        if (userInt % 7 == 0 && userInt % 13 == 0)
        {
            cout << userInt << " is a multiple of 7 and 13\n";
            break;
        }
        if (userInt % 7 == 0)
        {
            cout << userInt << " is a multiple of 7\n";
        }
        if (userInt % 11 == 0)
        {
            cout << userInt << " is a multiple of 11\n";
        }
        if (userInt % 13 == 0)
        {
            cout << userInt << " is a multiple of 13\n";
        }
        if (userInt % 7 != 0 && userInt % 11 != 0 && userInt % 13 != 0)
        {
            cout << userInt << " is NOT a multiple of 7, 11, or 13\n";
            break;
        }
        i++;
    }
}

//function for option b
/*
 formula up to 5 digits
 5 is 12345 % 10
 4 is 12345 / 10 % 10
 3 is 12345 / 100 % 10
 2 is 12345 / 1000 % 10
 1 is 12345 / 10000 % 10
 */
void myInt::sum_B()
{
    int a, b, c, d;
    int sumInt;
    
    a = userInt /1000 % 10;
    b = userInt /100 % 10;
    c = userInt /10 % 10;
    d = userInt % 10;
    sumInt = a + b + c + d;
    
    if (sumInt % 2 == 0)
    {
        cout << endl;
        cout << "the sum of digits in " << userInt << " = "
        << sumInt << " and is EVEN\n" << endl;
    }
    else
    {
        cout << endl;
        cout << "the sum of digits in " << userInt << " = "
        << sumInt << " and is ODD\n" << endl;
    }
}


void myInt::sqrt_C() //Only working with numbers that have a whole # sq. root
{
    double num = sqrt(userInt);
    cout << "Square root of " << userInt << " is " << num << endl;
    cout << endl;
}


void myInt::prime_D()
{
    int i;
    bool primeCheck = true;
    
    for (i = 2; i <= userInt / 2; i++)
    {
        if (userInt % i == 0)
        {
            primeCheck = false;
            break;
        }
    }
    
    if (primeCheck)
    {
        cout << userInt << " is a prime number.\n" << endl;
    }
    else
    {
        cout << userInt << " is not a prime number.\n" << endl;
    }
}

void myInt::perfNum_E()
{
    int i, factor;
    int sum = 0;
    
    for (i = 1; i < userInt; i++)
    {
        factor = userInt % i;
        
        if (factor == 0)
        {
            sum = sum + i;
        }
    }
    
    if (sum == userInt)
    {
        cout << userInt << " is a perfect number.\n" << endl;
    }
    else
    {
        cout << userInt << " is not a perfect number.\n" << endl;
    }
}

//getting user int
int myInt::getInt() const
{
    return userInt;
}
//setting user int
void myInt::setInt(int ui)
{
    userInt = ui;
}



