#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>

// chars for password generation
const char alphanum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// string length variable
int string_length = sizeof(alphanum)-1;

// max and minimum password length
void pswd_max_length(int(n), int(low))
{
    if (n < low)
    {
        std::cout << "Number cannot be smaller than 6 letters!\n\n" << std::endl;

        system("pause");
        exit(0);
    } else if (n > 100)
    {
        std::cout << "You cannot generate a password longer than 100 letters!\n\n" << std::endl;

        system("pause");
        exit(0);
    }   
}

// max and minimum amount of password to generate
void max_generate(int(repeat))
{
    if (repeat > 50)
    {
        std::cout << "You cannot generate more than 50 passwords!\n\n" << std::endl;

        system("pause");
        exit(0);
    } else if (repeat == int(0))
    {
        std::cout << "Generating 0 passwords isnt possible so I will assume you attempted to input 1.\n";

        repeat = 1;
    }
    
}

int main()
{
    int n;
    int repeat;
    int low = 6;

    std::cout << "[How many passwords would you like to generate]:> ";
    std::cin >> repeat; // input amount of passwords to generate

    max_generate(repeat); // check how for the max and lowest amount they can generate passwords

    std::cout << "[Enter the length of password]:> ";
    std::cin >> n; // input password length

    pswd_max_length(n, low); // Check if the password is too long or too short

    srand(time(0)); // Seed (unpredictable seed) time(0) makes sure every password generated is unique
 
    std::cout << "Generated passwords: \n" << std::endl;

    for(int i = 0; i < repeat; i++) // for loop to generate passwords
    {   
        for (int i = 0; i < n; i++)
        {
            std::cout << alphanum[rand() % string_length]; 
            
        }
        std::cout << "\n";
    }

    return 0;
}