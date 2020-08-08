#pragma once
#include<string>
#include<unordered_map>

namespace Stage
{
	class ActorBase;
	class Scene;
	class WarpBase;

	//Player以外をここで生成
	ActorBase* CreateStageActor(Scene* scene, std::string&& nameTag);



}