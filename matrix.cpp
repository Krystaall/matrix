#include<iostream>
using namespace std;

class matrix{
	int a[20][20];
	int r,c;
	int i,j,k;
public:
	matrix(){

	}
	matrix(int row, int column){
		r=row;
		c=column;
	}
		void accept();
		void display();
		void add(matrix m,matrix n);
		void multiplication(matrix m,matrix n);
		void transpose();
		void square();
		void uppertraingular();

};

void matrix::accept()
{
	cout<<"\nEnter number of rows:";
	      cin>>r;
	      cout<<endl;
	      cout<<"\nEnter number of columns:";
	      cin>>c;
	      cout<<endl;
	      for(i=0;i<r;i++)
	      {
	      	for(j=0;j<c;j++)
	         {
	         	cout<<"\nEnter element : ";
	                cin>>a[i][j];
	          }
	      }
}
void matrix::display()
{
	cout<<"\nThe matrix is:"<<endl;
	           for(i=0;i<r;i++)
	           {
	         	        for(j=0;j<c;j++)
	                   {
	            	        cout<<a[i][j]<<"\t";
	                   }
	                   cout<<endl;
	            }
}
void matrix ::add(matrix m,matrix n)
{
	matrix res;
	if(m.r==n.r && m.c==n.c){
	int r=m.r;
	 int c=n.c;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
		 res.a[i][j]=  m.a[i][j] + n.a[i][j];
	    }

	 }
	cout<<"\nThe result of matrix addition is is:"<<endl;
		           for(i=0;i<r;i++)
		           {
		         	        for(j=0;j<c;j++)
		                   {
		            	        cout<<res.a[i][j]<<"\t";
		                   }
		                   cout<<endl;
		            }
	}
	else cout<<"Addition not possible";

}

void matrix::uppertraingular(){
	int flag;
		   for (i = 1; i < r; i++)
			   for (j = 0; j < i; j++)
		   		   if (a[i][j] != 0)
		   			flag = 0;
		   		   else
		   			flag = 1;

		   	if (flag == 1)
		   		cout<<"It is an upper triangular matrix";
		   	else
		   		cout<<"It is not an upper triangular matrix";
		   	cout<<endl;
}

void matrix::square(){
	   if(r==c){
		   cout<<"It is a square matrix" ;
		   }
		   else{
			   cout<<"It is not a square matrix" ;
		   }
	   cout<<endl;

}

void matrix::transpose(){
	 cout<<"\nTranspose of matrix:"<<endl;
		    for(i=0;i<r;i++)
		   {
		   	for(j=0;j<c;j++)
		        {
		      	      cout<<a[j][i]<<"\t";
		        }
		        cout<<endl;
		   }


}

void matrix::multiplication(matrix m, matrix n){
	matrix res;
	if( m.c==n.r){
		int r=m.r;
		 int c=n.c;

	for(int i=0;i<m.r;i++){
		for(j=0;j<n.c;j++)
		{
			res.a[i][j]=0;
	    for(k=0;k<m.c;k++)
	    res.a[i][j]=res.a[i][j]+ (m.a[i][k] * n.a[k][j]);
	    }
	}
	cout<<"\nThe result of multiplication is is:"<<endl;
		 for(i=0;i<r;i++)
		 {
		    for(j=0;j<c;j++)
               {
	   	        cout<<res.a[i][j]<<"\t";
		       }
		       cout<<endl;
		 }
	}
	else{
		cout<<"multiplication is not possible"<<endl;
	}


}

int main()
{
	int ch;
matrix a,b,result;

do{
	cout<<"MENU"<<endl;
	cout<<"1. accept 2 matrices \n2.display 2 matrices \n3. check for square matrix \n4. check for upper triangular matrix \n5.transpose \n6. add \n7.multiply \n8. EXIT"<<endl;
	cout<<"Enter a choice"<<endl;
	cin>>ch;
	switch(ch){
	case 1:
		a.accept();
		b.accept();
		break;
	case 2:
		a.display();
		b.display();
		break;
	case 3:
		a.square();
		break;
	case 4:
		a.uppertraingular();
		break;
	case 5:
		a.transpose();
		break;
	case 6:
		result.add(a, b);
		break;
	case 7:
		result.multiplication(a, b);
		break;
	case 8:
		break;
	default:
		cout<<"enter a valid choice";
		break;
	}
}while(ch!=8);



return 0;
}


