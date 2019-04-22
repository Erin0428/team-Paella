//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

bool g_f = false;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//���������]�b�g
void CSceneMain::InitScene()
{
	//Font�쐬
	Font::SetStrTex(L"0123456789���b");

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;              //�X�e�[�W���̑傫��

	if (g_map_chenge == 0)
			p = Save::ExternalDataOpen(L"map1.csv", &size);//�O���f�[�^�ǂݍ���
		if (g_map_chenge == 1)
			p = Save::ExternalDataOpen(L"map2.csv", &size);//�O���f�[�^�ǂݍ���
		if (g_map_chenge == 2)
			p = Save::ExternalDataOpen(L"map3.csv", &size);//�O���f�[�^�ǂݍ���

	int map[19][120];
	int count = 1;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;

			if (w >= 10)
			{
				count += 1;
			}

			count += 2;
		}
	}

	if (g_map_chenge == 0)
	{
		Draw::LoadImage(L"�w�i1.jpg", 3, TEX_SIZE_1920);
		Draw::LoadImage(L"block1.png", 2, TEX_SIZE_768);
	}

	if (g_map_chenge == 1)
	{
		Draw::LoadImage(L"�w�i2.jpg", 3, TEX_SIZE_1920);
		Draw::LoadImage(L"block1.png", 2, TEX_SIZE_768);
	}

	//Font�쐬
	Font::SetStrTex(L"0123456789���b");

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(576�~384�s�N�Z��)
	Draw::LoadImage(L"��l��.png", 0, TEX_SIZE_576);
	Draw::LoadImage(L"����覐�.png", 7, TEX_SIZE_768);
	Draw::LoadImage(L"�S�[��.png", 5, TEX_SIZE_64);
	Draw::LoadImage(L"�ݒu�^覐�.png", 4, TEX_SIZE_768);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//�w�i�I�u�W�F�N�g�쐬
	C0bjBackground * back = new C0bjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 8);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	////覐΃I�u�W�F�N�g�쐬
	//ObjMeteo*objm = new ObjMeteo();
	//Objs::InsertObj(objm, OBJ_METEO, 10);

	//�^�C���I�u�W�F�N�g�쐬
	//C0bjTime* objt = new C0bjTime();
	//Objs::InsertObj(objt, OBJ_TIME, 12);


}

//���s�����]�b�g
void CSceneMain::Scene()
{

}
