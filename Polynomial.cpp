//anil kumar 19HCS4068
#include<iostream>
using namespace std;
class polynomial
{
private:
    int degree;
    int a[20];
public:
    polynomial()
    {
        degree=0;
    }
    polynomial(int deg)
    {
        degree=deg;
    }
    ~polynomial()
    {
        //cout<<"this is destructor";
    }
    void storePolynomial()
    {
        int i;
        cout<<"enter the terms:"<<endl;
        for(i=degree; i>=0; i--)
        {
            cin>>a[i];
        }
    }
    void display()
    {
        int i;
        for(i=degree; i>=0; i--)
        {
            if(i==0)
            {
                cout<<a[i];
            }
            else if(i==1)
            {
                cout<<a[i]<<"x"<<" + ";
            }
            else
            {
                cout<<a[i]<<"x^"<<i<<" + ";
            }
        }
    }
    polynomial operator+(polynomial ob)
    {
        polynomial temp;
        int maxi=max(this->degree,ob.degree);
        int mini=min(this->degree,ob.degree);
        temp.degree=maxi;
        int i;
        for (i=0; i<=mini; i++)
        {
            temp.a[i]=this->a[i]+ob.a[i];
            cout<<temp.a[i]<<endl;
        }
        for(i=mini+1; i<=maxi; i++)
        {
            if(this->degree>ob.degree)
            {
                temp.a[i]=this->a[i];
            }
            else
            {
                temp.a[i]=ob.a[i];
            }
        }
        return temp;
    }
    polynomial operator-(polynomial ob)
    {
        polynomial temp;
        int maxi=max(this->degree,ob.degree);
        int mini=min(this->degree,ob.degree);
        temp.degree=maxi;
        int i;
        for (i=0; i<=mini; i++)
        {
            temp.a[i]=this->a[i]-ob.a[i];
            cout<<temp.a[i]<<endl;
        }
        for(i=mini+1; i<=maxi; i++)
        {
            if(this->degree>ob.degree)
            {
                temp.a[i]=this->a[i];
            }
            else
            {
                temp.a[i]=-ob.a[i];
            }
        }
        return temp;
    }
    polynomial operator=(polynomial firstPolynomial)
{
    polynomial temp;
    int i;
    temp.degree=firstPolynomial.degree;

    for(i=0;i<=firstPolynomial.degree;i++){
        temp.a[i]=firstPolynomial.a[i];
    }

    return temp;

}

    };
    int main()
    {
        int degFirst,degSecond;
        cout<<"enter degree1:";
        cin>>degFirst;
        cout<<"enter degree2:";
        cin>>degSecond;
        polynomial firstPolynomial(degFirst);
        polynomial secondPolynomial(degSecond);

        firstPolynomial.storePolynomial();
        secondPolynomial.storePolynomial();

        polynomial thirdPolynomial=firstPolynomial+secondPolynomial;
        polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
        cout<<"\n\nthe first polynomial is\n";
        firstPolynomial.display();
        cout<<"\n\nthe second polynomial is\n";
        secondPolynomial.display();
        cout<<"\n\nthe sum is\n";
        thirdPolynomial.display();
        cout<<"\n\nthe difference is\n";
        fourthPolynomial.display();
        polynomial fifthPolynomial=firstPolynomial;
        cout<<"\n\nafter use of  assignment operator\n";
        fifthPolynomial.display();
        return 0;
    }
