#pragma once
#include<vector>
#include<memory>

namespace GameLib
{
	//���ꂼ��̊��N���X
	class DrawBase
	{
		int mDrawOrder;
		//�����ŕ`�悷�邩�ǂ���
		bool  mIsAutoDrawing;

	public:
		DrawBase(int drawOrder = 0);
		virtual ~DrawBase();

		virtual void SetUpDraw() {};
		virtual void Draw() = 0;

		int GetDrawOrder()const noexcept;
		void SetDrawOrder(int order);

		bool GetIsAutoDrawing();
		void SetIsAutoDrawing(bool i);
	};
}