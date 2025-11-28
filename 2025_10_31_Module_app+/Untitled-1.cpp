#include <fstream>
#include <iostream>  // добавляем для работы с консолью
using namespace std;

int main() {
    ifstream in("123.txt");

    
    long long a, b;
    in >> a >> b;
    
    long long sum = a + b;
    

    cout << sum;
    
    return 0;
}
