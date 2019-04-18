//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include"GameL\UserData.h"

#include "GameHead.h"
#include "ObjTitle.h"

#include"GameL\DrawTexture.h"

#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

int g_map_chenge = 0;//マップ変更
int block2 = 0;
bool check = false;
bool m_c = true;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
	choose = 0;
	m_time = 10;
}

//アクション
void CObjTitle::Action()
{
	g_map_chenge = 0; //マップ変更

	if (Input::GetVKey(VK_UP) == true && choose > 0 && m_time == 0)
	{
		--choose;
		m_time = 10;
	}
	if (Input::GetVKey(VK_DOWN) == true && choose < 2 && m_time == 0)
	{
		++choose;
		m_time = 10;
	}

	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			m_time = 0;
		}
	}
	if (choose == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneMain());
			}
		}
		else
		{
			m_key_flag = true;
		}
	}
	if (choose == 2)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			exit(1);
		}
	}
}

//ドロー
void CObjTitle::Draw()
{
	//描写カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描写元切り取り位置
	RECT_F dst;//描写先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 700.0f;
	src.m_bottom = 430.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//0番目に登録したグラフィックをsrc・dst・ｃの情報を元に描写
	Draw::Draw(3, &src, &dst, c, 0.0f);

	float b[4] = { 1,1,0,1 };

	//タイトル
	Font::StrDraw(L"Star Rain", 165, 120, 100, b);
	
	float s[4] = { 0,1,1,1 };
	if (choose == 0)
		Font::StrDraw(L"◇Start", GAME_START_POS_X - 55, GAME_START_POS_Y, GAME_START_FONT_SIZE, s);
	else
		Font::StrDraw(L"Start", GAME_START_POS_X, GAME_START_POS_Y, GAME_START_FONT_SIZE, s);
	if (choose == 1)
		Font::StrDraw(L"◇Option", GAME_OPTION_POS_X - 55, GAME_OPTION_POS_Y, GAME_OPTION_FONT_SIZE, s);
	else
		Font::StrDraw(L"Option", GAME_OPTION_POS_X, GAME_OPTION_POS_Y, GAME_OPTION_FONT_SIZE, s);
	if (choose == 2)
		Font::StrDraw(L"◇Exit", GAME_EXIT_POS_X - 55, GAME_EXIT_POS_Y, GAME_EXIT_FONT_SIZE, s);
	else
		Font::StrDraw(L"Exit", GAME_EXIT_POS_X, GAME_EXIT_POS_Y, GAME_EXIT_FONT_SIZE, s);
}