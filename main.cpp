#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "gameProject2.h"
using namespace std;

void printTable(string data[4][4],int start,int finish);
int playGame(string answer[4][4],string question[4][4]);
void printHeadGame();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int colorText=7;
int main()
{
    time_t start,stop;
    int side=4;
    int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    //string question[side][4]={{" ","12","9","2"},{"3","4","7","1"},{"8","11","10","6"},{"13","14","15","5"}};
    string question[side][4]={{"1","2","3","4"},{"5","6","7","8"},{"9","10","11","12"},{"13","14"," ","15"}};
    string answer[side][4]={{"1","2","3","4"},{"5","6","7","8"},{"9","10","11","12"},{"13","14","15"," "}};
    printHeadGame();
    SetConsoleTextAttribute(hConsole,colorText);
    printTable(question,0,4);
    //start count time
    time(&start);
    //run game
    playGame(answer,question);
    //stop count time
    time(&stop);

    //end game
    SetConsoleTextAttribute(hConsole, 11);
    cout <<"========================================="<<endl;
    cout <<"                                       "<<endl;
    cout <<"         you use time is "<<stop-start<<" sec"<<endl;
    cout <<"         ***** GOOD JOB! *****         "<<endl;
    cout <<"                                       "<<endl;
    cout <<"=========================================\n"<<endl;
    cout <<"========================================="<<endl;
    cout <<"key :\t'n' is new game"<<endl;
    cout <<"========================================="<<endl;

    //message key play again
    char c=getch();
    if (c=='n' || c=='×'){
        system("cls");
        colorText = 7;
        return main();
    }
    return 0;
}
void printHeadGame(){
    SetConsoleTextAttribute(hConsole, 13);
    cout <<"========================================="<<endl;
    cout <<"|                 GAME                  |" << endl;
    cout <<"========================================="<<endl;
}
void printTable(string data[4][4],int start,int finish){

    if(start==finish){
        cout<<"|===|-------|-------|-------|-------|===|"<<endl;
    }
    else{
        cout<<"|===|-------|-------|-------|-------|===|"<<endl;
        cout<<"|\t"<<data[start][0]<<"\t"<<data[start][1]<<"\t"<<data[start][2]<<"\t"<<data[start][3]<<"\t|"<<endl;
        return printTable(data,start+1,finish);
    }
}
int playGame(string answer[4][4],string question[4][4]){
    if(arrayIsSameSize4x4(question,answer,0)){
        system("cls");
        printHeadGame();
        colorText=10;
        SetConsoleTextAttribute(hConsole,colorText);
        printTable(question,0,4);
        cout<<"Correct"<<endl;
        return 0;
    }
    else{
        positionOfArray paNULL=findPosisionWordsInArray4x4(" ",question);
        SetConsoleTextAttribute(hConsole, 14);
        cout <<"========================================="<<endl;
        cout <<"Key :\t'w' is Up\t 's' is Down\n\t'a' is Left\t 'd' is Right" << endl;
        cout <<"========================================="<<endl;
        positionOfArray newPosition = movePosition(getch(),paNULL,4,4);
        system("cls");
        printHeadGame();
        question[paNULL.rows][paNULL.columns]=question[newPosition.rows][newPosition.columns];
        question[newPosition.rows][newPosition.columns]=" ";
        //cout<<"\n";
        SetConsoleTextAttribute(hConsole,colorText);
        printTable(question,0,4);
        return playGame(answer,question);
    }
}
