#pragma once

#include<DxLib.h>
#include<fstream>
#include<sstream>
#include<string>



const int MAP_MAX_X = 30;
const int MAP_MAX_Y = 20;
const int CELL = 32;	//ˆê•Ó‚Ì’·‚³


class TRANCESTAGE {
public:
	struct {
		int Type[MAP_MAX_X][MAP_MAX_Y];

	}Chip;

	void Read() {
		std::ifstream file("CourceMap/WorldMap.txt");
		std::string line;

		int y = 0;
		while (std::getline(file, line)) {
			std::istringstream stream(line);
			std::string field;
			int x = 0;
			while (std::getline(stream, field, ' '))
			{
				Chip.Type[x][y] = std::stoi(field);
				x++;
			}
			y++;
		}

	}

	void Draw() {
		int pic = 0;

		for (int y = 0; y < MAP_MAX_Y; y++) {
			for (int x = 0; x < MAP_MAX_X; x++) {
				switch (Chip.Type[x][y]) {
				case 0:
					pic = Picture.TranceMap[0];
					break;
				case 1:
					pic = Picture.TranceMap[1];
					break;
				case 2:
					pic = Picture.TranceMap[2];
					break;
				case 3:
					pic = Picture.TranceMap[3];
					break;
				case 4:
					pic = Picture.TranceMap[4];
					break;
				case 5:
					pic = Picture.TranceMap[5];
					break;
				case 6:
					pic = Picture.TranceMap[6];
					break;
				case 7:
					pic = Picture.TranceMap[7];
					break;
				case 8:
					pic = Picture.TranceMap[8];
					break;



				}
				DrawGraph(CELL * x, CELL * y, pic, false);
			}
		}

	}

private:



};



TRANCESTAGE TranceStage;
