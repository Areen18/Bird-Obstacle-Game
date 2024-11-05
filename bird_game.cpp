#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BIRD_WIDTH 40
#define BIRD_HEIGHT 30
#define PIPE_WIDTH 80
#define PIPE_GAP 200
#define GRAVITY 0.6
#define JUMP_STRENGTH 10
#define PIPE_SPEED 3
#define MAX_PIPES 3

// Define custom color ORANGE using RGB values
#define ORANGE COLOR(255, 165, 0)

struct Bird {
    float x, y;
    float velocity;
};

struct Pipe {
    float x;
    int topHeight;
};

Bird bird;
Pipe pipes[MAX_PIPES];
int score = 0;

void drawBird() {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(bird.x, bird.y, BIRD_WIDTH / 2, BIRD_HEIGHT / 2);

    // Eye
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(bird.x + BIRD_WIDTH / 4, bird.y - BIRD_HEIGHT / 4, 3, 3);

    // Beak
    setcolor(ORANGE);
    setfillstyle(SOLID_FILL, ORANGE);
    int beak[] = {int(bird.x + BIRD_WIDTH / 2), int(bird.y),
                  int(bird.x + BIRD_WIDTH / 2 + 10), int(bird.y - 5),
                  int(bird.x + BIRD_WIDTH / 2 + 10), int(bird.y + 5)};
    fillpoly(3, beak);
}

void drawPipe(Pipe pipe) {
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    bar(pipe.x, 0, pipe.x + PIPE_WIDTH, pipe.topHeight);
    bar(pipe.x, pipe.topHeight + PIPE_GAP, pipe.x + PIPE_WIDTH, SCREEN_HEIGHT);
}

void initializePipes() {
    for (int i = 0; i < MAX_PIPES; i++) {
        pipes[i].x = SCREEN_WIDTH + i * (SCREEN_WIDTH / MAX_PIPES);
        pipes[i].topHeight = rand() % (SCREEN_HEIGHT - PIPE_GAP - 100) + 50;
    }
}

bool checkCollision() {
    for (int i = 0; i < MAX_PIPES; i++) {
        if (bird.x + BIRD_WIDTH / 2 > pipes[i].x && bird.x - BIRD_WIDTH / 2 < pipes[i].x + PIPE_WIDTH) {
            if (bird.y - BIRD_HEIGHT / 2 < pipes[i].topHeight || bird.y + BIRD_HEIGHT / 2 > pipes[i].topHeight + PIPE_GAP) {
                return true;
            }
        }
    }
    return bird.y > SCREEN_HEIGHT || bird.y < 0;
}

void updateGame() {
    bird.velocity += GRAVITY;
    bird.y += bird.velocity;

    for (int i = 0; i < MAX_PIPES; i++) {
        pipes[i].x -= PIPE_SPEED;
        if (pipes[i].x < -PIPE_WIDTH) {
            pipes[i].x = SCREEN_WIDTH;
            pipes[i].topHeight = rand() % (SCREEN_HEIGHT - PIPE_GAP - 100) + 50;
            score++;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // Use NULL instead of an empty string

    bird = {100, SCREEN_HEIGHT / 2, 0};
    initializePipes();
    srand(time(NULL));

    while (true) {
        cleardevice();

        drawBird();
        for (int i = 0; i < MAX_PIPES; i++) {
            drawPipe(pipes[i]);
        }

        updateGame();

        if (checkCollision()) {
            break;
        }

        char scoreText[20];
        sprintf(scoreText, "Score: %d", score);
        outtextxy(10, 10, scoreText);

        if (kbhit()) {
            char ch = getch();
            if (ch == ' ') {
                bird.velocity = -JUMP_STRENGTH;
            }
        }

        delay(30);
    }

    cleardevice();
    outtextxy(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2, (char*)"Game Over!, press any key to exit.......");
  
    char finalScoreText[30];
    sprintf(finalScoreText, "Final Score: %d", score);
    outtextxy(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 30, finalScoreText);
    getch();

    closegraph();
    return 0;
}


