#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int playerX = 50;
int playerY = SCREEN_HEIGHT / 2;
#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 30
int bulletX, bulletY;
int isBulletActive = 0;//0 gaaktif
int enemyX, enemyY;
#define ENEMY_WIDTH 50
#define ENEMY_HEIGHT 30

void drawPlayer() {
    setcolor(WHITE);
    rectangle(playerX, playerY, playerX + PLAYER_WIDTH, playerY + PLAYER_HEIGHT);
}

void drawBullet() {
    if (isBulletActive) {
        setcolor(YELLOW);
        rectangle(bulletX, bulletY, bulletX + 10, bulletY + 5);//besar peluru
    }
}

void drawEnemy() {
    setcolor(RED);
    rectangle(enemyX, enemyY, enemyX + ENEMY_WIDTH, enemyY + ENEMY_HEIGHT);
}

int checkCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    return (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders ANJAYYYY");

    srand(time(0));

    enemyX = SCREEN_WIDTH;
    enemyY = rand() % (SCREEN_HEIGHT - ENEMY_HEIGHT);

    while (1) {
        cleardevice();
        drawPlayer();
        drawBullet();
        drawEnemy();
        enemyX -= 5;
        if (enemyX < 0) {
            enemyX = SCREEN_WIDTH;
            enemyY = rand() % (SCREEN_HEIGHT - ENEMY_HEIGHT);
        }
        if (isBulletActive) {
            bulletX += 10;
            if (bulletX > SCREEN_WIDTH) {//peluru nonaktif kalo lebih dari lebar layar
                isBulletActive = 0;
            }
        }
        if (isBulletActive && checkCollision(bulletX, bulletY, 10, 5, enemyX, enemyY, ENEMY_WIDTH, ENEMY_HEIGHT)) {//pepluru nonaktif nyentuh musuh
            isBulletActive = 0;
            enemyX = SCREEN_WIDTH;
            enemyY = rand() % (SCREEN_HEIGHT - ENEMY_HEIGHT);//ini musuh cuma 1 co, kalo kena peluru ya ngulang dari kanan trus random posisinya
        }
        if (kbhit()) {
            char key = getch();
            if (key == 'w' && playerY > 0) {//mencet w
                playerY -= 10;
            }
            if (key == 's' && playerY < SCREEN_HEIGHT - PLAYER_HEIGHT) {//mencet s
                playerY += 10;
            }
            if (key == 'a' && playerX > 0) {//mencet a
                playerX -= 10;
            }
            if (key == 'd' && playerX < SCREEN_WIDTH - PLAYER_WIDTH) {//mencet d
                playerX += 10;
            }
            if (key == ' ' && !isBulletActive) {//mencet spasi
                isBulletActive = 1;
                bulletX = playerX + PLAYER_WIDTH;
                bulletY = playerY + PLAYER_HEIGHT / 2 - 2;
            }
        }
        delay(30);
    }
    closegraph();
    return 0;
}
