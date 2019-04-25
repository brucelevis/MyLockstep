#ifndef LOCKSTEP_MAP_H
#define LOCKSTEP_MAP_H
#define MAX_SKILL_EQUIP_NUM 5
namespace lockstep
{
	extern "C"
	{
		struct Rect
		{
			int minX;
			int minY;
			int maxX;
			int maxY;
		};

		struct Vector2
		{
			int x;
			int y;
		};

		struct Bound
		{
			Vector2 size;
			Vector2 center;

		};

		struct entity_data
		{
			unsigned long long id; //��ɫID
			Vector2 pos; //��ɫ������Id;
			int d;//�����ĳ���
			int camp;//��Ӫ
			int config_id;// ��ɫ���������ļ�
			int skills[MAX_SKILL_EQUIP_NUM];
			int skill_size;
		};
		struct level_data
		{
			int mapId; //��ͼ�����ļ�
			unsigned int seed;
		};

		struct hurt_data
		{
			int hurt;
		};

		struct command_data
		{
			char* op; //����
			unsigned long long id; //���ĸ�ʵ�������
			char* data; //����
		};


	

	}
	struct hit
	{
		unsigned long long id;
		int param;
		int frozen;
		int x;
		int y;
	};

}


#endif
