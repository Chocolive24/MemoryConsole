#include "Card.h"

#include <utility>

Card::Card(Pattern pattern, const Console::Foreground foreground)
{
	_pattern = std::move(pattern);
	_foreground = foreground;
}
