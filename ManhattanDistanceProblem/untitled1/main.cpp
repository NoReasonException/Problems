#include <iostream>
#include <queue>
#include "Table/ManhattanTable/ManhattanTable.h"
#include "State/State.h"
//it is full of leacked memory , be kind :P
State* solveIt(State *st);
bool compareFunc (State *i,State *j) ;
int main() {
    ManhattanTable t = ManhattanTable(3);
    State *st = new State(ManhattanTable::shuffleTable(t, 100));
    State *finiteState = solveIt(st);
    if (finiteState == nullptr) {
        std::cout << "NO SOLVE"<<std::endl;
    }
    int c = 0;
    std::cout << "MOVE LOG FROM HERE TO END" << std::endl;
    while (finiteState->getPrevState() != nullptr) {
        std::cout << finiteState->debug() << std::endl;
        finiteState = finiteState->getPrevState();
        c += 1;
    }
    std::cout << "SOLVED IN " << c << " MOVES" << std::endl;
    std::cout << "EOF" << std::endl;

}
State* solveIt(State *st){
    bool b= false;
    std::queue<State*> queue;
    queue.push(st);
    while(!queue.empty()){
        st=queue.front();
        queue.pop();
        //std::cout<<st->debug()<<"-------------------------------------"<<std::endl;
        if(st->getStateTable().getManhattanDistance()==0){
            std::cout<<st->getStateTable().tableSignature()<<" SIG "<<std::endl;
            std::cout<<st->getStateTable().getManhattanDistance()<<" MAN DIST "<<std::endl;
            std::cout<<ManhattanTable(st->getStateTable().getTableYSize()).tableSignature()<<" SOLUTION SIG"<<std::endl;
            return st;
        }
        std::vector<State*> possibleStates=st->getNextPossibleStates();
        std::sort(possibleStates.begin(),possibleStates.end(),compareFunc);
        for(State *s:possibleStates){
            queue.emplace(s);
            b=true;
        }
        if(b){
            b= false;
        }
        else{
            std::cout<<"Backtracking"<<std::endl;
        }
    }
    return nullptr;
}
bool compareFunc (State* i,State* j) { return i->getStateTable().getManhattanDistance()<j->getStateTable().getManhattanDistance(); }