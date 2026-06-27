
/*
 *  02010-crypt1  -  main-crypt1.c
 *
 *  Sehr cryptischer C-Code
 *
 *  Beispielprogramme zur Vorlesung "Mikrocomputertechnik"
 *  FH S�dwestfalen - Studiengang Mechatronik
 *
 *  Created on: 16.09.2019
 *      Author: Tobias Ellermeyer
 */


float o=0.075,h=1.5,T,r,O,l,I;
int _,L=80,s=3200;
main(){for(;s%L||(h-=o,T=-2),s;4-(r=O*O)<(l=I*I)|++_==L&&write(1,(--s%L?_<L?--_
%6:6:7)+"World! \n",1)&&(O=I=l=_=r=0,T+=o /2))O=I*2*O+h,I=l+T-r;}
