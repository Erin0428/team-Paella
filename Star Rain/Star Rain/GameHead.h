#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_TITLE,
	OBJ_BACKGROUND,
	OBJ_CLEAR,
	OBJ_BLOCK,
	OBJ_OVER,
	OBJ_RANKING,
	OBJ_MENU,
	OBJ_TIME,
	OBJ_GOAL_BLOCK,
	OBJ_METEOFALL,
	OBJ_METEOFALLS,
	OBJ_METEOFALLL,
	OBJ_METEOFALLLR,
	OBJ_METEO,
	OBJ_BULLET,
	OBJ_ENDING,

};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_BULLET,
	ELEMENT_BLOCK,

};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--
extern int g_map_chenge; //マップ変更
extern int block2;
extern bool check;
extern bool m_c;
extern bool g_f;


//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjHero.h"
#include"ObjBackground.h"
#include"ObjClear.h"
#include"ObjBlock.h"
#include"ObjOver.h"
//#include"ObjRanking.h"
//#include"ObjMenu.h"
#include"ObjTime.h"
#include"Objgoalblock.h"
#include"ObjMeteoFall.h"
#include"ObjMeteo.h"
//#include"CObjBullet.h"
#include"ObjMeteoFallS.h"
#include"ObjMeteoFallL.h"
#include"ObjMeteoFallLR.h"
#include"ObjEnding.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include"SceneTitle.h"
//#include"SceneRanking.h"
#include"SceneClear.h"
#include"SceneOver.h"
//#include"SceneMenu.h"
#include "SceneEnding.h"

//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle

//-----------------------------------------------