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
        checkSeahag(p, &G)
        
int checkSeahag(int p, struct gameState *post) {
  struct gameState pre;
  //force an adventure card onto top of deck
  memcpy (&pre, post, sizeof(struct gameState));
  //check other players deck for presence of curse
  cardEffect(sea_hag, 0,0,0, &post, 0, 0);
  //create variable to hold number of coins player currently holds
  if( p == 0 ){
    while(i < MAX_HAND) {
      if(post.hand[p+1][i] == curse)
        r = 1;
      else
        i++;
  else( if p == 1 ){
    while(i < MAX_HAND) {
      if(post.hand[p-1][i] == curse)
        r = 1;
      else
        i++;
  int r;
  
  //call cardEffect to transform post game state
  r = playCard(MAX_HAND, 0, 0, 0, post);
  //assume the worst case scenario...that two copper treasures were pulled during the search
  if(post.coins[p] >= coinsBefore + 2 && post.coins <= coinsBefore + 6) {
    printf("Test Passed.\n");
   }
  
