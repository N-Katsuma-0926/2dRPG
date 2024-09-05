#pragma once

#include<fstream>
#include<sstream>
#include<string>

const int MAP_MAX_X = 30;
const int MAP_MAX_Y = 20;
const int CELL = 32;	//ˆê•Ó‚Ì’·‚³

class GLASSSTAGE {
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
						pic = Picture.GlassMap[0];
						break;
					case 1:
						pic = Picture.GlassMap[1];
						break;
					case 2:
						pic = Picture.GlassMap[2];
						break;
					case 3:
						pic = Picture.GlassMap[3];
						break;
					case 4:
						pic = Picture.GlassMap[4];
						break;
					case 5:
						pic = Picture.GlassMap[5];
						break;
					case 6:
						pic = Picture.GlassMap[6];
						break;
					case 7:
						pic = Picture.GlassMap[7];
						break;
					case 8:
						pic = Picture.GlassMap[8];
						break;
					case 9:
						pic = Picture.GlassMap[9];
						break;
					case 10:
						pic = Picture.GlassMap[10];
						break;
					case 11:
						pic = Picture.GlassMap[11];
						break;
					case 12:
						pic = Picture.GlassMap[12];
						break;
					case 13:
						pic = Picture.GlassMap[13];
						break;
					case 14:
						pic = Picture.GlassMap[14];
						break;
					case 15:
						pic = Picture.GlassMap[15];
						break;
					case 16:
						pic = Picture.GlassMap[16];
						break;
					case 17:
						pic = Picture.GlassMap[17];
						break;
					case 18:
						pic = Picture.GlassMap[18];
						break;
					case 19:
						pic = Picture.GlassMap[19];
						break;
					case 20:
						pic = Picture.GlassMap[20];
						break;
					case 21:
						pic = Picture.GlassMap[21];
						break;
					case 22:
						pic = Picture.GlassMap[22];
						break;
					case 23:
						pic = Picture.GlassMap[23];
						break;
					case 24:
						pic = Picture.GlassMap[24];
						break;
					case 25:
						pic = Picture.GlassMap[25];
						break;
					case 26:
						pic = Picture.GlassMap[26];
						break;
					case 27:
						pic = Picture.GlassMap[27];
						break;
					case 28:
						pic = Picture.GlassMap[28];
						break;
					case 29:
						pic = Picture.GlassMap[29];
						break;
					case 30:
						pic = Picture.GlassMap[30];
						break;
					case 31:
						pic = Picture.GlassMap[31];
						break;
					case 32:
						pic = Picture.GlassMap[32];
						break;
					case 33:
						pic = Picture.GlassMap[33];
						break;
					case 34:
						pic = Picture.GlassMap[34];
						break;
					case 35:
						pic = Picture.GlassMap[35];
						break;
					case 36:
						pic = Picture.GlassMap[36];
						break;
					case 37:
						pic = Picture.GlassMap[37];
						break;
					case 38:
						pic = Picture.GlassMap[38];
						break;
					case 39:
						pic = Picture.GlassMap[39];
						break;
					case 40:
						pic = Picture.GlassMap[40];
						break;
					case 41:
						pic = Picture.GlassMap[41];
						break;


					
					
					}
					DrawGraph(CELL * x, CELL * y, pic, false);
				}
			}
		}

	private:



	};



GLASSSTAGE GlassStage;






