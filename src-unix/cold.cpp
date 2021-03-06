#include <ctype.h>
#include <sys/types.h>
#include <stdio.h>
#include <syslog.h>
#include "define.h"
#include "struct.h"


index_data cold_index [] = 
{
  { "has no effect on",   "have no effect on",   0 },
  { "cools",              "cool",                7 },
  { "chills",             "chill",              15 },
  { "numbs",              "numbs",              35 },
  { "blisters",           "blister",            50 },
  { "frosts",             "frost",              75 },
  { "FREEZES",            "FREEZE",            100 },
  { "* STIFFENS *",       "* STIFFEN *",       150 },
  { "* HARDENS *",        "* HARDEN *",        200 },
  { "** ICES **",         "** ICE **",         275 },
  { "** SOLIDIFIES **",   "** SOLIDIFY **",    350 },
  { "*** PETRIFIES ***",  "*** PETRIFY ***",    -1 },
};


bool damage_cold( char_data* victim, char_data* ch, int damage,
  const char* string, bool plural )
{
  damage *= 100-victim->Save_Cold( );
  damage /= 100;

  dam_message( victim, ch, damage, string,
    lookup( cold_index, damage, plural ) );
  
  return inflict( victim, ch, damage, "fire" );
}


int obj_data :: vs_cold( )
{
  int save  = 100;
  int    i;

  for( i = 0; i < MAX_MATERIAL; i++ ) 
    if( is_set( &pIndexData->materials, i ) )
      save = min( save, material_table[i].save_cold );

  if( pIndexData->item_type != ITEM_ARMOR 
    || pIndexData->item_type != ITEM_WEAPON ) 
    return save;

  return save+value[0]*(100-save)/(value[0]+2);
}


/*
 *   COLD SPELLS
 */


bool spell_resist_cold( char_data* ch, char_data* victim, void*,
  int level, int duration )
{
  spell_affect( ch, victim, level, duration, SPELL_RESIST_COLD,
    AFF_RESIST_COLD );

  return TRUE;
}


bool spell_chilling_touch( char_data* ch, char_data* victim, void*,
  int level, int )
{
  if( ch == NULL ) {
    bug( "Chilling Touch: NULL caster.", 0 );
    return TRUE;
    }

  damage_cold( victim, ch, spell_damage( SPELL_CHILLING_TOUCH, level ),
    "*the touch of ice" );

  return TRUE; 
}


bool spell_freeze( char_data* ch, char_data* victim, void*, int level, int )
{
  if( null_caster( ch, SPELL_FREEZE ) )
    return TRUE;

  damage_cold( victim, ch, spell_damage( SPELL_FREEZE, level ),
    "*the sphere of cold" );

  return TRUE; 
}


bool spell_ice_storm( char_data* ch, char_data* victim, void*, int level,
  int )
{
  if( null_caster( ch, SPELL_ICE_STORM ) )
    return TRUE;

  damage_cold( victim, ch, spell_damage( SPELL_ICE_STORM, level ),
    "*the icy blast" );

  return TRUE; 
}

bool spell_ice_lance( char_data* ch, char_data* victim, void*, int level,
  int )
{
  if( null_caster( ch, SPELL_ICE_LANCE ) )
    return TRUE;

  damage_cold( victim, ch, spell_damage( SPELL_ICE_LANCE, level ),
    "*the frigid pierce" );

  return TRUE;
}








