#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<string>

namespace StageEditor
{
	class EditingActorBase;

	class InfoBase : public GameLib::Actor
	{
		enum class InfoState {
			Stay,
			Editing,
			Confirmed,
		};

		//Vector2�Ƃ�float��Dir2�Ƃ�
		std::string mInfoType;

		//Pos�Ƃ�Color�Ƃ�
		std::string mInfoName;

		InfoState mInfoState;


		virtual void PrintInfo() = 0;

	protected:
		//�����l��������Ăяo��
		void InfoConfirmed();

	public:
		InfoBase(EditingActorBase* owner, std::string&& infoType, std::string&& infoName);
		virtual ~InfoBase() = default;

		void CustomizeUpdate() override final;
		//���̌�����@�ƏI�������iInfoConfirmed���Ăԁj
		virtual void EditingInfoUpdate() = 0;

		//InfoState��Confirmed���ǂ���
		bool IsOK();

		//���̕\��
		void Print();

		//json�ւ̏o�͗p�֐��A���Ƃ�
		//void hoge()=0;
	};
}