#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include"Stage/Utilty/Dir4Vec.hpp"
#include"Stage/Utilty/PhysicsModel.hpp"

namespace Stage
{
	//Gravity�ɂ���ĕω��������ΓI�Ȍ������l�������֐�����

	//�����ƃT�C�Y����Vector2�𐶐�
	GameLib::Vector2 GetVector2(const Dir4& dir, float size);

	//Vector2��Dir4Vec�Ɋۂߍ���
	Dir4Vec GetDir4Vec(const GameLib::Vector2& vec);

	//Vector2��Dir4�����̑傫�����擾�A�}�C�i�X������
	float GetDir4DirectionSize(const GameLib::Vector2& vec, const Dir4& dir4);

	//Vector2�̐��������𔽓]
	GameLib::Vector2 GetVertialFlippedVector2(const GameLib::Vector2& vec);
	//vecor2�̐��������𔽓]
	GameLib::Vector2 GetHolizonalFlippedVector2(const GameLib::Vector2& vec);

	//�t���[��������̗͂̍��v��d�͂̕����𓥂܂��čX�V
	//maxSpeed�ȏ�̃X�s�[�h�Ȃ�␳�A-1�ł��̕����̍ő�l�͖���
	//isRotetio�͏d�͂̉�]�𔽉f�����邩�ǂ����B�����Ă��镨�̂Ȃǂ�false
	void UpdatePhysicsModelWithGravity(PhysicsModel& model, const GameLib::Vector2& power, float horizonMaxSpeed = -1.f, float virticalMaxSpeed = -1.f, bool isRotaion = true);

	//vec����dir�̌������傫��size�ɕύX���ꂽVector2��Ԃ�
	GameLib::Vector2 GetDirSizeSetVector2(const GameLib::Vector2& vec, const Dir4& dir, float size);

}