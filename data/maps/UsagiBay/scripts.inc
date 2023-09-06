UsagiBay_MapScripts::
	.byte 0


UsagiBay_Artist::
	lockall
	faceplayer
	goto_if_set FLAG_ARTISAN_TRADE, ARTIST_TRADE_COMPLETE
	msgbox UsagiBay_Artist_Text_0
	msgbox UsagiBay_Artist_Text_1
	msgbox UsagiBay_Artist_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq UsagiBay_Artist_2
	msgbox UsagiBay_Artist_Text_4
	releaseall
	end

UsagiBay_Artist_1:
Trade_Declined:
	msgbox UsagiBay_Artist_Text_5
	releaseall
	end
ARTIST_TRADE_COMPLETE:
	msgbox UsagiBay_Artist_Text_6
	releaseall
	end

UsagiBay_Artist_2:
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Trade_Declined
	copyvar VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, GetTradeSpecies
	goto_if_ne VAR_RESULT, SPECIES_SMEARGLE, Trade_Declined
	msgbox UsagiBay_Artist_Text_3
	multichoice 25, 5, MULTI_KANTO_STARTER_CHOICE, 1
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq UsagiBay_Artist_5
	compare VAR_RESULT, 1
	goto_if_eq UsagiBay_Artist_6
	compare VAR_RESULT, 2
	goto_if_eq UsagiBay_Artist_7
	goto UsagiBay_Artist_1

UsagiBay_Artist_5:
	setvar VAR_0x8004, INGAME_TRADE_BULBASAUR
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	setflag FLAG_ARTISAN_TRADE
	return
	releaseall
	end

UsagiBay_Artist_6:
	setvar VAR_0x8004, INGAME_TRADE_CHARMANDER
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	setflag FLAG_ARTISAN_TRADE
	return
	releaseall
	end

UsagiBay_Artist_7:
	setvar VAR_0x8004, INGAME_TRADE_SQUIRTLE
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	setflag FLAG_ARTISAN_TRADE
	return
	releaseall
	end


UsagiBay_Woman::
	lockall
	faceplayer
	msgbox UsagiBay_Woman_Text_0
	releaseall
	end


UsagiBay_Sailor::
	lockall
	faceplayer
	msgbox UsagiBay_Sailor_Text_0
	releaseall
	end


UsagiBay_LittleGirl::
	lockall
	faceplayer
	msgbox UsagiBay_LittleGirl_Text_0
	msgbox UsagiBay_LittleGirl_Text_1
	releaseall
	end


UsagiBay_Azurill::
	lockall
	faceplayer
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	showmonpic SPECIES_AZURILL, 10, 3
	msgbox UsagiBay_Azurill_Text_0
	waitmoncry
	hidemonpic
	releaseall
	end


UsagiBay_Ranger::
	lockall
	faceplayer
	msgbox UsagiBay_Ranger_Text_0
	releaseall
	end


UsagiBay_BugCatcher::
	lockall
	faceplayer
	msgbox UsagiBay_BugCatcher_Text_0
	releaseall
	end


StoneShop::
	lock
	faceplayer
	message StoneShop_Text_0
	waitmessage
	compare VAR_BADGES_OBTAINED, 0
	goto_if_eq StoneShop_2
	compare VAR_BADGES_OBTAINED, 2
	goto_if_le StoneShop_3
	compare VAR_BADGES_OBTAINED, 4
	goto_if_le StoneShop_4
	compare VAR_BADGES_OBTAINED, 6
	goto_if_le StoneShop_5
	compare VAR_BADGES_OBTAINED, 8
	goto_if_le StoneShop_6
StoneShop_1:
	message StoneShop_Text_1
	release
	end

StoneShop_2:
	pokemart stoneshop_1
	goto StoneShop_1

StoneShop_3:
	pokemart stoneshop_2
	goto StoneShop_1

StoneShop_4:
	pokemart stoneshop_3
	goto StoneShop_1

StoneShop_5:
	pokemart stoneshop_4
	goto StoneShop_1

StoneShop_6:
	pokemart stoneshop_5
	goto StoneShop_1


.align 2
stoneshop_1::
.2byte ITEM_FIRE_STONE
.2byte ITEM_WATER_STONE
.2byte ITEM_THUNDER_STONE
.2byte ITEM_LEAF_STONE
.2byte ITEM_NONE
release
end

stoneshop_2::
.2byte ITEM_FIRE_STONE
.2byte ITEM_WATER_STONE
.2byte ITEM_THUNDER_STONE
.2byte ITEM_LEAF_STONE
.2byte ITEM_MOON_STONE
.2byte ITEM_SUN_STONE
.2byte ITEM_DAWN_STONE
.2byte ITEM_DUSK_STONE
.2byte ITEM_SHINY_STONE
.2byte ITEM_DRAGON_SCALE
.2byte ITEM_KINGS_ROCK
.2byte ITEM_METAL_COAT
.2byte ITEM_NONE
release
end

stoneshop_3::
.2byte ITEM_FIRE_STONE
.2byte ITEM_WATER_STONE
.2byte ITEM_THUNDER_STONE
.2byte ITEM_LEAF_STONE
.2byte ITEM_MOON_STONE
.2byte ITEM_SUN_STONE
.2byte ITEM_DAWN_STONE
.2byte ITEM_DUSK_STONE
.2byte ITEM_SHINY_STONE
.2byte ITEM_ICE_STONE
.2byte ITEM_MAGMARIZER
.2byte ITEM_ELECTIRIZER
.2byte ITEM_PROTECTOR
.2byte ITEM_REAPER_CLOTH
.2byte ITEM_RAZOR_CLAW
.2byte ITEM_RAZOR_FANG
.2byte ITEM_SWEET_APPLE
.2byte ITEM_TART_APPLE
.2byte ITEM_DRAGON_SCALE
.2byte ITEM_KINGS_ROCK
.2byte ITEM_METAL_COAT
.2byte ITEM_NONE
release
end

