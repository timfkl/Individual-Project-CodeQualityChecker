#include<iostream>
#include "HashNode.h"

template <class T1, class T2>
HashNode<T1, T2>::HashNode(){
}

template <class T1, class T2>
HashNode<T1, T2>::HashNode(T1 k, T2 v){
    key = v;
    value = k;
}

template <class T1, class T2>
bool HashNode<T1, T2>::operator==(const HashNode<T1,T2>& oldnode){
    if(key == oldnode.key){
        return false;
    }else{
        return true;
    }
}

/**template <class T1, class T2>
bool HashNode<T1, T2>::operator!=(const HashNode<T1,T2>& oldnode){**/
    

/** i ran out of time**/
