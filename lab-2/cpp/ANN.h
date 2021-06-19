
const double LEARNING_RATE=0.01;

class Input
{
private:
    double input;
public:  
    double output;
    double weight[2];
    void Calsum();
    void Itera(double nexterror1,double nexterror2);
    void In(double in);
    void wei(double x,double y);
    Input(/* args */);
};

class Hidden
{
private:
    double input[3];
public:  
    double theta;
    double output;
    double error;
    double weight[2];
    void Calres1(Input a, Input b, Input c);
    void Calres2(Input a, Input b, Input c);
    void Calerror(double nexterror,double nexterror2);
    void Itera(double nexterror, double nexterror2);
    void In(double in1,double in2,double in3); 
    Hidden();  
};

class Out
{
private:
    double lable;
    double input[2];
public:
    double theta;
    double output;
    double error;
    void calres1(Hidden h1, Hidden h2);
    void calres2(Hidden h1, Hidden h2);
    void calerror();
    void Inres(double lab);
    void In(Hidden h1,Hidden h2);
    void Itera();
    Out();
};