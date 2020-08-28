#pragma once
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game
{
	class TearGemDisplay
	{
		GameLib::DrawTexture mTexture1;
		GameLib::DrawTexture mTexture2;
		GameLib::DrawTexture mTexture3;

		GameLib::Vector2 mAdjustPos;

	public:
		TearGemDisplay(const GameLib::Vector2&);
		virtual ~TearGemDisplay() = default;

		//�����\�����Ȃ�
		void NotDrawing();

		//���ׂĂ̂Ă���������t���[���ɃZ�b�g
		void SetFrame();

		void SetTearGem(int);

		void AdjustPos();
	};


}