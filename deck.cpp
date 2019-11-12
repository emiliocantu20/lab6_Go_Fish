//
// Created by Emilio Cantu on 05/11/2019.
//
#include "card.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstddef>
#include <random>
#include "deck.h"

Deck::Deck(){
    int i = 0;
    int n = 0;
    for(n=1;n<14; n++) {
        myCards[i] = Card{n, Card::spades};
        cout<<myCards[i].toString();
        i++;
    }
    cout<<endl;
    for(n=1; n<14; n++) {
        myCards[i] = Card{n, Card::clubs};
        cout<<myCards[i].toString();
        i++;
    }
    cout<<endl;
    for(n=1; n<14; n++) {
        myCards[i] = Card{n, Card::hearts};
        cout<<myCards[i].toString();
        i++;
    }
    cout<<endl;
    for(n=1; n<14; n++) {
        myCards[i] = Card{n, Card::diamonds};
        cout<<myCards[i].toString();
        i++;
    }
    cout<<endl;
    myIndex = 0;



};
void Deck::shuffle(){
    int i = 0;
    int n = 0;
    int cursor = 0;
    int numCards = 0;
    for(i = 0; i<SIZE; i++){
        numCards++;
    }
    srand(time(nullptr));
    for(i = 0; i<size(); i++){
        for(n = rand()%(numCards*5)+1; n > 0; n--){       //x3 to have a good random margin
             if(cursor == size()){
                cursor = 0;
            }
            cursor ++;
        }
        if(i != cursor && cursor!= size()){
            myCards[i].swap(myCards[cursor]);
        }
    }
}
int  Deck::size() const{
    int i = 0;
    int size = 0;
    for(i = myIndex; i<SIZE; i++){
        size++;
    }
    return size;
}
Card Deck::dealCard(){
    int temp = 0;
    temp = myIndex;
    myIndex ++;
    return myCards[temp];
}