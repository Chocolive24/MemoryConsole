#pragma once
#include "../../libs/ConsoleViewController/ConsoleViewController.h"

enum class PatternType
{
	CAT,
	CLUBS,
	DIAMOND,
	FACE,
	HEART,
	PLUS,
	PRAY,
	SPADE,
	X,
	HIDDEN
};

class Pattern
{
private:
	Console::Image _sprite;
	PatternType _type { PatternType::HIDDEN };
public:
	Pattern() = default;
	Pattern(const std::string& name, PatternType type);

	Console::Image GetSprite() { return _sprite; }
	PatternType GetType() { return _type; }
};

class PatternHidden : public Pattern
{
public:
	PatternHidden() :
		Pattern("hidden", PatternType::HIDDEN) {}
};

class PatternCat : public Pattern
{
public:
	PatternCat() :
		Pattern("cat", PatternType::CAT) {}
};

class PatternClubs : public Pattern
{
public:
	PatternClubs() :
		Pattern("Clubs", PatternType::CLUBS) {}
};

class PatternDiamond : public Pattern
{
public:
	PatternDiamond() :
		Pattern("diamond", PatternType::DIAMOND) {}
};

class PatternFace : public Pattern
{
public:
	PatternFace() :
		Pattern("face", PatternType::FACE) {}
};

class PatternHeart : public Pattern
{
public:
	PatternHeart() :
		Pattern("heart", PatternType::HEART) {}
};

class PatternPlus : public Pattern
{
public:
	PatternPlus() :
		Pattern("plus", PatternType::PLUS) {}
};

class PatternPray : public Pattern
{
public:
	PatternPray() :
		Pattern("pray", PatternType::PRAY) {}
};

class PatternSpade : public Pattern
{
public:
	PatternSpade() :
		Pattern("spade", PatternType::SPADE) {}
};

class PatternX : public Pattern
{
public:
	PatternX() :
		Pattern("x", PatternType::X) {}
};