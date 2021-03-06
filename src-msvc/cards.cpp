#include "define.h"
#include "struct.h"


const char* suit_name [] = {
  "Spades", "Hearts", "Diamonds", "Clubs" };

const char* cards = "AKQJT98765432";


void look_cards( char_data* ch, obj_data* deck )
{
  char      tmp  [ TWO_LINES ];
  int      suit;
  int      card;
  char*  letter;

  send( "A stack of cards contains\r\n\r\n", ch );

  for( suit = 0; suit < 4; suit++ ) {
    sprintf( tmp, "%10s: ", suit_name[suit] );
    letter = &tmp[12];
    for( card = 0; card < 13; card++ ) 
      if( is_set( deck->value, 13*suit+card ) )
        *letter++ = cards[card];
    strcat( letter, "\r\n" );
    send( tmp, ch );
    } 

  return;       
}
