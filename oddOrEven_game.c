#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define ROWS 2
#define COLS 3

pthread_mutex_t locak;
int matrix[ROWS][COLS];
bool cell_open[ROWS][COLS];
int even_score = 0;
int odd_score = 0;

void display_matrix() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

bool all_cells_open() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!cell_open[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void open_cell(int row, int col) {
    if (!cell_open[row][col]) {
        cell_open[row][col] = true;
    }
}

void play(const char* player, int row, int col) {
    pthread_mutex_lock(&lock);
    open_cell(row, col);
    int num = matrix[row][col];

    if (num % 2 == 0 && strcmp(player, "Even") == 0) {
        even_score += num;
    } else if (num % 2 == 0 && strcmp(player, "Odd") == 0) {
        odd_score += num;
    } else if (num % 2 != 0 && strcmp(player, "Even") == 0) {
        even_score -= num;
    } else {
        odd_score -= num;
    }

    printf("%s plays at (%d, %d), scores: Even=%d, Odd=%d\n", player, row, col, even_score, odd_score);
    pthread_mutex_unlock(&lock);
}

void* player_thread(void* player_name) {
    const char* player = (const char*)player_name;
    while (!all_cells_open()) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (cell_open[row][col]);

        play(player, row, col);
        sleep(1); // Sleep for a second to simulate player actions.
    }
    return NULL;
}

int main() {
    pthread_t even_thread, odd_thread;

    // we are assigning random no. to matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10 + 1;
            cell_open[i][j] = false;
        }
    }

    pthread_mutex_init(&lock, NULL);

    printf("Initial Matrix:\n");
    display_matrix();

    pthread_create(&even_thread, NULL, player_thread, (void*)"Even");
    pthread_create(&odd_thread, NULL, player_thread, (void*)"Odd");

    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);


    printf("Final Scores - Even: %d, Odd: %d\n", even_score, odd_score);
    if(even_score > odd_score) {
      printf("Player Named Even WON!!!!\n");
    }
  else if(even_score==odd_score){
    printf("Its's a DRAW!!\n");
  }
  else{
    printf("Player Named ODD WON!!!\n");
  }

    pthread_mutex_destroy(&lock);

    return 0;
}
