//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
//#include "GameL/Audio.h"
#include "ObjOP.h"
#include "SceneMain.h"




//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjOP::Init()
{
	//�}�E�X�̈ʒu
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_and = 0.0f;
	m_f = true;
	m_cnt = 1;
	m_gazo = false;
	m_flag = true;
	m_time = 30;
}

//�A�N�V����
void CObjOP::Action()
{
	//Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//Audio::Start(0);
	float k[4] = { 0.3f,0.6f,0.6f,m_and };
	float c[4] = { 1.f,1.f,1.f,m_and };

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	
	//�N���b�N����
	if (m_mou_x >= 450 && m_mou_x <= 740 && m_mou_y >= 470 && m_mou_y <= 500)
	{
		if (m_cnt >= 5)
		{
			return;
		}

		if (m_mou_l == true)
		{

			if (m_flag == true)
			{
				//Audio::Start(1);
				m_cnt++;
				m_flag = false;

			}
		}
		else
		{
			m_flag = true;
		}
	}
	if (m_cnt >= 5)
	{
		return;
	}
	else
	{
	
	}

	m_time--;
}

//�h���[
void CObjOP::Draw()
{
	float c[4] = { 1.f,1.f,1.f,m_and };
	float k[4] = { 0.7f,0.7f,0.0f,m_and };
	float d[4] = { 1.0f,1.0f,1.0f,m_and };

	RECT_F src;
	RECT_F dst;

	//�t�F�[�h�C���E�t�F�[�h�A�E�g
	if (m_f == true)
	{
		m_and += 0.1f;
		if (m_and >= 1.0)
		{
			m_and = 1.0f;
			m_f = false;
		}

	}


	////���}�E�X�ʒu�\��
	//wchar_t str[256];
	//swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	//Font::StrDraw(str, 20, 20, 12, c);
	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	//if (m_mou_x > 565 && m_mou_x < 750 && m_mou_y>540 && m_mou_y < 570)
	//{
	//	Font::StrDraw(L"���E�o�����݂�", 570, 550, 32, c);
	//	//�}�E�X�̃{�^���������ꂽ�烁�C���ɑJ��
	//	if (m_mou_l == true)
	//	{
	//		if (m_flag == true)
	//		{
	//			m_kesu = true;
	//			//Audio::Start(2);

	//			m_flag = false;
	//		}
	//	}
	//	else
	//	{
	//		m_flag = true;
	//	}
	//}
	//else
	//{
	//	Font::StrDraw(L"�E�o�����݂�", 570, 550, 32, c);
	//}
	//if (m_kesu == true)
	//{
	//	m_and -= 0.02f;
	//	if (m_and <= 0)
	//	{
	//		Scene::SetScene(new CSceneMain());
	//	}
	//}

	Font::StrDraw(L"���E�o�����݂�", 570, 550, 32, c);
	if (m_time <= 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
			Scene::SetScene(new CSceneMain());
	}

	if (m_cnt == 1)
	{
		
	}

	if (m_cnt == 2)
	{

		
	}


	if (m_cnt == 3)
	{
		

	}

	if (m_cnt == 4)
	{
		

	}

	if (m_cnt == 5)
	{
		

	}
	if (m_cnt >= 6)
	{
		Scene::SetScene(new CSceneMain());

	}
	//Choice�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 455.0f;
	src.m_bottom = 180.0f;

	dst.m_top = 150.0f;
	dst.m_left = 150.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 400.0f;
	Draw::Draw(0, &src, &dst, d, 0.0f);



}