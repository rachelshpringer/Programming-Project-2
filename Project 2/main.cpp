//Rachel Shpringer
//CS20A
//Programming Project #2
//Due: October 3, 2018

#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class LinearList
{
private:
    int length;
    int MaxSize;
    T *element;
public:
    LinearList(int MaxLinearSize=10);
    ~LinearList(){delete[]element;}
    int isEmpty()const{return length==0;}
    int Length()const{return length;}
    int Find(int k,T&x)const;
    int Search(const T&x)const;
    void Delete(int k,T&x);
    void Insert(int k,const T&x);
    void Output(string filename)const;
};

template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
    MaxSize=MaxListSize;
    element=new T[MaxSize];
    length=0;
}

template<class T>
int LinearList<T>::Find(int k,T&x)const
{
    if(k<1||k>length)
        return 0;
    x=element[k-1];
    return 1;
}

template<class T>
int LinearList<T>::Search(const T&x)const
{
    for(int i=0;i<length;i++)
        if(element[i]==x)
            return ++i;
    return 0;
}

template<class T>
void LinearList<T>::Delete(int k,T&x)
{
    if(Find(k,x))
    {
        for(int i=k;i<length;i++)
            element[i-1]=element[i];
        length--;
    }
    else
        cout<<"out of bounds\n";
}

template<class T>
void LinearList<T>::Insert(int k,const T&x)
{
    if(k<0||k>length)
        cout<<"out of bounds\n";
    //if(length==MaxSize)
    //    cout<<"(max list length achieved)\n";
    for(int i=length-1;i>=k;i--)
        element[i+1]=element[i];
    element[k]=x;
    
    length++;
}



//this function currently prints to a terminal but we need to modify it to save to the file Project2.txt
template<class T>
void LinearList<T>::Output(string filename)const

{
    ofstream outStream;

    if(isEmpty())
        cout<<"list is empty\n";
    else {
        if (filename == "")
            for(int i=0;i<length;i++)
                cout<<element[i]<<"\t";
        else {
            cout<<"print to " << filename << endl;
            outStream.open(filename);
            for(int i=0;i<length;i++)
                outStream<<element[i]<<"\t";
            outStream.close();
            }
    }
}


/*
//6) Create a new class for the linked list, include functions delete, inserts, and output
 
    template <typename E> class LList: public List<E> {
    private:
        Link<E>* head;
        Link<E>* curr;
        int cnt;
        void init() {
            curr = head = new Link<E>;
            cnt = 0;
        }
        void removeall() {   // Return link nodes to free store
            while(head != NULL) {
                curr = head;
                head = head->next;
                delete curr;
            } }
    public:
        LList(int size=defaultSize) { init(); }
        ̃LList() { removeall(); }
        void Output(string filename) const;                // Print list contents
        void clear() { removeall(); init(); }       // Clear list
        // Insert "it" at current position
        void insert(const E& it) {
            curr->next = new Link<E>(it, curr->next);
            if (tail == curr) tail = curr->next;  // New tail
            cnt++;
        }
        void append(const E& it) { // Append "it" to list
            tail = tail->next = new Link<E>(it, NULL);
            cnt++;
        }
        // Remove and return current element
        E delete(pos) {
            moveToPos(pos);
            Assert(curr->next != NULL, "No element");
            E it = curr->next->element;      // Remember value
            Link<E>* ltemp = curr->next;     // Remember link node
            if (tail == curr->next) tail = curr; // Reset tail
        }
        curr->next = curr->next->next;
        delete ltemp;
        cnt--;
        return it;
        void moveToStart() // Place curr at list start
        { curr = head; }
        void moveToEnd()   // Place curr at list end
        { curr = tail; }
        // Move curr one step left; no change if already at front
        void prev() {
            if (curr == head) return;       // No previous element
            Link<E>* temp = head;
            // March down list until we find the previous element
            while (temp->next!=curr) temp=temp->next;
            curr = temp; }
        // Move curr one step right; no change if already at end
        void next()
        { if (curr != tail) curr = curr->next; }
        int length() const  { return cnt; } // Return length
        // Return the position of the current element
        int currPos() const {
            Link<E>* temp = head;
            int i;
            for (i=0; curr != temp; i++)
                temp = temp->next;
            return i;
        }
        // Move down list to "pos" position
        void moveToPos(int pos) {
            Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
            curr = head;
            for(int i=0; i<pos; i++) curr = curr->next;
        }
        const E& getValue() const { // Return current element
            Assert(curr->next != NULL, "No value");
            return curr->next->element;
        } };

*/

int main()
{
    int ch;
    int k,x,len,p;
    string filename;
    LinearList <int> obj; //I don't know what it means when you have <type> in carrots
    //LList lobj;
    
//1) Create a list of the following elements using obj.Insert
    obj.Insert(0,11);
    obj.Insert(1,10);
    obj.Insert(2,9);
    obj.Insert(3,8);
    obj.Insert(4,7);
    obj.Insert(5,6);
    obj.Insert(6,5);
    obj.Insert(7,4);
    obj.Insert(8,3);
    obj.Insert(9,2);
    obj.Insert(10,1);
    
    obj.Output(""); //so we can see what the initial list looks like before continuing
    cout << endl;
    
    
//2) Delete element #5 (counting from 0) using obj.Delete
    x=5; //seems unnecessary but the code strangely won't work without it
    obj.Delete(6,x); //also seems unnecessary to pass the value at position 6 but the code won't work without it
    
   obj.Output(""); //so we can see what the list is after the deletion
    cout << endl;
    
//3) Insert element 100 at position 8 (couting from 0) using obj.Insert
    obj.Insert(8,100);
    
    obj.Output(""); //so we can see what the list is after the insertion
    cout << endl;
    
    
    len=obj.Length();
    if(len==0)
        cout<<"List is empty\n";
    else
        cout<<"current length of linearlist is "<<len<<endl;
    
    
//4) modify the output function to save the list to a file, the name of the file is provided as an constant argument
    obj.Output("Project2.txt");
    
    
//5) save to a different file name using a variable to hold the file name
    filename = "Rachel.Shpringer.aList.txt";
    obj.Output(filename);
    
    
/*
//7) repeat steps 1-5 using the object from the linked list
    lobj.Insert(0,11);
    lobj.Insert(1,10);
    lobj.Insert(2,9);
    lobj.Insert(3,8);
    lobj.Insert(4,7);
    lobj.Insert(5,6);
    lobj.Insert(6,5);
    lobj.Insert(7,4);
    lobj.Insert(8,3);
    lobj.Insert(9,2);
    lobj.Insert(10,1);
    
    //Delete element #5 (counting from 0) using obj.Delete
    lobj.Delete(6); //also seems unnecessary to pass the value at position 6 but the code won't work without it

    
    //Insert element 100 at position 8 (couting from 0) using lobj.Insert
    lobj.Insert(8,100);
    
    //modify the output function to save the list to a file, the name of the file is provided as an constant argument
    lobj.Output("Project2.txt");
    
    //save to a different file name using a variable to hold the file name
    filename = "Rachel.Shpringer.lList.txt";
    lobj.Output(filename);
    
 */
    
    
    
    
    return 0;
    
}
