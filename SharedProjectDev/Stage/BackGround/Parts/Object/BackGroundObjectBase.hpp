#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Stage::BackGround
{
	
	class ObjectBase : public GameLib::Actor
	{
		GameLib::Vector2 mPosition;

		//���S����̕�
		float mMarginX;
		float mMarginY;

		//�ǂꂾ��������
		float mMoveRateX;
		float mMoveRateY;

		//�����|�C���^�ɂ��ăA�j���[�V������������悤�ɂ��Ă�������
		GameLib::DrawTexture mTexture;

	public:
		ObjectBase(GameLib::Actor* owner, std::string&& fileName, int drawOrder);
		virtual ~ObjectBase() = default;

		void CustomizeUpdate() override;

		void SetMarginXY(float x, float y);
		void SetPosition(GameLib::Vector2&& pos);

	protected:
		//�h���N���X�̃R���X�g���N�^���Ŏg���\��
		void SetScale(float s);
		void SetMoveRateXY(float x, float y);
	};
}