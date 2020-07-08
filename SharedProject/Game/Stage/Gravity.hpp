#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Game/Dir4Vec.hpp"
#include"PhysicsModel.hpp"

namespace Game::Stage
{
	class Gravity : public GameLib::Actor
	{
		static float mSize;
		static Dir4 mDir4;

	public:
		Gravity(GameLib::Actor* owner);
		virtual ~Gravity() = default;

		//ViewPort�̉�]�̉�]�̐���
		void CustomizeUpdate() override;

		static GameLib::Vector2 GetGravityVector2();

		static GameLib::Vector2 GetVector2(const Dir4& dir4, float size);
		
		//Vector2��Dir4Vec�Ɋۂߍ���
		static Dir4Vec GetDir4Vec(const GameLib::Vector2& vec);

		//Vector2��Dir4�����̑傫���A�}�C�i�X�̏ꍇ������
		static float GetDir4Size(const GameLib::Vector2& vec, const Dir4& dir4);

		static float GetGravityRotation();

		//vector2�𐂒��A���������ɔ��]
		static GameLib::Vector2 GetVerticalFlippedVector2(const GameLib::Vector2& vec);
		static GameLib::Vector2 GetHolizonalFlippedVector2(const GameLib::Vector2& vec);

		//�t���[��������̗͂̍��v��d�͂̕����𓥂܂��čX�V
		static void UpdatePhysicsModel(PhysicsModel& model, const GameLib::Vector2& power, float horizonMaxSpeed = -1.f, float virticalMaxSpeed = -1.f, bool isRotaion = true);

		
		static float GetGravitySize() noexcept;
		static const Dir4& GetGravityDir4() noexcept;
		/*
		static void SetSize(float s);
		static void SetDir4(const Dir4& dir4);
		static void SetDir4Vec(const Dir4Vec& dir4Vec);
		*/
	};
}