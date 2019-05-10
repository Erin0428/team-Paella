//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
//#include "GameL/Audio.h"
#include "ObjOP.h"
#include "SceneMain.h"




//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjOP::Init()
{
	//マウスの位置
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

//アクション
void CObjOP::Action()
{
	//Audio::LoadAudio(0, L"mainBGM.wav", SOUND_TYPE::BACK_MUSIC);

	//Audio::Start(0);
	float k[4] = { 0.3f,0.6f,0.6f,m_and };
	float c[4] = { 1.f,1.f,1.f,m_and };

	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	
	//クリック処理
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

//ドロー
void CObjOP::Draw()
{
	float c[4] = { 1.f,1.f,1.f,m_and };
	float k[4] = { 0.7f,0.7f,0.0f,m_and };
	float d[4] = { 1.0f,1.0f,1.0f,m_and };

	RECT_F src;
	RECT_F dst;

	//フェードイン・フェードアウト
	if (m_f == true)
	{
		m_and += 0.1f;
		if (m_and >= 1.0)
		{
			m_and = 1.0f;
			m_f = false;
		}

	}


	////仮マウス位置表示
	//wchar_t str[256];
	//swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	//Font::StrDraw(str, 20, 20, 12, c);
	//マウスの位置とクリックする場所で当たり判定
	//if (m_mou_x > 565 && m_mou_x < 750 && m_mou_y>540 && m_mou_y < 570)
	//{
	//	Font::StrDraw(L"◇脱出を試みる", 570, 550, 32, c);
	//	//マウスのボタンが押されたらメインに遷移
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
	//	Font::StrDraw(L"脱出を試みる", 570, 550, 32, c);
	//}
	//if (m_kesu == true)
	//{
	//	m_and -= 0.02f;
	//	if (m_and <= 0)
	//	{
	//		Scene::SetScene(new CSceneMain());
	//	}
	//}

	Font::StrDraw(L"◇脱出を試みる", 570, 550, 32, c);
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
	//Choice表示
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