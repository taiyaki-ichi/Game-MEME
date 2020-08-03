#pragma once
#include<string>

namespace Stage
{
	class ActorBase;
	class Scene;
	class WarpBase;

	//Player�ȊO�������Ő���
	ActorBase* CreateStageActor(Scene* scene, std::string&& nameTag);

	//Warp�͂�����
	WarpBase* CreateStageWarp(Scene* scene, std::string&& warpType, std::string&& myNameTag, std::string&& destinationNameTag);

}