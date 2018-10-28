//
// Created by noreasonexception on 19/10/2018.
//

#include <iostream>

#include "ManhattanTable.h"



ManhattanTable::ManhattanTable(size_t sizexy) : Table(sizexy) {
    int c=1;
    for (int i = 0; i < sizexy; ++i) {
        for (int j = 0; j < sizexy; ++j) {
            elementpositions.push_back(std::pair<int,int>(i,j));
            Table::addData(i,j,c++);
        }
    }
    Table::addData(sizexy-1,sizexy-1,0);

    elementpositions.insert(elementpositions.begin(),std::pair<int,int>(sizexy-1,sizexy-1));
    elementpositions.erase(elementpositions.end());
}

bool ManhattanTable::addData(int row, int collumn, int dat) {
    bool retval;
    if((retval=Table::addData(row,collumn,dat))){
        std::pair<int,int> pair(row,collumn);
        //TODO is fucking slow , fix it, problem? std::vector maybe isnt Assignable and for
                ///TODO : This case the std::pair<int,int> assigment constructor is deleted!
        elementpositions.erase(elementpositions.begin()+dat);
        elementpositions.insert(elementpositions.begin()+dat,pair);
    }
    return retval;
}

bool ManhattanTable::addData(std::pair<int, int> coord, int dat) {
    return ManhattanTable::addData(coord.first,coord.second, dat);
}

std::pair<int, int> ManhattanTable::whereis(int i) {
    return elementpositions[i];
}

int ManhattanTable::getSolutionSignature(int size) {
    ManhattanTable solutionTable=ManhattanTable(size);
    return solutionTable.tableSignature();
}

ManhattanTable ManhattanTable::makeSignatureTable(int size) {
    ManhattanTable retval(size);
    int c=1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            retval.addData(i,j,c++);
        }
    }
    return retval;
}

int ManhattanTable::tableSignature(){
    int c=0;
    //because of [rl]values ;P
    ManhattanTable  sigtable=ManhattanTable::makeSignatureTable(this->getTableYSize());
    Table&ref=sigtable;
    Table signatureTable=this->operator*(ref);
    for (int i = 0; i < signatureTable.getTableXSize(); ++i) {
        for (int j = 0; j < signatureTable.getTableYSize(); ++j) {
            c+=signatureTable.getRow(i)[j];
        }
    }
    return tr()*c;
}

std::vector<std::pair<int, int>>::const_iterator ManhattanTable::getElementsBegin() {
    return this->elementpositions.cbegin();
}

std::vector<std::pair<int, int>>::const_iterator ManhattanTable::getElementsEnd() {
    return this->elementpositions.cend();
}

int ManhattanTable::getDistanceByCoordinates(std::pair<int, int> point1, std::pair<int, int> point2) {
    int xdistance=std::max(abs(point1.first),abs(point2.first))-
            std::min(abs(point1.first),abs(point1.first));
    int ydistance=std::max(abs(point1.second),abs(point2.second))-
            std::min(abs(point1.second),abs(point1.second));
    return xdistance+ydistance;
}

int ManhattanTable::getManhattanDistance() {
    int retvalCounter=0;
    //TODO make a const solution table as static , get by o(1)
    ManhattanTable solutiontemp=ManhattanTable(this->getTableYSize());
    auto solutionElementsBegin=solutiontemp.getElementsBegin();
    auto solutionElementsEnd=solutiontemp.getElementsEnd();

    auto thisTableElementsBegin=this->getElementsBegin();
    auto thisTableElementsEnd=this->getElementsEnd();
    for (;solutionElementsBegin<solutionElementsEnd
            &&thisTableElementsBegin<thisTableElementsEnd;
          (solutionElementsBegin++,
            thisTableElementsBegin++)) {
        retvalCounter+=ManhattanTable::getDistanceByCoordinates(*solutionElementsBegin,*thisTableElementsBegin);

    }
    return retvalCounter;
}

