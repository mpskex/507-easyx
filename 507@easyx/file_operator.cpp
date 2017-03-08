#include "file_operator.h"

int load_setting(SETTING &setting)
{
	FILE *file = NULL;
	fopen_s(&file, "Setting.bin", "r");
	if (file != NULL)
	{
		fscanf_s(file, "%d\t%\d\t%d\t%d\n", &setting.SCREEN_W, &setting.SCREEN_H, &setting.mode, &setting.speed_ratio);
	}
	fclose(file);
	return 0;
}

int write_setting(SETTING setting)
{
	FILE *file = NULL;
	fopen_s(&file, "Setting.bin", "wb");
	if (file != NULL)
	{
		fprintf_s(file, "%d\t%\d\t%d\t%d\n", setting.SCREEN_W, setting.SCREEN_H, setting.mode, setting.speed_ratio);
	}
	fclose(file);
	return 0;
}

int init_setting(SETTING &setting)
{
	FILE *file = NULL;
	fopen_s(&file, "Setting.bin", "r");
	if (file == NULL)
	{
		fopen_s(&file,"Setting.bin", "wb");
		fprintf_s(file, "%d\t%\d\t%d\t%d\n", setting.SCREEN_W, setting.SCREEN_H, setting.mode, setting.speed_ratio);
	}
	fclose(file);
	return 0;
}
