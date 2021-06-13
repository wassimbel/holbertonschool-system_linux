#ifndef _LIBASM_H
#define _LIBASM_H

size_t asm_strlen(const char *str);
int asm_strcmp(const char *s1, const char *s2);
int asm_strncmp(const char *s1, const char *s2, size_t n);
char *asm_strchr(const char *s, int c);
#endif /*_LIBASM_H */
