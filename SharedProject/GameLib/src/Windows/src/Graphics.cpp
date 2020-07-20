#include"../Graphics.hpp"
#include"WindowClassName.hpp"
#include<vector>

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<cmath>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include<iostream>


namespace GameLib
{

	namespace {
		LPDIRECT3D9 g_D3DInterface;
		LPDIRECT3DDEVICE9 g_D3DDevice;
	}


	bool InitGraphics()
	{
		D3DPRESENT_PARAMETERS present_param;
		ZeroMemory(&present_param, sizeof(D3DPRESENT_PARAMETERS));

		// �C���^�[�t�F�[�X�쐬
		g_D3DInterface = Direct3DCreate9(D3D_SDK_VERSION);
		if (g_D3DInterface == NULL)
		{
			// �쐬���s
			std::cout << "Direct3DCreate9 is failed\n";
			return false;
		}

		// �o�b�N�o�b�t�@�̐� => 1
		present_param.BackBufferCount = 1;
		// �o�b�N�o�b�t�@�̃t�H�[�}�b�g => D3DFMT_UNKNOWN(�t�H�[�}�b�g��m��܂���)
		present_param.BackBufferFormat = D3DFMT_UNKNOWN;
		// �E�B���h�E���[�h�ݒ� => �萔�Ő؂�ւ�
		present_param.Windowed = true;

		// �X���b�v�G�t�F�N�g => �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�ւ̐؂�ւ����@
		present_param.SwapEffect = D3DSWAPEFFECT_DISCARD;

		//�X�e���V���o�b�t�@
		present_param.EnableAutoDepthStencil = TRUE;
		present_param.AutoDepthStencilFormat = D3DFMT_D24S8;

		// DirectDevice�̍쐬
		if (FAILED(g_D3DInterface->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			FindWindowA(WINDOW_CLASS_NAME, nullptr),
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
			&present_param,
			&g_D3DDevice)))
		{
			std::cout << "CreateDevice is failed\n";
			return false;
		}

		g_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		g_D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		g_D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		g_D3DDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
		g_D3DDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
		g_D3DDevice->SetRenderState(D3DRS_ALPHAREF, 0x01);

