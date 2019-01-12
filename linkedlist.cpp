#include<iostream>


using namespace std;


class circle{ 

	public:
	
	//Data
	int data;

	//Ptr to the next node
	circle *next;
	
	//Constructor functn that makes ptr to NULL 
	circle(){
	next = NULL;
	}
	

};





class linkedlist {

	public:

	//Head + linked circles

	// Head -> Circle type ptr
	circle * head;
	circle * tail;

	//Construct
	linkedlist(){
	head=NULL;
	tail=NULL;
	}

	//Circles inside linked with each other
	//Rules how circles will be linked


	//Insert

	void insert(int value){
	//If first node is added
	circle *temp = new circle; //new makes circle in heap not stack, new gives address
	
	//insert data in the node
	temp -> data = value;

	//1st node only
	if (head == NULL)
	head = temp;
	

	//other nodes 
	else{
	tail -> next = temp;
	}

	tail = temp;
	

	}


	//count function
	int count() {
	
	circle *current = head;
	int k = 1;
	while (current -> next != NULL) {
	k++;
	current = current -> next;
	}

	return k;
	}

	

	void insertAt (int pos, int value) {

	

	//Reach the place before the pos

	circle *current = head;

	int i = 1;

	
	//for pos != 1
	if(pos != 1) {
	while (i < pos -1) {
	i++;
	current = current->next;
	
	//condition for pos>items in linked list
	if(current->next == NULL) {
	cout<<"The linked list does not have "<<pos<<" nodes."<<endl;
	break;
	}

	}

	

	//create a node

	circle * temp = new circle;
	temp->data = value;

	temp->next = current->next;

	current->next = temp;
	}


	//if pos == 1

	else {
	
	circle * temp = new circle;

	temp->data = value;


	temp->next = current;

	head = temp;

	
	}	
	
	}




	//Deletion

	void del() {
	//store tail in temp
	circle *temp = tail;

	//before tail has to point to null

	circle *current = head;

	while (current->next != tail) {
	
	current =current -> next;

	}

	current->next=NULL;


	//update tail
	tail=current;

	//delete temp 
	delete temp;

	}

	//Delete at functn

	void delAt(int p) {
	
	
	
	circle *current = head;

	int i = 1;
	if(p!=1){	
	while (i < p-1) {
	i++;
	current = current -> next;	
	}

	circle *temp = current -> next;
	
	current -> next = temp -> next;
	
	delete temp;

	}
	else {
	
	circle *temp = head;
	head = head->next;
	delete temp;

	}
	} 


	//Display 

	void display (){

	circle *current = head;
	
	while (current != NULL) {
	
	cout << current->data <<"->";
	current =current -> next;
	
	
	}

	cout<<endl;	
	}

	
};





	int main() {
	
	int c;

	linkedlist l1;

	l1.insert(1);
	l1.insert(2);
	l1.insert(3);

	l1.display();
	l1.del();
	l1.display();

	l1.insertAt(2,4);
	l1.display();

	l1.insertAt(1,5);
	l1.display();

	l1.delAt(3);
	l1.display();
	c = l1.count();
	cout<<"The number of nodes in the linked list are "<<c<<" ."<<endl;

	l1.insert(6);
	l1.display();
	l1.delAt(1);
	l1.display();


	l1.insertAt(3,8);
	l1.display();




	}































