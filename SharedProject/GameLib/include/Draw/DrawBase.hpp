#pragma once

namespace GameLib
{
	//���ꂼ��̊��N���X
	class DrawBase
	{
		int mDrawOrder;
		//�`�悷�邩�ǂ���
		bool  mIsDrawing;

	public:
		DrawBase(int drawOrder = 0);
		virtual ~DrawBase();

		virtual void Draw() = 0;

		int GetDrawOrder()const noexcept;
		void SetDrawOrder(int order);

		bool GetIsDrawing();
		void SetIsDrawing(bool i);
	};
}