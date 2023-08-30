# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>

// More concise implementation.
typedef struct operation {
    char op;
    double fst_op;
    double sec_op;
} Operation;

// Reads Both Opperands
# define MAX_NUM 2000
void read_opperands(Operation * op) {
    char c;
    char num[MAX_NUM];

    // Skipping Logs 
    while(!isdigit(c))
        c = getchar();

    // First Operand 
    for(int i = 0; i < MAX_NUM && c != '\n' && c != EOF; ++i){ 
        if(isdigit(c))
            num[i] = c;
        else if(isspace(c)) {
            op->fst_op = atof(num);
            break;
        }
        else {
            // Better error handling :D
            fprintf(stderr, "Error : Invalid number %s. At %c \n", num, c);
            exit(EXIT_FAILURE);
        }
        c = getchar();
    }

    // Space between Operands 
    while(isspace(c))
        c = getchar();

    char sec_num[MAX_NUM];
    
    // Second Operand
    for(int i = 0; i < MAX_NUM && c != '\n' && c != EOF; ++i) {
        if(isdigit(c))
            sec_num[i] = c;
        else {
            // Same here
            fprintf(stderr, "Error : Invalid number %s. At %c \n", num, c);
            exit(EXIT_FAILURE);
        }


        c = getchar();
    }
    // atof : alpha to float.
    op->sec_op = atof(sec_num);
    

    return;
}

int main() {

  printf("Enter an operator (+, -, *, /): ");

  // Use special type for it :)
  Operation op;
  op.op = getchar();
  // Only reads one Charachter.
    
  printf("Enter two operands: ");
  
  // scanf is bad and can cause memory vulnerabilies. :>
  // scanf("%lf %lf", &op.fst_op, &op.sec_op);
  //
  read_opperands(&op);

  switch (op.op) {
    case '+':
      printf("%.1lf + %.1lf = %.1lf\n", op.fst_op, op.sec_op, op.fst_op + op.sec_op);
      break;
    case '-':
      printf("%.1lf - %.1lf = %.1lf\n", op.fst_op, op.sec_op, op.fst_op - op.sec_op);
      break;
    case '*':
      printf("%.1lf * %.1lf = %.1lf\n", op.fst_op, op.sec_op, op.fst_op * op.sec_op);
      break;
    case '/':
      printf("%.1lf / %.1lf = %.1lf\n", op.fst_op, op.sec_op, op.fst_op / op.sec_op);
      break;
    // operator doesn't match any case constant
    default:
      printf("Error! operator %c is not correct \n", op.op);
  }

  return 0;
}
