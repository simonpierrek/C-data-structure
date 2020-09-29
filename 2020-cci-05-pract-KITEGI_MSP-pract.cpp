#include<iostream>
#include <cstring>
#define MAX_DATA_SIZE 1000
using namespace std;

//The following function computes the sum of the first n numbers : 1+2+3+.......+n
int sum_of_numbers(int n) {
 int s=0;
 for (int i=1; i<=n; i++)
	s=s+i;
 return s;
}

void sum() {
 //read a number n and compute the sum of the first n numbers using the function sum_of_numbers(n)
int n;
cout <<  "Enter a number : ";
cin >> n;
cout <<  "The sum of the first " << n << " numbers is : " << sum_of_numbers(n) << "\n";
}

// The following section implements List .................................................
class ListType {
 public:
    ListType(int n) {
    	MAX_ITEMS = n;
    	nbItems = NULL;
    };

    void MakeEmpty(){
    	nbItems = NULL;
    };

    bool IsEmpty() const {
 	return (nbItems == 0);
    };

    bool IsFull() const {
 	return (nbItems == MAX_ITEMS-1);
    };

    void FindNode(int searchItem) {
 	int i = 0;
	while (!((items[i]==searchItem)||(i>nbItems)))
 		i++;
	if (i>nbItems) 
		cout << "\nThe item : " << searchItem << " is not found !\n";
	else 	cout << "\nThe item : " << searchItem << " is found at position " << i << "\n";
    };

    void InsertNode(int position, int newItem) {
 	if (position <= nbItems) {
 	 for (int i=nbItems; i>position; i--)
	  items[i] = items[i-1];
	 items[position] = newItem;
	 nbItems++;
	}
    };

    void DeleteNode(int position) {
 	if (!(nbItems == 0)) {
 	 for (int i=position; i<nbItems; i++)
	  items[i] = items[i+1];
	 items[MAX_ITEMS-1] = 0;
	 nbItems--;
	}
    };

    void Display() {
	cout << "\nContent of the List : \n";
 	for (int i=0; i<nbItems; i++)
 		cout << "\n " << i << "\t" << items[i];
	cout << "\n";
    };

    void RandomNodes() {
  	for(int i=0; i<MAX_ITEMS; i++) items[i]=rand()%100+1;
	nbItems = MAX_ITEMS;
    };
    ~ListType() { }

 private:
    int MAX_ITEMS, nbItems;
    int items[MAX_DATA_SIZE];
};
// The following section implements Stack .................................................

class STACK
{
 private:
        int num[MAX_DATA_SIZE];
        int top;
        int nbItems;
        int stk;
        int MAX_ITEMS;
 public:
        //STACK();    //defualt //constructor
        STACK(int V){
    top=-1;
    MAX_ITEMS=V;
	}
        int push(int);
        int pop();
        int makeEmpty();
        int isEmpty();
        int isFull();
        void displayItems();
	};
		

	int STACK::makeEmpty () {
    nbItems = 0;
	}
 
	int STACK::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;   
	}
 
	int STACK::isFull(){
    if(top==(MAX_ITEMS-1))
        return 1;
    else
        return 0;
	}	
 
	int STACK::push(int n){
    //check stack is full or not
    if(isFull()){
        return 0;
    }
    ++top;
    num[top]=n;
    nbItems++;
    return n;
	}
 
	int STACK::pop(){
    //to store and print which number
    //is deleted
    int temp;
    //check for empty
    if(isEmpty())
        return 0;
    temp=num[top];
    --top;
    return temp;
     
	}
 
	void STACK::displayItems(){
    int i; //for loop
    if (nbItems==0 )
    {
        cout<<"STACK IS EMPTY";
    }
    else{
    cout<<"STACK is: ";
    for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
    }
    cout<<endl;

	}
//The following section implements Queue with Circular list .................................................-----------------------------------------------------------------------------------------------------------------------------

