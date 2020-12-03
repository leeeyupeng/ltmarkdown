#include <stdio.h>
#include "util.h"
#include "slp.h"
#include "prog1.h"

int _maxargs_A_stm(A_stm a);
int _maxargs_A_exp(A_exp e);
int _maxargs_A_stm(A_stm a){
    if(a->kind == A_compoundStm){
        return _maxargs_A_stm(a->u.compound.stm1) + _maxargs_A_stm(a->u.compound.stm2); 
    }
    else if(a->kind == A_assignStm){
        return _maxargs_A_exp(a->u.assign.exp);
    }
    else{
        A_expList el= a->u.print.exps;
        int value = 1;
        while(TRUE){
            if(el->kind == A_pairExpList){
                value += _maxargs_A_exp(el->u.pair.head);
                el = el->u.pair.tail;
            }
            else{
                value += _maxargs_A_exp(el->u.last);
                break;
            }
        }
        return  value;
    }
}
int _maxargs_A_exp(A_exp e){
    if(e->kind == A_idExp){
        return 0;
    }
    else if(e->kind == A_numExp){
        return 0;
    }
    else if(e->kind == A_opExp){
        return _maxargs_A_exp(e->u.op.left) + _maxargs_A_exp(e->u.op.right);
    }
    else{
        return _maxargs_A_stm(e->u.eseq.stm) + _maxargs_A_exp(e->u.eseq.exp);
    }
}
int maxargs(A_stm a){
    return _maxargs_A_stm(a);
}
void interp(A_stm a){

}
int main(){
    printf("Hello Tiger!\n");
    int valuemaxargs = maxargs(prog());
    printf("maxargs:%d",valuemaxargs);

    interp(prog());
    printf("\n");
    return 0;
}