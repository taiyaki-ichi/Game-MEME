#pragma once
#include"Actor.hpp"

namespace GameLib
{

	//Appに渡す用のOwnerのいないActor
	class RootActor : public Actor
	{
	public:
		RootActor();
		virtual ~RootActor();

	};
}