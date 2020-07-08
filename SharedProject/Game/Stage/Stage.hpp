#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include<unordered_map>

namespace Game::Stage
{
	class Scene;
	namespace Player {
		class Actor;
	}

	class Stage : public GameLib::Actor
	{
		//Stage�ɏ�������Scene�ւ̎Q��
		std::unordered_map<std::string, Scene*> mStageScenes;

		Player::Actor* mPlayer;

	public:
		Stage(GameLib::Actor* owner,std::string&& fileName);
		virtual ~Stage() = default;

		void CustomizeUpdate() override;

		void SceneActive(std::string& sceneName);
		void ScenePause(std::string& sceneName);

		//CreateStage�Ŏg�p
		Scene* AddScene(std::string&& sceneName);

		//CreateStage�Ŏg�p
		void SetPlayer(Player::Actor* player);

		const GameLib::Vector2& GetPlayerPos();
	};
}