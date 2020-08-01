#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"
#include<variant>

namespace Game::StageSelect
{
	class StageSelect;

	class WarpBox : public GameLib::Actor
	{
		GameLib::Collider mCollider;

		//BoxのTextureは768*768固定
		//isVaildがfalseの場合,DrawRect
		GameLib::DrawTexture mTexture;
		GameLib::DrawRect mRect;

		int mFlag;

	public:
		//StageNumから位置を決定,
		WarpBox(GameLib::Actor* stageSelect, std::string&& textureFileName, int stageNum, bool isVaild);
		virtual ~WarpBox() = default;

		void CustomizeUpdate() override;

		void SetPosition(const GameLib::Vector2& pos);
		const GameLib::Vector2& GetPosition() const;

		int GetFlag();
	};



}
