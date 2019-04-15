//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjMeteoFall.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

ObjMeteoFall::ObjMeteoFall(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void ObjMeteoFall::Init()
{
	m_speed_power = 1.3f;	//�ʏ푬�x
	m_vx = 0.0f;
	m_vy = 0.0f;

	m_move = false;			//true=�� false=��

	Fall_f = false;

	abc == false;

	//block�Ƃ̏Փˏ�Ԋm�F
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 100, 100, ELEMENT_ENEMY, OBJ_METEOFALL, 1);

}

//�A�N�V����
void ObjMeteoFall::Action()
{
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetPOSX();
	float hy = hero->GetPOSY();

	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

	if (hx > m_px - 440)
	{
		Fall_f = true;
	}
	if (Fall_f == true)
	{
		//����
		if (m_py > 1000.0f)
		{
			;
		}

		m_speed_power = +0.6f;  //�ʏ푬�x

		//�u���b�N�Փ˂Ō����ύX
		if (m_hit_up == true)
		{
			m_move = false;
		}
		if (m_hit_down == true)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

		//����
		if (m_move == false)
		{
			m_vy += m_speed_power;
			m_vx += -0.3f;
		}
	}
	


	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;

	//�u���b�N�Ƃ̓����蔻����s
	ObjMeteo* pd = (ObjMeteo*)Objs::GetObj(OBJ_METEO);
	pd->MeteoHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
	
	//�o���b�g�ɓ������Ă��邩
	if (hit->CheckObjNameHit(ELEMENT_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}
//�h���[
void ObjMeteoFall::Draw()
{
	//�`�ʃJ���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//�`�ʌ��؂���ʒu
	RECT_F dst;//�`�ʐ�\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = ALL_BLOCK_SIZE;
	src.m_bottom = ALL_BLOCK_SIZE;

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px + block->GetScroll();
	dst.m_right = ALL_BLOCK_SIZE + m_px + block->GetScroll();
	dst.m_bottom = ALL_BLOCK_SIZE + m_py;

	Draw::Draw(12
		, &src, &dst, c, 0.0f);

}