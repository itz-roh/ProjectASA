linha de compilação:
g++ -std=c++11 -O3 -Wall projAsa1.cpp -lm

linha de compilação do gerador de instâncias:
g++ -O3 -Wall -o random_k random_k.cpp -lm

linha de execução do gerador de instâncias:
./random_k 2 10 0.999 200 300 > testfile

linha de compilação do ficheiro com tempo:
g++ -std=c++11 -O3 -Wall timefile.cpp -lm

linha de execução do fiheiro com o teste:
./a.out < testfile

