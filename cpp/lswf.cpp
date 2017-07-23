/* INPUT:
* 19		
*		
* OUTPUT:		
* 1000101
*/
#include <iostream>
#include <fstream>
#include <list>
#define MAXG 1000001

int fibonacci(int* fib, int N)
{
    fib[0] = 1; fib[1] = 1;
    int lst;

    for(int i = 2; i < N; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        lst = i;
        if(fib[i] > N) break;
    }

    return lst;
}

int main()
{
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    std::list<int> seq;
    std::list<int>::iterator j;

    int N, i;
    in >> N;
    int caracts[MAXG], somma = 0, potSomma;
    int lastc;

    if(N > 4)
        lastc = fibonacci(caracts, N);
    else {
        caracts[0] = 1;
        for(i = 1; i < 4; i++)
            caracts[i] = i;

        switch (N) {
            case 1:
            case 2:
            case 3:
                lastc = N;
                break;
            default:
                lastc = 4;
        }
    }

    for(i = lastc; i > 0; i--) {
        potSomma = somma + caracts[i];
        if(potSomma < N) {
            somma = potSomma;
            seq.push_front(1);
        } else seq.push_front(0);
    }
    seq.push_front(1);
    for(j = seq.begin(); j != seq.end(); j++) out << *j;

    in.close();
    out.close();
    return 0;
}

