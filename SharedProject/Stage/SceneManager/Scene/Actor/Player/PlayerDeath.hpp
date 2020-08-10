#pragma once
#include"PlayerStateBase.hpp"


namespace GameLib
{
	class DrawAnimation;
}

namespace Stage::PlayerState
{

	class Death : public StateBase
	{
		int mCnt;

		//�A�j���[�V�����ւ̎Q��
		GameLib::DrawAnimation* mAnimation;

	public:
		Death(GameLib::DrawAnimation* anim);
		virtual ~Death() = default;

		Stage::StateBase<char>* Update() override;

		void BeginWorking() override {};
		void BeginToRest() override {};

		void SetPosition(const GameLib::Vector2 & pos) override;
	};

}