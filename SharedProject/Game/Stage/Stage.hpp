#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include<unordered_map>
#include<vector>
#include<optional>

namespace Game::Stage
{
	class Scene;
	namespace Player {
		class Actor;
	}
	class WarpBase;

	class Stage : public GameLib::Actor
	{
		//Stage�ɏ�������Scene�ւ̎Q��
		std::vector<Scene*> mStageScenes;
		Scene* mNowScene;
		
		std::vector<WarpBase*> mWarpGates;

		Player::Actor* mPlayer;

		int mFlag;

	public:
		Stage(GameLib::Actor* owner, std::string&& fileName, bool isDebug = false);
		virtual ~Stage() = default;

		void CustomizeUpdate() override;

		//CreateStage�Ŏg�p
		Scene* AddScene(std::string&& sceneName);

		//CreateStage�Ŏg�p�APlayer�̓o�^�ƃX�^�[�g�m��V�[���̗���
		void SetPlayerAndNowScene(Player::Actor* player,Scene* scene);

		const GameLib::Vector2& GetPlayerPos();
		void ResetPlayerPos(const GameLib::Vector2& pos);

		void AddWarpGate(WarpBase* warp);
		void RemoveWarpGate(WarpBase* warp);

		//����WarpGate��NameTag���w�肷��B���]���@���w�肵����
		void PlayerWarp(const std::string& destinationNameTag);

		void PlayerAcitve();
		void PlayerPause();

		//-1�͎��s�A1�ŃN���A,2�̓|�[�Y����
		int GetStateFlag();
	};
}