/*
 Authors: Cole Contreras and Christian Coulter
 
 Serial Number: Cole Contreras (#13), Christian Coulter (#14)
 
 Group Number: #8
 
 Due Date: 2/20/2019
 Assignment Number: Dos (2)
 Spring  -   2019    -   CS 3358, Section 3
 Instructor: Husain Gholoom
 
 Description: A C++ program using Encrypting and Decrypting Cipher-text
 to encrypt a message by taking each letter in the message (Letters: A-Z),
 (Numbers: 0-9) and replacing it with a "shifted" placement different from
 the original. The concept is as follows, if you shift the letter A by one
 space, you get the letter B. If you shift the letter A by two spaces, you
 get the letter C. The number of spaces you shift is the "key" in the Cipher
 if the key is 3 then all placement of characters will be shifted 3 spaces.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//function prototypes
void Encryption();
void Decryption();
void Validation();

//////////////////////
//  Main Function
//////////////////////
int main()
{
    cout << "Welcome to Cryptography \n\n";
    Validation();
    
    return 0;
}

///////////////////////////////////////////
//  Function Name: Validation
//  Parameters: none
//  Purpose: depending on user answer it
//  sends to the correct function to run
//  to run through either encrypt, decrypt,
//  or exit. If none of these choices are
//  made then an error returns.
///////////////////////////////////////////
void Validation()
{
    string choice;
    const string encrypt = "encrypt";
    const string decrypt = "decrypt";
    const string exit = "exit";
    bool flag;
    
    //do while loop to send direction to which function
    do
    {
        cout << "What do you wish to do with your message? "
        "(encrypt, decrypt, exit) \n";
        cout << "Enter choice here: ";
        cin >> choice;
        
        if (choice == encrypt)
        {
            Encryption();
            break;
        }
        
        else if (choice == decrypt)
        {
            Decryption();
            break;
        }
        
        else if (choice == exit)
        {
            cout << "\nCole Contreras and Christian Coulter Security Systems"
            "\n2-25-2019 \n\n";
            flag = false;
        }
        
        else
        {
            cout << "(ERROR: INVALID CHOICE) \n\n";
            flag = true;
        }
        
        //to exit the loop for now
        //flag = false;
        
    } while (flag);
}

/////////////////////////////////////////
//  Function Name: Encryption
//  Parameters: none
//  Return: the encrypted string
//  Purpose: to encrypt a one word message
//  with no spaces such as "hello" and to
//  then ask for a key (1-35) and change
//  (h, e, l, l, o) to whatever key value
//  was given and to change to uppercase
/////////////////////////////////////////
void Encryption()
{
    //for original message and key (1-35)
    string message;
    int key;

    cout << "Enter your message: ";
    cin >> message;
    
    //Capitalizes each letter in message.
    for(int i = 0; i < message.size(); i++)
    {
        message[i] = toupper(message[i]);
    }
    //cout << message << endl;
    
    cout << "Enter the key number (1-35) \n";
    cin >> key;
    cin.ignore();
    
    while(key < 1 || key > 35)
    {
        cout << "Invalid Key Number. \n\n";
        Validation();
    }
    
    //Encryption process
    char array[36] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
        'O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4',
        '5','6','7','8','9'};
    
    vector<char> orig(array, array + 36);
    vector<vector<char> > encrypt(2, orig);
    
    //creates shifted second row in vector
    int k = 0;
    for(int i = 0; i < 36; i++)
    {
        k = (i+key)%36;
        
        encrypt[1][i] = encrypt[1][k];
    }
    for (int z = 0; z < key; z++)
    {
        encrypt[1][z+36-key] = encrypt[0][z];
    }
    
    /*
     //For my testing of the 2d vector
     //displays original and shifted rows in vector
     for(int m = 0; m < 2; m++)
     {
     for(int n = 0; n < 36; n++)
     {
     cout << encrypt[m][n] << " ";
     }
     cout << endl << endl;
     }
     */
    
    
    //encrypt message
    for(int v = 0;v < message.size(); v++)
    {
        for(int i = 0; i < 36; i++)
        {
            if(encrypt[0][i] == message[v])
            {
                message[v] = encrypt[1][i];
                break;
            }
        }
    }
    
    //Return encrypted message
    for(int v = 0; v < message.size(); v++)
    {
        cout << message[v];
    }
    cout << endl << endl;
    
    Validation();
}

/////////////////////////////////////////////
//  Function Name: Decryption
//  Parameters: none
//  Return: the decrypted string
//  Purpose: the opposite of encrypt function
//  given a encrypt message already and a key
//  (1-35) to decrypt and change the message
//  back to the before encrypted message
/////////////////////////////////////////////
void Decryption()
{
    //for original message and key (1-35)
    string message;
    int key;

    cout << "Enter your message: ";
    cin >> message;
    
    //Capitalizes each letter in message.
    for(int i = 0; i < message.size(); i++)
    {
        message[i] = toupper(message[i]);
    }
    //cout << message << endl;
    
    cout << "Enter the key number (1-35) \n";
    cin >> key;
    cin.ignore();
    
    while(key < 1 || key > 35)
    {
        cout << "Invalid Key Number. \n\n";
        Validation();
    }
    
    //Encryption process
    char array[36] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N'
        ,'O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4'
        ,'5','6','7','8','9'};
    
    vector<char> orig(array, array + 36);
    vector<vector<char> > decrypt(2, orig);
    
    
    //creates a shifted second row in vector
    int k = 0;
    for(int i = 0; i < 36; i++)
    {
        k = (i+key)%36;
        decrypt[1][i] = decrypt[1][k];
    }
    for (int z = 0; z < key; z++)
    {
        decrypt[1][z+36-key] = decrypt[0][z];
    }
    
    //decrypts message
    for(int v = 0;v < message.size(); v++)
    {
        for(int i = 0; i < 36; i++)
        {
            if(decrypt[1][i] == message[v])
            {
                message[v] = decrypt[0][i];
                break;
            }
        }
    }
    
    for(int v = 0; v < message.size(); v++)
    {
        cout << message[v];
    }
    cout << endl << endl;
    
    Validation();
}
