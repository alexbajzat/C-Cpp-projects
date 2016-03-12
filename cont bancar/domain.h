#ifndef DOMAIN_H_INCLUDED
#define DOMAIN_H_INCLUDED

typedef struct {
    float sum;
    unsigned id,io,day;
    char description[20];
}Element;

Element createElement(unsigned id, float sum, unsigned day ,unsigned io, char description[]);

#endif // DOMAIN_H_INCLUDED
