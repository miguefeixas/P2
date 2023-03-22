const MAX = 10; /* Número máximo de elementos en el vector */

typedef float vect<MAX>; /* Vector de float */
typedef vect matrix<MAX>; /* Matriz de float */
typedef string word<>; /* Palabra */

program CALCULATORPROG {
	version CALCULATORVERS {
		float ADD(float, float) = 1;
		float SUB(float, float) = 2;
		float MUL(float, float) = 3;
		float DIV(float, float) = 4;
		vect ADDV(vect, vect) = 5;
		vect SUBV(vect, vect) = 6;
		vect MULV(vect, int) = 7;
		matrix TRANSPOSE(matrix) = 8;
		bool ISPALINDROME(word) = 9;
	} =1;
} = 0x20000001;
