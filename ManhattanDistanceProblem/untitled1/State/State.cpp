//
// Created by noreasonexception on 18/10/2018.
//

#include <iostream>
#include "State.h"
#include "../Table/ManhattanTable/ManhattanTable.h"

State::State(ManhattanTable& stateInformation):State(nullptr,stateInformation,std::make_shared<std::unordered_map<int,int>>()){

}

State::State(State *pstate,ManhattanTable &stateInformation, std::shared_ptr<std::unordered_map<int, int>> map):
        stateTable(stateInformation), map_ptr(map),prevState(pstate) {


}
std::vector<State*> State::getNextPossibleStates() throw(AlreadyVisitedException){
    //why we declare here that we have visited the node? because if we do it on ctor , the solution
    //will subscribed as 'already visited' preventing the algorithm from solve the problem!
    map_ptr->emplace(std::pair<int,bool>(stateTable.tableSignature()*
                                         ((prevState)?prevState->stateTable.tableSignature():1)*
                                                 (((prevState)&&(prevState->prevState))?prevState->prevState->stateTable.tableSignature():1),1));
    auto b=map_ptr->find(stateTable.tableSignature());
    //if(b!=map_ptr->end())std::cout<<"Subscribed "<<b->first;
    ///---end of subscription
    std::vector<State*> retval;
    std::vector<ManhattanTable> possibleMoves=stateTable.possibleMoves();
    if(possibleMoves.empty())throw AlreadyVisitedException();// we stuck :/
    for (auto c=possibleMoves.begin();c<possibleMoves.end();c++) {
        b=map_ptr->find((*c).tableSignature()*(stateTable.tableSignature())*((prevState)?prevState->stateTable.tableSignature():1));
        //retval.push_back(new State(this, *c, map_ptr));

        if(b==map_ptr->end()) {
            retval.push_back(new State(this, *c, map_ptr));
        }/*
        else if((*b).second<5){
            (*b).second+=1;
            retval.push_back(new State(this,*c,map_ptr));
        }*/
    }
    return retval;
}

std::string State::debug() {
    return stateTable.debug();
}

ManhattanTable &State::getStateTable() {
    return stateTable;
}

State *State::getPrevState() {
    return prevState;
}
