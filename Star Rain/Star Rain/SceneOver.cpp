//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
//#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "GameHead.h"
#include "SceneOver.h"

//���s�����\�b�h
void CSceneOver::Scene()
{

}

//�R���X�g���N�^
CSceneOver::CSceneOver()
{
}

//�f�X�g���N�^
CSceneOver::~CSceneOver()
{
}

//���������\�b�h
void CSceneOver::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	//Draw::LoadImage(L"Game Ober.jpg", 4, TEX_SIZE_700);

	//�w�i�I�u�W�F�N�g�쐬
	CObjOver* go1 = new CObjOver();
	Objs::InsertObj(go1, OBJ_OVER, 4);

	////���y�ǂݍ���
	//Audio::LoadAudio(0, L"BGMGameover.wav", BACK_MUSIC);
	////�{�����[����1.0�ɖ߂�
	//float v = Audio::VolumeMaster(1.5);

	//���y�X�^�[�g
	//Audio::Start(0);
}