#include <iostream>

using namespace std;

int x[20];
int y[20];


//---------------------------------------------------------------------------
//-------------------------- STACK CLASS ------------------------------------
//---------------------------------------------------------------------------

typedef char TipoDeDato; // tipo de los elementos de la pila
const int TAMPILA = 49;

template <class T>
class Stack
{
    private:
        T* stack; //puntero a arreglo dinamico, puede cambiar la direccion a la que apunta
        //int top; //init. value = -1
        int capacity;
        TipoDeDato listaPila[TAMPILA];
    public:
        int top;
        //Constructor
        Stack(int size = 20){
            this -> top = -1;
            this -> capacity = size;
            //int arreglo[tam];
            this -> stack = new T[size];
        }

        //top = -1; // condición de pila vacía
        //}

        bool IsEmpty();
        bool IsFull();
        int Size();

        //return top
        T& Top() const;


        void Push(const T& item); //Insert new element at top
        int Pop(); //Delete one element from top
        char Peek(); //Return top element in stack
};

//---------------------------------------------------------------------------
//----------------------- STACK FUNCTIONS -----------------------------------
//---------------------------------------------------------------------------

template <class T>
void Stack <T>::Push (const T& x) //(const T& x)
{
    //Add x to stack
    //cout <<
    if(IsFull()) cout << "Stack is full. Cannot add element." << endl;
    //cout << "Inserting " << x << endl;
    //cout << x;
    stack [++top] = x;
}

template< class T>
int Stack <T>::Pop()
{
    //Delete top element from stack
    if(IsEmpty()) cout << "Stack is empty. Cannot delete." << endl;
    //cout << "Removing " << stack[top] << endl;
    return stack[top--];
    //stack [top--].~T(); //Delete the element
}

template< class T>
bool Stack <T>::IsEmpty()
{
    //cout << top;
    return this -> top == -1;
}

template< class T>
bool Stack <T>::IsFull()
{
    //cout << top;
    return this -> top == this -> capacity -1;
}

template< class T>
int Stack <T>::Size()
{
    //cout << "size of stack " << this -> top + 1 << endl;
    return this -> top + 1;
}

template< class T>
char Stack <T>::Peek() //Return top element in the stack
{
    if(!IsEmpty()){
        //cout << "top element is " << stack[top] << endl;
        return stack[top];
    }
    else
        return '*';
}

Stack <char> q  = Stack <char>(); //Stack for storing characters
Stack <int> i_temp1  = Stack <int>();
Stack <int> j_temp1  = Stack <int>();

//---------------------------------------------------------------------------
//---------------------------- FUNCTIONS ------------------------------------
//---------------------------------------------------------------------------

bool isvowel(char k){
    if (k=='a' or k=='e' or k=='i' or k=='o' or k=='u'){
        // << "is vowel";
        return true;
    }
    else return false;
}

bool isconsonant(char k){
    if (k=='a' or k=='e' or k=='i' or k=='o' or k=='u') return false;
    else{
        //cout << "is consonant";
        return true;
    }
}

bool isvisited(int iter, int i, int i_arr[15],int j, int j_arr[15]){
    for(int k=0;k<iter;k++){
        if (i_arr[k]==i and j_arr[k]==j) return true;
    }
    return false;
}

bool isvstack(Stack <int> i_stack, Stack <int> j_stack, int i, int j){
    Stack <int> i_temp;
    Stack <int> j_temp;
    while(!i_stack.IsEmpty() and !j_stack.IsEmpty()){
        if (i_stack.Peek()==i and j_stack.Peek()==j){
            return true;
        }
        i_temp.Push(i_stack.Peek());
        i_stack.Pop();
        j_temp.Push(j_stack.Peek());
        j_stack.Pop();
    }
    return false;
}

bool consonants(Stack <char> r){
    int counter=0;
    while(!r.IsEmpty()){
        if (isconsonant(r.Peek())) counter++;
        r.Pop();
    }
    if (counter>=3) return true;
    else return false;
}

string concat(Stack <char> c){

    Stack <char> temp_c;
    string vowel = "";
    string consonant = "";

    while(!c.IsEmpty())
    {
        temp_c.Push(c.Peek());
        c.Pop();
    }
    while(!temp_c.IsEmpty())
    {
        if(isvowel(temp_c.Peek()))
        {
        vowel = vowel + temp_c.Peek();
        }
        else
        {
            consonant = consonant + temp_c.Peek();
        }
        temp_c.Pop();
    }
    vowel = vowel + consonant;
    return vowel;
}

