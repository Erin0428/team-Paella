//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


CObjBlock::CObjBlock(int map[19][65])
{
	//�}�b�v�f�[�^�R�s�[
	memcpy(m_map, map, sizeof(int)*(19 * 65));
}

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;
	m_scroll_map = 0.0f;
	float m_x1 = 0.0f;

	m_ani_time = 0;
	m_ani_frame = 0;

	m_ani_max_time = 15;
}


//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();
	////����X�N���[�����C��
	if (hx < 80)
	{
		hero->SetX(80);           //��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX(); //��l�����{�������ׂ����̒l��m_scroll�ɉ�����

	}

	//�O���X�N���[�����C��
	if (hx > 300)
	{
		hero->SetX(300);           //��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX(); //��l�����{�������ׂ����̒l��m_scroll�ɉ�����

	}


	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 65; j++)
		{

			if (m_map[i][j] == 4)
			{
				CObjgoalblock* ends = new CObjgoalblock(j*ALL_BLOCK_SIZE, i*ALL_BLOCK_SIZE);
				Objs::InsertObj(ends, OBJ_GOAL_BLOCK, 11);
				m_map[i][j] = 0;
			}
		}
	}
}

//�h���[
void CObjBlock::Draw()
{

	//�`�ʃJ���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//�`�ʌ��؂���ʒu
	RECT_F dst;//�`�ʐ�\���ʒu


	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 65; j++)
		{

			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = ALL_BLOCK_SIZE;
			src.m_bottom = ALL_BLOCK_SIZE;

			//�u���b�N�摜�\��
			if (m_map[i][j] == 1)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*ALL_BLOCK_SIZE;
				dst.m_left = j*ALL_BLOCK_SIZE + m_scroll;
				dst.m_right = dst.m_left + ALL_BLOCK_SIZE;
				dst.m_bottom = dst.m_top + ALL_BLOCK_SIZE;

				Draw::Draw(2, &src, &dst, c, 0.0f);
			}
		}
	}
}

//BlockHit�֐�
//�����P    float * x           :������s��object��X�ʒu
//�����Q    float * y           :������s��object��Y�ʒu
//�����R    bool     scroll_on  :������s��object�̓X�N���[���̉e���^���邩�ǂ����itrue=�^����@false=�^���Ȃ��j
//�����S    bool *   up         :�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//�����T    bool *   down       :�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//�����U    bool *   left       :�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//�����V    bool *   right      :�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//�����W    float * vx          :���E���莞�̔����ɂ��ړ������E�͂̒l�ς��ĕԂ�
//�����X    float * vy          :�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l�ς��ĕԂ�
//�����P�O  int * bt            :���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float *vx, float*vy, int *bt
)
{
	//�Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 65; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 4)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*32.0f;
				float by = i*32.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 50.0f > bx) && (*x + (-scroll) < bx + 16.0f) && (*y + 64.0f > by) && (*y < by + 32.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r < 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);


					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 79.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 75 && r>0) || r > 315)
						{
							//�E
							*right = true;//�I�u�W�F�N�g�̍��̕������Փ˂��Ă���
							*x = bx + 16.0f + (scroll);//�u���b�N�̈ʒu+��l���̕�
							*vx = 0.0f;//-VX*�����W��

						}
						if (r > 75 && r < 128)
						{
							//��
							*down = true;//��l���̉��̕������Փ˂��Ă���
							*y = by - 64.0f;//�u���b�N�̈ʒu-��l���̕�
							*vy = 0.0f;
							if (m_map[i][j] == 2)
							{
								Audio::Start(1);
								Scene::SetScene(new CSceneOver());
							}
						}
						if (r > 128 && r < 225)
						{
							//��
							*left = true;//��l���̉E�̕������Փ˂��Ă���
							*x = bx - 50.0f + (scroll);//�u���b�N�̈ʒu-��l���̕�
							*vx = -(*vx)*0.0f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;//��l���̏�̕������Փ˂��Ă���
							*y = by + 64.0f;//�u���b�N�̈ʒu+��l���̕�
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

void CObjBlock::BlockDraw(float x, float y, RECT_F *dst, float c[])
{

}