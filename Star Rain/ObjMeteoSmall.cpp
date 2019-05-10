//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"ObjMeteoSmall.h"

//使用するネームスペース
using namespace GameL;

ObjMeteoSmall::ObjMeteoSmall(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void ObjMeteoSmall::Init()
{
	m_speed_power_y = 1.3f;	//通常速度
	m_speed_power_x = 1.3f;	//通常速度
	m_vx = 0.0f;
	m_vy = 0.0f;

	m_move = false;			//true=上 false=下

	Fall_f = false;

	abc == false;

	//blockとの衝突状態確認
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 16, 16, ELEMENT_ENEMY, OBJ_METEOFALL, 1);

}

//アクション
void ObjMeteoSmall::Action()
{
	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetPOSX();
	float hy = hero->GetPOSY();

	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + 10 + block->GetScroll(), m_py + 8);



	if (hx > m_px - 400)
	{
		Fall_f = true;
	}
	if (Fall_f == true)
	{
		//落下
		if (m_py > 1000.0f)
		{
			;
		}

		m_speed_power_y = +0.5f;  //隕石落下速度y
		m_speed_power_x = -0.3f;	 //通常速度

		//ブロック衝突で向き変更
		if (m_hit_up == true)
		{
			m_move = false;
		}
		if (m_hit_down == true)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		if (m_hit_left == true)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		if (m_hit_right == true)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		//方向
		if (m_move == false)
		{
			m_vy += m_speed_power_y;
			m_vx += m_speed_power_x;
		}
	}



	//ブロックタイプ検知用の変数がないためのダミー
	//int d;

	//ブロックとの当たり判定実行
	CObjBlock* pd = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pd->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	if (m_speed_power_y >= 1.0f)
	{
		m_speed_power_y += -0.1f;
		m_speed_power_y += 0.1f;
	}

	if (m_speed_power_y <= 1.0f)
	{
		m_speed_power_y += 1.0f;
		m_speed_power_y += -0.1f;
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//ブロックに当たっているか
	if (hit->CheckObjNameHit(OBJ_BLOCK) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}
//ドロー
void ObjMeteoSmall::Draw()
{
	//描写カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描写元切り取り位置
	RECT_F dst;//描写先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px + block->GetScroll();
	dst.m_right = 32.0f + m_px + block->GetScroll();
	dst.m_bottom = 32.0f + m_py;

	Draw::Draw(10, &src, &dst, c, 0.0f);

}