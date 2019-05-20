//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjMeteotyu.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

ObjMeteotyu::ObjMeteotyu(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void ObjMeteotyu::Init()
{
	m_ani_time = 0;
	m_ani_frame = 0;
	m_ani_max_time = 15;
	m_speed_power_y = 1.3f;	//�ʏ푬�x
	m_speed_power_x = 1.3f;	//�ʏ푬�x
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
	Hits::SetHitBox(this, m_px, m_py, 65, 60, ELEMENT_ENEMY, OBJ_METEOFALL, 1);

}

//�A�N�V����
void ObjMeteotyu::Action()
{
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetPOSX();
	float hy = hero->GetPOSY();

	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + 10 + block->GetScroll(), m_py + 8);

	m_ani_time += 1;
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 3)
	{
		m_ani_frame = 0;
	}

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

		m_speed_power_y = +0.2f;  //覐Η������xy
		m_speed_power_x = -0.1f;	 //�ʏ푬�x

									 //�u���b�N�Փ˂Ō����ύX
		if (m_hit_up == true)
		{
			m_move = false;
		}
		if (m_hit_down == true)
		{
			m_speed_power_y = +0.1f;
			m_speed_power_x = -0.2f;
			//this->SetStatus(false);
			//Hits::DeleteHitBox(this);
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

		//����
		if (m_move == false)
		{
			m_vy += m_speed_power_y;
			m_vx += m_speed_power_x;
		}
	}



	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock* pd = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pd->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//�u���b�N�ɓ������Ă��邩
	if (hit->CheckObjNameHit(OBJ_BLOCK) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}
//�h���[
void ObjMeteotyu::Draw()
{
	int AniData[3] =
	{
		0,1,2
	};
	//�`�ʃJ���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//�`�ʌ��؂���ʒu
	RECT_F dst;//�`�ʐ�\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 256.0f - AniData[m_ani_frame] * 128;
	src.m_right = 384.0f - AniData[m_ani_frame] * 128;
	src.m_bottom = 125.0f;

	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px + block->GetScroll();
	dst.m_right = 80.0f + m_px + block->GetScroll();
	dst.m_bottom = 70.0f + m_py;

	Draw::Draw(13, &src, &dst, c, 0.0f);

}