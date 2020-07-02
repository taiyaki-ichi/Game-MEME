#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"Tohoho.hpp"

namespace Game
{
	class StartActor : public GameLib::RootActor
	{
	public:
		StartActor();
		virtual ~StartActor() = default;

		void CustomizeUpdate() override;

	private:
		Tohoho mTohoho;
	};
}