#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game::Stage::BackGround
{

	class FallObjectBase : public GameLib::Actor
	{
		GameLib::DrawTexture mTexture;
		
		//BackGround��Range���Ɏ��܂�悤�ɁA�܂�ViewPort�̉e�����󂯂Ă��Ȃ�
		GameLib::Vector2 mPosition;

		//deltaPos�͕��I�ȃC���[�W
		GameLib::Vector2 mDeltaPos;
		float mDeltaRot;

		float mMoveRate;

	public:
		FallObjectBase(GameLib::Actor* owner, std::string&& fileName, GameLib::Vector2&& startPos, float startRot, float scale,
			GameLib::Vector2&& deltaPos, float deltaRot, float moveRate,int drawOrder);
		virtual ~FallObjectBase() = default;

		void CustomizeUpdate() override;
	};

}