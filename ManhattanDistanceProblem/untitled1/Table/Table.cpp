//
// Created by noreasonexception on 18/10/2018.
//

#include <stdexcept>
#include <sstream>
#include <iostream>
#include "Table.h"

Table::Table(size_t sizex,size_t sizey):
        tableSize_x(sizex),
        tableSize_y(sizey),
        rowOrientedData(std::vector<std::vector<int>>()),
        collumnOrientedData(std::vector<std::vector<int>>()){
    for (int i = 0; i < sizex; ++i) {
            this->rowOrientedData.push_back(std::vector<int>());
            this->collumnOrientedData.push_back(std::vector<int>());
        for (int j = 0; j < sizey; ++j) {
             this->rowOrientedData[i].push_back(0);
             this->collumnOrientedData[i].push_back(0);
        }
    }
}
Table::Table(size_t sizexy) :Table(sizexy,sizexy){}

const std::vector<int>& Table::getRow(int i) const {
    return this->rowOrientedData[i];
}

const std::vector<int> &Table::getCollumn(int i) const {
    return this->collumnOrientedData[i];
}

bool Table::addData(int row, int coll, int dat) {

    this->rowOrientedData[row][coll]=dat;
    this->collumnOrientedData[coll][row]=dat;
    return true;
}
Table Table::operator*(Table &table) {
    if(this->getTableYSize()!= table.getTableXSize())throw std::runtime_error("Tables sizes must agree");
    Table retval(this->getTableXSize(), table.getTableYSize());

    for (int i = 0; i < this->getTableXSize(); ++i) {
        const std::vector<int> &row=this->getRow(i);

        for (int j = 0; j < table.getTableYSize(); ++j) {
            const std::vector<int> &coll=table.getCollumn(j);
            for (int k = 0; k < coll.size(); ++k) {
                retval.addData(i,j,retval.getRow(i)[j]+(row[k]*coll[k]));
            }
        }
    }
    return retval;
}

size_t Table::getTableXSize() const {
    return tableSize_x;
}

size_t Table::getTableYSize() const {
    return tableSize_y;
}

Table Table::makeNeutralTable(int size) {
    Table retval(size);
    for (int i = 0; i < size; ++i) {
        retval.addData(i,i,1);
    }
    return retval;
}
std::string Table::debug() {

    std::ostringstream out;
    for (int i = 0; i < this->getTableXSize(); ++i) {
        for (int j = 0; j < this->getTableYSize(); ++j) {
            out<<"\t"<<this->getRow(i)[j];
        }
        out<<std::endl;
    }
    return out.str();
}

int Table::getData(int row, int coll) {
    return getRow(row)[coll];
}

int Table::getData(std::pair<int, int> coord) {
    return getData(coord.first,coord.second);
}

bool Table::addData(std::pair<int, int> coord, int dat) {
    return addData(coord.first,coord.second,dat);
}
