#pragma once

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

	FLOAT2 operator +(const _tagpos& _other) const
	{
		return _tagpos{ x + _other.x, y + _other.y };
	}

}FLOAT2, *PFLOAT2;