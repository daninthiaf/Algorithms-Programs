#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <math.h>
#define TABLE_SIZE 1009
#define PRIME 572

using namespace std;

// LINEAR PROBING\\

//template for generic type
template<typename K, typename V>

//Hashnode class
class HashNode
{
    public:
    V value;
    K key;

    //Constructor of hashnode
    HashNode(K key, V value)
    {
        this->value = value;
        this->key = key;
    }
};

//template for generic type
template<typename K, typename V>

//Our own Hashmap class
class HashMap
{
    //hash element array
    HashNode<K,V> **arr;
    int capacity;
    //current size
    int size;
    //dummy node
    HashNode<K,V> *dummy;

    public:
    HashMap()
    {
        //Initial capacity of hash array
        capacity = 1009;
        size=0;
        arr = new HashNode<K,V>*[capacity];

        //Initialise all elements of array as NULL
        for(int i=0 ; i < capacity ; i++)
            arr[i] = NULL;

        //dummy node with value and key -1
        dummy = new HashNode<K,V>(-1, -1);
    }
    // This implements hash function to find index
    // for a key
    int hashCode(K key)
    {
        return key % capacity;
    }

    //Function to add key value pair
    void insertNode(K key, V value)
    {
        HashNode<K,V> *temp = new HashNode<K,V>(key, value);

        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        //find next free space
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key
            && arr[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= capacity;
        }

        //if new node to be inserted increase the current size
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }
    void probes(K key, V value, int& count)
    {
        HashNode<K,V> *temp = new HashNode<K,V>(key, value);

        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);
        //find next free space
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key
            && arr[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= capacity;
            count++;
        }
        //arr[hashIndex] = temp;
    }

    //Function to delete a key value pair
    V deleteNode(int key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        //finding the node with given key
        while(arr[hashIndex] != NULL)
        {
            //if node found
            if(arr[hashIndex]->key == key)
            {
                HashNode<K,V> *temp = arr[hashIndex];

                //Insert dummy node here for further use
                arr[hashIndex] = dummy;

                // Reduce size
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;

        }

        //If not found return null
        return 0;
    }

    //Function to search the value for a given key
    V get(int key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        //finding the node with given key
        while(arr[hashIndex] != NULL)
        {
            //if node found return its value
            if(arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }

        //If not found return null
        return 0;
    }

    //Return current size
    int sizeofMap()
    {
        return size;
    }

    //Return true if size is 0
    bool isEmpty()
    {
        return size == 0;
    }

    //Function to display the stored key value pairs
    void display()
    {
        for(int i=0 ; i<capacity ; i++)
        {
            if(arr[i] != NULL && arr[i]->key != -1)
                cout << "key = " << arr[i]->key
                    <<" value = "<< arr[i]->value << endl;
        }
    }
};

void dupcheck(HashMap<int,int> *h, int size)
{
  //ERROR FIXS DUPLICATED NUMBERS
  int futurenum;
  for (int z = 0; z < size; z++)
  {
    for (int x = 1; x < size; x++)
    {
      if (h->get(z) == h->get(x))
      {
        futurenum = rand() % 1500 + 1;
        h->deleteNode(x);
        h->insertNode(x, futurenum);
      }
    }
  }
}
// END OF LINEAR PROBING

//QUADRATIC PROBING\\

class hashTable{
   
    private:
        int table[TABLE_SIZE], elementCount;
   
    public:
   
        // initialize hash Table
        hashTable(){
            for(int i=0; i < TABLE_SIZE; i++){
                table[i] = 0;
            }
            elementCount = 0;
        }
       
        // method that checks if the hash table is full or not
        bool isFull(){
            if(elementCount == TABLE_SIZE){
                return true;
            }else{
                return false;
            }
        }
         
        // method that returns position for a given element
        int hashFunction(int element){
            return element % TABLE_SIZE;
        }  
       
         // method that finds the next empty position using quadratic probing
        int quadraticProbing(int element, int position){
            int limit = 50, i = 1;
            int newPosition = -1;
            while(i <= 50){
                newPosition = this->hashFunction(position + (int)pow(i, 2));
                if(this->table[newPosition] == 0){
                    break;
                }
                else{
                    i++;
                }
            }
            return newPosition;
        }
       
        // method that inserts element inside the hash table
        void insert(int element){
            int position;
            // checking if the table is full
            if(this->isFull()){
                //cout<<"\nHash Table Full";
                return;
            }  
           
            bool isStored = false;
           
            position = this->hashFunction(element);
               
            // checking if the position is empty
            if(table[position] == 0){
                table[position] = element;
                   // cout<<"\n Key =  " <<position <<" Value= " << element;
                    isStored = true;
                    elementCount += 1;      
            }  
           
            // collision occured hence we do linear probing
            else{
              //  cout<<"\nCollision has occured for element " <<element<<" at position " <<position<<" finding new Position.";
                position = quadraticProbing(element, position);
                if(position != -1)
                {
                    this->table[position] = element;
                    elementCount += 1; 
                }
            return;
        }  
    }

     void probes2(int element, int& count){
            int position;
            // checking if the table is full
            if(this->isFull()){
               // cout<<"\nHash Table Full";
                return;
            }  
           
            bool isStored = false;

            position = this->hashFunction(element);
               
            // checking if the position is empty
            if(table[position] == 0){
                table[position] = element;
                //cout<<"\nElement " <<element<<" stored at position " <<position;
                isStored = true;
                elementCount += 1;
            }  
           
            // collision occured hence we do linear probing
            else{
              //  cout<<"\nCollision has occured for element " <<element<<" at position " <<position<<" finding new Position.";
                position = quadraticProbing(element, position);
                if(position != -1){
                    count++;
                    this->table[position] = element;
                    elementCount += 1;
                  //  cout<<"\nElement " <<element<<" stored at position " <<position;
               
                }
               
            }  
            return;
        } 
 
        // method that searches for an element in the table
        // returns position of element if found
        // else returns false
        int search(int element){
            bool found = false;
           
            int position = this->hashFunction(element);
           
            if(table[position] == element){
                found = true;
                return position;
            }  
           
            // if element is not found at position returned hash function
            // then we search element using quadratic probing
            else{
                int limit = 50, i = 1;
                int newPosition = -1;
                while(i <= 50){
                    newPosition = this->hashFunction(position + (int)pow(i, 2));
                    if(this->table[newPosition] == element){
                        found = true;
                        break;
                    }
                    else{
                        i++;
                    }
                }
                if(found){
                    return newPosition;
                }
                else{
                    return -1;
                }
            }  
        }  
        // method to remove an element from the table      
        void remove(int element){
            int position = this->search(element);
            if(position != -1){
                table[position] = 0;
                this->elementCount -= 1;
            }else{
            }
            return;
        } 

        int sizeofMap_QP()
        {
            return elementCount;
        } 
       
        // method to display the hash table
        void q_display(){
            for (int i = 0; i < TABLE_SIZE; i++){
               cout<<"\n"<<i<<" = " << table[i];
            }  
              cout << endl;
        }
};
       
// END OF QUADRATIC PROBING

//DOUBLE HASHING\\

class DoubleHash 
{ 
    // Pointer to an array containing buckets 
    int *hashTable; 
    int curr_size; 
  
public: 
  
    // function to check if hash table is full 
    bool isFull() 
    { 
  
        // if hash size reaches maximum size 
        return (curr_size == TABLE_SIZE); 
    } 

    int sizeofMap_DH ()
    {
        return curr_size;
    }
  
    // function to calculate first hash 
    int hash1(int key) 
    { 
        return (key % TABLE_SIZE); 
    } 
  
    // function to calculate second hash 
    int hash2(int key) 
    { 
        return (PRIME - (key % PRIME)); 
    } 
  
    DoubleHash() 
    { 
        hashTable = new int[TABLE_SIZE]; 
        curr_size = 0; 
        for (int i=0; i<TABLE_SIZE; i++) 
            hashTable[i] = -1; 
    } 
  
    // function to insert key into hash table 
    void insertHash(int key) 
    { 
        // if hash table is full 
        if (isFull()) 
            return; 
  
        // get index from first hash 
        int index = hash1(key); 
  
        // if collision occurs 
        if (hashTable[index] != -1) 
        { 
            // get index2 from second hash 
            int index2 = hash2(key); 
            int i = 1; 
            while (1) 
            { 
                // get newIndex 
                int newIndex = (index + i * index2) % TABLE_SIZE; 
  
                // if no collision occurs, store 
                // the key 
                if (hashTable[newIndex] == -1) 
                { 
                    hashTable[newIndex] = key; 
                    break; 
                } 
                i++; 
            } 
        } 
  
        // if no collision occurs 
        else
            hashTable[index] = key; 
        curr_size++; 
    } 
  
 // function to insert key into hash table 
    void probes3(int key, int& count) 
    { 
        // if hash table is full 
        if (isFull()) 
            return; 
  
        // get index from first hash 
        int index = hash1(key); 
  
        // if collision occurs 
        if (hashTable[index] != -1) 
        { 
            // get index2 from second hash 
            int index2 = hash2(key); 
            int i = 1; 
            while (1) 
            { 
                // get newIndex 
                int newIndex = (index + i * index2) % 
                                        TABLE_SIZE; 
  
                // if no collision occurs, store 
                // the key 
                if (hashTable[newIndex] == -1) 
                { 
                    hashTable[newIndex] = key; 
                    break; 
                } 
                i++; 
                count++;
            } 
        } 
  
        // if no collision occurs 
        else
            hashTable[index] = key; 
        curr_size++; 
    } 
    // function to display the hash table 
    void displayHash() 
    { 
        for (int i = 0; i < TABLE_SIZE; i++) 
        { 
            if (hashTable[i] != -1) 
                cout << i << " --> "
                     << hashTable[i] << endl; 
            else
                cout << i << endl; 
        } 
    } 
};

//Driver method to test map class
int main()
{
const int RAND_TABLE_SIZE = 900;
const int NEW_RAND_TABLE_SIZE = 950;

   //Linear Probing
    HashMap<int, int> *h = new HashMap<int, int>;
   //Quadratic Probing
    hashTable table, table1;
   //Double Hashing
    DoubleHash hash;

    //Random numbers
    srand((unsigned)time(0));
    int randomnum, randomnum2, randomnum3; 
    int futurenum;

    //INSERTS THE RANDOM NUMBERS INTO THE HASH TABLE
    for (int x = 0; x < RAND_TABLE_SIZE; x++)
    {
      randomnum = rand() % 8500 + 1;
      randomnum2 = rand() % 6788 + 5;
      randomnum3 = rand() & 7775 + 14;
      //linear probing insertion
      h -> insertNode(x, randomnum);
      //quadratic probing insertion
      table.insert(randomnum2);
      //double hashing insertion
      hash.insertHash(randomnum3);
    }

    // CHECKS TO SEE IF THERE ARE ANY DUPLICATE NUMBERS!!!
    for (int z = 0; z < RAND_TABLE_SIZE; z++)
    {
      if (h->get(z) == h->get(z + 1))
      {
        dupcheck(h,z);
      }
    }

    dupcheck(h,900);

    int count = 0;

    for(int x = RAND_TABLE_SIZE; x <= NEW_RAND_TABLE_SIZE; x++)
    {
        //Linear Probing
        randomnum = rand() % 6500 + 1;
        h->probes(x, randomnum, count); 
        dupcheck(h, x);
    }
    for(int x = RAND_TABLE_SIZE; x < NEW_RAND_TABLE_SIZE; x++)
    {
      //randomnum = rand() % 6500 + 1;
      randomnum2 = rand() % 8886  + 34;
      randomnum3 = rand() % 5996 % + 17;
      //Linear Probing
     // h -> probes(x,randomnum,count);
     // dupcheck(h,x);

      //Quadratic Probing
      table.probes2(randomnum2, count);
      table.quadraticProbing(x, randomnum2);
      //Double Hashing  
      hash.probes3(randomnum3, count);
    }

     //h->display();                    
      cout << "Linear Probing: " << endl;
      cout << "Total number of insertions: " << h->sizeofMap() <<endl;
      cout << "Number of probes : " << count << endl;

    // table.q_display();
     cout << "Quadratic Probing: " << endl;
     cout << "Total number of insertions: " << table.sizeofMap_QP() << endl;
     cout << "Number of probes : " << count << endl;

     //hash.displayHash();
     cout << "Double Hashing: " << endl;
     cout << "Total number of insertions: " << hash.sizeofMap_DH() << endl;
     cout << "Number of probes : " << count << endl;

    return 0;
}
