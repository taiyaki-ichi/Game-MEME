#pragma once
#include<string>
#include<memory>
#include<d3d9.h>
#include"GameLib/include/Resource/Texture.hpp"


namespace GameLib
{

	bool InitGraphics();
	void ShutdownGraphics();

	class TextureImpl : public Texture
	{
	public:
		TextureImpl(LPDIRECT3DTEXTURE9 ptr,float w,float h);
		~TextureImpl();

		TextureImpl operator=(TextureImpl&) = delete;
		TextureImpl(TextureImpl&) = delete;

		LPDIRECT3DTEXTURE9 GetPtr() const { return mPtr; }
		float GetWidth() const noexcept override { return mWidth; }
		float GetHeight() const noexcept override { return mHeight; }

	private:
		LPDIRECT3DTEXTURE9 mPtr;
		float mWidth;
		float mHeight;
	};


	Texture* LoadTexture(const std::string& fileName);


	//flip=1�@�����ɔ��]�@flip=2 �����ɔ��] filp=3�͗���
	void GraphicsDrawTexture(Texture* texture, float posX, float posY, float scale, float rot, int alpha = 255, int flip = 0);
	//��_�̍��W�ARGB�ƃA���t�@��0-255
	void GraphicsDrawLine(float aX, float aY, float bX, float bY, int r, int g, int b, int alpha = 255);

	void GraphicsDrawFillTriangle(float aX, float aY, float bX, float bY, float cX, float cY, int r, int g, int b, int alpha = 255);
	void GraphycsDrawFillRect(float centerX, float centerY, float width, float heiht, float scale, float rot, int r, int g, int b, int alpha = 255);

	void GraphycsDrawFillCircle(float centerX, float centerY, float radius, int r, int g, int b, int alpha = 255);

	//�X�e���V���o�b�t�@�̏�����,num�ŏ������A��{�I�ɂ͂P����
	void ClearStencilBuffer(DWORD num);
	//����ʂ��͈͂�`�ʂ���O�Ɏg�p
	void SetMaskStencilBufferState(DWORD num);
	//���ʂɕ`�ʂ���O�Ɏg�p
	void SetStanderdStencilBufferState();

	//�`�ʂ̊J�n�ƏI�����Ɏg�p
	void DrawStart();
	void DrawEnd();
	
	
}
