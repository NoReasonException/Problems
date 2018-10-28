//
// Created by noreasonexception on 19/10/2018.
//

#ifndef UNTITLED1_MANHATTANTABLE_H
#define UNTITLED1_MANHATTANTABLE_H


#include <iosfwd>
#include <algorithm>
#include <iostream>
#include "../Table.h"
#define  TABLE_START 0
#define  TABLE_END_X this->getTableXSize()-1
#define  TABLE_END_Y this->getTableYSize()-1

#define UP_WEIGHT_TO_SIGNATURE 1
#define DOWN_WEIGHT_TO_SIGNATURE 10
#define LEFT_WEIGHT_TO_SIGNATURE 100
#define RIGHT_WEIGHT_TO_SIGNATURE 1000


class ManhattanTable: public Table {
public:
    ManhattanTable(size_t sizexy);

    static int getSolutionSignature(int i);
    std::pair<int,int>whereis(int i);
    std::vector<std::pair<int,int>>::const_iterator getElementsBegin();
    std::vector<std::pair<int,int>>::const_iterator getElementsEnd();
    bool addData(int row,int collumn,int dat) override ;
    bool addData(std::pair<int,int> coord,int dat) override ;

    int tableSignature();
    int tr();
    static ManhattanTable makeSignatureTable(int size) ;

    static int getDistanceByCoordinates(std::pair<int,int> point1,std::pair<int,int> point2);
    static ManhattanTable& shuffleTable(ManhattanTable&ref,int moves);
    int getManhattanDistance();

    std::vector<ManhattanTable> possibleMoves();
    ManhattanTable up() throw(std::exception);
    ManhattanTable down() throw(std::exception);
    ManhattanTable left() throw(std::exception);
    ManhattanTable right() throw(std::exception);




private:
    std::vector<std::pair<int,int>> elementpositions;

protected:


    //Make the standard Signature table as described in the beggining of this file





};


#endif //UNTITLED1_MANHATTANTABLE_H
