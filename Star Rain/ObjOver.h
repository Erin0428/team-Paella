#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�`��֌W�̒萔

#define GAME_OVER_X (165)
#define GAME_OVER_Y (125)
#define GAME_OVER_FONT_SIZE (100)

#define GAME_CON_X (145)
#define GAME_CON_Y (325)
#define GAME_CON_FONT_SIZE (50)

#define GAME_YES_X (335)
#define GAME_YES_Y (400)
#define GAME_YES_FONT_SIZE (50)

#define GAME_NO_X (345)
#define GAME_NO_Y (480)
#define GAME_NO_FONT_SIZE (50)

#define GAME_RETRY_X (190)
#define GAME_RETRY_Y (400)
#define GAME_RETRY_FONT_SIZE (50)

#define GAME_TITLE_X (460)
#define GAME_TITLE_Y (400)
#define GAME_TITLE_FONT_SIZE (50)

#define RANKING_POS_X (600)
#define RANKING_POS_Y (0)
#define RANKING_FONT_SIZE (24)
#define RANKING_SCORE_MAX (15)
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


//�I�u�W�F�N�g:�N���A
class CObjOver : public CObj
{
public:
	CObjOver() {};
	~CObjOver() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
private:
	bool m_key_flag;//�L�[�t���O
	int choose;
	int m_time;
};