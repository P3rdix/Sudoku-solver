#include <iostream>
#include <stdio.h>

class sudoku{
    public:
    int matrix[81];
    void entry();
    void ext();
    int chsq();
    int s(int*);
    int chr();
    int chc();
};

void sudoku::entry(){
    std::cout<<"Enter sudoku";
    for(int i=0;i<81;i++){
        std::cin>>*(matrix+i);
    }
    return;
};

void sudoku::ext(){
    std::cout<<"Sudoku: \n";
    for(int i=0;i<81;i++){
        std::cout<<*(matrix+i)<<" ";
        if(i%9==8){
            std::cout<<"\n";
        }
    }
    return;
};

int main(){
    sudoku trial;
    trial.entry();
    std::cout<<trial.chc()<<"\n";
    trial.ext();
}

int sudoku::chsq(){
    int x=0,y=0,z=0;
    while(x!=3){
        if(x==2 && y!=2){
            x=0;
            y++;
        }
        else{
            x++;
        }
        int* a=matrix+3*x+27*y;
        z=s(a);
        if(z!=0){
            return z;
        }
    }
    return 0;
};

int sudoku::s(int* a){
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(*(a+i%3+9*(i/3))!=0 && *(a+j%3+9*(j/3))==*(a+i%3+9*(i/3))){
                return 1;
            }
        }
    }
    return 0;
};

int sudoku::chr(){
    for(int i=0;i<81;i++){
        if(*(matrix+i)==0){
            continue;
        }
        for(int j=0;j<9;j++){
            if(*(matrix+9*(i/9)+j)==*(matrix+i) && 9*(i/9)+j!=i && *(matrix+9*(i/9)+j)!=0){
                return 1;
            }
        }
    }
    return 0;
}

int sudoku::chc(){
    for(int i=0;i<81;i++){
        if(*(matrix+i)==0){
            continue;
        }
        for(int j=0;j<9;j++){
            if(*(matrix+i%9+j*9)==*(matrix+i) && (i%9)+(9*j)!=i && *(matrix+i%9+j*9)!=0){
                return 1;
            }
        }
    }
    return 0;
}
