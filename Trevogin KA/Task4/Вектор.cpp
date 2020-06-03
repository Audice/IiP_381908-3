#include "Matrix.h"

int main()
{
    double res;
    int re, re1;
    cout << "Vector size"<<endl;
    do {
        cin >> re;
     } while (re < 3);
    Vector v1(re), v2(re), sum(re), resVec(re);
    Vector* arr = new Vector[re];
    Matrix mat1(re, re), mat2(re, re), mat3(re,re), gesmas(re, re);
    v1.Random();
    v2.Random();
    arr[1] = v1;
    arr[2] = v2;
    cout << "Generated vectors for this example"<< endl;
    cout << v1 << endl << v2<<endl;
    cout<<endl<<"Lenght between vectors   "<<v1.lenghtbwnvec(v2)<<endl<<endl;
    cout <<"+ result is "<< v1 + v2 << endl;
    cout <<"- result is " << v1 - v2 << endl;
    cout <<"* result is "<< v1 * v2 <<endl;
    for (int i = 3; i < re; i++)
    {
        v2.Random();
        arr[i] = v2;
    }
    cout << endl << "Generated vectors for this example" << endl << endl;;
    for (int i = 1; i < re; i++)
        cout << arr[i];

    cout <<endl<< "Vector product result is " << v1.vectorProizv(arr) <<endl;
  

    for (int i = 0; i < re; i++)
    {
        v1.Random();
        mat1.Set(v1, i);
        v1.Random();
        mat2.Set(v1, i);
    }
   
    cout << endl;
    cout << "Generated matrices"<<endl;
    mat1.PrintM();
    cout << endl;
    mat2.PrintM();
    cout << endl;

    cout << "Transposed of second matrix" << endl;
    mat3 = mat2.T();
    mat3.PrintM();
    cout << endl;

    cout << "Matrix addition" << endl;
    gesmas = mat1+mat2;
    gesmas.PrintM();
    cout << endl;

    cout << "Matrix subtraction" << endl;
    gesmas = mat1 - mat2;
    gesmas.PrintM();
    cout << endl;

    cout << "Matrix multiplication by 10" << endl;
    gesmas = gesmas * 10;
    gesmas.PrintM();
    cout << endl;

    cout << "Matrix multiplication" << endl;
    gesmas = mat1 * mat2;
    gesmas.PrintM();
    cout << endl;

    cout << "Determinant of second matrix" << endl;
    re1 = mat2.D();
    cout << re1 << endl;
    cout << "Inverse second matrix" << endl;
    gesmas = mat2.T();
    gesmas = gesmas/ re1;
    gesmas.PrintM();
    cout << "Matrix division" << endl;
    gesmas = mat1 / mat2;
    gesmas.PrintM();
    cout << endl;

    cout << "first Matrix in degree 4" << endl;
    gesmas = mat1^4;
    gesmas.PrintM();
    cout << endl;
}