class CircularQueue {
  private:
    int front;
    int rear;
    int arr[MAX_DATA_SIZE];
    int itemCount;
    int MAX_ITEMS;
 
  public:
    CircularQueue(int o) {
    MAX_ITEMS = o;
      itemCount = 0;
      front = -1;
      rear = -1;
      //for (int i = -1; i < MAX_ITEMS; i++) {
        //arr[i] = 0; 
      //}
    }

  	void makeEmpty() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        arr[i] = 0;}
  	}

  	bool isEmpty() {
    if (front == -1 && rear == -1)
      return true;
    else
      return false;
  	}

  	bool isFull() {
    if ((rear + 1) % MAX_ITEMS == front)
      return true;
    else
      return false;
  	}

  	void enqueue(int val) 
     {
        if ((front == 0 && rear == MAX_ITEMS - 1) || (front == rear + 1))
        {
            cout << "Queue Overflow \n";
            //return;
        }
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            if (rear == MAX_ITEMS - 1)
                rear = 0;
            else
                rear = rear + 1;
        }
            arr[rear] = val;
    }
   

	int dequeue() 
        {
        if (front == -1)
        {
            cout << "Queue Underflow\n";
            //return;
        }
        cout << "Element deleted from queue is : " << arr[front] << endl;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if (front == MAX_ITEMS - 1)
                front = 0;
            else
                front = front + 1;
        }
    }
    
 
  	int count() {
    return (itemCount);
  	}
 
  	void display() 
     {
        int front_pos = front, rear_pos = rear;
        if (front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements :\n";
        if (front_pos <= rear_pos)
        {
            while (front_pos <= rear_pos)
            {
                cout << arr[front_pos] << "  ";
                front_pos++;
            }
        }
        else
        {
            while (front_pos <= MAX_ITEMS - 1)
            {
                cout << arr[front_pos] << "  ";
                front_pos++;
            }
            front_pos = 0;
            while (front_pos <= rear_pos)
            {
                cout << arr[front_pos] << "  ";
                front_pos++;
            }
        }
        cout << endl;
    }
};



//The following section implements Selection sort algorithm .................................................-----------------------------------------------------------------------------------------------------------------------------

void selection(int arr[],int n)
{
    /*Selection sort*/
    int i,smallest,k,temp;
    for(i = 0; i< n - 1 ; i++)
    {
        /*Find the smallest element*/
        smallest = i;
        for(k = i + 1; k < n ; k++)
        {
            if(arr[smallest] > arr[k])
                smallest = k ;
        }
        if( i != smallest )
        {
            temp = arr [i];
            arr[i] = arr[smallest];
            arr[smallest] = temp ;
        }
    }/*End of for*/
}
//The following section implements Merge sort algorithm .................................................-----------------------------------------------------------------------------------------------------------------------------

void Merge(int A[],int p, int q,int r)     /*It merges two arrays */
{
    int n1=q-p+1,i,j,k;       /*n1 is the size of L[]*/
    int n2=r-q;               /*n2 is the sixe of R[]*/
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
    }
    i=0,j=0;
    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];
        }
    }
    while(i<n1)             /*If L[] has more elements than R[] then it will put all the reamining elements of L[] into A[]*/
    {
        A[k++]=L[i++];
    }
       while(j<n2)             /*If R[] has more elements than L[] then it will put all the reamining elements of R[] into A[]*/  
    {
        A[k++]=R[j++];
    }
}