std::vector<ManhattanTable> ManhattanTable::possibleMoves() {
    std::vector<ManhattanTable>retval;
    //may use nullptr here? is looks terrible with all those try's
    try {retval.push_back(this->up());}catch(std::exception&e) {;}
    try {retval.push_back(this->down());}catch(std::exception&e) {;}
    try {retval.push_back(this->right());}catch(std::exception&e) {;}
    try {retval.push_back(this->left());}catch(std::exception&e) {;}
    return retval;


}

ManhattanTable ManhattanTable::up() throw(std::exception) {
    if(whereis(0).first==TABLE_START)throw std::exception();

    std::pair<int,int> zeroLocation=whereis(0);
    std::pair<int,int> swapElementLocation=
            std::pair<int,int>(whereis(0).first-1,whereis(0).second); //TODO terrible , refactor that!
    int swapElement=getData(swapElementLocation);
    ManhattanTable upMoveTable=*this;//TODO:optimise copy constructors to perform lazy copy
    upMoveTable.addData(swapElementLocation,0);
    upMoveTable.addData(zeroLocation,swapElement);
    return upMoveTable;

}
//TODO so much duplication -> consider using lamda expression instead of this mess..!
ManhattanTable ManhattanTable::down() throw (std::exception){
    if(whereis(0).first==TABLE_END_X)throw std::exception();

    std::pair<int,int> zeroLocation=whereis(0);
    std::pair<int,int> swapElementLocation=
            std::pair<int,int>(whereis(0).first+1,whereis(0).second); //TODO terrible , refactor that!
    int swapElement=getData(swapElementLocation);
    ManhattanTable downMoveTable=*this;//TODO:optimise copy constructors to perform lazy copy
    downMoveTable.addData(swapElementLocation,0);
    downMoveTable.addData(zeroLocation,swapElement);
    return downMoveTable;
}
//TODO so much duplication -> consider using lamda expression instead of this mess..!
ManhattanTable ManhattanTable::left() throw(std::exception){
    if(whereis(0).second==TABLE_START)throw std::exception();

    std::pair<int,int> zeroLocation=whereis(0);
    std::pair<int,int> swapElementLocation=
            std::pair<int,int>(whereis(0).first,whereis(0).second-1); //TODO terrible , refactor that!
    int swapElement=getData(swapElementLocation);
    ManhattanTable leftMoveTable=*this;//TODO:optimise copy constructors to perform lazy copy
    leftMoveTable.addData(swapElementLocation,0);
    leftMoveTable.addData(zeroLocation,swapElement);
    return leftMoveTable;
}
//TODO so much duplication -> consider using lamda expression instead of this mess..!
ManhattanTable ManhattanTable::right() throw(std::exception){
    if(whereis(0).second==TABLE_END_Y)throw std::exception();

    std::pair<int,int> zeroLocation=whereis(0);
    std::pair<int,int> swapElementLocation=
            std::pair<int,int>(whereis(0).first,whereis(0).second+1); //TODO terrible , refactor that!
    int swapElement=getData(swapElementLocation);
    ManhattanTable rightMoveTable=*this;//TODO:optimise copy constructors to perform lazy copy
    rightMoveTable.addData(swapElementLocation,0);
    rightMoveTable.addData(zeroLocation,swapElement);
    return rightMoveTable;
}

ManhattanTable &ManhattanTable::shuffleTable(ManhattanTable &ref,int moves) {

    for (int i = 0; i <moves; ++i) {
        try{
            switch (abs(rand())%4){
                case 0:ref=ref.up();
                    break;
                case 1:ref=ref.down();
                    break;
                case 2:ref=ref.right();
                    break;
                case 3:ref=ref.left();
                    break;
            }
        }catch (std::exception&e){
        }
    }
    return ref;
}

int ManhattanTable::tr() {
    int c=0;
    for (int i = 0; i < getTableYSize(); ++i){
        c+=getData(i,i);
    }
    return c;
}

