#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
template<typename T>
class Trapez{
private:
    T * ptr; // 0 - малка основа , 1 - голяма освнова , 2 - бедро
public:
    Trapez(){
    ptr = new T[3];
    cout << "Default Constructor" << endl;
    }
    Trapez(const Trapez<T>& cop)
    {
        ptr = new T[3];
        for(int i=0; i < 3; i++) ptr[i] = cop.ptr[i];
        cout << "Copy constructor " << endl;
    }
    ~Trapez(){
    cout << "Destructor" << endl;
    delete [] ptr;
    }
    Trapez(T a, T b,T c){ // A malka osnova, B golqma osnova ,C e bedroto
    ptr = new T[3];
    cout << "Constructor" << endl;
        if(a > 0 && b > 0 && c > 0){
            ptr[0] = a;
            ptr[1] = b;
            ptr[2] = c;
    }
    }
    Trapez& operator=(const Trapez<T>& t)
    {
        if (this != &t)
        {
             for(int i=0; i < 3; i++) ptr[i] = t.ptr[i];
        }
        return *this;
    }
    T obikolka() const{
    return ptr[0] + ptr[1] + ptr[2];
    }

    double area() const
    {
        double t = (ptr[1] + ptr[0])/(4*(ptr[1] - ptr[0])); // формула по 4-те страни на трапеца

        double fin = sqrt((ptr[1] + ptr[2] - ptr[0] + ptr[2])*(ptr[1] - ptr[2] - ptr[0] + ptr[2])*(ptr[1] + ptr[2] - ptr[0] - ptr[2])*(-(ptr[1] + ptr[2] + ptr[0] + ptr[2])));
        return t*fin;
    }
    bool operator !(){
        if(ptr[0] == ptr[1])
            return true;
    }
    bool operator !=(Trapez<T> & b){
    if(ptr[0] == b.ptr[0] && ptr[1] == b.ptr[1] && ptr[2] == b.ptr[2])
        return true;
    }
    Trapez<T> operator ++(int dummy){
    // +1;
    Trapez<T> cop(*this);
    for(int i =0;i<2;i++)
        ptr[i] += 1;
    return cop;
    }
    friend ostream & operator <<(ostream & out,const Trapez<T> & t){
    out << t.ptr[0] << " " << t.ptr[1] << " " << t.ptr[2] << endl; // малка основа, голяма основа,бедро
    return out;
    }
};

int main()
{
    Trapez<int> s;
    Trapez<int> d = s;
    Trapez<int> t(2,4,5);
    Trapez<int> k(4,4,5);

    if(!k)
        cout << "operator !" << endl;
    t++;
    cout << t;
    cout << t.obikolka() << endl;
    s = t;
    cout << s << " " << s.area() << endl;
    return 0;
}