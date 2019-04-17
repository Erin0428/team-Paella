#pragma once
#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;


extern float g_px;
extern float g_py;

//�I�u�W�F�N�g : �S�[���u���b�N
class ObjMeteo : public CObj
{
#define ALL_BLOCK_SIZE (32.0f)

public:
	ObjMeteo(float x, float y);
	~ObjMeteo() {};
	void Init();   //�C��V�����C�Y
	void Action();	//�A�N�V����
	void Draw();    //�h���[
	int m_map[19][65]; //�}�b�v���

	//�u���b�N�̓����蔻��
	void MeteoHit(
		float*x, float*y, bool scroll_on,
		bool*up, bool*down, bool*left, bool*right,
		float*vx, float*vy, int*bt
	);
private:
	float m_px;			//�ʒu
	float m_py;
	float m_vx;			//�ړ��x�N�g��
	float m_vy;
	float m_posture;	//�p��

	int des = 0;

	float m_speed_power;	//�X�s�[�h�p���[

	float m_scrollx;     //���E�X�N���[���p
	float m_scrolly;
	float m_scroll_map;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	int  d;
	int  m_block_type;
	//�ړ��̌�������p
	bool m_move;
};