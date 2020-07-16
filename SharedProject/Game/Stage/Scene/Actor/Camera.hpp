#pragma once
#include"ActorBase.hpp"

namespace Game::Stage
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
		Camera(Scene* scene, std::vector<float>&& data);
		virtual ~Camera() = default;

		void ActorUpdate() override;

		void Active() override {}
		void Pause() override {}

		void AdjustCameraPos();

	};

}