#include <iostream>

using namespace std;

float f(float x){
    // площадь какой фигуры вычислять я так и не понял
	// нужно подставить формулу 
	return 2*x*x*x-7*x*x+4*x-4; 
}

// отрезок интегрирования [A, B]. 
// количество шагов разбиения: n
// дополнительная инфа про методы: https://habr.com/ru/post/479202/

dobule retangle_method(double A, double B, int n){
	double y;
	double retangle_integral = 0;
	retangle_integral = (f(A) + f(B))/2;
    double h = (B-A)/n;	
	for (int i = 1; i < n; i ++){ 
		retangle_integral += f(A + i*h);
	}
	retangle_integral *= h;
	return retangle_integral;
}

double trapezoidal_method(double A, double B, int n){
    double h = (B-A)/n;
	double trapezoidal_integral = 0;
	for(int i = 0; i < n; i ++) {
        double y1 = A + i*h;
        double y2 = A + (i+1)*h;
        trapezoidal_integral += 0.5*(y2-y1)*(f(y1) + f(y2));
    }
    return trapezoidal_integral;
}

double simpson_method(double A, double B, int n) {
    double width = (B-A)/n;
    double simpson_integral = 0;
    for(int i = 0; i < n; i ++) {
        double y1 = A + i*h;
      	double y2 = A + (i+1)*h;
        simpson_integral += (y2-y1)/6.0*(f(y1) + 4.0*f(0.5*(y1+y2)) + f(y2));
    }

    return simpson_integral;
}

int main() {
	int n1, n2, n3;
	float A = 0, B = 2;
	char exit_symbol = 'a'; // выходим по q
	while (exit_symbol != 'q') {
		cout << "Введите число разбиений: n1, n2, n3" << endl;
		cin >> n1 >> n2 >> n3;
		// в условии нет ввода отрезка интегрирования
		// cin >> A >> B;
		cout << '-------------------------------------------------------' << endl;
		cout << '| ' << setw(20) << 'Число разбиений' << '|' << setw(20) << 'Результат' << '|' << endl;
		cout << setw(20) << " " << '|' << '------------------------------' << endl;
		cout << '|' << setw(20) << 'n' << '|' << setw(20) << 'A' << setw(20) << 'B' << setw(20) << 'C' << endl;
		cout << '-------------------------------------------------------' << endl;
		cout << '|' << setw(20) << n1 << '|' << setw(20) << retangle_method(A, B, n1) << '|'  << setw(20) << trapezoidal_method(A, B, n1) << '|' << setw(20) << simpson_method(A, B, n1) << '|' << endl;
		cout << '|' << setw(20) << n1 << '|' << setw(20) << retangle_method(A, B, n2) << '|'  << setw(20) << trapezoidal_method(A, B, n2) << '|' << setw(20) << simpson_method(A, B, n2) << '|' << endl;
		cout << '|' << setw(20) << n1 << '|' << setw(20) << retangle_method(A, B, n3) << '|'  << setw(20) << trapezoidal_method(A, B, n3) << '|' << setw(20) << simpson_method(A, B, n3) << '|' << endl;
		cout << '-------------------------------------------------------' << endl;
		cout << "Для выхода нажмите q" << endl;
		cin >> exit_symbol;
	}
	
	return 0;
}


#include <string>
#include <random>
const int K = 2;
const int L = 7;
const int M = 20;
const int N = 10;
using namespace std;

string generate(int k, int l){
	const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int length;
    srand (time(NULL));
    string random_string;
	length = (rand() % l + k) % l; 

    for (int i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[rand() % length(CHARACTERS)];
    }
    return random_string;
}
bool validate_string(sting s){
	// проверка условия зависит от номера зачетки
	return true;
}

bool validate_column_or_row(string *matrix){
	// проверка условия зависит от номера зачетки
	return true;
}
bool validate(string *matrix){
	int count = 0;
	for (int i = 0; i < N; i ++){
		for (int j = 0; j < M; j ++){
			if (validate_string(matrix[i][j])) {
				validate_column_or_row();
			}
		}
	}
}

int main(){
	string matrix[N][M];
	// create matrix
	for (int i = 0; i < N; i ++){
		for (int j = 0; j < M; j ++){
			matrix[i][j] = generate(k, l);
		}
	}
	// check matrix
	for (int i = 0; i < N; i ++){
		for (int j = 0; j < M; j ++){
			validate(matrix);
		}
	}

	return 0;
}
