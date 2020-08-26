#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Stage
{
	//StageActorBese����h�������Ă��Ȃ��̂�Scene�Ɏ������Ă͂����Ȃ�
	class Lift : public GameLib::Actor
	{
		GameLib::Collider mCollider;
		GameLib::DrawTexture mTexture;

	public:
		Lift(GameLib::Actor*);

		void CustomizeUpdate() override;

		void SetPosition(const GameLib::Vector2&);
		const GameLib::Vector2& GetPosition() const;

		void BeginWorking();
		void BeginToRest();
	};
}