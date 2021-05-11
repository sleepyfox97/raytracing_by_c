#include "./miniRT.h"

void	ft_put_rtfile_error(char **line, int i)
{
	printf("\x1b[41m  \x1b[37m===Error===\x1b[39m  \x1b[49m\n");
	printf("type       : \x1b[33m.rt file error\033[m\n");
	if (i == 0)
		printf("\x1b[32myour .rt file is empty. check the file again\033[m\n");
	else
	{
		printf("error line : ");
		printf("\"\x1b[36m%s\x1b[39m\"\n\n", line[i]);
		printf("<you should check>\n");
		printf("0 : check every elemnts really in this line?\n");
		printf("1 : check wrong number input like \"0..0\" or \"10,,10\"\n");
		printf("2 : check the normarize vector is really normarized?\n");
		printf("3 : check the RGB, all in 0 to 256, diveded by \",\"");
		printf("4 : check end of each line is really \"\\n\"");
	}
}

void	ft_put_resolution_error(void)
{
	printf("\x1b[41m  \x1b[37m===Error===\x1b[39m  \x1b[49m\n");
	printf("type       : \x1b[33m.rt file error\033[m\n");
	printf("there is no Resolution line. Check rt file again.\n");
}

void	ft_put_ambient_error(void)
{
	printf("\x1b[41m  \x1b[37m===Error===\x1b[39m  \x1b[49m\n");
	printf("type       : \x1b[33m.rt file error\033[m\n");
	printf("there is no Ambient light line. Check rt file again.\n");
}

void	ft_put_camera_error(void)
{
	printf("\x1b[41m  \x1b[37m===Error===\x1b[39m  \x1b[49m\n");
	printf("type       : \x1b[33m.rt file error\033[m\n");
	printf("there is no Camera line. Check rt file again.\n");
}
