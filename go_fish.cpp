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
void dealCards(Player p, Deck deck);
int main() {

    ofstream myfile;
    myfile.open("go_fish.txt");
    int i = 0;
    int x = 0;
    int y = 0;
    bool yes = true;
    Card temp1;
    Card temp2;
    Player player1("Emilio");
    Player player2("Diego");
    Deck myDeck;
    myDeck.shuffle();
    myDeck.shuffle();
    myDeck.shuffle();
    myDeck.shuffle();
    myDeck.shuffle();

    for (i = 0; i < 7; i++) {                            //Deal cards
        player1.addCard(myDeck.dealCard());
        player1.bookCards(temp1, temp2);
    }

    myfile << player1.showBooks() << endl;
    myfile << player1.showHand() << endl;

    for (i = 0; i < 7; i++) {
        player2.addCard(myDeck.dealCard());
        player2.bookCards(temp1, temp2);
    }

    myfile << player2.showBooks() << endl;
    myfile << player2.showHand() << endl;

    while (myDeck.size() > 0) {// && player1.getHandSize()!=0 && player2.getHandSize()!=0){

        //PLAYER 1 TURN//////

        if (player1.getHandSize() == 0) {
            dealCards(player1, myDeck);
        } else {
            temp1 = player1.chooseCardFromHand();
            myfile << player1.getName() << " asks -Do you have a(n) "
                 << temp1.rankString(temp1.getRank())<< "?"
                 << endl;        //Player 1 TURN
            if (player2.cardInHand(temp1)) {
                myfile << player2.getName() << "- Yes, I have a(n) "
                     << temp1.rankString(temp1.getRank()) << endl;
                temp2 = player2.removeCardFromHand(temp1);
                player1.addCard(temp2);
                player1.bookCards(temp1, temp2);
                myfile << player1.getName() << "'s hand: " << player1.showHand() << endl;
                myfile << player1.getName() << "'s book: " << player1.showBooks() << endl;
            } else {
                myfile << "Go Fish!" << endl;
                player1.addCard(myDeck.dealCard());
                player1.bookCards(temp1, temp2);
            }
        }


        //PLAYER 2 TURN//

        if (player1.getHandSize() == 0) {
            dealCards(player1, myDeck);
        } else {
            temp1 = player2.chooseCardFromHand();
            myfile << player2.getName() << " asks- Do you have a(n) "
                 << temp1.rankString(temp1.getRank())<< "?"
                 << endl;        //Player 2 TURN
            if (player1.cardInHand(temp1)) {
                myfile << player1.getName() << "- Yes, I have a(n) "
                     << temp1.rankString(temp1.getRank()) << endl;
                temp2 = player1.removeCardFromHand(temp1);
                player2.addCard(temp2);
                player2.bookCards(temp1, temp2);
                myfile << player2.getName() << "'s hand: " << player2.showHand() << endl;
                myfile << player2.getName() << "'s book: " << player2.showBooks() << endl;
            } else {
                myfile << "Go Fish!" << endl;
                player2.addCard(myDeck.dealCard());
                player2.bookCards(temp1, temp2);
            }
        }
    }


    while (player1.getHandSize() != 0 && player2.getHandSize() != 0) {

        temp1 = player1.chooseCardFromHand();
        myfile << player1.getName() << " asks -Do you have a(n) "
             << temp1.rankString(temp1.getRank())<< "?"
             << endl;        //Player 1 TURN
        player2.cardInHand(temp1);
        myfile << player2.getName() << "- Yes, I have a(n) "
             << temp1.rankString(temp1.getRank())<< endl;
        temp2 = player2.removeCardFromHand(temp1);
        player1.addCard(temp2);
        player1.bookCards(temp1, temp2);
        myfile << player1.getName() << "'s hand: " << player1.showHand() << endl;
        myfile << player1.getName() << "'s book: " << player1.showBooks() << endl;

        temp1 = player2.chooseCardFromHand();
        myfile << player2.getName() << " asks- Do you have a(n) "
             << temp1.rankString(temp1.getRank())<< "?"
             << endl;        //Player 2 TURN
        player1.cardInHand(temp1);
        myfile << player1.getName() << "- Yes, I have a(n) "
             << temp1.rankString(temp1.getRank())<< endl;
        temp2 = player1.removeCardFromHand(temp1);
        player2.addCard(temp2);
        player2.bookCards(temp1, temp2);
        myfile << player2.getName() << "'s hand: " << player2.showHand() << endl;
        myfile << player2.getName() << "'s book: " << player2.showBooks() << endl;
    }

    if (player1.getBookSize() > player2.getBookSize()) {
        myfile << player1.getName() << "'s book: " << player1.showBooks() << endl;
        myfile << player2.getName() << "'s book: " << player2.showBooks() << endl;
        myfile << player1.getName() << " is the WINNER with " << player1.getBookSize() / 2 << " pairs!" << endl;
        myfile<<player1.getBookSize()<<endl;
        myfile<<player2.getBookSize()<<endl;
        myfile.close();
        exit(0);
    }if(player1.getBookSize() == player2.getBookSize()){
        myfile << player1.getName() << "'s book: " << player1.showBooks() << endl;
        myfile << player2.getName() << "'s book: " << player2.showBooks() << endl;
        myfile << "Draw!"<<endl;
        myfile<<player1.getBookSize()<<endl;
        myfile<<player2.getBookSize()<<endl;
        myfile.close();
        exit(0);
    }else {
        myfile << player1.getName() << "'s book: " << player1.showBooks() << endl;
        myfile << player2.getName() << "'s book: " << player2.showBooks() << endl;
        myfile << player2.getName() << " is the WINNER with " << player2.getBookSize() / 2 << " pairs!" << endl;
        myfile<<player1.getBookSize()<<endl;
        myfile<<player2.getBookSize()<<endl;
        myfile.close();
        exit(0);

    }

}
void dealCards(Player p, Deck deck) {
    for (int i = 0; i < 7; i++) {
        if (deck.size() == 0) {
            return;
        }
        p.addCard(deck.dealCard());
    }
}