// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

void renderMap(int, int, int, int, int, int, int, int, int, int);
void renderScore(int leftScore, int rightScore);
void first(int x, int z);
void one(int x);
void two(int x);
void three(int x);
void four(int x);
void five(int x);
void six(int x);
void seven(int x);
void eight(int x);
void nine(int x);
void zero(int x);
void first_branch_chet(int x, int y, int i);
void second_branch_chet(int x, int y, int i);
void thierd_branch_chet(int x, int y, int i);

int main() {
    char userInput;

    int mapWidth = 80;
    int mapHeight = 25;
    int leftY, rightY, leftX, rightX;
    int leftScore, rightScore;
    leftY = rightY = mapHeight / 2;
    leftX = mapWidth / 8;
    rightX = mapWidth * 7 / 8;
    leftScore = rightScore = 0;

    int ballX, ballXStep, ballY, ballYStep;
    ballX = mapWidth / 2;
    ballY = mapHeight / 2 - 1;
    ballXStep = ballYStep = -1;

    initscr();

    do {
        nodelay(stdscr, true);

        clear();
        renderMap(mapWidth, mapHeight, leftX, leftY, rightX, rightY, ballX, ballY, leftScore, rightScore);
        userInput = getch();
        // Update variables
        if ((userInput == 'a' || userInput == 'A') && leftY != 2) leftY -= 1;
        if ((userInput == 'z' || userInput == 'Z') && leftY != mapHeight - 2) leftY += 1;
        if ((userInput == 'k' || userInput == 'K') && rightY != 2) rightY -= 1;
        if ((userInput == 'm' || userInput == 'M') && rightY != mapHeight - 2) rightY += 1;
        ballY += ballYStep;
        ballX += ballXStep;
        if (ballY == mapHeight - 1 || ballY == 1) ballYStep *= -1;  // Floor / Ceiling collision
        if ((ballX == rightX - 1) && (ballY == rightY || ballY == rightY - 1 || ballY == rightY + 1 ||
                                      ballY == rightY + 2 || ballY == rightY - 2))
            ballXStep *= -1;
        if ((ballX == leftX + 1) && (ballY == leftY || ballY == leftY - 1 || ballY == leftY + 1 ||
                                     ballY == leftY + 2 || ballY == leftY - 2))
            ballXStep *= -1;
        if (ballX == mapWidth || ballX == 0) {  // Side collision
            if (ballX == 0) {
                rightScore += 1;
                ballX = leftX + 5;
            } else {
                leftScore += 1;
                ballX = rightX - 5;
            }

            leftY = rightY = ballY = mapHeight / 2;
            ballXStep *= -1;
            printw("\n");
        }

        usleep(60 * 1000);
        if (leftScore == 21 || rightScore == 21) break;
    } while (userInput != 'q');

    endwin();
    if (rightScore == 21) printf("Congratulations we have a winner - RIGHT player!!!!");
    if (leftScore == 21) printf("Congratulations we have a winner - LEFT player!!!!");
}

// RENDERING
void renderMap(int mapWidth, int mapHeight, int leftX, int leftY, int rightX, int rightY, int ballX,
               int ballY, int leftScore, int rightScore) {
    for (int i = 0; i < mapWidth + 1; i++) printw("#");
    printw("\n");
    for (int row = 1; row < mapHeight; row++) {
        for (int col = 0; col <= mapWidth; col++) {
            if (col == 0 || col == mapWidth)
                printw("#");
            else if (row == ballY && col == ballX)
                printw("X");
            else if (col == mapWidth / 2)
                printw("|");
            else if (col == rightX && (row == rightY - 1 || row == rightY || row == rightY + 1))
                printw("|");
            else if ((col == leftX) && (row == leftY - 1 || row == leftY || row == leftY + 1))
                printw("|");
            else
                printw(" ");
        }
        printw("\n");
    }
    for (int i = 0; i < mapWidth + 1; i++) printw("#");
    printw("\n");
    renderScore(leftScore, rightScore);
}

void renderScore(int leftScore, int rightScore) {
    int x = leftScore;
    int y = rightScore;
    for (int i = 0; i < 7; i++)  //Количество строк с которыми взаимодействует счет - 7 строчек
    {
        if (x <= 9)
            first_branch_chet(x, y, i);
        else if (x <= 19)
            second_branch_chet(x, y, i);
        else
            thierd_branch_chet(x, y, i);
    }
    printw("\n");
}

void first(int x, int z) {
    if (x == 0) zero(z);
    if (x == 1) one(z);
    if (x == 2) two(z);
    if (x == 3) three(z);
    if (x == 4) four(z);
    if (x == 5) five(z);
    if (x == 6) six(z);
    if (x == 7) seven(z);
    if (x == 8) eight(z);
    if (x == 9) nine(z);
}

void one(int x) {
    if (x == 0) printw("   @");
    if (x == 1) printw("  @@");
    if (x == 2) printw(" @ @");
    if (x == 3) printw("@  @");
    if (x == 4) printw("   @");
    if (x == 5) printw("   @");
    if (x == 6) printw("   @");
}

