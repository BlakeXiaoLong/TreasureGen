#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>
#include <fstream>
#include "windows.h"

void cls()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

int roll(int numOfRolls, int dice, int multiplier = 1)
{
	int result = 0;
	for (int i = 0; i < numOfRolls; i++)
		result += rand() % dice + 1;
	return (result*multiplier);
}
int lootValue(std::vector<int> values, double value)
{
	for (int i = values.size() - 1; i > 0; i--)
		if (value > values.at(i)) return i;
	return -1;
}

std::string coinGen(int number, int dice, int type, int modifier = 1)
{
	std::stringstream ss;
	ss << roll(number, dice, modifier);
	switch (type)
	{
	case 1:
		ss << " cp\n";
		break;
	case 2:
		ss << " sp\n";
		break;
	case 3:
		ss << " gp\n";
		break;
	case 4:
		ss << " pp\n";
		break;
	default:
		std::cout << "Error Code 80\n";
		break;
	}
	return ss.str();
}
std::string gemGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int worth, rollG = roll(1, 100);
		switch (subtype)
		{
		case 1:
			worth = roll(2, 4) + 5;
			if (rollG < 9) ss << "Agate (" << worth << " gp)";
			else if (rollG < 14) ss << "Alabaster (" << worth << " gp)";
			else if (rollG < 21) ss << "Azurite (" << worth << " gp)";
			else if (rollG < 27) ss << "Hematite (" << worth << " gp)";
			else if (rollG < 35) ss << "Lapis Lazuli (" << worth << " gp)";
			else if (rollG < 41) ss << "Malachite (" << worth << " gp)";
			else if (rollG < 49) ss << "Obsidian (" << worth << " gp)";
			else if (rollG < 57) ss << "Irrigular freshwater Pearl (" << worth << " gp)";
			else if (rollG < 63) ss << "Pyrite (" << worth << " gp)";
			else if (rollG < 71) ss << "Rhodochrosite (" << worth << " gp)";
			else if (rollG < 79) ss << "Rock Crystal Quartz (" << worth << " gp)";
			else if (rollG < 85) ss << "Shell (" << worth << " gp)";
			else if (rollG < 93) ss << "Tigereye (" << worth << " gp)";
			else if (rollG < 101) ss << "Turquoise (" << worth << " gp)";
			else std::cout << "Error Code 109\n";
			break;
		case 2:
			worth = roll(2, 4, 5) + 25;
			if (rollG < 7) ss << "Bloodstone (" << worth << " gp)";
			else if (rollG < 13) ss << "Carnelian (" << worth << " gp)";
			else if (rollG < 19) ss << "Chrysoprase (" << worth << " gp)";
			else if (rollG < 25) ss << "Citrine  (" << worth << " gp)";
			else if (rollG < 33) ss << "Ivory (" << worth << " gp)";
			else if (rollG < 39) ss << "Jasper (" << worth << " gp)";
			else if (rollG < 45) ss << "Moonstone (" << worth << " gp)";
			else if (rollG < 51) ss << "Onyx (" << worth << " gp)";
			else if (rollG < 57) ss << "Peridot (" << worth << " gp)";
			else if (rollG < 75) ss << "Milky Quartz (" << worth << " gp)";
			else if (rollG < 81) ss << "Sard (" << worth << " gp)";
			else if (rollG < 87) ss << "Red Spinel (" << worth << " gp)";
			else if (rollG < 101) ss << "Zircon (" << worth << " gp)";
			else std::cout << "Error Code 126\n";
			break;
		case 3:
			worth = roll(2, 4, 10) + 50;
			if (rollG < 11) ss << "Amber (" << worth << " gp)";
			else if (rollG < 21) ss << "Amethyst (" << worth << " gp)";
			else if (rollG < 31) ss << "Chyrsoberyl (" << worth << " gp)";
			else if (rollG < 41) ss << "Coral (" << worth << " gp)";
			else if (rollG < 51) ss << "Garnet (" << worth << " gp)";
			else if (rollG < 61) ss << "Jade (" << worth << " gp)";
			else if (rollG < 71) ss << "Jet (" << worth << " gp)";
			else if (rollG < 81) ss << "Saltwater Pearl (" << worth << " gp)";
			else if (rollG < 91) ss << "Deep Blue Spinel (" << worth << " gp)";
			else if (rollG < 101) ss << "Tourmaline (" << worth << " gp)";
			else std::cout << "Error Code 140\n";
			break;
		case 4:
			worth = roll(2, 4, 50) + 250;
			if (rollG < 26) ss << "Aquamarine (" << worth << " gp)";
			else if (rollG < 51) ss << "Opal (" << worth << " gp)";
			else if (rollG < 76) ss << "Black Pearl (" << worth << " gp)";
			else if (rollG < 101) ss << "Topaz (" << worth << " gp)";
			else std::cout << "Error Code 148\n";
			break;
		case 5:
			worth = roll(2, 4, 100) + 500;
			if (rollG < 26) ss << "Small Diamond (" << worth << " gp)";
			else if (rollG < 51) ss << "Emerald (" << worth << " gp)";
			else if (rollG < 76) ss << "Small Ruby (" << worth << " gp)";
			else if (rollG < 101) ss << "Sapphire (" << worth << " gp)";
			else std::cout << "Error Code 156\n";
			break;
		case 6:
			worth = roll(2, 4, 100) + 2500;
			if (rollG < 26) ss << "Large Diamond (" << worth << " gp)";
			else if (rollG < 51) ss << "Brilliant Green Emerald (" << worth << " gp)";
			else if (rollG < 76) ss << "Large Ruby (" << worth << " gp)";
			else if (rollG < 101) ss << "Star Sapphire (" << worth << " gp)";
			else std::cout << "Error Code 164\n";
			break;
		default:
			std::cout << "Error Code 167\n";
			break;
		}
		ss << std::endl;
	}
	return ss.str();
}
std::string artGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int rollG = roll(1, 100);
		switch (subtype)
		{
		case 1:
			if (rollG < 6) ss << "Bronze statuette of a warrior (15 gp)";
			else if (rollG < 7) ss << "Elaborate copper wind chimes (20 gp)";
			else if (rollG < 8) ss << "Painted paper fan with silver slats (20 gp)";
			else if (rollG < 10) ss << "Copper and glass decanter (25 gp)";
			else if (rollG < 18) ss << "Silver holy symbol (25 gp)";
			else if (rollG < 22) ss << "Carved stone idol (30 gp)";
			else if (rollG < 26) ss << "Set of six ivory dice (30 gp)";
			else if (rollG < 30) ss << "Ivory bowl with animal carvings (40 gp)";
			else if (rollG < 31) ss << "Porcelain doll with silk clothing (40 gp)";
			else if (rollG < 33) ss << "Porcelain mask (40 gp)";
			else if (rollG < 37) ss << "Bronze flagon with warrior images (50 gp)";
			else if (rollG < 40) ss << "Copper brazier with religious markings (50 gp)";
			else if (rollG < 43) ss << "Copper scepter with gold inlay (50 gp)";
			else if (rollG < 45) ss << "Crystal egg with silver stand (50 gp)";
			else if (rollG < 47) ss << "Painting of a noblewoman (50 gp)";
			else if (rollG < 52) ss << "Polished darkwood chalice (50 gp)";
			else if (rollG < 53) ss << "Silver baby rattle (50 gp)";
			else if (rollG < 56) ss << "Silver chess set (50 gp)";
			else if (rollG < 61) ss << "Carved ivory scroll case (60 gp)";
			else if (rollG < 67) ss << "Decorated silver plate (60 gp)";
			else if (rollG < 72) ss << "Ivory drinking horn with copper ends (60 gp)";
			else if (rollG < 75) ss << "Silver noble family seal (60 gp)";
			else if (rollG < 81) ss << "Silver statue of a dragon (65 gp)";
			else if (rollG < 84) ss << "Electrum censer with silver filigree (70 gp)";
			else if (rollG < 88) ss << "Silver candelabra with holy symbol (75 gp)";
			else if (rollG < 91) ss << "Silver comb with ornate handle (75 gp)";
			else if (rollG < 94) ss << "Silver hand mirror (75 gp)";
			else if (rollG < 97) ss << "Crystal skull (80 gp)";
			else if (rollG < 98) ss << "Ornate silver flute (80 gp)";
			else if (rollG < 101) ss << "Engraved jade scarab (85 gp)";
			else std::cout << "Error Code 213\n";
			break;
		case 2:
			if (rollG < 3) ss << "Elaborate silver wind chimes (60 gp)";
			else if (rollG < 9) ss << "Engraved gold scarab (75 gp)";
			else if (rollG < 11) ss << "Painted silk fan with electrum slats (75 gp)";
			else if (rollG < 13) ss << "Preserved beast head on a plaque (75 gp)";
			else if (rollG < 18) ss << "Set of six silver dice (75 gp)";
			else if (rollG < 21) ss << "Silver and glass decanter (75 gp)";
			else if (rollG < 23) ss << "Silver bowl with lion engravings (75 gp)";
			else if (rollG < 27) ss << "Silver mask (75 gp)";
			else if (rollG < 31) ss << "Carved jade idol (80 gp)";
			else if (rollG < 32) ss << "Porcelain doll with furs and jewelry (80 gp)";
			else if (rollG < 36) ss << "Silver brazier with religious markings (80 gp)";
			else if (rollG < 39) ss << "Silver flagon with religious markings (80 gp)";
			else if (rollG < 42) ss << "Gold censer with silver filigree (90 gp)";
			else if (rollG < 45) ss << "Gold and silver chess set (100 gp)";
			else if (rollG < 46) ss << "Gold baby rattle (100 gp)";
			else if (rollG < 54) ss << "Gold holy symbol (100 gp)";
			else if (rollG < 57) ss << "Masterwork lyre (100 gp)";
			else if (rollG < 59) ss << "Painting of a princess (100 gp)";
			else if (rollG < 62) ss << "Silver cup with royal crest (100 gp)";
			else if (rollG < 66) ss << "Decorated electrum plate (110 gp)";
			else if (rollG < 70) ss << "Gold statue of a dragon (110 gp)";
			else if (rollG < 73) ss << "Gold statue of a lion (110 gp)";
			else if (rollG < 78) ss << "Ivory drinking horn with silver ends (110 gp)";
			else if (rollG < 82) ss << "Gold and silver hand mirror (120 gp)";
			else if (rollG < 86) ss << "Silver cauldron with animal symbols (120 gp)";
			else if (rollG < 89) ss << "Silver comb with gold handle (125 gp)";
			else if (rollG < 91) ss << "Silver egg with dragon figurine (125 gp)";
			else if (rollG < 93) ss << "Silver scepter with eagle symbols (125 gp)";
			else if (rollG < 98) ss << "Silver chalice with dragon carvings (150 gp)";
			else if (rollG < 101) ss << "Gold candelabra with holy symbol (200 gp)";
			else std::cout << "Error Code 246\n";
			break;
		case 3:
			if (rollG < 4) ss << "Gilded demon skull (300 gp)";
			else if (rollG < 14) ss << "Marble idol (300 gp)";
			else if (rollG < 20) ss << "Masterwork darkwood lute (300 gp)";
			else if (rollG < 25) ss << "Engraved mithral scarab (400 gp)";
			else if (rollG < 29) ss << "Gold and ivory decanter (400 gp)";
			else if (rollG < 33) ss << "Gold bowl with dragon engravings (400 gp)";
			else if (rollG < 36) ss << "Gold censer with platinum inlay (400 gp)";
			else if (rollG < 42) ss << "Gold mask (450 gp)";
			else if (rollG < 43) ss << "Gold and mithral baby rattle (500 gp)";
			else if (rollG < 49) ss << "Gold chess set (500 gp)";
			else if (rollG < 52) ss << "Gold flagon with religious markings (500 gp)";
			else if (rollG < 57) ss << "Gold puzzle box (500 gp)";
			else if (rollG < 66) ss << "Platinum holy symbol (500 gp)";
			else if (rollG < 70) ss << "Gold cup with royal crest (550 gp)";
			else if (rollG < 78) ss << "Gold chalice with griffon carvings (600 gp)";
			else if (rollG < 82) ss << "Mithral scepter with gold inlay (600 gp)";
			else if (rollG < 89) ss << "Decorated gold plate (700 gp)";
			else if (rollG < 94) ss << "Gold and platinum statuette of a deity (750 gp)";
			else if (rollG < 97) ss << "Gold cauldron with alchemical symbols (750)";
			else if (rollG < 101) ss << "Painting of a queen (750 gp)";
			else std::cout << "Error Code 269\n";
			break;
		case 4:
			if (rollG < 6) ss << "Engraved platinum scarab (700 gp)";
			else if (rollG < 12) ss << "Gilded dragon skull (800 gp)";
			else if (rollG < 19) ss << "Platinum bowl with arcane engravings (800 gp)";
			else if (rollG < 23) ss << "Platinum censer with ornate markings (800 gp)";
			else if (rollG < 27) ss << "Gold decanter with grape vine patterns (850 gp)";
			else if (rollG < 32) ss << "Platinum mask (900 gp)";
			else if (rollG < 37) ss << "Gold and mithral chess set (1,000 gp)";
			else if (rollG < 42) ss << "Gold and platinum orrery (1,000 gp)";
			else if (rollG < 47) ss << "Gold flute (1,000 gp)";
			else if (rollG < 52) ss << "Gold idol with strange carvings (1,000 gp)";
			else if (rollG < 53) ss << "Platinum baby rattle (1,000 gp)";
			else if (rollG < 56) ss << "Platinum holy symbol of a famous priest (1,000 gp)";
			else if (rollG < 65) ss << "Decorated platinum plate (1,100 gp)";
			else if (rollG < 69) ss << "Platinum cauldron with odd symbols (1,100 gp)";
			else if (rollG < 72) ss << "Platinum flagon with religious markings (1,100 gp)";
			else if (rollG < 78) ss << "Platinum cup with royal crest (1,200 gp)";
			else if (rollG < 82) ss << "Platinum scepter with gold inlay (1,200 gp)";
			else if (rollG < 88) ss << "Platinum chalice with angel carvings (1,250 gp)";
			else if (rollG < 94) ss << "Platinum statuette of a deity (1,300 gp)";
			else if (rollG < 101) ss << "Painting of a queen by a master (1,500 gp)";
			else std::cout << "Error Code 292\n";
			break;
		case 5:
			if (rollG < 9) ss << "Book of lost songs by a famous bard (3,000 gp)";
			else if (rollG < 17) ss << "Darkwood and platinum music box (4,000 gp)";
			else if (rollG < 27) ss << "Mithral hourglass with diamond dust (4,000 gp)";
			else if (rollG < 35) ss << "Jeweled egg with epic sorcerer's blood (4,500 gp)";
			else if (rollG < 38) ss << "Gold urn containing hero's ashes (5,000 gp)";
			else if (rollG < 46) ss << "Helm carved from a pit fiend skull (5,000 gp)";
			else if (rollG < 56) ss << "Holy text penned by a saint (5,000 gp)";
			else if (rollG < 66) ss << "Painting of a beloved queen by a master (5,000 gp)";
			else if (rollG < 75) ss << "Platinum idol with mysterious markings (5,000 gp)";
			else if (rollG < 78) ss << "Bejeweled sword of state (6,000 gp)";
			else if (rollG < 84) ss << "Carved saint's femur (6,000 gp)";
			else if (rollG < 89) ss << "Platinum chalice blessed by a saint (6,000 gp)";
			else if (rollG < 92) ss << "Glowing metallic meteor (6,500 gp)";
			else if (rollG < 98) ss << "Gold bejeweled royal orb (7,000 gp)";
			else if (rollG < 101) ss << "Crystallized dragon heart (7,500 gp)";
			else std::cout << "Error Code 310\n";
			break;
		case 6:
			if (rollG < 7) ss << "Frozen vampire soul (7,000 gp)";
			else if (rollG < 14) ss << "Mithral-inlaid unicorn horn (7,000 gp)";
			else if (rollG < 17) ss << "Crystallized god breath (10,000 gp)";
			else if (rollG < 23) ss << "Essence of truth (10,000 gp)";
			else if (rollG < 32) ss << "Globe of pristine air (10,000 gp)";
			else if (rollG < 41) ss << "Heart of the mountain (10,000 gp)";
			else if (rollG < 47) ss << "Inverted soul gem (10,000 gp)";
			else if (rollG < 56) ss << "Orb of living water (10,000 gp)";
			else if (rollG < 65) ss << "Shard of pure fire (10,000 gp)";
			else if (rollG < 73) ss << "Unmelting ice (10,000 gp)";
			else if (rollG < 80) ss << "Time jewel (11,000 gp)";
			else if (rollG < 84) ss << "Adamantine poiuyt (12,000 gp)";
			else if (rollG < 90) ss << "Holy text written in saint's blood (12,000 gp)";
			else if (rollG < 94) ss << "Mithral tribar (12,000 gp)";
			else if (rollG < 101) ss << "Ethereal tapestry (13,000)";
			else std::cout << "Error Code 328\n";
			break;
		default:
			break;
		}
		ss << std::endl;
	}
	return ss.str();
}
int getScrollLevel(int subtype)
{
	int rollG = roll(1, 100);
	switch (subtype)
	{
	case 1:
		if (rollG < 16) return 0;
		else if (rollG < 96) return 1;
		else if (rollG < 101) return 2;
		else std::cout << "Error Code 346\n";
		break;
	case 2:
		if (rollG < 6) return 0;
		else if (rollG < 36) return 1;
		else if (rollG < 91) return 2;
		else if (rollG < 101) return 3;
		else std::cout << "Error Code 353\n";
		break;
	case 3:
		if (rollG < 11) return 2;
		else if (rollG < 56) return 3;
		else if (rollG < 101) return 4;
		else std::cout << "Error Code 359\n";
		break;
	case 4:
		if (rollG < 21) return 3;
		else if (rollG < 61) return 4;
		else if (rollG < 101) return 5;
		else std::cout << "Error Code 365\n";
		break;
	case 5:
		if (rollG < 31) return 4;
		else if (rollG < 66) return 5;
		else if (rollG < 91) return 6;
		else if (rollG < 101) return 7;
		else std::cout << "Error Code 372\n";
		break;
	case 6:
		if (rollG < 6) return 6;
		else if (rollG < 36) return 7;
		else if (rollG < 71) return 8;
		else if (rollG < 101) return 9;
		else std::cout << "Error Code 379\n";
		break;
	default:
		break;
	}
	return -1;
}
std::string scrollGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int rollA = roll(1, 100), rollB = roll(1, 100), lvl = getScrollLevel(subtype);
		ss << "Scroll of ";
		if (rollA < 46)
			switch (lvl)
			{
			case 0:
				if (rollB < 10) ss << "Acid Splash";
				else if (rollB < 18) ss << "Daze";
				else if (rollB < 28) ss << "Detect Magic";
				else if (rollB < 36) ss << "Flare";
				else if (rollB < 46) ss << "Light";
				else if (rollB < 56) ss << "Mage Hand";
				else if (rollB < 64) ss << "Mending";
				else if (rollB < 73) ss << "Predigitation";
				else if (rollB < 82) ss << "Ray of Frost";
				else if (rollB < 92) ss << "Read Magic";
				else if (rollB < 101) ss << "Touch of Fatigue";
				else std::cout << "Error Code 408\n";
				break;
			case 1:
				if (rollB < 6) ss << "Burning Hands";
				else if (rollB < 10) ss << "Cause Fear";
				else if (rollB < 15) ss << "Charm Person";
				else if (rollB < 18) ss << "Chill Touch";
				else if (rollB < 22) ss << "Disguise Self";
				else if (rollB < 25) ss << "Endure Elements";
				else if (rollB < 29) ss << "Enlarge Person";
				else if (rollB < 33) ss << "Expeditious Retreat";
				else if (rollB < 37) ss << "Grease";
				else if (rollB < 40) ss << "Hypnotism";
				else if (rollB < 43) ss << "Identify";
				else if (rollB < 49) ss << "Mage Armor";
				else if (rollB < 55) ss << "Magic Missle";
				else if (rollB < 59) ss << "Magic Weapon";
				else if (rollB < 63) ss << "Obscuring Mist";
				else if (rollB < 65) ss << "Protection from Chaos";
				else if (rollB < 68) ss << "Protection from Evil";
				else if (rollB < 70) ss << "Protection Good";
				else if (rollB < 72) ss << "Protection from Law";
				else if (rollB < 76) ss << "Ray of Enfeeblement";
				else if (rollB < 81) ss << "Shield";
				else if (rollB < 85) ss << "Shocking Grasp";
				else if (rollB < 89) ss << "Silent Image";
				else if (rollB < 94) ss << "Sleep";
				else if (rollB < 97) ss << "Summon Monster I";
				else if (rollB < 101) ss << "True Strike";
				else std::cout << "Error Code 437\n";
				break;
			case 2:
				if (rollB < 5) ss << "Acid Arrow";
				else if (rollB < 8) ss << "Alter Self";
				else if (rollB < 13) ss << "Bear's Endurance";
				else if (rollB < 16) ss << "Blur";
				else if (rollB < 21) ss << "Bull's Strength";
				else if (rollB < 25) ss << "Cat's Grace";
				else if (rollB < 28) ss << "Darkness";
				else if (rollB < 31) ss << "Darkvision";
				else if (rollB < 35) ss << "Eagle's Splendor";
				else if (rollB < 38) ss << "False Life";
				else if (rollB < 41) ss << "Flaming Sphere";
				else if (rollB < 45) ss << "Fox's Cunning";
				else if (rollB < 48) ss << "Glitterdust";
				else if (rollB < 53) ss << "Invisibility";
				else if (rollB < 55) ss << "Knock";
				else if (rollB < 59) ss << "Levitate";
				else if (rollB < 62) ss << "Minor Image";
				else if (rollB < 66) ss << "Mirror Image";
				else if (rollB < 70) ss << "Owl's Wisdom";
				else if (rollB < 74) ss << "Resist Energy";
				else if (rollB < 76) ss << "Rope Trick";
				else if (rollB < 81) ss << "Scorching Ray";
				else if (rollB < 84) ss << "See Invisibility";
				else if (rollB < 86) ss << "Shatter";
				else if (rollB < 89) ss << "Spider Climb";
				else if (rollB < 92) ss << "Summon Monster II";
				else if (rollB < 94) ss << "Summon Swarm";
				else if (rollB < 99) ss << "Web";
				else if (rollB < 101) ss << "Whispering Wind";
				else std::cout << "Error Code 469\n";
				break;
			case 3:
				if (rollB < 4) ss << "Beast Shape I";
				else if (rollB < 8) ss << "Blink";
				else if (rollB < 13) ss << "Dispel Magic";
				else if (rollB < 17) ss << "Displacement";
				else if (rollB < 22) ss << "Fireball";
				else if (rollB < 25) ss << "Flame Arrow";
				else if (rollB < 30) ss << "Fly";
				else if (rollB < 33) ss << "Gaseous Form";
				else if (rollB < 38) ss << "Haste";
				else if (rollB < 41) ss << "Heroism";
				else if (rollB < 44) ss << "Hold Person";
				else if (rollB < 47) ss << "Invisibility Sphere";
				else if (rollB < 52) ss << "Lightning Bolt";
				else if (rollB < 55) ss << "Magic Circle against Chaos";
				else if (rollB < 58) ss << "Magic Circle against Evil";
				else if (rollB < 61) ss << "Magic Circle against Good";
				else if (rollB < 64) ss << "Magic Circle against Law";
				else if (rollB < 67) ss << "Major Image";
				else if (rollB < 71) ss << "Phantom Steed";
				else if (rollB < 75) ss << "Protection from Energy";
				else if (rollB < 79) ss << "Slow";
				else if (rollB < 82) ss << "Stinking Cloud";
				else if (rollB < 85) ss << "Suggestion";
				else if (rollB < 88) ss << "Summon Monster III";
				else if (rollB < 91) ss << "Tiny Hut";
				else if (rollB < 85) ss << "Tongues";
				else if (rollB < 98) ss << "Vampiric Touch";
				else if (rollB < 101) ss << "Water Breathing";
				else std::cout << "Error Code 500\n";
				break;
			case 4:
				if (rollB < 4) ss << "Beast Shape II";
				else if (rollB < 6) ss << "Bestow Curse";
				else if (rollB < 10) ss << "Black Tentacles";
				else if (rollB < 15) ss << "Charm Monster";
				else if (rollB < 19) ss << "Confusion";
				else if (rollB < 22) ss << "Crushing Despair";
				else if (rollB < 27) ss << "Dimension Door";
				else if (rollB < 30) ss << "Dimensional Anchor";
				else if (rollB < 33) ss << "Elemental Body I";
				else if (rollB < 37) ss << "Enervation";
				else if (rollB < 39) ss << "Mass Enlarge Person";
				else if (rollB < 44) ss << "Fear";
				else if (rollB < 48) ss << "Fire Shield";
				else if (rollB < 51) ss << "Lesser Globe of Invulnerability";
				else if (rollB < 55) ss << "Ice Storm";
				else if (rollB < 60) ss << "Greater Invisibility";
				else if (rollB < 65) ss << "Phantasmal Killer";
				else if (rollB < 68) ss << "Resiliant Sphere";
				else if (rollB < 72) ss << "Scrying";
				else if (rollB < 75) ss << "Shadow Conjuration";
				else if (rollB < 77) ss << "Shout";
				else if (rollB < 79) ss << "Solid Fog";
				else if (rollB < 81) ss << "Stone Shape";
				else if (rollB < 84) ss << "Summon Monster IV";
				else if (rollB < 89) ss << "Wall of Fire";
				else if (rollB < 93) ss << "Wall of Ice";
				else if (rollB < 98) ss << "Stoneskin";
				else if (rollB < 101) ss << "Animate Dead";
				else std::cout << "Error Code 531\n";
				break;
			case 5:
				if (rollB < 4) ss << "Baleful Polymorph";
				else if (rollB < 8) ss << "Beast Shape III";
				else if (rollB < 11) ss << "Break Enchantment";
				else if (rollB < 16) ss << "Cloudkill";
				else if (rollB < 22) ss << "Cone of Cold";
				else if (rollB < 24) ss << "Contact other Plane";
				else if (rollB < 27) ss << "Dismissal";
				else if (rollB < 32) ss << "Dominate Person";
				else if (rollB < 36) ss << "Feeblemind";
				else if (rollB < 41) ss << "Hold Monster";
				else if (rollB < 44) ss << "Magic Jar";
				else if (rollB < 47) ss << "Mind Fog";
				else if (rollB < 52) ss << "Overland Flight";
				else if (rollB < 55) ss << "Passwall";
				else if (rollB < 57) ss << "Permanancy";
				else if (rollB < 59) ss << "Lesser Planar Binding";
				else if (rollB < 63) ss << "Polymorph";
				else if (rollB < 66) ss << "Sending";
				else if (rollB < 70) ss << "Shadow Evocation";
				else if (rollB < 74) ss << "Summon Monster V";
				else if (rollB < 77) ss << "Telekinesis";
				else if (rollB < 83) ss << "Teleport";
				else if (rollB < 89) ss << "Wall of Force";
				else if (rollB < 93) ss << "Wall of Stone";
				else if (rollB < 96) ss << "Waves of Fatigue";
				else if (rollB < 98) ss << "Symbol of Pain";
				else if (rollB < 101) ss << "Symbol of Sleep";
				else std::cout << "Error Code 561\n";
				break;
			case 6:
				if (rollB < 4) ss << "Acid Fog";
				else if (rollB < 8) ss << "Antimagic Field";
				else if (rollB < 11) ss << "Mass Bear's Edurance";
				else if (rollB < 14) ss << "Beast Shape IV";
				else if (rollB < 17) ss << "Mass Bull's Strength";
				else if (rollB < 20) ss << "Mass Cat's Grace";
				else if (rollB < 26) ss << "Chain Lightning";
				else if (rollB < 32) ss << "Disintegrate";
				else if (rollB < 38) ss << "Greater Dispel Magic";
				else if (rollB < 41) ss << "Mass Eagle's Splendor";
				else if (rollB < 43) ss << "Eyebite";
				else if (rollB < 48) ss << "Flesh to Stone";
				else if (rollB < 51) ss << "Form of the Dragon I";
				else if (rollB < 54) ss << "Mass Fox's Cunning";
				else if (rollB < 57) ss << "Globe of Invulnerability";
				else if (rollB < 60) ss << "Greater Heroism";
				else if (rollB < 63) ss << "Mislead";
				else if (rollB < 66) ss << "Mass Owl's Wisdom";
				else if (rollB < 68) ss << "Planar Binding";
				else if (rollB < 71) ss << "Shadow Walk";
				else if (rollB < 73) ss << "Stone to Flesh";
				else if (rollB < 77) ss << "Mass Suggestion";
				else if (rollB < 80) ss << "Summon Monster VI";
				else if (rollB < 83) ss << "Transformation";
				else if (rollB < 85) ss << "Veil";
				else if (rollB < 88) ss << "Wall to Iron";
				else if (rollB < 90) ss << "Create Undead";
				else if (rollB < 93) ss << "Legend Lore";
				else if (rollB < 97) ss << "True Seeking";
				else if (rollB < 99) ss << "Circle of Death";
				else if (rollB < 101) ss << "Symbol of Fear";
				else std::cout << "Error Code 595\n";
				break;
			case 7:
				if (rollB < 5) ss << "Greater Arcane Sight";
				else if (rollB < 8) ss << "Banishment";
				else if (rollB < 14) ss << "Delayed Blast Fireball";
				else if (rollB < 18) ss << "Ethereal Jaunt";
				else if (rollB < 23) ss << "Finger of Death";
				else if (rollB < 28) ss << "Form of the Dragon II";
				else if (rollB < 31) ss << "Mass Hold Person";
				else if (rollB < 36) ss << "Mass Invisibility";
				else if (rollB < 40) ss << "Mage's Sword";
				else if (rollB < 43) ss << "Phase Door";
				else if (rollB < 49) ss << "Plane Shift";
				else if (rollB < 54) ss << "Greater Polymorph";
				else if (rollB < 58) ss << "Power Word Blind";
				else if (rollB < 63) ss << "Prismatic Spray";
				else if (rollB < 67) ss << "Reverse Gravity";
				else if (rollB < 71) ss << "Greater Scrying";
				else if (rollB < 74) ss << "Greater Shadow Conjuration";
				else if (rollB < 79) ss << "Spell Turning";
				else if (rollB < 82) ss << "Summon Monster VII";
				else if (rollB < 88) ss << "Greater Teleport";
				else if (rollB < 91) ss << "Waves of Exhaustion";
				else if (rollB < 94) ss << "Project Image";
				else if (rollB < 98) ss << "Forcecage";
				else if (rollB < 101) ss << "Limited Wish";
				else std::cout << "Error Code 622\n";
				break;
			case 8:
				if (rollB < 6) ss << "Mass Charm Monster";
				else if (rollB < 10) ss << "Demand";
				else if (rollB < 14) ss << "Dimensional Lock";
				else if (rollB < 19) ss << "Form of the Dragon III";
				else if (rollB < 24) ss << "Horrid Wilting";
				else if (rollB < 29) ss << "Instd::cindiary Cloud";
				else if (rollB < 34) ss << "Irresistable Dance";
				else if (rollB < 41) ss << "Maze";
				else if (rollB < 46) ss << "Mind Blank";
				else if (rollB < 50) ss << " Greater Planar Binding";
				else if (rollB < 56) ss << "Polar Ray";
				else if (rollB < 60) ss << "Polymorph any Object";
				else if (rollB < 67) ss << "Power Word Stun";
				else if (rollB < 73) ss << "Prismatic Wall";
				else if (rollB < 77) ss << "Sstd::cintillating Pattern";
				else if (rollB < 81) ss << "Summon Monster VIII";
				else if (rollB < 86) ss << "Telekinetic Sphere";
				else if (rollB < 91) ss << "Protection from Spells";
				else if (rollB < 95) ss << "Symbol of Death";
				else if (rollB < 98) ss << "Temporal Stasis";
				else if (rollB < 101) ss << "Trap the Soul";
				else std::cout << "Error Code 646\n";
				break;
			case 9:
				if (rollB < 7) ss << "Dominate Monster";
				else if (rollB < 12) ss << "Energy Drain";
				else if (rollB < 17) ss << "Freedom";
				else if (rollB < 24) ss << "Gate";
				else if (rollB < 29) ss << "Mass Hold Monster";
				else if (rollB < 34) ss << "Improsonment";
				else if (rollB < 40) ss << "Mage's Disjunction";
				else if (rollB < 48) ss << "Meteor Storm";
				else if (rollB < 56) ss << "Power Word Kill";
				else if (rollB < 62) ss << "Prismatic Sphere";
				else if (rollB < 67) ss << "Shapechange";
				else if (rollB < 72) ss << "Summon Monster IX";
				else if (rollB < 80) ss << "Time Stop";
				else if (rollB < 86) ss << "Weird";
				else if (rollB < 91) ss << "Astral Projection";
				else if (rollB < 97) ss << "Teleportaion Circle";
				else if (rollB < 101) ss << "Wish";
				else std::cout << "Error Code 666\n";
				break;
			default:
				std::cout << "Error Code 669\n";
				break;
			}
		else if (rollA < 61)
			switch (lvl)
			{
			case 0:
				if (rollB < 8) ss << "Arcane Mark";
				else if (rollB < 18) ss << "Bleed";
				else if (rollB < 26) ss << "Danstd::cing Lights";
				else if (rollB < 36) ss << "Detect Poison";
				else if (rollB < 43) ss << "Disrupt Undead";
				else if (rollB < 52) ss << "Ghost Sound";
				else if (rollB < 62) ss << "Message";
				else if (rollB < 69) ss << "Open/Close";
				else if (rollB < 76) ss << "Resistance";
				else if (rollB < 84) ss << "Sift";
				else if (rollB < 93) ss << "Spark";
				else if (rollB < 101) ss << "Unwitting Ally";
				else std::cout << "Error Code 688\n";
				break;
			case 1:
				if (rollB < 3) ss << "Air Bubble";
				else if (rollB < 7) ss << "Alarm";
				else if (rollB < 9) ss << "Animate Rope";
				else if (rollB < 13) ss << "Ant Haul";
				else if (rollB < 16) ss << "Blend";
				else if (rollB < 19) ss << "Break";
				else if (rollB < 24) ss << "Color Spray";
				else if (rollB < 27) ss << "Comprehend Languages";
				else if (rollB < 31) ss << "Corrosive Touch";
				else if (rollB < 34) ss << "Detect Secret Doors";
				else if (rollB < 37) ss << "Detect Undead";
				else if (rollB < 39) ss << "Erase";
				else if (rollB < 41) ss << "Flare Burst";
				else if (rollB < 44) ss << "Floating Disk";
				else if (rollB < 47) ss << "Hold Portal";
				else if (rollB < 49) ss << "Hydraulic Push";
				else if (rollB < 52) ss << "Icicle Dagger";
				else if (rollB < 55) ss << "Illusion of Calm";
				else if (rollB < 59) ss << "Jump";
				else if (rollB < 61) ss << "Magic Aura";
				else if (rollB < 64) ss << "Mirror Strike";
				else if (rollB < 67) ss << "Mount";
				else if (rollB < 70) ss << "Ray of Sickening";
				else if (rollB < 72) ss << "Reduce Person";
				else if (rollB < 75) ss << "Shadow Person";
				else if (rollB < 78) ss << "Shock Shield";
				else if (rollB < 81) ss << "Stone Fist";
				else if (rollB < 85) ss << "Touch of the Sea";
				else if (rollB < 89) ss << "Unseen Servant";
				else if (rollB < 92) ss << "Urban Grace";
				else if (rollB < 97) ss << "Vanish";
				else if (rollB < 99) ss << "Ventriloquism";
				else if (rollB < 101) ss << "Voice Alteration";
				else std::cout << "Error Code 724\n";
				break;
			case 2:
				if (rollB < 4) ss << "Bestow Weapon Proficiency";
				else if (rollB < 7) ss << "Blindness/Deafness";
				else if (rollB < 10) ss << "Burning Gaze";
				else if (rollB < 13) ss << "Certain Grip";
				else if (rollB < 15) ss << "Command Undead";
				else if (rollB < 17) ss << "Create Pit";
				else if (rollB < 21) ss << "Daze Monster";
				else if (rollB < 24) ss << "Detect Thoughts";
				else if (rollB < 28) ss << "Disguise Other";
				else if (rollB < 32) ss << "Elemental Touch";
				else if (rollB < 35) ss << "Fire Breath";
				else if (rollB < 39) ss << "Fog Cloud";
				else if (rollB < 41) ss << "Ghoul Touch";
				else if (rollB < 42) ss << "Glide";
				else if (rollB < 45) ss << "Gust of Wind";
				else if (rollB < 48) ss << "Haunting Mists";
				else if (rollB < 52) ss << "Hideous Laughter";
				else if (rollB < 55) ss << "Hypnotic Pattern";
				else if (rollB < 58) ss << "Locate Object";
				else if (rollB < 61) ss << "Make Whole";
				else if (rollB < 63) ss << "Misdirection";
				else if (rollB < 64) ss << "Obscure Object";
				else if (rollB < 66) ss << "Pernicious Poison";
				else if (rollB < 68) ss << "Protection from Arrows";
				else if (rollB < 71) ss << "Pyrotechnics";
				else if (rollB < 74) ss << "Returning Weapon";
				else if (rollB < 78) ss << "Scare";
				else if (rollB < 81) ss << "Shadow Anchor";
				else if (rollB < 84) ss << "Share Memory";
				else if (rollB < 86) ss << "Slipstream";
				else if (rollB < 89) ss << "Spectral Hand";
				else if (rollB < 91) ss << "Spontaneous Immolation";
				else if (rollB < 94) ss << "Touch of Idiocy";
				else if (rollB < 95) ss << "Unshakable Chill";
				else if (rollB < 97) ss << "Magic Mouth";
				else if (rollB < 98) ss << "Arcane Lock";
				else if (rollB < 100) ss << "Continual Flame";
				else if (rollB < 101) ss << "Phantom Trap";
				else std::cout << "Error Code 765\n";
				break;
			case 3:
				if (rollB < 4) ss << "Lesser Animate Dead";
				else if (rollB < 7) ss << "Aqueous Orb";
				else if (rollB < 9) ss << "Arcane Sight";
				else if (rollB < 13) ss << "Beast Shape";
				else if (rollB < 16) ss << "Clairaudience/Clairvoyance";
				else if (rollB < 18) ss << "Cloak of Winds";
				else if (rollB < 21) ss << "Daylight";
				else if (rollB < 25) ss << "Deep Slumber";
				else if (rollB < 28) ss << "Distracting Cacophany";
				else if (rollB < 31) ss << "Draconic Reservoir";
				else if (rollB < 36) ss << "Elemental Aura";
				else if (rollB < 39) ss << "Explosive Runes";
				else if (rollB < 44) ss << "Force Punch";
				else if (rollB < 46) ss << "Gentle Repose";
				else if (rollB < 48) ss << "Halt Undead";
				else if (rollB < 50) ss << "Healing Thief";
				else if (rollB < 52) ss << "Hydraulic Torrent";
				else if (rollB < 57) ss << "Keen Edge";
				else if (rollB < 62) ss << "Greater Magic Weapon";
				else if (rollB < 66) ss << "Monstrous Physique I";
				else if (rollB < 69) ss << "Rage";
				else if (rollB < 71) ss << "Ray of Exhaustion";
				else if (rollB < 74) ss << "Resinous Skin";
				else if (rollB < 76) ss << "Communal Resist Energy";
				else if (rollB < 79) ss << "Secret Page";
				else if (rollB < 81) ss << "Shrink Item";
				else if (rollB < 84) ss << "Sleet Storm";
				else if (rollB < 87) ss << "Spiked Pit";
				else if (rollB < 91) ss << "Undead Anatomy I";
				else if (rollB < 93) ss << "Versatile Weapon";
				else if (rollB < 96) ss << "Wind Wall";
				else if (rollB < 97) ss << "Illusory Script";
				else if (rollB < 100) ss << "Nondetection";
				else if (rollB < 101) ss << "Sepia Snake Sigil";
				else std::cout << "Error Code 802\n";
				break;
			case 4:
				if (rollB < 3) ss << "Acid Pit";
				else if (rollB < 7) ss << "Arcane Eye";
				else if (rollB < 11) ss << "Ball Lightning";
				else if (rollB < 14) ss << "Contagion";
				else if (rollB < 18) ss << "Greater Darkvision";
				else if (rollB < 20) ss << "Detect Scrying";
				else if (rollB < 24) ss << "Dragon's Breath";
				else if (rollB < 29) ss << "Greater False Life";
				else if (rollB < 33) ss << "Firefall";
				else if (rollB < 36) ss << "Lesser Geas";
				else if (rollB < 40) ss << "Ghost Wolf";
				else if (rollB < 42) ss << "Hallustd::cinatory Terrain";
				else if (rollB < 44) ss << "Illusory Wall";
				else if (rollB < 47) ss << "Locate Creature";
				else if (rollB < 51) ss << "Minor Creation";
				else if (rollB < 55) ss << "Monstrous Physique II";
				else if (rollB < 58) ss << "Obsidian Flow";
				else if (rollB < 60) ss << "Phantom Chariot";
				else if (rollB < 63) ss << "Rainbow Pattern";
				else if (rollB < 65) ss << "Mass Reduce Person";
				else if (rollB < 69) ss << "Remove Curse";
				else if (rollB < 72) ss << "Secure Shelter";
				else if (rollB < 75) ss << "Shadow Projection";
				else if (rollB < 80) ss << "Shocking Image";
				else if (rollB < 84) ss << "Telekinetic Charge";
				else if (rollB < 86) ss << "True Form";
				else if (rollB < 90) ss << "Vermin Shape I";
				else if (rollB < 95) ss << "Volcanic Storm";
				else if (rollB < 98) ss << "Wandering Star Motes";
				else if (rollB < 100) ss << "Fire Trap";
				else if (rollB < 101) ss << "Mnemonic Enhancer";
				else std::cout << "Error Code 836\n";
				break;
			case 5:
				if (rollB < 3) ss << "Absorb Toxicity";
				else if (rollB < 5) ss << "Animal Growth";
				else if (rollB < 7) ss << "Blight";
				else if (rollB < 10) ss << "Dream";
				else if (rollB < 14) ss << "Elemental Body II";
				else if (rollB < 16) ss << "Fabricate";
				else if (rollB < 20) ss << "Fire Snake";
				else if (rollB < 23) ss << "Hostile Juxtaposition";
				else if (rollB < 26) ss << "Hungry Pit";
				else if (rollB < 30) ss << "Icy Prison";
				else if (rollB < 34) ss << "Interposing Hand";
				else if (rollB < 37) ss << "Life Bubble";
				else if (rollB < 39) ss << "Mage's Faithful Hand";
				else if (rollB < 41) ss << "Mage's Private Sanctum";
				else if (rollB < 44) ss << "Major Creation";
				else if (rollB < 47) ss << "Mirage Arcana";
				else if (rollB < 51) ss << "Monstrous Physique III";
				else if (rollB < 55) ss << "Nightmare";
				else if (rollB < 57) ss << "Persistent Image";
				else if (rollB < 61) ss << "Planar Adaptation";
				else if (rollB < 65) ss << "Plant Shape I";
				else if (rollB < 69) ss << "Prying Eyes";
				else if (rollB < 71) ss << "Secret Chest";
				else if (rollB < 74) ss << "Seeming";
				else if (rollB < 77) ss << "Sonic Thrust";
				else if (rollB < 80) ss << "Suffocation";
				else if (rollB < 83) ss << "Telepathic Bond";
				else if (rollB < 85) ss << "Transmute Mud to Rock";
				else if (rollB < 87) ss << "Transmute Rock to Mud";
				else if (rollB < 91) ss << "Undead Anatomy II";
				else if (rollB < 95) ss << "Vermin Form";
				else if (rollB < 99) ss << "Wind Blades";
				else if (rollB < 101) ss << "False Vision";
				else std::cout << "Error Code 872\n";
				break;
			case 6:
				if (rollB < 5) ss << "Analyze Dweomer";
				else if (rollB < 9) ss << "Battlemind Link";
				else if (rollB < 13) ss << "Cloak of Dreams";
				else if (rollB < 16) ss << "Greater Contagion";
				else if (rollB < 21) ss << "Contagious Flame";
				else if (rollB < 27) ss << "Contingency";
				else if (rollB < 31) ss << "Control Water";
				else if (rollB < 36) ss << "Elemental Body III";
				else if (rollB < 40) ss << "Fluid Form";
				else if (rollB < 46) ss << "Forceful Hand";
				else if (rollB < 49) ss << "Freezing Sphere";
				else if (rollB < 54) ss << "Geas/Quest";
				else if (rollB < 58) ss << "Getaway";
				else if (rollB < 60) ss << "Guards and Wards";
				else if (rollB < 62) ss << "Mage's Lubrication";
				else if (rollB < 67) ss << "Monstrous Physique IV";
				else if (rollB < 69) ss << "Move Earth";
				else if (rollB < 72) ss << "Permanent Image";
				else if (rollB < 77) ss << "Plant Shape II";
				else if (rollB < 81) ss << "Repulsion";
				else if (rollB < 85) ss << "Sirocco";
				else if (rollB < 88) ss << "Tar Pool";
				else if (rollB < 93) ss << "Undead Anatomy III";
				else if (rollB < 96) ss << "Programmed Image";
				else if (rollB < 99) ss << "Undead to Death";
				else if (rollB < 101) ss << "Symbol of Persuasion";
				else std::cout << "Error Code 901\n";
				break;
			case 7:
				if (rollB < 4) ss << "Control Undead";
				else if (rollB < 8) ss << "Control Weather";
				else if (rollB < 11) ss << "Lesser Create Demiplane";
				else if (rollB < 15) ss << "Deflection";
				else if (rollB < 20) ss << "Elemental Body IV";
				else if (rollB < 24) ss << "Firebrand";
				else if (rollB < 30) ss << "Mass Fly";
				else if (rollB < 35) ss << "Giant Form I";
				else if (rollB < 41) ss << "Grasping Hand";
				else if (rollB < 45) ss << "Greater Hostile Juxtaposition";
				else if (rollB < 50) ss << "Ice Body";
				else if (rollB < 54) ss << "Insanity";
				else if (rollB < 57) ss << "Mage's Magnificent Mansion";
				else if (rollB < 62) ss << "Phantasmal Revenge";
				else if (rollB < 66) ss << "Plague Storm";
				else if (rollB < 71) ss << "Plant Shape III";
				else if (rollB < 75) ss << "Resonating Word";
				else if (rollB < 79) ss << "Sequester";
				else if (rollB < 82) ss << "Statue";
				else if (rollB < 85) ss << "Teleport Object";
				else if (rollB < 89) ss << "Walk Through Space";
				else if (rollB < 92) ss << "Vision";
				else if (rollB < 94) ss << "Instant Summons";
				else if (rollB < 97) ss << "Symbol of Stunning";
				else if (rollB < 99) ss << "Symbol of Weakness";
				else if (rollB < 101) ss << "Simulcrum";
				else std::cout << "Error Code 930\n";
				break;
			case 8:
				if (rollB < 5) ss << "Antipathy";
				else if (rollB < 11) ss << "Clenched Fist";
				else if (rollB < 13) ss << "Clone";
				else if (rollB < 16) ss << "Create Demiplane";
				else if (rollB < 20) ss << "Discern Location";
				else if (rollB < 25) ss << "Euphoric Tranquility";
				else if (rollB < 30) ss << "Frightful Aspect";
				else if (rollB < 35) ss << "Giant Form II";
				else if (rollB < 39) ss << "Iron Body";
				else if (rollB < 44) ss << "Moment of Prescience";
				else if (rollB < 48) ss << "Orb of the Void";
				else if (rollB < 53) ss << "Greater Prying Eyes";
				else if (rollB < 57) ss << "Screen";
				else if (rollB < 63) ss << "Greater Shadow Evocation";
				else if (rollB < 67) ss << "Greater Shout";
				else if (rollB < 73) ss << "Stormbolts";
				else if (rollB < 77) ss << "Sunburst";
				else if (rollB < 82) ss << "Undead Anatomy IV";
				else if (rollB < 88) ss << "Wall of Lava";
				else if (rollB < 92) ss << "Create Greater Undead";
				else if (rollB < 96) ss << "Sympathy";
				else if (rollB < 99) ss << "Symbol of Insanity";
				else if (rollB < 101) ss << "Binding (chaining)";
				else std::cout << "Error Code 956\n";
				break;
			case 9:
				if (rollB < 7) ss << "Greater Create Demiplane";
				else if (rollB < 16) ss << "Crushing Hand";
				else if (rollB < 24) ss << "Etherealness";
				else if (rollB < 32) ss << "Firey Body";
				else if (rollB < 39) ss << "Foresight";
				else if (rollB < 45) ss << "Heroic Invocation";
				else if (rollB < 51) ss << "Mass Icy Prison";
				else if (rollB < 58) ss << "Ride the Lightning";
				else if (rollB < 66) ss << "Shades";
				else if (rollB < 73) ss << "Soul Bind";
				else if (rollB < 80) ss << "Tsunami";
				else if (rollB < 89) ss << "Wail of the Banshee";
				else if (rollB < 96) ss << "Winds of Vengeance";
				else if (rollB < 101) ss << "Refuge";
				else std::cout << "Error Code 973\n";
				break;
			default:
				std::cout << "Error Code 976\n";
				break;
			}
		else if (rollA < 91)
			switch (lvl)
			{
			case 0:
				if (rollB < 12) ss << "Bleed";
				else if (rollB < 22) ss << "Create Water";
				else if (rollB < 35) ss << "Detect Magic";
				else if (rollB < 45) ss << "Know Direction";
				else if (rollB < 56) ss << "Light";
				else if (rollB < 66) ss << "Mending";
				else if (rollB < 76) ss << "Purify Food and Drink";
				else if (rollB < 89) ss << "Read Magic";
				else if (rollB < 101) ss << "Stablize";
				else std::cout << "Error Code 992\n";
				break;
			case 1:
				if (rollB < 5) ss << "Bane";
				else if (rollB < 11) ss << "Bless";
				else if (rollB < 16) ss << "Cause Fear";
				else if (rollB < 20) ss << "Command";
				else if (rollB < 23) ss << "Comprehend Languages";
				else if (rollB < 29) ss << "Cure Light Wounds";
				else if (rollB < 31) ss << "Detect Chaos";
				else if (rollB < 33) ss << "Detect Evil";
				else if (rollB < 35) ss << "Detect Good";
				else if (rollB < 37) ss << "Detect Law";
				else if (rollB < 40) ss << "Detect Undead";
				else if (rollB < 46) ss << "Divine Favor";
				else if (rollB < 49) ss << "Doom";
				else if (rollB < 53) ss << "Entangle";
				else if (rollB < 58) ss << "Inflict Light Wounds";
				else if (rollB < 62) ss << "Magic Fang";
				else if (rollB < 66) ss << "Obscuring Mist";
				else if (rollB < 69) ss << "Produce Flame";
				else if (rollB < 72) ss << "Protection from Chaos";
				else if (rollB < 75) ss << "Protection from Evil";
				else if (rollB < 78) ss << "Protection from Good";
				else if (rollB < 81) ss << "Protection from Law";
				else if (rollB < 85) ss << "Remove Fear";
				else if (rollB < 89) ss << "Sanctuary";
				else if (rollB < 95) ss << "Shield of Faith";
				else if (rollB < 98) ss << "Summon Monster I";
				else if (rollB < 101) ss << "Summon Nature's Ally";
				else std::cout << "Error Code 1022\n";
				break;
			case 2:
				if (rollB < 5) ss << "Aid";
				else if (rollB < 7) ss << "Align Weapon";
				else if (rollB < 9) ss << "Animal Messenger";
				else if (rollB < 14) ss << "Barkskin";
				else if (rollB < 17) ss << "Bear's Endurance";
				else if (rollB < 20) ss << "Bull's Strength";
				else if (rollB < 23) ss << "Cat's Grace";
				else if (rollB < 25) ss << "Chill Metal";
				else if (rollB < 31) ss << "Cure Moderate Wounds";
				else if (rollB < 34) ss << "Darkness";
				else if (rollB < 37) ss << "Delay Poison";
				else if (rollB < 40) ss << "Eagle's Splendor";
				else if (rollB < 42) ss << "Find Traps";
				else if (rollB < 45) ss << "Flame Blade";
				else if (rollB < 47) ss << "Fog Cloud";
				else if (rollB < 51) ss << "Heat Metal";
				else if (rollB < 53) ss << "Hold Animal";
				else if (rollB < 57) ss << "Hold Person";
				else if (rollB < 61) ss << "Inflict Moderate Wounds";
				else if (rollB < 64) ss << "Owl's Wisdom";
				else if (rollB < 66) ss << "Remove Paralysis";
				else if (rollB < 69) ss << "Resist Energy";
				else if (rollB < 74) ss << "Lesser Restoration";
				else if (rollB < 78) ss << "Shield Other";
				else if (rollB < 82) ss << "Silence";
				else if (rollB < 86) ss << "Sound Burst";
				else if (rollB < 90) ss << "Spiritual Weapon";
				else if (rollB < 92) ss << "Summon Monster II";
				else if (rollB < 94) ss << "Summon Nature's Ally II";
				else if (rollB < 96) ss << "Summon Swarm";
				else if (rollB < 98) ss << "Zone of Truth";
				else if (rollB < 101) ss << "Augry";
				else std::cout << "Error Code 1057\n";
				break;
			case 3:
				if (rollB < 4) ss << "Bestow Curse";
				else if (rollB < 9) ss << "Call Lightning";
				else if (rollB < 16) ss << "Cure Serious Wounds";
				else if (rollB < 20) ss << "Daylight";
				else if (rollB < 24) ss << "Deeper Darkness";
				else if (rollB < 29) ss << "Dispel Magic";
				else if (rollB < 34) ss << "Inflict Serious Wounds";
				else if (rollB < 38) ss << "Invisibility Purge";
				else if (rollB < 41) ss << "Locate Object";
				else if (rollB < 43) ss << "Magic Circle against Chaos";
				else if (rollB < 45) ss << "Magic Circle against Evil";
				else if (rollB < 47) ss << "Magic Circle against Good";
				else if (rollB < 49) ss << "Magic Circle against Law";
				else if (rollB < 53) ss << "Greater Magic Fang";
				else if (rollB < 58) ss << "Magic Vestment";
				else if (rollB < 60) ss << "Poison";
				else if (rollB < 66) ss << "Prayer";
				else if (rollB < 69) ss << "Protection from Energy";
				else if (rollB < 71) ss << "Remove Blindness/Deafness";
				else if (rollB < 74) ss << "Remove Curse";
				else if (rollB < 77) ss << "Remove Disease";
				else if (rollB < 80) ss << "Searing Light";
				else if (rollB < 82) ss << "Sleet Storm";
				else if (rollB < 86) ss << "Speak with Dead";
				else if (rollB < 88) ss << "Stone Shape";
				else if (rollB < 90) ss << "Summon Monster III";
				else if (rollB < 92) ss << "Summon Nature's Ally III";
				else if (rollB < 96) ss << "Water Breathing";
				else if (rollB < 98) ss << "Water Walk";
				else if (rollB < 101) ss << "Animate Dead";
				else std::cout << "Error Code 1090\n";
				break;
			case 4:
				if (rollB < 5) ss << "Air Walk";
				else if (rollB < 8) ss << "Chaos Hammer";
				else if (rollB < 16) ss << "Cure Critical Wounds";
				else if (rollB < 20) ss << "Death Ward";
				else if (rollB < 23) ss << "Dimensional Anchor";
				else if (rollB < 26) ss << "Discern Lies";
				else if (rollB < 29) ss << "Dismissal";
				else if (rollB < 34) ss << "Divine Power";
				else if (rollB < 40) ss << "Flame Strike";
				else if (rollB < 44) ss << "Freedom of Movement";
				else if (rollB < 47) ss << "Holy Smite";
				else if (rollB < 52) ss << "Inflict Critical Wounds";
				else if (rollB < 57) ss << "Greater Magic Weapon";
				else if (rollB < 62) ss << "Neutalize Poison";
				else if (rollB < 65) ss << "Order's Wrath";
				else if (rollB < 69) ss << "Poison";
				else if (rollB < 74) ss << "Spell Immunity";
				else if (rollB < 78) ss << "Spike Stones";
				else if (rollB < 81) ss << "Summon Monster IV";
				else if (rollB < 84) ss << "Summon Nature's Ally IV";
				else if (rollB < 87) ss << "Tongues";
				else if (rollB < 90) ss << "Unholy Blight";
				else if (rollB < 94) ss << "Divination";
				else if (rollB < 97) ss << "Lesser Planar Ally";
				else if (rollB < 101) ss << "Restoration";
				else std::cout << "Error Code 1118\n";
				break;
			case 5:
				if (rollB < 3) ss << "Animal Growth";
				else if (rollB < 5) ss << "Atonement";
				else if (rollB < 8) ss << "Baleful Polymorph";
				else if (rollB < 12) ss << "Break Enchantment";
				else if (rollB < 17) ss << "Breath of Life";
				else if (rollB < 22) ss << "Call Lightning Storm";
				else if (rollB < 26) ss << "Greater Command";
				else if (rollB < 31) ss << "Mass Cure Light Wounds";
				else if (rollB < 35) ss << "Death Ward";
				else if (rollB < 38) ss << "Disrupting Weapon";
				else if (rollB < 43) ss << "Mass Inflict Light Wounds";
				else if (rollB < 48) ss << "Plane Shift";
				else if (rollB < 54) ss << "Rightwous Might";
				else if (rollB < 58) ss << "Scrying";
				else if (rollB < 63) ss << "Slay Living";
				else if (rollB < 68) ss << "Spell Resistance";
				else if (rollB < 71) ss << "Summon Monster V";
				else if (rollB < 74) ss << "Summon Nature's Ally V";
				else if (rollB < 76) ss << "Tree Stride";
				else if (rollB < 78) ss << "Wall of Fire";
				else if (rollB < 81) ss << "Wall of Stone";
				else if (rollB < 83) ss << "Wall of Thorns";
				else if (rollB < 88) ss << "True Seeing";
				else if (rollB < 92) ss << "Commune";
				else if (rollB < 95) ss << "Awaken";
				else if (rollB < 101) ss << "Raise Dead";
				else std::cout << "Error Code 1147\n";
				break;
			case 6:
				if (rollB < 6) ss << "Mass Bear's Endurance";
				else if (rollB < 12) ss << "Blade Barrier";
				else if (rollB < 17) ss << "Mass Bull's Strength";
				else if (rollB < 22) ss << "Mass Cat's Grace";
				else if (rollB < 28) ss << "Mass Cure Moderate Wounds";
				else if (rollB < 33) ss << "Greater Dispel Magic";
				else if (rollB < 38) ss << "Mass Eagle's Splendor";
				else if (rollB < 44) ss << "Find the Path";
				else if (rollB < 48) ss << "Fire Seeds";
				else if (rollB < 56) ss << "Harm";
				else if (rollB < 64) ss << "Heal";
				else if (rollB < 70) ss << "Heroes' Feast";
				else if (rollB < 75) ss << "Mass Inflict Moderate Wounds";
				else if (rollB < 79) ss << "Liveoak";
				else if (rollB < 84) ss << "Mass Owl's Wisdom";
				else if (rollB < 88) ss << "Summon Monster VI";
				else if (rollB < 82) ss << "Summon Nature's Ally VI";
				else if (rollB < 97) ss << "Word of Recall";
				else if (rollB < 101) ss << "Planar Ally";
				else std::cout << "Error Code 1169\n";
				break;
			case 7:
				if (rollB < 5) ss << "Blasphemy";
				else if (rollB < 11) ss << "Control Weather";
				else if (rollB < 18) ss << "Creeping Doom";
				else if (rollB < 25) ss << "Mass Cure Serious Wounds";
				else if (rollB < 29) ss << "Dictum";
				else if (rollB < 34) ss << "Ethereal Jaunt";
				else if (rollB < 41) ss << "Fire Storm";
				else if (rollB < 45) ss << "Holy Word";
				else if (rollB < 51) ss << "Mass Inflict Serious Wounds";
				else if (rollB < 56) ss << "Regenerate";
				else if (rollB < 61) ss << "Repulsion";
				else if (rollB < 66) ss << "Greater Scrying";
				else if (rollB < 70) ss << "Summon Monster VII";
				else if (rollB < 74) ss << "Summon Nature's Ally VII";
				else if (rollB < 79) ss << "Sunbeam";
				else if (rollB < 83) ss << "Word of Chaos";
				else if (rollB < 90) ss << "Destruction";
				else if (rollB < 95) ss << "Greater Restoration";
				else if (rollB < 101) ss << "Resurrection";
				else std::cout << "Error Code 1191\n";
				break;
			case 8:
				if (rollB < 9) ss << "Antimagic Field";
				else if (rollB < 15) ss << "Cloak of Chaos";
				else if (rollB < 24) ss << "Mass Cure Critical Wounds";
				else if (rollB < 32) ss << "Earthquake";
				else if (rollB < 39) ss << "Finger of Death";
				else if (rollB < 45) ss << "Holy Aura";
				else if (rollB < 52) ss << "Mass Inflict Critical Wounds";
				else if (rollB < 60) ss << "Reverse Gravity";
				else if (rollB < 66) ss << "Shield of Law";
				else if (rollB < 74) ss << "Greater Spell Immunity";
				else if (rollB < 79) ss << "Summon Monster VIII";
				else if (rollB < 84) ss << "Summon Nature's Ally VIII";
				else if (rollB < 90) ss << "Sunburst";
				else if (rollB < 96) ss << "Unholy Aura";
				else if (rollB < 101) ss << "Greater Planar Ally";
				else std::cout << "Error Code 1209\n";
				break;
			case 9:
				if (rollB < 8) ss << "Elemental Swarm";
				else if (rollB < 16) ss << "Energy Drain";
				else if (rollB < 23) ss << "Etherealness";
				else if (rollB < 31) ss << "Gate";
				else if (rollB < 41) ss << "Mass Heal";
				else if (rollB < 49) ss << "Implosion";
				else if (rollB < 59) ss << "Miracle";
				else if (rollB < 66) ss << "Shambler";
				else if (rollB < 74) ss << "Shapechange";
				else if (rollB < 82) ss << "Storm of Vengeance";
				else if (rollB < 88) ss << "Summon Monster IX";
				else if (rollB < 94) ss << "Summon Nature's Ally IX";
				else if (rollB < 101) ss << "True Resurrection";
				else std::cout << "Error Code 1282\n";
				break;
			default:
				std::cout << "Error Code 1228\n";
				break;
			}
		else if (rollA < 101)
			switch (lvl)
			{
			case 0:
				if (rollB < 16) ss << "Detect Poison";
				else if (rollB < 34) ss << "Flare";
				else if (rollB < 51) ss << "Guidance";
				else if (rollB < 69) ss << "Resistance";
				else if (rollB < 86) ss << "Spark";
				else if (rollB < 101) ss << "Virtue";
				else std::cout << "Error Code 1241\n";
				break;
			case 1:
				if (rollB < 5) ss << "Ant Haul";
				else if (rollB < 8) ss << "Aspect of the Falcon";
				else if (rollB < 10) ss << "Calm Animals";
				else if (rollB < 13) ss << "Charm Animal";
				else if (rollB < 16) ss << "Compel Hostility";
				else if (rollB < 18) ss << "Deathwatch";
				else if (rollB < 19) ss << "Detect Animals or Plants";
				else if (rollB < 21) ss << "Detect Snares and Pits";
				else if (rollB < 24) ss << "Diagnose Disease";
				else if (rollB < 28) ss << "Endure Elements";
				else if (rollB < 31) ss << "Entropic Shield";
				else if (rollB < 34) ss << "Faerie Fire";
				else if (rollB < 37) ss << "Feather Step";
				else if (rollB < 40) ss << "Forbid Action";
				else if (rollB < 43) ss << "Frostbite";
				else if (rollB < 47) ss << "Goodberry";
				else if (rollB < 48) ss << "Hide From Animals";
				else if (rollB < 50) ss << "Hide From Undead";
				else if (rollB < 53) ss << "Hydraulic Push";
				else if (rollB < 56) ss << "Jump";
				else if (rollB < 60) ss << "Keen Senses";
				else if (rollB < 63) ss << "Liberating Command";
				else if (rollB < 66) ss << "Longstrider";
				else if (rollB < 69) ss << "Magic Stone";
				else if (rollB < 73) ss << "Pass Without Trace";
				else if (rollB < 75) ss << "Remove Sickness";
				else if (rollB < 76) ss << "Sanctify Corpse";
				else if (rollB < 79) ss << "Shillelagh";
				else if (rollB < 82) ss << "Speak with Animals";
				else if (rollB < 86) ss << "Stone Fist";
				else if (rollB < 89) ss << "Stone Shield";
				else if (rollB < 92) ss << "Sun Metal";
				else if (rollB < 96) ss << "Touch of the Sea";
				else if (rollB < 99) ss << "Bless Water";
				else if (rollB < 101) ss << "Curse Water";
				else std::cout << "Error Code 1279\n";
				break;
			case 2:
				if (rollB < 5) ss << "Animal Aspect";
				else if (rollB < 7) ss << "Animal Trace";
				else if (rollB < 11) ss << "Lesser Animate Dead";
				else if (rollB < 14) ss << "Arrow of Law";
				else if (rollB < 18) ss << "Aspect of the Bear";
				else if (rollB < 21) ss << "Blessing of Courage and Life";
				else if (rollB < 25) ss << "Calm Emotions";
				else if (rollB < 28) ss << "Death Knell";
				else if (rollB < 31) ss << "Dread Bolt";
				else if (rollB < 35) ss << "Effortless Armor";
				else if (rollB < 38) ss << "Enthrall";
				else if (rollB < 42) ss << "Flaming Sphere";
				else if (rollB < 44) ss << "Gentle Repose";
				else if (rollB < 47) ss << "Grace";
				else if (rollB < 49) ss << "Groundswell";
				else if (rollB < 52) ss << "Gust of Wind";
				else if (rollB < 54) ss << "Instant Armor";
				else if (rollB < 56) ss << "Instrument of Agony";
				else if (rollB < 59) ss << "Make Whole";
				else if (rollB < 61) ss << "Reduce Animal";
				else if (rollB < 63) ss << "Scent Trail";
				else if (rollB < 66) ss << "Shard of Chaos";
				else if (rollB < 69) ss << "Share Language";
				else if (rollB < 71) ss << "Shatter";
				else if (rollB < 74) ss << "Soften Earth and Stone";
				else if (rollB < 77) ss << "Spear of Purity";
				else if (rollB < 80) ss << "Spider Climb";
				else if (rollB < 83) ss << "Status";
				else if (rollB < 85) ss << "Tree Shape";
				else if (rollB < 86) ss << "Undetectable Alignment";
				else if (rollB < 89) ss << "Warp Wood";
				else if (rollB < 92) ss << "Weapon of Awe";
				else if (rollB < 94) ss << "Wood Shape";
				else if (rollB < 96) ss << "Consecreate";
				else if (rollB < 98) ss << "Desecrate";
				else if (rollB < 99) ss << "Fire Trap";
				else if (rollB < 101) ss << "Masterwork Transformation";
				else std::cout << "Error Code 1319\n";
				break;
			case 3:
				if (rollB < 5) ss << "Aqueous Orb";
				else if (rollB < 9) ss << "Archon's Aura";
				else if (rollB < 13) ss << "Bestow Inshight";
				else if (rollB < 17) ss << "Blindness/Deafness";
				else if (rollB < 20) ss << "Burst of Nettles";
				else if (rollB < 23) ss << "Chain of Perdition";
				else if (rollB < 27) ss << "Contagion";
				else if (rollB < 31) ss << "Create Food and Water";
				else if (rollB < 35) ss << "Daybreak Arrow";
				else if (rollB < 37) ss << "Diminish Plants";
				else if (rollB < 41) ss << "Discovery Torch";
				else if (rollB < 46) ss << "Dominate Animal";
				else if (rollB < 49) ss << "Guiding Star";
				else if (rollB < 52) ss << "Helping Hand";
				else if (rollB < 57) ss << "Meld into Stone";
				else if (rollB < 59) ss << "Obscure Object";
				else if (rollB < 62) ss << "Plant Growth";
				else if (rollB < 65) ss << "Quench";
				else if (rollB < 68) ss << "Shifting Sands";
				else if (rollB < 73) ss << "Snare";
				else if (rollB < 76) ss << "Speak with Plants";
				else if (rollB < 81) ss << "Spike Growth";
				else if (rollB < 84) ss << "Vision of Hell";
				else if (rollB < 88) ss << "Wind Wall";
				else if (rollB < 91) ss << "Wrathful Mantle";
				else if (rollB < 94) ss << "Continual Flame";
				else if (rollB < 97) ss << "Nap Stack";
				else if (rollB < 99) ss << "Glyph of Warding";
				else if (rollB < 101) ss << "Symbol of Healing";
				else std::cout << "Error Code 1351\n";
				break;
			case 4:
				if (rollB < 5) ss << "Absorb Toxicity";
				else if (rollB < 7) ss << "Antiplant Shell";
				else if (rollB < 12) ss << "Aspect of the Stag";
				else if (rollB < 16) ss << "Aura of Doom";
				else if (rollB < 22) ss << "Ball Lightning";
				else if (rollB < 26) ss << "Blessing of Fervor";
				else if (rollB < 39) ss << "Blight";
				else if (rollB < 32) ss << "Command Plants";
				else if (rollB < 36) ss << "Control Water";
				else if (rollB < 40) ss << "Debilitating Portent";
				else if (rollB < 44) ss << "Giant Vermin";
				else if (rollB < 50) ss << "Ice Storm";
				else if (rollB < 56) ss << "Imbue with Spell Ability";
				else if (rollB < 60) ss << "Plague Carrier";
				else if (rollB < 64) ss << "Planar Adaptation";
				else if (rollB < 68) ss << "Communal Protection from Energy";
				else if (rollB < 73) ss << "Reincarnate";
				else if (rollB < 76) ss << "Repel Vermin";
				else if (rollB < 79) ss << "Rusting Grasp";
				else if (rollB < 84) ss << "Scrying";
				else if (rollB < 88) ss << "Sending";
				else if (rollB < 91) ss << "Spiritual Ally";
				else if (rollB < 94) ss << "Thorn Body";
				else if (rollB < 99) ss << "Volcanic Storm";
				else if (rollB < 101) ss << "Symbol of Slowing";
				else std::cout << "Error Code 1379\n";
				break;
			case 5:
				if (rollB < 4) ss << "Communal Air Walk";
				else if (rollB < 9) ss << "Aspect of the Wolf";
				else if (rollB < 12) ss << "Blessing of the Salamander";
				else if (rollB < 16) ss << "Cleanse";
				else if (rollB < 22) ss << "Commune with Nature";
				else if (rollB < 25) ss << "Greater Contagion";
				else if (rollB < 29) ss << "Control Winds";
				else if (rollB < 32) ss << "Dispel Chaos";
				else if (rollB < 35) ss << "Dispel Evil";
				else if (rollB < 38) ss << "Dispel Good";
				else if (rollB < 41) ss << "Dispel Law";
				else if (rollB < 44) ss << "Fickle Winds";
				else if (rollB < 47) ss << "Greater Forbid Action";
				else if (rollB < 53) ss << "Insect Plague";
				else if (rollB < 56) ss << "Life Bubble";
				else if (rollB < 59) ss << "Mark of Justice";
				else if (rollB < 64) ss << "Pillar of Life";
				else if (rollB < 67) ss << "Serenity";
				else if (rollB < 73) ss << "Snake Staff";
				else if (rollB < 77) ss << "Communal Spell Immunity";
				else if (rollB < 80) ss << "Transmute Mud to Rock";
				else if (rollB < 83) ss << "Wind Blades";
				else if (rollB < 87) ss << "Stoneskin";
				else if (rollB < 91) ss << "Hallow";
				else if (rollB < 93) ss << "Symbol of Pain";
				else if (rollB < 95) ss << "Symbol of Sleep";
				else if (rollB < 97) ss << "Unhallow";
				else if (rollB < 99) ss << "Hallow (with fixed 4th level spell)";
				else if (rollB < 101) ss << "Unhallow (with fixed 4th level spell)";
				else std::cout << "Error Code 1411\n";
				break;
			case 6:
				if (rollB < 6) ss << "Animate Objects";
				else if (rollB < 10) ss << "Antilife Shell";
				else if (rollB < 16) ss << "Banishment";
				else if (rollB < 20) ss << "Cold Ice Strike";
				else if (rollB < 24) ss << "Dust Form";
				else if (rollB < 30) ss << "Geas/Quest";
				else if (rollB < 34) ss << "Ironwood";
				else if (rollB < 38) ss << "Joyful Rapture";
				else if (rollB < 43) ss << "Move Earth";
				else if (rollB < 47) ss << "Plague Storm";
				else if (rollB < 52) ss << "Mass Planar Adaptation";
				else if (rollB < 55) ss << "Repel Wood";
				else if (rollB < 60) ss << "Sirocco";
				else if (rollB < 64) ss << "Spellstaff";
				else if (rollB < 67) ss << "Stone Tell";
				else if (rollB < 71) ss << "Swarm Sense";
				else if (rollB < 75) ss << "Tar Pool";
				else if (rollB < 78) ss << "Trasport Via Plants";
				else if (rollB < 84) ss << "Wind Walk";
				else if (rollB < 87) ss << "Create Undead";
				else if (rollB < 91) ss << "Greater Glyph of Warding";
				else if (rollB < 93) ss << "Undeath to Death";
				else if (rollB < 96) ss << "Symbol of Fear";
				else if (rollB < 99) ss << "Forbiddance";
				else if (rollB < 101) ss << "Symbol of Persuasion";
				else std::cout << "Error Code 1439\n";
				break;
			case 7:
				if (rollB < 9) ss << "Animate Plants";
				else if (rollB < 18) ss << "Changestaff";
				else if (rollB < 25) ss << "Circle of Clarity";
				else if (rollB < 31) ss << "Lesser Create Demiplane";
				else if (rollB < 39) ss << "Jolting Portent";
				else if (rollB < 46) ss << "Rampart";
				else if (rollB < 54) ss << "Scouring Winds";
				else if (rollB < 61) ss << "Siege of Trees";
				else if (rollB < 68) ss << "Transmute Metal to Wood";
				else if (rollB < 77) ss << "Vortex";
				else if (rollB < 84) ss << "Waves of Ecstacy";
				else if (rollB < 90) ss << "Refuge";
				else if (rollB < 96) ss << "Symbol of Stunning";
				else if (rollB < 101) ss << "Symbol of Weakness";
				break;
			case 8:
				if (rollB < 8) ss << "Animal Shapes";
				else if (rollB < 14) ss << "Blood Mist";
				else if (rollB < 19) ss << "Control Plants";
				else if (rollB < 25) ss << "Create Demiplane";
				else if (rollB < 32) ss << "Dimensional Lock";
				else if (rollB < 38) ss << "Discern Location";
				else if (rollB < 43) ss << "Euphoric Tranquility";
				else if (rollB < 50) ss << "Frightful Aspect";
				else if (rollB < 57) ss << "Orb of the Void";
				else if (rollB < 62) ss << "Repel Metal or Stone";
				else if (rollB < 69) ss << "Seamantle";
				else if (rollB < 76) ss << "Storm Bolts";
				else if (rollB < 84) ss << "Whirlwind";
				else if (rollB < 89) ss << "Create Greater Undead";
				else if (rollB < 96) ss << "Symbol of Death";
				else if (rollB < 101) ss << "Symbol of Insanity";
				break;
			case 9:
				if (rollB < 9) ss << "Antipathy";
				else if (rollB < 16) ss << "Clashing Rocks";
				else if (rollB < 23) ss << "Greater Create Demiplane";
				else if (rollB < 32) ss << "Foresight";
				else if (rollB < 40) ss << "Overwhelming Presence";
				else if (rollB < 48) ss << "Polar Midnight";
				else if (rollB < 57) ss << "Soul Bind";
				else if (rollB < 65) ss << "Greater Spell Immunity";
				else if (rollB < 72) ss << "Summon Froghemoth";
				else if (rollB < 81) ss << "Winds of Vengeance";
				else if (rollB < 88) ss << "World Wave";
				else if (rollB < 95) ss << "Astral Projection";
				else if (rollB < 101) ss << "Sympathy";
				else std::cout << "Error Code 1489\n";
				break;
			default:
				std::cout << "Error Code 1492\n";
				break;
			}
		else std::cout << "Error Code 1495\n";
	}
	return ss.str();
}
int getWandLevel(int subtype)
{
	int rollG = roll(1, 100);
	switch (subtype)
	{
	case 1:
		if (rollG < 41) return 0;
		else if (rollG < 101) return 1;
		else std::cout << "Error Code 1507\n";
		break;
	case 2:
		if (rollG < 81) return 1;
		else if (rollG < 101) return 2;
		else std::cout << "Error Code 1512\n";
		break;
	case 3:
		if (rollG < 76) return 2;
		else if (rollG < 101) return 3;
		else std::cout << "Error Code 1517\n";
		break;
	case 4:
		if (rollG < 21) return 2;
		else if (rollG < 101) return 3;
		else std::cout << "Error Code 1522\n";
		break;
	case 5:
		if (rollG < 61) return 3;
		else if (rollG < 101) return 4;
		else std::cout << "Error Code 1527\n";
		break;
	case 6:
		if (rollG < 31) return 3;
		else if (rollG < 101) return 4;
		else std::cout << "Error Code 1532\n";
		break;
	default:
		std::cout << "Error Code 1535\n";
		break;
	}
	return -1;
}
std::string wandGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int rollA = roll(1, 100), rollB = roll(1, 100), lvl = getWandLevel(subtype);
		ss << "Wand of ";
		if (rollA < 76)
			switch (lvl)
			{
			case 0:
				if (rollB < 8) ss << "Acid Splash";
				else if (rollB < 15) ss << "Create Water";
				else if (rollB < 21) ss << "Daze";
				else if (rollB < 29) ss << "Detect Magic";
				else if (rollB < 35) ss << "Ghost Sound";
				else if (rollB < 43) ss << "Light";
				else if (rollB < 50) ss << "Mage Hand";
				else if (rollB < 56) ss << "Mending";
				else if (rollB < 61) ss << "Message";
				else if (rollB < 67) ss << "Prestidigitation";
				else if (rollB < 74) ss << "Purify Food and Drink";
				else if (rollB < 82) ss << "Ray of Frost";
				else if (rollB < 89) ss << "Read Magic";
				else if (rollB < 96) ss << "Stabilize";
				else if (rollB < 101) ss << "Touch of Fatigue";
				else std::cout << "Error Code 1566\n";
				break;
			case 1:
				if (rollB < 3) ss << "Alarm";
				else if (rollB < 4) ss << "Animate Rope";
				else if (rollB < 6) ss << "Bane";
				else if (rollB < 12) ss << "Bless";
				else if (rollB < 15) ss << "Burning Hands";
				else if (rollB < 18) ss << "Cause Fear";
				else if (rollB < 20) ss << "Charm Person";
				else if (rollB < 22) ss << "Color Spray";
				else if (rollB < 24) ss << "Command";
				else if (rollB < 25) ss << "Comprehand Languages";
				else if (rollB < 32) ss << "Cure Light Wounds";
				else if (rollB < 34) ss << "Disguise Self";
				else if (rollB < 38) ss << "Divine Favor";
				else if (rollB < 39) ss << "Endure Elements";
				else if (rollB < 42) ss << "Enlarege Person";
				else if (rollB < 44) ss << "Entangle";
				else if (rollB < 46) ss << "Expeditious Retreat";
				else if (rollB < 47) ss << "Feather Fall";
				else if (rollB < 49) ss << "Grease";
				else if (rollB < 51) ss << "Identify";
				else if (rollB < 53) ss << "Inflict Light Wounds";
				else if (rollB < 59) ss << "Mage Armor";
				else if (rollB < 61) ss << "Magic Fang";
				else if (rollB < 68) ss << "Magic Missle";
				else if (rollB < 69) ss << "Magic Stone";
				else if (rollB < 71) ss << "Magic Weapon";
				else if (rollB < 72) ss << "Obscuring Mist";
				else if (rollB < 74) ss << "Produce Flame";
				else if (rollB < 75) ss << "Protection from Chaos";
				else if (rollB < 76) ss << "Protection from Evil";
				else if (rollB < 77) ss << "Protection from Good";
				else if (rollB < 78) ss << "Protection from Law";
				else if (rollB < 80) ss << "Ray of Efeeblement";
				else if (rollB < 82) ss << "Remove Fear";
				else if (rollB < 85) ss << "Shield";
				else if (rollB < 87) ss << "Shield of Faith";
				else if (rollB < 88) ss << "Shillelagh";
				else if (rollB < 90) ss << "Shocking Grasp";
				else if (rollB < 91) ss << "Silent Image";
				else if (rollB < 95) ss << "Sleep";
				else if (rollB < 96) ss << "Summon Monster I";
				else if (rollB < 97) ss << "Summon Nature's Ally I";
				else if (rollB < 100) ss << "True Strike";
				else if (rollB < 101) ss << "Unseen Servant";
				else std::cout << "Error Code 1613\n";
				break;
			case 2:
				if (rollB < 3) ss << "Acid Arrow";
				else if (rollB < 4) ss << "Aid";
				else if (rollB < 6) ss << "Alter Self";
				else if (rollB < 8) ss << "Barkskin";
				else if (rollB < 11) ss << "Bear's Endurance";
				else if (rollB < 12) ss << "Blur";
				else if (rollB < 15) ss << "Bull's Strength";
				else if (rollB < 17) ss << "Cat's Grace";
				else if (rollB < 23) ss << "Cure Moderate Wounds";
				else if (rollB < 26) ss << "Darkness";
				else if (rollB < 27) ss << "Darkvision";
				else if (rollB < 28) ss << "Delay Poison";
				else if (rollB < 30) ss << "Eagle's Splendor";
				else if (rollB < 31) ss << "False Life";
				else if (rollB < 32) ss << "Find Traps";
				else if (rollB < 33) ss << "Flame Blade";
				else if (rollB < 34) ss << "Flame Sphere";
				else if (rollB < 36) ss << "Fog Cloud";
				else if (rollB < 38) ss << "Fox's Cunning";
				else if (rollB < 39) ss << "Glitterdust";
				else if (rollB < 41) ss << "Heat Metal";
				else if (rollB < 44) ss << "Hold Person";
				else if (rollB < 47) ss << "Inflict Moderate Wounds";
				else if (rollB < 52) ss << "Invisibility";
				else if (rollB < 53) ss << "Knock";
				else if (rollB < 55) ss << "Levitate";
				else if (rollB < 56) ss << "Minor Image";
				else if (rollB < 58) ss << "Mirror Image";
				else if (rollB < 60) ss << "Owl's Wisdom";
				else if (rollB < 61) ss << "Pyrotechnics";
				else if (rollB < 62) ss << "Remove Paralysis";
				else if (rollB < 65) ss << "Resist Energy";
				else if (rollB < 67) ss << "Lesser Restoration";
				else if (rollB < 72) ss << "Scorching Ray";
				else if (rollB < 74) ss << "See Invisibility";
				else if (rollB < 75) ss << "Shatter";
				else if (rollB < 77) ss << "Shield Other";
				else if (rollB < 79) ss << "Silence";
				else if (rollB < 82) ss << "Sound Burst";
				else if (rollB < 84) ss << "Spider Climb";
				else if (rollB < 87) ss << "Spiritual Weapon";
				else if (rollB < 89) ss << "Summon Monster II";
				else if (rollB < 91) ss << "Summon Nature's Ally II";
				else if (rollB < 93) ss << "Summon Swarm";
				else if (rollB < 97) ss << "Web";
				else if (rollB < 98) ss << "Whispering Wind";
				else if (rollB < 100) ss << "Augury";
				else if (rollB < 101) ss << "Fire Trap";
				else std::cout << "Error Code 1664\n";
				break;
			case 3:
				if (rollB < 3) ss << "Beast Shape I";
				else if (rollB < 5) ss << "Blink";
				else if (rollB < 8) ss << "Call Lightning";
				else if (rollB < 9) ss << "Create Food and Water";
				else if (rollB < 15) ss << "Cure Serious Wounds";
				else if (rollB < 17) ss << "Daylight";
				else if (rollB < 19) ss << "Deep Slumber";
				else if (rollB < 21) ss << "Deeper Darkness";
				else if (rollB < 26) ss << "Dispel Magic";
				else if (rollB < 29) ss << "Displacement";
				else if (rollB < 35) ss << "Fireball";
				else if (rollB < 36) ss << "Flame Arrow";
				else if (rollB < 38) ss << "Fly";
				else if (rollB < 41) ss << "Gaseous Form";
				else if (rollB < 43) ss << "Heroism";
				else if (rollB < 46) ss << "Haste";
				else if (rollB < 48) ss << "Inflict Serious Wounds";
				else if (rollB < 49) ss << "Invisibility Purge";
				else if (rollB < 51) ss << "Invisibility Sphere";
				else if (rollB < 56) ss << "Keen Edge";
				else if (rollB < 57) ss << "Lightning Bolt";
				else if (rollB < 58) ss << "Magic Circle against Chaos";
				else if (rollB < 59) ss << "Magic Circle against Evil";
				else if (rollB < 60) ss << "Magic Circle against Good";
				else if (rollB < 61) ss << "Magic Circle against Law";
				else if (rollB < 63) ss << "Greater Magic Fang";
				else if (rollB < 65) ss << "Magic Vestment";
				else if (rollB < 67) ss << "Greater Magic Weapon";
				else if (rollB < 71) ss << "Major Image";
				else if (rollB < 75) ss << "Prayer";
				else if (rollB < 76) ss << "Protection from Energy";
				else if (rollB < 78) ss << "Remove Blindness/Deafness";
				else if (rollB < 80) ss << "Remove Curse";
				else if (rollB < 83) ss << "Remove Disease";
				else if (rollB < 84) ss << "Searing Light";
				else if (rollB < 86) ss << "Sleet Storm";
				else if (rollB < 88) ss << "Slow";
				else if (rollB < 90) ss << "Speak with Dead";
				else if (rollB < 91) ss << "Stinking Cloud";
				else if (rollB < 93) ss << "Stone Shape";
				else if (rollB < 94) ss << "Suggestion";
				else if (rollB < 95) ss << "Summon Monster III";
				else if (rollB < 98) ss << "Summon Nature's Ally III";
				else if (rollB < 100) ss << "Vampiric Touch";
				else if (rollB < 101) ss << "Water Breathing";
				else std::cout << "Error Code 1712\n";
				break;
			case 4:
				if (rollB < 3) ss << "Air Walk";
				else if (rollB < 5) ss << "Beast Shape II";
				else if (rollB < 8) ss << "Black Tentacles";
				else if (rollB < 9) ss << "Chaos Hammer";
				else if (rollB < 12) ss << "Charm Monster";
				else if (rollB < 15) ss << "Confusion";
				else if (rollB < 17) ss << "Crushing Despair";
				else if (rollB < 23) ss << "Cure Critical Wounds";
				else if (rollB < 25) ss << "Death Ward";
				else if (rollB < 29) ss << "Dimension Door";
				else if (rollB < 30) ss << "Dimensional Anchor";
				else if (rollB < 31) ss << "Dismissal";
				else if (rollB < 34) ss << "Divine Power";
				else if (rollB < 36) ss << "Elemental Body I";
				else if (rollB < 38) ss << "Enervation";
				else if (rollB < 40) ss << "Mass Enlarge Person";
				else if (rollB < 43) ss << "Fear";
				else if (rollB < 45) ss << "Fire Shield";
				else if (rollB < 49) ss << "Flame Strike";
				else if (rollB < 52) ss << "Freedom of Movement";
				else if (rollB < 54) ss << "Lesser Globe of Invulnerability";
				else if (rollB < 55) ss << "Holy Smite";
				else if (rollB < 57) ss << "Ice Storm";
				else if (rollB < 59) ss << "Imbue with Spell Abilty";
				else if (rollB < 62) ss << "Inflict Critical Wounds";
				else if (rollB < 66) ss << "Greater Invisibility";
				else if (rollB < 67) ss << "Order's Wrath";
				else if (rollB < 70) ss << "Phantasmal Killer";
				else if (rollB < 71) ss << "Resiliant Sphere";
				else if (rollB < 73) ss << "Scrying";
				else if (rollB < 74) ss << "Sending";
				else if (rollB < 75) ss << "Shout";
				else if (rollB < 77) ss << "Solid Fog";
				else if (rollB < 80) ss << "Spell Immunity";
				else if (rollB < 81) ss << "Summon Monster IV";
				else if (rollB < 82) ss << "Summon Nature's Ally IV";
				else if (rollB < 83) ss << "Unholy Blight";
				else if (rollB < 88) ss << "Wall of Fire";
				else if (rollB < 92) ss << "Wall of Ice";
				else if (rollB < 94) ss << "Divination";
				else if (rollB < 96) ss << "Restoration";
				else if (rollB < 97) ss << "Break Enchantment";
				else if (rollB < 99) ss << "Stoneskin";
				else if (rollB < 100) ss << "Lesser Planar Ally";
				else if (rollB < 101) ss << "Restoration";
				else std::cout << "Error Code 1760\n";
				break;
			default:
				std::cout << "Error Code 1763\n";
				break;
			}
		else if (rollB < 101)
			switch (lvl)
			{
			case 0:
				if (rollB < 7) ss << "Arcane Mark";
				else if (rollB < 16) ss << "Bleed";
				else if (rollB < 23) ss << "Dancing Lights";
				else if (rollB < 32) ss << "Detect Poison";
				else if (rollB < 41) ss << "Disrupt Undead";
				else if (rollB < 49) ss << "Flare";
				else if (rollB < 57) ss << "Guidance";
				else if (rollB < 66) ss << "Know Direction";
				else if (rollB < 74) ss << "Lullaby";
				else if (rollB < 80) ss << "Open/Close";
				else if (rollB < 87) ss << "Resistance";
				else if (rollB < 95) ss << "Spark";
				else if (rollB < 101) ss << "Virtue";
				else std::cout << "Error Code 1783\n";
				break;
			case 1:
				if (rollB < 3) ss << "Ant Haul";
				else if (rollB < 6) ss << "Apect of the Falcon";
				else if (rollB < 8) ss << "Bless Weapon";
				else if (rollB < 9) ss << "Calm Animals";
				else if (rollB < 11) ss << "Charm Animal";
				else if (rollB < 13) ss << "Chill Touch";
				else if (rollB < 15) ss << "Compel Hostility";
				else if (rollB < 18) ss << "Lesser Confusion";
				else if (rollB < 20) ss << "Corrosive Touch";
				else if (rollB < 22) ss << "Deathwatch";
				else if (rollB < 23) ss << "Detect Animals or Plants";
				else if (rollB < 24) ss << "Detect Chaos";
				else if (rollB < 25) ss << "Detect Evil";
				else if (rollB < 26) ss << "Detect Good";
				else if (rollB < 27) ss << "Detect Law";
				else if (rollB < 29) ss << "Detect Secret Doors";
				else if (rollB < 30) ss << "Detect Snares and Pits";
				else if (rollB < 32) ss << "Detect Undead";
				else if (rollB < 36) ss << "Doom";
				else if (rollB < 38) ss << "Entropic Shield";
				else if (rollB < 39) ss << "Erase";
				else if (rollB < 40) ss << "Faerie Fire";
				else if (rollB < 42) ss << "Feather Step";
				else if (rollB < 45) ss << "FLoating Disk";
				else if (rollB < 48) ss << "Goodberry";
				else if (rollB < 50) ss << "Hide From Animals";
				else if (rollB < 52) ss << "Hide From Undead";
				else if (rollB < 53) ss << "Hideous Laughter";
				else if (rollB < 55) ss << "Hold Portal";
				else if (rollB < 57) ss << "Hynotism";
				else if (rollB < 59) ss << "Icicle Daggar";
				else if (rollB < 61) ss << "Ill Omen";
				else if (rollB < 64) ss << "Jump";
				else if (rollB < 66) ss << "Longstrider";
				else if (rollB < 67) ss << "Magic Aura";
				else if (rollB < 69) ss << "Mount";
				else if (rollB < 70) ss << "Obscure Object";
				else if (rollB < 72) ss << "Pass Without Trace";
				else if (rollB < 73) ss << "Ray of Sickening";
				else if (rollB < 76) ss << "Reduce Person";
				else if (rollB < 79) ss << "Sanctuary";
				else if (rollB < 81) ss << "Shock Shield";
				else if (rollB < 84) ss << "Speak With Animals";
				else if (rollB < 86) ss << "Stone Fist";
				else if (rollB < 88) ss << "Stone Shield";
				else if (rollB < 89) ss << "Summon Minor Monster";
				else if (rollB < 90) ss << "Undectable Alignment";
				else if (rollB < 93) ss << "Urban Grace";
				else if (rollB < 97) ss << "Vanish";
				else if (rollB < 98) ss << "Ventriloquism";
				else if (rollB < 99) ss << "Magic Mouth";
				else if (rollB < 100) ss << "Bless Water";
				else if (rollB < 101) ss << "Curse Water";
				else std::cout << "Error Code 1839\n";
				break;
			case 2:
				if (rollB < 3) ss << "Align Weapon";
				else if (rollB < 6) ss << "Animal Aspect";
				else if (rollB < 7) ss << "Animal Messenger";
				else if (rollB < 8) ss << "Animal Trace";
				else if (rollB < 11) ss << "Aspect of the Bear";
				else if (rollB < 14) ss << "Bestow Weapon Proficiency";
				else if (rollB < 16) ss << "Blindness/Deafness";
				else if (rollB < 19) ss << "Burning Gaze";
				else if (rollB < 22) ss << "Calm Emotions";
				else if (rollB < 25) ss << "Chill Metal";
				else if (rollB < 26) ss << "Command Undead";
				else if (rollB < 28) ss << "Daze Monster";
				else if (rollB < 30) ss << "Death Knell";
				else if (rollB < 33) ss << "Defensive Shock";
				else if (rollB < 34) ss << "Delay Pain";
				else if (rollB < 36) ss << "Detect Thoughts";
				else if (rollB < 40) ss << "Disguise Other";
				else if (rollB < 43) ss << "Effortless Armor";
				else if (rollB < 47) ss << "Elemental Touch";
				else if (rollB < 49) ss << "Enthrall";
				else if (rollB < 51) ss << "Gentle Repose";
				else if (rollB < 52) ss << "Ghoul Touch";
				else if (rollB < 54) ss << "Glide";
				else if (rollB < 56) ss << "Groundswell";
				else if (rollB < 57) ss << "Gust of Wind";
				else if (rollB < 58) ss << "Hold Animal";
				else if (rollB < 60) ss << "Hypnotic Pattern";
				else if (rollB < 61) ss << "Locate Object";
				else if (rollB < 62) ss << "Make Whole";
				else if (rollB < 64) ss << "Misdirection";
				else if (rollB < 66) ss << "Oppressive Boredom";
				else if (rollB < 67) ss << "Protection from Arrows";
				else if (rollB < 68) ss << "Reduce Animal";
				else if (rollB < 70) ss << "Rope Trick";
				else if (rollB < 73) ss << "Scare";
				else if (rollB < 75) ss << "Share Language";
				else if (rollB < 77) ss << "Soften Earth and Stone";
				else if (rollB < 79) ss << "Spectral Hand";
				else if (rollB < 81) ss << "Status";
				else if (rollB < 83) ss << "Tongues";
				else if (rollB < 85) ss << "Touch of Idiocy";
				else if (rollB < 87) ss << "Tree Shape";
				else if (rollB < 89) ss << "Warp Wood";
				else if (rollB < 92) ss << "Weapon of Awe";
				else if (rollB < 94) ss << "Wood Shape";
				else if (rollB < 96) ss << "Zone of Truth";
				else if (rollB < 97) ss << "Arcane Lock";
				else if (rollB < 98) ss << "Consecrate";
				else if (rollB < 99) ss << "Desecrate";
				else if (rollB < 100) ss << "Continual Flame";
				else if (rollB < 101) ss << "Phantom Trap";
				else std::cout << "Error Code 1893\n";
				break;
			case 3:
				if (rollB < 5) ss << "Greater Animal Aspect";
				else if (rollB < 7) ss << "Aqueous Orb";
				else if (rollB < 9) ss << "Arcane Sight";
				else if (rollB < 12) ss << "Archon's Aura";
				else if (rollB < 15) ss << "Ash Storm";
				else if (rollB < 18) ss << "Bestow Curse";
				else if (rollB < 21) ss << "Clairaudience/Clairvoyance";
				else if (rollB < 23) ss << "Contagion";
				else if (rollB < 24) ss << "Diminish Plants";
				else if (rollB < 26) ss << "Dominate Animal";
				else if (rollB < 30) ss << "Elemental Aura";
				else if (rollB < 31) ss << "Explosive Runes";
				else if (rollB < 35) ss << "Force Punch";
				else if (rollB < 36) ss << "Halt Undead";
				else if (rollB < 38) ss << "Helping Hand";
				else if (rollB < 41) ss << "Hostile Levitation";
				else if (rollB < 44) ss << "Howling Agony";
				else if (rollB < 46) ss << "Hydraulic Torrent";
				else if (rollB < 47) ss << "Mad Monkeys";
				else if (rollB < 50) ss << "Meld into Stone";
				else if (rollB < 53) ss << "Neutralize Poison";
				else if (rollB < 55) ss << "Pain Strike";
				else if (rollB < 56) ss << "Phantom Steed";
				else if (rollB < 58) ss << "Plant Growth";
				else if (rollB < 61) ss << "Poison";
				else if (rollB < 62) ss << "Quench";
				else if (rollB < 66) ss << "Rage";
				else if (rollB < 68) ss << "Ray of Exhaustion";
				else if (rollB < 70) ss << "Resinous Skin";
				else if (rollB < 71) ss << "Secret Page";
				else if (rollB < 72) ss << "Shrink Item";
				else if (rollB < 74) ss << "Snare";
				else if (rollB < 75) ss << "Speak with Plants";
				else if (rollB < 77) ss << "Spike Growth";
				else if (rollB < 78) ss << "Tiny Hut";
				else if (rollB < 82) ss << "Water Walk";
				else if (rollB < 85) ss << "Wind Wall";
				else if (rollB < 87) ss << "Wrathful Mantle";
				else if (rollB < 88) ss << "Illusory Script";
				else if (rollB < 90) ss << "Nondetection";
				else if (rollB < 92) ss << "Glibness";
				else if (rollB < 96) ss << "Good Hope";
				else if (rollB < 98) ss << "Heal Mount";
				else if (rollB < 99) ss << "Sculpt Sound";
				else if (rollB < 100) ss << "Glyph of Warding";
				else if (rollB < 101) ss << "Sepia Snake Sigil";
				else std::cout << "Error Code 1942\n";
				break;
			case 4:
				if (rollB < 2) ss << "Antiplant Shell";
				else if (rollB < 5) ss << "Arcane Eye";
				else if (rollB < 8) ss << "Aspect of the Stag";
				else if (rollB < 12) ss << "Ball Lightning";
				else if (rollB < 13) ss << "Blight";
				else if (rollB < 14) ss << "Command Plants";
				else if (rollB < 16) ss << "Control Water";
				else if (rollB < 19) ss << "Greater Darkvision";
				else if (rollB < 20) ss << "Detect Scrying";
				else if (rollB < 21) ss << "Descern Lies";
				else if (rollB < 25) ss << "Dragons Breath";
				else if (rollB < 29) ss << "Greater False Life";
				else if (rollB < 31) ss << "Lesser Geas";
				else if (rollB < 35) ss << "Ghost Wolf";
				else if (rollB < 37) ss << "Giant Vermin";
				else if (rollB < 38) ss << "Hallucinatory Terrain";
				else if (rollB < 39) ss << "Illusory Wall";
				else if (rollB < 41) ss << "Locate Creature";
				else if (rollB < 43) ss << "Minor Creation";
				else if (rollB < 44) ss << "Mnemonic Enhancer";
				else if (rollB < 47) ss << "Obsidian Flow";
				else if (rollB < 49) ss << "Rainbow Pattern";
				else if (rollB < 51) ss << "Mass Reduce Person";
				else if (rollB < 54) ss << "Reincarnate";
				else if (rollB < 55) ss << "Repel Vermin";
				else if (rollB < 57) ss << "Ride the Waves";
				else if (rollB < 60) ss << "Rusting Grasp";
				else if (rollB < 61) ss << "Secure Shelter";
				else if (rollB < 64) ss << "Shadow Conjuration";
				else if (rollB < 68) ss << "Shadow Step";
				else if (rollB < 71) ss << "Shocking Image";
				else if (rollB < 75) ss << "Spike Stones";
				else if (rollB < 77) ss << "Volcanic Storm";
				else if (rollB < 80) ss << "Wadering Star Motes";
				else if (rollB < 81) ss << "Animal Growth";
				else if (rollB < 83) ss << "Commune with Nature";
				else if (rollB < 84) ss << "Dispel Chaos";
				else if (rollB < 85) ss << "Dispel Evil";
				else if (rollB < 88) ss << "Dominate Person";
				else if (rollB < 92) ss << "Hold Monster";
				else if (rollB < 95) ss << "Holy Sword";
				else if (rollB < 96) ss << "Mark of Justice";
				else if (rollB < 98) ss << "Modify Memory";
				else if (rollB < 99) ss << "Tree Stride";
				else if (rollB < 100) ss << "Zone of Silence";
				else if (rollB < 101) ss << "Legend Lore";
				else std::cout << "Error Code 1991\n";
				break;
			default:
				std::cout << "Error Code 1994\n";
				break;
			}
		else std::cout << "Error Code 1997\n";
		ss << std::endl;
	}
	return ss.str();
}
int getPotLevel(int subtype)
{
	int rollG = roll(1, 100);
	switch (subtype)
	{
	case 1:
		if (rollG < 41) return 0;
		else if (rollG < 101) return 1;
		else std::cout << "Error Code 2010\n";
		break;
	case 2:
		if (rollG < 11) return 0;
		else if (rollG < 61) return 1;
		else if (rollG < 101) return 2;
		else std::cout << "Error Code 2016\n";
		break;
	case 3:
		if (rollG < 26) return 1;
		else if (rollG < 86) return 2;
		else if (rollG < 101) return 3;
		else std::cout << "Error Code 2022\n";
		break;
	case 4:
		if (rollG < 11) return 1;
		else if (rollG < 51) return 2;
		else if (rollG < 101) return 3;
		else std::cout << "Error Code 2028\n";
		break;
	case 5:
		if (rollG < 36) return 2;
		else if (rollG < 101) return 3;
		else std::cout << "Error Code 2033\n";
		break;
	case 6:
		if (rollG < 11) return 2;
		else if (rollG < 101) return 3;
		else std::cout << "Error Code 2038\n";
		break;
	default:
		std::cout << "Error Code 2041\n";
		break;
	}
	return -1;
}
std::string potGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int rollA = roll(1, 100), rollB = roll(1, 100), lvl = getPotLevel(subtype);
		ss << "Potion/Oil of ";
		if (rollA < 76)
			switch (lvl)
			{
			case 0:
				if (rollB < 15) ss << "Arcane Mark";
				else if (rollB < 29) ss << "Guidance";
				else if (rollB < 45) ss << "Light";
				else if (rollB < 59) ss << "Purify Food and Drink";
				else if (rollB < 73) ss << "Resistance";
				else if (rollB < 87) ss << "Stabilise";
				else if (rollB < 101) ss << "Virtue";
				else std::cout << "Error Code 2064\n";
				break;
			case 1:
				if (rollB < 5) ss << "Bless Weapon";
				else if (rollB < 15) ss << "Cure Light Wounds";
				else if (rollB < 20) ss << "Endure Elements";
				else if (rollB < 28) ss << "Enlarge Person";
				else if (rollB < 34) ss << "Jump";
				else if (rollB < 42) ss << "Mage Armor";
				else if (rollB < 48) ss << "Magic Fang";
				else if (rollB < 56) ss << "Magic Weapon";
				else if (rollB < 61) ss << "Pass Without Trace";
				else if (rollB < 65) ss << "Protection from Chaos";
				else if (rollB < 69) ss << "Protection from Evil";
				else if (rollB < 73) ss << "Protection from Good";
				else if (rollB < 77) ss << "Protection from Law";
				else if (rollB < 82) ss << "Reduce Person";
				else if (rollB < 88) ss << "Remove Fear";
				else if (rollB < 93) ss << "Sanctuary";
				else if (rollB < 101) ss << "Shield of Faith";
				else std::cout << "Error Code 2084\n";
				break;
			case 2:
				if (rollB < 5) ss << "Aid";
				else if (rollB < 8) ss << "Align Weapon";
				else if (rollB < 12) ss << "Barkskin";
				else if (rollB < 17) ss << "Bear's Endurance";
				else if (rollB < 21) ss << "Blur";
				else if (rollB < 26) ss << "Bull's Strength";
				else if (rollB < 31) ss << "Cat's Grace";
				else if (rollB < 38) ss << "Cure Moderate Wounds";
				else if (rollB < 42) ss << "Darkvision";
				else if (rollB < 45) ss << "Delay Poison";
				else if (rollB < 50) ss << "Eagle's Spendor";
				else if (rollB < 55) ss << "Fox's Cunning";
				else if (rollB < 62) ss << "Invisibility";
				else if (rollB < 67) ss << "Levitate";
				else if (rollB < 72) ss << "Owl's Wisdome";
				else if (rollB < 74) ss << "Protection from Arrows";
				else if (rollB < 77) ss << "Remove Paralysis";
				else if (rollB < 81) ss << "Resist Energy - Acid";
				else if (rollB < 85) ss << "Resist Energy - Cold";
				else if (rollB < 89) ss << "Resist Energy - Electricity";
				else if (rollB < 93) ss << "Resist Energy - Fire";
				else if (rollB < 95) ss << "Resist Energy - Sonic";
				else if (rollB < 99) ss << "Spider Climb";
				else if (rollB < 101) ss << "Undetectable Alignment";
				else std::cout << "Error Code 2111\n";
				break;
			case 3:
				if (rollB < 7) ss << "Cure Serious Wounds";
				else if (rollB < 11) ss << "Dispel Magic";
				else if (rollB < 15) ss << "Displacement";
				else if (rollB < 21) ss << "Fly";
				else if (rollB < 26) ss << "Gaseous Form";
				else if (rollB < 30) ss << "Good Hope";
				else if (rollB < 36) ss << "Haste";
				else if (rollB < 41) ss << "Heroism";
				else if (rollB < 45) ss << "Keen Edge";
				else if (rollB < 49) ss << "Greater Magic Fang";
				else if (rollB < 53) ss << "Magic Vestment";
				else if (rollB < 58) ss << "Neutralize Poison";
				else if (rollB < 61) ss << "Protection from Energy - Acid";
				else if (rollB < 64) ss << "Protection from Energy - Cold";
				else if (rollB < 67) ss << "Protection from Energy - Electricity";
				else if (rollB < 70) ss << "Protection from Energy - Fire";
				else if (rollB < 72) ss << "Protection from Energy - Sonic";
				else if (rollB < 75) ss << "Rage";
				else if (rollB < 78) ss << "Remove Blindness/Deafness";
				else if (rollB < 82) ss << "Remove Curse";
				else if (rollB < 87) ss << "Remove Disease";
				else if (rollB < 92) ss << "Tongues";
				else if (rollB < 97) ss << "Water Breathing";
				else if (rollB < 101) ss << "Water Walk";
				else std::cout << "Error Code 2138\n";
				break;
			default:
				std::cout << "Error Code 2141\n";
				break;
			}
		else if (rollA < 101)
			switch (lvl)
			{
			case 0:
				if (rollB < 15) ss << "Arcane Mark";
				else if (rollB < 29) ss << "Guidance";
				else if (rollB < 45) ss << "Light";
				else if (rollB < 59) ss << "Purify Food and Drink";
				else if (rollB < 73) ss << "Resistance";
				else if (rollB < 87) ss << "Stabilise";
				else if (rollB < 101) ss << "Virtue";
				else std::cout << "Error Code 2155\n";
				break;
			case 1:
				if (rollB < 5) ss << "Animate Rope";
				else if (rollB < 12) ss << "Ant Haul";
				else if (rollB < 17) ss << "Cloak of Shade";
				else if (rollB < 21) ss << "Erase";
				else if (rollB < 27) ss << "Feather Step";
				else if (rollB < 31) ss << "Goodberry";
				else if (rollB < 35) ss << "Grease";
				else if (rollB < 42) ss << "Hide from Animals";
				else if (rollB < 50) ss << "Hide from Undead";
				else if (rollB < 54) ss << "Hold Portal";
				else if (rollB < 59) ss << "Invigorate";
				else if (rollB < 65) ss << "Keen Senses";
				else if (rollB < 69) ss << "Magic Stone";
				else if (rollB < 76) ss << "Remove Sickness";
				else if (rollB < 81) ss << "Sanctify Corpse";
				else if (rollB < 85) ss << "Shillealagh";
				else if (rollB < 93) ss << "Touch of the Sea";
				else if (rollB < 101) ss << "Vanish";
				else std::cout << "Error Code 2176\n";
				break;
			case 2:
				if (rollB < 7) ss << "Ablative Barrier";
				else if (rollB < 15) ss << "Acute Senses";
				else if (rollB < 20) ss << "Arcane Lock";
				else if (rollB < 25) ss << "Bullet Shield";
				else if (rollB < 31) ss << "Certain Grip";
				else if (rollB < 36) ss << "Continual Flame";
				else if (rollB < 41) ss << "Corruption Resistance";
				else if (rollB < 49) ss << "Disguise Other";
				else if (rollB < 57) ss << "Gentle Repose";
				else if (rollB < 62) ss << "Make Whole";
				else if (rollB < 68) ss << "Obscure Object";
				else if (rollB < 73) ss << "Reduce Animal";
				else if (rollB < 77) ss << "Rope Trick";
				else if (rollB < 83) ss << "Slipstream";
				else if (rollB < 91) ss << "Status";
				else if (rollB < 96) ss << "Warp Wood";
				else if (rollB < 101) ss << "Wood Shape";
				else std::cout << "Error Code 2196\n";
				break;
			case 3:
				if (rollB < 11) ss << "Burrow";
				else if (rollB < 23) ss << "Countless Eyes";
				else if (rollB < 35) ss << "Daylight";
				else if (rollB < 50) ss << "Draconic Resivoir";
				else if (rollB < 59) ss << "Flame Arrow";
				else if (rollB < 68) ss << "Shrink Item";
				else if (rollB < 78) ss << "Stone Shape";
				else if (rollB < 88) ss << "Fire Trap";
				else if (rollB < 101) ss << "Nondetection";
				else std::cout << "Error Code 2208\n";
				break;
			default:
				std::cout << "Error Code 2211\n";
				break;
			}
		else std::cout << "Error Code 2214\n";
		ss << std::endl;
	}
	return ss.str();
}
std::string aEn(int type, int subtype)
{
	std::stringstream ss;
	int rollA = roll(1, 100);
	if (type == 1)
		switch (subtype)
		{
		case 1:
			if (rollA < 7) ss << "Benevolent";
			else if (rollA < 13) ss << "Poison-Resistant";
			else if (rollA < 19) ss << "Balanced";
			else if (rollA < 25) ss << "Bitter";
			else if (rollA < 31) ss << "Bolstering";
			else if (rollA < 37) ss << "Brawling";
			else if (rollA < 43) ss << "Champion";
			else if (rollA < 49) ss << "Dastard";
			else if (rollA < 55) ss << "Deathless";
			else if (rollA < 61) ss << "Defiant";
			else if (rollA < 67) ss << "Light Fortification";
			else if (rollA < 72) ss << "Grinding";
			else if (rollA < 77) ss << "Impervious";
			else if (rollA < 83) ss << "Mirrored";
			else if (rollA < 89) ss << "Spell Storing";
			else if (rollA < 95) ss << "Stanching";
			else if (rollA < 101) ss << "Warding";
			else std::cout << "Error Code 2244\n";
			break;
		case 2:
			if (rollA < 13) ss << "Glamered";
			else if (rollA < 25) ss << "Jousting";
			else if (rollA < 39) ss << "Shadow";
			else if (rollA < 53) ss << "Slick";
			else if (rollA < 65) ss << "Expeditious";
			else if (rollA < 77) ss << "Creeping";
			else if (rollA < 89) ss << "Rallying";
			else if (rollA < 101) ss << "Spell Resistance (13)";
			else std::cout << "Error Code 2255\n";
			break;
		case 3:
			if (rollA < 9) ss << "Adhesive";
			else if (rollA < 18) ss << "Hosteling";
			else if (rollA < 27) ss << "Radiant";
			else if (rollA < 37) ss << "Delving";
			else if (rollA < 46) ss << "Putrid";
			else if (rollA < 56) ss << "Moderate Fortification";
			else if (rollA < 66) ss << "Ghost Touch";
			else if (rollA < 75) ss << "Invulerability";
			else if (rollA < 85) ss << "Spell Resistance (15)";
			else if (rollA < 93) ss << "Titanic";
			else if (rollA < 101) ss << "Wild";
			else std::cout << "Error Code 2269\n";
			break;
		case 4:
			if (rollA < 17) ss << "Harmonizing";
			else if (rollA < 34) ss << "Improved Shadow";
			else if (rollA < 51) ss << "Improved Slick";
			else if (rollA < 68) ss << "Energy Resistance";
			else if (rollA < 84) ss << "Martyring";
			else if (rollA < 101) ss << "Spell Resistance (17)";
			else std::cout << "Error Code 2278\n";
			break;
		case 5:
			if (rollA < 9) ss << "Righteous";
			else if (rollA < 16) ss << "Unbound";
			else if (rollA < 24) ss << "Unrighteous";
			else if (rollA < 31) ss << "Vigilant";
			else if (rollA < 38) ss << "Determination";
			else if (rollA < 46) ss << "Greater Shadow";
			else if (rollA < 54) ss << "Greater Slick";
			else if (rollA < 62) ss << "Improved Energy Resistance";
			else if (rollA < 70) ss << "Etherealness";
			else if (rollA < 77) ss << "Undead Controlling";
			else if (rollA < 85) ss << "Greater Energy Resistance";
			else if (rollA < 93) ss << "Heavy Fortification";
			else if (rollA < 101) ss << "Spell Resistance (19)";
			else std::cout << "Error Code 2294\n";
			break;
		default:
			std::cout << "Error Code 2297\n";
			break;
		}
	else if (type == 2)
		switch (subtype)
		{
		case 1:
			if (rollA < 11) ss << "Poison Resistant";
			else if (rollA < 20) ss << "Arrow Catching";
			else if (rollA < 29) ss << "Bashing";
			else if (rollA < 38) ss << "Blinding";
			else if (rollA < 47) ss << "Clangorous";
			else if (rollA < 56) ss << "Defiant";
			else if (rollA < 65) ss << "Light Fortification";
			else if (rollA < 74) ss << "Grinding";
			else if (rollA < 83) ss << "Impervious";
			else if (rollA < 92) ss << "Mirrored";
			else if (rollA < 101) ss << "Ramming";
			else std::cout << "Error Code 2315\n";
			break;
		case 2:
			if (rollA < 16) ss << "Rallying";
			else if (rollA < 31) ss << "Wyrmsbreath";
			else if (rollA < 51) ss << "Animated";
			else if (rollA < 68) ss << "Arrow Deflection";
			else if (rollA < 83) ss << "Merging";
			else if (rollA < 101) ss << "Spell Resistance (13)";
			else std::cout << "Error Code 2324\n";
			break;
		case 3:
			if (rollA < 16) ss << "Hosteling";
			else if (rollA < 33) ss << "Radiant";
			else if (rollA < 50) ss << "Moderate Fortification";
			else if (rollA < 67) ss << "Ghost Touch";
			else if (rollA < 84) ss << "Spell Resistance (15)";
			else if (rollA < 101) ss << "Wild";
			else std::cout << "Error Code 2333\n";
			break;
		case 4:
			if (rollA < 51) ss << "Energy Resistance";
			else if (rollA < 101) ss << "Spell Resistance (17)";
			else std::cout << "Error Code 2338\n";
			break;
		case 5:
			if (rollA < 12) ss << "Determination";
			else if (rollA < 28) ss << "Improved Energy Resistance";
			else if (rollA < 39) ss << "Undead Controlling";
			else if (rollA < 56) ss << "Greater Energy Resistance";
			else if (rollA < 71) ss << "Heavy Fortification";
			else if (rollA < 86) ss << "Reflecting";
			else if (rollA < 101) ss << "Spell Resistance (19)";
			else std::cout << "Error Code 2348\n";
			break;
		default:
			std::cout << "Error Code 2351\n";
			break;
		}
	else std::cout << "Error Code 2354\n";
	ss << " ";
	return ss.str();
}
std::string aPrefix(int type, int subtype)
{
	int rollA = roll(1, 100);
	std::stringstream ss;
	switch (subtype)
	{
	case 0:
		break;
	case 1:
		if (rollA < 81) ss << "+1 ";
		else if (rollA < 101) ss << "Lesser Minor Specific Armor/Shield";
		else std::cout << "Error Code 2369\n";
		break;
	case 2:
		if (rollA < 27) ss << "+1 ";
		else if (rollA < 54) ss << "+2 ";
		else if (rollA < 81) ss << "+1 " + aEn(type, 1);
		else if (rollA < 101) ss << "Greater Minor Specific Armor/Shield";
		else std::cout << "Error Code 2376\n";
		break;
	case 3:
		if (rollA < 11) ss << "+1 ";
		else if (rollA < 21) ss << "+2 ";
		else if (rollA < 33) ss << "+3 ";
		else if (rollA < 45) ss << "+1 " + aEn(type, 1);
		else if (rollA < 57) ss << "+1 " + aEn(type, 1) + aEn(type, 1);
		else if (rollA < 69) ss << "+1 " + aEn(type, 2);
		else if (rollA < 81) ss << "+2 " + aEn(type, 1);
		else if (rollA < 101) ss << "Lesser Medium Specific Armor/Shield";
		else std::cout << "Error Code 2387\n";
		break;
	case 4:
		if (rollA < 11) ss << "+2 ";
		else if (rollA < 23) ss << "+3 ";
		else if (rollA < 33) ss << "+1 " + aEn(type, 1);
		else if (rollA < 45) ss << "+1 " + aEn(type, 2);
		else if (rollA < 57) ss << "+2 " + aEn(type, 1);
		else if (rollA < 69) ss << "+2 " + aEn(type, 2);
		else if (rollA < 81) ss << "+3 " + aEn(type, 1);
		else if (rollA < 101) ss << "Greater Medium Specific Armor/Shield";
		else std::cout << "Error Code 2398\n";
		break;
	case 5:
		if (rollA < 11) ss << "+3 ";
		else if (rollA < 23) ss << "+4 ";
		else if (rollA < 33) ss << "+1 " + aEn(type, 2);
		else if (rollA < 45) ss << "+1 " + aEn(type, 3);
		else if (rollA < 57) ss << "+2 " + aEn(type, 2);
		else if (rollA < 59) ss << "+3 " + aEn(type, 1);
		else if (rollA < 81) ss << "+4 " + aEn(type, 1);
		else if (rollA < 101) ss << "Lesser Major Specific Armor/Shield";
		else std::cout << "Error Code 2409\n";
		break;
	case 6:
		if (rollA < 11) ss << "+4 ";
		else if (rollA < 21) ss << "+5 ";
		else if (rollA < 31) ss << "+4 " + aEn(type, 1);
		else if (rollA < 39) ss << "+4 " + aEn(type, 2);
		else if (rollA < 47) ss << "+4 " + aEn(type, 3);
		else if (rollA < 52) ss << "+4 " + aEn(type, 4);
		else if (rollA < 60) ss << "+5 " + aEn(type, 1);
		else if (rollA < 68) ss << "+5 " + aEn(type, 2);
		else if (rollA < 72) ss << "+5 " + aEn(type, 3);
		else if (rollA < 75) ss << "+5 " + aEn(type, 2) + aEn(type, 2);
		else if (rollA < 78) ss << "+5 " + aEn(type, 4);
		else if (rollA < 81) ss << "+5 " + aEn(type, 5);
		else if (rollA < 101) ss << "Greater Major Specific Armor/Shield";
		else std::cout << "Error Code 2425\n";
		break;
	default:
		std::cout << "Error Code 2428\n";
		break;
	}
	return ss.str();
}
std::string armorGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int rollB, t;
		std::string a, p;
		do  
		{
			rollB = roll(1, 100);
			if (rollB < 5) { a = "Banded Mail"; t = 1; }
			else if (rollB < 12) { a = "Breastplate"; t = 1; }
			else if (rollB < 15) { a = "Buckler"; t = 2; }
			else if (rollB < 22) { a = "Chain Shirt"; t = 1; }
			else if (rollB < 28) { a = "Chainmail"; t = 1; }
			else if (rollB < 35) { a = "Full Plate"; t = 1; }
			else if (rollB < 40) { a = "Half-Plate"; t = 1; }
			else if (rollB < 46) { a = "Heavy Steel Shield"; t = 2; }
			else if (rollB < 52) { a = "Heavy Wooden Shield"; t = 2; }
			else if (rollB < 56) { a = "Hide Armor"; t = 1; }
			else if (rollB < 62) { a = "Leather Armor"; t = 1; }
			else if (rollB < 66) { a = "Light Steel Shield"; t = 2; }
			else if (rollB < 70) { a = "Light Wooden Shield"; t = 2; }
			else if (rollB < 73) { a = "Padded Armor"; t = 1; }
			else if (rollB < 78) { a = "Scale Mail"; t = 1; }
			else if (rollB < 82) { a = "Splint Mail"; t = 1; }
			else if (rollB < 88) { a = "Studded Leather Armor"; t = 1; }
			else if (rollB < 91) { a = "Tower Shield"; t = 2; }
			else if (rollB < 101) { }
			else std::cout << "Error Code 2642\n";
		} while (rollB >= 91);
		p = aPrefix(t, subtype);
		if (p.size() == 0) ss << "mwk " + a;
		else if (p.at(0) == '+') ss << p + a;
		else ss << p;
		ss << std::endl;
	}
	return ss.str();
}
std::string wEn(int type, int subtype)
{
	std::stringstream ss;
	int rollA = roll(1, 100);
	if (type == 1)
		switch (subtype)
		{
		case 0:
			break;
		case 1:
			if (rollA < 2) ss << "Impervious";
			else if (rollA < 3) ss << "Glamered";
			else if (rollA < 4) ss << "Allying";
			else if (rollA < 9) ss << "Bane";
			else if (rollA < 10) ss << "Benevolent";
			else if (rollA < 11) ss << "Called";
			else if (rollA < 13) ss << "Conductive";
			else if (rollA < 17) ss << "Corrosive";
			else if (rollA < 18) ss << "Countering";
			else if (rollA < 19) ss << "Courageous";
			else if (rollA < 20) ss << "Cruel";
			else if (rollA < 22) ss << "Cunning";
			else if (rollA < 23) ss << "Deadly";
			else if (rollA < 27) ss << "Deafening";
			else if (rollA < 28) ss << "Dispelling";
			else if (rollA < 34) ss << "Flaming";
			else if (rollA < 40) ss << "Frost";
			else if (rollA < 42) ss << "Furious";
			else if (rollA < 46) ss << "Ghost Touch";
			else if (rollA < 48) ss << "Greyflame";
			else if (rollA < 49) ss << "Grounding";
			else if (rollA < 50) ss << "Guardian";
			else if (rollA < 51) ss << "Hearseeker";
			else if (rollA < 53) ss << "Huntsman";
			else if (rollA < 55) ss << "Jurist";
			else if (rollA < 60) ss << "Keen";
			else if (rollA < 62) ss << "Ki Focus";
			else if (rollA < 63) ss << "Limming";
			else if (rollA < 65) ss << "Menacing";
			else if (rollA < 66) ss << "Merciful";
			else if (rollA < 69) ss << "Mighty Cleaving";
			else if (rollA < 70) ss << "Mimetic";
			else if (rollA < 71) ss << "Neutralizing";
			else if (rollA < 72) ss << "Ominous";
			else if (rollA < 73) ss << "Planar";
			else if (rollA < 74) ss << "Quenching";
			else if (rollA < 75) ss << "Seaborne";
			else if (rollA < 81) ss << "Shock";
			else if (rollA < 86) ss << "Spell Storing";
			else if (rollA < 87) ss << "Thawing";
			else if (rollA < 92) ss << "Throwing";
			else if (rollA < 97) ss << "Thundering";
			else if (rollA < 98) ss << "Valiant";
			else if (rollA < 101) ss << "Vicious";
			else std::cout << "Error Code 2526\n";
			break;
		case 2:
			if (rollA < 2) ss << "Advancing";
			else if (rollA < 11) ss << "Anarchic";
			else if (rollA < 20) ss << "Anchoring";
			else if (rollA < 21) ss << "Axiomatic";
			else if (rollA < 28) ss << "Corrosive Burst";
			else if (rollA < 29) ss << "Defiant";
			else if (rollA < 30) ss << "Dispelling Burst";
			else if (rollA < 39) ss << "Disruption";
			else if (rollA < 48) ss << "Flaming Burst";
			else if (rollA < 49) ss << "Furyborn";
			else if (rollA < 50) ss << "Glorious";
			else if (rollA < 59) ss << "Holy";
			else if (rollA < 68) ss << "Icy Burst";
			else if (rollA < 69) ss << "Igniting";
			else if (rollA < 70) ss << "Impact";
			else if (rollA < 71) ss << "Invigorating";
			else if (rollA < 72) ss << "Ki Intensifying";
			else if (rollA < 73) ss << "Lifesurge";
			else if (rollA < 74) ss << "Negating";
			else if (rollA < 75) ss << "Phase Locking";
			else if (rollA < 84) ss << "Shocking Burst";
			else if (rollA < 85) ss << "Stalking";
			else if (rollA < 92) ss << "Unholy";
			else if (rollA < 101) ss << "Wounding";
			else std::cout << "Error Code 2553\n";
			break;
		case 3:
			if (rollA < 21) ss << "Nullifying";
			else if (rollA < 41) ss << "Repositioning";
			else if (rollA < 81) ss << "Speed";
			else if (rollA < 101) ss << "Spell Stealing";
			else std::cout << "Error Code 2560\n";
			break;
		case 4:
			if (rollA < 41) ss << "Brilliant Energy";
			else if (rollA < 101) ss << "Dancing";
			else std::cout << "Error Code 2565\n";
			break;
		case 5:
			if (rollA < 91) ss << "Vorpal";
			else if (rollA < 96) ss << "Transformative";
			else if (rollA < 101) ss << "Dueling";
			else std::cout << "Error Code 2571\n";
			break;
		default:
			std::cout << "Error Code 2574\n";
			break;
		}
	else if (type == 2)
		switch (subtype)
		{
		case 0:
			break;
		case 1:
			if (rollA < 2) ss << "Adaptive";
			else if (rollA < 3) ss << "Impervious";
			else if (rollA < 4) ss << "Glamered";
			else if (rollA < 7) ss << "Allying";
			else if (rollA < 16) ss << "Bane";
			else if (rollA < 17) ss << "Called";
			else if (rollA < 20) ss << "Conductive";
			else if (rollA < 21) ss << "Conserving";
			else if (rollA < 25) ss << "Corrosive";
			else if (rollA < 26) ss << "Cruel";
			else if (rollA < 29) ss << "Cunning";
			else if (rollA < 37) ss << "Distance";
			else if (rollA < 46) ss << "Flaming";
			else if (rollA < 55) ss << "Frost";
			else if (rollA < 59) ss << "Huntsman";
			else if (rollA < 63) ss << "Jurist";
			else if (rollA < 64) ss << "Limning";
			else if (rollA < 65) ss << "Lucky";
			else if (rollA < 67) ss << "Merciful";
			else if (rollA < 68) ss << "Planar";
			else if (rollA < 69) ss << "Reliable";
			else if (rollA < 77) ss << "Returning";
			else if (rollA < 85) ss << "Seeking";
			else if (rollA < 93) ss << "Shock";
			else if (rollA < 101) ss << "Thundering";
			else std::cout << "Error Code 2608\n";
			break;
		case 2:
			if (rollA < 11) ss << "Anarchic";
			else if (rollA < 14) ss << "Anchoring";
			else if (rollA < 24) ss << "Axiomatic";
			else if (rollA < 32) ss << "Corrosive Burst";
			else if (rollA < 35) ss << "Lesser Designating";
			else if (rollA < 38) ss << "Endless Ammunition";
			else if (rollA < 49) ss << "Flaming Burst";
			else if (rollA < 59) ss << "Holy";
			else if (rollA < 70) ss << "Icy Burst";
			else if (rollA < 74) ss << "Igniting";
			else if (rollA < 77) ss << "Phase Locking";
			else if (rollA < 87) ss << "Shocking Burst";
			else if (rollA < 91) ss << "Stalking";
			else if (rollA < 101) ss << "Unholy";
			else std::cout << "Error Code 2625\n";
			break;
		case 3:
			if (rollA < 26) ss << "Greater Lucky";
			else if (rollA < 46) ss << "Greater Reliable";
			else if (rollA < 86) ss << "Speed";
			else std::cout << "Error Code 2631\n";
			break;
		case 4:
		case 5:
		case 6:
			if (rollA < 95) ss << "Brilliant Energy";
			else if (rollA < 97) ss << "Greater Designating";
			else if (rollA < 99) ss << "Nimble Shot";
			else if (rollA < 101) ss << "Second Chance";
			else std::cout << "Error Code 2640\n";
			break;
		default:
			std::cout << "Error Code 2643\n";
			break;
		}
	else std::cout << "Error Code 2646\n";
	ss << " ";
	return ss.str();
}
std::string wPrefix(int type, int subtype)
{
	int rollA = roll(1, 100);
	std::stringstream ss;
	switch (subtype)
	{
	case 1:
		if (rollA < 81) ss << "+1 ";
		else if (rollA < 101) ss << "Lesser Minor specific weapon";
		else std::cout << "Error Code 2659\n";
		break;
	case 2:
		if (rollA < 27) ss << "+1 ";
		else if (rollA < 54) ss << "+2 ";
		else if (rollA < 81) ss << "+1 " + wEn(type, 1);
		else if (rollA < 101) ss << "Greater Minor specific weapon";
		else std::cout << "Error Code 2666\n";
		break;
	case 3:
		if (rollA < 11) ss << "+1 ";
		else if (rollA < 21) ss << "+2 ";
		else if (rollA < 33) ss << "+3 ";
		else if (rollA < 45) ss << "+1 " + wEn(type, 1);
		else if (rollA < 57) ss << "+1 " + wEn(type, 1) + wEn(type, 1);
		else if (rollA < 69) ss << "+1 " + wEn(type, 2);
		else if (rollA < 81) ss << "+2 " + wEn(type, 1);
		else if (rollA < 101) ss << "Lesser Medium specific weapon";
		else std::cout << "Error Code 2677\n";
		break;
	case 4:
		if (rollA < 11) ss << "+2 ";
		else if (rollA < 23) ss << "+3 ";
		else if (rollA < 33) ss << "+1 " + wEn(type, 1);
		else if (rollA < 54) ss << "+1 " + wEn(type, 2);
		else if (rollA < 57) ss << "+2 " + wEn(type, 1);
		else if (rollA < 69) ss << "+2 " + wEn(type, 2);
		else if (rollA < 81) ss << "+3 " + wEn(type, 3);
		else if (rollA < 101) ss << "Greater Medium specific weapon";
		else std::cout << "Error Code 2688\n";
		break;
	case 5:
		if (rollA < 11) ss << "+3 ";
		else if (rollA < 23) ss << "+4 ";
		else if (rollA < 33) ss << "+1 " + wEn(type, 2);
		else if (rollA < 45) ss << "+1 " + wEn(type, 3);
		else if (rollA < 57) ss << "+2 " + wEn(type, 2);
		else if (rollA < 69) ss << "+3 " + wEn(type, 1);
		else if (rollA < 81) ss << "+4 " + wEn(type, 1);
		else if (rollA < 101) ss << "Lesser Major specific weapon";
		else std::cout << "Error code 2699\n";
		break;
	case 6:
		if (rollA < 11) ss << "+4 ";
		else if (rollA < 21) ss << "+5 ";
		else if (rollA < 31) ss << "+4 " + wEn(type, 1);
		else if (rollA < 39) ss << "+4 " + wEn(type, 2);
		else if (rollA < 47) ss << "+4 " + wEn(type, 3);
		else if (rollA < 52) ss << "+4 " + wEn(type, 4);
		else if (rollA < 60) ss << "+5 " + wEn(type, 1);
		else if (rollA < 68) ss << "+5 " + wEn(type, 2);
		else if (rollA < 72) ss << "+5 " + wEn(type, 3);
		else if (rollA < 75) ss << "+5 " + wEn(type, 4);
		else if (rollA < 78) ss << "+5 " + wEn(type, 4) + wEn(type, 1);
		else if (rollA < 81) ss << "+5 " + wEn(type, 3) + wEn(type, 2);
		else if (rollA < 101) ss << "Greater Major specific weapon";
		else std::cout << "Error Code 2715\n";
		break;
	default:
		std::cout << "Error Code 2718\n";
		break;
	}
	return ss.str();
}
std::string weaponGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int t = 0, rollB;
		std::string w, p;
		do 
		{
			rollB = roll(1, 100);
			if (rollB < 2) { w = "Bastard Sword"; t = 1; }
			else if (rollB < 6) { w = "Battleaxe"; t = 1; }
			else if (rollB < 7) { w = "Bolas"; t = 1; }
			else if (rollB < 9) { w = "Club"; t = 1; }
			else if (rollB < 11) { w = "Composite Longbow"; t = 2; }
			else if (rollB < 13) { w = "Composite Shortbow"; t = 2; }
			else if (rollB < 17) { w = "Dagger"; t = 1; }
			else if (rollB < 18) { w = "Dart"; t = 2; }
			else if (rollB < 19) { w = "Dwarven Waraxe"; t = 1; }
			else if (rollB < 20) { w = "Falchion"; t = 1; }
			else if (rollB < 21) { w = "Gauntlet"; t = 1; }
			else if (rollB < 22) { w = "Glaive"; t = 1; }
			else if (rollB < 25) { w = "Greataxe"; t = 1; }
			else if (rollB < 26) { w = "Greatclub"; t = 1; }
			else if (rollB < 29) { w = "Greatsword"; t = 1; }
			else if (rollB < 30) { w = "Halberd"; t = 1; }
			else if (rollB < 31) { w = "Handaxe"; t = 1; }
			else if (rollB < 34) { w = "Heavy Crossbow"; t = 1; }
			else if (rollB < 35) { w = "Heavy Flail"; t = 1; }
			else if (rollB < 36) { w = "Heavy Mace"; t = 1; }
			else if (rollB < 38) { w = "Lance"; t = 1; }
			else if (rollB < 41) { w = "Light Crossbow"; t = 2; }
			else if (rollB < 42) { w = "Light Flail"; t = 1; }
			else if (rollB < 43) { w = "Light Hammer"; t = 1; }
			else if (rollB < 45) { w = "Light Mace"; t = 1; }
			else if (rollB < 46) { w = "Light Pick"; t = 1; }
			else if (rollB < 50) { w = "Longbow"; t = 2; }
			else if (rollB < 52) { w = "Longspear"; t = 1; }
			else if (rollB < 59) { w = "Longsword"; t = 1; }
			else if (rollB < 61) { w = "Morningstar"; t = 1; }
			else if (rollB < 62) { w = "Nunchaku"; t = 1; }
			else if (rollB < 64) { w = "Quarterstaff"; t = 1; }
			else if (rollB < 85) { w = "Rapier"; t = 1; }
			else if (rollB < 88) { w = "Spear"; t = 1; }
			else if (rollB < 89) { w = "Trident"; t = 1; }
			else if (rollB < 92) { w = "Warhammer"; t = 1; }
			else if (rollB < 95) { w = "Whip"; t = 1; }
			else if (rollB < 101) {}
			else std::cout << "Error Code 2771\n";
		} while (rollB >= 95);
		p = wPrefix(t, subtype);
		if (p.size() == 0) ss << "mwk " + w;
		else if (p.at(0) == '+') ss << p + w;
		else ss << p;
		ss << std::endl;
	}
	return ss.str();
}
std::string ringGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int rollA = roll(1, 100);
		switch (subtype)
		{
		case 1:
			if (rollA < 8) ss << "Prisoner's Dungeon Ring";
			else if (rollA < 17) ss << "Ring of Arcane Signets";
			else if (rollA < 26) ss << "Ring of Spell Knowledge I";
			else if (rollA < 41) ss << "Ring of Protection +1";
			else if (rollA < 48) ss << "Ring of the Grasping Grave";
			else if (rollA < 58) ss << "Ring of Feather Falling";
			else if (rollA < 67) ss << "Ring of Climbing";
			else if (rollA < 76) ss << "Ring of Jumping";
			else if (rollA < 85) ss << "Ring of Sustenance";
			else if (rollA < 94) ss << "Ring of Swimming";
			else if (rollA < 101) ss << "Ring of Ferocious Action";
			else std::cout << "Error Code 2801\n";
			break;
		case 2:
			if (rollA < 16) ss << "Ring of Counterspells";
			else if (rollA < 26) ss << "Ring of Maniacal Devices";
			else if (rollA < 36) ss << "Ring of Rat Fangs";
			else if (rollA < 53) ss << "Ring of Sacred Mistletoe";
			else if (rollA < 70) ss << "Ring of Spell Knowledge II";
			else if (rollA < 87) ss << "Ring of Swarming Stabs";
			else if (rollA < 101) ss << "Ring of Grit Mastery";
			else std::cout << "Error Code 2811\n";
			break;
		case 3:
			if (rollA < 3) ss << "Ring of Forcefangs";
			else if (rollA < 7) ss << "Ring of Mind Shielding";
			else if (rollA < 12) ss << "Ring of Protection +2";
			else if (rollA < 14) ss << "Ring of Strength Sapping";
			else if (rollA < 18) ss << "Ring of Force Shield";
			else if (rollA < 23) ss << "Ring of the Ram";
			else if (rollA < 25) ss << "Scholar's Ring";
			else if (rollA < 28) ss << "Improved Ring of Climbing";
			else if (rollA < 30) ss << "Ring of Curing";
			else if (rollA < 32) ss << "Ring of Foe Focus";
			else if (rollA < 36) ss << "Improved Ring of Jumping";
			else if (rollA < 38) ss << "Ring of Ki Mastery";
			else if (rollA < 41) ss << "Lesser Ring of Revelation";
			else if (rollA < 44) ss << "Improved Ring of Swimming";
			else if (rollA < 47) ss << "Ring of Animal Friendship";
			else if (rollA < 49) ss << "Ring of Transposition";
			else if (rollA < 51) ss << "Ring of Tactical Precision";
			else if (rollA < 53) ss << "Ring of the Sophisticate";
			else if (rollA < 56) ss << "Decoy Ring";
			else if (rollA < 59) ss << "Ring of Craft Magic";
			else if (rollA < 62) ss << "Ring of Ectoplasmic Invigoration";
			else if (rollA < 65) ss << "Minor Ring of Energy Resistance";
			else if (rollA < 68) ss << "Ring of the Troglodyte";
			else if (rollA < 71) ss << "Steelhand Circle";
			else if (rollA < 77) ss << "Ring of Chameleon";
			else if (rollA < 80) ss << "Ring of Spell Knowledge III";
			else if (rollA < 83) ss << "Ring of the Sea Strider";
			else if (rollA < 86) ss << "Ring of Retribution";
			else if (rollA < 90) ss << "Ring of Water Walking";
			else if (rollA < 96) ss << "Jailer's Dungeon Ring";
			else if (rollA < 101) ss << "Greater Ring of Revelation";
			else std::cout << "Error Code 2845\n";
			break;
		case 4:
			if (rollA < 5) ss << "Minor Ring of Inner Fortitude";
			else if (rollA < 17) ss << "Ring of Protection +3";
			else if (rollA < 27) ss << "Minor Ring of Spell Storing";
			else if (rollA < 31) ss << "Ring of Energy Shroud";
			else if (rollA < 36) ss << "Ring of Arcane Mastery";
			else if (rollA < 47) ss << "Ring of Invisibility";
			else if (rollA < 55) ss << "Ring of Wizardry I";
			else if (rollA < 61) ss << "Superior Ring of Revelation";
			else if (rollA < 69) ss << "Ring of Spell Knowledge IV";
			else if (rollA < 81) ss << "Ring of Evasion";
			else if (rollA < 89) ss << "Ring of X-Ray Vision";
			else if (rollA < 101) ss << "Ring of Blinking";
			else std::cout << "Error Code 2860\n";
			break;
		case 5:
			if (rollA < 10) ss << "Major Ring of Energy Resistance";
			else if (rollA < 17) ss << "Ring of the Ecclesiarch";
			else if (rollA < 34) ss << "Ring of Protection +4";
			else if (rollA < 40) ss << "Ring of Return";
			else if (rollA < 56) ss << "Ring of Freedom of Movement";
			else if (rollA < 71) ss << "Ring of Wizardry II";
			else if (rollA < 76) ss << "Major Ring of Inner Fortitude";
			else if (rollA < 93) ss << "Greater Ring of Energy Resistance";
			else if (rollA < 101) ss << "Ring of Delayed Doom";
			else std::cout << "Error Code 2872\n";
			break;
		case 6:
			if (rollA < 7) ss << "Ring of Friend Shield";
			else if (rollA < 19) ss << "Ring of Protection +5";
			else if (rollA < 28) ss << "Ring of Shooting Stars";
			else if (rollA < 38) ss << "Ring of Spell Storing";
			else if (rollA < 44) ss << "Ring of Continuation";
			else if (rollA < 49) ss << "Greater Ring of Inner Fortitude";
			else if (rollA < 58) ss << "Ring of Wizardry III";
			else if (rollA < 64) ss << "Spiritualist Rings";
			else if (rollA < 72) ss << "Ring of Telekinesis";
			else if (rollA < 77) ss << "Ring of Regeneration";
			else if (rollA < 83) ss << "Ring of Spell Turning";
			else if (rollA < 87) ss << "Ring of Wizardry IV";
			else if (rollA < 91) ss << "Ring of Three Wishes";
			else if (rollA < 94) ss << "Ring of Djinni Calling";
			else if (rollA < 98) ss << "Ring of Elemental Command";
			else if (rollA < 101) ss << "Major Ring of Spell Storing";
			else std::cout << "Error Code 2891\n";
			break;
		default:
			std::cout << "Error Code 2894\n";
			break;
		}
		ss << std::endl;
	}
	return ss.str();
}
std::string wGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int rollG = roll(1, 100), rollA = roll(1, 100);
		if (rollG < 7) // Belts
			switch (subtype)
			{
			case 1:
				if (rollA < 17) ss << "Belt of Tumbling";
				else if (rollA < 29) ss << "Beneficial Bandolier";
				else if (rollA < 41) ss << "Meridian Belt";
				else if (rollA < 55) ss << "Bladed Belt";
				else if (rollA < 71) ss << "Heavyload Belt";
				else if (rollA < 85) ss << "Aquatic Cummerbund";
				else if (rollA < 101) ss << "Equestrian Belt";
				else std::cout << "Error Code 2918\n";
				break;
			case 2:
				if (rollA < 19) ss << "Belt of Giant Strength +2";
				else if (rollA < 37) ss << "Belt of Incredible Dexterity +2";
				else if (rollA < 55) ss << "Belt of Mighty Constitution +2";
				else if (rollA < 63) ss << "Belt of Teeth";
				else if (rollA < 75) ss << "Blinkback Belt";
				else if (rollA < 85) ss << "Plague Rat Belt";
				else if (rollA < 101) ss << "Belt of Foraging";
				else std::cout << "Error Code 2928\n";
				break;
			case 3:
				if (rollA < 5) ss << "Serpent Belt";
				else if (rollA < 9) ss << "Monkey Belt";
				else if (rollA < 17) ss << "Belt of Physical Might +2";
				else if (rollA < 23) ss << "Belt of the Weasel";
				else if (rollA < 28) ss << "Belt of Thunderous Charging";
				else if (rollA < 33) ss << "Minotaur Belt";
				else if (rollA < 37) ss << "Greater Plague Rat Belt";
				else if (rollA < 42) ss << "Belt of Equilibrium";
				else if (rollA < 47) ss << "Security Belt";
				else if (rollA < 52) ss << "Lesser Belt of Mighty Hurling";
				else if (rollA < 58) ss << "Belt of Dwarvenkind";
				else if (rollA < 62) ss << "Cord of Stubborn Resolve";
				else if (rollA < 72) ss << "Belt of Giant Strength +4";
				else if (rollA < 81) ss << "Belt of Physical Perfection +2";
				else if (rollA < 91) ss << "Belt of Incredible Dexterity +4";
				else if (rollA < 101) ss << "Belt of Mighty Constitution +4";
				else std::cout << "Error Code 2947\n";
				break;
			case 4:
				if (rollA < 13) ss << "Greater Monkey Belt";
				else if (rollA < 27) ss << "Anaconda Coils";
				else if (rollA < 39) ss << "Greater Serpent Belt";
				else if (rollA < 54) ss << "Belt of Fallen Heroes";
				else if (rollA < 68) ss << "Gorgon Belt";
				else if (rollA < 85) ss << "Elemental Earth Belt";
				else if (rollA < 101) ss << "Sash of Flowing Water";
				else std::cout << "Error Code 2957\n";
				break;
			case 5:
				if (rollA < 13) ss << "Merform Belt";
				else if (rollA < 31) ss << "Belt of Giant Strength +6";
				else if (rollA < 49) ss << "Belt of Incredible Dexterity +6";
				else if (rollA < 67) ss << "Belt of Mighty Constitution +6";
				else if (rollA < 89) ss << "Belt of Physical Might +4";
				else if (rollA < 101) ss << "Greater Belt of Mighty Hurling";
				else std::cout << "Error Code 2966\n";
				break;
			case 6:
				if (rollA < 26) ss << "Belt of Stoneskin";
				else if (rollA < 56) ss << "Belt of Physical Perfection +4";
				else if (rollA < 76) ss << "Belt of Physical Might +6";
				else if (rollA < 91) ss << "Shadowform Belt";
				else if (rollA < 101) ss << "Belt of Physical Perfection +6";
				else std::cout << "Error Code 2974\n";
				break;
			default:
				std::cout << "Error Code 2977\n";
				break;
			}
		else if (rollG < 13) // Body
			switch (subtype)
			{
			case 1:
				if (rollA < 21) ss << "Robe of Infinite Twine";
				else if (rollA < 36) ss << "Robe of Needles";
				else if (rollA < 61) ss << "Robe of Bones";
				else if (rollA < 71) ss << "Bodywrap of Mighty Strikes +1";
				else if (rollA < 81) ss << "Corset of the Vishkanya";
				else if (rollA < 101) ss << "Druid's Vestment";
				else std::cout << "Error Code 2990\n";
				break;
			case 2:
				if (rollA < 16) ss << "Cassock of the the Clergy";
				else if (rollA < 31) ss << "Mnemonic Vestments";
				else if (rollA < 46) ss << "Robe of Components";
				else if (rollA < 61) ss << "Sorcerer's Robe";
				else if (rollA < 76) ss << "Eidolon Ancoring Harness";
				else if (rollA < 101) ss << "Robe of Useful Items";
				else std::cout << "Error Code 2999\n";
				break;
			case 3:
				if (rollA < 16) ss << "Robe of Blending";
				else if (rollA < 27) ss << "Blazing Robes";
				else if (rollA < 38) ss << "Shocking Robe";
				else if (rollA < 49) ss << "Voidfrost Robes";
				else if (rollA < 60) ss << "Bodywrap of Mighty Strikes +2";
				else if (rollA < 76) ss << "Monk's Robe";
				else if (rollA < 101) ss << "Robe of Arcane Heritage";
				else std::cout << "Error Code 3009\n";
				break;
			case 4:
				if (rollA < 26) ss << "Xorn Robe";
				else if (rollA < 53) ss << "Corset of Dire Witchcraft";
				else if (rollA < 77) ss << "Bodywrap of Mighty Stikes +3";
				else if (rollA < 101) ss << "Robe of Scintillating Colors";
				else std::cout << "Error Code 3016\n";
				break;
			case 5:
				if (rollA < 41) ss << "Gunman's Duster";
				else if (rollA < 81) ss << "Bodywrap of Mighty Strikes +4";
				else if (rollA < 101) ss << "Smuggler's Collapsable Robe";
				else std::cout << "Error Code 3022\n";
				break;
			case 6:
				if (rollA < 11) ss << "Robe of Stars";
				else if (rollA < 16) ss << "Robe of Gates";
				else if (rollA < 21) ss << "Otherworldly Kimono";
				else if (rollA < 41) ss << "Bodywrap of Mighty Strikes +5";
				else if (rollA < 52) ss << "Resplendent Robe of the Thespian";
				else if (rollA < 68) ss << "Robe of the Archmagi";
				else if (rollA < 48) ss << "Bodywrap of Mighty Strikes +6";
				else if (rollA < 98) ss << "Robe of Eyes";
				else if (rollA < 101) ss << "Bodywrap of Mighty Strikes +7";
				else std::cout << "Error Code 3034\n";
				break;
			default:
				std::cout << "Error Code 3037\n";
				break;
			}
		else if (rollG < 18) // Chest
			switch (subtype)
			{
			case 1:
				if (rollA < 16) ss << "Bandages of Rapid Recovery";
				else if (rollA < 31) ss << "Quick Runner's Shirt";
				else if (rollA < 51) ss << "Endless Bandolier";
				else if (rollA < 76) ss << "All Tools Vest";
				else if (rollA < 101) ss << "Vest of Surgery";
				else std::cout << "Error Code 3049\n";
				break;
			case 2:
				if (rollA < 11) ss << "Sash of the War Champion";
				else if (rollA < 21) ss << "Slipping Jacket";
				else if (rollA < 32) ss << "Tunic of Careful Casting";
				else if (rollA < 43) ss << "Vest of Escape";
				else if (rollA < 53) ss << "Cackling Hag's Blouse";
				else if (rollA < 63) ss << "Deadshot Vest";
				else if (rollA < 71) ss << "Prophet's Pectoral";
				else if (rollA < 80) ss << "Tunic of Deadly Might";
				else if (rollA < 91) ss << "Vest of the Vengeful Tracker";
				else if (rollA < 101) ss << "Resplendent Uniform";
				else std::cout << "Error Code 3062\n";
				break;
			case 3:
				if (rollA < 14) ss << "Shirt of Immolation";
				else if (rollA < 29) ss << "Snakeskin Tunic";
				else if (rollA < 41) ss << "Bane Baldric";
				else if (rollA < 61) ss << "Unfettered Shirt";
				else if (rollA < 81) ss << "Lesser Prisoner's Jacket";
				else if (rollA < 101) ss << "Vest of the Cockroach";
				else std::cout << "Error Code 3071\n";
				break;
			case 4:
				if (rollA < 51) ss << "Vest of Stable Mutagen";
				else if (rollA < 101) ss << "Spectral Shroud";
				else std::cout << "Error Code 3076\n";
				break;
			case 5:
				if (rollA < 61) ss << "Mantle of Immortality";
				else if (rollA < 101) ss << "Greater Prisoner's Jacket";
				else std::cout << "Error Code 3081\n";
				break;
			case 6:
				if (rollA < 36) ss << "Merciful Baldric";
				else if (rollA < 71) ss << "Mantle of Faith";
				else if (rollA < 101) ss << "Mantle of Spell Resistance";
				else std::cout << "Error Code 3087\n";
				break;
			default:
				std::cout << "Error Code 3090\n";
				break;
			}
		else if (rollG < 23) // Eyes
			switch (subtype)
			{
			case 1:
				if (rollA < 19) ss << "Deathwatch Eyes";
				else if (rollA < 39) ss << "Eyes of the Eagle";
				else if (rollA < 59) ss << "Goggles of Minute Seeing";
				else if (rollA < 73) ss << "Pirate's Eye Patch";
				else if (rollA < 88) ss << "Spectacles of Understanding";
				else if (rollA < 101) ss << "Lenses of Detection";
				else std::cout << "Error Code 3103\n";
				break;
			case 2:
				if (rollA < 21) ss << "Eyes of the Owl";
				else if (rollA < 45) ss << "Eyes of Keen Sight";
				else if (rollA < 67) ss << "Treasure Hunter's Goggles";
				else if (rollA < 85) ss << "Inquisitor's Monacle";
				else if (rollA < 101) ss << "Kinsight Goggles";
				else std::cout << "Error Code 3111\n";
				break;
			case 3:
				if (rollA < 17) ss << "Goggles of Elvenkind";
				else if (rollA < 32) ss << "Goggles of Brilliant Light";
				else if (rollA < 49) ss << "Blind Man's Fold";
				else if (rollA < 68) ss << "Goggles of Night";
				else if (rollA < 83) ss << "Lenses of Figment Piercing";
				else if (rollA < 101) ss << "Arachnid Goggles";
				else std::cout << "Error Code 3120\n";
				break;
			case 4:
				if (rollA < 22) ss << "Darksight Goggles";
				else if (rollA < 41) ss << "Sniper Goggles";
				else if (rollA < 59) ss << "Rainbow Lenses";
				else if (rollA < 78) ss << "Annihilation Spectacles";
				else if (rollA < 101) ss << "Eyes of Doom";
				else std::cout << "Error Code 3128\n";
				break;
			case 5:
				if (rollA < 61) ss << "Eyes of Eyebite";
				else if (rollA < 101) ss << "Greater Sniper Goggles";
				else std::cout << "Error Code 3133\n";
				break;
			case 6:
				if (rollA < 19) ss << "Eyes of Charming";
				else if (rollA < 35) ss << "Monacle of the Investigatior";
				else if (rollA < 49) ss << "Sea Tyrant's Patch";
				else if (rollA < 64) ss << "Swordmaster's Blindfold";
				else if (rollA < 78) ss << "Mindmaster's Eyes";
				else if (rollA < 91) ss << "Eyes of the Dragon";
				else if (rollA < 101) ss << "Truesight Goggles";
				else std::cout << "Error Code 3143\n";
				break;
			default:
				std::cout << "Error Code 3146\n";
				break;
			}
		else if (rollG < 29) // Feet
			switch (subtype)
			{
			case 1:
				if (rollA < 12) ss << "Boots of the Cat";
				else if (rollA < 23) ss << "Daredevil Boots";
				else if (rollA < 32) ss << "Boots of the Enduring March";
				else if (rollA < 42) ss << "Feather Step Slippers";
				else if (rollA < 51) ss << "Boots of Friendly Terrain";
				else if (rollA < 61) ss << "Boots of the Winterlands";
				else if (rollA < 77) ss << "Boots of Elvenkind";
				else if (rollA < 86) ss << "Acrobat Slippers";
				else if (rollA < 93) ss << "Horseshoes of Speed";
				else if (rollA < 101) ss << "Boots of the Mire";
				else std::cout << "Error Code 3163\n";
				break;
			case 2:
				if (rollA < 8) ss << "Burgular Boots (minor)";
				else if (rollA < 14) ss << "Horseshoes of Crushing Blows";
				else if (rollA < 20) ss << "Sandals of Quick Reaction";
				else if (rollA < 27) ss << "Slippers of Cloudwalking";
				else if (rollA < 41) ss << "Slippers of Spider Climbing";
				else if (rollA < 47) ss << "Sandals of the Lightest Step";
				else if (rollA < 61) ss << "Boots of Striding and Springing";
				else if (rollA < 69) ss << "Horseshoes of a Zephyr";
				else if (rollA < 76) ss << "Haunted Shoes";
				else if (rollA < 83) ss << "Jaunt Boots";
				else if (rollA < 101) ss << "Boots of Levitation";
				else std::cout << "Error Code 3177\n";
				break;
			case 3:
				if (rollA < 9) ss << "Boots of Escape";
				else if (rollA < 15) ss << "Earth Root Boots";
				else if (rollA < 22) ss << "Nightmare Boots";
				else if (rollA < 27) ss << "Nightmare Horseshoes";
				else if (rollA < 33) ss << "Caltrop Boots";
				else if (rollA < 40) ss << "Tremor Boots";
				else if (rollA < 48) ss << "Boots of the Mastedon";
				else if (rollA < 55) ss << "Shoes of the Lightning Leaper";
				else if (rollA < 71) ss << "Boots of Speed";
				else if (rollA < 78) ss << "Verdant Boots";
				else if (rollA < 85) ss << "Horseshoes of Crushing Blows";
				else if (rollA < 101) ss << "Winged Boots";
				else std::cout << "Error Code 3192\n";
				break;
			case 4:
				if (rollA < 39) ss << "Shoes of the Firewalker";
				else if (rollA < 73) ss << "Dryad Sandals";
				else if (rollA < 101) ss << "Horseshoes of the Mist";
				else std::cout << "Error Code 3198\n";
				break;
			case 5:
				if (rollA < 21) ss << "Getaway Boots";
				else if (rollA < 36) ss << "Horseshoes of Crushing Blows +3";
				else if (rollA < 56) ss << "Horseshoes of Glory";
				else if (rollA < 76) ss << "Burgular Boots (major)";
				else if (rollA < 101) ss << "Boots of Teleportation";
				else std::cout << "Error Code 3206\n";
				break;
			case 6:
				if (rollA < 41) ss << "Slippers of the Triton";
				else if (rollA < 71) ss << "Horseshoes of Crushing Blows +4";
				else if (rollA < 101) ss << "Horseshoes of Crushing Blows +5";
				else std::cout << "Error Code 3212";
				break;
			default:
				std::cout << "Error Code 3215\n";
				break;
			}
		else if (rollG < 25) // Hands
			switch (subtype)
			{
			case 1:
				if (rollA < 14) ss << "Assisting Gloves";
				else if (rollA < 23) ss << "Claws of the Ice Bear";
				else if (rollA < 35) ss << "Gloves of Reconnaissance";
				else if (rollA < 47) ss << "Growing Glove";
				else if (rollA < 59) ss << "Apprentice's Cheating Glove";
				else if (rollA < 71) ss << "Challenger's Gloves";
				else if (rollA < 81) ss << "Gloves of Larceny";
				else if (rollA < 91) ss << "Healer's Gloves";
				else if (rollA < 101) ss << "Engineer's Workgloves";
				else std::cout << "Error Code 3231\n";
				break;
			case 2:
				if (rollA < 13) ss << "Gauntlets of the Skilled Maneuver";
				else if (rollA < 22) ss << "Ghostvision Gloves";
				else if (rollA < 34) ss << "Gloves of Arrow Snaring";
				else if (rollA < 44) ss << "Trapspringer's Gloves";
				else if (rollA < 56) ss << "Gloves of Arcane Striking";
				else if (rollA < 66) ss << "Prisoner's Gloves";
				else if (rollA < 76) ss << "Magnetist's Gloves";
				else if (rollA < 101) ss << "Gloves of Swimming and Climbing";
				else std::cout << "Error Code 3242\n";
				break;
			case 3:
				if (rollA < 3) ss << "Deliquescent Gloves";
				else if (rollA < 6) ss << "Form-Fixing Gauntlets";
				else if (rollA < 9) ss << "Iron Cobra Gauntlet";
				else if (rollA < 17) ss << "Shadow Falconer's Glove";
				else if (rollA < 21) ss << "Spellstrike Gloves";
				else if (rollA < 29) ss << "Glyphbane Gloves";
				else if (rollA < 41) ss << "Glove of Storing";
				else if (rollA < 47) ss << "Gloves of Shaping";
				else if (rollA < 55) ss << "Pliant Gloves";
				else if (rollA < 77) ss << "Gauntlets of Rust";
				else if (rollA < 101) ss << "Gloves of Dueling";
				else std::cout << "Error Code 3256\n";
				break;
			case 4:
				if (rollA < 31) ss << "Vampiric Gloves";
				else if (rollA < 66) ss << "Giant Fist Gauntlets";
				else if (rollA < 101) ss << "Gloves of the Shortened Path";
				else std::cout << "Error Code 3262\n";
				break;
			case 5:
				if (rollA < 41) ss << "Gloves of the Commanding Conjurer";
				else if (rollA < 101) ss << "Gauntlet of Rust (greater)";
				else std::cout << "Error Code 3267\n";
				break;
			case 6:
				if (rollA < 61) ss << "Talons of Leng";
				else if (rollA < 101) ss << "Gauntlets of the Weaponmaster";
				else std::cout << "Error Code 3272\n";
				break;
			default:
				std::cout << "Error Code 3275\n";
				break;
			}
		else if (rollG < 42) // Head
			switch (subtype)
			{
			case 1:
				if (rollA < 11) ss << "Mask of Stony Demeanor";
				else if (rollA < 23) ss << "Cap of Human Guise";
				else if (rollA < 37) ss << "Cap of Light";
				else if (rollA < 57) ss << "Hat of Disguise";
				else if (rollA < 72) ss << "Buffering Cap";
				else if (rollA < 86) ss << "Miser's Mask";
				else if (rollA < 101) ss << "Stalker's Mask";
				else std::cout << "Error Code 3289\n";
				break;
			case 2:
				if (rollA < 13) ss << "Circlet of Persuasion";
				else if (rollA < 22) ss << "Grappler's Mask";
				else if (rollA < 32) ss << "Helm of Fearson Mein";
				else if (rollA < 41) ss << "Jingasa of the Fortunate Soldier";
				else if (rollA < 55) ss << "Helm of Comprehend Languages and Read Magic";
				else if (rollA < 68) ss << "Crown of Swords";
				else if (rollA < 88) ss << "Crown of Blasting (minor)";
				else if (rollA < 101) ss << "Mask of the Krenshar";
				else std::cout << "Error Code 3300\n";
				break;
			case 3:
				if (rollA < 17) ss << "Helm of the Mammoth Lord";
				else if (rollA < 31) ss << "Veil of Fleeting Glances";
				else if (rollA < 47) ss << "Mask of a Thousand Tomes";
				else if (rollA < 64) ss << "Medusa Mask";
				else if (rollA < 81) ss << "Cap of the Free Thinker";
				else if (rollA < 101) ss << "Halo of Inner Calm";
				else std::cout << "Error Code 3309\n";
				break;
			case 4:
				if (rollA < 7) ss << "Cat's Eye Crown";
				else if (rollA < 13) ss << "Maw of the Wyrm";
				else if (rollA < 20) ss << "Mitre of the Hierophant";
				else if (rollA < 28) ss << "Magician's Hat";
				else if (rollA < 35) ss << "Circlet of Mindsight";
				else if (rollA < 43) ss << "Mask of the Skull";
				else if (rollA < 51) ss << "Howling Helm";
				else if (rollA < 63) ss << "Crown of Blasting (major)";
				else if (rollA < 73) ss << "Helm of Underwater Action";
				else if (rollA < 80) ss << "Crown of Conquest";
				else if (rollA < 86) ss << "Batrachian Helm";
				else if (rollA < 95) ss << "Helm of Telepathy";
				else if (rollA < 101) ss << "Plague Mask";
				else std::cout << "Error Code 3325\n";
				break;
			case 5:
				if (rollA < 15) ss << "Iron Circlet of Guarded Souls";
				else if (rollA < 30) ss << "Laurel of Command";
				else if (rollA < 46) ss << "Mask of Giants (lesser)";
				else if (rollA < 62) ss << "Steel-Minded Cap";
				else if (rollA < 79) ss << "Stormlord's Helm";
				else if (rollA < 101) ss << "Helm of Brilliance (lesser)";
				else std::cout << "Error Code 3334\n";
				break;
			case 6:
				if (rollA < 15) ss << "Judge's Wig";
				else if (rollA < 40) ss << "Helm of Teleportation";
				else if (rollA < 56) ss << "Halo of Menace";
				else if (rollA < 69) ss << "Mask of Giants (greater)";
				else if (rollA < 84) ss << "Helm of Brilliance";
				else if (rollA < 93) ss << "Helm of Electric Radiance";
				else if (rollA < 101) ss << "Crown of Heaven";
				else std::cout << "Error Code 3344\n";
				break;
			default:
				std::cout << "Error Code 3347\n";
				break;
			}
		else if (rollG < 48) // Headband
			switch (subtype)
			{
			case 1:
				if (rollA < 61) ss << "Phylactery of Faithfulness";
				else if (rollA < 101) ss << "Dead Man's Headband";
				else std::cout << "Error Code 3356\n";
				break;
			case 2:
				if (rollA < 10) ss << "Headband of Alluring Charisma +2";
				else if (rollA < 19) ss << "Headband of Inspired Wisdom +2";
				else if (rollA < 28) ss << "Headband of Vast Intelligence +2";
				else if (rollA < 34) ss << "Headband of Aerial Agility +2";
				else if (rollA < 40) ss << "Shifter's Headband +2";
				else if (rollA < 46) ss << "Headband of Ponderous Recollection";
				else if (rollA < 52) ss << "Headband of Ki Focus";
				else if (rollA < 59) ss << "Headband of Unshakable Resolve";
				else if (rollA < 67) ss << "Hollywreath Band";
				else if (rollA < 75) ss << "Headband of Deathless Devotion";
				else if (rollA < 83) ss << "Phylactery of the Shepherd";
				else if (rollA < 92) ss << "Headband of Intuition";
				else if (rollA < 101) ss << "Headband of Fortune's Favor";
				else std::cout << "Error Code 3372\n";
				break;
			case 3:
				if (rollA < 7) ss << "Headband of Havoc";
				else if (rollA < 13) ss << "Serpent's Band";
				else if (rollA < 21) ss << "Headband of Mental Prowess +2";
				else if (rollA < 27) ss << "Hunter's Band";
				else if (rollA < 35) ss << "Phylactery of Negative Channeling";
				else if (rollA < 43) ss << "Phylactery of Positive Channeling";
				else if (rollA < 49) ss << "Veiled Eye";
				else if (rollA < 55) ss << "Band of the Stalwart Warrior";
				else if (rollA < 61) ss << "Headband of Ninjitsu";
				else if (rollA < 69) ss << "Headband of Alluring Charisma +4";
				else if (rollA < 77) ss << "Headband of Inspired Wisdom +4";
				else if (rollA < 86) ss << "Headband of Mental Superiority +2";
				else if (rollA < 94) ss << "Headband of Vast Intelligence";
				else if (rollA < 101) ss << "Shifter's Headband +4";
				else std::cout << "Error Code 3389\n";
				break;
			case 4:
				if (rollA < 31) ss << "Headband of Arcane Energy";
				else if (rollA < 71) ss << "Headband of Counterspelling";
				else if (rollA < 101) ss << "Headband of Knucklebones";
				else std::cout << "Error Code 3395\n";
				break;
			case 5:
				if (rollA < 10) ss << "Soulbound Eye";
				else if (rollA < 20) ss << "Winter Wolf Headband";
				else if (rollA < 33) ss << "Headband of Alluring Charisma +6";
				else if (rollA < 46) ss << "Headband of Inspired Wisdom +6";
				else if (rollA < 59) ss << "Headband of Vast Intelligence +6";
				else if (rollA < 57) ss << "Shifter's Headband +6";
				else if (rollA < 82) ss << "Headband of Mental Prowess +4";
				else if (rollA < 91) ss << "Headband of Seduction";
				else if (rollA < 101) ss << "Headband of Aerial Agility +4";
				else std::cout << "Error Code 3407\n";
				break;
			case 6:
				if (rollA < 21) ss << "Headband of Mental Resiliance";
				else if (rollA < 51) ss << "Headband of Mental Superiority +4";
				else if (rollA < 66) ss << "Headband of Aerial Agility +6";
				else if (rollA < 86) ss << "Headband of Mental Prowess +6";
				else if (rollA < 101) ss << "Headband of Mental Superiority +6";
				else std::cout << "Error Code 3415\n";
				break;
			default:
				std::cout << "Error Code 3418\n";
				break;
			}
		else if (rollG < 55) // Neck
			switch (subtype)
			{
			case 1:
				if (rollA < 11) ss << "Hand of the Mage";
				else if (rollA < 19) ss << "Aegis of Recovery";
				else if (rollA < 26) ss << "Amulet of Bullet Protection +1";
				else if (rollA < 38) ss << "Brooch of Shielding";
				else if (rollA < 50) ss << "Necklace of Fireballs (type I)";
				else if (rollA < 64) ss << "Amulet of Natural Armor +1";
				else if (rollA < 73) ss << "Golembane Scarab";
				else if (rollA < 83) ss << "Necklace of Fireballs (type II)";
				else if (rollA < 90) ss << "Swarmbane Clasp";
				else if (rollA < 96) ss << "Mind Sentinal's Medallion";
				else if (rollA < 101) ss << "Mummer's Ruff";
				else std::cout << "Error Code 3436\n";
				break;
			case 2:
				if (rollA < 9) ss << "Amulet of Elemental Strife";
				else if (rollA < 16) ss << "Righteous Fist Amulet";
				else if (rollA < 27) ss << "Amulet of Mighty Fists +1";
				else if (rollA < 37) ss << "Necklace of Fireballs (type III)";
				else if (rollA < 48) ss << "Necklace of Fireballs (type IV)";
				else if (rollA < 56) ss << "Stormlure";
				else if (rollA < 67) ss << "Necklace of Fireballs (type V)";
				else if (rollA < 74) ss << "Amulet of Bullet Protection +2";
				else if (rollA < 82) ss << "Feychild Necklace";
				else if (rollA < 90) ss << "Carcanet of Destruction";
				else if (rollA < 101) ss << "Periapt of Health";
				else std::cout << "Error Code 3450\n";
				break;
			case 3:
				if (rollA < 9) ss << "Amulet of Natural Armor +2";
				else if (rollA < 13) ss << "Amulet of Proof Against Petrification";
				else if (rollA < 16) ss << "Everwake Amulet";
				else if (rollA < 19) ss << "Gravewatch Pendant";
				else if (rollA < 24) ss << "Hand of Glory";
				else if (rollA < 27) ss << "Torc of Lionheart Fury";
				else if (rollA < 34) ss << "Necklace of Fireballs (type VI)";
				else if (rollA < 41) ss << "Necklace of Fireballs (type VII)";
				else if (rollA < 44) ss << "Amulet of Hidden Strength";
				else if (rollA < 48) ss << "Necklace of Adaptation";
				else if (rollA < 52) ss << "Amulet of Spell Cunning";
				else if (rollA < 55) ss << "Collar of the True Companion";
				else if (rollA < 59) ss << "Frost Fist Amulet";
				else if (rollA < 64) ss << "Crystal of Healing Hands";
				else if (rollA < 97) ss << "Guardian Gorget";
				else if (rollA < 74) ss << "Medallion of Thoughts";
				else if (rollA < 78) ss << "Periapt of Protection from Curses";
				else if (rollA < 82) ss << "Forge Fist Amulet";
				else if (rollA < 86) ss << "Amulet of Bullet Protection +3";
				else if (rollA < 93) ss << "Periapt of Wound Closure";
				else if (rollA < 96) ss << "Amulet of Mighty Fists +2";
				else if (rollA < 99) ss << "Necklace of Ki Serenity";
				else if (rollA < 101) ss << "Brooch of Amber Sparks";
				else std::cout << "Error Code 3476\n";
				break;
			case 4:
				if (rollA < 16) ss << "Symbol of Sanguine Protection";
				else if (rollA < 25) ss << "Amulet of Natural Armor +3";
				else if (rollA < 36) ss << "Ampuole of False Blood";
				else if (rollA < 51) ss << "Amulet of Magecraft";
				else if (rollA < 63) ss << "Dragonfor Amulet";
				else if (rollA < 68) ss << "Amulet of Spell Mastery";
				else if (rollA < 73) ss << "Amulet of Bullet Protection +4";
				else if (rollA < 86) ss << "Hand of Stone";
				else if (rollA < 101) ss << "Periapt of Proof Against Poison";
				else std::cout << "Error Code 3488\n";
				break;
			case 5:
				if (rollA < 19) ss << "Amulet of Natural Armor";
				else if (rollA < 36) ss << "Amulet of Proof Against Detection and Location";
				else if (rollA < 50) ss << "Amulet of Mighty Fists +3";
				else if (rollA < 68) ss << "Amulet of Bullet Protection +5";
				else if (rollA < 83) ss << "Scarab of Protection";
				else if (rollA < 101) ss << "Necklace of Netted Stars";
				else std::cout << "Error Code 3497\n";
				break;
			case 6:
				if (rollA < 36) ss << "Amulet of Natural Armor +5";
				else if (rollA < 61) ss << "Amulet of Mighty Fists +4";
				else if (rollA < 86) ss << "Amulet of Mighty Fists +5";
				else if (rollA < 101) ss << "Amulet of the Planes";
				else std::cout << "Error Code 3504\n";
				break;
			default:
				std::cout << "Error Code 3507\n";
				break;
			}
		else if (rollG < 62) // Shoulders
			switch (subtype)
			{
			case 1:
				if (rollA < 7) ss << "Catching Cape";
				else if (rollA < 11) ss << "Cloak of Human Guise";
				else if (rollA < 31) ss << "Cloak of Resistance +1";
				else if (rollA < 37) ss << "Muleback Cords";
				else if (rollA < 39) ss << "Shawl of Life-Kepping";
				else if (rollA < 45) ss << "Shield Cloak";
				else if (rollA < 51) ss << "Quickchange Cloak";
				else if (rollA < 57) ss << "Cowardly Crouching Cloak";
				else if (rollA < 75) ss << "Cloak of Elvenkind";
				else if (rollA < 81) ss << "Cloak of the Hedge Wizard";
				else if (rollA < 86) ss << "Cloak of Firey Vanishing";
				else if (rollA < 95) ss << "Cloak of Fangs";
				else if (rollA < 98) ss << "Pauldrons of the Serpent";
				else if (rollA < 101) ss << "Stonemist Cloak";
				else std::cout << "Error Code 3528\n";
				break;
			case 2:
				if (rollA < 27) ss << "Cloak of Resistance +2";
				else if (rollA < 39) ss << "Cloak of the Scuttling Rat";
				else if (rollA < 40) ss << "Seafoam Shawl";
				else if (rollA < 53) ss << "Treeform Cloak";
				else if (rollA < 75) ss << "Eagle Cape";
				else if (rollA < 95) ss << "Cloak of the Manta Ray";
				else if (rollA < 101) ss << "Hunter's Cloak";
				else std::cout << "Error Code 3538\n";
				break;
			case 3:
				if (rollA < 21) ss << "Cloak of Resistance +3";
				else if (rollA < 23) ss << "Cloak of the Dustwalker";
				else if (rollA < 26) ss << "Cocoon Cloak";
				else if (rollA < 28) ss << "Pauldrons of the Bull";
				else if (rollA < 33) ss << "Stone Cloak (minor)";
				else if (rollA < 41) ss << "Cape of the Mountebank";
				else if (rollA < 46) ss << "Pauldrons of the Watchful Lion";
				else if (rollA < 53) ss << "Lion Cloak";
				else if (rollA < 55) ss << "Mantle of Spores";
				else if (rollA < 60) ss << "Cape of Effulgent Escape";
				else if (rollA < 70) ss << "Cloak of Arachnida";
				else if (rollA < 73) ss << "Gunfighter's Poncho";
				else if (rollA < 75) ss << "Tentacle Cloak";
				else if (rollA < 77) ss << "Demonspike Pauldrons";
				else if (rollA < 79) ss << "Comfort's Cloak";
				else if (rollA < 89) ss << "Cloak of Resistance +4";
				else if (rollA < 92) ss << "Shawl of the Crone";
				else if (rollA < 101) ss << "Prestidigitator's Cloak";
				else std::cout << "Error Code 3559\n";
				break;
			case 4:
				if (rollA < 13) ss << "Stole of Justice";
				else if (rollA < 25) ss << "Jellyfish Cape";
				else if (rollA < 33) ss << "Cloak of the Diplomat";
				else if (rollA < 45) ss << "Slashing Cloak";
				else if (rollA < 57) ss << "Stone Cloak (major)";
				else if (rollA < 69) ss << "Cloak of Displacement (minor)";
				else if (rollA < 89) ss << "Cloak of Resistance +5";
				else if (rollA < 101) ss << "Cloak of the Bat";
				else std::cout << "Error Code 3570\n";
				break;
			case 5:
				if (rollA < 41) ss << "Highwayaman's Cape";
				else if (rollA < 61) ss << "Juggernaut's Pauldrons";
				else if (rollA < 101) ss << "Charlatan's Cape";
				else std::cout << "Error Code 3576\n";
				break;
			case 6:
				if (rollA < 16) ss << "Cloak of Displacement (major)";
				else if (rollA < 36) ss << "Wings of Flying";
				else if (rollA < 56) ss << "Cloak of Etherealness";
				else if (rollA < 81) ss << "Wings of the Gargoyle";
				else if (rollA < 101) ss << "Wyvern Cloak";
				else std::cout << "Error Code 3584\n";
				break;
			default:
				std::cout << "Error Code 3587\n";
				break;
			}
		else if (rollG < 68) // Wrists
			switch (subtype)
			{
			case 1:
				if (rollA < 11) ss << "Sleeves of Many Garments";
				else if (rollA < 21) ss << "Armbands of the Brawler";
				else if (rollA < 49) ss << "Bracers of Armor +1";
				else if (rollA < 64) ss << "Burglar's Bracers";
				else if (rollA < 92) ss << "Bracers of Steadiness";
				else if (rollA < 97) ss << "Manacles of Cooperation";
				else if (rollA < 101) ss << "Shackles of Compliance";
				else std::cout << "Error Code 3601\n";
				break;
			case 2:
				if (rollA < 28) ss << "Bracers of Armor +2";
				else if (rollA < 29) ss << "Bracers of Falcon's Aim";
				else if (rollA < 39) ss << "Inquisitor's Bastion Vambraces";
				else if (rollA < 66) ss << "Bracers of Archery (lesser)";
				else if (rollA < 69) ss << "Spellguard Bracers";
				else if (rollA < 72) ss << "Bonebreaker Gauntlets";
				else if (rollA < 82) ss << "Vambraces of Defense";
				else if (rollA < 99) ss << "Verdant Vine";
				else if (rollA < 100) ss << "Longarm Bracers";
				else if (rollA < 101) ss << "Bracers of the Glib Entertainer";
				else std::cout << "Error Code 3614\n";
				break;
			case 3:
				if (rollA < 5) ss << "Charm Bracelet";
				else if (rollA < 9) ss << "Duelist Vambraces";
				else if (rollA < 14) ss << "Merciful Vambraces";
				else if (rollA < 19) ss << "Vambraces of the Tactitian";
				else if (rollA < 44) ss << "Bracer's of Armor +3";
				else if (rollA < 54) ss << "Seducer's Bane";
				else if (rollA < 59) ss << "Bracers of the Avenging Knight";
				else if (rollA < 64) ss << "Arrowmaster's Bracers";
				else if (rollA < 74) ss << "Vambraces of the Genie (efreeti)";
				else if (rollA < 79) ss << "Bracelet of Bargaining";
				else if (rollA < 83) ss << "Bracers of Mercy";
				else if (rollA < 87) ss << "Bracers of the Merciful Knight";
				else if (rollA < 91) ss << "Bracelet of Second Chances";
				else if (rollA < 100) ss << "Bracers of Armor +4";
				else if (rollA < 101) ss << "Shackles of Durance Vile";
				else std::cout << "Error Code 3632\n";
				break;
			case 4:
				if (rollA < 11) ss << "Vambraces of the Genie (djinni)";
				else if (rollA < 21) ss << "Vambraces of the Genie (marid)";
				else if (rollA < 31) ss << "Vambraces of the Genie (shaitan)";
				else if (rollA < 51) ss << "Bracelet of Friends";
				else if (rollA < 71) ss << "Bracers of Archery (greater)";
				else if (rollA < 91) ss << "Bracers of Armor +5";
				else if (rollA < 101) ss << "Bracers of Sworn Venegance";
				else std::cout << "Error Code 3642\n";
				break;
			case 5:
				if (rollA < 31) ss << "Dimensional Shackles";
				else if (rollA < 46) ss << "Gauntlets of Skill at Arms";
				else if (rollA < 101) ss << "Bracers of Armor +6";
				else std::cout << "Error Code 3648\n";
				break;
			case 6:
				if (rollA < 61) ss << "Bracers of Armor +7";
				else if (rollA < 101) ss << "Bracers of Armor +8";
				else std::cout << "Error Code 3653\n";
				break;
			default:
				std::cout << "Error Code 3656\n";
				break;
			}
		else if (rollG < 101) // Slotless
			switch (subtype)
			{
			case 0:
				if (rollA < 2) ss << "Feather Token (Anchor)";
				else if (rollA < 3) ss << "Universal Solvent";
				else if (rollA < 5) ss << "Ioun Torch";
				else if (rollA < 6) ss << "Stubborn Nail";
				else if (rollA < 7) ss << "War Paint of the Terrible Visage";
				else if (rollA < 8) ss << "Elixir of Love";
				else if (rollA < 9) ss << "Unguent of Timelesness";
				else if (rollA < 10) ss << "Feather token (Fan)";
				else if (rollA < 11) ss << "Formula Alembic";
				else if (rollA < 12) ss << "Hybridization Funnel";
				else if (rollA < 13) ss << "Soul Soap";
				else if (rollA < 14) ss << "Dust of Tracelessness";
				else if (rollA < 17) ss << "Elixir of Hiding";
				else if (rollA < 20) ss << "Elixir of Swimming";
				else if (rollA < 23) ss << "Elixir of Tumbling";
				else if (rollA < 26) ss << "Elixir of Vision";
				else if (rollA < 28) ss << "Nightdrops";
				else if (rollA < 29) ss << "Oil of Silence";
				else if (rollA < 32) ss << "Silversheen";
				else if (rollA < 33) ss << "Traveler's Any-Tool";
				else if (rollA < 35) ss << "Bottle of Messages";
				else if (rollA < 37) ss << "Feather Token (Bird)";
				else if (rollA < 38) ss << "Origami Swarm";
				else if (rollA < 39) ss << "Alluring Golden Apple";
				else if (rollA < 40) ss << "Feather Token (Tree)";
				else if (rollA < 41) ss << "Key of Lock Jamming";
				else if (rollA < 43) ss << "Feather Token (Swan Boat)";
				else if (rollA < 44) ss << "Animated Portrait";
				else if (rollA < 45) ss << "Bottled Misfortune";
				else if (rollA < 47) ss << "Elixir of Truth";
				else if (rollA < 49) ss << "Feather Token (Whip)";
				else if (rollA < 52) ss << "Scabbard of Honing";
				else if (rollA < 54) ss << "Seer's Tea";
				else if (rollA < 58) ss << "Abjurant Salt";
				else if (rollA < 62) ss << "Arrow Magnet";
				else if (rollA < 64) ss << "Dust of Darkness";
				else if (rollA < 70) ss << "Campfire Bead";
				else if (rollA < 73) ss << "Archon's Torch";
				else if (rollA < 76) ss << "Book of Extended Summoning, Lesser";
				else if (rollA < 80) ss << "Iron Rope";
				else if (rollA < 84) ss << "Snapleaf";
				else if (rollA < 87) ss << "Bottled Yeti Fur";
				else if (rollA < 90) ss << "Defoliant Polish";
				else if (rollA < 93) ss << "Dust of Emulation";
				else if (rollA < 98) ss << "Steadfast Gut-Stone";
				else if (rollA < 101) ss << "Dust of Dryness";
				else std::cout << "Error Code 3709\n";
				break;
			case 1:
				if (rollA < 4) ss << wGen(0);
				else if (rollA < 5) ss << "Anatomy Doll";
				else if (rollA < 6) ss << "Bead of Newt Prevention";
				else if (rollA < 7) ss << "Beast-Bond Brand";
				else if (rollA < 8) ss << "Bookplate of Recall";
				else if (rollA < 10) ss << "Boro Bead (1st)";
				else if (rollA < 11) ss << "Concealing Pocket";
				else if (rollA < 12) ss << "Dowsing Syrup";
				else if (rollA < 13) ss << "Incense of Transcendence";
				else if (rollA < 15) ss << "Page of Spell Knowledge (1st)";
				else if (rollA < 18) ss << "Pearl of Power (1st)";
				else if (rollA < 19) ss << "Preserving Flask (1st)";
				else if (rollA < 21) ss << "Pyxes of Redirected Focus";
				else if (rollA < 23) ss << "Salve of Slipperiness";
				else if (rollA < 24) ss << "Wasp Nest of Swarming";
				else if (rollA < 27) ss << "Elixir of Fire Breath";
				else if (rollA < 28) ss << "Grave Salt";
				else if (rollA < 30) ss << "Pipes of the Sewers";
				else if (rollA < 32) ss << "Dust of Illusion";
				else if (rollA < 34) ss << "Goblin Skull Bomb";
				else if (rollA < 36) ss << "Elixir of Dragon Breath";
				else if (rollA < 37) ss << "Bookmark of Deception";
				else if (rollA < 38) ss << "Word Bottle";
				else if (rollA < 39) ss << "Dust of Acid Consumption";
				else if (rollA < 41) ss << "Dust of Appearance";
				else if (rollA < 43) ss << "Efficient Quiver";
				else if (rollA < 44) ss << "Pipes of Sounding";
				else if (rollA < 45) ss << "Scabbard of Vigor";
				else if (rollA < 46) ss << "Agile Alpenstock";
				else if (rollA < 47) ss << "Blood Reservoir of Physical Prowess";
				else if (rollA < 48) ss << "Clamor Box";
				else if (rollA < 49) ss << "Dry Load Powder Horn";
				else if (rollA < 50) ss << "Goblin Fire Drum";
				else if (rollA < 52) ss << "Handy Haversack";
				else if (rollA < 54) ss << "Horn of Fog";
				else if (rollA < 55) ss << "Iron Spike of Safe Passage";
				else if (rollA < 56) ss << "Knight's Pennon, Honor";
				else if (rollA < 60) ss << "Volatile Vaporizer (1st)";
				else if (rollA < 63) ss << "Elemental Gem";
				else if (rollA < 65) ss << "Flying Ointment";
				else if (rollA < 66) ss << "Sovereign Glue";
				else if (rollA < 67) ss << "Apple of Eternal Sleep";
				else if (rollA < 69) ss << "Bag of Holding (Type 1)";
				else if (rollA < 70) ss << "Candle of Truth";
				else if (rollA < 71) ss << "Hexing Doll";
				else if (rollA < 73) ss << "Stone of Alarm";
				else if (rollA < 74) ss << "Book of Extended Summoning, Standard";
				else if (rollA < 78) ss << "Bead of Force";
				else if (rollA < 79) ss << "Cauldron of Brewing";
				else if (rollA < 81) ss << "Chime of Opening";
				else if (rollA < 82) ss << "Philter of Love";
				else if (rollA < 87) ss << "Rope of Climbing";
				else if (rollA < 89) ss << "Volatile Vaporizer (2nd)";
				else if (rollA < 90) ss << "Shroud of Disintegration";
				else if (rollA < 93) ss << "Bag of Tricks, Gray";
				else if (rollA < 96) ss << "Dust of Disappearance";
				else if (rollA < 97) ss << "Dust of Weighty Burdens";
				else if (rollA < 98) ss << "Noble's Vigilant Pillbox";
				else if (rollA < 100) ss << "Figurine of Wondrous Power (Silver Raven)";
				else if (rollA < 101) ss << "Volatile Vaporizer (3rd)";
				else std::cout << "Error Code 3772\n";
				break;
			case 2:
				if (rollA < 2) ss << "Boro Bead (2nd)";
				else if (rollA < 3) ss << "Cautionary Creance";
				else if (rollA < 4) ss << "Escape Ladder";
				else if (rollA < 5) ss << "Far-Reaching Sight";
				else if (rollA < 7) ss << "Ioun Stone (Clear Spindle)";
				else if (rollA < 8) ss << "Marvelous Pigments";
				else if (rollA < 16) ss << "Page of Spell Knowledge (2nd)";
				else if (rollA < 26) ss << "Pearl of Power (2nd)";
				else if (rollA < 27) ss << "Preserving Flask (2nd)";
				else if (rollA < 28) ss << "Restorative Ointment";
				else if (rollA < 31) ss << "Stone Salve";
				else if (rollA < 32) ss << "Wind-Caller Compass";
				else if (rollA < 33) ss << "Goblin Fire Drum, Greater";
				else if (rollA < 34) ss << "Knight's Pennon, Battle";
				else if (rollA < 35) ss << "Knight's Pennon, Parley";
				else if (rollA < 36) ss << "Void Dust";
				else if (rollA < 37) ss << "Incense of Meditation";
				else if (rollA < 38) ss << "Admixture Vial";
				else if (rollA < 52) ss << "Bag of Holding (Type 2)";
				else if (rollA < 53) ss << "Bone Razor";
				else if (rollA < 54) ss << "Horn of the Huntmaster";
				else if (rollA < 55) ss << "Insistent Doorknocker";
				else if (rollA < 57) ss << "Ioun Stone (Dusty Rose Prism)";
				else if (rollA < 58) ss << "Mallet of Building";
				else if (rollA < 59) ss << "Polymorphic Pouch";
				else if (rollA < 60) ss << "Scabbard of Stanching";
				else if (rollA < 61) ss << "School of Eyes";
				else if (rollA < 62) ss << "Sheath of Bladestealth";
				else if (rollA < 63) ss << "Stone of Alliance";
				else if (rollA < 64) ss << "Summoning Shackle";
				else if (rollA < 65) ss << "Eversmoking Bottle";
				else if (rollA < 66) ss << "Sustaining Spoon";
				else if (rollA < 67) ss << "Wind Fan";
				else if (rollA < 68) ss << "Grim Lantern";
				else if (rollA < 69) ss << "Coin of the Untrodden Road";
				else if (rollA < 70) ss << "Horn of Battle Clarity";
				else if (rollA < 71) ss << "Life Link Badge";
				else if (rollA < 72) ss << "Martyr's Tear";
				else if (rollA < 73) ss << "Pipes of Haunting";
				else if (rollA < 74) ss << "Rope of Knots";
				else if (rollA < 75) ss << "Singing Bell of Striking";
				else if (rollA < 76) ss << "Stone Familiar";
				else if (rollA < 77) ss << "Book of Extended Summoning, Greater";
				else if (rollA < 78) ss << "Dragonbone Divination Sticks";
				else if (rollA < 79) ss << "Horn of Goodness/Evil";
				else if (rollA < 80) ss << "Naga-Scale Bindi";
				else if (rollA < 81) ss << "Bottle of Shadows";
				else if (rollA < 82) ss << "Cape of Bravado";
				else if (rollA < 84) ss << "Instant Bridge";
				else if (rollA < 85) ss << "Mirror of Guarding Reflections";
				else if (rollA < 86) ss << "Folding Boat";
				else if (rollA < 88) ss << "Bottle of Air";
				else if (rollA < 95) ss << "Bag of Holding (Type 3)";
				else if (rollA < 96) ss << "Balm of Impish Grace";
				else if (rollA < 97) ss << "Candle of Clean Air";
				else if (rollA < 98) ss << "Harp of Charming";
				else if (rollA < 101) ss << "Manual of War";
				else std::cout << "Error Code 3832\n";
				break;
			case 3:
				if (rollA < 2) ss << "Chalice of Poison Weeping";
				else if (rollA < 3) ss << "Exorcist's Aspergillum";
				else if (rollA < 4) ss << "Golem Manual, Flesh";
				else if (rollA < 5) ss << "Harp of Shattering";
				else if (rollA < 6) ss << "Insignia of Valor, Deep Red Sphere";
				else if (rollA < 7) ss << "Ioun Stone";
				else if (rollA < 8) ss << "Ioun Stone (Incandescent Blue Sphere";
				else if (rollA < 9) ss << "Ioun Stone (Pale Blue Rhomboid)";
				else if (rollA < 10) ss << "Ioun Stone (Pink and Green Sphere)";
				else if (rollA < 11) ss << "Ioun Stone (Pink Rhomboid)";
				else if (rollA < 12) ss << "Ioun Stone (Scarlet and Blue Sphere)";
				else if (rollA < 13) ss << "Needles of Fleshgraving";
				else if (rollA < 14) ss << "Restless Lockpicks";
				else if (rollA < 15) ss << "Werewhistle";
				else if (rollA < 17) ss << "Deck of Illusions";
				else if (rollA < 18) ss << "Candle of Invocation";
				else if (rollA < 20) ss << "Bag of Tricks, Rust";
				else if (rollA < 21) ss << "Boro Bead (3rd)";
				else if (rollA < 22) ss << "Decanter of Endless Water";
				else if (rollA < 23) ss << "Loathsome Mirror";
				else if (rollA < 26) ss << "Page of Spell Knowledge (3rd)";
				else if (rollA < 32) ss << "Pearl of Power (3rd)";
				else if (rollA < 33) ss << "Preserving Flask (3rd)";
				else if (rollA < 34) ss << "Figurine of Wondrous Power (Serpentine Owl)";
				else if (rollA < 35) ss << "Strand of Prayer Beads, Lesser";
				else if (rollA < 39) ss << "Bag of Holding (Type 4)";
				else if (rollA < 40) ss << "Boundary Chalk";
				else if (rollA < 41) ss << "Chime of Resounding Silence";
				else if (rollA < 42) ss << "Construct Channel Brick";
				else if (rollA < 43) ss << "Doomharp";
				else if (rollA < 44) ss << "Drum of Advance and Retreat";
				else if (rollA < 45) ss << "Embalming Thread";
				else if (rollA < 46) ss << "Eye of the Void";
				else if (rollA < 47) ss << "Figurine of Wondrous Power (Bronze Griffon)";
				else if (rollA < 48) ss << "Figurine of Wondrous Power (Ebony Fly)";
				else if (rollA < 49) ss << "Figurine of Wondrous Power (Slate Spider)";
				else if (rollA < 50) ss << "Hourglass of Last Chances";
				else if (rollA < 52) ss << "Ioun Stone (Dark BLue Rhomboid)";
				else if (rollA < 53) ss << "Ki Mat";
				else if (rollA < 54) ss << "Lord's Banner, Swiftness";
				else if (rollA < 55) ss << "Malleable Symbol";
				else if (rollA < 56) ss << "Migrus Locker";
				else if (rollA < 57) ss << "Ornament of Healing Light";
				else if (rollA < 58) ss << "Prayer Wheel of Ethical Strength";
				else if (rollA < 59) ss << "Stone Horse, Courser";
				else if (rollA < 60) ss << "Summon-Slave Crystal";
				else if (rollA < 61) ss << "Treasurer's Seal";
				else if (rollA < 62) ss << "Black Soul Shard";
				else if (rollA < 63) ss << "Golem Manual, Clay";
				else if (rollA < 64) ss << "Horsemaster's Saddle";
				else if (rollA < 65) ss << "Pipes of Dissolution";
				else if (rollA < 66) ss << "Pipes of Pain";
				else if (rollA < 67) ss << "Seeker's Sight";
				else if (rollA < 68) ss << "Blessed Book";
				else if (rollA < 69) ss << "Waters of Transfiguration";
				else if (rollA < 70) ss << "Gem of Brightness";
				else if (rollA < 71) ss << "Harp of Contagion";
				else if (rollA < 72) ss << "Lyre of Building";
				else if (rollA < 73) ss << "Void Pennant";
				else if (rollA < 74) ss << "Stone Horse, Destrier";
				else if (rollA < 75) ss << "Book of the Loremaster";
				else if (rollA < 76) ss << "Cauldron of Plenty";
				else if (rollA < 77) ss << "Horn of Judgment";
				else if (rollA < 78) ss << "Horn of the Tritons";
				else if (rollA < 79) ss << "Pearl of the Sirines";
				else if (rollA < 80) ss << "Figurine of Wondrous Power (Onyx Dog)";
				else if (rollA < 82) ss << "Bag of Tricks, Tan";
				else if (rollA < 83) ss << "Boro Bead (4th)";
				else if (rollA < 84) ss << "Page of Spell Knowledge (4th)";
				else if (rollA < 88) ss << "Pearl of Power (4th)";
				else if (rollA < 89) ss << "Preserving Flask (4th)";
				else if (rollA < 92) ss << "Scabbard of Keen Edges";
				else if (rollA < 94) ss << "Figurine of Wondrous Power (Golden Lions)";
				else if (rollA < 96) ss << "Chime of Interruption";
				else if (rollA < 100) ss << "Broom of Flying";
				else if (rollA < 101) ss << "Figurine of Wondrous Power (Marble Elephant)";
				else std::cout << "Error Code 3911\n";
				break;
			case 4:
				if (rollA < 4) ss << "Ioun Stone (Iridescent Spindle)";
				else if (rollA < 5) ss << "Orb of Foul Abaddon";
				else if (rollA < 9) ss << "Carpet of Flying (5ft. by 5ft.)";
				else if (rollA < 10) ss << "Horn of Antagonism";
				else if (rollA < 14) ss << "Horn of Blasting";
				else if (rollA < 18) ss << "Ioun Stone (Pale Lavender Ellipsoid)";
				else if (rollA < 22) ss << "Ioun Stone (Pearly White Spindle)";
				else if (rollA < 25) ss << "Master's Perfect Golden Bell";
				else if (rollA < 28) ss << "Necromancer's Athame";
				else if (rollA < 32) ss << "Portable Hole";
				else if (rollA < 36) ss << "Stone of Good Luck";
				else if (rollA < 38) ss << "Figurine of Wondrous Power (Ivory Goats)";
				else if (rollA < 41) ss << "Rope of Entanglement";
				else if (rollA < 43) ss << "Golem Manual, Stone";
				else if (rollA < 44) ss << "Orb of Golden Heaven";
				else if (rollA < 46) ss << "Mattock of the Titans";
				else if (rollA < 49) ss << "Drinking Horn of Bottomless Valor";
				else if (rollA < 52) ss << "Boro Bead (5th)";
				else if (rollA < 54) ss << "Chaos Emerald";
				else if (rollA < 58) ss << "Page of Spell Knowledge (5th)";
				else if (rollA < 65) ss << "Pearl of Power (5th)";
				else if (rollA < 68) ss << "Preserving Flask (5th)";
				else if (rollA < 70) ss << "Maul of the Titans";
				else if (rollA < 74) ss << "Iron Bands of Binding";
				else if (rollA < 77) ss << "Cube of Frost Resistance";
				else if (rollA < 81) ss << "Manual of Bodily Health +1";
				else if (rollA < 85) ss << "Manual of Gainful Excercise +1";
				else if (rollA < 89) ss << "Maunal of Quickness of Action +1";
				else if (rollA < 93) ss << "Tome of Clear Thought +1";
				else if (rollA < 97) ss << "Tome of Leadership and Influence +1";
				else if (rollA < 101) ss << "Tome of Understanding +1";
				else std::cout << "Error Code 3945\n";
				break;
			case 5:
				if (rollA < 5) ss << "Figurine of Wondrous Power (Obsidian Steed)";
				else if (rollA < 8) ss << "Cauldron of the Dead";
				else if (rollA < 12) ss << "Drums of Panic";
				else if (rollA < 16) ss << "Ioun Stone (Orange Prism)";
				else if (rollA < 20) ss << "Ioun Stone (Pale Green Prism)";
				else if (rollA < 24) ss << "Lantern of Revealing";
				else if (rollA < 28) ss << "Racing Broom of Flying";
				else if (rollA < 32) ss << "Cauldron of Resurrection";
				else if (rollA < 37) ss << "Carpet of Flying (5 ft. by 10 ft.)";
				else if (rollA < 39) ss << "Golem Manual, Iron";
				else if (rollA < 41) ss << "Boro Bead (6th)";
				else if (rollA < 45) ss << "Ioun Stone (Vibrant Purple Prism)";
				else if (rollA < 49) ss << "Orb of Utter Chaos";
				else if (rollA < 51) ss << "Page of Spell Knowledge (6th)";
				else if (rollA < 59) ss << "Pearl of Power (6th)";
				else if (rollA < 61) ss << "Preserving Flask (6th)";
				else if (rollA < 65) ss << "Cauldron of Flying";
				else if (rollA < 67) ss << "Enmity Fetish";
				else if (rollA < 70) ss << "Ioun Stone (Lavender and Green Ellipsoid)";
				else if (rollA < 74) ss << "Ring Gates";
				else if (rollA < 78) ss << "Cauldron of Seeing";
				else if (rollA < 82) ss << "Crystal Ball";
				else if (rollA < 84) ss << "Golem Manual, Stone Guardian";
				else if (rollA < 88) ss << "Drums of Haste";
				else if (rollA < 92) ss << "Strand of Prayer Beads, Standard";
				else if (rollA < 95) ss << "Orb of Storms";
				else if (rollA < 97) ss << "Page of Spell Knowledge (7th)";
				else if (rollA < 101) ss << "Pearl of Power (7th)";
				else std::cout << "Error Code 3976\n";
				break;
			case 6:
				if (rollA < 4) ss << "Crystal Ball with See Invisibility";
				else if (rollA < 6) ss << "Horn of Valhalla";
				else if (rollA < 9) ss << "Crystal Ball with Detect Thoughts";
				else if (rollA < 10) ss << "Last Leaves of the Autumn Dryad";
				else if (rollA < 12) ss << "Instant Fortress";
				else if (rollA < 16) ss << "Manual of Bodily Health +2";
				else if (rollA < 20) ss << "Manual of Gainful Excercise +2";
				else if (rollA < 24) ss << "Manual of Quickness of Action +2";
				else if (rollA < 28) ss << "Tome of Clear Thought +2";
				else if (rollA < 32) ss << "Tome of Leadership and Influence +2";
				else if (rollA < 36) ss << "Tome of Understanding +2";
				else if (rollA < 37) ss << "Lord's Banner, Terror";
				else if (rollA < 38) ss << "Carpet of Flying (10 ft. by 10 ft.)";
				else if (rollA < 40) ss << "Darkskull";
				else if (rollA < 41) ss << "Orb of Pure Law";
				else if (rollA < 42) ss << "Cube of Force";
				else if (rollA < 44) ss << "Page of Spell Knowledge (8th)";
				else if (rollA < 50) ss << "Pearl of Power (8th)";
				else if (rollA < 51) ss << "Crystal Ball with Telepathy";
				else if (rollA < 52) ss << "Horn of Blasting, Greater";
				else if (rollA < 55) ss << "Pearl of Power (Two Spells)";
				else if (rollA < 56) ss << "Gem of Seeing";
				else if (rollA < 57) ss << "Lord's Banner, Victory";
				else if (rollA < 58) ss << "Crystal Ball with True Seeing";
				else if (rollA < 60) ss << "Page of Spell Knowledge (9th)";
				else if (rollA < 63) ss << "Pearl of Power (9th)";
				else if (rollA < 64) ss << "Well of Many Worlds";
				else if (rollA < 66) ss << "Manual of Bodily Health +3";
				else if (rollA < 68) ss << "Manual of Gainful Excercise +3";
				else if (rollA < 70) ss << "Maunal of Quickness of Action +3";
				else if (rollA < 72) ss << "Tome of Clear Thought +3";
				else if (rollA < 74) ss << "Tome of Leadership and Influence +3";
				else if (rollA < 76) ss << "Tome of Understanding +3";
				else if (rollA < 77) ss << "Apparatus of the Crab";
				else if (rollA < 78) ss << "Bowl of Conjuring Water Elementals";
				else if (rollA < 79) ss << "Bowl of Conjuring Fire Elementals";
				else if (rollA < 80) ss << "Bowl of Conjuring Air Elementals";
				else if (rollA < 81) ss << "Bowl of Conjuring Earth Elementals";
				else if (rollA < 82) ss << "Mirror of Opposition";
				else if (rollA < 83) ss << "Strand of Prayer Beads, Greater";
				else if (rollA < 84) ss << "Lord's Banner, Crusades";
				else if (rollA < 85) ss << "Manual of Bodily Health +4";
				else if (rollA < 86) ss << "Manual of Gainful Excercise +4";
				else if (rollA < 87) ss << "Manual of Quickness of Action +4";
				else if (rollA < 88) ss << "Tome of Clear Thought +4";
				else if (rollA < 89) ss << "Tome of Leadership and Influence +4";
				else if (rollA < 90) ss << "Tome of Understanding +4";
				else if (rollA < 91) ss << "Manual of Bodily Health +5";
				else if (rollA < 92) ss << "Manual of Gainful Excercise +5";
				else if (rollA < 93) ss << "Manual of Quickness of Action +5";
				else if (rollA < 94) ss << "Tome of Clear Thought +5";
				else if (rollA < 95) ss << "Tome of Leadership and Influence +5";
				else if (rollA < 96) ss << "Tome of Understanding +5";
				else if (rollA < 97) ss << "Efreeti Bottle";
				else if (rollA < 98) ss << "Cubic Gate";
				else if (rollA < 99) ss << "Iron Flask";
				else if (rollA < 100) ss << "Mirror of Mental Prowess";
				else if (rollA < 101) ss << "Mirror of Life Trapping";
				else std::cout << "Error Code 4037\n";
				break;
			default:
				std::cout << "Error Code 4040\n";
				break;
			}
		else
			std::cout << "Error Code 4044\n";
		ss << std::endl;
	}
	return ss.str();
}
std::string staffGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int rollA = roll(1, 100);
		switch (subtype)
		{
		case 3:
			if (rollA < 11) ss << "Staff of Blessed Relief";
			else if (rollA < 21) ss << "Staff of Minor Arcana";
			else if (rollA < 31) ss << "Staff of Tricks";
			else if (rollA < 45) ss << "Staff of the Scout";
			else if (rollA < 55) ss << "Staff of Eidolons";
			else if (rollA < 68) ss << "Staff of Accompaniment";
			else if (rollA < 85) ss << "Staff of Understanding";
			else if (rollA < 101) ss << "Staff of Charming";
			else std::cout << "Error Code 4066\n";
			break;
		case 4:
			if (rollA < 12) ss << "Staff of Fire";
			else if (rollA < 22) ss << "Staff of Courage";
			else if (rollA < 30) ss << "Staff of Belittling";
			else if (rollA < 39) ss << "Staff of Feast and Famine";
			else if (rollA < 50) ss << "Staff of Rigor";
			else if (rollA < 61) ss << "Staff of Swarming Insects";
			else if (rollA < 69) ss << "Staff of Authority";
			else if (rollA < 82) ss << "Staff of Radiance";
			else if (rollA < 93) ss << "Staff of Size Alteration";
			else if (rollA < 101) ss << "Staff of Journeys";
			else std::cout << "Error Code 4079\n";
			break;
		case 5:
			if (rollA < 5) ss << "Staff of Acid";
			else if (rollA < 9) ss << "Staff of Shrieking";
			else if (rollA < 12) ss << "Chaotic Staff";
			else if (rollA < 15) ss << "Holy Staff";
			else if (rollA < 18) ss << "Lawful Staff";
			else if (rollA < 22) ss << "Staff of Healing";
			else if (rollA < 25) ss << "Unholy Staff";
			else if (rollA < 29) ss << "Staff of the Master (Necromancy)";
			else if (rollA < 33) ss << "Staff of Spiders";
			else if (rollA < 37) ss << "Staff of Electricity";
			else if (rollA < 40) ss << "Heretic's Bane";
			else if (rollA < 43) ss << "Musical Staff";
			else if (rollA < 47) ss << "Staff of Souls";
			else if (rollA < 51) ss << "Staff of Toxins";
			else if (rollA < 55) ss << "Staff of Stealth";
			else if (rollA < 59) ss << "Staff of the Avenger";
			else if (rollA < 63) ss << "Staff of Aspects";
			else if (rollA < 67) ss << "Staff of Speaking";
			else if (rollA < 71) ss << "Staff of Frost";
			else if (rollA < 75) ss << "Staff of Bostering";
			else if (rollA < 79) ss << "Staff of Curses";
			else if (rollA < 86) ss << "Staff of Dark Flame";
			else if (rollA < 90) ss << "Staff of Cackling Wrath";
			else if (rollA < 94) ss << "Staff of Performance";
			else if (rollA < 98) ss << "Animate Staff";
			else if (rollA < 101) ss << "Staff of Revelations";
			else std::cout << "Error Code 4108\n";
			break;
		case 6:
			if (rollA < 5) ss << "Staff of Illumination";
			else if (rollA < 8) ss << "Staff of Obstacles";
			else if (rollA < 11) ss << "Staff of Heaven and Earth";
			else if (rollA < 14) ss << "Staff of Travel";
			else if (rollA < 17) ss << "Staff of Hoarding";
			else if (rollA < 20) ss << "Staff of Traps";
			else if (rollA < 23) ss << "Staff of Many Rays";
			else if (rollA < 26) ss << "Staff of Mithral Might";
			else if (rollA < 30) ss << "Staff of Defense";
			else if (rollA < 33) ss << "Staff of the Planes";
			else if (rollA < 36) ss << "Staff of Hungry Shadows";
			else if (rollA < 39) ss << "Dragon Staff";
			else if (rollA < 42) ss << "Staff of Slumber";
			else if (rollA < 47) ss << "Staff of Abjuration";
			else if (rollA < 52) ss << "Staff of Conjuration";
			else if (rollA < 57) ss << "Staff of Divination";
			else if (rollA < 62) ss << "Staff of Enchantment";
			else if (rollA < 67) ss << "Staff of Evocation";
			else if (rollA < 72) ss << "Staff of Illusion";
			else if (rollA < 77) ss << "Staff of Necromancy";
			else if (rollA < 82) ss << "Staff of Transmutation";
			else if (rollA < 84) ss << "Staff of Weather";
			else if (rollA < 87) ss << "Staff of Earth and Stone";
			else if (rollA < 89) ss << "Staff of Vision";
			else if (rollA < 92) ss << "Staff of the Woddlnads";
			else if (rollA < 95) ss << "Staff of Life";
			else if (rollA < 96) ss << "Staff of One Hundred Hands";
			else if (rollA < 99) ss << "Staff of Passage";
			else if (rollA < 100) ss << "Staff of the Hierophant";
			else if (rollA < 101) ss << "Staff of Power";
			else std::cout << "Error Code 4141\n";
			break;
		default:
			break;
		}
		ss << std::endl;
	}
	return ss.str();
}
std::string mGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int rollA = roll(1, 100);
		switch (subtype)
		{
		case 1:
			if (rollA < 5) ss << "Bouncing";
			else if (rollA < 10) ss << "Disruptive";
			else if (rollA < 15) ss << "Ectoplasmic";
			else if (rollA < 20) ss << "Elemental";
			else if (rollA < 32) ss << "Enlarge";
			else if (rollA < 44) ss << "Extend";
			else if (rollA < 49) ss << "Flaring";
			else if (rollA < 54) ss << "Focused";
			else if (rollA < 59) ss << "Intensified";
			else if (rollA < 64) ss << "Lingering";
			else if (rollA < 69) ss << "Piercing";
			else if (rollA < 74) ss << "Reach";
			else if (rollA < 79) ss << "Rime";
			else if (rollA < 84) ss << "Selective";
			else if (rollA < 96) ss << "Silent";
			else if (rollA < 101) ss << "Toppling";
			else std::cout << "Error Code 4175\n";
			break;
		case 2:
			if (rollA < 12) ss << "Burning";
			else if (rollA < 23) ss << "Concussive";
			else if (rollA < 41) ss << "Empower";
			else if (rollA < 52) ss << "Persistent";
			else if (rollA < 63) ss << "Sickening";
			else if (rollA < 76) ss << "Thanatopic";
			else if (rollA < 89) ss << "Threnodic";
			else if (rollA < 101) ss << "Thundering";
			else std::cout << "Error Code 4186\n";
			break;
		case 3:
			if (rollA < 21) ss << "Dazing";
			else if (rollA < 41) ss << "Echoing";
			else if (rollA < 71) ss << "Maximize";
			else if (rollA < 101) ss << "Widen";
			else std::cout << "Error Code 4193\n";
			break;
		default:
			break;
		}
		ss << std::endl;
	}
	return ss.str();
}
std::string rodGen(int subtype, int multiple = 1)
{
	std::stringstream ss;
	for (int i = 0; i < multiple; i++)
	{
		int rollA = roll(1, 100);
		switch (subtype)
		{
		case 3:
			if (rollA < 2) ss << "Merciful Metamagic Rod, Lesser";
			else if (rollA < 35) ss << "+1 Spell Level, " + mGen(1) + " Metamagic Rod, Minor";
			else if (rollA < 50) ss << "Immovable Rod";
			else if (rollA < 60) ss << "Rod of Thunderous Force";
			else if (rollA < 61) ss << "Merciful Metamagic Rod, Normal";
			else if (rollA < 62) ss << "Rod of Ice";
			else if (rollA < 72) ss << "+2 Spell Level, " + mGen(2) + " Metamagic Rod, Minor";
			else if (rollA < 82) ss << "Rod of Metal and Mineral Detection";
			else if (rollA < 87) ss << "+1 Spell Level, " + mGen(1) + " Metamagic Rod, Normal";
			else if (rollA < 101) ss << "Rod of Cancellation";
			else std::cout << "Error Code 4221\n";
			break;
		case 4:
			if (rollA < 4) ss << "Conduit Rod";
			else if (rollA < 7) ss << "Grounding Rod";
			else if (rollA < 11) ss << "Rod of the Wayang";
			else if (rollA < 19) ss << "Rod of Wonder";
			else if (rollA < 20) ss << "Merciful Metamagic Rod, Greater";
			else if (rollA < 30) ss << "Rod of the Python";
			else if (rollA < 34) ss << "Trap-Stealer's Rod";
			else if (rollA < 56) ss << "+3 Spell Level, " + mGen(3) + " Metamagic Rod, Minor";
			else if (rollA < 60) ss << "Rod of Balance";
			else if (rollA < 64) ss << "Rod of Escape";
			else if (rollA < 73) ss << "Rod of Flame Extinguishing";
			else if (rollA < 77) ss << "Rod of Ruin";
			else if (rollA < 81) ss << "Sapling Rod";
			else if (rollA < 87) ss << "Rod of Beguiling";
			else if (rollA < 91) ss << "Rod of Nettles";
			else if (rollA < 101) ss << "Rod of the Viper";
			else std::cout << "Error Code 4240\n";
			break;
		case 5:
			if (rollA < 5) ss << "Suzerain Scepter";
			else if (rollA < 7) ss << "Fiery Nimbus Rod";
			else if (rollA < 14) ss << "Rod of Enemy Detection";
			else if (rollA < 28) ss << "+1 Spell Level, " + mGen(1) + " Metamagic Rod, Greater";
			else if (rollA < 37) ss << "Rod of Splendor";
			else if (rollA < 45) ss << "Rod of Withering";
			else if (rollA < 51) ss << "Earthbind Rod";
			else if (rollA < 57) ss << "Rod of the Aboleth";
			else if (rollA < 64) ss << "Liberator's Rod";
			else if (rollA < 71) ss << "+2 Spell Level, " + mGen(2) + " Metamagic Rod, Normal";
			else if (rollA < 80) ss << "Rod of Thunder and Lightning";
			else if (rollA < 84) ss << "Quicken Metamagic Rod, Minor";
			else if (rollA < 95) ss << "Rod of Negation";
			else if (rollA < 101) ss << "Rod of Steadfast Resolve";
			else std::cout << "Error Code 4257\n";
			break;
		case 6:
			if (rollA < 9) ss << "Rod of Absorption";
			else if (rollA < 12) ss << "Rod of Flailing";
			else if (rollA < 27) ss << "+3 Spell Level, " + mGen(3) + " Metamagic Rod, Normal";
			else if (rollA < 29) ss << "Rod of Rulership";
			else if (rollA < 31) ss << "Rod of Security";
			else if (rollA < 33) ss << "Rod of Shadows";
			else if (rollA < 35) ss << "Rod of Mind Mastery";
			else if (rollA < 38) ss << "Rod of Lordly Might";
			else if (rollA < 58) ss << "+2 Spell Level, " + mGen(2) + " Metamagic Rod, Greater";
			else if (rollA < 59) ss << "Scepter of Heaven";
			else if (rollA < 69) ss << "Quicken Metamagic Rod, Normal";
			else if (rollA < 71) ss << "Rod of Dwarven Might";
			else if (rollA < 76) ss << "Rod of Alertness";
			else if (rollA < 96) ss << "+3 Spell Level, " + mGen(3) + " Metamagic Rod, Greater";
			else if (rollA < 101) ss << "Quicken Metamagic Rod, Greater";
			else std::cout << "Error Code 4275\n";
			break;
		default:
			std::cout << "Error Code 4278\n";
			break;
		}
		ss << std::endl;
	}
	return ss.str();
}

