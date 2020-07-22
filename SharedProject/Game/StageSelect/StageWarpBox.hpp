#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Game::StageSelect
{
	class StageSelect;

	class WarpBox : public GameLib::Actor
	{
		GameLib::Collider mCollider;

		//Box��Texture��768*768�Œ�
		GameLib::DrawTexture mTexture;

		//isVaild��false�̏ꍇ
		GameLib::DrawRect mRect;

	public:
		//StageNum����ʒu������,
		WarpBox(StageSelect* stageSelect, std::string&& textureFileName, int stageNum, bool isVaild);
		virtual ~WarpBox() = default;

		void CustomizeUpdate() override;

		//�ҋ@�ʒu����o������
		void Up();
		//�ҋ@�ʒu��
		void Down();

	};
}