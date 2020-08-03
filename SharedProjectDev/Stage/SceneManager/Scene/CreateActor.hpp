#pragma once
#include<string>

namespace Stage
{
	class ActorBase;
	class Scene;
	class WarpBase;

	//Player以外をここで生成
	ActorBase* CreateStageActor(Scene* scene, std::string&& nameTag);

	//Warpはここで
	WarpBase* CreateStageWarp(Scene* scene, std::string&& warpType, std::string&& myNameTag, std::string&& destinationNameTag);

}