#pragma once
#include<string>
#include<unordered_map>

namespace GameLib
{
	class Texture;
	class Font;

	class ResourceManager
	{
		static std::unordered_map<std::string, Texture*> mTextures;
		static std::unordered_map<std::wstring, Font*> mFonts;

	public:
		static Texture* GetTexture(const std::string& fileName);
		static Texture* GetTexture(std::string&& fileName);

		static Font* GetFont(const std::wstring& fileName);
		static Font* GetFont(std::wstring&& fileName);

		static void ReleaseResources();
	};
}