#include <file_operator.h>

int load_setting(SETTING &setting)
{
	FILE *file = NULL;
	fopen_s(&file, "Setting.bin", "r");
	if (file != NULL)
	{
		fscanf_s(file, "%d\t%d\t%d\t%d\n", &setting.SCREEN_W, &setting.SCREEN_H, &setting.mode, &setting.speed_ratio);
	}
	if(file) fclose(file);
	return 0;
}

int write_setting(SETTING &setting)
{
	FILE *file = NULL;
	fopen_s(&file, "Setting.bin", "wb");
	fprintf_s(file, "%d\t%d\t%d\t%d\n", setting.SCREEN_W, setting.SCREEN_H, setting.mode, setting.speed_ratio);
	fclose(file);
	return 0;
}

int write_save(SAVE *save)
{
	FILE *file = NULL;
	char temp_str[BUFFSIZE];
	TcharToChar(save->player, temp_str);
	fopen_s(&file, "Game.save", "wb");
	//	Here needs to do with the wchar_t!
	//fwprintf_s(file, L"%wS\t", save->player);
	fprintf_s(file, "%s\t", temp_str);
	fprintf_s(file, "%f\t%d\t%d\t\t", save->level, save->score, save->time);
	fprintf_s(file, "==PEARL==\t\t");
	fprintf_s(file, "%d\t%d\t%d\t\t", save->pearl.x, save->pearl.y, save->pearl.flag);
	fprintf_s(file, "==FISH==\t\t");
	FISH *p = save->fish;
	while (p != NULL)
	{
		fprintf_s(file, "%f\t%f\t%f\t%f\t%f\t%d\t%d\t\t", p->x, p->y, p->s_x, p->s_y, p->level, p->res_num, p->flag);
		p = p->next;
	}
	if(file) fclose(file);
	free(save);
	return 0;
}
int load_save(SAVE &save)
{
	FILE *file;
	char temp_str[BUFFSIZE];
	wchar_t temp_str_t[BUFFSIZE];
	fopen_s(&file, "Game.save", "r");
	if (file != NULL)
	{
		//	Here need to fight with wchar_t
		fscanf_s(file, "%s\t", temp_str, BUFFSIZE);
		CharToTchar(temp_str, temp_str_t);
		save.player = (wchar_t*)malloc(BUFFSIZE * sizeof(wchar_t));
		wcscpy_s(save.player, BUFFSIZE, temp_str_t);
		fscanf_s(file, "%f\t%d\t%d\t\t", &save.level, &save.score, &save.time);
		fscanf_s(file, "==PEARL==\t\t");
		fscanf_s(file, "%d\t%d\t%d\t\t", &save.pearl.x, &save.pearl.y, &(bool)(save.pearl.flag));
		fscanf_s(file, "==FISH==\t\t");
		FISH * head = (FISH*)malloc(sizeof(FISH));
		fscanf_s(file, "%f\t%f\t%f\t%f\t%f\t%d\t%d\t\t", &head->x, &head->y, &head->s_x, &head->s_y, &head->level, &head->res_num, &head->flag);
		FISH *p = head;
		do
		{
			FISH *temp = p;
			p = (FISH*)malloc(sizeof(FISH));
			temp->next = p;
			fscanf_s(file, "%f\t%f\t%f\t%f\t%f\t%d\t%d\t\t", &p->x, &p->y, &p->s_x, &p->s_y, &p->level, &p->res_num, &p->flag);
		}while (!feof(file));
		p->next = NULL;
		save.fish = head;
		if(file) fclose(file);
		remove("Game.save");
		return 0;
	}
	else
	{
		return -1;
	}
}

//将TCHAR转为char   
//*tchar是TCHAR类型指针，*_char是char类型指针   
void TcharToChar(const TCHAR * tchar, char * _char)
{
	int iLength;
	//获取字节长度   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//将tchar值赋给_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

void CharToTchar(const char * _char, TCHAR * tchar)
{
	int iLength;

	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}