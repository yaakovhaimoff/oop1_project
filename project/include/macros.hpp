#pragma once

#include <string>
#include <SFML/Graphics.hpp>

// amount of player tools in the game
const int numOfPlayers = 4;
const int LEVELS = 3;

const int AmountOfWindows = 3;
const int MENU = 0;
const int HELP = 1;
const int PLAY = 2;
const int EXIT = 3;

const float kingSpeed = 110;
const float mageSpeed = 130;
const float warriorSpeed = 160;
const float thiefSpeed = 180;
const float dwarfSpeed = 170;

const std::string selectLevelNames[] = {"Level 1", "Level 2", "Level 3"};
const std::string menu_names[] = {"HELP", "PLAY", "EXIT"};

// what the tiles in the game can posses

const auto BOARD_COLOR = sf::Color(199, 220, 227);
const auto MENU_COLOR = sf::Color(214, 217, 213);
const auto BACKGROUND_COLOR = sf::Color(217, 255, 255);
const int CELL = 70;
const int SPACE = 350;
const int SIDE_WIDTH = 60;
const int SIDE_LENGTH = 200;
const int MenuBar = 14;
const int PLAYER_EXIST = 2;

const int teleportsConnection[LEVELS] = {032145, 0312, 0123};
const int levelTimes[LEVELS] = {180, 240, 300};

const std::string FontName = "font.ttf";
const std::vector SOUNDS_NAMES = {"gamePlay.wav", "menuMusic.wav", "ClickSound.wav", "FailSound.wav",
								  "ThiefTakeKey.wav", "GrabPresent.wav", "TeleportEnter.wav",
								  "OpenGate.wav", "WinLevel.wav", "fire.wav","OrkDeathSoundEffect.wav"};
const std::vector NAMES = {"play1.png", "play2.png", "play3.png", "menu.png", "help.png", "SelectLevel.png", "king.png", "mage.png",
						   "warrior.png", "thief.png", "crown.png", "gate.png", "fire.png",
						   "key.png", "monster.png", "teleport.png", "brickWall.png", "dwarf.png", "gift.png",
						   "pause.png", "paused.png", "soundOn.png", "soundOff.png", "noKey.png"};
enum rcsNames
{
	BoardBackground1,
	BoardBackground2,
	BoardBackground3,
	MenuBackground,
	HelpScreen,
	SelecetLevel,
	King,
	Mage,
	Warrior,
	Thief,
	Crown,
	Gate,
	Fire,
	Key,
	Monster,
	Teleport,
	Wall,
	Dwarf,
	Gift,
	Pause,
	Paused,
	soundOn,
	soundOff,
	noKey,
};
enum SoundsNames
{
	GameSound,
	menuSound,
	ClickSound,
	DwarfColide,
	ThiefTake,
	GrabPresent,
	TeleportEnter,
	OpenGate,
	LevelWin,
	MageFire,
	KillOrk,
};
// the player tools in the games
enum playersKeys
{
	KING = 75,	  // 'K'
	MAGE = 77,	  // 'M'
	WARRIOR = 87, // 'W'
	THIEF = 84	  // 'T'
};

// what the tiles in the game can posses
enum gameTools
{
	ERASE = 1,
	NEW_BOARD = 2,
	SAVE_BOARD = 3,
	GATE_KEY = 70,
	FIRE = 42,
	TELEPORT = 88,
	CROWN = 64,
	MONSTER = 33,
	GATE = 35,
	WALL = 61,
	DWARF = 94,
	GIFT = 36,
	REMOVE_DWARFS = 126
};

enum BoardRectObjects
{
	KING_BOARD_OBJECT = 0,
	MAGE_BOARD_OBJECT = 1,
	WARRIOR_BOARD_OBJECT = 2,
	THIEF_BOARD_OBJECT = 3,
};
