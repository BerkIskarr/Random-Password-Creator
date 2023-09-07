# Random Password Generator
This is a simple C++ program that generates random passwords based on a set of specified criteria. The program creates 20 unique passwords with the following characteristics:

Length between 10 and 16 characters.
At least one uppercase letter.
At least one lowercase letter.
At least one digit.

# How it Works
The program uses the C++ standard library to achieve its goal. Here's an overview of how it works:

Character Set: The characters that can be used in the generated passwords are defined in the characters string.

Random Seed: The program initializes the random number generator with the current time to ensure that each run produces different passwords.

Password Generation: The main loop iterates 20 times to generate 20 different passwords. For each password, it follows these steps:

a. Randomly selects a length between 10 and 16 characters.

b. Enters an inner loop to construct the password character by character.

c. In the inner loop, it randomly selects characters from the characters set, ensuring that each character is unique within the password and meets the specified criteria.

Password Validation: After constructing a password, it checks if it meets the criteria of having at least one uppercase letter, one lowercase letter, and one digit. If not, it clears the password and generates a new one with a different length.

Storage: Valid passwords are stored in a vector named password_20.

Display: Finally, the program prints all 20 generated passwords to the console.
