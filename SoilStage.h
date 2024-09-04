#pragma once

#include<DxLib.h>
#include<fstream>
#include<sstream>
#include<string>





class SOILSTAGE {
public:
	struct {
		int Type[MAP_MAX_X][MAP_MAX_Y];

	}Chip;

	void Read() {
		std::ifstream file("CourceMap/WorldMap2.txt");
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
					pic = Picture.SoilMap[0];
					break;
				case 1:
					pic = Picture.SoilMap[1];
					break;
				case 2:
					pic = Picture.SoilMap[2];
					break;
				case 3:
					pic = Picture.SoilMap[3];
					break;
				case 4:
					pic = Picture.SoilMap[4];
					break;
				case 5:
					pic = Picture.SoilMap[5];
					break;
				case 6:
					pic = Picture.SoilMap[6];
					break;
				case 7:
					pic = Picture.SoilMap[7];
					break;
				case 8:
					pic = Picture.SoilMap[8];
					break;
				case 9:
					pic = Picture.SoilMap[9];
					break;
				case 10:
					pic = Picture.SoilMap[10];
					break;
				case 11:
					pic = Picture.SoilMap[11];
					break;
				case 12:
					pic = Picture.SoilMap[12];
					break;
				case 13:
					pic = Picture.SoilMap[13];
					break;


				}
				DrawGraph(CELL * x, CELL * y, pic, false);
			}
		}
		if (Key[KEY_INPUT_RETURN] == 1)
		{
			Scene = COURCE::GLASSMAP;
		}
	}
	
	
private:



};



SOILSTAGE SoilStage;
