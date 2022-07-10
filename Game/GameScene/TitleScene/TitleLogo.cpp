#include"TitleLogo.hpp"
#include"TitleLogoParam.hpp"

namespace Game
{
	TitleLogo::TitleLogo(const GameLib::Vector2& pos)
		:mIcon{"../Assets/Player/icon.png"}
		, mEngText{ L"../Assets/Font/mplus-1c-black.ttf" }
		, mJpnText{ L"../Assets/Font/mplus-1c-black.ttf" }
	{
		using namespace TitleLogParam;

		mEngText.SetPosition(pos + ENG_TEXT_ADJUST);
		mEngText.SetSize(GameLib::Font::Size::Size_72);
		mEngText.SetText("MEME");

		mJpnText.SetPosition(pos + JPN_TEXT_ADJUST);
		mJpnText.SetSize(GameLib::Font::Size::Size_24);
		mJpnText.SetText("����");

		mIcon.SetScale(ICON_SCALE);
		mIcon.SetPosition(pos + ICON_ADJUST);
	}
}