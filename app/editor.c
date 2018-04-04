/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed> ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }
	
        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }
            /* Сохраняем в файл, заданный параметром */
	    if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }


        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
	    if(tracer(txt, 0) != NULL)
		show(txt);
	    else
		fprintf(stderr, "No file\n");
            continue;
        }

	/* Выводим текст с нумирацией */
         if (strcmp(cmd, "shownum") == 0) {
            if(tracer(txt, 0) != NULL)
                shownum(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }
	/* Меняем строки местами в порядке 2-1 4-3 */
	if (strcmp(cmd, "showevenbeforodd") == 0) {
            if(tracer(txt, 0) != NULL)
                showevenbeforodd(txt);
            else
                fprintf(stderr, "No file\n");
            continue;
        }
	/* Переводим курсор в начало предыдущей строки */
	if (strcmp(cmd, "mplb") == 0) {
	   mplb(txt);
	   continue;
	}
	  /* Вставляем новую строку перед текущей */
        if (strcmp(cmd, "pp") == 0) {
	    if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "No arguments\n");
            }
	    else{
		/*char new_str[MAXLINE];
		  sscanf(arg, "%s", new_str);*/
                pp(txt, arg);
	    }
            continue;
	}





	if (strcmp(cmd, "randomic") == 0) {
           randomic(txt);
           continue;
        }

	 /* Вставляем курсор в текст */
        if (strcmp(cmd, "ctp") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "No arguments\n");
            } else {
		int line, pos;
		sscanf(arg, "%d", &line);
	       	if((arg = strtok(NULL, " \n")) == NULL)
		    fprintf(stderr, "No 2nd argument\n");
		else{
		    sscanf(arg, "%d", &pos);
		    /* Исправить ошибку */
		    switch(c_to_pos(txt, line, pos)){
		    case 1:
			fprintf(stderr, "Out of lines\n");
			break;
		    case 2:
			fprintf(stderr, "Out of length\n");
			break;
		    case 3:
			fprintf(stderr, "No file\n");
			break;
		    }
		}
	    }
            continue;
        }
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
