//
//  main.cpp
//  nbonacci
//
//  Created by Kelson on 9/6/24.
//

#include <iostream>
#include <string>
#include <array>

long nbonacci(unsigned int series, unsigned int n){
    if(n < series){
        return 1;
    }
    long sum{0};
    for(int i{1}; i <= series; i++){
        sum += nbonacci(series, n - i);
    }
    return sum;
}

void computeNbonacciRatio(std::string title, unsigned int series){
    std::cout << "I am the computeNbonacciRatio function!\n";
}

int main(int argc, const char * argv[]) {
    
    std::array<std::string, 4> naccis = {"Fibonacci", "Tribonacci", "Fourbonacci", "Fivebonacci"};
    
    for(int series{0}; series < 4; series++){
        std::cout << "--- " << naccis[series] << " Sequence" << " ---\n";
        for(int n{0}; n < 20; n++){
            long output = nbonacci(series + 2, n);
            std::cout << output << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
