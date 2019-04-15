//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjMeteoFall.h"

//使用するネームスペース
using namespace GameL;

ObjMeteoFall::ObjMeteoFall(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void ObjMeteoFall::Init()
{
	m_speed_power = 1.3f;	//通常速度
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
	Hits::SetHitBox(this, m_px, m_py, 100, 100, ELEMENT_ENEMY, OBJ_METEOFALL, 1);

}

//アクション
void ObjMeteoFall::Action()
{
	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetPOSX();
	float hy = hero->GetPOSY();

	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

	if (hx > m_px - 440)
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

		m_speed_power = +0.6f;  //通常速度

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

		//方向
		if (m_move == false)
		{
			m_vy += m_speed_power;
			m_vx += -0.3f;
		}
	}
	


	//ブロックタイプ検知用の変数がないためのダミー
	int d;

	//ブロックとの当たり判定実行
	ObjMeteo* pd = (ObjMeteo*)Objs::GetObj(OBJ_METEO);
	pd->MeteoHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;
	
	//バレットに当たっているか
	if (hit->CheckObjNameHit(ELEMENT_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}
//ドロー
void ObjMeteoFall::Draw()
{
	//描写カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描写元切り取り位置
	RECT_F dst;//描写先表示位置

			   //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = ALL_BLOCK_SIZE;
	src.m_bottom = ALL_BLOCK_SIZE;

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px + block->GetScroll();
	dst.m_right = ALL_BLOCK_SIZE + m_px + block->GetScroll();
	dst.m_bottom = ALL_BLOCK_SIZE + m_py;

	Draw::Draw(12
		, &src, &dst, c, 0.0f);

}