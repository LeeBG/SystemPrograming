/*
 * formprocess.c
 * 
 * Copyright 2019 BG <bg@bg-virtual-machine>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

/* formprocess.c */
/* fork example */
#include <sys/types.h>
#include <unistd.h>


#include <stdio.h>

int main(int argc, char **argv)
{
	pid_t pid;			/*부모에서 프로세스 식별번호 저장*/
	printf("Callnig fork \n");
	pid = fork();
	if(pid == 0)
		printf("I'm the child process\n");
	else if(pid > 0)
		printf("I'm the parent process\n");
	else
		printf("fork failed\n");
	return 0;
}

