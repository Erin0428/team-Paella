#pragma once
//使用するヘッダーファイル
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//描画関係の定数

#define GAME_CLEAR_X (130)
#define GAME_CLEAR_Y (160)
#define GAME_CLEAR_FONT_SIZE (100)

#define NEXT_STAGE_X (230)
#define NEXT_STAGE_Y (300)
#define NEXT_STAGE_FONT_SIZE (70)

#define NEXT_STAGE_YES_X (335)
#define NEXT_STAGE_YES_Y (400)
#define NEXT_STAGE_YES_FONT_SIZE (70)

#define NEXT_STAGE_NO_X (315)
#define NEXT_STAGE_NO_Y (480)
#define NEXT_STAGE_NO_FONT_SIZE (70)

#define STR_MAX (256)
#define SCORE_INIT (1)
#define SCORE_POS_X (670)
#define SCORE_POS_Y (24)
#define SCORE_POINT_MAX (100)
#define SCORE_INTERVAL (24)
#define SCORE_FONT_SIZE (12)

#define CLICK_START_POS_X (230)
#define CLICK_START_POS_Y (400)
#define CLICK_START_FONT_SIZE (30)

#define CLICK_RESET_POS_X (680)
#define CLICK_RESET_POS_Y (380)
#define CLICK_RESET_FONT_SIZE (16)


//オブジェクト:クリア
class CObjClear : public CObj
{
public:
	CObjClear() {};
	~CObjClear() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー
private:
	bool m_key_flag;//キーフラグ
	float m_mou_x;  //マウスの位置X
	float m_mou_y;  //マウスの位置Y
	bool m_mou_r;   //マウスの右ボタン
	bool m_mou_l;   //マウスの左ボタン
	int choose;
};