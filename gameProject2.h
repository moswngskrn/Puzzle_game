#ifndef GAMEPROJECT2_H_INCLUDED
#define GAMEPROJECT2_H_INCLUDED
#include <string>
//Data Definition
//position of array
//  Rows
//  columns
struct positionOfArray{
    int rows;
    int columns;
};
bool operator==(positionOfArray pa1,positionOfArray pa2);

//Purpose:Find position words in array
//Input:
//  words
//  array
//Output:
//  positionOfArray
//Contract:
//  findPosisionNumber(int,int,int arrays[])==positionOfArray
//Example:
//  string array[2][2] = {{"0","1"},
//                        {"2","3"}}
//  findPosisionNumber()==0
//  findPosisionNumber("0",2,2,array)=={0'0}
//  findPosisionNumber("1",2,2,array)=={0'1}
//  findPosisionNumber("2",2,2,array)=={1'0}
//  findPosisionNumber("3",2,2,array)=={1'1}
positionOfArray findPosisionWordsInArray4x4(std::string s,std::string data[4][4]);
//Purpose:move position
//Input:
//  char
//  position word
//  side rows of the array
//  side columns of the array
//Output:
//  new position of word
//Contract:
//  movePosition(char,positionOfArray)==positionOfArray
//Example:
//  movePosition("w",{1,1})=={0,1}
//  movePosition("s",{1,1})=={2,1}
//  movePosition("a",{1,1})=={1,0}
//  movePosition("d",{1,1})=={1,2}
//  movePosition("c",{1,1})=={1,1}
positionOfArray movePosition(char c,positionOfArray pa,int rows,int columns);
//Purpose:Verify that the array is the same size 4x4
//Input:
//  array1,array2
//  position start number
//Output:
//  true,false
//Contract:
//  arrayIsSameSize2D(array,array,int,int)==bool
//Example:
//  arrayIsSameSize({{"1","2"},{"3","4"}},{{"1","2"},{"3","4"}})==true
//  arrayIsSameSize({{"1","2"},{"3","4"}},{{"1","2"},{"3"," "}})==false
bool arrayIsSameSize4x4(std::string question[4][4],std::string answer[4][4],int n);
#endif // GAMEPROJECT2_H_INCLUDED