bool last_item(Stack <char> s){
    while(s.Size()>1){
        s.Pop();
    }
    //cout << "last item: " << s.Peek() << endl;
    if(isconsonant(s.Peek())) return true;
    else return false;
}

//void eval(int i, int j, int n, Stack <char> s, char **matrix){
void eval(int i, int j, int n, Stack <char> s, Stack <int> idex, Stack <int> jdex, char matrix[100][100], int dir, int i_arr[15], int j_arr[15], int iter)
{

while(!s.IsEmpty()){
    q.Push(s.Peek());
    s.Pop();
}

//cout << last_item(q) << endl;

if(q.Size()>=5 and consonants(q) and last_item(q)){
    while(!q.IsEmpty()){
        cout << q.Peek();
        s.Push(q.Peek());
        q.Pop();
    }

    cout << " " << concat(s) << endl;
    //cout << " add some shit " << concat(q) << endl;
    //cout << concat(q);



    /*for(int d=0;d<15;d++){
        //cout << i_arr[d] << "/";
    }
    //cout << endl;

    for(int d=0;d<15;d++){
        //cout << j_arr[d] << "/";
    }
    //cout << endl;*/
}

else {
    while(!q.IsEmpty()){
        s.Push(q.Peek());
        q.Pop();
    }
}

/*
while(!idex.IsEmpty()){
    i_temp1.Push(idex.Peek());
    idex.Pop();
}

while(!jdex.IsEmpty()){
    j_temp1.Push(jdex.Peek());
    jdex.Pop();
}

while(!i_temp1.IsEmpty()){
    cout << i_temp1.Peek() << "/";
    idex.Push(i_temp1.Peek());
    i_temp1.Pop();
}
cout << endl;

while(!j_temp1.IsEmpty()){
    cout << j_temp1.Peek();
    jdex.Push(j_temp1.Peek());
    j_temp1.Pop();
}
*/


//test whether current pos [i][j] and new pos. Push current position and compare if new pos is vowel or not.
// DOWN = 0
    //s.Push(matrix[i][j]);// no need to push C (matrix[i][j]) cause it will be pushed in the double for loop
if (dir==0){ // GO DOWN
    //baseline
    if ((isconsonant(s.Peek()) and isconsonant(matrix[i+1][j])) or i+1>=n or j>=n or i+1<0 or j<0)
    {
        dir=dir+1;
        //eval(i,j,n,s,idex,jdex,matrix,dir,i_arr,j_arr,iter);
    }
    else
    {
        if(isvisited(iter,i+1,i_arr,j,j_arr) or isvisited(iter,i,i_arr,j,j_arr))//isvstack(idex,jdex,i+1,j))//
        {
            dir=dir+1;
            //eval(i,j,n,s,idex,jdex,matrix,dir,i_arr,j_arr,iter);
        }
        else
        {
            s.Push(matrix[i+1][j]);
            idex.Push(i);
            jdex.Push(j);
            i_arr[iter]=i;
            j_arr[iter]=j;

            //dir=dir+1;
            eval(i+1,j,n,s,idex,jdex,matrix,0,i_arr,j_arr,iter+1); //antes
            dir = dir+1;
            s.Pop();
            i_arr[iter]=-2;
            j_arr[iter]=-2;


            s.Size();
            s.Peek();
        }
    }
}

if (dir==1){ // GO RIGHT
    //baseline
    if ((isconsonant(s.Peek()) and isconsonant(matrix[i][j+1])) or i>n or j+1>=n or i<0 or j+1<=0)
    {
            dir=dir+1;
            //eval(i,j,n,s,idex,jdex,matrix,dir,i_arr,j_arr,iter);
    }
    else{
        if(isvisited(iter,i,i_arr,j+1,j_arr) or isvisited(iter,i,i_arr,j,j_arr))//isvstack(idex,jdex,i,j+1))//isvisited(iter,i,i_arr,j+1,j_arr) or isvisited(iter,i,i_arr,j,j_arr))
        {
            dir=dir+1;
            //eval(i,j,n,s,idex,jdex,matrix,dir,i_arr,j_arr,iter);
        }
        else
        {
            s.Push(matrix[i][j+1]);
            idex.Push(i);
            jdex.Push(j);
            i_arr[iter]=i;
            j_arr[iter]=j;
            //dir=dir+1;
            //eval(i,j+1,n,s,idex,jdex,matrix,0,i_arr,j_arr,iter+1);
            eval(i,j+1,n,s,idex,jdex,matrix,0,i_arr,j_arr,iter+1);

            dir = dir+1;
            s.Pop();
            i_arr[iter]=-2;
            j_arr[iter]=-2;

            s.Size();
            s.Peek();
        }
    }
}

if (dir==2){ // GO UP
    //baseline
    if ((isconsonant(s.Peek()) and isconsonant(matrix[i-1][j]))or i-1>n or j>n or i-1<0 or j<0)
    {
            dir=dir+1;
            //eval(i,j,n,s,idex,jdex,matrix,dir,i_arr,j_arr,iter);
    }
    else
    { //if (isconsonant(s.Peek()) and i<n and isvowel(matrix[i+1][j])){ // If C V, push V
        if(isvisited(iter,i-1,i_arr,j,j_arr) or isvisited(iter,i,i_arr,j,j_arr))//isvstack(idex,jdex,i-1,j)){
        {
            dir=dir+1;
            //eval(i,j,n,s,idex,jdex,matrix,dir,i_arr,j_arr,iter);
        }
        else
        {
            s.Push(matrix[i-1][j]);
            idex.Push(i);
            jdex.Push(j);
            i_arr[iter]=i;
            j_arr[iter]=j;
            //dir=dir+1;
            //eval(i-1,j,n,s,idex,jdex,matrix,0,i_arr,j_arr,iter+1);
            eval(i-1,j,n,s,idex,jdex,matrix,0,i_arr,j_arr,iter+1);

            dir = dir+1;
            s.Pop();
            i_arr[iter]=-2;
            j_arr[iter]=-2;

            s.Size();
            s.Peek();

        }
    }
}

if (dir==3){ // GO LEFT
    //baseline
    if ((isconsonant(s.Peek()) and isconsonant(matrix[i][j-1])) or i>n or j-1>n or i<0 or j-1<0)
    {
    }
    else
    { //if (isconsonant(s.Peek()) and i<n and isvowel(matrix[i+1][j])){ // If C V, push V
        if(isvisited(iter,i,i_arr,j-1,j_arr) or isvisited(iter,i,i_arr,j,j_arr))//isvstack(idex,jdex,i,j-1))//
        {
        }
        else
        {
            s.Push(matrix[i][j-1]);
            idex.Push(i);
            jdex.Push(j);
            i_arr[iter]=i;
            j_arr[iter]=j;
            //dir=dir+1;
            //eval(i,j-1,n,s,idex,jdex,matrix,0,i_arr,j_arr,iter+1);
            eval(i,j-1,n,s,idex,jdex,matrix,0,i_arr,j_arr,iter+1);

            s.Size();
            s.Peek();
            s.Pop();
            idex.Pop();
            jdex.Pop();
            i_arr[iter]=-2;
            j_arr[iter]=-2;

            //eval(i,j,n,s,idex,jdex,matrix,dir,i_arr,j_arr,iter+1);
        }
    }
}

//if (dir==4) dir=0;

}


