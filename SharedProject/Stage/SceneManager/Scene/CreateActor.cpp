#include"CreateActor.hpp"
#include<functional>
#include"StageScene.hpp"
#include"Actor/Ground.hpp"
#include"Actor/Camera.hpp"
#include"Actor/WarpBase.hpp"
#include"Actor/GuruWarp.hpp"
#include"Actor/GravityBox.hpp"
#include"Actor/Triple.hpp"
#include"Actor/Toge.hpp"
#include"Actor/Bee.hpp"
#include"Actor/Goal.hpp"
#include"Actor/Gem.hpp"
#include"Actor/Blinder.hpp"
#include"Actor/TearGem.hpp"
#include"Actor/Frog.hpp"
#include"Actor/ThroughFloor.hpp"
#include"Actor/MoveGround.hpp"
#include"Actor/Carrot.hpp"
#include"Actor/Dogu.hpp"

namespace Stage
{
	namespace {

		//Actor����
		const std::unordered_map<std::string, std::function<ActorBase* (Scene*)>> ActorPtrGenerator =
		{
			{"Ground",[](Scene* scene) {return new GroundGenerator{scene}; }},
			{"Camera",[](Scene* scene) {return new Camera{scene}; }},
			{"GravityBox2",[](Scene* scene) {return new GravityBox{scene,2}; }},
			{"GravityBox4",[](Scene* scene) {return new GravityBox{scene,4}; }},
			{"Triple",[](Scene* scene) {return new Triple{scene}; }},
			{"Toge",[](Scene* scene) {return new Toge{scene}; }},
			{"StraightBee",[](Scene* scene) {return new Bee{scene}; }},
			{"CircleBee",[](Scene* scene) {return new Bee{scene}; }},
			{"GuruWarp",[](Scene* scene) {return new GuruWarp{scene}; }},
			{"DownGoal",[](Scene* scene) {return new Goal{scene,Dir4::Down}; }},
			{"UpGoal",[](Scene* scene) {return new Goal{scene,Dir4::Up}; }},
			{"RightGoal",[](Scene* scene) {return new Goal{scene,Dir4::Right}; }},
			{"LeftGoal",[](Scene* scene) {return new Goal{scene,Dir4::Left}; }},
			{"Gem",[](Scene* scene) {return new Gem{scene}; }},
			{"Blinder",[](Scene* scene) {return new Blinder{scene}; }},
			{"TearGem",[](Scene* scene) {return new TearGem{scene}; }},
			{"Frog",[](Scene* scene) {return new Frog{scene}; }},
			{"ThroughFloor",[](Scene* scene) {return new ThroughFloor{scene}; }},
			{"MoveGround",[](Scene* scene) {return new MoveGround{scene}; }},
			{"Carrot",[](Scene* scene) {return new Carrot{scene}; }},
			{"Dogu",[](Scene* scene) {return new Dogu{scene}; }}


		};

	}






	ActorBase* CreateStageActor(Scene* scene, std::string&& name)
	{
		auto i = ActorPtrGenerator.find(name);
		if (i != ActorPtrGenerator.end())
			return i->second(scene);

		return nullptr;

	}

}