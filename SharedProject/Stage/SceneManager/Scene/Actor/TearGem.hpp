#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace Stage
{
	class TearGem : public ActorBase
	{
		GameLib::DrawTexture mTexture;
		GameLib::Vector2 mPosition;
		GameLib::Collider mCollider;

		int mCnt;

		//�X�e�[�W�̉��Ԗڂ�Gem�Ȃ̂��A�l�����������ĂȂ����̏��Ɏg������
		int mNumber;

	public:
		TearGem(GameLib::Actor*);

		bool UpdateOrNot() override;
		void Update() override;

		void BeginWorking() override;
		void BeginToRest() override;

		void LoadPosData(std::vector<GameLib::Vector2>&&) override;
		void LoadStringData(std::vector<std::string>&&) override;

	};
}