//---------------------------------------------------------------------------
//------------------------------ M A I N ------------------------------------
//---------------------------------------------------------------------------

int main()
{
    int dim;
    cin >> dim;

    char matrix[100][100];

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cin >> matrix[i][j];
        }
    }
    /*
    int n = 3;
    char **matrix = new char*[n];
    for(int h=0; h<n; h++){
        matrix[h] = new char[n];
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }*/

    /*char matrix[5][5] = {
        {'x','s','c','a','t'},
        {'c','o','z','d','p'},
        {'o','k','x','b','x'},
        {'b','l','c','p','u'},
        {'l','n','i','a','v'}
    };*/

    int i_array[20];
    int j_array[20];
    for(int i=0; i<20; i++){
        i_array[i] = -2;
        j_array[i] = -2;
    }

    Stack <char> s  = Stack <char>(); //Stack for storing characters

    Stack <int> idex = Stack <int>(); //Stack for storing i index
    Stack <int> jdex = Stack <int>(); //Stack for storing j index

    //cout << "size: " << sizeof(x)/sizeof(*x) << endl;

// store in stacks iindex and jindex the positions of consonants to start
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
            if (isconsonant(matrix[i][j]) and s.IsEmpty()){

                s.Push(matrix[i][j]); //pushing consonants into stack before applying iterative function
                s.Size();
                s.Peek();

                // CALL ITERATIVE FUNCTION
                eval(i,j,dim,s,idex,jdex,matrix,0,i_array,j_array,0);

                while(!s.IsEmpty()) s.Pop();
                while(!idex.IsEmpty()) idex.Pop();
                while(!jdex.IsEmpty()) jdex.Pop();

                for(int i=0; i<20; i++){
                    i_array[i] = -2;
                    j_array[i] = -2;
                }
                s.Size();
            }
        }
    }

}


