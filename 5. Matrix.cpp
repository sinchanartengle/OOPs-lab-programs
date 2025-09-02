#include<iostream>

#define MAX 10

using namespace std;

class MATRIX
{
    int row;
    int col; 
    int mat[MAX][MAX];

    public:
    //MATRIX(){};
    MATRIX(int r=0,int c=0)
    {
        row = r;
        col = c;
    }

    friend istream& operator>>(istream &input,MATRIX &m)
    {
        if(m.row == 0 && m.col == 0)
        {
            cout<<"Enter the Row size : ";
            input>>m.row;

            cout<<"Enter the Column size : ";
            input>>m.col;
        }

        for(int i=0;i<m.row;i++)
        {
            cout<<"Enter row "<<i+1<<" elements : \n";
            for(int j=0;j<m.col;j++)
            {
                input>>m.mat[i][j];
            }
        }

        return input;
    }

    friend ostream& operator<<(ostream &os,MATRIX m)
    {
        if(m.row == 0 && m.col == 0)
        {
            os<< "EMPTY MATRIX\n";
        }

        for(int i=0;i<m.row;i++)
        {
            for(int j=0;j<m.col;j++)
            {
                os<<m.mat[i][j]<<" ";
            }
            os<<"\n";
        }

        return os;
    }


    bool operator==(MATRIX m2)
    {
        return ((row == m2.row) && (col == m2.col));
    }

    MATRIX operator+(MATRIX m2)
    {
        MATRIX m3 (this->row,this->col);

        for(int i=0;i<this->row;i++)
        {
            for(int j=0;j<this->col;j++)
            {
                m3.mat[i][j] = this->mat[i][j] + m2.mat[i][j];
            }
        }
        return m3;
    }

    MATRIX operator-(MATRIX m2)
    {
        MATRIX m3{row,col};

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                m3.mat[i][j] = mat[i][j] - m2.mat[i][j];
            }
        }
        return m3;
    }
};

int main()
{
    MATRIX m1,m2,m3;

    cout<<"Matrix 1 : \n";
    cin>>m1;

    cout<<"Matrix 2 : \n";
    cin>>m2;

    if(m1==m2)
    {
        m3 = m1+m2;
        cout<<"Addition of Matrices : \n";
        cout<<m3;

        m3 = m1-m2;
        cout<<"Subtraction of Matrices : \n";
        cout<<m3;
    }
    else
    {
        cout<<"INCOMPATIBLE MATRICES\n";
    }
}