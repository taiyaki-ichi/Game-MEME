#pragma once
#include<Windows.h>
#include<cmath>

namespace GameLib
{
	// 座標から空間番号を算出
	DWORD GetMortonNumber(float left, float top, float right, float bottom);
	
}