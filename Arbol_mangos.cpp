
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

class Node{
  int data;
  Node* izq;
  Node* der;
  Node* cen;
  
public:

  Node(){
      data=0;
      izq = NULL;
      der =  NULL;
      cen =  NULL;
  }

  Node(int d){
      data=d;
      izq = NULL;
      der =  NULL;
      cen = NULL;
  }
  
  int getData(){
      return data;
  }
  
  Node* getIzq(){
      return izq;
  }
  
  Node* getDer(){
      return der;
  }
  
  Node* getCen(){
      return cen;
  }
  
  void setIzq(Node* iz){
      izq =  iz;
  }
  
  void setDer(Node* de){
      der =  de;
  }
  
  void setCen(Node* ce){
      cen =  ce;
  }
  
  bool hasIzq(){
      return izq!=NULL;
  }
  
  bool hasDer(){
      return der!=NULL;
  }
  
  bool hasCen(){
      return cen!=NULL;
  }
  
  bool isHoja(){
      if(izq == NULL && der == NULL && cen == NULL)
        return true;
        
      return false;
  }
    
};

class Tree{
  Node* root;

public:
  Tree(){
      root = NULL;
  }
  
  void add(int d){
      Node* n = new Node(d);
      if(root == NULL){
          root = n;
      }else{
          Node* t = root;
          bool found = false;
          while(!found){
              if(t->getData() < n->getData()/3){
                if(t->hasDer()){
                    t =  t->getDer();
                }else{
                    t->setDer(n);
                    found=true;
                }   
              }else if(t->getData() >= (n->getData()/3)*2){
                if(t->hasIzq()){
                    t =  t->getIzq();
                }else{
                    t->setIzq(n);
                    found=true;
                }   
              }else{
                if(t->hasCen()){
                    t =  t->getCen();
                }else{
                    t->setCen(n);
                    found=true;
                } 
              }
          }
      }
  }

  void preorder(){
      preorder1(root);
      cout<<endl;
      preorder(root);
  }
  
  void preorder(Node* r){
      if(r != NULL){
          cout<<r->getData()<<"\t";
          preorder(r->getIzq());
          preorder(r->getCen());
          preorder(r->getDer());
      }
  }

  void preorder1(Node* r){
      if(r != NULL){
          cout<<r->getData()<<"-";
          if(r->hasIzq()){
              cout<<r->getIzq()->getData()<<"-";
          }
          if(r->hasCen()){
              cout<<r->getCen()->getData()<<"-";
          }
          if(r->hasDer()){
              cout<<r->getDer()->getData()<<"-";
          }
          cout<<endl;
          preorder1(r->getIzq());
          preorder1(r->getCen());
          preorder1(r->getDer());
      }
  }
    
  void addr(int d){
      if(root != NULL)
        addr(d, root, root);
      else
        root =  new Node(d);
    }

    void addr(int d, Node* t, Node* pt){
        if(t == NULL){
            Node* n = new Node(d);
            if(d < pt->getData()/3){
                pt->setIzq(n);
            }else if(d >= (pt->getData()/3)*2){
                pt->setDer(n);
            }else{
                pt->setCen(n);
            }
        }else{
            if(d < t->getData()/3){
                addr(d, t->getIzq(), t);
            }else if(d >= (t->getData()/3)*2){
                addr(d, t->getDer(), t);
            }else{
                addr(d, t->getCen(), t);
            }
        }
    }

    
    
};

int main()
{
    
    Tree t;
    t.addr(100);
    t.addr(95);
    t.addr(92);
    t.addr(81);
    t.addr(70);
    t.addr(68);
    t.addr(51);
    t.addr(49);
    t.addr(31);
    t.addr(21);
    t.addr(11);
    t.addr(7);
    
    t.preorder();
    
    return 0;
}