		g_D3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
		g_D3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		g_D3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_CURRENT);

		// ���e�N�X�`���X�e�[�W�F�A���t�@�v�f�̐ݒ�
		g_D3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
		g_D3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
		g_D3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);

		// �r���[�|�[�g�p�����[�^
		D3DVIEWPORT9 view_port;

		// �r���[�|�[�g�̍�����W
		view_port.X = 0;
		view_port.Y = 0;
		// �r���[�|�[�g�̕�
		view_port.Width = present_param.BackBufferWidth;
		// �r���[�|�[�g�̍���
		view_port.Height = present_param.BackBufferHeight;
		// �r���[�|�[�g�[�x�ݒ�
		view_port.MinZ = 0.0f;
		view_port.MaxZ = 1.0f;

		// �r���[�|�[�g�ݒ�
		if (FAILED(g_D3DDevice->SetViewport(&view_port)))
		{
			std::cout << "SetViewport is failed\n";
			return false;
		}

		return true;
	}

	void ShutdownGraphics()
	{
		if (g_D3DInterface)
			g_D3DInterface->Release();
		if (g_D3DDevice)
			g_D3DDevice->Release();
	}


	TextureImpl::TextureImpl(LPDIRECT3DTEXTURE9 ptr, float w, float h)
		:Texture()
		,mPtr(std::move(ptr))
		,mWidth(w)
		,mHeight(h)
	{
	}

	TextureImpl::~TextureImpl()
	{
		if (mPtr)
			mPtr->Release();
	}


	Texture* LoadTexture(const std::string& fileName)
	{
		
		LPDIRECT3DTEXTURE9 tex;
		D3DXIMAGE_INFO info;

		// 2�̗ݏ悶��Ȃ��P�[�X��z�肵�Č��̃T�C�Y���擾����D3DXCreateTextureFromFileEx�Ŏg��
		D3DXGetImageInfoFromFileA(fileName.c_str(), &info);

		if (FAILED(D3DXCreateTextureFromFileExA(g_D3DDevice,
			fileName.c_str(),
			info.Width,
			info.Height,
			1,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0x0000ff00,
			nullptr,
			nullptr,
			&tex)
		))
		{
			std::cout << "CreateTexture is failed : " << fileName << "\n";
			return nullptr;
		}
		else
		{
			// �e�N�X�`���T�C�Y�̎擾
			D3DSURFACE_DESC desc;

			if (FAILED(tex->GetLevelDesc(0, &desc)))
			{
				std::cout << "GetLevelDesc is failed : " << fileName << "\n";
				return nullptr;
			}

			return new TextureImpl(tex, static_cast<float>(desc.Width), static_cast<float>(desc.Height));
		}

	}

	FontImpl::FontImpl(std::unordered_map<int, LPD3DXFONT>&& font)
		:Font{}
		, mFont{std::move(font)}
	{
	}

	FontImpl::~FontImpl()
	{
		for (auto ptr : mFont) {
			ptr.second->Release();
		}
	}

	LPD3DXFONT FontImpl::GetPtr(const Size& size)
	{
		auto iter = mFont.find(static_cast<int>(size));
		if (iter != mFont.end())
			return iter->second;
		else
			return nullptr;
	}

	LPD3DXFONT FontImpl::GetPtr(Size&& size)
	{
		auto iter = mFont.find(static_cast<int>(size));
		if (iter != mFont.end())
			return iter->second;
		else
			return nullptr;
	}

	Font* LoadFont(const std::string& fileName)
	{

		std::unordered_map<int, LPD3DXFONT> font;
		for (auto& size: Font::GetAllSize())
		{
			LPD3DXFONT tmp = nullptr;
			if (FAILED(D3DXCreateFont(
				g_D3DDevice,                /* �f�o�C�X */
				static_cast<int>(size),                            /* �����̍��� */
				0,                            /* ������ */
				FW_NORMAL,                    /* �t�H���g�̑��� */
				1,                            /* MIPMAP�̃��x�� */
				FALSE,                        /* �C�^���b�N���H */
				DEFAULT_CHARSET,            /* �����Z�b�g */
				OUT_DEFAULT_PRECIS,            /* �o�͐��x */
				DEFAULT_QUALITY,            /* �o�͕i�� */
				DEFAULT_PITCH | FF_SWISS,    /* �t�H���g�s�b�`�ƃt�@�~�� */
				fileName.c_str(),                    /* �t�H���g�� */
				&tmp))) {        /* Direct3D�t�H���g�ւ̃|�C���^�ւ̃A�h���X */

				std::cout << "FontName: " << fileName << "size: " << static_cast<int>(size) << " is failed\n";
			}
			else {
				font.emplace(static_cast<int>(size), tmp);
			}
		}

		return new FontImpl{ std::move(font) };
	}

	//��ɐ}�`�p
	struct SIMPLE_VERTEX
	{
		float x, y, z, rhw;

		DWORD color;

	};

	//�e�N�X�`���Ƃ��p
	struct TEXTURE_VERTEX
	{
		float x, y, z, rhw;

		DWORD color;

		// �e�N�X�`�����W(��)
		float tu;
		// �e�N�X�`�����W(�c)
		float tv;

	};

	void GetRectPoints(float points[4][2],float centerX, float centerY, float width, float heiht, float scale, float rot)
	{
		float halfWidth = width * scale / 2.f;
		float halfHeigth = heiht * scale / 2.f;

		float point[4][2] = {
			{ -halfWidth, -halfHeigth},
			{ halfWidth, -halfHeigth},
			{ halfWidth, halfHeigth},
			{ -halfWidth, halfHeigth}
		};

		for (int i = 0; i < 4; i++) {
			points[i][0] = point[i][0] * std::cos(-rot) - point[i][1] * std::sin(-rot) + centerX;
			points[i][1] = point[i][0] * std::sin(-rot) + point[i][1] * std::cos(-rot) + centerY;
		}

	}



	void GraphicsDrawTexture(Texture* texture, float posX, float posY, float scale, float rot, int alpha, int flip)
	{
		if (texture)
		{
			auto color = D3DCOLOR_ARGB(alpha, 255, 255, 255);

			float rotAndMovePoint[4][2];
			GetRectPoints(rotAndMovePoint, posX, posY, texture->GetWidth(), texture->GetHeight(), scale, rot);

			bool h = flip == 1 || flip == 3;
			bool v = flip == 2 || flip == 3;
			TEXTURE_VERTEX TriangleFan[] = {
				{ rotAndMovePoint[0][0], rotAndMovePoint[0][1],0.f, 1.f ,color,(h ? 1.f : 0.f),(v ? 1.f : 0.f)},
				{ rotAndMovePoint[1][0], rotAndMovePoint[1][1],0.f, 1.f ,color,(h ? 0.f : 1.f),(v ? 1.f : 0.f)},
				{ rotAndMovePoint[2][0], rotAndMovePoint[2][1],0.f, 1.f ,color,(h ? 0.f : 1.f),(v ? 0.f : 1.f)},
				{ rotAndMovePoint[3][0], rotAndMovePoint[3][1],0.f, 1.f ,color,(h ? 1.f : 0.f),(v ? 0.f : 1.f)},
			};

			TextureImpl* tex = (TextureImpl*)(texture);
			// ���_�\���̎w��
			g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE| D3DFVF_TEX1 );
			g_D3DDevice->SetTexture(0, tex->GetPtr());
			g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, TriangleFan, sizeof(TEXTURE_VERTEX));


		}
	}


	void GraphicsDrawLine(float aX, float aY, float bX, float bY, int r, int g, int b, int alpha)
	{
		auto color = D3DCOLOR_ARGB(alpha, r, g, b);
		SIMPLE_VERTEX p[] = {
			{aX,aY,0.f,1,color},
			{bX,bY,0.f,1,color},
		};

		g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
		g_D3DDevice->SetTexture(0, nullptr);
		g_D3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, 1, p, sizeof(SIMPLE_VERTEX));
	}

	void GraphicsDrawFillTriangle(float aX, float aY, float bX, float bY, float cX, float cY, int r, int g, int b, int alpha)
	{
		auto color = D3DCOLOR_ARGB(alpha, r, g, b);
		SIMPLE_VERTEX p[] = {
			{aX,aY,0.f,1,color},
			{bX,bY,0.f,1,color},
			{cX,cY,0.f,1,color}
		};

		g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
		g_D3DDevice->SetTexture(0, nullptr);
		g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 1, p, sizeof(SIMPLE_VERTEX));
	}

	void GraphycsDrawRect(float centerX, float centerY, float width, float heiht, float scale, float rot, int r, int g, int b, int alpha,bool isFill)
	{
		float points[4][2];
		GetRectPoints(points, centerX, centerY, width, heiht, scale, rot);

		auto color = D3DCOLOR_ARGB(alpha, r, g, b);
		SIMPLE_VERTEX p[5];
		for (int i = 0; i < 4; i++)
			p[i] = SIMPLE_VERTEX{ points[i][0],points[i][1],0.f,1,color };
		p[4] = p[0];

		g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
		g_D3DDevice->SetTexture(0, nullptr);

		if (isFill)
			g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, p, sizeof(SIMPLE_VERTEX));
		else
			g_D3DDevice->DrawPrimitiveUP(D3DPT_LINESTRIP, 4, p, sizeof(SIMPLE_VERTEX));
	}

	void GraphycsDrawCircle(float centerX, float centerY, float radius, int r, int g, int b, int alpha, bool isFill)
	{
		auto color = D3DCOLOR_ARGB(alpha, r, g, b);

		const int pointNum = 50;
		SIMPLE_VERTEX p[pointNum];

		
		//p[0] = SIMPLE_VERTEX{ radius * std::cos(-3.1415f * 2.f / pointNum) + centerX, radius * std::sin(-3.1415f * 2.f / pointNum) + centerY,0.f,1,color };
		for (int i = 0; i < pointNum-1; i++)
			p[i] = SIMPLE_VERTEX{ radius * std::cos(3.1415f * 2.f / pointNum * i) + centerX, radius * std::sin(3.1415f * 2.f / pointNum * i) + centerY,0.f,1,color };
		p[pointNum - 1] = SIMPLE_VERTEX{ radius + centerX,centerY,0.f,1,color };
		g_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
		g_D3DDevice->SetTexture(0, nullptr);
		if (isFill)
			g_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, pointNum - 2, p, sizeof(SIMPLE_VERTEX));
		else
			g_D3DDevice->DrawPrimitiveUP(D3DPT_LINESTRIP, pointNum - 1, p, sizeof(SIMPLE_VERTEX));
		
	}

	void GraphycsDrawText(Font* font, const Font::Size& size, const std::string& tex, float cX, float cY, int r, int g, int b, int alpha)
	{
		auto fontImpl = static_cast<FontImpl*>(font);
		LPD3DXFONT ptr = fontImpl->GetPtr(size);
		if (ptr) {
			int s = static_cast<int>(size);

			float width = s * tex.size();
			float height = s;

			RECT rect = {
				static_cast<LONG>(cX - width / 2.f),
				static_cast<LONG>(cY - height / 2.f),
				static_cast<LONG>(cX + width / 2.f),
				static_cast<LONG>(cY + height / 2.f)
			};
			auto color = D3DCOLOR_ARGB(alpha, r, g, b);
			ptr->DrawTextA(NULL, tex.c_str(), -1, &rect, DT_CENTER | DT_NOCLIP, color);

		}

	}

	void ClearStencilBuffer(DWORD num)
	{
		g_D3DDevice->Clear(0, nullptr, D3DCLEAR_STENCIL, D3DCOLOR_ARGB(255, 255, 255, 255), 1.0f, num);
	}

	void SetMaskStencilBufferState(DWORD num)
	{
		// �X�e���V���o�b�t�@�ݒ� => �L��
		g_D3DDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);

		// �X�e���V���o�b�t�@�֕`�����ގQ�ƒl�ݒ�
		g_D3DDevice->SetRenderState(D3DRS_STENCILREF, num);

		// �}�X�N�ݒ� => 0xff(�S�Đ^)
		g_D3DDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);

		// �X�e���V���e�X�g��r�ݒ� => �K����������
		g_D3DDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMPFUNC::D3DCMP_ALWAYS);

		// �X�e���V���e�X�g�̃e�X�g�ݒ�
		g_D3DDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_ZERO);
		g_D3DDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_REPLACE);
		g_D3DDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_ZERO);

		// Z�o�b�t�@�ݒ� => �L��
		g_D3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		// ZBUFFER��r�ݒ�ύX => �K�����s����
		g_D3DDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
	}

	void SetStanderdStencilBufferState()
	{
		// Z�o�b�t�@�ݒ� => �L��
		g_D3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		// ZBUFFER��r�ݒ�ύX => (�Q�ƒl <= �o�b�t�@�l)
		g_D3DDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

		// �X�e���V���o�b�t�@ => �L��
		g_D3DDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);
		// �X�e���V���o�b�t�@�Ɣ�r����Q�ƒl�ݒ� => ref
		g_D3DDevice->SetRenderState(D3DRS_STENCILREF, 1);
		// �X�e���V���o�b�t�@�̒l�ɑ΂��Ẵ}�X�N�ݒ� => 0xff(�S�Đ^)
		g_D3DDevice->SetRenderState(D3DRS_STENCILMASK, 0xff);
		// �X�e���V���e�X�g�̔�r���@�ݒ� => 
		//		���̕`��ł̎Q�ƒl >= �X�e���V���o�b�t�@�̎Q�ƒl�Ȃ獇�i
		g_D3DDevice->SetRenderState(D3DRS_STENCILFUNC, D3DCMPFUNC::D3DCMP_EQUAL);
		// �X�e���V���e�X�g�̌��ʂɑ΂��Ă̔��f�ݒ�
		g_D3DDevice->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
		g_D3DDevice->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
		g_D3DDevice->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
	}

	void DrawStart()
	{
		g_D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 0.0f, 0);

		if (D3D_OK != g_D3DDevice->BeginScene())
			std::cout << "BeginScene is failed\n";

	}

	void DrawEnd()
	{
		g_D3DDevice->EndScene();
		g_D3DDevice->Present(NULL, NULL, NULL, NULL);

	}






}
