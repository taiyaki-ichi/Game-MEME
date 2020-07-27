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

		//Box��Texture��768*768�Œ�
		//isVaild��false�̏ꍇ,DrawRect
		std::variant<GameLib::DrawTexture, GameLib::DrawRect> mBox;
		GameLib::DrawTexture mTexture;

		int mStageNum;

	public:
		//StageNum����ʒu������,
		WarpBox(StageSelect* stageSelect, std::string&& textureFileName, int stageNum, bool isVaild);
		virtual ~WarpBox() = default;

		void CustomizeUpdate() override;

		void SetPosition(const GameLib::Vector2& pos);
		const GameLib::Vector2& GetPosition() const;
	};



}
