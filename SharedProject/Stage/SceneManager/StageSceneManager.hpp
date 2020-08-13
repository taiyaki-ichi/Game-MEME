#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<vector>
#include"Scene/ActorInfo.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	class Scene;
	class WarpBase;
	class Player;

	class SceneManager : public GameLib::Actor
	{

		//Warp�ւ̎Q��
		std::vector<WarpBase*> mWarpBases;

		Player* mPlayer;

		char mFlags;


	public:

		SceneManager(GameLib::Actor* stage,int playerLifeNum,int playerGemNum);
		virtual ~SceneManager() = default;

		//PLayer�̃��[�v
		void CustomizeUpdate()override;

		void CreateScene(std::vector<std::vector<ActorInfo>>&& stageData);

		void AddWarpBase(WarpBase* warp);
		void RemoveWarpBase(WarpBase* warp);

		const GameLib::Vector2& GetPlayerPos() const;

		void Warp(WarpBase* prevWarpBase, const std::string& nextNameTag);

		bool CheckFlag(char);

	};
}