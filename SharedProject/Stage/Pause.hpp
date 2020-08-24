#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Utilty/DrawFlameRect.hpp"
#include"GameLib/include/Draw/DrawFontText.hpp"

namespace Stage
{
	class SceneManager;

	class Pause : GameLib::Actor
	{
		//�摜�Ȃǂ̕\��

		DrawFlameRect mFlameRect;

		SceneManager* mSceneManager;

		GameLib::DrawFontText mText;

	public:

		Pause(GameLib::Actor* stage,SceneManager* sceneManager);
		virtual ~Pause() = default;

		void CustomizeUpdate() override;

	};
}