#include<bits/stdc++.h>
using namespace std;

class calculater{
public:
    int num1,num2;
    calculater(){
        num1 = 20;
        num2 = 30;
    }
    //虚函数
    virtual int res(){
        return 0;
    }
    /*或者
    virtual int res() = 0;
    纯虚函数
    */
};

 /*加减乘除的类*/
class add:public calculater{
    int res(){
        return num1+num2;
    }
};

class sub:public calculater{
    int res(){
        return num1-num2;
    }
};

class multi:public calculater{
    int res(){
        return num1*num2;
    }
};

class chu:public calculater{
    int res(){
        return num1/num2;
    }
};
/*end*/


/*计算接口*/
void cal(calculater& C){
    cout<<C.res()<<endl;;
}
/*end*/


void test01(){
    calculater *C = new add;
    C->num1 = 100;
    C->num2 = 200;
    cout<<C->num1<<"+"<<C->num2<<"="<<C->res()<<endl;
    delete C;
}

void test02(){
    calculater *C = new sub;
    C->num1 = 100;
    C->num2 = 200;
    cout<<C->num1<<"-"<<C->num2<<"="<<C->res()<<endl;
    delete C;
}



int main(){
    // test01();
    // test02();
    add A;
    cal(A);
    sub S;
    cal(S);
}
