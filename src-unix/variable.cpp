#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include "define.h"
#include "struct.h"


/*
 *   COMMANDS
 */


class command_ident
{
 public:
  const char*      name;
  do_func*     function;
};


command_ident command_list [] =
{
  { "-",           do_avatar     },
  { "'",           do_say        },       
  { ":",           do_buildchan  }, 
  { "]",           do_immtalk    },   
  { "}",           do_god        },       
  { "accounts",    do_accounts   },
  { "allegiance",  do_allegiance },
  { "ask",         do_ask        },       
  { "auction",     do_auction    },  
  { "atalk",       do_atalk      }, 
  { "berserk",     do_berserk    },
  { "bid",         do_bid        },
  { "bite",        do_bite       },
  { "build",       do_build      },
  { "bury",        do_bury       },
  { "buy",         do_buy        },       
  { "calculate",   do_calculate  },
  { "cedit",       do_cedit      }, 
  { "changes",     do_changes    },
  { "chant",       do_chant      },     
  { "chat",        do_chat       },      
  { "clans",       do_clans      },
  { "close",       do_close      },    
  { "configure",   do_configure  },
  { "consent",     do_consent    },
  { "cook",        do_cook       },
  { "ctell",       do_ctell      },
  { "custom",      do_custom     },    
  { "define",      do_define     },
  { "dig",         do_dig        },
  { "dip",         do_dip        },
  { "disguise",    do_disguise   },
  { "dismount",    do_dismount   },
  { "down",        do_down       },
  { "drink",       do_drink      },    
  { "drop",        do_drop       },     
  { "east",        do_east       },
  { "emote",       do_emote      },     
  { "empty",       do_empty      },    
  { "enter",       do_enter      },
  { "equipment",   do_equipment  },
  { "exits",       do_exits      },
  { "exp",         do_exp        },
  { "extract",     do_extract    },
  { "filter",      do_filter     },    
  { "garotte",     do_garrote    },
  { "get",         do_get        },      
  { "give",        do_give       },  
  { "gossip",      do_gossip     },    
  { "gouge",       do_gouge      },
  { "grab",        do_wear       },     
  { "gtell",       do_gtell      },     
  { "hbug",        do_hbug       },    
  { "homepage",    do_homepage   },
  { "identity",    do_identity   },  
  { "iflag",       do_iflag      },     
  { "ignite",      do_ignite     },
  { "index",       do_index      },     
  { "info",        do_info       },      
  { "introduce",   do_introduce  }, 
  { "kick",        do_kick       },       
  { "kill",        do_kill       },       
  { "knock",       do_knock      },
  { "label",       do_label      },
  { "language",    do_language   },  
  { "ledit",       do_ledit      },
  { "lie",         do_lie        },
  { "list",        do_list       },      
  { "load",        do_load       },
  { "lset",        do_lset       },      
  { "lstat",       do_lstat      },
  { "marmor",      do_marmor     },
  { "mdesc",       do_mdesc      }, 
  { "medit",       do_medit      },
  { "meditate",    do_meditate   },  
  { "melt",        do_melt       },      
  { "melee",       do_melee      },
  { "message",     do_message    },
  { "mfind",       do_mfind      },
  { "mflag",       do_mflag      },
  { "mload",       do_mload      },
  { "mlog",        do_mlog       }, 
  { "mount",       do_mount      },     
  { "mpflag",      do_mpflag     },
  { "mreset",      do_mreset     },
  { "mset",        do_mset       },
  { "mstat",       do_mstat      }, 
  { "mwhere",      do_mwhere     },  
  { "north",       do_north      },     
  { "ooc",         do_ooc        },
  { "pbug",        do_pbug       },
  { "purchase",    do_purchase   }, 
  { "pray",        do_pray       },      
  { "prompt",      do_prompt     },
  { "ps",          do_ps         },
  { "qstat",       do_qstat      },
  { "repair",      do_repair     },    
  { "reply",       do_reply      },     
  { "reset",       do_reset      },    
  { "rest",        do_rest       },      
  { "reboot",      do_reboot     },
  { "rename",      do_rename     },    
  { "request",     do_request    },
  { "review",      do_review     },
  { "rmwhere",     do_rmwhere    },   
  { "roomlist",    do_roomlist   },
  { "rtable",      do_rtable     },
  { "rtwhere",     do_rtwhere    },
  { "say",         do_say        },       
  { "sell",        do_sell       },      
  { "shout",       do_shout      },     
  { "sit",         do_sit        },       
  { "sleep",       do_sleep      },     
  { "smoke",       do_smoke      },
  { "south",       do_south      },     
  { "split",       do_split      },
  { "stand",       do_stand      },     
  { "tell",        do_tell       },      
  { "to",          do_to         },
  { "typo",        do_typo       },
  { "up",          do_up         },        
  { "value",       do_value      },     
  { "vote",        do_vote       },
  { "wake",        do_wake       },      
  { "wear",        do_wear       },     
  { "west",        do_west       },      
  { "whisper",     do_whisper    },
  { "wield",       do_wear       },     
  { "yell",        do_yell       },      

  { "relations",   do_relations  }, 
  { "eat",         do_eat        },      
  { "fill",        do_fill       },     
  { "hold",        do_wear       },     
  { "inventory",   do_inventory  },
  { "junk",        do_junk       },     
  { "lock",        do_lock       },     
  { "open",        do_open       },     
  { "pick",        do_pick       },     
  { "put",         do_put        },      
  { "quaff",       do_quaff      },    
  { "remove",      do_remove     },   
  { "sacrifice",   do_sacrifice  },
  { "unlock",      do_unlock     },   
  { "assist",      do_assist     },     
  { "backstab",    do_backstab   },   
  { "bash",        do_bash       },      
  { "camouflage",  do_camouflage },
  { "charge",      do_charge     }, 
  { "consider",    do_consider   },   
  { "disarm",      do_disarm     },     
  { "flee",        do_flee       },       
  { "glance",      do_glance     },     
  { "punch",       do_punch      },      
  { "rescue",      do_rescue     },     
  { "shoot",       do_shoot      },      
  { "spin",        do_spin_kick  },  
  { "throw",       do_throw      },      
  { "wimpy",       do_wimpy      },      
  { "cast",        do_cast       },      
  { "focus",       do_focus      },     
  { "leech",       do_leech      },     
  { "polymorph",   do_polymorph  }, 
  { "prepare",     do_prepare    },   
  { "probe",       do_probe      },     
  { "recite",      do_recite     },    
  { "spells",      do_spells     },    
  { "sweep",       do_sweep      },     
  { "switch",      do_switch     },    
  { "return",      do_return     },    
  { "zap",         do_zap        },       
  { "alias",       do_alias      },     
  { "appearance",  do_appearance },
  { "areas",       do_areas      },     
  { "befriend",    do_befriend   },  
  { "commands",    do_commands   },  
  { "compare",     do_compare    },   
  { "color",       do_color      },     
  { "description", do_descript   },  
  { "help",        do_help       },      
  { "keywords",    do_keywords   },  
  { "last",        do_last       },      
  { "look",        do_look       },      
  { "motd",        do_motd       },      
  { "options",     do_options    },   
  { "peek",        do_peek       },      
  { "pets",        do_pets       },      
  { "qlook",       do_qlook      },     
  { "quests",      do_quests     },    
  { "qwho",        do_qwho       },      
  { "reputation",  do_reputation },
  { "score",       do_score      },     
  { "socials",     do_socials    },   
  { "statistics",  do_statistics },
  { "time",        do_time       },      
  { "who",         do_who        },       
  { "whois",       do_whois      },     
  { "mail",        do_mail       },      
  { "notes",       do_notes      },     
  { "title",       do_title      },     
  { "follow",      do_follow     },  
  { "group",       do_group      },
  { "name",        do_name       }, 
  { "order",       do_order      },
  { "delete",      do_delete     },    
  { "password",    do_password   },  
  { "quit",        do_quit       },      
  { "save",        do_save       },      
  { "balance",     do_balance    },   
  { "deposit",     do_deposit    },   
  { "withdraw",    do_withdraw   },  
  { "abilities",   do_abilities  }, 
  { "appraise",    do_appraise   },  
  { "bandage",     do_bandage    },   
  { "climb",       do_climb      },     
  { "hands",       do_hands      },      
  { "hide",        do_hide       },       
  { "inspect",     do_inspect    },    
  { "practice",    do_practice   },   
  { "scan",        do_scan       },       
  { "search",      do_search     },     
  { "skin",        do_skin       },       
  { "skills",      do_skills     },     
  { "sneak",       do_sneak      },      
  { "steal",       do_steal      },      
  { "heist",       do_heist      },
  { "energize",    do_energize   },
  { "track",       do_track      },      
  { "untrap",      do_untrap     },     
  { "advance",     do_advance    },   
  { "approve",     do_approve    },   
  { "ban",         do_ban        },       
  { "beep",        do_beep       },      
  { "bamfin",      do_bamfin     },    
  { "bamfout",     do_bamfout    },   
  { "bugs",        do_bugs       },      
  { "disconnect",  do_disconnect },
  { "identify",    do_identify   },  
  { "pardon",      do_pardon     },    
  { "reimburse",   do_reimburse  }, 
  { "where",       do_where      },     
  { "tedit",       do_tedit      },     
  { "tset",        do_tset       },     
  { "tstat",       do_tstat      },       
  { "dedit",       do_dedit      },       
  { "dflag",       do_dflag      },       
  { "dset",        do_dset       },        
  { "dstat",       do_dstat      },       
  { "rbug",        do_rbug       },        
  { "redit",       do_redit      },       
  { "rdesc",       do_rdesc      },       
  { "rflag",       do_rflag      },       
  { "rlog",        do_rlog       },        
  { "rname",       do_rname      },       
  { "rset",        do_rset       },        
  { "rstat",       do_rstat      },       
  { "odesc",       do_odesc      },   
  { "oedit",       do_oedit      },   
  { "oextra",      do_oextra     },  
  { "ofind",       do_ofind      },   
  { "oflag",       do_oflag      },   
  { "oload",       do_oload      },   
  { "olog",        do_olog       },    
  { "oset",        do_oset       },    
  { "ostat",       do_ostat      },   
  { "owhere",      do_owhere     },  
  { "opedit",      do_opedit     },  
  { "opcode",      do_opcode     },  
  { "opdata",      do_opdata     },  
  { "opstat",      do_opstat     },  
  { "opset",       do_opset      },   
  { "hdesc",       do_hdesc      },   
  { "hedit",       do_hedit      },   
  { "hset",        do_hset       },    
  { "acode",       do_acode      },   
  { "adata",       do_adata      },   
  { "aedit",       do_aedit      },   
  { "aflag",       do_aflag      },   
  { "aset",        do_aset       },    
  { "astat",       do_astat      },   
  { "mpedit",      do_mpedit     },  
  { "mpcode",      do_mpcode     },  
  { "mpdata",      do_mpdata     },  
  { "mpstat",      do_mpstat     },  
  { "mpset",       do_mpset      },   
  { "cflag",       do_cflag      },   
  { "qedit",       do_qedit      },   
  { "qremove",     do_qremove    }, 
  { "qset",        do_qset       },    
  { "qwhere",      do_qwhere     },  
  { "shcustom",    do_shcustom   },
  { "shedit",      do_shedit     },  
  { "shflag",      do_shflag     },    
  { "affects",     do_affects    },   
  { "high",        do_high       },      
  { "level",       do_level      },     
  { "memory",      do_memory     },    
  { "move",        do_move       },      
  { "pull",        do_pull       },      
  { "push",        do_push       },      
  { "read",        do_read       },      
  { "system",      do_system     },    
  { "wanted",      do_wanted     },    
  { "whistle",     do_whistle    },   
  { "functions",   do_functions  },
  { "return",      do_return     },   
  { "deny",        do_deny       },     
  { "echo",        do_echo       },     
  { "force",       do_force      },    
  { "freeze",      do_freeze     },   
  { "god",         do_god        },      
  { "goto",        do_goto       },     
  { "holylight",   do_holylight  },
  { "immtalk",     do_immtalk    },  
  { "imprison",    do_imprison   }, 
  { "invis",       do_invis      },    
  { "lag",         do_lag        },      
  { "map",         do_map        },      
  { "peace",       do_peace      },    
  { "purge",       do_purge      },    
  { "recho",       do_recho      },    
  { "restore",     do_restore    },  
  { "rowhere",     do_rowhere    },  
  { "shutdown",    do_shutdown   }, 
  { "snoop",       do_snoop      },    
  { "slay",        do_slay       },     
  { "sset",        do_sset       },     
  { "tfind",       do_tfind      },    
  { "train",       do_train      },    
  { "transfer",    do_transfer   }, 
  { "trust",       do_trust      },    
  { "users",       do_users      },    
  { "wizlock",     do_wizlock    },  
  { "write",       do_write      },    
  { "",            NULL          }
};


