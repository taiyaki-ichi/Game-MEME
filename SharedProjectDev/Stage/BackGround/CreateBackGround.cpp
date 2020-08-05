#include"CreateBackGround.hpp"
#include"Parts/Horizon.hpp"
#include"Parts/Object/BackGroundTree.hpp"
#include"Stage/WindowSize.hpp"

namespace Stage::BackGround
{
	void CreateSharpTreeForest(GameLib::Actor* owner)
	{
		new Horizon{ owner };

		//��
		int num;
		//�Ԋu
		float w;
		//���R�̗]��
		float marginX;
		//�^�e�̍��W
		float lineY;

		marginX = 100.f;
		lineY = 200.f;
		num = 5;
		w = (WindowSize::WIDTH + marginX * 2.f) / num;
		for (int i = 0; i < num; i++) {
			auto ptr = new SharpTree230{ owner };
			ptr->SetPosition(GameLib::Vector2{ w / 2.f + w * i,lineY });
			ptr->SetMarginXY(marginX, -1.f);
		}

		marginX = 100.f;
		lineY = 140.f;
		num = 4;
		w = (WindowSize::WIDTH + marginX * 2.f) / num;
		for (int i = 0; i < num; i++) {
			auto ptr = new SharpTree180{ owner };
			ptr->SetPosition(GameLib::Vector2{ w / 2.f + w * i,lineY });
			ptr->SetMarginXY(marginX, -1.f);
		}

		marginX = 150.f;
		lineY = 90.f;
		num = 4;
		w = (WindowSize::WIDTH + marginX * 2.f) / num;
		for (int i = 0; i < num; i++) {
			auto ptr = new SharpTree130{ owner };
			ptr->SetPosition(GameLib::Vector2{ w / 2.f + w * i,lineY });
			ptr->SetMarginXY(marginX, -1.f);
		}
	}
}