# Poiect pclp3
Stewordle 
The program uses the ncurses library to create a text-based interface. Here's a breakdown of the code:

The code defines a structure called Driver to represent a Formula 1 driver. It contains fields such as name, team, country, car number, debut year, and wins.
An array of Driver structures called drivers is declared, which stores information about various drivers.
The initializeDrivers() function is used to allocate memory for the strings in the drivers array.
The cleanupDrivers() function frees the allocated memory for the strings in the drivers array.
The findDriverIndex() function searches for a driver in the drivers array based on the provided name and returns the index of the driver if found.
The printDriver() function prints the details of a driver at the given index.
The printDriverbad() function prints the details of a driver at the given index and highlights the correct and incorrect details with different colors.
The main() function is the entry point of the program.
It initializes the ncurses library and sets up color pairs for displaying correct and incorrect guesses.
It prompts the user to guess the name of a Formula 1 driver within 4 attempts.
After each guess, it compares the input with the randomly selected driver's name and displays the driver's details.
If the guess is correct, it displays a success message.
If the guess is incorrect, it increments the count and displays a failure message.
If the user exceeds the maximum number of attempts, it displays the correct answer.
The ncurses library is cleaned up, memory is freed, and the program exits.
