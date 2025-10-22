#include "../include/cub3d.h"
   
void free_lines(char **lines) 
     
{ 
     
 int i; 
     
 
     
 if (!lines) 
     
 return ; 
     
 i = 0; 
     
 while (lines[i]) 
     
 { 
     
 free(lines[i]); 
     
 i++; 
     
 } 
     
 free(lines); 
     
} 
     
 
     
void ft_free_split(char **arr) 
     
{ 
     
 int i; 
     
 
     
 if (!arr) 
     
 return ; 
     
 i = 0; 
     
 while (arr[i]) 
     
 free(arr[i++]); 
     
 free(arr); 
     
} 
     
 
     
int ft_is_empty_line(char *s) 
     
{ 
     
 int i; 
     
 
     
 if (!s) 
     
 return (1); 
     
 i = 0; 
     
 while (s[i]) 
     
 { 
     
 if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') 
     
 return (0); 
     
 i++; 
     
 } 
     
 return (1); 
     
} 
     