#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<vector>

namespace Game::Stage
{
	class Stage;
	class ActorBase;

	class Scene : public GameLib::Actor
	{
		//Sceneに属しているActorへの参照
		std::vector<ActorBase*> mStageActors;

	public:
		Scene(Stage* stage, int updateOrder = 0);
		virtual ~Scene() = default;

		void Active();
		void Pause();

		void AddStageActor(ActorBase* actor);
		void RemoveStageActor(ActorBase* actor);
	};
}