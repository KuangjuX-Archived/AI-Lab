#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "ANN.h"

Input::Input(/* args */)
{
    input=0.0;
    output=0.0;
    srand(1);
    weight[0]=0.6+rand()%1;
    weight[1]=0.3+rand()%1;
}
void Input::wei(double x, double y)
{
    weight[0]=x;
    weight[1]=y;
}
void Input::In(double in)
{
    input=in;
}
void Input::Calsum()
{
    output=input;
}

void Input::Itera(double nexterror1,double nexterror2)
{
        weight[0]+=LEARNING_RATE*1.0*nexterror1*output;
        weight[1]+=LEARNING_RATE*1.0*nexterror2*output;
}


Hidden::Hidden()
{
    output=0.0;
    error=0.0;
    theta=1;
    srand(2);
    weight[0]=0.5+rand()%2;
    weight[1]=0.2+rand()%2;
}
void Hidden::In(double in1,double in2,double in3)
{
    input[0]=in1; input[1]=in2;input[2]=in3;
}
void Hidden::Calres1(Input a, Input b, Input c)
{
    double temp;
    temp=a.output*a.weight[0]+b.output*b.weight[0]+c.output*c.weight[0]+theta;
    output=1.0/(1.0+exp(-1.0*temp));
}
void Hidden::Calres2(Input a, Input b, Input c)
{
    double temp;
    temp=a.output*a.weight[1]+b.output*b.weight[1]+c.output*c.weight[1]+theta;
    output=1.0/(1.0+exp(-1.0*temp));
}
void Hidden::Calerror(double nexterror1,double nexterror2)
{
    double temp=output*1.0*(1.0-output)*(nexterror1*weight[0]+nexterror2*weight[1]);
    error=temp;
}
void Hidden::Itera(double nexterror1, double nexterror2)
{
    weight[0]+=LEARNING_RATE*1.0*nexterror1*output;
    weight[1]+=LEARNING_RATE*1.0*nexterror2*output;
    theta+=LEARNING_RATE*1.0*error;
}

Out::Out()
{
    lable=0.0;input[0]=0.0;input[1]=0.0;
    theta=0.3;
    output=0.0;
    error=0.0;
}
void Out::Inres(double lab)
{
    lable=lab;
}
void Out::In(Hidden h1, Hidden h2)
{
    input[0]=h1.output;
    input[1]=h2.output;
}

void Out::calres1(Hidden h1, Hidden h2)
{
    double temp;
    temp=h1.output*1.0*h1.weight[0]+1.0*h2.output*h2.weight[0];
    output=1.0/(1.0+exp(-1.0*temp));
}
void Out::calres2(Hidden h1, Hidden h2)
{
    double temp;
    temp=h1.output*1.0*h1.weight[1]+1.0*h2.output*h2.weight[1];
    output=1.0/(1.0+exp(-1.0*temp));
}
void Out::calerror()
{
    error=1.0*output*(1-output)*(lable-output);
}
void Out::Itera()
{
    theta+=LEARNING_RATE*error;
}