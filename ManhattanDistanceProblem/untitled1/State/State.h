//
// Created by noreasonexception on 18/10/2018.
//

#ifndef UNTITLED1_STATE_H
#define UNTITLED1_STATE_H


#include <array>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "../Table/Table.h"
#include "../Table/ManhattanTable/ManhattanTable.h"
#include "errors/AlreadyVisitedException.h"
#include <memory>
/***
 * This is the Class State
 * A simple , thin wrapper over ManhattanTable , the only service provided , is the subscription mechanism
 * and the guarantee that we will dont repeat the same move again (using a shared_ptr we pass around a unordered map)
 */
class State {
    private:
        ManhattanTable stateTable;                              //the current table representing the state
        State          *prevState;
        std::shared_ptr<std::unordered_map<int,int>> map_ptr;  //the ptr to the unordered_map
    public:
        State(ManhattanTable& stateInformation);
        State(State *prevstate,ManhattanTable& stateInformation,std::shared_ptr<std::unordered_map<int,int>> map);
        bool isSolved();                                        //check if the table signature is the same with solution table
        std::vector<State*> getNextPossibleStates() throw(AlreadyVisitedException);
        std::string debug();

        ManhattanTable &getStateTable();

    State *getPrevState();

protected:
        int                getManhattanDistance();

};


#endif //UNTITLED1_STATE_H
