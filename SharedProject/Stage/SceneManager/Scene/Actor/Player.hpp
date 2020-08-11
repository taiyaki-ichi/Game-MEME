#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Player/PlayerStateManager.hpp"

namespace Stage
{
	class Life;

	class Player : public ActorBase
	{
		GameLib::DrawAnimation mAnimation;
		PlayerState::Manager mStateManager;

		static GameLib::Vector2 mPosition;

		Life* mLife;

	public:
		Player(GameLib::Actor* scene);
		virtual ~Player() = default;

		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&& data) override;

		void SetPosition(const GameLib::Vector2& pos);

		//Animation�̈ʒu
		static const GameLib::Vector2& GetPosition();

		//���x�Ȃǂ̃��Z�b�g
		void ResetPotentialPower();

		bool CheckFlag(char);
	};
}