#pragma once

namespace Game
{
	namespace SceneFlag
	{
		constexpr unsigned int GO_STAGE_FLAG = 0b1;
		constexpr unsigned int GO_TITLE_FLAG = 0b10;
		constexpr unsigned int GO_STAGESELECT_FLAG = 0b100;
		
		//�X�e�[�W���N���A�����ꍇ��gStageData�ƏƂ炵���킹��SaveData��
		//�ύX����ꍇ������AOpenFlag�𗧂Ă�̂ŕ�
		constexpr unsigned int STAGE_CLAER_FLAG = 0b1000;
		constexpr unsigned int STAGE_MISS_FLAG = 0b10000;

		constexpr unsigned int SAVE_FLAG = 0b100000;
	}
}