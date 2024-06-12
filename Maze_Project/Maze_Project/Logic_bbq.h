#pragma once

const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;

typedef struct _tagpos
{
	int x;
	int y;
	
	bool operator ==(const _tagpos& _other) const
	{
		if (x == _other.x && y == _other.y)
			return true;
		else
			return false;
	}

}FLOAT2, *PFLOAT2;