void toText(std::string ss, std::string head)
{
	std::ofstream ofs("Loot Output.txt", std::ofstream::app);
	ofs << head << ss << "- - - - - - - - - - - - - - - - - - - -\n\n";
	ofs.close();
	cls();
	std::cout << "Save Success\n\n";
}
int genFirst(int type, double value, std::string head)
{
	std::stringstream ss;
	std::vector<int> types[] = {
		{ 1,5,10,25,50,100,200,500,1000,5000,10000,50000 }, // 12
		{ 10,15,25,50,75,100,150,200,250,500,750,1000,2500,5000,10000,20000,50000 }, // 17
		{ 50,100,150,200,250,500,750,1000,1500,2000,2500,5000,7500,10000,15000,20000,50000 }, // 17
		{ 50,100,150,200,250,300,400,500,750,1000,1500,2000,3000,4000,5000,7500,10000,15000,20000,25000,30000,50000 }, // 22
		{ 200,300,350,1000,1500,2500,3000,4000,5500,6000,7500,8000,9000,10000,13000,15000,20000,25000,30000,35000,40000,50000,75000,100000 }, // 24
		{ 50,250,350,400,500,750,1000,1500,2000,3000,4000,5000,6000,7500,10000,12500,15000,20000,25000,30000,40000,50000,60000,75000,100000 }, // 25
		{ 50,75,100,150,200,250,500,750,1000,1500,2000,2500,3000,4000,5000,6000,7500,10000,12500,15000,20000,25000,30000,40000,50000,60000,75000,100000 }, // 28
		{ 500,1000,2500,5000,7500,10000,15000,20000,25000,30000,40000,50000,75000,100000 }, // 14
		{ 5000,10000,15000,20000,25000,30000,40000,50000,60000,75000,100000,125000,150000,200000,300000 } }; // 15

	if (type == 1)
		switch (lootValue(types[0], value))
		{
		case -1: std::cout << "Too sm0l value for this encounter type\nTry again with a less valuable type\n"; break;
		case 0: ss << coinGen(5, 10, 1) << std::endl << coinGen(3, 4, 2) << std::endl; break;
		case 1: ss << coinGen(2, 6, 1, 10) << std::endl << coinGen(4, 8, 2) << std::endl << coinGen(1, 4, 3) << std::endl; break;
		case 2: ss << coinGen(5, 10, 1, 10) << std::endl << coinGen(5, 10, 2) << std::endl << coinGen(1, 8, 3) << std::endl; break;
		case 3: ss << coinGen(2, 4, 1, 100) << std::endl << coinGen(3, 6, 2, 10) << std::endl << coinGen(4, 4, 3) << std::endl;	break;
		case 4: ss << coinGen(4, 4, 1, 100) << std::endl << coinGen(4, 6, 2, 10) << std::endl << coinGen(8, 6, 3) << std::endl;	break;
		case 5: ss << coinGen(6, 8, 2, 10) << std::endl << coinGen(3, 4, 3, 10) << std::endl; break;
		case 6: ss << coinGen(2, 4, 2, 100) << std::endl << coinGen(4, 4, 3, 10) << std::endl << coinGen(2, 4, 4) << std::endl;	break;
		case 7: ss << coinGen(6, 6, 3, 10) << std::endl << coinGen(8, 6, 4) << std::endl; break;
		case 8: ss << coinGen(2, 4, 3, 100) << std::endl << coinGen(10, 10, 4) << std::endl; break;
		case 9: ss << coinGen(4, 8, 3, 100) << std::endl << coinGen(6, 10, 4, 10) << std::endl; break;
		case 10: ss << coinGen(2, 4, 3, 1000) << std::endl << coinGen(12, 8, 4, 10) << std::endl; break;
		case 11: ss << coinGen(2, 6, 3, 1000) << std::endl << coinGen(8, 10, 4, 100) << std::endl; break;
		default: std::cout << "Error Code 4324\n"; break;
		}
	else if (type == 2)
		switch (lootValue(types[1], value))
		{
		case -1: std::cout << "Too sm0l value for this encounter type\nTry again with a less valuable type\n"; break;
		case 0: ss << gemGen(1) << std::endl; break;
		case 1: ss << coinGen(2, 6, 1, 10) << std::endl << coinGen(4, 8, 2) << std::endl << coinGen(1, 4, 3) << std::endl << gemGen(1) << std::endl; break;
		case 2: ss << coinGen(5, 10, 2) << std::endl << coinGen(1, 4, 3) << std::endl << gemGen(2, 1) << std::endl; break;
		case 3: ss << coinGen(3, 6, 2, 10) << std::endl << coinGen(3, 6, 3) << std::endl << gemGen(3, 1) << std::endl; break;
		case 4: ss << coinGen(1, 4, 2, 10) << std::endl << coinGen(1, 4, 3) << std::endl << gemGen(2, 1) << std::endl << gemGen(2) << std::endl; break;
		case 5: ss << coinGen(3, 8, 2, 10) << std::endl << coinGen(4, 8, 3) << std::endl << gemGen(2, 1) << std::endl << gemGen(2) << std::endl; break;
		case 6: ss << gemGen(2) << std::endl << gemGen(3) << std::endl; break;
		case 7: ss << coinGen(3, 6, 2, 10) << std::endl << coinGen(2, 4, 3, 10) << std::endl << gemGen(4, 1) << std::endl << gemGen(3) << std::endl; break;
		case 8: ss << coinGen(2, 4, 3, 10) << std::endl << gemGen(2, 2) << std::endl << gemGen(3) << std::endl; break;
		case 9: ss << coinGen(2, 4, 3, 10) << std::endl << coinGen(2, 4, 4) << std::endl << gemGen(2, 2) << std::endl << gemGen(3, 3) << std::endl; break;
		case 10: ss << coinGen(2, 4, 3, 10) << std::endl << gemGen(2, 2) << std::endl << gemGen(3) << std::endl << gemGen(4) << std::endl; break;
		case 11: ss << coinGen(3, 6, 3, 10) << std::endl << coinGen(4, 4, 4) << std::endl << gemGen(3, 3) << std::endl << gemGen(4) << std::endl; break;
		case 12: ss << coinGen(2, 4, 3, 100) << std::endl << gemGen(2, 4) << std::endl << gemGen(5) << std::endl; break;
		case 13: ss << coinGen(2, 4, 3, 100) << std::endl << coinGen(2, 4, 4, 10) << std::endl << gemGen(2, 4) << std::endl << gemGen(3, 5) << std::endl; break;
		case 14: ss << gemGen(5, 5) << std::endl << gemGen(6) << std::endl; break;
		case 15: ss << coinGen(4, 8, 3, 100) << std::endl << coinGen(6, 10, 4, 10) << std::endl << gemGen(3, 6) << std::endl; break;
		case 16: ss << coinGen(4, 4, 4, 10) << std::endl << gemGen(10, 3) << std::endl << gemGen(4, 4) << std::endl << gemGen(6, 5) << std::endl << gemGen(8, 6) << std::endl; break;
		default: std::cout << "Error Code 4347\n"; break;
		}
	else if (type == 3)
		switch (lootValue(types[2], value))
		{
		case -1: std::cout << "Too sm0l value for this encounter type\nTry again with a less valuable type\n"; break;
		case 0: ss << artGen(1) << std::endl; break;
		case 1: ss << artGen(2, 1) << std::endl; break;
		case 2: ss << artGen(1) << std::endl << artGen(2) << std::endl; break;
		case 3: ss << artGen(2) << std::endl; break;
		case 4: ss << artGen(3, 1) << std::endl << artGen(2) << std::endl; break;
		case 5: ss << artGen(4, 1) << std::endl << artGen(3, 2) << std::endl; break;
		case 6: ss << artGen(3, 1) << std::endl << artGen(2, 2) << std::endl << artGen(3) << std::endl; break;
		case 7: ss << artGen(2, 3) << std::endl; break;
		case 8: ss << artGen(3) << std::endl << artGen(4) << std::endl; break;
		case 9: ss << artGen(2, 4) << std::endl; break;
		case 10: ss << artGen(5, 2) << std::endl << artGen(2, 3) << std::endl << artGen(4) << std::endl; break;
		case 11: ss << artGen(4, 3) << std::endl << artGen(2, 4) << std::endl << artGen(5) << std::endl; break;
		case 12: ss << artGen(3) << std::endl << artGen(2, 4) << std::endl << artGen(5) << std::endl; break;
		case 13: ss << artGen(5, 4) << std::endl << artGen(5) << std::endl; break;
		case 14: ss << artGen(5) << std::endl << artGen(6) << std::endl; break;
		case 15: ss << artGen(2, 5) << std::endl << artGen(6) << std::endl; break;
		case 16: ss << artGen(10, 3) << std::endl << artGen(5, 4) << std::endl << artGen(4, 5) << std::endl << artGen(2, 6) << std::endl; break;
		default: std::cout << "Error Code 4370\n"; break;
		}
	else if (type == 4)
		switch (lootValue(types[3], value))
		{
		case -1: std::cout << "Too sm0l value for this encounter type\nTry again with a less valuable type\n"; break;
		case 0: ss << coinGen(3, 6, 2, 10) << std::endl << coinGen(4, 4, 3) << std::endl << scrollGen(1) << std::endl; break;
		case 1: ss << coinGen(4, 6, 2, 10) << std::endl << coinGen(3, 10, 3) << std::endl << scrollGen(1) << std::endl << potGen(1) << std::endl; break;
		case 2: ss << coinGen(2, 4, 2, 10) << std::endl << coinGen(6, 6, 3) << std::endl << scrollGen(2) << std::endl; break;
		case 3: ss << coinGen(2, 4, 2, 10) << std::endl << coinGen(4, 6, 3) << std::endl << potGen(2) << std::endl << scrollGen(1) << std::endl; break;
		case 4: ss << coinGen(3, 6, 2, 10) << std::endl << coinGen(3, 6, 3) << std::endl << coinGen(1, 4, 4) << std::endl << potGen(2, 1) << std::endl << scrollGen(2) << std::endl; break;
		case 5: ss << coinGen(2, 4, 2, 10) << std::endl << coinGen(6, 6, 3) << std::endl << potGen(2) << std::endl << scrollGen(2) << std::endl; break;
		case 6: ss << potGen(2) << std::endl << scrollGen(2, 2) << std::endl; break;
		case 7: ss << coinGen(2, 4, 3, 10) << std::endl << coinGen(1, 4, 4) << std::endl << potGen(2, 2) << std::endl << scrollGen(2) << std::endl; break;
		case 8: ss << coinGen(7, 6, 3) << std::endl << scrollGen(2) << std::endl << wandGen(1) << std::endl; break;
		case 9: ss << coinGen(2, 4, 3, 10) << std::endl << coinGen(2, 4, 4) << std::endl << potGen(3) << std::endl << wandGen(1) << std::endl; break;
		case 10: ss << coinGen(4, 4, 3, 10) << std::endl << coinGen(3, 6, 4) << std::endl << potGen(4) << std::endl << scrollGen(4) << std::endl; break;
		case 11: ss << coinGen(2, 4, 3, 10) << std::endl << coinGen(2, 4, 4) << std::endl << potGen(3) << std::endl << scrollGen(2, 4) << std::endl; break;
		case 12: ss << coinGen(3, 6, 3, 10) << std::endl << coinGen(4, 4, 4) << std::endl << potGen(4) << std::endl << scrollGen(4) << std::endl << wandGen(2) << std::endl; break;
		case 13: ss << coinGen(3, 6, 3, 10) << std::endl << coinGen(4, 4, 4) << std::endl << scrollGen(4) << std::endl << wandGen(2, 2) << std::endl; break;
		case 14: ss << coinGen(2, 4, 3, 10) << std::endl << coinGen(2, 4, 4) << std::endl << potGen(3, 3) << std::endl << scrollGen(2, 4) << std::endl << wandGen(2) << std::endl; break;
		case 15: ss << coinGen(5, 6, 4) << std::endl << potGen(2, 6) << std::endl << scrollGen(2, 6) << std::endl; break;
		case 16: ss << coinGen(4, 6, 4) << std::endl << potGen(6) << std::endl << scrollGen(6) << std::endl << wandGen(3) << std::endl; break;
		case 17: ss << coinGen(9, 10, 4) << std::endl << potGen(3, 6) << std::endl << scrollGen(2, 5) << std::endl << wandGen(4) << std::endl; break;
		case 18: ss << coinGen(6, 6, 3, 10) << std::endl << potGen(3, 5) << std::endl << wandGen(6) << std::endl; break;
		case 19: ss << scrollGen(5, 6) << std::endl << wandGen(4) << std::endl; break;
		case 20: ss << coinGen(6, 6, 4) << std::endl << potGen(4, 6) << std::endl << scrollGen(3, 6) << std::endl << wandGen(6) << std::endl; break;
		case 21: ss << coinGen(6, 6, 4) << std::endl << potGen(4, 6) << std::endl << scrollGen(3, 6) << std::endl << wandGen(6) << std::endl; break;
		case 22: ss << coinGen(8, 4, 4, 10) << std::endl << scrollGen(4, 6) << std::endl << wandGen(2, 6) << std::endl; break;
		default: std::cout << "Error Code 4399\n"; break;
		}
	else if (type == 5)
		switch (lootValue(types[4], value))
		{
		case -1: std::cout << "Too sm0l value for this encounter type\nTry again with a less valuable type\n"; break;
		case 1: ss << armorGen(0) << std::endl; break;
		case 2: ss << armorGen(0) << std::endl; break;
		case 3: ss << weaponGen(0) << std::endl; break;
		case 4: ss << armorGen(0) << std::endl; break;
		case 5: ss << armorGen(1) << std::endl; break;
		case 6: ss << weaponGen(1) << std::endl; break;
		case 7: ss << armorGen(2) << std::endl; break;
		case 8: ss << armorGen(1) << std::endl << weaponGen(1) << std::endl; break;
		case 9: ss << armorGen(2) << std::endl << weaponGen(1) << std::endl; break;
		case 10: ss << weaponGen(2) << std::endl; break;
		case 11: ss << armorGen(1) << std::endl << armorGen(2) << std::endl; break;
		case 12: ss << armorGen(2) << std::endl << weaponGen(1) << std::endl << weaponGen(1) << std::endl; break;
		case 13: ss << armorGen(2) << std::endl << armorGen(2) << std::endl; break;
		case 14: ss << armorGen(3) << std::endl << weaponGen(1) << std::endl; break;
		case 15: ss << weaponGen(3) << std::endl; break;
		case 16: ss << armorGen(4) << std::endl << weaponGen(1) << std::endl; break;
		case 17: ss << armorGen(3) << std::endl << weaponGen(3) << std::endl; break;
		case 18: ss << armorGen(2) << std::endl << weaponGen(4) << std::endl; break;
		case 19: ss << armorGen(3) << std::endl << weaponGen(4) << std::endl; break;
		case 20: ss << armorGen(1) << std::endl << weaponGen(5) << std::endl; break;
		case 21: ss << armorGen(6) << std::endl << weaponGen(2) << std::endl; break;
		case 22: ss << armorGen(6) << std::endl << weaponGen(3) << std::endl; break;
		case 23: ss << armorGen(2) << std::endl << weaponGen(6) << std::endl; break;
		case 24: ss << armorGen(6) << std::endl << weaponGen(6) << std::endl; break;
		default: std::cout << "Error Code 4429\n"; break;
		}
	else if (type == 6)
		switch (lootValue(types[5], value))
		{
		case -1: std::cout << "Too sm0l value for this encounter type\nTry again with a less valuable type\n"; break;
		case 1: ss << coinGen(2, 4, 2, 10) << std::endl << coinGen(2, 4, 3) << std::endl << potGen(1) << std::endl; break;
		case 2: ss << coinGen(2, 4, 2, 10) << std::endl << coinGen(2, 4, 3) << std::endl << armorGen(0) << std::endl << potGen(1) << std::endl; break;
		case 3: ss << coinGen(2, 4, 2, 10) << std::endl << coinGen(2, 4, 3) << std::endl << armorGen(0) << std::endl << potGen(1) << std::endl; break;
		case 4: ss << coinGen(2, 4, 2, 10) << std::endl << coinGen(2, 4, 3) << std::endl << weaponGen(0) << std::endl << potGen(1) << std::endl; break;
		case 5: ss << weaponGen(0) << std::endl << potGen(2) << std::endl; break;
		case 6: ss << coinGen(6, 6, 3) << std::endl << armorGen(0) << std::endl << weaponGen(0) << std::endl << potGen(2, 1) << std::endl; break;
		case 7: ss << armorGen(0) << std::endl; break;
		case 8: ss << armorGen(0) << std::endl << weaponGen(0) << std::endl << potGen(2) << std::endl; break;
		case 9: ss << armorGen(1) << std::endl << weaponGen(1) << std::endl << potGen(2, 1) << std::endl; break;
		case 10: ss << armorGen(0) << std::endl << weaponGen(1) << std::endl << potGen(2) << std::endl; break;
		case 11: ss << armorGen(1) << std::endl << weaponGen(0) << std::endl << wGen(1) << std::endl << potGen(2) << std::endl; break;
		case 12: ss << armorGen(0) << std::endl << weaponGen(1) << std::endl << wGen(1) << std::endl << potGen(2) << std::endl; break;
		case 13: ss << armorGen(1) << std::endl << weaponGen(1) << std::endl << wGen(1) << std::endl; break;
		case 14: ss << armorGen(2) << std::endl << weaponGen(1) << std::endl << ringGen(1) << std::endl; break;
		case 15: ss << armorGen(2) << std::endl << weaponGen(1) << std::endl << ringGen(1) << std::endl << wGen(1) << std::endl << potGen(3, 2) << std::endl; break;
		case 16: ss << armorGen(2) << std::endl << weaponGen(1) << std::endl << wGen(2) << std::endl << potGen(2, 4) << std::endl; break;
		case 17: ss << armorGen(2) << std::endl << weaponGen(2) << std::endl << ringGen(2) << std::endl; break;
		case 18: ss << armorGen(3) << std::endl << weaponGen(2) << std::endl << wGen(2) << std::endl << potGen(2, 4) << std::endl; break;
		case 19: ss << armorGen(3) << std::endl << weaponGen(3) << std::endl << ringGen(1) << std::endl << wGen(1) << std::endl << potGen(2, 4) << std::endl; break;
		case 20: ss << armorGen(3) << std::endl << weaponGen(3) << std::endl << ringGen(2, 1) << std::endl << wGen(2) << std::endl; break;
		case 21: ss << armorGen(3) << std::endl << weaponGen(3) << std::endl << ringGen(3) << std::endl << wGen(2) << std::endl << potGen(2, 4) << std::endl; break;
		case 22: ss << armorGen(4) << std::endl << weaponGen(4) << std::endl << wGen(3) << std::endl << potGen(2, 5) << std::endl; break;
		case 23: ss << armorGen(4) << std::endl << weaponGen(4) << std::endl << ringGen(2, 2) << std::endl << wGen(2, 2) << std::endl; break;
		case 24: ss << armorGen(5) << std::endl << weaponGen(4) << std::endl << ringGen(2) << std::endl << wGen(4) << std::endl << potGen(3, 6) << std::endl; break;
		case 25: ss << armorGen(5) << std::endl << weaponGen(5) << std::endl << ringGen(3) << std::endl << ringGen(2) << std::endl << wGen(2, 3) << std::endl; break;
		default: std::cout << "Error Code 4460\n"; break;
		}
	else if (type == 7)
		switch (lootValue(types[6], value))
		{
		case -1: std::cout << "Too sm0l value for this encounter type\nTry again with a less valuable type\n"; break;
		case 1: ss << coinGen(2, 4, 2, 10) << std::endl << coinGen(2, 4, 3) << std::endl << potGen(1) << std::endl; break;
		case 2: ss << coinGen(2, 4, 3) << std::endl << potGen(1) << std::endl << scrollGen(1) << std::endl; break;
		case 3: ss << potGen(1) << std::endl << scrollGen(2, 1) << std::endl; break;
		case 4: ss << scrollGen(1) << std::endl << scrollGen(2) << std::endl; break;
		case 5: ss << potGen(2, 1) << std::endl << scrollGen(2) << std::endl; break;
		case 6: ss << scrollGen(2, 2) << std::endl; break;
		case 7: ss << potGen(3, 1) << std::endl << scrollGen(3, 1) << std::endl; break;
		case 8: ss << potGen(2) << std::endl << wandGen(1) << std::endl; break;
		case 9: ss << coinGen(7, 6, 3) << std::endl << scrollGen(3, 2) << std::endl << wandGen(1) << std::endl; break;
		case 10: ss << coinGen(3, 6, 3, 10) << std::endl << potGen(3) << std::endl << scrollGen(3) << std::endl << wandGen(1) << std::endl; break;
		case 11: ss << coinGen(2, 4, 3, 10) << std::endl << weaponGen(0) << std::endl << scrollGen(2, 3) << std::endl << wandGen(1) << std::endl; break;
		case 12: ss << potGen(2, 4) << std::endl << wandGen(2) << std::endl; break;
		case 13: ss << potGen(4) << std::endl << scrollGen(2, 3) << std::endl << wandGen(2) << std::endl; break;
		case 14: ss << wGen(1) << std::endl << potGen(4) << std::endl << wandGen(2) << std::endl; break;
		case 15: ss << ringGen(1) << std::endl << wGen(1) << std::endl << scrollGen(2, 1) << std::endl; break;
		case 16: ss << ringGen(1) << std::endl << wGen(1) << std::endl << potGen(4) << std::endl << wandGen(2) << std::endl; break;
		case 17: ss << potGen(2, 4) << std::endl << scrollGen(1) << std::endl << wandGen(3) << std::endl; break;
		case 18: ss << ringGen(1) << std::endl << wGen(1) << std::endl << wandGen(3) << std::endl; break;
		case 19: ss << ringGen(1) << std::endl << wGen(2) << std::endl << scrollGen(2, 4) << std::endl << wandGen(2, 2) << std::endl; break;
		case 20: ss << ringGen(1) << std::endl << rodGen(3) << std::endl << wandGen(3) << std::endl; break;
		case 21: ss << ringGen(2) << std::endl << wGen(2) << std::endl << potGen(4) << std::endl << scrollGen(2, 4) << std::endl << wandGen(3) << std::endl; break;
		case 22: ss << ringGen(1) << std::endl << wandGen(3) << std::endl << wandGen(4) << std::endl << wGen(2) << std::endl; break;
		case 23: ss << ringGen(2) << std::endl << wGen(3) << std::endl << scrollGen(5) << std::endl << wandGen(4) << std::endl; break;
		case 24: ss << weaponGen(1) << std::endl << staffGen(3) << std::endl << rodGen(4) << std::endl << wGen(2, 1) << std::endl << wandGen(5) << std::endl; break;
		case 25: ss << ringGen(2) << std::endl << wGen(2, 3) << std::endl << potGen(5) << std::endl << scrollGen(3, 4) << std::endl << wandGen(5) << std::endl; break;
		case 26: ss << staffGen(3) << std::endl << rodGen(4) << std::endl << wGen(4) << std::endl << potGen(4) << std::endl << scrollGen(2, 5) << std::endl << wandGen(3) << std::endl; break;
		case 27: ss << weaponGen(1) << std::endl << staffGen(4) << std::endl << wGen(4) << std::endl << scrollGen(3, 6) << std::endl << wGen(6) << std::endl; break;
		case 28: ss << ringGen(5) << std::endl << rodGen(4) << std::endl << staffGen(5) << std::endl << scrollGen(5) << std::endl << wandGen(4) << std::endl; break;
		default: std::cout << "Error Code 4494\n"; break;
		}
	else if (type == 8)
		switch (lootValue(types[7], value))
		{
		case -1: std::cout << "Too sm0l value for this encounter type\nTry again with a less valuable type\n"; break;
		case 1: ss << coinGen(4, 4, 1, 100) << std::endl << coinGen(3, 6, 2, 10) << std::endl << coinGen(2, 4, 3, 10) << std::endl << weaponGen(0) << std::endl << potGen(1) << std::endl << scrollGen(1) << std::endl << gemGen(2) << std::endl; break;
		case 2: ss << coinGen(2, 4, 1, 100) << std::endl << coinGen(2, 6, 2, 100) << std::endl << coinGen(6, 6, 3) << std::endl << potGen(2) << std::endl << scrollGen(2) << std::endl << wandGen(1) << std::endl << gemGen(3, 1) << std::endl; break;
		case 3: ss << coinGen(3, 6, 2, 10) << std::endl << coinGen(2, 4, 3) << std::endl << armorGen(0) << std::endl << weaponGen(0) << std::endl << potGen(2, 3) << std::endl << scrollGen(2, 2) << std::endl << gemGen(2) << std::endl; break;
		case 4: ss << coinGen(2, 4, 3, 10) << std::endl << coinGen(4, 6, 4) << std::endl << weaponGen(0) << std::endl << ringGen(1) << std::endl << potGen(4) << std::endl << scrollGen(3) << std::endl << wandGen(2) << std::endl; break;
		case 5: ss << coinGen(4, 4, 3, 10) << std::endl << coinGen(6, 6, 4) << std::endl << weaponGen(1) << std::endl << wGen(1) << std::endl << potGen(2, 4) << std::endl << wandGen(2) << std::endl << gemGen(2, 3) << std::endl; break;
		case 6: ss << coinGen(4, 8, 3, 10) << std::endl << coinGen(6, 10, 4) << std::endl << armorGen(2) << std::endl << ringGen(1) << std::endl << wGen(1) << std::endl << scrollGen(3) << std::endl << wandGen(2) << std::endl << gemGen(4) << std::endl; break;
		case 7: ss << coinGen(4, 4, 3, 10) << std::endl << coinGen(4, 4, 4, 10) << std::endl << armorGen(2) << std::endl << wGen(1) << std::endl << potGen(2, 4) << std::endl << scrollGen(2, 4) << std::endl << wandGen(3) << std::endl << gemGen(3) << std::endl;	break;
		case 8: ss << coinGen(2, 4, 4, 10) << std::endl << ringGen(2) << std::endl << wGen(2, 1) << std::endl << potGen(2, 4) << std::endl << scrollGen(2, 5) << std::endl << wandGen(3) << std::endl; break;
		case 9: ss << coinGen(6, 10, 3, 10) << std::endl << coinGen(6, 6, 4) << std::endl << armorGen(3) << std::endl << weaponGen(1) << std::endl << wGen(2) << std::endl << scrollGen(2, 5) << std::endl << wandGen(3) << std::endl << gemGen(4) << std::endl; break;
		case 10: ss << coinGen(6, 6, 3, 10) << std::endl << coinGen(2, 4, 4, 10) << std::endl << weaponGen(2) << std::endl << wGen(3) << std::endl << wandGen(4) << std::endl << gemGen(3, 3) << std::endl;	break;
		case 11: ss << coinGen(4, 4, 3, 10) << std::endl << coinGen(4, 4, 4, 10) << std::endl << ringGen(3) << std::endl << rodGen(3) << std::endl << potGen(2, 6) << std::endl << scrollGen(2, 5) << std::endl << wandGen(5) << std::endl;	break;
		case 12: ss << coinGen(4, 4, 4, 10) << std::endl << armorGen(4) << std::endl << staffGen(3) << std::endl << wGen(3) << std::endl << scrollGen(6) << std::endl << wandGen(3) << std::endl << gemGen(5) << std::endl;	break;
		case 13: ss << coinGen(2, 8, 3, 100) << std::endl << coinGen(4, 4, 4, 10) << std::endl << weaponGen(2) << std::endl << ringGen(4) << std::endl << staffGen(4) << std::endl << potGen(3, 6) << std::endl << scrollGen(6) << std::endl << wandGen(5) << std::endl << gemGen(5) << std::endl; break;
		case 14: ss << coinGen(8, 6, 3, 100) << std::endl << coinGen(4, 4, 4, 10) << std::endl << ringGen(5) << std::endl << wGen(5) << std::endl << potGen(3, 6) << std::endl << scrollGen(6) << std::endl << wandGen(3) << std::endl << gemGen(2, 5) << std::endl << gemGen(6) << std::endl; break;
		default: std::cout << "Error Code 4514\n"; break;
		}
	else if (type == 9)
		switch (lootValue(types[8], value))
		{
		case -1: std::cout << "Too sm0l value for this encounter type\nTry again with a less valuable type\n"; break;
		case 1: ss << coinGen(4, 4, 1, 100) << std::endl << coinGen(6, 6, 2, 100) << std::endl << coinGen(2, 4, 3, 100) << std::endl << coinGen(6, 6, 4) << std::endl << armorGen(1) << std::endl << wandGen(2) << std::endl << gemGen(5, 3) << std::endl << artGen(3) << std::endl; break;
		case 2: ss << coinGen(4, 4, 1, 100) << std::endl << coinGen(6, 6, 2, 100) << std::endl << coinGen(2, 4, 3, 100) << std::endl << coinGen(6, 6, 4) << std::endl << armorGen(2) << std::endl << weaponGen(1) << std::endl << wGen(1) << std::endl << scrollGen(4) << std::endl << gemGen(4) << std::endl << artGen(3) << std::endl; break;
		case 3: ss << coinGen(2, 4, 1, 1000) << std::endl << coinGen(6, 4, 2, 100) << std::endl << coinGen(3, 6, 3, 10) << std::endl << coinGen(6, 6, 4) << std::endl << ringGen(2) << std::endl << wGen(2, 1) << std::endl << potGen(2, 4) << std::endl << wandGen(2) << std::endl << gemGen(4) << std::endl << artGen(3) << std::endl; break;
		case 4: ss << coinGen(2, 4, 1, 1000) << std::endl << coinGen(6, 4, 2, 100) << std::endl << coinGen(3, 6, 3, 10) << std::endl << coinGen(6, 6, 4) << std::endl << armorGen(2) << std::endl << rodGen(3) << std::endl << wGen(2) << std::endl << potGen(2, 5) << std::endl << scrollGen(4) << std::endl << artGen(3, 3) << std::endl; break;
		case 5: ss << coinGen(2, 4, 1, 1000) << std::endl << coinGen(6, 4, 2, 100) << std::endl << coinGen(3, 6, 3, 10) << std::endl << coinGen(6, 6, 4) << std::endl << staffGen(3) << std::endl << wGen(2, 1) << std::endl << potGen(4) << std::endl << wandGen(3) << std::endl << gemGen(2, 2) << std::endl << gemGen(2, 3) << std::endl << gemGen(4) << std::endl; break;
		case 6: ss << coinGen(2, 4, 1, 1000) << std::endl << coinGen(6, 4, 2, 100) << std::endl << coinGen(3, 6, 3, 10) << std::endl << coinGen(6, 6, 4) << std::endl << armorGen(3) << std::endl << weaponGen(2) << std::endl << wGen(3) << std::endl << scrollGen(2, 5) << std::endl << artGen(4) << std::endl; break;
		case 7: ss << coinGen(4, 4, 1, 100) << std::endl << coinGen(6, 6, 2, 100) << std::endl << coinGen(2, 4, 3, 100) << std::endl << coinGen(6, 6, 4) << std::endl << weaponGen(3) << std::endl << rodGen(4) << std::endl << potGen(6) << std::endl << scrollGen(4) << std::endl << wandGen(3) << std::endl << artGen(3, 3) << std::endl << artGen(2, 4) << std::endl; break;
		case 8: ss << coinGen(4, 4, 1, 10000) << std::endl << coinGen(6, 6, 2, 1000) << std::endl << coinGen(4, 4, 3, 100) << std::endl << coinGen(2, 4, 4, 10) << std::endl << armorGen(2) << std::endl << weaponGen(2, 2) << std::endl << staffGen(4) << std::endl << wGen(2) << std::endl << gemGen(5) << std::endl; break;
		case 9: ss << coinGen(2, 4, 1, 10000) << std::endl << coinGen(2, 4, 2, 1000) << std::endl << coinGen(2, 4, 3, 100) << std::endl << coinGen(2, 4, 4, 10) << std::endl << weaponGen(4) << std::endl << rodGen(4) << std::endl << wGen(3) << std::endl << scrollGen(6) << std::endl << wandGen(2, 2) << std::endl << gemGen(4) << std::endl << artGen(5, 2) << std::endl; break;
		case 10: ss << coinGen(2, 4, 1, 10000) << std::endl << coinGen(2, 4, 2, 1000) << std::endl << coinGen(2, 4, 3, 100) << std::endl << coinGen(2, 4, 4, 10) << std::endl << armorGen(5) << std::endl << ringGen(4) << std::endl << staffGen(3) << std::endl << wandGen(4) << std::endl << gemGen(6) << std::endl << artGen(4) << std::endl; break;
		case 11: ss << coinGen(2, 4, 1, 10000) << std::endl << coinGen(2, 4, 2, 1000) << std::endl << coinGen(2, 4, 3, 100) << std::endl << coinGen(2, 4, 4, 10) << std::endl << weaponGen(3) << std::endl << ringGen(4) << std::endl << rodGen(5) << std::endl << wGen(4) << std::endl << potGen(2, 6) << std::endl << scrollGen(3) << std::endl << artGen(2, 4) << std::endl; break;
		case 12: ss << coinGen(4, 4, 1, 10000) << std::endl << coinGen(6, 6, 2, 1000) << std::endl << coinGen(4, 4, 3, 100) << std::endl << coinGen(2, 8, 4, 10) << std::endl << armorGen(6) << std::endl << weaponGen(3) << std::endl << staffGen(5) << std::endl << scrollGen(2, 6) << std::endl << wandGen(6) << std::endl << gemGen(6) << std::endl << artGen(3, 4) << std::endl; break;
		case 13: ss << coinGen(4, 4, 1, 10000) << std::endl << coinGen(6, 6, 2, 1000) << std::endl << coinGen(4, 4, 3, 100) << std::endl << coinGen(2, 8, 4, 10) << std::endl << armorGen(4) << std::endl << ringGen(5) << std::endl << wGen(6) << std::endl << wandGen(6) << std::endl; break;
		case 14: ss << coinGen(4, 4, 1, 10000) << std::endl << coinGen(6, 6, 2, 1000) << std::endl << coinGen(4, 4, 3, 100) << std::endl << coinGen(2, 8, 4, 10) << std::endl << weaponGen(6) << std::endl << ringGen(2, 3) << std::endl << staffGen(5) << std::endl << wGen(5) << std::endl << wandGen(5) << std::endl << gemGen(3, 5) << std::endl << gemGen(4) << std::endl;	break;
		case 15: ss << coinGen(8, 4, 1, 10000) << std::endl << coinGen(12, 6, 2, 1000) << std::endl << coinGen(8, 4, 3, 100) << std::endl << coinGen(2, 8, 4, 10) << std::endl << weaponGen(6) << std::endl << ringGen(5) << std::endl << staffGen(6) << std::endl << wGen(6) << std::endl << wandGen(4) << std::endl << gemGen(6) << std::endl << artGen(6) << std::endl; break;
		default: std::cout << "Error Code 4535\n"; break;
		}
	std::cout << head << ss.str();

	int repeat;
	do  
	{
		std::cout << "Again?\n1. Yes\n2. No\n3. Save these results for later\n";
		std::cin >> repeat;
		if (repeat == 3) toText(ss.str(), head);
	} while (repeat != 1 && repeat != 2);
	return repeat;
}

