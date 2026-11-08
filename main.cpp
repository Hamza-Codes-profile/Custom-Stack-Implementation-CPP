#include <iostream>
using namespace std;
class Node{
	private:
		int obj;
		Node *next;
	public:
		Node():obj(0),next(nullptr){
		}
		void set(int _obj){
			obj = _obj;
		}
		void setNext(Node *_next){
			next = _next;
		}
		int get(){
			return obj;
		}
		Node* getNext(){
			return next;
		}
};

class NumberStack{
	private:
		Node *head;
	public:
		NumberStack():head(nullptr){
		}
		
		void push(int x){
			Node *newNode = new Node();
			newNode->set(x);
			newNode->setNext(head);
			head = newNode;
		}
		
		int pop(){
			if(head!=nullptr){
				int x = head->get();
				Node *temp = head;
				head = temp->getNext();
				delete temp;
				return x;
			}
			else{
				return -1;
			}
		}
		
		bool isPrime(const int number){
			if(number<2){
				return false;
			}
			for(int i=2; i<number; i++){
				if(number%i==0){
					return false;
				}
			}
			return true;
		}
		
		int countPrimes(){
			Node *current = head;
			int totalPrimes = 0;
			int number = 0;
			while(current!=nullptr){
				number = current->get();
				if(isPrime(number)){
					totalPrimes++;
				}
				current = current->getNext();
			}
			return totalPrimes;
		}
		
		int sumPrimes(){
			Node *current = head;
			int sumofPrimes = 0;
			int number = 0;
			while(current!=nullptr){
				number = current->get();
				if(isPrime(number)){
					sumofPrimes += number;
				}
				current = current->getNext();
			}
			return sumofPrimes;
		}
		
		int toBinary(int number){
			NumberStack binary_stk;
			int remainder = 0; //Remainder from division by 2 
			int number_left = number; //Result of number / 2  
			int binary_number = 0; //Actual binary number
			int pop_val = 0; //Popped value from binary_stk
			int digit_place = 1; //points to the current digit place e.g. ones, tens
			while(number_left!=0){
				remainder = number_left%2; //Remainder of number / 2, can only be 1 or 0
				binary_stk.push(remainder); //points to the current digit place e.g. ones, tens
				number_left /= 2; // cutting the number in half
			}
			pop_val = binary_stk.pop();
			while(pop_val!=-1){	//Checking whether stack is empty
				binary_number += pop_val * digit_place; // for every 1, adding a 10 to the binary number 
				digit_place *= 10; //advancing to next place
				pop_val = binary_stk.pop(); //popping next value
			}
			return binary_number;
		}
		
		~NumberStack(){
			Node *temp = head;
			while(head!=nullptr){
				head = head->getNext();	
				delete temp;
				temp = head;
			}
		}
};
int main(){
	string VUID = "BC123456789";
	int idLastDigit = VUID[VUID.length()-1] - '0';
	NumberStack s;
	cout<<"**********************************************"<<endl;
	cout<<"VU ID: "<<VUID<<endl;
	cout<<"**********************************************"<<endl;
	cout<<"Numbers pushed into stack: "<<idLastDigit<<", 18, 23, 29, 41, 45\n\n";
	s.push(idLastDigit);
	s.push(18);
	s.push(23);
	s.push(29);
	s.push(41);
	s.push(45);
	cout<<"Total Prime Numbers: "<<s.countPrimes()<<endl;
	cout<<"Sum of Prime Numbers: "<<s.sumPrimes()<<endl;
	cout<<"**********************************************"<<endl;
	int tobePopped = s.pop();
	cout<<"Popped Number: "<<tobePopped<<endl;
	cout<<"Binary of "<<tobePopped<<": "<<s.toBinary(tobePopped)<<endl;
	cout<<"**********************************************";
	return 0;
}

