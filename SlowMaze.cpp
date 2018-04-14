#include <iostream>
//#include <cstdlib>
#include <conio.h>      //_kbhit & _getch
//#include <string>
#include <ctime>        //srand(time())
//#include <stdlib.h>
#include <windows.h>     //system("CLS")
using namespace std;
bool GameOver=false;
const int WIDTH=25;
const int HEIGHT=25;
int x,y,xE,yE;
//int ObstacleX[25];
//int ObstacleY[25];
int Obstacle[25];
enum Direction{
    STOP=0,UP,DOWN,LEFT,RIGHT
};
Direction direction;
static void PlayOrExit(){
    int Choise=0;
    cout << "Awesome MazeGame from PLLUG(No)"<< endl;
    cout << "Enter 1,if u want playing or 0 for exit" << endl;
    cin >> Choise;
    if(Choise==1){
        GameOver=false;
    }
    else if(Choise==0){
        cout << "No,press 1.(u will not regret(no),we repeat question)" << endl;
    PlayOrExit();
    }
}
static void Settings(){
    GameOver=false;
    srand(time(NULL));
        x=1;
        y=1;
        xE=1+rand()%24;
        yE=1+rand()%24;
           for(int i=0;i<(sizeof(Obstacle)/sizeof(int));i++){
            Obstacle[i]=1+rand()%25;
           // cout << Obstacle[i] << endl;
    }

 /*       for(int i=0;i<(sizeof(AbstacleX)/sizeof(int));i++){
            AbstacleX[i]=2+rand()%24;
    }                                                             //old Abstacle
        for(int i=0;i<(sizeof(AbstacleY)/sizeof(int));i++){
            AbstacleY[i]=2+rand()%24;
    }
    */
}
static void DrawGameField (){
    Sleep(5);
    system("CLS");
    for(int i=0;i<WIDTH-1;i++){
        cout << "X";
    }
   for(int i =0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
         if(j==0 || j==WIDTH-1){
            cout << "X";
        }
        else if(j==x && i==y){
            cout << "@";
        }
        else if(j==xE && i==yE){
            cout << "E";
        }
        else if(i==Obstacle[j]){
            cout << "I";
        }
        else{
            cout << " ";
        }
        }
        cout << endl;
    }

    for(int i=0;i<WIDTH;i++){
        cout << "X";
    }
    cout << "\nGET TO E!!!"<< endl;
    }

static void KeybordHit(){
    if(_kbhit()){
        switch(_getch()){
        case'a':
            direction = LEFT;
        break;
        case 'd':
            direction = RIGHT;
        break;
        case 's':
            direction = DOWN;
        break;
        case 'w':
            direction = UP;
        break;
        case 'e':
            GameOver = true;
        break;
        case 'p':
            direction=STOP;
        }
         switch(direction){
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
     break;
    case DOWN:
        y++;
        break;
    case UP:
        y--;
        break;
    case STOP:
        x=1;
        y=1;
    default:
        break;
    }
    }
}
static void Logic(){
 if(x>=WIDTH || y>=HEIGHT || x<0 || y<0){
    GameOver=true;
    cout << "You hit the wall!let's try again?" << endl;
 }
 else if(x==xE && y==yE){
        GameOver=true;
        cout << "You found a way out!!!"<< endl;
 }

    for(int j=0;j<(sizeof(Obstacle)/sizeof(int));j++){
        if(x==j && y==Obstacle[j]){
                GameOver=true;
                cout << "You hit the Obstacle" << endl;
        }
    }
 }

int  main()
{
    PlayOrExit();
    Settings();
    do{
        DrawGameField();
        KeybordHit();
        Logic();
     }
     while(!GameOver);
     Sleep(1000);
     cout << endl;
     main();
     return 0;
}

// ÷
