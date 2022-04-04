#include "Dictionary.h"
const std::string Dictionary::words[] = {
	"speed",
	"crowd",
	"teeth",
	"which",
	"agree",
	"basis",
	"ratio",
	"lease",
	"avoid",
	"state",
	"anger",
	"needs",
	"input",
	"motor",
	"blame",
	"short",
	"album",
	"smoke",
	"rural",
	"equal",
	"mayor",
	"their",
	"tight",
	"block",
	"three",
	"field",
	"while",
	"trade",
	"chart",
	"maria",
	"offer",
	"flash",
	"front",
	"thick",
	"birth",
	"crown",
	"faith",
	"fight",
	"boost",
	"right"
};

std::string Dictionary::getWord(int index)
{
	return words[index];
}
