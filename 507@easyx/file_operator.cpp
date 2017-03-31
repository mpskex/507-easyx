#include "file_operator.h"

int load_setting(SETTING &setting)
{
	FILE *file = NULL;
	fopen_s(&file, "Setting.bin", "r");
	if (file != NULL)
	{
		fopen_s(&file, "Setting.bin", "r");
		fscanf_s(file, "%d\t%\d\t%d\t%d\n", &setting.SCREEN_W, &setting.SCREEN_H, &setting.mode, &setting.speed_ratio);
	}
	fclose(file);
	return 0;
}

int write_setting(SETTING setting)
{
	FILE *file = NULL;
	fopen_s(&file, "Setting.bin", "wb");
	fprintf_s(file, "%d\t%d\t%d\t%d\n", setting.SCREEN_W, setting.SCREEN_H, setting.mode, setting.speed_ratio);
	fclose(file);
	return 0;
}

int init_setting(SETTING &setting)
{
	FILE *file = NULL;
	fopen_s(&file, "Setting.bin", "wb");
	fprintf_s(file, "%d\t%\d\t%d\t%d\n", setting.SCREEN_W, setting.SCREEN_H, setting.mode, setting.speed_ratio);
	fclose(file);
	return 0;
}

int write_save(SAVE *save)
{
	FILE *file = NULL;
	fopen_s(&file, "Game.save", "wb");
	//fwprintf_s(file, L"%wS\t", save->player);
	fprintf_s(file, "%f\t%d\t%d\t\t", save->level, save->score, save->time);
	fprintf_s(file, "==FISH==\t\t");
	FISH *p = save->fish;
	while (p != NULL)
	{
		fprintf_s(file, "%f\t%f\t%f\t%f\t%f\t%d\t%d\t\t", p->x, p->y, p->s_x, p->s_y, p->level, p->res_num, p->flag);
		p = p->next;
	}
	fclose(file);
	free(save);
	return 0;
}
int load_save(SAVE &save)
{
	FILE *file;
	fopen_s(&file, "Game.save", "r");
	if (file != NULL)
	{
		//fwscanf_s(file, L"%wS\t", save.player);
		save.player = _T("saved");
		fscanf_s(file, "%f\t%d\t%d\t\t", &save.level, &save.score, &save.time);
		fscanf_s(file, "==FISH==\t\t");
		FISH * head = (FISH*)malloc(sizeof(FISH));
		fscanf_s(file, "%f\t%f\t%f\t%f\t%f\t%d\t%d\t\t", &head->x, &head->y, &head->s_x, &head->s_y, &head->level, &head->res_num, &head->flag);
		FISH *p = head;
		//while (!feof(file))
		do
		{
			FISH *temp = p;
			p = (FISH*)malloc(sizeof(FISH));
			temp->next = p;
			fscanf_s(file, "%f\t%f\t%f\t%f\t%f\t%d\t%d\t\t", &p->x, &p->y, &p->s_x, &p->s_y, &p->level, &p->res_num, &p->flag);
		}
		//while (fscanf_s(file, "%f\t%f\t%f\t%f\t%f\t%d\t%d\t\t", &p->x, &p->y, &p->s_x, &p->s_y, &p->level, &p->res_num, &p->flag));
		while (!feof(file));
		save.fish = head;
		fclose(file);
		remove("Game.save");
		return 0;
	}
	else
	{
		return -1;
	}
}

int clear_save()
{
	FILE *file;
	fopen_s(&file, "Game.save", "wb");
	if (file == NULL)
	{
		fprintf_s(file, "");
	}
	return 0;
}