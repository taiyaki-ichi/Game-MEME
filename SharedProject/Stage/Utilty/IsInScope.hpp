#pragma once
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	//��ʂ̒��S���炱�͈͓̔���pos�����邩�ǂ���
	bool IsInScope(const GameLib::Vector2& pos, float left, float right, float bottom, float top);
	//��ʂ̈ʒu�𒆐S�Ƃ��āA��w�^�eh�̒����`�̓������ǂ���
	bool IsInScope(const GameLib::Vector2& pos, float w, float h);
}