//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjMeteo.h"

//使用するネームスペース
using namespace GameL;

ObjMeteo::ObjMeteo(float x, float y)
{
	m_px = x;		//位置
	m_py = y;
}

//イニシャライズ
void ObjMeteo::Init()
{
	m_ani_time = 0;
	m_ani_frame = 0;
	m_ani_max_time = 15;
	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0f 左向き1.0f

	m_speed_power = 10.0f;	//通常速度

	m_move = true;			//true=右 false=左

	//blockとの衝突状態確認
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 128, 32, ELEMENT_ENEMY, OBJ_METEO, 1);
}

//アクション
void ObjMeteo::Action()
{
	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	m_ani_time += 1;
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 7)
	{
		m_ani_frame = 0;
	}
	//落下
	//if (m_py > 1000.0f)
	//{
	//	;
	//}

	////通常速度
	//m_speed_power = 10.0f;


	//ブロック衝突で向き変更
	//if (m_hit_down == true)
	//{
	//	m_move = true;
	//}
	//if (m_hit_up == true)
	//{
	//	m_move = false;
	//}

	////方向
	//if (m_move == false)
	//{
	//	m_vy += m_speed_power;
	//}
	//else if (m_move == true)
	//{
	//	m_vy -= m_speed_power;
	//}

	////摩擦
	//m_vx += -(m_vx * 0.098);
	//m_vy += -(m_vy * 0.098);


	//ブロックタイプ検知用の変数がないためのダミー
	int d;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scrollx = block->GetScrollX();
	m_scrolly = block->GetScrollY();
	memcpy(m_map, block->m_map, sizeof(int) * 19 * 65);

	//位置の更新
	/*m_px += m_vx;
	m_py += m_vy;*/

	//HitBoxの位置の変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

	//バレットに当たっているか
	/*if (hit->CheckObjNameHit(ELEMENT_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}*/

}

//ドロー
void ObjMeteo::Draw()
{
	int AniData[7] =
	{
		0,1,2,3,4,5,6
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;	//描画元切り取り位置
	RECT_F dst;	//描画先表示位置

				//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f - AniData[m_ani_frame] * 128;
	src.m_right = 130.0f - AniData[m_ani_frame] * 128;
	src.m_bottom = 50.0f;


	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top = -15.0f + m_py;						//↓描画に対してスクロールの影響を加える
	dst.m_left = (ALL_BLOCK_SIZE * m_posture) + m_px-35+ block->GetScroll();
	dst.m_right = (ALL_BLOCK_SIZE - ALL_BLOCK_SIZE * m_posture) + m_px+145 + block->GetScroll();
	dst.m_bottom = ALL_BLOCK_SIZE + m_py;

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);
}

//wallHit関数
//引数１    float * x           :判定を行うobjectのX位置
//引数２    float * y           :判定を行うobjectのY位置
//引数３    bool     scroll_on  :判定を行うobjectはスクロールの影響与えるかどうか（true=与える　false=与えない）
//引数４    bool *   up         :上下左右判定の上部分に当たっているかどうかを返す
//引数５    bool *   down       :上下左右判定の下部分に当たっているかどうかを返す
//引数６    bool *   left       :上下左右判定の左部分に当たっているかどうかを返す
//引数７    bool *   right      :上下左右判定の右部分に当たっているかどうかを返す
//引数８    float * vx          :左右判定時の反発による移動方向・力の値変えて返す
//引数９    float * vy          :上下判定時による自由落下運動の移動方向・力の値変えて返す
//引数１０  int * bt            :下部分判定時、特殊なブロックのタイプを返す
//判定を行うobjectとブロック64×64限定で、当たり判定と上下左右判定を行う
//その結果は引数4～10に返す
void ObjMeteo::MeteoHit(
	float*x, float*y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)

{
	//衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 19; i++)
	{

		for (int j = 0; j < 65; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 30)
			{
				//要素番号を座標に変更
				float bx = j*32.0f;
				float by = i*32.0f;

				//スクロールの影響
				float scrollx = scroll_on ? m_scrollx : 0;
				float scrolly = scroll_on ? m_scrolly : 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scrollx) + 32.0f > bx) && (*x + (-scrollx) < bx + 32.0f) && (*y + (-scrolly) + 32.0f > by) && (*y + (-scrolly)< by + 32.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-scrollx)) - bx;
					float rvy = (*y + (-scrolly)) - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r < 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);
					//lenがある一定の長さのより短い場合判定に入る
					if (len < 79.0f)
					{
						//角度で上下左右を判定
						if ((r < 75 && r>0) || r > 315)
						{
							//右
							*right = true;//オブジェクトの左の部分が衝突している
							*x = bx + 32.0f + (scrollx);//ブロックの位置+主人公の幅
							*vx = 0.0f;//-VX*反発係数
						}
						if (r > 75 && r < 128)
						{
							//上
							*down = true;//主人公の下の部分が衝突している
							*y = by - 32.0f + (scrolly);//ブロックの位置-主人公の幅
							*vy = 0.0f;
						}
						if (r > 128 && r < 170)
						{
							//左
							*left = true;//主人公の右の部分が衝突している
							*x = bx - 32.0f + (scrollx);//ブロックの位置-主人公の幅
							*vx = -(*vx)*0.0f;//-VX*反発係数
						}
						if (r > 190 && r < 315)
						{
							//下
							*up = true;//主人公の上の部分が衝突している
							*y = by + 32.0f + (scrolly);//ブロックの位置+主人公の幅
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}

					}
				}
			}
		}
	}
}