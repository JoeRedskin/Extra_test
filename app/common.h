/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Выводит содержимое указанного файла на экран и нумерует
 */
void shownum(text txt);

/**
 * Сохраняет в указанный файл
 */

void save(text txt,  char *f);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Выводит содержимое указанного файла на экран в порядке строк 2-1 4-3
 */
void showevenbeforodd(text txt);

/**
 * Перемещает курсор на начало предыдущей строки
 */
void mplb(text txt);

/**
 * Вставляет новую строку перед текущей
 */
void pp(text txt, char *new_str);


void randomic(text txt);
#endif
