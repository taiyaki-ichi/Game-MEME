#pragma once
#include<string>

namespace Stage
{
	class ActorBase;
	class Scene;

	//Player�ȊO�������Ő���
	ActorBase* CreateStageActor(Scene* scene, std::string&& nameTag);

}