void MergeSort(int A[],int p,int r)    /*It will will divide the array and sort them while merging them*/
{
    int q;                                
    if(p<r)
    {
        q=(p+r)/2;                      /*q is the middle element to divide the array*/ 
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}


//The following section implements Sequentialsearch algorithm .................................................-----------------------------------------------------------------------------------------------------------------------------
//    function    :   sequentialSearch()

int sequentialSearch(int *a,int n, int v)
{
    int i,pos=-1;
 
    for(i=0;i<v; i++)
    {
        if(a[i]==n)
        {
            pos=i;
            break;
        }
    }
    return pos;
}

//The following section implements Binarysearch algorithm .................................................-----------------------------------------------------------------------------------------------------------------------------

struct node

{
    int info;
    struct node *left;
    struct node *right;
}*root;

class BST

{

  public:

    void find(int, node **, node **);    
    void insert(node *, node *);
    void del(int);
    void case_a(node *,node *);
    void case_b(node *,node *);
    void case_c(node *,node *);
    void preorder(node *);
    void inorder(node *);
    void postorder(node *);
    void display(node *, int);
    BST()
        {
            root = NULL;
        }
};

	void BST::find(int item, node **par, node **loc)
	{
    node *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        //return;
    }

    if (item == root->info)
    {
        *loc = root;
        *par = NULL;
        //return;
    }

    if (item < root->info)
        ptr = root->left;
    else
        ptr = root->right;
    	ptrsave = root;

    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            //return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->left;
		else
	    ptr = ptr->right;
    }

    *loc = NULL;
    *par = ptrsave;
	}	

 

/*

 * Inserting Element into the Tree

 */

	void BST::insert(node *tree, node *newnode)
	{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node is Added"<<endl;
        //return;
    //}//else if (tree->info == newnode->info)
    //{
       // cout<<"Element already in the tree"<<endl;
        //return;
    }else if (tree->info > newnode->info)
    	{
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);	
		} else
			{
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Node Added To Left"<<endl;
            //return;
        	}
    	} else if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        } else
        {

            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Node Added To Right"<<endl;
            //return;
        }	
    }

/*

 * Case A

 */

	void BST::case_a(node *par, node *loc )
	{
    	if (par == NULL)
    	{
        root = NULL;
    	}

    else
    	{
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    	}

	}

 

/*

 * Case B

 */

	void BST::case_b(node *par, node *loc)
	{
    node *child;
   		 if (loc->left != NULL)
        child = loc->left;
    	else
        child = loc->right;
    		if (par == NULL)
    			{
        root = child;	}

    	else
    		{
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    			}
	}	

 

/*

 * Case C

 */

	void BST::case_c(node *par, node *loc)
	{
    node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    
    while (ptr->left != NULL)
    	{
        ptrsave = ptr;
        ptr = ptr->left;
    		}

    suc = ptr;
    parsuc = ptrsave;
    
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    	{
        root = suc;
    		}
    else
    	{
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    	}
    suc->left = loc->left;
    suc->right = loc->right;
	}

 

/*

 * Pre Order Traversal

 */

	void BST::preorder(node *ptr)
	{
	    if (root == NULL)
	    {
	        cout<<"Tree is empty"<<endl;
	        //return;
	    }
	    if (ptr != NULL)
	    {
	        cout<<ptr->info<<"  ";
	        preorder(ptr->left);
	        preorder(ptr->right);
	    }
	}
/*

 * In Order Traversal

 */

	void BST::inorder(node *ptr)
	{
	    if (root == NULL)
	    {
	        cout<<"Tree is empty"<<endl;
	        //return;
	    }
	    if (ptr != NULL)
	    {
	        inorder(ptr->left);
	        cout<<ptr->info<<"  ";
	        inorder(ptr->right);
	    }
	} 
/*
 * Postorder Traversal
 */
	void BST::postorder(node *ptr)
	{
	    if (root == NULL)
	    {
	        cout<<"Tree is empty"<<endl;
	        //return;
	    }
	    if (ptr != NULL)
	    {
	        postorder(ptr->left);
	        postorder(ptr->right);
	        cout<<ptr->info<<"  ";
	    }
	}
