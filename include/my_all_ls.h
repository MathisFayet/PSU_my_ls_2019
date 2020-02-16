/*
** EPITECH PROJECT, 2019
** CPE_solostumper_3_2019
** File description:
** lol.h
*/

#ifndef MY_FUNCTION_STR_H
#define MY_FUNCTION_STR_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"

int my_ls(char **argv);
int my_ls_basic(char *argv);
int my_ls_l(char *argv);
int gettype(struct stat info_file);
int getlaw(struct stat info_file);

#endif /* !MY_FUNCTION_STR_H */