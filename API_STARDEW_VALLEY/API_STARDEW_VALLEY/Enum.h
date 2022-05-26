#pragma once
enum OBJID
{
	OBJ_Land,
	OBJ_Crops,
	OBJ_Cat,
	OBJ_Player,
	OBJ_HugeCrop,
	OBJ_Mouse,
	OBJ_Monster,
	OBJ_MyButton,
	OBJ_Bullet,
	OBJ_Collision,
	OBJ_Source,//풀만 추가.
	OBJ_Wood,
	OBJ_Stone,
	OBJ_Mine1,//금.
	OBJ_Mine2,//이리듐.
	OBJ_Tool,
	OBJ_Imoji,
	OBJ_Ball,
	OBJ_Arrow,
	OBJ_Treasure,
	OBJ_Key,
	OBJ_Birds,
	OBJ_TV,
	OBJ_End
};

enum SCENEID { SC_Menu, SC_Stage, SC_Farm, SC_Cave1, SC_Cave2, SC_Cave3, SC_Shop, SC_MinigameGamble, SC_MinigameWall, SC_MyEdit, SC_Ending, SC_End };

enum DirID { Dir_Down, Dir_Right, Dir_Up, Dir_Left, Dir_End };

enum WOODID { WOOD_1, WOOD_2, WOOD_End };
enum GRASSID {GRASS_1,GRASS_2,GRASS_End};
enum MINEID{MINE_GOLD,MINE_IRIDIUM,MINE_End};

enum CHANNELID 
{ 
	SOUND_BGM, 
    SOUND_EFFECT, 
    SOUND_PLAYER, 
    SOUND_MONSTER_Bat, 
    SOUND_MONSTER_Slime, 
    SOUND_Cat, 
	SOUND_Birds, 
    SOUND_Button, 
	SOUND_Wood, 
    SOUND_Grass, 
	SOUND_Stone,
	SOUND_Land,
    SOUND_Mine, 
	SOUND_Coin, 
    SOUND_Bullet, 
	SOUND_DoorOpen, 
    SOUND_Eat, 
    SOUND_Win,
	SOUND_EARTHQUAKE,
	SOUND_MINIGAME_REWARD,
	SOUND_MOVIE_BOOM,
	SOUND_MOVIE_WOOD,
	SOUND_MOVIE_GHOST,
    MAXCHANNEL 
};