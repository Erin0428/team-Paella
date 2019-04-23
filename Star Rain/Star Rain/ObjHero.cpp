//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "CObjBullet.h"

#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

float g_px = 64.0f;
float g_py = 450.0f;

//イニシャライズ
void CObjHero::Init()
{
	m_pos_x = 0.0f;
	m_pos_y = 0.0f;
	m_vx = 0.0f; //移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0f,左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 0;  //静止フレームを初期化する

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_f = true;

	m_del = false;

	m_key_f == false;

	m_block_type = 0;	//踏んでいるブロックの種類


	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;  //アニメーション間隔幅

	m_time = 31;

	hit_size = 0;
	hit_size_x = 0;
	hit_size_x2 = 0;

	//当たり判定用のHitBoxを作成				
	Hits::SetHitBox(this, g_px, g_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	hit_size = 0;
	hit_size_x = 0;
	hit_size_x2 = 0;

	//落下によるゲームオーバー＆リスタート
	if (g_py > 1000.0f)
	{
		//場外に出たらリスタート
		Scene::SetScene(new CSceneOver());
	}

	m_speed_power = 0.5f;


	////主人公機の弾丸発射
	//if (Input::GetVKey('Z') == true)
	//{
	//	if (m_f == true)
	//	{
	//		//弾丸オブジェクト作成
	//		CObjBullet* obj_b = new CObjBullet(g_px + 30.0f, g_py + 15.0f);
	//		Objs::InsertObj(obj_b, OBJ_BULLET, 14);

	//		m_f = false;
	//	}
	//}
	//else
	//{
	//	m_f = true;
	//}

	//ジャンプ
	if (Input::GetVKey(VK_SPACE) == true)
	{
		if (m_hit_down == true && g_map_chenge == 0)
		{
			m_vy = -10;
			g_py += m_vy;
		}
		if (m_hit_down == true && g_map_chenge == 1)
		{
			m_vy = -7;
			g_py + m_vy;
		}
		if (m_hit_down == true && g_map_chenge == 2)
		{
			m_vy = -6;
			g_py + m_vy;
		}

	}
	//ジャンプ
	else if (Input::GetVKey('W') == true)
	{
		if (m_hit_down == true && g_map_chenge == 0)
		{
			m_vy = -10;
			g_py += m_vy;
		}
		if (m_hit_down == true && g_map_chenge == 1)
		{
			m_vy = -7;
			g_py + m_vy;
		}
		if (m_hit_down == true && g_map_chenge == 2)
		{
			m_vy = -6;
			g_py + m_vy;
		}

	}
	if (m_time > 0) {
		m_time--;
		if (m_time <= 0) {
			m_time = 0;
		}
	}

	//自身のHitBoxを持ってくる
	CHitBox*hit = Hits::GetHitBox(this);

	if (m_ani_frame >= 4)
	{
		m_ani_frame = 0;
		m_ani_time = 0;
	}

	else if (Input::GetVKey('D') == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey('A') == true)
	{
		m_vx -= m_speed_power;
		m_posture = 2.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 1;   //キー入力が無い場合静止フレームにする
		m_ani_time = 0;
	}
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//主人公機が領域外行かない処理
	if (g_px + 64.0f > 800.0f)
	{
		g_px = 800.0f - 64.0f;

	}

	CObjBlock*b = (CObjBlock*)Objs::GetObj(OBJ_HERO);
	//後方スクロールライン
	if (g_px < 80)
	{
		g_px = 80;
		b->SetScroll(b->GetScroll());
	}

	//前方スクロールライン
	if (g_px > 350)
	{
		g_px = 350;
		b->SetScroll(b->GetScroll());
	}

	//摩擦
	//m_vx += -(m_vx*0.098);

	//自由落下運動
	m_vy += 2.0 / (16.0f); //初期値　m_vx+=3.0/(16.0f);

	//摩擦
	m_vx += -(m_vx*0.098);

	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&g_px, &g_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//敵と当ったているか確認
	if (hit->CheckObjNameHit(OBJ_METEO) != nullptr)
	{
		//主人公が敵とどの角度当ったているかを確認
		HIT_DATA**hit_data;           //当たった時の細かな情報を入れるための構造体
		hit_data = hit->SearchObjNameHit(OBJ_METEO);//hit_dataに主人公と当たっている他全てのHitBoxとの情報を入れる

		for (int i = 0; i < hit->GetCount(); i++)
		{
			//敵の左右に当たったら
			float r = 0;
			for (int i = 0; i < 10; i++)
			{
				if (hit_data[i] != nullptr) {
					r = hit_data[i]->r;
				}
			}

			if ((r < 75 && r >= 0) || r > 300)
			{
				if (Input::GetVKey('D') == true || Input::GetVKey(VK_RIGHT) == true)
				{
					m_posture = 1;
					m_vx = 0.0f;
				}
			}
			if (r > 120 && r < 235)
			{
				if (Input::GetVKey('A') == true || Input::GetVKey(VK_LEFT) == true)
				{
					m_posture = 2;
					m_vx = 0.0f;
				}

			}
			if (r > 60 && r < 120)
			{
				if (Input::GetVKey('S') == true)
				{
					if (r > 0 && r < 180)
						Scene::SetScene(new CSceneOver());
				}
				else
					Scene::SetScene(new CSceneOver());
			}
		}
	}

	//敵と当ったているか確認
	if (hit->CheckObjNameHit(OBJ_METEOFALL) != nullptr)
	{
		//主人公が敵とどの角度当ったているかを確認
		HIT_DATA**hit_data;           //当たった時の細かな情報を入れるための構造体
		hit_data = hit->SearchObjNameHit(OBJ_METEOFALL);//hit_dataに主人公と当たっている他全てのHitBoxとの情報を入れる

		for (int i = 0; i < hit->GetCount(); i++)
		{
			//敵の左右に当たったら
			float r = 0;
			for (int i = 0; i < 10; i++)
			{
				if (hit_data[i] != nullptr) {
					r = hit_data[i]->r;
				}
			}

			if ((r < 75 && r >= 0) || r > 300)
			{
				if (Input::GetVKey('D') == true || Input::GetVKey(VK_RIGHT) == true)
				{
					m_posture = 1;
					m_vx = 0.0f;
				}
				else
				{

				}
			}
			if (r > 120 && r < 235)
			{
				if (Input::GetVKey('A') == true || Input::GetVKey(VK_LEFT) == true)
				{
					m_posture = 2;
					m_vx = 0.0f;
				}
				else
				{

				}

			}
			if (r > 60 && r < 120)
			{
				if (Input::GetVKey('S') == true)
				{
					if (r > 0 && r < 180)
						Scene::SetScene(new CSceneOver());
				}
				else
					Scene::SetScene(new CSceneOver());
			}
		}
	}

	//敵と当ったているか確認
	if (hit->CheckObjNameHit(OBJ_METEO) != nullptr||
		hit->CheckObjNameHit(OBJ_METEOFALL) != nullptr)
	{
		Scene::SetScene(new CSceneOver());
		////主人公が敵とどの角度当ったているかを確認
		//HIT_DATA**hit_data;           //当たった時の細かな情報を入れるための構造体
		//hit_data = hit->SearchObjNameHit(OBJ_METEO);//hit_dataに主人公と当たっている他全てのHitBoxとの情報を入れる

		//for (int i = 0; i < hit->GetCount(); i++)
		//{
		//	//敵の左右に当たったら
		//	float r = 0;
		//	for (int i = 0; i < 10; i++)
		//	{
		//		if (hit_data[i] != nullptr) {
		//			r = hit_data[i]->r;
		//		}
		//	}

		//	if ((r < 75 && r >= 0) || r >= 290)
		//	{
		//		if (m_c == true)
		//		{
		//			Scene::SetScene(new CSceneOver());
		//		}
		//	}
		//}
	}

	//位置の更新
	g_px += m_vx;
	g_py += m_vy;
	m_pos_x += m_vx;
	m_pos_y += m_vy;

	//HitBoxの位置を更新
	hit->SetPos(g_px + 18 - hit_size_x, g_py + hit_size, 64 - hit_size, 32 + hit_size_x2);

	if (hit->CheckObjNameHit(OBJ_BLOCK) != nullptr)
	{
		Scene::SetScene(new CSceneOver());//場外に出たらリスタート
		g_px = 64.0f;
		g_py = 500.0f;
	}
}

//ドロー
void CObjHero::Draw()
{
	int AniData[4] =
	{
		1,0,2,0
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	if (m_posture == 1)
	{
		//Dが入力された時の
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 100;
		src.m_right = 100.0f + AniData[m_ani_frame] * 100;
		src.m_bottom = 100.0f;
	}
	else if (m_posture == 2)
	{
		//Aが入力された時の
		//切り取り位置の設定
		src.m_top = 101.0f;
		src.m_left = 0.0f + AniData[m_ani_frame] * 100;
		src.m_right = 100.0f + AniData[m_ani_frame] * 100;
		src.m_bottom = 200.0f;
	}
	//表示位置の設定
	dst.m_top = 0.0f + g_py;
	dst.m_left = 0.0f + g_px;
	dst.m_right = 64.0f + g_px;
	dst.m_bottom = 64.0f + g_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}