//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjOver.h"

//使用するネームスペース
using namespace GameL;


extern float g_px;
extern float g_py;

//イニシャライズ
void CObjOver::Init()
{
	choose = 0;
	m_key_flag = false;
}

//アクション
void CObjOver::Action()
{
	if (Input::GetVKey(VK_LEFT) == true)
	{
		choose = 0;
	}
	if (Input::GetVKey(VK_RIGHT) == true)
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
		if (Input::GetVKey(VK_RETURN) == true)
		{
			g_map_chenge = 0;//マップ変更
			if (m_key_flag == true)
			{

				Scene::SetScene(new CSceneTitle());

				

				m_key_flag = false;
			}
		}
		else
		{
			m_key_flag = true;
		}
		
	}

}
//ドロー
void CObjOver::Draw()

{
	//描写カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描写元切り取り位置
	RECT_F dst;//描写先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 700.0f;
	src.m_bottom = 420.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//0番目に登録したグラフィックをsrc・dst・ｃの情報を元に描写
	Draw::Draw(4, &src, &dst, c, 0.0f);

	float p[4] = { 1,0,0,1 };

	Font::StrDraw(L"GAME OVER", GAME_OVER_X, GAME_OVER_Y, GAME_OVER_FONT_SIZE, p);

	float y[4] = { 1,1,1,1 };

	if (choose == 0)
		Font::StrDraw(L"◇Retry?", GAME_RETRY_X - 40, GAME_RETRY_Y, GAME_RETRY_FONT_SIZE, y);
	else
		Font::StrDraw(L"Retry?", GAME_RETRY_X, GAME_RETRY_Y, GAME_RETRY_FONT_SIZE, y);
	if (choose == 1)
		Font::StrDraw(L"◇Title?", GAME_TITLE_X - 40, GAME_TITLE_Y, GAME_TITLE_FONT_SIZE, y);
	else
		Font::StrDraw(L"Title?", GAME_TITLE_X, GAME_TITLE_Y, GAME_TITLE_FONT_SIZE, y);
}
