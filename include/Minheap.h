#include<iostream>
#include<climits>
#include "S_Node.h"
#include <vector>
using namespace std;

class Minheap{
    vector<S_Node*> harr;
    int heapSize;
    public:
        Minheap(){
            heapSize = 0;
        };
        int parent(int i){
            return (i-1)/2;
        };
        int left(int i){
            return (2*i+1);
        }
        int right(int i){
            return (2*i+2);
        }
        void insert(S_Node* newNode,vector<S_Node*> &harr){

            int i = harr.size();
            harr.push_back(newNode);

            while (i != 0 && harr[parent(i)]->freq > harr[i]->freq)
            {
                S_Node* temp = harr[i];
                harr[i] = harr[parent(i)];
                harr[parent(i)] = temp;
                i = parent(i);
            }
        }
        S_Node* extractMin(vector<S_Node*> &harr){
            if (harr.size() <= 0){
                S_Node* minNode = new S_Node('\0',INT_MIN);
                return minNode;
            }
            if (harr.size() == 1){
                S_Node* temp = harr[0];
                harr.pop_back();
                return harr[0];
            }

            S_Node* root = harr[0];
            harr[0] = harr[harr.size()-1];
            MinHeapify(0, harr);
            harr.pop_back();
            return root;
        }
        void MinHeapify(int i, vector<S_Node*> &harr){
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if (l < harr.size() && harr[l]->freq < harr[i]->freq)
                smallest = l;
            if (r < harr.size() && harr[r]->freq < harr[smallest]->freq)
                smallest = r;
            if (smallest != i){
                S_Node* temp = harr[i];
                harr[i] = harr[smallest];
                harr[smallest] = temp;
                MinHeapify(smallest, harr);
            }
        }
};

//Minheap::Minheap(){
//    heapSize = 0;
//}

//int Minheap::parent(int i){
//    return (i-1)/2;
//}
//
//int Minheap::left(int i){
//    return (2*i+1);
//}
//int Minheap::right(int i){
//    return (2*i+2);
//}
//void Minheap::insert(S_Node* newNode,vector<S_Node*> &harr){
//
//    int i = harr.size();
//    harr.push_back(newNode);
//
//    while (i != 0 && harr[parent(i)]->freq > harr[i]->freq)
//    {
//        S_Node* temp = harr[i];
//        harr[i] = harr[parent(i)];
//        harr[parent(i)] = temp;
//        i = parent(i);
//    }
//}
//S_Node* Minheap::extractMin(vector<S_Node*> &harr){
//    if (harr.size() <= 0){
//        S_Node* minNode = new S_Node('\0',INT_MIN);
//        return minNode;
//    }
//    if (harr.size() == 1){
//        S_Node* temp = harr[0];
//        harr.pop_back();
//        return harr[0];
//    }
//
//    S_Node* root = harr[0];
//    harr[0] = harr[harr.size()-1];
//    MinHeapify(0, harr);
//    harr.pop_back();
//    return root;
//}
//void Minheap::MinHeapify(int i, vector<S_Node*> &harr){
//    int l = left(i);
//    int r = right(i);
//    int smallest = i;
//    if (l < harr.size() && harr[l]->freq < harr[i]->freq)
//        smallest = l;
//    if (r < harr.size() && harr[r]->freq < harr[smallest]->freq)
//        smallest = r;
//    if (smallest != i){
//        S_Node* temp = harr[i];
//        harr[i] = harr[smallest];
//        harr[smallest] = temp;
//        MinHeapify(smallest, harr);
//    }
//}


