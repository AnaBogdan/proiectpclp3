#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char team[50];
    int carNumber;
    int debutYear;
    int numOfWins;
} Driver;

Driver drivers[] = {
    {"Logan Sargeant", "Williams", 2, 2023, 0}
    {"Daniel Ricciardo", "McLaren", 3, 2011, 7},
    {"Lando Norris", "McLaren", 4, 2019, 0},
    {"Sebastian Vettel", "Aston Martin", 5, 2007, 53},
    {"Nicholas Latifi", "Williams", 6, 2020, 0},
    {"Kimi Räikkönen", "Alfa Romeo", 7, 2001, 21},
    {"Nikita Mazepin", "Haas", 9, 2021, 0},
    {"Pierre Gasly", "AlphaTauri", 10, 2017, 1},
    {"Sergio Perez", "Red Bull", 11, 2011, 2},
    {"Fernando Alonso", "Aston Martin", 14, 2001, 32},
    {"Charles Leclerc", "Ferrari", 16, 2018, 2},
    {"Lance Stroll", "Aston Martin", 18, 2017, 0},
    {"Yuki Tsunoda", "AlphaTauri", 22, 2021, 0},
    {"Esteban Ocon", "Alpine", 31, 2016, 1},
    {"Max Verstappen", "Red Bull", 33, 2015, 23},
    {"Lewis Hamilton", "Mercedes", 44, 2007, 103},
    {"Mick Schumacher", "Haas", 47, 2021, 0},
    {"Carlos Sainz Jr.", "Ferrari", 55, 2015, 2},
    {"George Russell", "Mercedes", 63, 2019, 1},
    {"Valtteri Bottas", "Alpha Romeo", 77, 2013, 9},
    {"Oscar Piastri", "McLaren", 81, 2023, 0},
    {"Antonio Giovinazzi", "Alfa Romeo", 99, 2017, 0},
};

int totalDrivers = sizeof(drivers) / sizeof(Driver);

int main() {
    char playerName[50];
    int i, guess, found = 0;

    printf("Welcome to the Formula 1 Driver Guessing Game!\n");
    printf("Enter your name: ");
    scanf("%s", playerName);
    printf("\n");

    printf("Guess the driver!\n");
    printf("Enter the number corresponding to the driver's name:\n");

    while (!found) {
        i = rand() % totalDrivers;

        printf("\nDriver Name: %s\n", drivers[i].name);
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess == i) {
            printf("\nCongratulations, %s! Your guess is correct!\n", playerName);
            printf("Driver: %s\n", drivers[i].name);
            printf("Team: %s\n", drivers[i].team);
            printf("Car Number: %d\n", drivers[i].carNumber);
            printf("Debut Year: %d\n", drivers[i].debutYear);
            printf("Number of Wins: %d\n", drivers[i].numOfWins);
            found = 1;
        } else {
            printf("Oops! Incorrect guess. Try again!\n");
        }
    }

    return 0;
}
