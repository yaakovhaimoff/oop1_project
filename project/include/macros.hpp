#pragma once

#include <string>
#include <SFML/Graphics.hpp>

// amount of player tools in the game
const int numOfPlayers = 4;
const int LEVELS = 3;

const int AmountOfWindows = 4;
const int MENU = 0;
const int HELP = 1;
const int PLAY = 2;
const int EXIT = 3;
const int SELECT = 4;

const float kingSpeed = 110;
const float mageSpeed = 130;
const float warriorSpeed = 160;
const float thiefSpeed = 180;
const float dwarfSpeed = 170;

const std::string selectLevelNames[] = {"Easiest", "Medium", "Hardest"};
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

const std::vector SOUNDS_NAMES = {"sounds/gamePlay.wav", "sounds/menuMusic.wav", "sounds/ClickSound.wav", "sounds/FailSound.wav",
								  "sounds/ThiefTakeKey.wav", "sounds/GrabPresent.wav", "sounds/TeleportEnter.wav",
								  "sounds/OpenGate.wav", "sounds/WinLevel.wav", "sounds/fire.wav", "sounds/OrkDeathSoundEffect.wav"};

const std::vector NAMES = {"images/play1.png", "images/play2.png", "images/play3.png", "images/menu.png", "images/help.png", "images/SelectLevel.png",
						   "images/king.png", "images/mage.png", "images/warrior.png", "images/thief.png", "images/crown.png", "images/gate.png", "images/fire.png",
						   "images/key.png", "images/monster.png", "images/teleport.png", "images/brickWall.png", "images/dwarf.png", "images/gift.png",
						   "images/pause.png", "images/paused.png", "images/soundOn.png", "images/soundOff.png", "images/noKey.png"};
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
