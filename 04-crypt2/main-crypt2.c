/*
 *  02020-crypt2  -  main-crypt2.c
 *
 *  Eine andere Variante schwer lesbaren Codes
 *  hier werden Befehle über #define umdefiniert...
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH Südwestfalen - Studiengang Mechatronik
 *
 *  Created on: 16.09.2019
 *      Author: Tobias Ellermeyer
 */

#include <stdio.h>
#define o_ main
#define o_o for
#define ___o printf
#define o__ if
#define _o_ int
#define o_o_ 3
#define _o_o 2
#define o_oo (o_o_+_o_o)
#define o_ooo o_oo*_o_o
#define __oo_(_o) ___o("%d",_o)

o_(){_o_ _,__;__oo_(_o_o);___o(",");__oo_(o_o_);
o_o(_=o_oo;_<(o_ooo*o_oo*o_oo);_+=_o_o){
o_o(__=o_o_;__*__<=_&&!(_%__==0);__+=_o_o){}o__(__*__>_)
{___o(",");__oo_(_);}}}

