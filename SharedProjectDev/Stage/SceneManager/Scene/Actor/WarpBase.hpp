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

		//�f�[�^�擾�p
		constexpr static char TYPE[] = "Type";
		constexpr static char NAMETAG[] = "NameTag";
		constexpr static char DESTINATION_NAMETAG[] = "DestinationNameTag";


		WarpBase(GameLib::Actor* scene);
		virtual ~WarpBase();

		const std::string& GetNameTag() const;

		//�Â��Ȃ疾�邭�A���邢�Ȃ�Â�����
		//Changing���o�R
		virtual void ChangeLight() = 0;

		//��C�ɈÂ��܂��햾�邭�ݒ�
		//mLightState���Y�ꂸ�ɕύX����
		virtual void SetDark() = 0;
		virtual void SetBright() = 0;

		const LightState& GetLightState() const {
			return mLightState;
		}

		//
		virtual const GameLib::Vector2& GetPosiotion() = 0;

	};
}