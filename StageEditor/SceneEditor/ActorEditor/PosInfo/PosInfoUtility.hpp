#pragma once
#include"PosInfo.hpp"

namespace StageEditor
{
	//a,b�̋���
	float GetLength(PosInfo* a, PosInfo* b);

	//����abc�����v��肩�ǂ���
	bool IsClockwise(PosInfo* a, PosInfo* b, PosInfo* c);

	//a,b�̐^��
	GameLib::Vector2 GetCenter(PosInfo* a, PosInfo* b);

	//a,b��x�����̋���
	float GetWidth(PosInfo* a, PosInfo* b);
	float GetHeight(PosInfo* a, PosInfo* b);
}