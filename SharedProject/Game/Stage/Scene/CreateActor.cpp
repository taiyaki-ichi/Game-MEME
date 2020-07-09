#include"CreateActor.hpp"
#include"Actor/Ground.hpp"
#include"Actor/Camera.hpp"
#include"Actor/Triple.hpp"

#include<iostream>

namespace Game::Stage
{
	void CreateActor(Scene* scene, std::string&& actorName, std::vector<float>&& data)
	{


		////////////////////////////////////////////////////////////////////////////////////////////////
		//ここに追加していく
		////////////////////////////////////////////////////////////////////////////////////////////////
		

		if (actorName == "Ground")
			new Ground{ scene,std::move(data) };
		if (actorName == "Camera")
			new Camera{ scene,std::move(data) };
		if (actorName == "Triple") 
			new Triple::Actor{ scene,std::move(data) };
			


	}
}