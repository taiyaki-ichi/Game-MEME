#pragma once
#include"PlayerStateBase.hpp"

namespace GameLib
{
	class DrawAnimation;
}

namespace Stage
{
	class PlayerDeath : public PlayerStateBase
	{
		int mCnt;

		//�A�j���[�V�����ւ̎Q��
		GameLib::DrawAnimation* mAnimation;

	public:
		PlayerDeath(StateManager<char>* player, GameLib::DrawAnimation* anim);
		virtual ~PlayerDeath() = default;

		void CustomizeUpdate() override;


		void Active() override {};
		void Pause() override {};

		void SetPosition(const GameLib::Vector2& pos) override;
	};
}