#pragma once
#include<vector>
#include"DrawTexture.hpp"

namespace GameLib
{
	class DrawAnimation : public DrawTexture
	{
		using Animation = std::vector<Texture*>;
		std::vector<Animation> mAnimations;

		int mCurrentChannel;

		float mAnimationFPS;

		double mCurrectFrame;

	public:
		DrawAnimation(float animFPS, const Vector2& pos = { 0.f,0.f }, float scale = 1.f, float rot = 0.f, int drawOrder = 0);
		virtual ~DrawAnimation() = default;

		//�ǉ��������Ƀ`�����l�������Ă���
		void AddAnimation(std::vector<std::string>&& fileNames);

		//Actor��CusutomUpdate�Ŗ��t���[���Ăяo��
		void Update(float gameFPS = 60.f);

		void SetChannel(int channel);
		void SetAnimationFPS(float animFPS);

	};
}