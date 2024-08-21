#pragma once
/* Sub.h */


class
{
public:

	int c[50 + 1];

	void Load()
	{
		for (int i = 0; i < 50 + 1; i++)
		{
			c[i] = CreateFontToHandle("�l�r �S�V�b�N", i, 6, DX_FONTTYPE_NORMAL);
		}
	}
private:
}Font;

class
{
public:

	int WHITE;
	int RED;
	int GREEN;
	int BLUE;
	int BLACK;

	void Load()
	{
		WHITE = GetColor(255, 255, 255);
		RED = GetColor(255, 0, 0);
		GREEN = GetColor(0, 255, 0);
		BLUE = GetColor(0, 0, 255);
		BLACK = GetColor(0, 0, 0);
	}
private:
}Color;

int Key[256];

int GetKey()
{
	char allKey[256];
	GetHitKeyStateAll(allKey);

	for (int i = 0; i < 256; i++) {
		if (allKey[i] != 0)
		{
			Key[i]++;
		}
		else
		{
			Key[i] = 0;
		}
	}
	return 0;
}
