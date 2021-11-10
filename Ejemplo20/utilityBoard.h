#include <stdbool.h>

#define DEFAULT_ROWS 4
#define DEFAULT_COLUMNS 4
#define COLOR_STRING_SIZE 12

enum showStatus { HIDDEN, SHOW, MATCH };

struct size {
    int n;
    int m;
};

struct cell {
    char card;               // 'A' 'B' 'C'
    enum showStatus status;  // Si esta baca arribo o boca abajo
};

struct board {
    struct size dimensions;
    char borderColor[COLOR_STRING_SIZE];
    char contentColor[COLOR_STRING_SIZE];
    struct cell **content;
};

struct size getBoardSize(int, const char *[]);
void initBoard(struct board *);
void fillBoard(struct board *); 
void freeBoard(struct board *);
void displayBoard(struct board *);
void displayCell(char *, char *, struct cell);
bool hasPairs(struct board *);