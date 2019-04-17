//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "CObjBullet.h"
#include "GameL\HitBoxManager.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y)
{
	g_px = x;
	g_py = y;
}


//�C�j�V�����C�Y
void CObjBullet::Init()
{
	m_vx = 0.0f;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = false;	//����ł���u���b�N�̎��


	//�����蔻��HitoBox���쐬
	Hits::SetHitBox(this, g_px, g_py, 32, 32, ELEMENT_BULLET, OBJ_BULLET, 1);



	
}
//�A�N�V����
void CObjBullet::Action()
{
	if (m_hit_up == true)	//��
		m_hit = true;
	if (m_hit_down == true)	//��
		m_hit = true;
	if (m_hit_left == true)	//��
		m_hit = true;
	if (m_hit_right == true)//�E
		m_hit = true;

	m_vx += 1.0f;

	g_px += m_vx;

	//HitBox�̓��e���X�V
	CHitBox * hit = Hits::GetHitBox(this);
	hit->SetPos(g_px, g_py);


	//�o���b�g����ʊO�ō폜
	if (g_px > 800.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	
	//METEO�ɓ������Ă��邩
	if (hit->CheckObjNameHit(OBJ_BLOCK) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//METEO�ɓ������Ă��邩
	if (hit->CheckObjNameHit(OBJ_METEOFALL) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//METEO�ɓ������Ă��邩
	if (hit->CheckObjNameHit(OBJ_METEO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}





	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&*x, &g_py, false,
	&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy, &m_block_type);

	//�ǂɓ�������������鏈��
	if (m_hit == true) {
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	


}

//�h���[
void CObjBullet::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 = 0.0f	 + g_py;
	dst.m_left	 = 0.0f  + g_px;
	dst.m_right  = 32.0f + g_px;
	dst.m_bottom = 32.0f + g_py;

	//�`��
	Draw::Draw(7, &src, &dst, c, 0.0f);



}
//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "CObjBullet.h"
#include "GameL\HitBoxManager.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y)
{
	g_px = x;
	g_py = y;
}


//�C�j�V�����C�Y
void CObjBullet::Init()
{
	m_vx = 0.0f;
	//�����蔻��HitoBox���쐬
	Hits::SetHitBox(this, g_px, g_py, 32, 32, ELEMENT_BULLET, OBJ_BULLET, 1);
}
//�A�N�V����
void CObjBullet::Action()
{
	m_vx += 1.0f;

	g_px += m_vx;

	//HitBox�̓��e���X�V
	CHitBox * hit = Hits::GetHitBox(this);
	hit->SetPos(g_px, g_py);


	//�o���b�g����ʊO�ō폜
	if (g_px > 800.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		
	}




}

//�h���[
void CObjBullet::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 = 0.0f	 + g_py;
	dst.m_left	 = 0.0f  + g_px;
	dst.m_right  = 32.0f + g_px;
	dst.m_bottom = 32.0f + g_py;

	//�`��
	Draw::Draw(7, &src, &dst, c, 0.0f);
}