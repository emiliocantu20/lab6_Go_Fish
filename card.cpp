//
// Created by Emilio Cantu on 05/11/2019.
//
#include <iostream>
#include <string>
#include "card.h"
using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

int Card::getRank() const {
    return myRank;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const{

    if(myRank == 1){ return rankString(myRank)+suitString(mySuit);}
    if(myRank == 2){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 3){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 4){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 5){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 6){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 7){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 8){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 9){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 10){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 11){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 12){return rankString(myRank)+suitString(mySuit);}
    if(myRank == 13){return rankString(myRank)+suitString(mySuit);}
    else{
        return "incorrect rank";
    }
}

string Card::suitString(Suit s) const{
    switch(s){
        case spades:
            return "s";
            break;
        case hearts:
            return "h";
            break;
        case diamonds:
            return "d";
            break;
        case clubs:
            return "c";
            break;
    }
    return "null";
}

bool Card::sameSuitAs(const Card& c) const{
    return c.mySuit == mySuit;
}

string Card::rankString(int r) const{
    if(myRank == 1){return "A";}
    if(myRank == 2){return "2";}
    if(myRank == 3){return "3";}
    if(myRank == 4){return "4";}
    if(myRank == 5){return "5";}
    if(myRank == 6){return "6";}
    if(myRank == 7){return "7";}
    if(myRank == 8){return "8";}
    if(myRank == 9){return "9";}
    if(myRank == 10){return "10";}
    if(myRank == 11){return "J";}
    if(myRank == 12){return "Q";}
    if(myRank == 13){return "K";}
}
bool Card::operator == (const Card& rhs) const{
    return ( myRank == rhs.myRank);                             //mySuit == rhs.mySuit ||

}
bool Card::operator != (const Card& rhs) const{
    return myRank != rhs.myRank;                            //mySuit == rhs.mySuit ||

}
void Card::swap(Card &c)                //Credit to Professor Priebe
{
    Card temp = c;
    c = *this;
    *this = temp;
}