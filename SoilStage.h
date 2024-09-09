#pragma once

#include<DxLib.h>
#include<fstream>
#include<sstream>
#include<string>

#include"HeroCat.h"
#include"BossRat.h"





class SOILSTAGE {
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
				case 14:
					pic = Picture.SoilMap[14];
					break;
				case 15:
					pic = Picture.SoilMap[15];
					break;
				case 16:
					pic = Picture.SoilMap[16];
					break;
				case 17:
					pic = Picture.SoilMap[17];
					break;
				case 18:
					pic = Picture.SoilMap[18];
					break;
				case 19:
					pic = Picture.SoilMap[19];
					break;
				case 20:
					pic = Picture.SoilMap[20];
					break;
				case 21:
					pic = Picture.SoilMap[21];
					break;
				case 22:
					pic = Picture.SoilMap[22];
					break;
				case 23:
					pic = Picture.SoilMap[23];
					break;
				case 24:
					pic = Picture.SoilMap[24];
					break;
				case 25:
					pic = Picture.SoilMap[25];
					break;
				case 26:
					pic = Picture.SoilMap[26];
					break;
				case 27:
					pic = Picture.SoilMap[27];
					break;
				case 28:
					pic = Picture.SoilMap[28];
					break;
				case 29:
					pic = Picture.SoilMap[29];
					break;
				case 30:
					pic = Picture.SoilMap[30];
					break;
				case 31:
					pic = Picture.SoilMap[31];
					break;
				case 32:
					pic = Picture.SoilMap[32];
					break;
				case 33:
					pic = Picture.SoilMap[33];
					break;
				case 34:
					pic = Picture.SoilMap[34];
					break;
				case 35:
					pic = Picture.SoilMap[35];
					break;
				case 36:
					pic = Picture.SoilMap[36];
					break;
				case 37:
					pic = Picture.SoilMap[37];
					break;
				case 38:
					pic = Picture.SoilMap[38];
					break;
				case 39:
					pic = Picture.SoilMap[39];
					break;
				case 40:
					pic = Picture.SoilMap[40];
					break;
				case 41:
					pic = Picture.SoilMap[41];
					break;


				}
				DrawGraph(CELL * x, CELL * y, pic, false);
			}
		}
		if (RatPosX - 30 <= CatPosX && CatPosX + CAT_SIZE_WID <= RatPosX + RAT_SIZE_WID + 30 && CatPosY <= RatPosY + RAT_SIZE_HIG  && CatPosY + CAT_SIZE_HIG >= RatPosY)
		{
			
			Scene = COURCE::BATTLE;
		}
	

	}
	
	
private:



};



SOILSTAGE SoilStage;
