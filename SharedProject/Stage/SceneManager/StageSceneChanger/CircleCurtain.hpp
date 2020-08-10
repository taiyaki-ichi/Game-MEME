#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/CustomizeDrawBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"GameLib/include/Draw/DrawCircle.hpp"
#include"GameLib/include/Draw/DrawRect.hpp"

namespace Stage
{
	//Scene��ύX����ۂ̈Ó]->���]�̏���
	class CircleCurtain : public GameLib::CustomizeDrawBase
	{
		GameLib::DrawCircle mCircle;
		GameLib::DrawRect mRect;
		
		//0�͂��߁A1�^���Âɂ��Ă���A2�^���ÁA3���邭���Ă���A4���邭�Ȃ���
		int mStateFlag;

		constexpr static float RADIUS_SPEED = 15.f;
		constexpr static float MAX_RADIUS = 800.f;

	public:
		CircleCurtain();
		virtual ~CircleCurtain() = default;

		//pos�𒆐S�ɂ��ĈÓ]
		void TurnDark(const GameLib::Vector2& pos);

		//�܂�����ɂȂ������ǂ���
		bool IsDark();

		//pos�𒆎~�ɂ��Ė��]
		void TurnBright(const GameLib::Vector2& pos);

		//���邭�Ȃ�����
		bool IsBright();

		void Draw() override;

		//���t���[���Ăяo��
		void Update();
	};
}