/*
 * Display Tree Structure
 */
	void BST::display(node *ptr, int level)
	{
	    int i;
	    if (ptr != NULL)
	    {
	        display(ptr->right, level+1);
	        cout<<endl;
	        if (ptr == root)
	            cout<<"Root->:  ";
	        else
	        {
	            for (i = 0;i < level;i++)
	                cout<<"       ";
		}
	        cout<<ptr->info;
	        display(ptr->left, level+1);
	    }
	}
//
//Variables needed for the program
	int arraySize;
	int choice;
	int element;
	int position = 0;
	int minValue;
	int maxValue;
	int midValue;
	int searchValue;
	int searchIndex;

//Function declaration: Bubble sort algorithm to sort the array in ascending order
	int sortAscending(int arr[0], int sizeOfArray){
	    for(int i = 0; i <= sizeOfArray-2; i++){
	        for(int j = i+1; j <= sizeOfArray-1; j++){
	            int temp;
	            if(arr[i] > arr[j]){
	                temp = arr[i];
	                arr[i] = arr[j];
	                arr[j] = temp;
	            }
	        }
	    }
	    return 0;
	}

	//Function declaration: Bubble sort algorithm to sort the array in descending order
	int sortDescending(int arr[0], int sizeOfArray){
	    for(int i = 0; i <= sizeOfArray-2; i++){
	        for(int j = i+1; j <= sizeOfArray-1; j++){
	            int temp;
	            if(arr[i] < arr[j]){
	                temp = arr[i];
	                arr[i] = arr[j];
	                arr[j] = temp;
	            }
	        }
	    }
	    return 0;
	}


	//Function declaration: Print the inserted array in a relative format.
	void printArray(int arr[], int sizeOfArray){
	    for(int j = 0; j < sizeOfArray; j++){
	        if(position == 0){
	            cout<<"[ ";
	        }
	        cout<<arr[j];
	        position++;
	        if(position == sizeOfArray){
	            cout<<" ]";
	        }
	        if(position != sizeOfArray){
	            cout<<", ";
	        }
	    }
	    position = 0;
	}



	//Function declaration: Function that implements the binary search algorithm for ascending ordered arrays.
	int binarySearchAlgorithmAscending(int value, int arr[], int sizeOfArray){
	    minValue = 0;
	    maxValue = sizeOfArray - 1;
	    while(minValue <= maxValue){
	        midValue = minValue +(maxValue - minValue)/2;
	        if(arr[midValue] == value)return midValue;
	        if(arr[midValue] < value) minValue = midValue + 1;
	        else maxValue = midValue - 1;
	    }
	    return -1;
	}

	//Function declaration: Function that implements the binary search algorithm for descending ordered arrays.
	int binarySearchAlgorithmDescending(int value, int arr[], int sizeOfArray){
	    minValue = 0;
	    maxValue = sizeOfArray - 1;
	    while(minValue <= maxValue){
	        midValue = minValue +(maxValue - minValue)/2;
	        if(arr[midValue] == value)return midValue;
	        if(arr[midValue] < value) maxValue = midValue - 1;
	        else minValue = midValue + 1;
	    }
	    return -1;
	}

	//Function declaration: Function that recursively calls itself in case the number the user wants to find is not found in the array.
	//Because the binary search algorithm depends on the way the array is sorted, there is a function for both cases. This one, calls
	// binarySearchAlgorithmAscending(int value, int arr[], int sizeOfArray)
	void inCaseOfNotFoundAscending(int arr[], int arraySize){
	    cout<<"\nEnter the value you want to binary search for: ";
	    cin>>searchValue;
	    searchIndex = binarySearchAlgorithmAscending(searchValue, arr, arraySize);
	    if(searchIndex != -1) {cout<<"The value "<<arr[searchIndex]<<" was found at index "<<searchIndex ;
	    	cout<<" Thanks\n";}
	    else{
	        cout<<"The number "<<searchValue<<" was not found in the array";
	        inCaseOfNotFoundAscending(arr, arraySize);
	    }
	}
	//Function declaration: Function that recursively calls itself in case the number the user want to find is not found in the array.
	//Because the binary search algorithm depends on the way the array is sorted, there is a function for both cases. This one, calls
	// binarySearchAlgorithmDescending(int value, int arr[], int sizeOfArray)
	void inCaseOfNotFoundDescending(int arr[], int arraySize){
	    cout<<"\nEnter the value you want to binary search for: ";
	    cin>>searchValue;
	    searchIndex = binarySearchAlgorithmDescending(searchValue, arr, arraySize);
	    if(searchIndex != -1) cout<<"The value "<<arr[searchIndex]<<" was found at index "<<searchIndex;
	    else{
	        cout<<"The number "<<searchValue<<" was not found in the array";
	        inCaseOfNotFoundDescending(arr, arraySize);
	    } 
	}
	//Function declaration: Function that lets the user decide the way the array will be sorted. Depending the choice, either
	//inCaseNotFoundAscending(int arr[], int arraySize) or inCaseNotFoundDescending(int arr[], int arraySize) are called.
	void wayToSort(int arr[], int sizeOfArray){
	    cout<<"\nThe array has to be sorted in order for the binary search algorithm to be used!\nWould you like to sort it in ascending or descending order?\n";
	    cout<<"1)Ascending 2)Descending:";
	    cin>>choice;
	    if(choice == 1){
	        sortAscending(arr, sizeOfArray);
	        cout<<"The array sorted in ascending order is: ";
	        printArray(arr, arraySize);
	        inCaseOfNotFoundAscending(arr, sizeOfArray);
	    }
	    else if(choice == 2){
	        sortDescending(arr, sizeOfArray);
	        cout<<"The array sorted in descending order is: ";
	        printArray(arr, arraySize);
	        inCaseOfNotFoundDescending(arr, sizeOfArray);
	    }
	    else{
	        cout<<"Option not available. Choose one of the available options!";
	        wayToSort(arr, sizeOfArray);
	    }
	}

