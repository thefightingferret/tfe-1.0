#include "define.h"
#include "struct.h"


flag_data align_flags = { "Alignment", &alignment_table[0].name,
  &alignment_table[1].name, &MAX_ENTRY_ALIGNMENT };

flag_data abv_align_flags = { "Alignment", &alignment_table[0].abbrev,
  &alignment_table[1].abbrev, &MAX_ENTRY_ALIGNMENT };

/*
void do_alignment( char_data* ch, char* argument )
{
  int i;

  if( is_mob( ch ) )
    return;
 
  i = ch->shdata->alignment;

  class type_field type = 
    { "alignment", MAX_ALIGNMENT, &alignment_name[0], &alignment_name[1],
      &i  };

  type.set( ch, "you", argument );

  if( !is_set( &clss_table[ ch->pcdata->clss ].alignments, i ) ) {
    send( ch, "Your class does not allow that alignment.\r\n" );
    return;
    }

  if( ch->shdata->race < MAX_PLYR_RACE 
    && !is_set( &plyr_race_table[ ch->shdata->race ].alignments, i ) ) {
    send( ch, "Your race does not allow that alignment.\r\n" );
    return;
    }

  ch->shdata->alignment = i;

  return;
}
*/






