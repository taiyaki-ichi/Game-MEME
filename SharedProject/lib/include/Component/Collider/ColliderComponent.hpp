#pragma once
#include<utility>
#include<string>
#include<unordered_map>
#include<functional>
#include<optional>
#include"lib/include/Component/Draw/SpriteCompoent.hpp"
#include"lib/include/Math/Vector2.hpp"


namespace GameLib
{
	class CoordinateActor;

	class ColliderComponent : public SpriteComponent
	{
		//��{���
		CoordinateActor* mCoordinateActor;
		float mWidth;
		float mHeight;
		Vector2 mAdjust;
		//���ʗp�^�O
		std::string mName;

		//�`�ʂ����ۂ̐F
		Color mColor;

		//�`�ʂ��邩�ǂ���
		static bool mIsDrawing;

		//��������ColliderComponent��Name�^�O�ƌĂяo���ׂ��֐���ێ�
		//void(ColliderComponent*, ColliderComponent*)�̑����������g��ColliderComponennt�A��񂪏Փ˂��Ă���Collider
		std::unordered_map<std::string, std::function<void(ColliderComponent*, ColliderComponent*)>> mHitFunctions;


	public:
		ColliderComponent(CoordinateActor* owner,std::string&& name, float width, float heigth, Color&& color = { 0,0,0,255 }, int updateOrder = 0);
		virtual ~ColliderComponent();

		//����ColliderComponent�ƏՓ˂���\��������ꍇ�A���Ȃ킿�����������ꂽ��ԓ��ɂɂ���Ƃ�
		//�Ăяo���ׂ��֐�������Ȃ�ڂ��������蔻������s
		//�����łȂ��Ȃ�nullopt��Ԃ������蔻����s��Ȃ�
		std::optional<std::function<void(ColliderComponent*, ColliderComponent*)>> GetHitFunction(const std::string& name);


		virtual void Draw() override;

		void SetWidthAndHeigth(float w, float h);
		void SetColor(Color&& color);
		void SetName(std::string&& name);

		static void SetIsDrawing(bool d);

	
	
	};

}