stoneshop_4::
.2byte ITEM_FIRE_STONE
.2byte ITEM_WATER_STONE
.2byte ITEM_THUNDER_STONE
.2byte ITEM_LEAF_STONE
.2byte ITEM_MOON_STONE
.2byte ITEM_SUN_STONE
.2byte ITEM_DAWN_STONE
.2byte ITEM_DUSK_STONE
.2byte ITEM_SHINY_STONE
.2byte ITEM_ICE_STONE
.2byte ITEM_MAGMARIZER
.2byte ITEM_ELECTIRIZER
.2byte ITEM_REAPER_CLOTH
.2byte ITEM_RAZOR_CLAW
.2byte ITEM_RAZOR_FANG
.2byte ITEM_SWEET_APPLE
.2byte ITEM_TART_APPLE
.2byte ITEM_DEEP_SEA_SCALE
.2byte ITEM_DEEP_SEA_TOOTH
.2byte ITEM_DRAGON_SCALE
.2byte ITEM_KINGS_ROCK
.2byte ITEM_METAL_COAT
.2byte ITEM_OVAL_STONE
.2byte ITEM_NONE
release
end

stoneshop_5::
.2byte ITEM_FIRE_STONE
.2byte ITEM_WATER_STONE
.2byte ITEM_THUNDER_STONE
.2byte ITEM_LEAF_STONE
.2byte ITEM_MOON_STONE
.2byte ITEM_SUN_STONE
.2byte ITEM_DAWN_STONE
.2byte ITEM_DUSK_STONE
.2byte ITEM_SHINY_STONE
.2byte ITEM_ICE_STONE
.2byte ITEM_MAGMARIZER
.2byte ITEM_ELECTIRIZER
.2byte ITEM_REAPER_CLOTH
.2byte ITEM_RAZOR_CLAW
.2byte ITEM_RAZOR_FANG
.2byte ITEM_SWEET_APPLE
.2byte ITEM_TART_APPLE
.2byte ITEM_DEEP_SEA_SCALE
.2byte ITEM_DEEP_SEA_TOOTH
.2byte ITEM_DRAGON_SCALE
.2byte ITEM_KINGS_ROCK
.2byte ITEM_METAL_COAT
.2byte ITEM_OVAL_STONE
.2byte ITEM_SACHET
.2byte ITEM_WHIPPED_DREAM
.2byte ITEM_UPGRADE
.2byte ITEM_DUBIOUS_DISC
.2byte ITEM_DRAGON_SCALE
.2byte ITEM_KINGS_ROCK
.2byte ITEM_METAL_COAT
.2byte ITEM_STRAWBERRY_SWEET
.2byte ITEM_LOVE_SWEET
.2byte ITEM_BERRY_SWEET
.2byte ITEM_CLOVER_SWEET
.2byte ITEM_FLOWER_SWEET
.2byte ITEM_STAR_SWEET
.2byte ITEM_RIBBON_SWEET
.2byte ITEM_NONE
release
end

UsagiBay_Artist_Text_0:
	.string "I'm a traveling artist looking for new\n"
	.string "things to paint.$"

UsagiBay_Artist_Text_1:
	.string "Usagi Bay has a wonderful ladscape,\n"
	.string "but I'm looking for something more\l"
	.string "animated.$"

UsagiBay_Artist_Text_2:
	.string "Do you by chance have a Smeargle?\nI'll trade it for a Pokémon from my home\lregion.$"

UsagiBay_Artist_Text_3:
	.string "Excellet!\nWhich Pokemon would you like?$"

UsagiBay_Artist_Text_4:
	.string "Oh... Well if you should change your mind\nyou know where to find me.$"

UsagiBay_Artist_Text_5:
	.string "Oh why must you tease me so?$"

UsagiBay_Artist_Text_6:
	.string "Hello, friend!\nHow is my Pokémon doing?\lYour Smeargle is just fine.$"

UsagiBay_Woman_Text_0:
	.string "The square is so lovely!\nI always come here to do a little\lshopping.$"

UsagiBay_Sailor_Text_0:
	.string "You'd never guess from it's size,\nbut the square is a hub for travelers\lfrom all over the world.\pI'm from Paldea, myself.$"

UsagiBay_LittleGirl_Text_0:
	.string "Mommy left me to play while she does\nsome shopping.$"

UsagiBay_LittleGirl_Text_1:
	.string "I'm perfectly safe as long as Azurill is\nwith me!$"

UsagiBay_Azurill_Text_0:
	.string "Azuuuuurill!$"

UsagiBay_Ranger_Text_0:
	.string "Not just anyone can enter Victory\nRoad, ya know.\pIt takes a hardened trainer like myself\nto trudge through that forest.\pToo bad I can never make it, huh?$"

UsagiBay_BugCatcher_Text_0:
	.string "Keep this between you and me, but I\n"
	.string "hear the square shopkeeps reveal more\l"
	.string "of their inventory to trainers with\l"
	.string "more badges.\p"
	.string "How's that fair, huh?\n"
	.string "I want some Net Balls too!$"

StoneShop_Text_0:
	.string "Hi and welcome to Steven's Stones.\nHow may I help you?$"

StoneShop_Text_1:
	.string "We hope to see you again!$"