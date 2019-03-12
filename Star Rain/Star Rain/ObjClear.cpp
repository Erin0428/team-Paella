//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include"GameL\UserData.h"

#include "GameHead.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
	choose = 0;
}

//アクション
void CObjClear::Action()
{
	Save::Seve();//UserDataの情報フォルダ「UserData」を作成する;

	if (Input::GetVKey(VK_UP) == true)
	{
		choose = 0;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		choose = 1;
	}

	if (choose == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{

			if (m_key_flag == true)
			{
				g_px = 64.0f;
				g_py = 500.0f;

				Scene::SetScene(new CSceneMain());
				m_key_flag = false;
			}
		}
		else
		{
			m_key_flag = true;
		}
	}
	if (choose == 1)
	{
		if (Input::GetVKey(VK_BACK) == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
}
//ドロー
void CObjClear::Draw()

{
	//描写カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描写元切り取り位置
	RECT_F dst;//描写先表示位置

			   //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 191.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//0番目に登録したグラフィックをsrc・dst・ｃの情報を元に描写
	Draw::Draw(4, &src, &dst, c, 0.0f);

	float p[4] = { 1,1,1,1 };

	Font::StrDraw(L"Stage Clear", GAME_CLEAR_X, GAME_CLEAR_Y, GAME_CLEAR_FONT_SIZE, p);

	Font::StrDraw(L"Next Stage", NEXT_STAGE_X, NEXT_STAGE_Y, NEXT_STAGE_FONT_SIZE, p);

	if (choose == 0)
		Font::StrDraw(L"◇はい", NEXT_STAGE_YES_X - 40, NEXT_STAGE_YES_Y, GAME_NO_FONT_SIZE, p);
	else
		Font::StrDraw(L"はい", GAME_YES_X, GAME_YES_Y, GAME_NO_FONT_SIZE, p);
	if (choose == 1)
		Font::StrDraw(L"◇いいえ", GAME_NO_X - 40, GAME_NO_Y, GAME_NO_FONT_SIZE, p);
	else
		Font::StrDraw(L"いいえ", GAME_NO_X, GAME_NO_Y, GAME_NO_FONT_SIZE, p);
}