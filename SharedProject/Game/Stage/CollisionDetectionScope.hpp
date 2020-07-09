#pragma once
#include"Game/Window.hpp"

namespace Game::Stage
{
	namespace CollisionDetectionScope {

		//�����蔻����s���͈͂��E�B���h�E�̃T�C�Y���400.f�]�T��������
		//�Ίp���̒�����400.f�ȉ��̕��̂Ȃ�A��ʓ��ɂ���Ƃ��m���ɓ����蔻�肪�s����
		//300.f�~300.f���ő�l�̂߂₷�A�]�T��������

		constexpr float MARGIN = 400.f;
		constexpr float WIDTH = WINDOW_WIDTH + MARGIN * 2.f;
		constexpr float HEIGHT = WINDOW_HEIGHT + MARGIN * 2.f;
	}
}