const MAX = 10; /* Número máximo de elementos en el vector */

typedef float vect<MAX>; /* Vector de float */
typedef vect matrix<MAX>; /* Matriz de float */
typedef string word<>; /* Palabra */

/* Vector resultado */
union calcV_res switch (int errno) {
	case 0:
		vect res;
	default:
		void;
};

/* Matriz resultado */
union calcM_res switch (int errno) {
	case 0:
		matrix res;
	default:
		void;
};

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
		calcV_res ADDV(vect, vect) = 1;
		calcV_res SUBV(vect, vect) = 2;
		calcV_res MULV(vect, float) = 3;
		calcM_res TRANSPOSE(matrix) = 4;
	} =1;
} = 0x20000002;

program PALINDROMECHECKER {
	version PALINDROMECHECKERVERS {
		bool ISPALINDROME(word) = 1;
	} =1;
} = 0x20000003;

