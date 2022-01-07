#pragma once

#include <string>
#include <SFML/Graphics.hpp>

// amount of player tools in the game
const int numOfPlayers = 4;

const int AmountOfSounds = 3;
const int GAME_SOUND = 0;
const int CLICK_SOUND = 1;
const int FAIL_SOUND = 2;

const int AmountOfWindows = 4;
const int MENU = 0;
const int HELP = 1;
const int PLAY = 2;
const int EXIT = 3;

const std::string menu_names[] = { "HELP", "PLAY", "EXIT" };

// what the tiles in the game can posses

const auto BOARD_COLOR = sf::Color(199, 220, 227);
const auto MENU_COLOR = sf::Color(214, 217, 213);
const auto BACKGROUND_COLOR = sf::Color(217, 255, 255);
const int CELL = 70;
const int SPACE = 350;
const int SIDE_WIDTH = 450;
const int SIDE_LENGTH = 180;
const int MenuBar = 14;
const int PLAYER_EXIST = 2;

const int teleportsConnection[] ={ 032145, 0312, 012354 };
const int levelTimes[] = { 300, 300, 350 };

const std::string FontName = "font.ttf";
const std::vector SOUNDS_NAMES = { "GameOfThrones.wav", "ClickSound.wav","FailSound.wav" };
const std::vector NAMES = { "play.png","menu.png","help.png","king.png", "mage.png",
							"thief.png","warrior.png","crown.png", "gate.png", "fire.png",
							"key.png","monster.png", "teleport.png", "brickWall.png", "dwarf.png", "gift.png" };
enum rcsNames
{
	BoardBackground,
	MenuBackground,
	HelpScreen,
	King,
	Mage,
	Thief,
	Warrior,
	Crown,
	Gate,
	Fire,
	Key,
	Monster,
	Teleport,
	Wall,
	Dwarf,
	Gift,
};
enum SoundsNames {
	GameSound,
	ClickSound,
	FailSound,
};
// the player tools in the games
enum playersKeys
{
	KING = 75,    // 'K'
	MAGE = 77,    // 'M'
	WARRIOR = 87, // 'W'
	THIEF = 84    // 'T'
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
	GIFT = 36
};

enum BoardRectObjects
{
	KING_BOARD_OBJECT = 0,
	MAGE_BOARD_OBJECT = 1,
	WARRIOR_BOARD_OBJECT = 2,
	THIEF_BOARD_OBJECT = 3,
	WALL_BOARD_OBJECT = 4,
	CROWN_BOARD_OBJECT = 5,
	FIRE_BOARD_OBJECT = 6,
	GATE_BOARD_OBJECT = 7,
	GATE_KEY_BOARD_OBJECT = 8,
	MONSTER_BOARD_OBJECT = 9,
	TELEPORT_BOARD_OBJECT = 10,
	DO_NOTHING = 11
};