int main()
{
	int CR, type, level = 0;
	double modifier, value;
	int npcVal[20] = { 260, 390, 780, 1650, 2400, 3450, 4650, 6000, 7800, 10050, 12750, 16350, 21000, 27000, 34800, 45000, 58500, 75000, 96000, 123000 },
		crVal[20] = { 400, 800, 1200, 1700, 2300, 3000, 3900, 5000, 6400, 8200, 10500, 13500, 17500, 22000, 29000, 38000, 48000, 62000, 79000, 100000 };
	std::string head = "";
	srand((unsigned int)time(NULL));

	do
	{
		cls();
		do  
		{
			std::cout << "What CR was the encounter?\n";
			std::cin >> CR;
			cls();
			if (CR < 1 || CR > 20) std::cout << "Invalid CR. Please enter a number between 1 and 20\n\n";
		} while (CR < 1 || CR > 20);

		do  
		{
			std::cout << "How much treasure do you want to generate?\n1. Incidental\n2. Normal\n3. Double\n4. Triple\n5. NPC Gear\n";
			std::cin >> modifier;
			cls();
			if (modifier < 1 || modifier > 5) std::cout << "Invalid number. Please enter a number between 1 and 5\n\n";
		} while (modifier < 1 || modifier > 5);

		if (modifier == 5)
		{
			level = 0, value = 0;
			do
			{
				std::cout << "What level was the NPC?\n";
				std::cin >> level;
				value += npcVal[level - 1];
				std::cout << "Was there another NPC?\n1. Yes\n2. No\n";
				std::cin >> level;
				if (level < 1 || level > 2) std::cout << "Invalid number. Please enter a number between 1 and 2\n\n";
			} while (level < 1 || level > 2);
		}
		if (modifier != 5) value = crVal[CR - 1] * modifier;

		do 
		{
			std::cout << "What kind of treasure do you want to generate?\n";
			std::cout << "1. Coins\n\tTreasure of this type consists entirely of coins\n";
			std::cout << "2. Coins and Gems\n\tThis type also includes gemstones, some of which can be quite valuable\n";
			std::cout << "3. Art Objects\n\tThese items are valuable for their beauty and craftsmanship\n\t and are made with precious metals, gems, and other fine materials\n";
			std::cout << "4. Coins and Small Objects\n\tCoins and small magic items, such as potions, rings, scrolls, and wands\n";
			std::cout << "5. Armor and Weapons\n\tSolely weapons and armor\n";
			std::cout << "6. Combatant Gear\n\tArmor, coins, potions, weapons, and wondrous items\n";
			std::cout << "7. Spellcaster Gear\n\tCoins, potions, scrolls, staves, wands, and wondrous items\n";
			std::cout << "8. Lair Treasure\n\tA large number of magic items, coins, and other valuables\n";
			std::cout << "9. Treasure Hoard\n\tThis can contain virtually any type of item\n";
			std::cin >> type;
			cls();
			if (type > 9 || type < 1)std::cout << "Invalid number. Please enter a number between 1 and 9\n\n";
		} while (type > 9 || type < 1);

		if (level == 0) head = "CR " + std::to_string(CR) + " Encounter - Type " + std::to_string(type) + " Treasure\n\n";
		else if (level != 0) head = "Level " + std::to_string(level) + " NPC - Type " + std::to_string(type) + " Treasure\n\n";
	} while (genFirst(type, value, head) == 1);
	return 0;
}