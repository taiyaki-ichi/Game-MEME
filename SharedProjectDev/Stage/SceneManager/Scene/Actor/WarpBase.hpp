#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	class WarpBase : public ActorBase
	{
	public:
		enum class LightState {
			Bright,
			Dark,
			Changing
		};

	private:
		std::string mNameTag;

	protected:
		LightState mLightState;


	public:
		WarpBase(GameLib::Actor* scene);
		virtual ~WarpBase();

		const std::string& GetNameTag() const;

		//暗いなら明るく、明るいなら暗くする
		//Changingを経由
		virtual void ChangeLight() = 0;

		//一気に暗くまたわ明るく設定
		//mLightStateも忘れずに変更する
		virtual void SetDark() = 0;
		virtual void SetBright() = 0;

		const LightState& GetLightState() const {
			return mLightState;
		}

		//
		virtual const GameLib::Vector2& GetPosiotion() = 0;

	};
}