void init_commands( )
{
  int i, j;

  for( i = 0; i < MAX_ENTRY_COMMAND; i++ ) {
    for( j = 0; command_list[j].name[0] != '\0'; j++ ) {
      if( !strcasecmp( command_table[i].func_name, command_list[j].name ) ) {
        command_table[i].function = command_list[j].function;
        break;
        }
      }
    }

  return;
}


/*
 *   SPELLS 
 */


class spell_ident
{
 public:
  const char*       name;
  spell_func*   function;
};


spell_ident spell_list [] =
{ 
  { "acid blast",         spell_acid_blast         },
  { "acid storm",         spell_acid_storm         },
  { "armor",              spell_armor              },
  { "astral gate",        spell_astral_gate        },
  { "augury",             spell_augury             },
  { "balm",               spell_balm               },
  { "banishment",         spell_banishment         },
  { "barkskin",           spell_barkskin           },
  { "bless",              spell_bless              },
  { "blind",              spell_blind              },
  { "blink",              spell_blink              },
  { "burning hands",      spell_burning_hands      },
  { "calm",               spell_calm               },
  { "call lightning",     spell_call_lightning     },
  { "cause critical",     spell_cause_critical     },
  { "cause light",        spell_cause_light        },
  { "cause serious",      spell_cause_serious      },
  { "conflagration",      spell_conflagration      },
  { "confuse",            spell_confuse            },
  { "construct golem",    spell_construct_golem    },
  { "create feast",       spell_create_feast       },
  { "create food",        spell_create_food        },
  { "create light",       spell_create_light       },
  { "create water",       spell_create_water       },
  { "cure blindness",     spell_cure_blindness     },
  { "cure critical",      spell_cure_critical      },
  { "cure light",         spell_cure_light         },
  { "cure poison",        spell_cure_poison        },
  { "cure serious",       spell_cure_serious       },
  { "detect invisible",   spell_detect_invisible   },
  { "displace",           spell_displace           },
  { "eagle eye",          spell_eagle_eye          },
  { "fear",               spell_fear               },
  { "find familiar",      spell_find_familiar      },
  { "fire shield",        spell_fire_shield        },
  { "fireball",           spell_fireball           },
  { "flame strike",       spell_flame_strike       },
  { "float",              spell_float              },
  { "fly",                spell_fly                },
  { "greater animation",  spell_greater_animation  },
  { "hallucinate",        spell_hallucinate        },
  { "harm",               spell_harm               },
  { "haste",              spell_haste              },
  { "heal",               spell_heal               },
  { "identify",           spell_identify           },
  { "invulnerability",    spell_invulnerability    },
  { "lesser summoning",   spell_lesser_summoning   },
  { "lightning bolt",     spell_lightning_bolt     },
  { "magic missile",      spell_magic_missile      },
  { "maelstrom",          spell_maelstrom          },
  { "major enchantment",  spell_major_enchantment  },
  { "mind blade",         spell_mind_blade         },
  { "minor enchantment",  spell_minor_enchantment  },
  { "neutralize",         spell_neutralize         },
  { "pass door",          spell_pass_door          },
  { "polymorph",          spell_polymorph          },
  { "poultice",           spell_poultice           },
  { "prismic missile",    spell_prismic_missile    },
  { "protection/good",    spell_protect_good       },
  { "protection/evil",    spell_protect_evil       },
  { "recall",             spell_recall             },
  { "remove curse",       spell_remove_curse       },
  { "request ally",       spell_request_ally       },
  { "resist acid",        spell_resist_acid        },
  { "resist cold",        spell_resist_cold        },
  { "resist fire",        spell_resist_fire        },
  { "resist shock",       spell_resist_shock       },
  { "resurrect",          spell_resurrect          },
  { "revitalize",         spell_revitalize         },
  { "sanctify",           spell_sanctify           },
  { "scry",               spell_scry               },
  { "sense danger",       spell_sense_danger       },
  { "slay",               spell_slay               },
  { "shock",              spell_shock              },
  { "sleep",              spell_sleep              },
  { "slow",               spell_slow               },
  { "summon",             spell_summon             },
  { "surcease",           spell_surcease           },
  { "transfer",           spell_transfer           }, 
  { "restoration",        spell_restoration        }, 
  { "turn undead",        spell_turn_undead        },
  { "vitality",           spell_vitality           },
  { "water breathing",    spell_water_breathing    },
  { "web",                spell_web                },
  { "wizard lock",        spell_wizard_lock        },
  { "youth",              spell_youth              },

  { "holy wrath",         spell_holy_wrath         },
  { "tame",               spell_tame               },
  { "faerie fire",        spell_faerie_fire        },
  { "invisibility",       spell_invisibility       },
  { "protection plants",  spell_protection_plants  },
  { "curse",              spell_curse              }, 
  { "mists of sleep",     spell_mists_sleep        },
  { "locust swarm",       spell_locust_swarm       },
  { "poison cloud",       spell_poison_cloud       },
  { "magic mapping",      spell_magic_mapping      },
  { "amnesia",            spell_amnesia            },
  { "detect hidden",      spell_detect_hidden      },
  { "detect good",        spell_detect_good        },
  { "detect evil",        spell_detect_evil        },
  { "ignite weapon",      spell_ignite_weapon      },
  { "chain lightning",    spell_chain_lightning    },
  { "infravision",        spell_infravision        },
  { "mystic shield",      spell_mystic_shield      },
  { "animate dead",       spell_animate_dead       },
  { "ogre strength",      spell_ogre_strength      },
  { "silence",            spell_silence            },
  { "drain life",         spell_drain_life         },
  { "blinding light",     spell_blinding_light     },
  { "gift of tongues",    spell_gift_of_tongues    },
  { "protect life",       spell_protect_life       },
  { "true sight",         spell_true_sight         },
  { "sense life",         spell_sense_life         },
  { "detect magic",       spell_detect_magic       },
  { "continual light",    spell_continual_light    },
  { "cure disease",       spell_cure_disease       },
  { "animate clay",       spell_animate_clay       },
  { "freeze",             spell_freeze             },
  { "chilling touch",     spell_chilling_touch     },
  { "ice storm",          spell_ice_storm          },
  { "replicate",          spell_replicate          },
  { "thorn shield",       spell_thorn_shield       },
  { "group serious",      spell_group_serious      },
  { "group critical",     spell_group_critical     },
  { "ion shield",         spell_ion_shield         },
  { "meteor swarm",       spell_meteor_swarm       },
  { "ice lance",          spell_ice_lance          },
  { "purify",             spell_purify             },
  { "wither",             spell_wither             },
  { "obscure",            spell_obscure            },
  { "conjure elemental",  spell_conjure_elemental  },
  { "find mount",         spell_find_mount         },
  { "hawks view",         spell_hawks_view         },
  { "",                   NULL                     }
};


void init_spells( )
{
  int i, j;

  for( i = 0; i < MAX_SPELL; i++ ) {
    spell_table[i].function = NULL; 
    for( j = 0; spell_list[j].name[0] != '\0'; j++ ) {
      if( !strcasecmp( spell_table[i].name, spell_list[j].name ) ) {
        spell_table[i].function = spell_list[j].function;
        break;
        }
      }
    if( spell_table[i].function == NULL ) 
      panic( "Init_Spells: Null function - %s", spell_table[i].name );
    }

  return;
}


