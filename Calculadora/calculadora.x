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
		
	} =1;
} = 0x20000001;

program CALCULATORVPROG {
	version CALCULATORVVERS {
		vect ADDV(vect, vect) = 1;
		vect SUBV(vect, vect) = 2;
		vect MULV(vect, int) = 3;
		matrix TRANSPOSE(matrix) = 4;
	} =1;
} = 0x20000002;

program PALINDROMECHECKER {
	version PALINDROMECHECKERVERS {
		bool ISPALINDROME(word) = 1;
	} =1;
} = 0x20000003;

