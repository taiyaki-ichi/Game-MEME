#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"Stage/Ground.hpp"
#include"Stage/Character/Player.hpp"
#include"Game/Stage/Character/Enemy/Toge.hpp"

namespace Game
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor()
			:RootActor()
		{
			new Stage::Ground(this,{ 0.f,-250.f }, 600.f, 100.f);
			new Stage::Ground(this, { 0.f,250.f }, 600.f, 100.f);
			new Stage::Ground(this, { 350.f,0.f }, 100.f, 600.f);
			new Stage::Ground(this, { -350.f,0.f }, 100.f, 600.f);
			new Stage::Ground(this, { 0.f,-150.f }, 100.f, 100.f);
			
			new Stage::Player(this);

			//new Stage::Triple::Actor{ this ,GameLib::Vector2{200.f,0.f} };
			//new Stage::Triple::Actor{ this ,GameLib::Vector2{-100.f,0.f} };

			new Stage::Toge::Actor(this, { 100.f,0.f });
		}

		virtual ~StartActor() = default;
	};
}