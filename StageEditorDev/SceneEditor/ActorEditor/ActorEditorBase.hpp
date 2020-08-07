#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Data/Data.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"ActorData.hpp"

namespace StageEditor
{


	class ActorEditorBase : public GameLib::Actor
	{
	protected:
		Data<GameLib::Vector2> mPosData;
		Data<std::string> mStringData;

	private:
		//この名前でJsonに記述される
		std::string mNameTag;

	public:
		ActorEditorBase(GameLib::Actor* actor, std::string&& nameTage, int posDataNum, int stringDataNum);
		virtual ~ActorEditorBase() = default;

		bool IsOK();

		void AddData(GameLib::Vector2&& pos);
		void AddData(std::string&& str);

		void PrintStringData();

		virtual void BeginWorking() = 0;
		virtual void BeginToRest() = 0;

		ActorData GetData();
	};


}