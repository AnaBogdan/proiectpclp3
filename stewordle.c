#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char team[50];
    char country[50];
    int carNumber;
    int debutYear;
    int numOfWins;
} Driver;

Driver drivers[] = {
    {"Stoffel Vandoorne", "McLaren", "Belgium", 2, 2017, 0},
    {"Logan Sargeant", "Williams", "United States", 2, 2023, 0},
    {"Daniel Ricciardo", "McLaren", "Australia", 3, 2011, 8},
    {"Max Chilton", "Marussia", "United Kingdom", 4, 2013, 0},
    {"Lando Norris", "McLaren", "United Kingdom", 4, 2019, 0},
    {"Sebastian Vettel", "Aston Martin", "Germany", 5, 2007, 53},
    {"Nico Rosberg", "Mercedes", "Germany", 6, 2006, 20},
    {"Nicholas Latifi", "Williams", "Canada", 6, 2020, 0},
    {"Kimi Raikkonen", "Alfa Romeo", "Finland", 7, 2001, 21},
    {"Romain Grosjean", "Haas", "France", 8, 2009, 0},
    {"Marcus Ericsson", "Sauber", "Sweden", 9, 2014, 0},
    {"Nikita Mazepin", "Haas", "Russia", 9, 2021, 0},
    {"Kamui Kobayashi", "Caterham", "Japan", 10, 2009, 0},
    {"Pierre Gasly", "Alpine", "France", 10, 2017, 1},
    {"Sergio Perez", "Red Bull", "Mexico", 11, 2011, 6},
    {"Felipe Nasr", "Sauber", "Brazil", 12, 2015, 0},
    {"Pastor Maldonado", "Lotus", "Venezuela", 13, 2011, 1},
    {"Fernando Alonso", "Aston Martin", "Spain", 14, 2001, 32},
    {"Charles Leclerc", "Ferrari", "Monaco", 16, 2018, 5},
    {"Jules Bianchi", "Marussia", "France", 17, 2013, 0},
    {"Lance Stroll", "Aston Martin", "Canada", 18, 2017, 0},
    {"Felipe Massa", "Williams", "Brazil", 19, 2002, 11},
    {"Kevin Magnussen", "Haas", "Denmark", 20, 2014, 0},
    {"Esteban Gutiérrez", "Haas", "Mexico", 21, 2013, 0},
    {"Nyck de Vries", "AlphaTauri", "Netherlands", 21, 2022, 0},
    {"Jenson Button", "McLaren", "United Kingdom", 22, 2002, 15},
    {"Yuki Tsunoda", "AlphaTauri", "Japan", 22, 2021, 0},
    {"Alexander Albon", "Williams", "Thailand", 23, 2019, 0},
    {"Zhou Guanyu", "Alfa Romeo", "China", 24, 2022, 0},
    {"Jean-Éric Vergne", "Torro Rosso", "France", 25, 2012, 0},
    {"Daniil Kvyat", "AlphaTauri", "Russia", 26, 2014, 0},
    {"Nico Hülkenberg", "Haas", "Germany", 27, 2010, 0},
    {"Will Stevens", "Marussia", "United Kingdom", 28, 2014, 0},
    {"Brendon Hartley", "Torro Rosso", "New Zealand", 28, 2017, 0},
    {"Jolyon Palmer", "Renault", "United Kingdom", 30, 2016, 0},
    {"Esteban Ocon", "Alpine", "France", 31, 2016, 1},
    {"Max Verstappen", "Red Bull", "Netherlands", 33, 2015, 38},
    {"Sergey Sirotkin", "Williams", "Russia", 35, 2018, 0},
    {"Lewis Hamilton", "Mercedes", "United Kingdom", 44, 2007, 103},
    {"Mick Schumacher", "Haas", "Germany", 47, 2021, 0},
    {"Alexander Rossi", "Marussia", "United States", 53, 2014, 0},
    {"Carlos Sainz Jr.", "Ferrari", "Spain", 55, 2015, 1},
    {"George Russell", "Mercedes", "United Kingdom", 63, 2019, 1},
    {"Valtteri Bottas", "Alfa Romeo", "Finland", 77, 2013, 10},
    {"Oscar Piastri", "McLaren", "Australia", 81, 2023, 0},
    {"Rio Haryanto", "Manor", "Indonesia", 88, 2016, 0},
    {"Robert Kubica", "Alfa Romeo", "Poland", 88, 2006, 1},
    {"Jack Aitken", "Williams", "United Kingdom", 89, 2020, 0},
    {"Pascal Wehrlein", "Sauber", "Germany", 94, 2016, 0},
    {"Roberto Merhi", "Marussia", "Spain", 98, 2015, 0},
    {"Antonio Giovinazzi", "Haas", "Italy", 99, 2019, 0}
    {"Adrian Sutil", "Sauber", "Germany", 99, 2007, 0}
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
