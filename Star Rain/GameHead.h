#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
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

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
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
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--
extern int g_map_chenge; //�}�b�v�ύX
extern int block2;
extern bool check;
extern bool m_c;
extern bool g_f;


//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
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

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneMain.h"
#include"SceneTitle.h"
//#include"SceneRanking.h"
#include"SceneClear.h"
#include"SceneOver.h"
//#include"SceneMenu.h"
#include "SceneEnding.h"

//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle

//-----------------------------------------------