*/ 
**Author: Brock Neidert
**Date: 11/14/2018
**Description: This is a random test for the adventurer card (Dominion)
/*

// The code below was adapted/modified from the test code sample provided in the week 4 materials

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
//add in time.h to allow for psuedo random number generation
#include <time.h>

//variable TESTCARD will reflect card being tested (adventurer in this case)
#define TESTCARD "adventurer"


//when played, adventurer allows the player to discard cards in their hand until they find (2) treasure 
//cards.  the end result should be an increase in the player's available coins.  at the high end, this 
//means an increase of (6) coins while at the low end, this card will only incrase players available coin by(2)

int main() {

    int i, n, r, p, deckCount, discardCount, handCount;
    
	  struct gameState G;
    
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};

	  // initialize a game state and player cards
	  initializeGame(numPlayers, k, seed, &G);
    SelectStream(2);
    PutSeed(3);
    
//this code was used in the random testing (part 1) lecture and adapted into this code module
    for(n = 0; n < 20000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
	checkAdventure(p, &G);
        
int checkAdventurer(int p, struct gameState *post) {
  struct gameState pre;
  //force an adventure card onto top of deck
  post.hand[p][MAX_HAND] = k[1];
  memcpy (&pre, post, sizeof(struct gameState));
  
  //create variable to hold number of coins player currently holds
  int coinsBefore;
  coinsBefore = updateCoins(p, pre, 0);
  
  int r;
  
  //call cardEffect to transform post game state
  r = playCard(MAX_HAND, 0, 0, 0, post);
  //assume the worst case scenario...that two copper treasures were pulled during the search
  if(post.coins[p] >= coinsBefore + 2 && post.coins <= coinsBefore + 6) {
    printf("Test Passed.\n");
   }
  
