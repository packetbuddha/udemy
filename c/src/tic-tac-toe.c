#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

#define COLS 3
#define ROWS 4 // +1 for '\0' terminator
#define PLAYERS 2
#define TURN_MAX 9

void show_grid(char grid[COLS][ROWS]);
void do_turn(char grid[COLS][ROWS], char player_turn);
bool check_win(char grid[COLS][ROWS], char player_turn);


int main()
{
    char player_turn = 'X'; 
    int turn_count = 0;

    char grid[COLS][ROWS] = {
        {},
        {},
        {}
    };
    
    show_grid(grid); // print starting grid 

    while (turn_count < TURN_MAX)
    {
        do_turn(grid, player_turn);
        turn_count++;

        if (check_win(grid, player_turn) == 1)
        {
            printf("*** player %c wins! ***\n\n", player_turn);
            break;
        }

        // swap player turn
        if (player_turn == 'X')
        {
            player_turn = 'Y';
        } else {
            player_turn = 'X';
        }
    }

    return 0;
}

void show_grid(char grid[COLS][ROWS])
{
    printf("----------------\n");
    int c;
    for (c = 0; c < 3; c++)
    {
        int r;
        for (r = 0; r < 3; r++)
        {
            printf("|%c:%i.%i", grid[c][r], c, r);
        }
        printf("|\n");
        printf("----------------\n");
    }
}

void do_turn(char grid[COLS][ROWS], char player_turn)
{
    int x;
    int y;
    bool x_valid = 0; 
    bool y_valid = 0;

    // check if coordinates within the grid bounds 
    // TODO: this gets stuck in infinate loop if a float is entered (0.0)
    while (x_valid == 0)
    {
        printf("player %c enter x coordinate: ", player_turn); 
        scanf("%d", &x); 

        if (x >= 0 && x < 3) {
            x_valid = 1;
        }
        else {
            printf("Your entry must be between 0 and 2");
        }
    }

    while (y_valid == 0)
    {
        printf("player %c enter y coordinate: ", player_turn); 
        scanf("%d", &y); 

        if (y >= 0 && y < 3) {
            y_valid = 1;
        }
        else {
            printf("Your entry must be between 0 and 2");
        }
    }

    printf("player %c entered %i,%i\n", player_turn, x, y);

    // check if the cell is available
    if (grid[x][y] == 'X' || grid[x][y] == 'Y')
    {
        printf("position %i, %i has already been chosen, try again\n", x, y);
    }
    else
    {
        grid[x][y] = player_turn; 
        printf("contents of grid @ %i,%i: %c\n", x, y, grid[x][y]);
        show_grid(grid);
    }
}

bool check_win(char grid[COLS][ROWS], char player_turn)
{
    bool winner = 0;

    int winners[8][3][2] = {
        { {0, 0}, {0, 1}, {0, 2} },
        { {1, 0}, {1, 1}, {1, 2} },
        { {2, 0}, {2, 1}, {2, 2} },
        { {0, 0}, {1, 0}, {2, 0} },
        { {0, 1}, {1, 1}, {2, 1} },
        { {0, 2}, {1, 2}, {2, 2} },
        { {0, 0}, {1, 1}, {2, 2} },
        { {0, 2}, {1, 1}, {2, 0} }
    };

    int i; // winning set
    int j; // coordinate set
    for (i = 0; i < 8; i++)
    {
        if (winner == 1)
            break;

        for (j = 0; j < 3; j++)
        {
            int x = winners[i][j][0];
            int y = winners[i][j][1];
            if (grid[x][y] == player_turn)
            {
                winner = 1;
            } else {
                winner = 0;
                break;
            }
        }
    }
       
    return winner;
}
