#include<stdio.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<termios.h>
#include<unistd.h>
#include"tetris.h"

GameMode::ReadKeyboardRealTime(char &in_char){
	char in_char = 0; /* 入力されたキーを保持 */
	char read_byte = 0; /* 読み込んだバイト数 */
	struct termio tty_backup; /* 変更前の設定を保持 */
	struct termio tty_change; /* 変更後の設定を保持 */


	/* 最初に現在の設定を退避します */
	ioctl(0, TCGETA, &tty_backup);
	tty_change = tty_backup;


	/* 設定を変更し、反映させます */
	tty_change.c_lflag &= ~(ECHO | ICANON); /* エコーを止め、RAW モードへ変更 */
	tty_change.c_cc[VMIN] = 0;
	tty_change.c_cc[VTIME] = 1;
	ioctl(0, TCSETAF, &tty_change);

	/*      文字入力                */
	while(in_char   !=      0x0a)
	{
		read_byte = read(0, &in_char, 1);
		switch(read_byte)
		{
			case    -1:
				/* 退避していた設定に戻す */
				ioctl(0, TCSETAF, &tty_backup);
				/* 異常終了 */
				return 1;
			case    0:
				/*      なにもしない    */
				putchar('.');
				fflush(NULL);
				break;
			default:
				putchar(in_char);
				fflush(NULL);
		}
	}

	/* 退避していた設定に戻す */
	ioctl(0, TCSETAF, &tty_backup);

	/* 正常終了 */
	return 0;
}
