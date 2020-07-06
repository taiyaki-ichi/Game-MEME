#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace StageEditor
{
	//��������Ȃ�
	class ClickManager : public GameLib::Actor
	{
		//�t���[�������Ȃ���2��N���b�N���ꂽ��DoubleClick�Ƃ��ĔF��
		//��������N���b�N!!!!
		constexpr static int DOUBLE_CLICK_TIME = 60;
		static int mCnt;

		static bool mClickedFlag;
		static bool mDoubleClickedFlag;

	public:
		ClickManager(GameLib::Actor* owner);
		virtual ~ClickManager() = default;

		void CustomizeUpdate() override;

		static bool Clicked();
		static bool DoubleClicked();
	};
}