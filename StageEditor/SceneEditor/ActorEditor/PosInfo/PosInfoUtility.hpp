#pragma once
#include"PosInfo.hpp"

namespace StageEditor
{
	//a,b�̋���
	float GetLength(PosInfo* a, PosInfo* b);

	//����abc�����v��肩�ǂ���
	bool IsClockwise(PosInfo* a, PosInfo* b, PosInfo* c);
}