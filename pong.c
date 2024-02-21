// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI
#include <stdio.h>

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
    char userInput = 'b';

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

    do {
        puts("\x1B[2J");

        // Update variables
        renderMap(mapWidth, mapHeight, leftX, leftY, rightX, rightY, ballX, ballY, leftScore, rightScore);
        if (userInput == 'A' || userInput == 'Z' || userInput == 'K' || userInput == 'M' ||
            userInput == ' ') {
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
            }
            printf("\n");
        }
        if (scanf("%c", &userInput) == 1) continue;
    } while (leftScore != 21 && rightScore != 21);
    if (rightScore == 21) printf("Congratulations we have a winner - RIGHT player!!!!");
    if (leftScore == 21) printf("Congratulations we have a winner - LEFT player!!!!");
}

// RENDERING
void renderMap(int mapWidth, int mapHeight, int leftX, int leftY, int rightX, int rightY, int ballX,
               int ballY, int leftScore, int rightScore) {
    for (int i = 0; i < mapWidth + 1; i++) printf("#");
    printf("\n");
    for (int row = 1; row < mapHeight; row++) {
        for (int col = 0; col <= mapWidth; col++) {
            if (col == 0 || col == mapWidth)
                printf("#");
            else if (row == ballY && col == ballX)
                printf("X");
            else if (col == mapWidth / 2)
                printf("|");
            else if (col == rightX && (row == rightY - 1 || row == rightY || row == rightY + 1))
                printf("|");
            else if ((col == leftX) && (row == leftY - 1 || row == leftY || row == leftY + 1))
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < mapWidth + 1; i++) printf("#");
    printf("\n");
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
    printf("\n");
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
    if (x == 0) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 1) printf("\u25A0\u25A0\u25A1\u25A1");
    if (x == 2) printf("\u25A0\u25A1\u25A0\u25A1");
    if (x == 3) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 4) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 5) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 6) printf("\u25A0\u25A0\u25A0\u25A1");
}

void two(int x) {
    if (x == 0) printf("\u25A0\u25A1\u25A1\u25A0");
    if (x == 1) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 2) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 3) printf("\u25A0\u25A0\u25A1\u25A0");
    if (x == 4) printf("\u25A0\u25A1\u25A0\u25A0");
    if (x == 5) printf("\u25A1\u25A0\u25A0\u25A0");
    if (x == 6) printf("\u25A1\u25A1\u25A1\u25A1");
}

void three(int x) {
    if (x == 0) printf("\u25A0\u25A1\u25A1\u25A0");
    if (x == 1) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 2) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 3) printf("\u25A0\u25A1\u25A1\u25A0");
    if (x == 4) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 5) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 6) printf("\u25A0\u25A1\u25A1\u25A0");
}
void four(int x) {
    if (x == 0) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 1) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 2) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 3) printf("\u25A0\u25A1\u25A1\u25A1");
    if (x == 4) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 5) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 6) printf("\u25A0\u25A0\u25A0\u25A1");
}
void five(int x) {
    if (x == 0) printf("\u25A1\u25A1\u25A1\u25A1");
    if (x == 1) printf("\u25A1\u25A0\u25A0\u25A0");
    if (x == 2) printf("\u25A1\u25A0\u25A0\u25A0");
    if (x == 3) printf("\u25A1\u25A1\u25A1\u25A0");
    if (x == 4) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 5) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 6) printf("\u25A1\u25A1\u25A1\u25A0");
}
void six(int x) {
    if (x == 0) printf("\u25A0\u25A1\u25A1\u25A0");
    if (x == 1) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 2) printf("\u25A1\u25A0\u25A0\u25A0");
    if (x == 3) printf("\u25A1\u25A1\u25A1\u25A0");
    if (x == 4) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 5) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 6) printf("\u25A0\u25A1\u25A1\u25A0");
}
void seven(int x) {
    if (x == 0) printf("\u25A1\u25A1\u25A1\u25A1");
    if (x == 1) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 2) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 3) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 4) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 5) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 6) printf("\u25A0\u25A0\u25A0\u25A1");
}
void eight(int x) {
    if (x == 0) printf("\u25A0\u25A1\u25A1\u25A0");
    if (x == 1) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 2) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 3) printf("\u25A1\u25A1\u25A1\u25A1");
    if (x == 4) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 5) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 6) printf("\u25A0\u25A1\u25A1\u25A0");
}
void nine(int x) {
    if (x == 0) printf("\u25A0\u25A1\u25A1\u25A0");
    if (x == 1) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 2) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 3) printf("\u25A0\u25A1\u25A1\u25A1");
    if (x == 4) printf("\u25A0\u25A0\u25A0\u25A1");
    if (x == 5) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 6) printf("\u25A0\u25A1\u25A1\u25A0");
}
void zero(int x) {
    if (x == 0) printf("\u25A0\u25A1\u25A1\u25A0");
    if (x == 1) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 2) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 3) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 4) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 5) printf("\u25A1\u25A0\u25A0\u25A1");
    if (x == 6) printf("\u25A0\u25A1\u25A1\u25A0");
}

void first_branch_chet(int x, int y, int i) {
    printf("                                 ");  //Тут мы печатаем первый
                                                  //отступ до счета,
    first(x, i);
    if (i == 3)
        printf("  \u2B1B\u2B1B  ");  //Логика для тире между цифрами
    else
        printf("        ");
    if (y <= 9) {
        first(y, i);
        printf("\n");
    } else if (y <= 19) {  //Логика есть счет 9-19
        first(1, i);
        printf(" ");
        first(y % 10, i);
        printf("\n");
    } else {
        first(2, i);  //Логика есть счет 9-21
        printf(" ");
        first(y % 10, i);
        printf("\n");
    }
}

void second_branch_chet(int x, int y, int i) {  //Логика есть счет 19-9
    printf("                            ");     //Тут мы печатаем первый отступ до
    first(x / 10, i);
    printf(" ");
    first(x % 10, i);
    if (i == 3)
        printf("  \u2B1B\u2B1B  ");  //Логика для тире между цифрами
    else
        printf("      ");
    if (y <= 9) {
        first(y, i);
        printf("\n");
    } else if (y <= 19) {  //Логика есть счет 19-19
        first(1, i);
        printf(" ");
        first(y % 10, i);
        printf("\n");
    } else {
        first(2, i);  //Логика есть счет 21-21
        printf(" ");
        first(y % 10, i);
        printf("\n");
    }
}
void thierd_branch_chet(int x, int y, int i) {
    //Логика есть счет 21-9
    printf("                            ");  //Тут мы печатаем первый отступ

    first(x / 10, i);
    printf(" ");
    first(x % 10, i);
    if (i == 3)
        printf("  \u2B1B\u2B1B  ");  //Логика для тире между цифрами
    else
        printf("      ");
    if (y <= 9) {
        first(y, i);
        printf("\n");
    } else if (y <= 19) {  //Логика есть счет 21-19
        first(1, i);
        printf(" ");
        first(y % 10, i);
        printf("\n");
    } else {
        first(2, i);  //Логика есть счет 21-21
        printf(" ");
        first(y % 10, i);
        printf("\n");
    }
}