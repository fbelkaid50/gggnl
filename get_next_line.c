 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:26:21 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/02/08 13:19:29 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>
// #include<fcntl.h>
// #include<limits.h>
// #include<stdlib.h>
// #include<unistd.h>
// #define BUFFER_SIZE 5
// void	ft_bzero(void *s, size_t n)
// {
// 	char	*str;
// 	size_t	i;

// 	str = (char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		str[i] = '\0';
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t elementCount, size_t elementSize)
// {
// 	char	*res;

// 	res = malloc(elementSize * elementCount);
// 	if (!res)
// 		return (NULL);
// 	ft_bzero(res, elementSize * elementCount);
// 	return (res);
// }

// void *ft_addback(char *str, char **res)
// {
//     size_t i;

//     i=0;  
//     if (!*res)
//         *res = ft_calloc(1,1);  
//     if (!*res)
//         return NULL; 
//     while(str[i])
//     {
//         (*res)[i]= str[i];
//         i++;
//     }
//     (*res)[i]=0;
//     ////////'\0'?/////
//     return *res;
// }

// size_t check_line(char *str )
// {
//     size_t plc;

//     plc=0;
//     while(str[plc])
//     {
//         if(str[plc]=='\n')
//             return plc;
//             plc++;
//     }
//     return plc;
// }


// size_t ft_strlen(char *str)
// {
//     size_t i;

//     i=0;
//     while(*str++){
//         i++;
//     }
//     return i;
// }

// char *ft_substr(char *str,size_t from , size_t to)
// {
//     char *res;
//     size_t i;

//     i=0;
//     res=malloc((to - from + 1) * sizeof(char));
//     if (!res)
//         return NULL;
//     while(i<(to-from))
//     {
//         res[i]=str[from+i];
//         i++;
//     }
//     res[i]=0;
//     //// the difference etwen '\0'////
//     return res;   
// }

// void ft_edditline(char *str, char **res, size_t plc) {
//     char *bfrline = ft_substr(str, 0, plc + 1);
//     if (!bfrline)
//         return;

//     size_t len = ft_strlen(str);
//     *res = ft_calloc(len + 3, sizeof(char));
//     if (!*res) {
//         free(bfrline); // Freeing bfrline if allocation for *res fails
//         return;
//     }

//     ft_addback(bfrline, res);
//     free(bfrline);

//     (*res)[len + 2] = '\n';

//     char *aftrline = ft_substr(str, plc, len);
//     if (!aftrline) {
//         free(*res);
//         *res = NULL;
//         return;
//     }
//     ft_addback(aftrline, res);
//     free(aftrline);
// }

// char *ft_read(char *str,int fd)
// {
//     ssize_t bytesread ;

//     bytesread =1 ;
    
//     while(bytesread>0)
//     {
//         bytesread = read(fd,str,BUFFER_SIZE); 
//         if (bytesread == -1 )
//         {
//             free(str);
//             return NULL;
//         }
//         str[bytesread]=0;
//         /////////nulldeterminator/////
//     }
//     return (str);
// }
// void *ft_free(char **res,char *str)
// {
//     free (*res);
//     *res = NULL;
//     free(str);
//     return NULL;
// }

// char *get_next_line(int fd)
// {
//     static char *dep;
//     char *buff;

//    buff = malloc((BUFFER_SIZE+1 )*sizeof(char));
//    if(!buff)
//         return NULL;
// //    buff[BUFFER_SIZE+1]=0;
//     if(BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE>INT_MAX)
//         ft_free(&dep,buff);
//     buff= ft_read(buff,fd);
//     if(check_line(buff) == 0)
//         {   
//             dep = ft_calloc(ft_strlen(buff)+2,sizeof(char));
//             if(!dep)
//                 ft_free(&dep,buff);
//             ft_addback(buff,&dep);
//             free (buff);
//         }
//     else
//     {
//             ft_edditline(buff,&dep,check_line(buff));
//             free(buff);
//     }
//     return (dep);
// }

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include<limits.h>
#define BUFFER_SIZE 1024

void ft_bzero(void *s, size_t n) {
    char *str = (char *)s;
    size_t i = 0;
    while (i < n) {
        str[i] = '\0';
        i++;
    }
}

void *ft_calloc(size_t elementCount, size_t elementSize) {
    char *res = malloc(elementSize * elementCount);
    if (!res)
        return NULL;
    ft_bzero(res, elementSize * elementCount);
    return res;
}

void *ft_addback(char *str, char **res) {
    size_t i = 0;
    if (!*res)
        *res = ft_calloc(1, 1);
    if (!*res)
        return NULL;

    while (str[i]) {
        (*res)[i] = str[i];
        i++;
    }
    (*res)[i] = '\0';
    return *res;
}

size_t check_line(char *str) {
    size_t plc = 0;
    while (str[plc]) {
        if (str[plc] == '\n')
            return plc;
        plc++;
    }
    return plc;
}

size_t ft_strlen(char *str) {
    size_t i = 0;
    while (*str++) {
        i++;
    }
    return i;
}

char *ft_substr(char *str, size_t from, size_t to) {
    char *res = malloc((to - from + 1) * sizeof(char));
    if (!res)
        return NULL;
    size_t i = 0;
    while (i < (to - from)) {
        res[i] = str[from + i];
        i++;
    }
    res[i] = '\0';
    return res;
}

void ft_edditline(char *str, char **res, size_t plc) {
    char *bfrline = ft_substr(str, 0, plc + 1);
    if (!bfrline)
        return;

    size_t len = ft_strlen(str);
    *res = ft_calloc(len + 3, sizeof(char));
    if (!*res) {
        free(bfrline); // Freeing bfrline if allocation for *res fails
        return;
    }

    ft_addback(bfrline, res);
    free(bfrline);

    (*res)[len + 2] = '\n';

    char *aftrline = ft_substr(str, plc, len);
    if (!aftrline) {
        free(*res);
        *res = NULL;
        return;
    }
    ft_addback(aftrline, res);
    free(aftrline);
}


char *ft_read(char *str, int fd) {
    ssize_t bytesread;
    while ((bytesread = read(fd, str, BUFFER_SIZE)) > 0) {
        str[bytesread] = '\0';
        return str;
    }
    if (bytesread == -1) {
        free(str);
        return NULL;
    }
    return str;
}

char *get_next_line(int fd) {
    static char *dep = NULL;
    ////seting it to null///
    char *buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return NULL;

    if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX) {
        free(buff);
        return NULL;
    }

    buff = ft_read(buff, fd);

    if (!buff) {
        free(buff);
        return NULL;
    }

    if (check_line(buff) == 0) {
        dep = ft_calloc(ft_strlen(buff) + 2, sizeof(char));
        if (!dep) {
            free(buff);
            return NULL;
        }
        ft_addback(buff, &dep);
        free(buff);
    } else {
        ft_edditline(buff, &dep, check_line(buff));
        free(buff);
    }

    return dep;
}

int main() {
    int fd = open("txt.txt", O_RDONLY);
    if (fd == -1)
        return 1;

    char *line = get_next_line(fd);
    if (line)
        printf("%s", line);

    close(fd);
    free(line);

    return 0;
}
