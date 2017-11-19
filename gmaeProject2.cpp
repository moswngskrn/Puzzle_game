#include "gameProject2.h"
bool operator==(positionOfArray pa1,positionOfArray pa2){
    return pa1.columns==pa2.columns && pa1.rows==pa2.rows;
}
positionOfArray findPosisionWordsInArray4x4(std::string s,std::string data[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(data[i][j]==s){
                return {i,j};
            }
        }
    }
    return {0,0};
}

positionOfArray movePosition(char c,positionOfArray pa,int rows,int columns){
    if(c=='s' || c=='Ë'){
        if(pa.rows==0){
            return {pa.rows,pa.columns};
        }
        else{
            return {pa.rows-1,pa.columns};
        }
    }
    else if(c=='w' || c=='ä'){
        if(pa.rows==(rows-1)){
            return {pa.rows,pa.columns};
        }
        else{
            return {pa.rows+1,pa.columns};
        }
    }
    else if(c=='d' || c=='¡'){
        if(pa.columns==0){
            return {pa.rows,pa.columns};
        }
        else{
            return {pa.rows,pa.columns-1};
        }
    }
    else if(c=='a' || c=='¿'){
        if(pa.columns==(columns-1)){
            return {pa.rows,pa.columns};
        }
        else{
            return {pa.rows,pa.columns+1};
        }
    }
    else{
        return {pa.rows,pa.columns};
    }
}

bool arrayIsSameSize4x4(std::string question[4][4],std::string answer[4][4],int n){
    if(n==4){
        return true;
    }
    else{
        return (question[n][0]==answer[n][0] &&
                question[n][1]==answer[n][1] &&
                question[n][2]==answer[n][2] &&
                question[n][3]==answer[n][3])&& arrayIsSameSize4x4(question,answer,n+1);
    }
}
