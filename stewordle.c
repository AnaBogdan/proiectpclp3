#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>

typedef struct {
    char name[50];
    char team[50];
    char country[50];
    int carNumber;
    int debutYear;
    int wins;
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
    {"Alex Albon", "Williams", "Thailand", 23, 2019, 0},
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
    {"Antonio Giovinazzi", "Haas", "Italy", 99, 2019, 0},
    {"Adrian Sutil", "Sauber", "Germany", 99, 2007, 0}
};

int totalDrivers = sizeof(drivers) / sizeof(Driver);

int findDriverIndex(char* name) {
    for (int i = 0; i < totalDrivers; i++) {
        if (strncmp( drivers[i].name, name, strlen(drivers[i].name) - 1) == 0)  {
            return i; // return the index of the driver if found
        }
    }
    return -1; // return -1 if driver not found
}

void printDriver(int index) {
    if (index >= 0 && index < totalDrivers) {
        printw("| %-20s | %-15s | %-15s | %-10d | %-10d | %-6d |\n",
               drivers[index].name, drivers[index].team, drivers[index].country,
               drivers[index].carNumber, drivers[index].debutYear, drivers[index].wins);
    }
}


void printDriverbad(int index, int correct) {
    if (index >= 0 && index < totalDrivers) {
        printw("| %-20s ", drivers[index].name);

        if (strcmp(drivers[index].team, drivers[correct].team) == 0) {
            attron(COLOR_PAIR(1)); // Set color pair 1 (green)
        } else {
            attron(COLOR_PAIR(2)); // Set color pair 2 (red)
        }
        printw("| %-15s ", drivers[index].team);

        if (strcmp(drivers[index].country, drivers[correct].country) == 0) {
            attron(COLOR_PAIR(1)); // Set color pair 1 (green)
        } else {
            attron(COLOR_PAIR(2)); // Set color pair 2 (red)
        }
        printw("| %-15s ", drivers[index].country);

        if (drivers[index].carNumber < drivers[correct].carNumber) {
            attron(COLOR_PAIR(4)); // Set color pair 3 (orange)
        } else if (drivers[index].carNumber > drivers[correct].carNumber) {
            attron(COLOR_PAIR(3)); // Set color pair 4 (purple)
        } else {
            attron(COLOR_PAIR(1)); // Set color pair 1 (green)
        }
        printw("| %-10d ", drivers[index].carNumber);

        if (drivers[index].debutYear < drivers[correct].debutYear) {
            attron(COLOR_PAIR(4)); // Set color pair 3 (orange)
        } else if (drivers[index].debutYear > drivers[correct].debutYear) {
            attron(COLOR_PAIR(3)); // Set color pair 4 (purple)
        } else {
            attron(COLOR_PAIR(1)); // Set color pair 1 (green)
        }
        printw("| %-10d ", drivers[index].debutYear);

        if (drivers[index].wins < drivers[correct].wins) {
            attron(COLOR_PAIR(4)); // Set color pair 3 (orange)
        } else if (drivers[index].wins > drivers[correct].wins) {
            attron(COLOR_PAIR(3)); // Set color pair 4 (purple)
        } else {
            attron(COLOR_PAIR(1)); // Set color pair 1 (green)
        }
        printw("| %-6d |\n", drivers[index].wins);

        attron(COLOR_PAIR(1)); // Reset color pair to default
        refresh(); // Refresh the screen
    }
}




int main() {
srand(time(NULL));
echo();
char playerName[50];
int i, found = 0, count = 0;
char guess[50];
int index, aux;

// Initialize ncurses
initscr();
cbreak();
start_color();
keypad(stdscr, TRUE);

// Check if terminal supports colors
if (has_colors() == FALSE) {
    printw("Your terminal does not support color.\n");
    endwin();
    return 1;
}

// Initialize color pairs
init_pair(1, COLOR_GREEN, COLOR_BLACK);      // Correct guess
init_pair(2, COLOR_RED, COLOR_BLACK);        // Incorrect guess
init_pair(3, COLOR_MAGENTA, COLOR_BLACK);    // Too high car number
init_pair(4, COLOR_YELLOW, COLOR_BLACK);     // Too low car number

printw("Welcome to the Formula 1 Driver Guessing Game!\n");
printw("\n");

printw("Guess the driver!\n");
printw("Enter the name corresponding to the driver's name:\n");
i = rand() % totalDrivers;
aux = findDriverIndex(drivers[i].name);
printw("\nDriver Name: %s\n", drivers[i].name);
refresh();

while (!found) {
    printw("Enter your guess: ");
    getstr(guess);
    index = findDriverIndex(guess);
    printw("+----------------------+-----------------+-----------------+------------+------------+--------+\n");
    printw("| Driver               | Team            | Country         | Car Number | Debut Year | Wins   |\n");
    printw("+----------------------+-----------------+-----------------+------------+------------+--------+\n");

    if (index != -1) {
        if (strcmp(drivers[index].name, drivers[i].name) == 0) {
            attron(COLOR_PAIR(1));  // Set color pair 1 (correct guess)
            printDriver(index);
            attroff(COLOR_PAIR(1)); // Turn off color pair 1
            printw("+----------------------+-----------------+-----------------+------------+------------+--------+\n");
            found = 1;
        } else {
            attron(COLOR_PAIR(2));  // Set color pair 2 (incorrect guess)
            printDriverbad(index, aux);
            attroff(COLOR_PAIR(2)); // Turn off color pair 2
            printw("+----------------------+-----------------+-----------------+------------+------------+--------+\n");
            count++;
        }
    } else {
        printw("Invalid guess. Please try again.\n");
    }
}

getch();
// Clean up ncurses
endwin();

return 0;


}
