#include <stdio.h>
#include <string.h>

#define COLS 3
#define ROWS 4 // +1 for '\0' terminator
#define PLAYERS 2
#define TURN_MAX = 9;


void show_grid(char grid[COLS][ROWS]);
void do_turn(char grid[COLS][ROWS], int turn[2], int player_turn);


int main()
{
    int player_turn = 1;
    int turn_count = 0;
    int turn[2];

    char grid[COLS][ROWS] = {
        {""},
        {""},
        {""}
    };
    
    // print staring grid 
    show_grid(grid); 

    do_turn(grid, turn, player_turn);
    return 0;
}

void show_grid(char grid[COLS][ROWS])
{
    printf("----------------\n");
    int r;
    for (r = 0; r < 3; r++)
    {
        int c;
        for (c = 0; c < 3; c++)
        {
            printf("|%c:%i.%i", grid[r][c], r, c);
        }
        printf("|\n");
        printf("----------------\n");
    }
}

void do_turn(char grid[COLS][ROWS], int turn[2], int player_turn)
{
    int x;
    int y;
    _Bool x_valid = 0; 
    _Bool y_valid = 0;

    // check if coordinates within the grid bounds 
    while (x_valid == 0)
    {
        printf("enter x coordinate: "); 
        scanf("%i", &x); 

        if (x < 3) {
            x_valid = 1;
        }
        else {
            printf("Your entry must be between 0 and 2");
        }
    }

    while (y_valid == 0)
    {
        printf("enter y coordinate: "); 
        scanf("%i", &y); 

        if (y < 3) {
            y_valid = 1;
        }
        else {
            printf("Your entry must be between 0 and 2");
        }
    }

    printf("player %i entered %i,%i\n", player_turn, x, y);

    // check if the cell is available
    if (strcmp(&grid[x][y], "p1") == 0 || strcmp(&grid[x][y], "p2") == 0)
    {
        printf("position %i, %i has already been chosen, try again", x, y);
    }
    else
    {
        char player_name[3]; 
        player_name[0] = *"p";
        player_name[1] = (char) player_turn;

        grid[x][y] = *player_name;
        printf("contents of grid @ %i,%i: %c\n", x, y, grid[x][y]);
    }
}

