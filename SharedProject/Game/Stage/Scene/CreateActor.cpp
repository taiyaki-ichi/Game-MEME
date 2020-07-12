#include"CreateActor.hpp"
#include"Actor/Ground.hpp"
#include"Actor/Camera.hpp"
#include"Actor/Triple.hpp"
#include"Actor/GravityBox.hpp"

#include<iostream>

namespace Game::Stage
{
	void CreateActor(Scene* scene, std::string&& actorName, std::vector<float>&& data)
	{


		////////////////////////////////////////////////////////////////////////////////////////////////
		//�����ɒǉ����Ă���
		////////////////////////////////////////////////////////////////////////////////////////////////
		

		if (actorName == "Ground")
			CreateGround(scene, std::move(data));
		if (actorName == "Camera")
			new Camera{ scene,std::move(data) };
		if (actorName == "Triple") 
			new Triple::Actor{ scene,std::move(data) };
		if (actorName == "GravityBox")
			new GravityBox{ scene,std::move(data) };


	}
}