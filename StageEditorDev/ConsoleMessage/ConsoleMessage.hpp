#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace StageEditor
{
	class ConsoleMessage : public GameLib::Actor
	{

		std::vector<std::string> mMessage;

		void RunGetMessageThread();

	public:
		ConsoleMessage(GameLib::Actor* editor);
		virtual ~ConsoleMessage() = default;

		void CustomizeUpdate() override;

		//���b�Z�[�W�̎擾�A��{size=0�Ȋ���
		const std::vector<std::string>& GetMessage() const;

		//���b�Z�[�W���N���A
		void ClearMessage();
	};
}