/*-------------------------------------*/

//Main program begins here ....................................
	int main() {
	char choice = '+';
	char option = '+';
	int size = 0; 
	int  n;
	int temp;
	int choix;
	int value;
	int choic;
	int arr[MAX_DATA_SIZE], i, alchoix, alchoi;
	int A_Size;
	int A[A_Size];
	int num;     /* element to search*/
	int position;
	int count, first, last, middle;
	cout<<"                \n";
	cout<<"                               :::::::KITEGI Simon Pierre, Wascal Informcc Program::::::::::  \n";
 	while (!((choice == 'e')||(choice == 'e'))) {
	cout << "                      Select an option : \n";
	cout << "          n ::     Sum of numbers\n";
	cout << "          l ::     ListType\n";
	cout << "          s ::     StackType\n";
	cout << "          q ::     QueueType\n";
	cout << "          r ::     Sorting algorithm(Selection sort and Merge sort)\n";
	cout << "          o ::     Searching algorithm(Sequential search and Binary search)\n";
	cout << "          t ::     Tree traversals (preorder, inorder and postorder)\n";
	cout << "          e ::     Stop the programm\n";
	cout << "                 Enter your choice : \n";
	cin >> choice; 
	choice = toupper(choice);
		if (choice == 'N') 
        {cout<<"                      -----------------Sum of first numbers operations-----------------\n";
        sum();
        }
		else if (choice =='L') {     
	      //List operations ..................
	       cout << "\nEnter the size of the list : ";
	       cin >> size; 
	       ListType list(size);
	       while (!(option == '0')) {
		cout << "     \nSelect a List operation : ";
		cout << "     \n1.     Create a list";
		cout << "     \n2.     Insert a new item";
		cout << "     \n3.     Delete an item";
		cout << "     \n4.     Find an item";
		cout << "     \n5.     Empty the list";
		cout << "     \n6.     Test whether the list is empty";
		cout << "     \n7.     Test whether the list is full";
		cout << "     \n8.     Fill the list randomly";
		cout << "     \n9.     Display the content of the list";
		cout << "     \n0.     Stop";
		cout << "     \nEnter option : ";
		cin >> option; 
			switch (option) {
				case '1': {ListType list(size); break;}
				case '2': {
			       int position, item;
			       cout << "\nEnter a position and an item : ";
			       cin >> position >> item;
			       list.InsertNode(position, item);
			       break;
			 	}
				case '3': {
			       int position;
			       cout << "\nEnter the position of the item to delete : ";
			       cin >> position;
			       list.DeleteNode(position);
				       break;
				 }
				 case '4': {
			       int item;
			       cout << "\nEnter the item to find : ";
			       cin >> item;
			       list.FindNode(item);
			       break;
				 }
				 case '5': {list.MakeEmpty(); cout << "\nThe list is emptied\n"; break;}
				 case '6': {if (list.IsEmpty()) cout << "\nThe list is empty\n"; else cout << "\nThe list is not empty\n"; break;}
				 case '7': {if (list.IsFull()) cout << "\nThe list is full\n"; else cout << "\nThe list is not full\n"; break;}
				 case '8': {list.RandomNodes(); break;}
				 case '9': {list.Display(); break;}
				 default:  cout<<"************you stop List operations.Thanks!**************\n";
		        	break;}
			       }
		}  
   		else if (choice == 'E') { cout << "----------------You stop your program----------------\n"; exit(0);}
		else if (choice == 'S') {   
            cout<<"                             -----------STACK OPERATIONS-------------          \n";
            cout << "\nEnter the size of the Stack : ";
	        cin >> size; 
	        STACK stk(size);
            while ((choix < 7)) {
        cout<<"     1.       Make the stack Empty."<<endl;
        cout<<"     2.       Test whether the stack is Empty."<<endl;
        cout<<"     3.       Test whether the stack is full."<<endl;
        cout<<"     4.       Push an Item to the top of the stack."<<endl;
        cout<<"     5.       Pop out the Item on the top of the stack."<<endl;
        cout<<"     6.       Print all the elements of the Stack."<<endl;
        cout<<"     7.       stop"<<endl;
        cout<<"         Enter your choice: ";
        cin>>choix;
         
	        switch(choix){
	            
	            case 1: {stk.makeEmpty(); cout << "\nYou make stack is emptied\n"; break;}

	            case 2: {if (stk.isEmpty()) cout << "\nTRUE, the stack is empty\n"; else cout << "\nThe stack is not empty\n"; break;}

	            case 3: {if (stk.isFull()) cout << "\nTRUE,The stack is full\n"; else cout << "\nThe stack is not full\n"; break;}

	            case 4: {
	                cout<<"Enter item to insert: ";
	                cin>>n;
	                temp=stk.push(n);
	                if(temp==0)
	                    cout<<"STACK is FULL."<<endl;
	                else
	                   cout<<temp<<" inserted successfully"<<endl;
	          		break;
	            	}
	                 
	            case 5:
	               { temp=stk.pop();
	                if(temp==0)
	                cout<<"STACK IS EMPTY."<<endl;
	                else
	                cout<<temp<<" is removed (popped)."<<endl;
	           		break;
	        		}
	             
	            case 6: {
	                stk.displayItems();
	               	break;
	            }
	            case 7:{ 
	                cout<<"************you stop Stack operations.Thanks!**************\n";
	                break;}
	            default: 
	                cout<<"An Invalid choice."<<endl; 
	                break;    
	       	 }
    		}
		}

    	else if (choice == 'Q'){
    		      
            cout<<"--------------------------------------------------------------------------------------CIRCULAR QUEUE OPERATIONS-----------------------------------------------------------------\n"; 
            cout << "\nEnter the size of the queue : ";
	        cin >> size; 
	      	CircularQueue q1(size);
            while ((choic < 7)) {
                cout<<"     1.       make a queue empty\n";
                cout<<"     2.       test whether the queue is empty\n";         
                cout<<"     3.       test whether the queue is full\n";
                cout<<"     4.       insert an element at the rear of the queue\n";  
                cout<<"     5.       delete the element at the front of the queue\n";
                cout<<"     6.       Print all the elements of the queue\n";       
                cout<<"     7.       stop\n";
                cout<<"     Enter your choice\n";
                cin >> choic;
       		switch (choic) {
        		
        		case 7: 
	        		{cout<<"************you stop Queue operations.Thanks!**************\n";
	        		break;
	        		}
       			case 1:{
	        		q1.makeEmpty();
	     			cout << "You make your Queue Empty\n";
	      			break;
	    			}
        		case 2:{
	     			if (q1.isEmpty())
	        		cout << "Queue is Empty" << endl;
	      			else
	        		cout << "Queue is not Empty" << endl;
	      			break;
	    			}
        		case 3:
	    			{if (q1.isFull())
	        		cout << "Queue is Full" << endl;
	      			else
	        		cout << "Queue is not Full" << endl;
	      			break;
	        		}
        		case 4:
	        		{ 
	    			cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
	      			cin >> value;
	      			q1.enqueue(value);
	      			cout << value<<" was inserted successfully." <<endl;
	      			break;
	      			}
        		case 5:
	        		{ 
				    q1.dequeue();
				    cout << "you Delete " << value << " successfully." <<endl;
				    break;
	                }
        		case 6: 
	      			{cout << "Display Function Called - " << endl;
	      			q1.display();
	      			break;
	      			}
        		default:{
	      			cout << "Enter Proper Option number " << endl;
	   	 			}
  			} 
			}
		}

    	else if (choice == 'R') {
        
        	while ((alchoix < 3)) {
        	cout<<"                        -----------Sorting algorithm------------           \n";
            cout<<"     1.       Selection sort\n";
            cout<<"     2.       Merge sort\n";
            cout<<"     3.       Stop\n";
            cout<<"     select your option ";
            cin>>alchoix;
        	switch(alchoix) {
            
            	case 1: {
	    			cout << "Enter the number of elements :";
	   				cin >> n;	
	    			for (i = 0; i < n; i++)
	   			 	{
	    			cout<<"Enter element "<< i+1 <<" :";
	   	 			cin>> arr[i];
	    				}
	   				 cout<<"Unsorted list is :";
	   					 for (i = 0; i < n; i++)
	        				cout<<arr[i]<<"  ";
	    						cout<<"\n";
	    			selection(arr,n);
	    				cout<<"Sorted list is :";
	    					for (i = 0; i < n; i++)
	        					cout<< arr[i] << " ";
	        							cout<<" \n";
	        		break; 
	        		}
	       	  
       	  		case 2: {   
				    cout<<"Enter number of elements :";
				    cin>>A_Size;   
				    cout<<"Enter the array elements :";
				    	for(int i=0;i<A_Size;i++)
				    	{cin>>A[i]; }
				    MergeSort(A,0,A_Size-1);
				   			 cout<<"The result after merging your entered elements:";
				   			 for(int i=0;i<A_Size;i++)
	    						{	
	    				     cout<<A[i]<<" ";
	    						}
	    				     cout<<endl;
					break;
					}

        		case 3: {
	        		cout<<"************you stop the sorting algorithm operations.Thanks!**************\n"; 
	       			break;
					}
        	}
     		}
     	}

    	else if (choice == 'O') {
        
       		while ((alchoi < 3)) {
       		cout<<"                    --------------Searching algorithm---------------               \n";
            cout<<"1.       Sequential search\n";
            cout<<"2.       Binary search\n";
            cout<<"3.       Stop\n";
            cout<<"         select your option ";
            cin>>alchoi;
       		switch(alchoi) {

	        	case 1:  {     
		        	int s;
			        cout<<"\nEnter the number of elements in the array: ";
			        cin >> s;
			        cout<<"\nNow enter the element in the array: ";
			    		for(i=0;i < s;i++)
			        	cin>>arr[i];
			   		cout<<"\nNow enter element to search :";
			    	cin>>num;
		 
		    /* calling sequentialSearch function*/
		 
		   				position=sequentialSearch(arr,num,s);
		 
					    if(num==-1)
					        cout<<"Element not found.\n";
					    else
					        cout<<num<<" is found at position " << position <<"\n";
					break;
					}

	    		case 2: 
		    		{    //User input for the size of the array
				    cout<<"Enter the size of the array:";
				    cin>>arraySize;
				    int integerArray[arraySize];

					    //User input for the values
					    for(int i = 0; i < arraySize; i++){
					        cout<<"Enter the value for array position number "<<i<<":\n";
					        cin>>element;
					        integerArray[i] = element;
					        cout<<endl;
					    }

					    //Formatted output of the user input
					    cout<<"The array inserted is: \n";
					    printArray(integerArray, arraySize);


					    //Function call: wayToSort(int arr[], int sizeOfArray) -> This function call, triggers the corresponding to the user's choice
					    //functionality of the program. If the user chooses to sort the array in ascending order the binarySearchAlgorithmAscending(int arr[], int arraySize)
					    //method will be called alongside inCaseOfNotFoundAscending(int arr[], int arraySize) as a "safety" measure. If the user chooses to sort the array in
					    //descending order the binarySearchAlgorithmDescending(int arr[], int arraySize)
					    //method will be called alongside inCaseOfNotFoundDescending(int arr[], int arraySize) as a "safety" measure.
					    wayToSort(integerArray, arraySize);
					break;
				}

				case 3:
					{cout<<"************you stop the searching algorithm operations.Thanks!**************\n"; 
		       		break;
					}
			}
			}
        }
    	
    	else if (choice='t')
        {
    	int choik, num;
    	BST bst;
    	node *temp;

   			while ((choik < 6))
    		{
	        cout<<"                       ----------------Operations on Binary Search tree Traversals----------------   "<<endl;
	        cout<<"        1.	Insert Element to build your binary search tre "<<endl;
	        cout<<"        2.	Print the Inorder Traversal of your binary search tree"<<endl;
	        cout<<"        3.	Print the Preorder Traversal of your binary search tree"<<endl;
	        cout<<"        4.	Print the Postorder Traversal of your binary search tree"<<endl;
	        cout<<"        5.	Display your binary search tree"<<endl;
	        cout<<"        6.	Stop"<<endl;
	        cout<<"        Enter your choice : ";
	        cin>>choik;
	        switch(choik)
	        {
		        case 1:
		        	{
		            temp = new node;
		            cout<<"Enter the number to be inserted in your binary search tree : ";
			    	cin>>temp->info;
		            bst.insert(root, temp);
		            break; }
		        case 2:{
		            cout<<"The Inorder Traversal of your binary search tree"<<endl;
		            bst.inorder(root);
		            cout<<endl;
		            break;}

				case 3:{
		            cout<<"The Preorder Traversal of your binary search tree"<<endl;
		            bst.preorder(root);
		            cout<<endl;
		            break;}
		        case 4:{
		            cout<<"The Postorder Traversal of your binary search tre"<<endl;
		            bst.postorder(root);
		            cout<<endl;
		            break;}

		        case 5:{
		            cout<<"Display your Binary search tree:"<<endl;
		            bst.display(root,1);
		            cout<<endl;
		            break;}
		        case 6:{
			        cout<<"************you stop the Binary search tree traversals operations.Thanks!**************\n"; 
			        break;
			    	}
		        default:{
			         cout<<"Wrong choice, try again"<<endl;
			        }
		    }
    		}

	}

	
}

}




