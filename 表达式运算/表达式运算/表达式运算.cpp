#include<bits/stdc++.h>
using namespace std;

#define OPSETSIZE 7
unsigned char Prior[7][7] = { //运算符间的优先关系
	  '>','>','<','<','<','>','>',
	  '>','>','<','<','<','>','>',
	  '>','>','>','>','<','>','>',
	  '>','>','>','>','<','>','>',
	  '<','<','<','<','<','=',' ',
	  '>','>','>','>',' ','>','>',
	  '<','<','<','<','<',' ','='
};
char OPSET[OPSETSIZE] = { '+' , '-' , '*' , '/' ,'(' , ')' , '#' }; //运算符集合

double Operate(double a, unsigned char theta, double b) {
	if (theta == '+') return a + b;
	else if (theta == '-') return a - b;
	else if (theta == '*') return a * b;
	else if (theta == '/') return a / b;
}
bool In(char Test, char* TestOp) {
	for (int i = 0; i < 7; i++) {
		if (TestOp[i] == Test) return 1;
	}
	return 0;
} //判断字符Test是否是运算符，是则返回true
char precede(char Aop, char Bop) {
	int i, j;
	for (i = 0; i < 7; i++) {
		if (OPSET[i] == Aop) break;
	}
	for (j = 0; j < 7; j++) {
		if (OPSET[j] == Bop) break;
	}
	return Prior[i][j];
} //返回两个运算符优先级的比较结果 

//以下完成算术表达式求值函数EvaluateExpression(string MyExp)的填空
double EvaluateExpression(string MyExp) //算术表达式求值算法
//设OPTR和OPND分别为运算符栈和运算数栈
//参数MyExp是表达式字符串
{
	stack<char> OPTR;		//运算符栈，字符元素
	stack<double> OPND;	//运算数栈，实数元素
	
	
	char TempData[20];
	double Data, a, b, r;
	int pos = 0;
	char theta, c, x, Dr[2];
	OPTR.push('#');
	strcpy_s(TempData, "\0");
	int i = 0;		//表达式字符串的当前字符位置
	c = MyExp[i];	//表达式字符串的当前字符

	//逐个读入表达式字符串的字符到变量c，并识别为数值或运算符，做相应处理
/********** Write your code here! **********/
	while (MyExp[i]!='#'||OPTR.top()!='#') {
		if (!In(MyExp[i], OPSET)) {
			Dr[0] = MyExp[i];
			Dr[1] = '\0';
			strcat_s(TempData, Dr);
			i++;
			if (In(MyExp[i], OPSET)) {
				sscanf_s(TempData, "%lf", &Data);
				strcpy_s(TempData, "\0");
				OPND.push(Data);
			}
		}
		else if (In(MyExp[i], OPSET)) {
			if (precede(OPTR.top(), MyExp[i]) == '<') {
				OPTR.push(MyExp[i]);
				i++;
			}
			else if (precede(OPTR.top(), MyExp[i]) == '>') {
				a= OPND.top();
				OPND.pop();
				b= OPND.top();
				OPND.pop();
				theta = OPTR.top();
				OPTR.pop(); 	
				OPND.push(Operate(b, theta, a));
			}
			else if (precede(OPTR.top(), MyExp[i]) == '=') {
				OPTR.pop();
				i++;
			}
		}
	}
	return OPND.top();


/*******************************************/
} //这是函数EvaluateExpression的右花括号
//函数EvaluateExpression的代码到此结束


//以下填空完成其他函数的定义，包括函数Operate\函数In\函数precede
//可以参考教材光盘中文件夹CHAP03的源代码ALGO0304.cpp，几乎照抄
/********** Write your code here! **********/




/*******************************************/
//主函数
int main()
{
	string Exp;
	int t;
	double result;
	cin >> t;
	while (t--)
	{
		cin >> Exp;
		result = EvaluateExpression(Exp);
		cout << fixed << setprecision(2) << result << endl;
	}

	return 0;
}
