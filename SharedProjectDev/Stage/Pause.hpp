#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace Stage
{
	class SceneManager;

	class Pause : GameLib::Actor
	{
		//画像などの表示


		SceneManager* mSceneManager;

	public:

		Pause(GameLib::Actor* stage,SceneManager* sceneManager);
		virtual ~Pause() = default;

		void CustomizeUpdate() override;

	};
}