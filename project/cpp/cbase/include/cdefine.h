#ifndef  _CDEFINE_H
#define  _CDEFINE_H
#define BAO(a) (a)
#define MAX(a,b)	\
int max(int a,int b)		\
{					\
if(a>b){ return a;}	\
else{ return b;}	\
};

#define swap(x,y,T) do { \
    T temp = (*x);\
    (*x) = (*y); \
    (*y) = temp; \
} while (0)
#endif