void two(int x) {
    if (x == 0) printw(" @@ ");
    if (x == 1) printw("@  @");
    if (x == 2) printw("   @");
    if (x == 3) printw("  @ ");
    if (x == 4) printw(" @  ");
    if (x == 5) printw("@   ");
    if (x == 6) printw("@@@@");
}

void three(int x) {
    if (x == 0) printw(" @@ ");
    if (x == 1) printw("@  @");
    if (x == 2) printw("   @");
    if (x == 3) printw(" @@ ");
    if (x == 4) printw("   @");
    if (x == 5) printw("@  @");
    if (x == 6) printw(" @@ ");
}
void four(int x) {
    if (x == 0) printw("@  @");
    if (x == 1) printw("@  @");
    if (x == 2) printw("@  @");
    if (x == 3) printw(" @@@");
    if (x == 4) printw("   @");
    if (x == 5) printw("   @");
    if (x == 6) printw("   @");
}
void five(int x) {
    if (x == 0) printw("@@@@");
    if (x == 1) printw("@   ");
    if (x == 2) printw("@   ");
    if (x == 3) printw("@@@ ");
    if (x == 4) printw("   @");
    if (x == 5) printw("   @");
    if (x == 6) printw("@@@ ");
}
void six(int x) {
    if (x == 0) printw(" @@ ");
    if (x == 1) printw("@  @");
    if (x == 2) printw("@   ");
    if (x == 3) printw("@@@ ");
    if (x == 4) printw("@  @");
    if (x == 5) printw("@  @");
    if (x == 6) printw(" @@ ");
}
void seven(int x) {
    if (x == 0) printw("@@@@");
    if (x == 1) printw("@  @");
    if (x == 2) printw("   @");
    if (x == 3) printw("   @");
    if (x == 4) printw("   @");
    if (x == 5) printw("   @");
    if (x == 6) printw("   @");
}
void eight(int x) {
    if (x == 0) printw(" @@ ");
    if (x == 1) printw("@  @");
    if (x == 2) printw("@  @");
    if (x == 3) printw(" @@ ");
    if (x == 4) printw("@  @");
    if (x == 5) printw("@  @");
    if (x == 6) printw(" @@ ");
}
void nine(int x) {
    if (x == 0) printw(" @@ ");
    if (x == 1) printw("@  @");
    if (x == 2) printw("@  @");
    if (x == 3) printw(" @@@");
    if (x == 4) printw("   @");
    if (x == 5) printw("@  @");
    if (x == 6) printw(" @@ ");
}
void zero(int x) {
    if (x == 0) printw(" @@ ");
    if (x == 1) printw("@  @");
    if (x == 2) printw("@  @");
    if (x == 3) printw("@  @");
    if (x == 4) printw("@  @");
    if (x == 5) printw("@  @");
    if (x == 6) printw(" @@ ");
}

void first_branch_chet(int x, int y, int i) {
    printw("                                 ");  //Тут мы печатаем первый
                                                  //отступ до счета,
    first(x, i);
    if (i == 3)
        printw("   ==   ");  //Логика для тире между цифрами
    else
        printw("        ");
    if (y <= 9) {
        first(y, i);
        printw("\n");
    } else if (y <= 19) {  //Логика есть счет 9-19
        first(1, i);
        printw(" ");
        first(y % 10, i);
        printw("\n");
    } else {
        first(2, i);  //Логика есть счет 9-21
        printw(" ");
        first(y % 10, i);
        printw("\n");
    }
}

void second_branch_chet(int x, int y, int i) {  //Логика есть счет 19-9
    printw("                            ");     //Тут мы печатаем первый отступ до
    first(x / 10, i);
    printw(" ");
    first(x % 10, i);
    if (i == 3)
        printw("  ==  ");  //Логика для тире между цифрами
    else
        printw("      ");
    if (y <= 9) {
        first(y, i);
        printw("\n");
    } else if (y <= 19) {  //Логика есть счет 19-19
        first(1, i);
        printw(" ");
        first(y % 10, i);
        printw("\n");
    } else {
        first(2, i);  //Логика есть счет 21-21
        printw(" ");
        first(y % 10, i);
        printw("\n");
    }
}
void thierd_branch_chet(int x, int y, int i) {
    //Логика есть счет 21-9
    printw("                            ");  //Тут мы печатаем первый отступ

    first(x / 10, i);
    printw(" ");
    first(x % 10, i);
    if (i == 3)
        printw("  ==  ");  //Логика для тире между цифрами
    else
        printw("      ");
    if (y <= 9) {
        first(y, i);
        printw("\n");
    } else if (y <= 19) {  //Логика есть счет 21-19
        first(1, i);
        printw(" ");
        first(y % 10, i);
        printw("\n");
    } else {
        first(2, i);  //Логика есть счет 21-21
        printw(" ");
        first(y % 10, i);
        printw("\n");
    }
}
