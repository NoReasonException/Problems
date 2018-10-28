//
// Created by noreasonexception on 18/10/2018.
//

#ifndef UNTITLED1_TABLE_H
#define UNTITLED1_TABLE_H


#include <glob.h>
#include <vector>
/***
 * Hashing technique
 * Multiply table by the table below
 * [1 2 3
 *  4 5 6
 *  7 8 9]
 *  After that , add every collumn
 */
class Table {
private:
    size_t  tableSize_x;
    size_t  tableSize_y;
    std::vector<std::vector<int>> rowOrientedData;
    std::vector<std::vector<int>> collumnOrientedData;


    //-----------------utills------------------------

public:
    Table(size_t sizex,size_t sizey);
    Table(size_t sizexy);


    //Make a table who has the property AB=A
    static Table makeNeutralTable(int i) ;



    //----------------------------Getter-Setter Section
    size_t getTableXSize() const;

    size_t getTableYSize() const;

    // get per row and per collumn
    const std::vector<int>& getRow(int i) const ;
    const std::vector<int>& getCollumn(int i)const;
    //-----------------------add data into structure
    virtual bool  addData(int row,int coll,int dat);
    virtual bool  addData(std::pair<int,int> coord,int dat);
    virtual int  getData(int row,int coll);
    virtual int  getData(std::pair<int,int> coord);
    virtual Table operator*(Table& table);//Standard Matrix Multiplication
    std::string debug();

};


#endif //UNTITLED1_TABLE_H
