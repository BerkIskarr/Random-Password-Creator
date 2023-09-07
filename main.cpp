//
//  main.cpp
//  Assignment1
//
//  Created by Berk Iskar on 20/03/2023.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string characters = "ASDFGHJKLZXCVBNMQWERTYUIOPasdfghjklzxcvbnmqwertyuiop0123456789";//we will be choosing our unique characters from there.
    srand((int)time(NULL));
    
    vector<string> password_20;//to be able to store all of the password created (20 passwords).
    
    for (int i = 0; i < 20; i++) { //this for loop is to create 20 different passwords.
        
        string password;//each of the password will be stored in this string.
        int limit = 10 + (rand() % 7);//creates a limit of which we can limit the amount of character our passwords have.
        
        while (true) {//to create multiple passwords, I created an infinite loop until it breaks.
            
            for (int j = 0; j < limit; j++) {//this loop will work 10 to 16 times(depends on the 'limit').
                int specific_char = rand() % characters.length();//choose random char from our string characters.
                char new_char = characters[specific_char];//to be able to make it easier to read,to prevent ambigiousness, and make it easier for me to write codes and comments- it is so long.
                
                while(password.find(new_char) != string::npos ||//to compare each of the character picked to all the other character to see if there is any repitition. Find function helps us to find the 'new_char inside of the password, and string::npos means from beginning till the end, which control if 'new_char' already exist in our password.
                      (isupper(new_char) && password.find(tolower(new_char)) != string::npos) ||//issupper finds uppercases and using tolower, we can transfer to lowercases instead of using ASCII, and also as i mentioned before, i control if there is any in the password by using != string::npos.
                      (islower(new_char) && password.find(toupper(new_char)) != string::npos)) {//same reason except islower finds the lowercases and toupper transfers to uppercases.
                    
                    specific_char = rand() % characters.length();//if there is any problem choose another random char.
                    new_char = characters[specific_char];
                }
                
                password += new_char;//add our choosen and evaluated character into our password
            }
            
            if (password.length() == limit &&//to make sure length of our password equals to the randomly created limit
                count_if(password.begin(), password.end(), ::isupper) > 0 &&
                count_if(password.begin(), password.end(), ::islower) > 0 &&
                count_if(password.begin(), password.end(), ::isdigit) > 0) {//count_if(start, end, what are we counting) enables us to count uppercases(isupper), lowercases(islower), numbers(isdigit or isnumber) and continues if they exist in the password
                
                password_20.push_back(password);//add our complete password into our vector
                
                break;//after adding break the while loop
            }
            else {//if the password is flawed
                password.clear();//clear the password
                limit = 10 + (rand() % 7);//create a new random limit, to prevent all of our passwords having the same length
            }
        }
        
        
    }
    
    for (auto l: password_20) {
        cout << l << endl;   //to be able to print all of the passwords stored in our vector
    }

    return 0;
}

