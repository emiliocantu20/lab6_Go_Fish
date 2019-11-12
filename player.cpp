//
// Created by Emilio Cantu on 05/11/2019.
//
#include "card.h"
#include "deck.h"
#include "player.h"
#include <time.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <cstddef>
using namespace std;

void Player::addCard(Card c){
    myHand.push_back(c);
}
void Player::bookCards(Card c1, Card c2){
    for(int i =0; i< myHand.size(); i++){
        for(int n = i+1; n<myHand.size(); n++){
            if(myHand[i].getRank() == myHand[n].getRank()&& !(myHand[i].sameSuitAs(myHand[n]))){
                c1 = myHand[i];
                c2 = myHand[n];
                myBook.push_back(removeCardFromHand(c1));
                myBook.push_back(removeCardFromHand(c2));
            }

        }
    }
}
Card Player::chooseCardFromHand() const{
    int i =0;
    int n = 0;
    int max = 0;
    int pair =0;
    int count = 0;
    int rankArr[14]={0};
    int countArr[14]= {0};


    for(i = 0; i < myHand.size(); i++ ){
        for(n = i+1; n < myHand.size(); n++){
                pair = myHand[i].getRank();
                rankArr[i] = pair;
                count ++;
        }
        countArr[i] = count;
        count = 0;
    }
    for(n=0; n<13; n++){
        if(countArr[n+1]> countArr[n]){
            max = n+1;
        }
    }
    return myHand[max];

}
bool Player::cardInHand(Card c) const{
    int i =0;
    for(i = 0; i< myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank()&& !(myHand[i].sameSuitAs(c))){
            return true;
        }
    }
    return false;
}
Card Player::removeCardFromHand(Card c){
    vector<Card>::iterator it;
    Card temp;
    int i =0;
    for(it = myHand.begin(); it != myHand.end(); it++){
        if(myHand[i].getRank() == c.getRank()){ //&& myHand[i].sameSuitAs(c)
            temp = *it;
            myHand.erase(it);
            return temp;
        }
        i++;
    }
    return c;
}
string Player::showHand() const{
    int i = 0;
    string hand;
    for(i = 0; i< myHand.size(); i++){
        hand += myHand[i].toString();
    }
    return hand;
}
string Player::showBooks() const{
    int i = 0;
    string book;
    for(i = 0; i< myBook.size(); i++){
        book += myBook[i].toString();
    }
    return book;
}
int Player::getHandSize() const{
    return myHand.size();
}
int Player::getBookSize() const{
    return myBook.size();
}
bool Player::checkHandForBook(Card &c1, Card &c2){
    return c1 == c2;
}
