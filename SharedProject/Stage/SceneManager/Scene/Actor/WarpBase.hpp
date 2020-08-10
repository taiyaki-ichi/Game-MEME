#pragma once
#include"StageActorBase.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{

	class WarpBase : public ActorBase
	{
	private:
		std::string mNameTag;
		std::string mDestinationNameTag;

	public:

		//�f�[�^�擾�p
		constexpr static char TYPE[] = "WarpType";
		constexpr static char NAMETAG[] = "NameTag";
		constexpr static char DESTINATION_NAMETAG[] = "DestinationNameTag";

		WarpBase(GameLib::Actor* scene);
		virtual ~WarpBase();

		const std::string& GetNameTag() const;

		//Warp�̎�Player�̈ړ��Ɏg�p
		virtual const GameLib::Vector2& GetPosition() const = 0;

		//Player�������ɔ��ł���Ƃ��̒ʒm�p
		virtual void PlayerWarpHere() {};

	protected:
		//Player��Warp�����Ƃ��Ăяo��
		void WarpPlayer();

		void SetNameTags(std::string&& my, std::string&& dedtiantion);

	};
}