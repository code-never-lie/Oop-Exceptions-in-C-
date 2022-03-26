Exception Handling

- Exception are runtime unusual events.

Example : Disk full, out of memory, divide by zero, array index out of bounds, 

- Exception will immediately crash/abort the program.

Example: Divide by zero

void main(){
	int i;
	cin>>i;
	int y=9/i;
	cout<<y<<endl;
	cout<<"End of main"<<endl;
}

Note: Dividing by zero is beyond the power of a processor.

..............................................

Example 2: Null pointer Exception

class Car{
private:
	int price;
public:
	Car(){price=4000;}
	void m(){cout<<"I am car"<<price<<endl;}
};

void main(){
	Car *c=NULL;
	c->m(); //null pointer exception
	cout<<"End of Main"<<endl;
}

...............................................

- A program with unhandled exceptions are called highly unreliable program.

- Unethical programmer : who can't manage exceptions.

Major Issue in Software Industry

Example: Plugins or APIs

*API: Application Programmer Interface; in simple words, redimade functions or classes.

- Two companies: A and B. Company A developed F function and marketed it. Company B wants to use F function in their applications.

void f(int i){
	cout<<"Start of Function F"<<endl;
	int y=9/i;
	cout<<y<<endl;
	cout<<"End of Function F"<<endl;
}

// Company B Software

void f1(int n){
	cout<<"Start of Function F1"<<endl;
	f(n);
	cout<<"End of Function F1"<<endl;	
}

void main(){
	cout<<"Start of Main"<<endl;
	int i;
	cin>>i;
	f1(i);
	cout<<"End of Main"<<endl;
}

- Such types of aborts are known as cascade aborts.
- Cascade Aborts mean abort whole hierarchy.

...................................................

How to Handle Exceptions?

Step 1: Diagnose all risky statements from your code.
Step 2: Diagnose all dependant statements whose execution depends on risky statements.
Step 3: Mark risky plus dependant statements into try catch block. (sandbox)

try{
Risky Statements

Dependant Statements
}catch(){action}

Example: Divide By Zero

void main(){
	int i;
	cin>>i;

	try{
	int y=9/i; //risky statement
	cout<<y<<endl; //dependant statement
	}catch(...){cout<<"Divide by zero"<<endl;}

	cout<<"End of main"<<endl;
}

... operator : it will catch all types of exceptions.

Ethical Programming

- Ethical programmer handles exceptions using two techniques:

Method 1. Handle all exceptions by try catch block.
Method 2. Inform others about the exceptions without handling exceptions.

Example: Method 1 

void f(int i){
	cout<<"Start of Function F"<<endl;
	try{
		int y=9/i;
		cout<<y<<endl;
	}catch(...){cout<<"Divide by Zero"<<endl;}
	cout<<"End of Function F"<<endl;
}

// Company B Software

void f1(int n){
	cout<<"Start of Function F1"<<endl;
	f(n);
	cout<<"End of Function F1"<<endl;	
}

void main(){
	cout<<"Start of Main"<<endl;
	int i;
	cin>>i;
	f1(i);
	cout<<"End of Main"<<endl;
}

Example : Method 2

void f(int i)throw(int){
	cout<<"Start of Function F"<<endl;
	try{
		int y=9/i;
		cout<<y<<endl;
	}catch(...){throw 2;}
	cout<<"End of Function F"<<endl;
}

// Company B Software

void f1(int n){
	cout<<"Start of Function F1"<<endl;
	try{
	f(n);
	}catch(int a){cout<<"Divide by Zero "<<a<<endl;}
	cout<<"End of Function F1"<<endl;	
}

void main(){
	cout<<"Start of Main"<<endl;
	int i;
	cin>>i;
	f1(i);
	cout<<"End of Main"<<endl;
}

.................................................

Types of Exceptions

1. System Exceptions
2. Business Exceptions (User-defined Exceptions)

System Exception Examples: Divide by zero, disk full, null pointer exception, out of memory.

Business Exception Example(s): ATM withdrawal ( when requested amount > current balance )

.................................................

class BankException{
private:
	char msg[20];
public:
	BankException(){}
	BankException(char n[]){strcpy(msg,n);}
	void setMsg(char n[]){strcpy(msg,n);}
	char* getMsg(){return msg;}
};

class Account{
private:
	int balance;
public:
	Account(){}
	Account(int b){balance=b;}
	void deposit(int b){balance=balance+b;}
	bool withdraw(int amt)throw(BankException){
		if(amt<balance){
			balance=balance-amt;
			return true;
		}
		else{
			throw BankException("Out of Balance");
		}
	}
};

void main(){
	int i;
	cin>>i;
	Account obj(5000);
	try{
	if(obj.withdraw(i))
		cout<<"Successfully withdrawn."<<endl;
	}catch(BankException ob){cout<<ob.getMsg()<<endl;}
	cout<<"End of Main"<<endl;
}
