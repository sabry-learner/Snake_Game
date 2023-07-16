#include "graphics.h"
#include <climits>
#include <queue>
#include<iostream>
using namespace std;


const int EMPTY = 0;
const int BODY = 1;
const int APPLE = 2;
const int WALL = 3;
bool isGameOver= false;
enum Directions{ UP,DOWN,LEFT,RIGHT};
Directions snakeDirection = DOWN;
struct Location{
    int r;
    int c;
};
queue<Location> snakeBody;

int board[35][35]={
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
};
void drawSnakeBody(int r, int c)
{
    int x = c*18;
    int y = r*18;
    setfillstyle(SOLID_FILL,YELLOW);
    bar(x+1,y+1,x+17,y+17);
}

void eraseSnakeBody(int r, int c)
{
    int x = c*18;
    int y = r*18;
    setfillstyle(SOLID_FILL,BLACK);
    bar(x,y,x+18,y+18);
}

void drawApple(int r, int c)
{
    int x = c*18;
    int y = r*18;

    readimagefile("red-apple (1).ico",x+1,y+1,x+16,y+16);
}
void drawWall(int r, int c)
{
    int x = c*18;
    int y = r*18;
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(x,y,x+18,y+18);
    setcolor(BLACK);
    setlinestyle(SOLID_LINE,1,NORM_WIDTH);
    line(x+0,y+0,x+18,y+0);
    line(x+0,y+9,x+18,y+9);
    line(x+0,y+18,x+18,y+18);
    line(x+12,y+0,x+12,y+9);
    line(x+6,y+9,x+6,y+18);

}
void drawBoard()
{
    for(int r=0; r<35; r++)
        for(int c=0; c<35; c++)
        {
            switch(board[r][c])
            {
            case EMPTY:
                break;
            case BODY:
                drawSnakeBody(r,c);
                break;
            case APPLE:
                drawApple(r,c);
                break;
            case WALL:
                drawWall(r,c);
                break;

            }
        }
}
void initSnake(){
    Location loc;
    loc.r = 2;
    loc.c = 10;

    for(int i=0;i<5;i++){
        snakeBody.push(loc);
        loc.r+=1;

    }
}
Location getNextHead(){
    Location head = snakeBody.back();
    switch(snakeDirection){
    case UP:
        head.r -= 1;break;
    case DOWN:
        head.r += 1;break;
    case LEFT:
        head.c -= 1;break;
    case RIGHT:
        head.c += 1;break;
    }

    return head;
}
void generateNextRandomApple(){
    int r,c;
    do{
        r = rand() % 35;
        c = rand() % 35;

    }while(board[r][c] !=EMPTY);
    drawApple(r,c);
    board[r][c] = APPLE;
}
void moveSnakeToNextLocation(Location nextHead){
    snakeBody.push(nextHead);
    drawSnakeBody(nextHead.r,nextHead.c);
    board[nextHead.r][nextHead.c] = 1;

    Location tail = snakeBody.front();
    snakeBody.pop();
    eraseSnakeBody(tail.r,tail.c);
    board[tail.r][tail.c] = 0;
}
void moveAndGrowSnake(Location nextHead){
    snakeBody.push(nextHead);
    drawSnakeBody(nextHead.r,nextHead.c);
    board[nextHead.r][nextHead.c] = 1;


}
void GameOver(){
    string sound="433644__dersuperanton__game-over-sound.wav";
    PlaySound(sound.c_str(),NULL,SND_SYNC);
    isGameOver = true;
    setcolor(RED);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    outtextxy(getmaxx()/2,getmaxy()/2,"Game Over");
    setcolor(CYAN);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
    outtextxy(getmaxx()/2,(getmaxy()*3)/4,"Developed By: Eng.Ahmed Sabry");

}
void menuGame(){
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(GREEN);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    outtextxy(getmaxx()/2,getmaxy()/4,"Snake Game");
    setcolor(CYAN);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
    outtextxy(getmaxx()/2,240,"1. Start Game. ");
    outtextxy(getmaxx()/2,290,"2. Info About Me. ");
    outtextxy(getmaxx()/2,340,"3. Exit. ");


}
void moveSnake()
{
    string sound="20279__koops__apple_crunch_16.wav";
    Location nextHead = getNextHead();
    switch(board[nextHead.r][nextHead.c]){
    case EMPTY:
        moveSnakeToNextLocation(nextHead);
        break;
    case APPLE:
        PlaySound(sound.c_str(),NULL,SND_ASYNC);
        moveAndGrowSnake(nextHead);
        generateNextRandomApple();
        break;
    case WALL:
    case BODY:
        GameOver();
    }
}
void changeSnakeDirection(char ch){
    switch(ch){
    case KEY_UP: snakeDirection = UP; break;
    case KEY_DOWN: snakeDirection = DOWN; break;
    case KEY_LEFT: snakeDirection = LEFT; break;
    case KEY_RIGHT: snakeDirection = RIGHT; break;
    }
}
void checkKeyInput(){
    char ch;
    if(kbhit()){
        ch = getch();
        if(ch==0){
            ch = getch();
            changeSnakeDirection(ch);
        }
    }
}
int main()
{
    isGameOver = false;
    initwindow(630,630);




    initSnake();
    drawBoard();


    int gameTimer=0;
    while(!isGameOver)
    {
        if(gameTimer==INT_MAX)
        {
            gameTimer=0;
        }
        if(gameTimer%6000000==0){
            moveSnake();
        }
        gameTimer++;
        checkKeyInput();
    }

        while(! kbhit());




    return 0;

}
