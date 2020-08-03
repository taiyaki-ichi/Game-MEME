#pragma once
#include<string>

namespace Stage
{
	class ActorBase;
	class Scene;

	//Player以外をここで生成
	ActorBase* CreateStageActor(Scene* scene, std::string&& nameTag);

}