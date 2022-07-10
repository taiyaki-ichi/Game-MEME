#include"SavedParts.hpp"
#include"ClearSceneFlag.hpp"
#include"GameLib/include/InputState/InputState.hpp"

namespace Game
{
	SavedParts::SavedParts(GameLib::Actor* actor)
		:ClearScenePartsBase{ actor }
		, mSaved{ "../Assets/Font/mplus-1c-black.ttf" }
	{
		mSaved.SetText("�Z�[�u�����傤�I");
		mSaved.SetSize(GameLib::Font::Size::Size_24);
	}

	void SavedParts::CustomizeUpdate()
	{
		if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
			UpFlag(ClearSceneFlag::GO_TITLE_FLAG);
	}
}