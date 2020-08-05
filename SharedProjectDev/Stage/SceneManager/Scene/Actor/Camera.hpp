#pragma once
#include"StageActorBase.hpp"

namespace Stage
{
	class Camera : public ActorBase
	{
		float mLeft;
		float mRight;
		float mTop;
		float mBottom;

		//���R�����ւ�Player��ǔ��A�^�e�Ɋւ��Ă͑傫���������ꍇ�ǔ�
		constexpr static float MARGIN_Y = 200.f;

	public:
		Camera(GameLib::Actor* scene);
		virtual ~Camera() = default;

		void Update() override;

		void BeginWorking() override {};
		void BeginToRest() override {};

		void LoadData(std::vector<float>&& data) override;

		void AdjustPos();
	};
}