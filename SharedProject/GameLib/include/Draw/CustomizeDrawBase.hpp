#pragma once
#include"DrawBase.hpp"

namespace GameLib
{

	class CustomizeDrawBase : public DrawBase
	{
	public:
		CustomizeDrawBase(int drawOrder = 0);
		virtual ~CustomizeDrawBase() = default;

		//Draw�Ȃ��ŕ`�ʂ���ꍇ
		//DrawBase��IsAutoDrawing��False�ɂ��Ă���
		void Draw() override {};

	protected:
		//���ꂼ���Draw�̑O�Ɏg�p����
		//�`�ʂ���͈͂��w�肷��
		void SetUpAndDrawRange();
		//�`�ʂ��Ȃ��͈͂��w�肷��
		void SetUpNotDrawRange();
		//�ʏ�̕`��
		void SetUpStanderdDraw();


		//�`�ʂ���͈͂�0�Ń��Z�b�g����
		void ResetDrawRangeZero();

	};

}